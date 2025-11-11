/**
 * File: send_signal.c
 * Modified by: Hunter Van Mersbergen 
 * 
 * Brief summary of program:
 * Sends the SIGUSR1 signal with a random number to a program.
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