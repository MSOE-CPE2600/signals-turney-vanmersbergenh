/**
 * File: signal_sigaction.c
 * Modified by: Hunter Van Mersbergen
 * 
 * Brief summary of program: 
 * Handles the SIGUSR1 signal with sigaction and prints the PID of the sender.
 */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>

/**
* Handles the SIGUSR1 signal and prints the PID of the sender.
*/
void handle_signal(int signum, siginfo_t *info, void *context) {
    printf("Received SIGUSR1 from: %d\n", info->si_pid);
}


int main() {
    struct sigaction sa;
    sa.sa_sigaction = handle_signal;
    sa.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &sa, NULL);

    printf("PID: %d\n", getpid()); // PID to send the signal

    while (1) {
        pause();
    }

    return 0;
}


