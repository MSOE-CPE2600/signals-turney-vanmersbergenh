/**
 * File: signal_alarm.c
 * Modified by: Hunter Van Mersbergen
 * 
 * Brief summary of program: Sends SIGALRM after 5 seconds and handles it.
 */
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void handle_alarm() {
    printf("Received SIGALRM\n");
}

int main() {
    printf("5 second alarm\n");
    signal(SIGALRM, handle_alarm);
    alarm(5);
    pause();

    return 0;
}