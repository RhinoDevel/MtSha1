# MT, 2016apr02

# Original source: http://mrbook.org/blog/tutorials/make/

CC=gcc
#CFLAGS=-c -O3 -std=gnu11 -Wall -DNDEBUG
CFLAGS=-c -g -std=gnu11 -Wall
#LDFLAGS=
LDFLAGS=-g
SOURCES=main.c Sys.c Sha1.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=mtsha1

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm $(OBJECTS) $(EXECUTABLE)
