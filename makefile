CC         = gcc
CFLAGS     = -c -Wall -Wextra
SOURCES    = $(wildcard *.c) $(wildcard sources/*.c)
EXECUTABLE = alloc
OBJECTS    = $(SOURCES:.c=.o)

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	@ echo "\033[32;1mCreating executable:\033[0m\t$(EXECUTABLE)"
	@ $(CC) $(OBJECTS) -o $@

%.o: %.c
	@ echo "\033[32;1mCompiling:\033[0m\t$<"
	@ $(CC) $(CFLAGS) -c -o $@ $<

clean:
	@ echo "\033[32;1mCleaning object files and executable\033[0m"
	@ -rm -r sources/*o *o $(EXECUTABLE) 2> /dev/null
