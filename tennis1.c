/**********************************************************
* @file tennis1.c
* @brief Player 1 of the tennis signal simulation
* Author: Hunter Van Mersbergen
* Class: CPE2600 121
* Date: 11/10/25
* Compile: make
***********************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>

/**
* Handles the SIGUSR1 signal to return the ball to Player 2.
*
* @param signum The signal number.
* @param info The signal information, used to obtain Player 2's PID.
* @param context The signal context.
*/
void return_ball(int signum, siginfo_t *info, void *context) 
{
    printf("Player 2 Returned the ball (received signal)\n");
    srand(time(NULL));
    sleep(rand() % 3 + 1);
    if (rand() % 7 == 0) {
        printf("Player 1: Missed\n");
        printf("Player 2 Wins\n");
        kill(info->si_pid, SIGTERM);
        exit(0);
        return;
    }
    printf("Player 1: Returning (sending the signal)\n");
    kill(info->si_pid, SIGUSR1); // Send signal to opponent
}

/**
* Handles the SIGTERM signal when Player 2 misses the ball.
*/
void win() 
{
    printf("Player 2 missed the ball.\n");
    printf("Player 1 wins the game.\n");
    exit(0);
}

int main(void) 
{
    FILE *fp = fopen("tennis_handshake.txt", "w");
    if (fp == NULL) {
        perror("Error creating handshake file");
        return 1;
    }
    fprintf(fp, "%d\n", getpid());
    fclose(fp);

    struct sigaction sa;
    sa.sa_sigaction = return_ball;
    sa.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &sa, NULL);

    struct sigaction sa_term;
    sa_term.sa_sigaction = win;
    sa_term.sa_flags = SA_SIGINFO;
    sigaction(SIGTERM, &sa_term, NULL);

    printf("Waiting for Player 2 to serve.\n");
    while (1) {
        pause();
    }

    return 0;
}