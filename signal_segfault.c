/**
 * @file signal_segfault.c
 * @brief Program that dereferences a null pointer causing a segmentation fault
 */

/**
 * Modified by: Hunter Van Mersbergen
 * 
 * Brief summary of modifications: 
 * Added signal_handler() to handle the sementation fault but not exit the program.
 */

#include <stdio.h>
#include <signal.h>

void signal_handler() {
    printf("Segmentation fault handled.\n");
}

int main (int argc, char* argv[]) {
    // Declare a null pointer
    int* i = NULL;

    signal(SIGSEGV, signal_handler); 
    // Dereference the null pointer
    printf("The value of i is: %d\n", *i);

    // Return to exit the program
    return 0;
}