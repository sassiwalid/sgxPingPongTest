#include <stdio.h>
#include <iostream>
#include "Enclave_u.h"
#include "sgx_urts.h"
#include "sgx_utils/sgx_utils.h"


sgx_enclave_id_t pingEnclaveId ;
sgx_enclave_id_t pongEnclaveId ;

// OCall implementations
void ocall_print(const char* str) {
    printf("%s\n", str);
}

int main(int argc, char const *argv[]) {
    sgx_status_t ret;
    sgx_launch_token_t token = {0};
    char token_path[20] = {"enclave.token"};
    int i ;
    uint32_t pingVal;
    uint32_t  pongVal;
    int updated = 0;
    // read the enclave token 
    FILE *fp = fopen(token_path, "rb");
    if (fp == NULL && (fp = fopen(token_path, "wb")) == NULL) {
        printf("Warning: Failed to create/open the launch token file \"%s\".\n", token_path);
    }

    if (fp != NULL) {
        /* read the token from saved file */
        size_t read_num = fread(token, 1, sizeof(sgx_launch_token_t), fp);
        if (read_num != 0 && read_num != sizeof(sgx_launch_token_t)) {
            /* if token is invalid, clear the buffer */
            memset(&token, 0x0, sizeof(sgx_launch_token_t));
            printf("Warning: Invalid launch token read from \"%s\".\n",token_path );
        }
    }
    // create the two enclaves

    ret = sgx_create_enclave("enclave.signed.so", 1, &token, &updated, &pingEnclaveId, NULL);
    //handle exception 
    if (ret != SGX_SUCCESS) {
        std::cout << "enclave ping not created" << std::endl;
	return -1;
    } 
    ret = sgx_create_enclave("enclave.signed.so", 1, &token , &updated, &pongEnclaveId, NULL);
    if (ret != SGX_SUCCESS) {
        std::cout << "enclave pong not created" << std::endl;
	return -1;
    } 
   std::cout << "pingEnclaveId :"  << std::endl;
   std::cout << pingEnclaveId << std::endl;
   std::cout << "pongEnclaveId :" << std::endl;
   std::cout << pongEnclaveId << std::endl;
   // launch the two enclaves 
   for (i=0;i<10;i++){

	sgx_status_t enclaveping_status = ping(pingEnclaveId, &pingVal);
        sgx_status_t enclavepong_status = pong(pongEnclaveId, &pongVal,pingVal);
	//handle exceptions  
	if (enclaveping_status != SGX_SUCCESS) {
        std::cout << "enclave ping not launched" << std::endl;
    	}
    	if (enclaveping_status != SGX_SUCCESS) {
        std::cout << "enclave pong not launched" << std::endl;
    	}
	printf("ping number: %d\n", pingVal);
   	printf("pong run status :%d\n",pongVal);
    }	
 return 0;
}
