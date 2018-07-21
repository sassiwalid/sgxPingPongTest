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
    int i ;
    uint32_t ptr;
    uint32_t  pongVal;
    ret = sgx_create_enclave("enclavePing", 1, &token, 0, &pingEnclaveId, NULL);
    if (ret != SGX_SUCCESS) {
        std::cout << "enclave ping not created" << std::endl;
    } 
    ret = sgx_create_enclave("enclavePong", 1, &token , 0, &pongEnclaveId, NULL);
    if (ret != SGX_SUCCESS) {
        std::cout << "enclave pong not created" << std::endl;
    } 
   for (i=0;i<10;i++){
	sgx_status_t enclaveping_status = ping(pingEnclaveId, &ptr);
        sgx_status_t enclavepong_status = pong(pongEnclaveId, &pongVal,ptr);
	if (enclaveping_status != SGX_SUCCESS) {
        std::cout << "enclave ping not launched" << std::endl;
    	}
    	if (enclaveping_status != SGX_SUCCESS) {
        std::cout << "enclave pong not launched" << std::endl;
    	}
	printf("Random number: %d\n", ptr);
   	printf("pong run status :%d\n",pongVal);
    }	
 return 0;
}
