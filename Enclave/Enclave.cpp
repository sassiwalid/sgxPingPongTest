#include "Enclave_t.h"
#include "stdio.h"
#include "stdlib.h"
#include <sgx_trts.h>

uint32_t ping (){
    uint32_t val; 
    sgx_read_rand((unsigned char *) &val, 4);
    return val;
}

uint32_t pong (uint32_t inputValue){
   uint32_t val; 
   sgx_read_rand((unsigned char *) &val, 4);
   if (inputValue > val){
     return 1;
   }
  return 0;
}
