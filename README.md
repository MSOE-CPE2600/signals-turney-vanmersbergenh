# Lab 10: Signals
Includes several programs related sending, recieving, and handling various signals.

## Compile
Use the included Makefile

>$ make

## Signal Handler
Handles the SIGINT signal, then does NOT exit the program.

>$ ./signal_handler

## Signal Segfault
Handles the segmentation fault, but does NOT exit the program. It returns to the same line and continues to handle the segmentation fault every time.

>$ ./signal_segfault

## Signal Alarm
Waits for 5 seconds, then handles the alarm signal it sends to itself.

>$ ./signal_alarm

## Signal Sigaction
Handles the SIGUSR1 signal and prints the PID of the sender.

>$ ./signal_sigaction

## Send and Recieve Signals
Recieves the SIGUSR1 signal and prints the random number it sent. Waits for signals until terminated.

>$ ./recv_signal

Sends the SIGUSR1 signal, with a random number included, to the specified PID.

>$ ./send_signal

> 12345

## Tennis Simulation
Begin the simulation by starting Player 1:

>$ ./tennis1

This adds Player 1's PID to a text file that Player 2 reads from to know where to serve. Start Player 2:

>$ ./tennis2

The Players will pass the ball back and forth until one of them randomly missed the ball, declaring the winner and terminating both processes.