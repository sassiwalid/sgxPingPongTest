# PingPong SGX Demo
#### What is Intel SGX?
Software applications frequently need to work with private information such as passwords, account numbers, financial information, encryption keys, and health records. This sensitive data is intended to be accessed only by the designated recipient. In Intel SGX terminology, this private information is referred to as an application’s secrets.
## Getting Started
The application called "Ping-Pong" consists of two enclaves: (1) The Ping Enclave, which when called upon generates a random number a and sends it to the application. (2) The Pong enclave, which generates a value b upon creation and responds weather a > b when called upon by the application.
In the following, we describe the different messages of the protocol:
1. The application initiates a ping-pong request.
2. The Enclave Ping generates a random number a and sends it encrypted to the application. 
3. The application sends [a] to the Enclave Pong.
4. The Enclave Pong decrypts and sends the boolean result of a > b.
### Prerequisites
Intel(R) Software Guard Extensions (Intel(R) SGX) is an Intel technology for application developers seeking to protect select code and data from disclosure or modification.
to use the SGX sdk in Ubuntu 16.04 LTS, you should  follow this steps:
1. Install tools to build the SGX SDK using this command:
```shell
sudo apt-get install build-essential ocaml automake autoconf libtool wget python
```
2. Use the script download-prebuilt.sh inside source code package to download prebuilt binaries to prebuilt folder like this:
```shell
$ ./download_prebuilt.sh
```
3. To build both Intel(R) SGX SDK and PSW with default configuration, enter the following command:
```shell
$ make
```
4. Now, you should build the SGX SDK Installer and also the SGX PSW installer using this two commands:
```shell
$ make sdk_install_pkg
$ make psw_install_pkg
```
5. You will got two binary files, Intel(R) SGX PSW installer in the linux/installer/bin folder.
*sgx_linux_x64_sdk_${version}.bin*, so install the sdk using this command:
```shell
$ ./sgx_linux_x64_sdk_${version}.bin
```
6. After installing, you should setup the environnement variable using this command.

## Running the pingpong demo 
After downloading the demo, you shoud access to the directory by this command:
```shell
$ cd {path_Directory_pingpongDemo}
```
1. Compile the project using the make command:
```shell
$ make
```
2. Run the demo:
```shell
$ ./App
```

#### Versioning:
1.0
#### Author:
* Walid Sassi, Assistant professor, University of carthage.[sassi.walid@outlook.com](sassi.walid@outlook.com)
