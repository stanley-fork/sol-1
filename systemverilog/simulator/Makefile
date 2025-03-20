CC = gsim
CFLAGS = -std=c11
LIBS = -lm -lncurses

BASENAME = $(notdir $(basename $(FILE)))

.phony: all
all: sim

sim: sim.o char.o debug.o search.o
	$(CC) $(CFLAGS) -o sim sim.o char.o debug.o search.o $(LIBS)
	rm sim.o char.o debug.o search.o

sim.o: sim.c definitions.h
	$(CC) $(CFLAGS) -c sim.c -o sim.o

char.o: char.c char.h
	$(CC) $(CFLAGS) -c char.c -o char.o

debug.o: debug.c debug.h
	$(CC) $(CFLAGS) -c debug.c -o debug.o

search.o: search.c search.h
	$(CC) $(CFLAGS) -c search.c -o search.o

.phony: clean
clean:
	rm -f sim sim.o char.o debug.o search.o
