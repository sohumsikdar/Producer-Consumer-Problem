#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<wait.h>
#include<sys/time.h>
#include<time.h>
#include<signal.h>
#include<stdint.h>
#include<inttypes.h>
#include<fcntl.h>
#include<string.h>

typedef unsigned long long ull;

#define writer 450

ull getRand(int fd) {
    unsigned char buff[8];
    read(fd, buff, sizeof(buff));
    
    ull num = 0;
    for(int i = 0; i < 8; i++) {
        num = num << 8;
        num |= buff[i];
    }   

    return num;
}

int main() {
    int fd = open("/dev/urandom", O_RDONLY);
    while(1) {
        for(int i = 0; i < 1e6; i++);
        ull num = getRand(fd);
        int res = syscall(writer, num);
        if(!res) printf("The number queued is: %llu\n", num);
    }
    return 0;
}