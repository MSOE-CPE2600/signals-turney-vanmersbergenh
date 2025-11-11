CFLAGS=-c -g -Wall -Werror
CC=gcc

all: signal_segfault signal_alarm recv_signal send_signal signal_handler signal_sigaction tennis1 tennis2

signal_alarm: signal_alarm.o
	$(CC) -o signal_alarm signal_alarm.o

recv_signal: recv_signal.o
	$(CC) -o recv_signal recv_signal.o

send_signal: send_signal.o
	$(CC) -o send_signal send_signal.o

signal_handler: signal_handler.o
	$(CC) -o signal_handler signal_handler.o

signal_sigaction: signal_sigaction.o
	$(CC) -o signal_sigaction signal_sigaction.o

signal_segfault: signal_segfault.o
	$(CC) -o signal_segfault signal_segfault.o

tennis1: tennis1.o
	$(CC) -o tennis1 tennis1.o

tennis2: tennis2.o
	$(CC) -o tennis2 tennis2.o

clean:
	rm -f *.o signal_alarm recv_signal send_signal signal_handler signal_sigaction signal_segfault tennis1 tennis2
%.o: %.c
	$(CC) $(CFLAGS) -o $@ $<