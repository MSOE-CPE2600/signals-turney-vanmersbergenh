/**********************************************************
* @file tennis2.c
* @brief Player 2 of the tennis signal simulation
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

int opponent_pid;

/**
* Handles the SIGUSR1 signal to return the ball to Player 1.
*/
void return_ball() 
{
    printf("Player 1 Returned the ball (received signal)\n");
    srand(time(NULL));
    sleep(rand() % 3 + 1);
    if (rand() % 6 == 0) {
        printf("Player 2: Missed\n");
        printf("Player 1 Wins\n");
        kill(opponent_pid, SIGTERM);
        exit(0);
        return;
    }
    printf("Player 2: Returning (sending the signal)\n");
    kill(opponent_pid, SIGUSR1); // Send signal to opponent
}

/**
* Handles the SIGTERM signal when Player 1 misses the ball.
*/
void win() 
{
    printf("Player 1 missed the ball.\n");
    printf("Player 2 wins the game.\n");
    exit(0);
}

int main(void) 
{
    FILE *fp = fopen("tennis_handshake.txt", "r");
    if (fp == NULL) {
        perror("Error opening handshake file");
        return 1;
    }
    fscanf(fp, "%d", &opponent_pid);
    fclose(fp);    
    
    printf("Player 1 PID: %d\n", opponent_pid);
    printf("Player 2 PID: %d\n", getpid());

    struct sigaction sa;
    sa.sa_sigaction = return_ball;
    sa.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &sa, NULL);

    struct sigaction sa_term;
    sa_term.sa_sigaction = win;
    sa_term.sa_flags = SA_SIGINFO;
    sigaction(SIGTERM, &sa_term, NULL);

    printf("Player 2: Serving (sending the first signal)\n");
    kill(opponent_pid, SIGUSR1);

    while (1) {
        pause();
    }

    return 0;
}