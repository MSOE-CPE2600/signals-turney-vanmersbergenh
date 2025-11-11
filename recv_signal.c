/**
 * File: 
 * Modified by:
 * 
 * Brief summary of program:
 */
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

/**
* Handles the SIGUSR1 signal and prints the number from the sender.
*/
void handle_signal(int signum, siginfo_t *info, void *context) {
    printf("Received SIGUSR1 from: %d\n", info->si_pid);
    printf("sival_int: %d\n", info->si_value.sival_int);
    return;
}

int main() {
    printf("%d\n", getpid());

 struct sigaction sa;
    sa.sa_sigaction = handle_signal;
    sa.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &sa, NULL);

    while (1) {
        pause();
    }

    return 0;
}