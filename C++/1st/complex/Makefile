CC= g++
CFLAGS= -c -W -Wall
LDFLAGS= 

SOURCES= complex.cpp main.cpp
EXECUTABLE= main

OBJECTS= $(SOURCES:.cpp=.o)

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o $(EXECUTABLE)
