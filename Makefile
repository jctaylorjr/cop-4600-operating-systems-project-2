# https://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/
CC=gcc
CFLAGS=-I.
DEPS = policies.h error_check.h dataStructures.h
OBJ = memsim.o dataStructures.o fifo.o lru.o vms.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

memsim: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)