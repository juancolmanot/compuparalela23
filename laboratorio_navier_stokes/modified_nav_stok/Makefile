CC=gcc
OPTFLAGS? =
NOFLAGS = -Wno-implicit-function-declaration -Wno-unused-parameter -Wno-unused-variable
CFLAGS=-std=c11 -Wall -Wextra $(NOFLAGS) $(OPTFLAGS)
LDFLAGS=


TARGETS=demo headless compute_stats
SOURCES=$(shell echo *.c)
COMMON_OBJECTS=solver.o wtime.o

all: $(TARGETS)

demo: demo.o $(COMMON_OBJECTS)
	$(CC) $(CFLAGS) $(OPTFLAGS) $^ -o $@ $(LDFLAGS) -lGL -lGLU -lglut

headless: headless.o $(COMMON_OBJECTS)
	$(CC) $(CFLAGS) $(OPTFLAGS) $^ -o $@ $(LDFLAGS)

compute_stats: compute_stats.o
	$(CC) $(CFLAGS) $(OPTFLAGS) $^ -o $@ $(LDFLAGS)

clean:
	rm -f $(TARGETS) *.o .depend *~

.depend: *.[ch]
	$(CC) -MM $(SOURCES) >.depend

-include .depend

.PHONY: clean all
