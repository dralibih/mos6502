OBJS = main.o addressing_modes.o fetch_cycle.o execute_cycle.o instruction_set.o mos6502_utils.o
BINARY = programa

CFLAGS = -g -Wall

all: programa

programa: $(OBJS)
	gcc -o $@ $?

%.o: %.c
	gcc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(BINARY) $(OBJS)
