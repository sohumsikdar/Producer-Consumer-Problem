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
#include<string.h>

typedef unsigned long long ull;

#define reader 449


int main() {
    while(1) {
        for(int i = 0; i < 1e6; i++);
        ull deq = -1;
        int res = syscall(reader, &deq);
        if(deq != -1) printf("The number dequeued is: %llu\n", deq);
    }
    return 0;
}