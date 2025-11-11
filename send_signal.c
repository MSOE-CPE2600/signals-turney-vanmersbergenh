/**
 * File: 
 * Modified by:
 * 
 * Brief summary of program:
 */
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int num = rand();

    int pid;
    scanf("%d", &pid);

    sigqueue(pid, SIGUSR1, (union sigval){.sival_int = num});
    
    return 0;
}