PIthread
=============
The idea is to approximate the PI number using monte carlo method. The programs worked in parallel using thread, generating random numbers with values ​​between 0 and 1 and checking if those numbers are inside the circle.
## Getting Started
Follow these steps to get PIthread C running without errors.

### Prerequisites
You need a C compiler installed. To do it, use the following command:
```
sudo apt-get install gcc
```
### Installing
cd into the files directory and compile both.
```
gcc -pthread main.c pithread.h pithread.c
```
You should see both executable into directory.
