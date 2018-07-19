#include <stdio.h>
#include <iostream>
#include "Enclave_u.h"
#include "sgx_urts.h"
#include "sgx_utils/sgx_utils.h"

/* Global EID shared by multiple threads */
sgx_enclave_id_t global_eid = 0;

// OCall implementations
void ocall_print(const char* str) {
    printf("%s\n", str);
}

int main(int argc, char const *argv[]) {
    if (initialize_enclave(&global_eid, "enclave.token", "enclave.signed.so") < 0) {
        std::cout << "Fail to initialize enclave." << std::endl;
        return 1;
    }
    uint32_t ptr;
    uint32_t  pongVal;
    // declare enclaves and launch the ping pong 
    sgx_status_t enclaveping = ping(global_eid, &ptr);
    sgx_status_t enclavepong = pong(global_eid, &pongVal,ptr);
    if (enclaveping != SGX_SUCCESS) {
        std::cout << "enclave ping not created" << std::endl;
    }
    if (enclavepong != SGX_SUCCESS) {
        std::cout << "enclave pong not created" << std::endl;
    }

    printf("Random number: %d\n", ptr);
    printf("pong run status :%d\n",pongVal);
    return 0;
}
