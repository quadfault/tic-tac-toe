# Makefile.

prog = tic-tac-toe
objs = board.o comp.o main.o

all: $(prog)

$(prog): $(objs)
	$(CC) $(CFLAGS) -o $@ $^

board.o: board.c
comp.o: comp.c
main.o: main.c

clean:
	-rm $(prog) $(objs)

.PHONY: all clean
