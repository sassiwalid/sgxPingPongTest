# PingPong SGX Demo
#### Intel SGX
Software applications frequently need to work with private information such as passwords, account numbers, financial information, encryption keys, and health records. This sensitive data is intended to be accessed only by the designated recipient. In Intel SGX terminology, this private information is referred to as an application’s secrets.
#### What is PingPong SGX 
The application called "Ping-Pong" consists of two enclaves: (1) The Ping Enclave, which when called upon generates a random number a and sends it to the application. (2) The Pong enclave, which generates a value b upon creation and responds weather a > b when called upon by the application.

