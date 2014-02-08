# Define the flags to control make
CC = g++
INCLUDE = -I$(shell root-config --incdir)
OPFLAGS = -O2
CFLAGS = -Wall -Wextra -std=c++11 $(INCLUDE) $(OPFLAGS)
LDFLAGS = $(shell root-config --libs) -lTreePlayer -lHistPainter


EXECUTABLE = addPVWeight

# Define the phony targets
.PHONY: clean

# The default rule
all: $(EXECUTABLE)

SOURCES = addPVWeight.cpp
OBJECTS = $(SOURCES:.cpp=.o)

$(EXECUTABLE): $(OBJECTS)
	@$(CC) $(LDFLAGS) $+ -o $@

# '$@' is expanded to the target, '$+' expanded to all the dependencies. See
# http://www.gnu.org/savannah-checkouts/gnu/make/manual/html_node/Automatic-Variables.html



%.o: %.cpp
	@$(CC) -c $(CFLAGS) $< -o $@
# '$<' is expanded to the first dependency

clean:
	@rm -f *.o
# '@' prevents the command from being printed to stdout
