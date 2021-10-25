DIR = ./
CC = gcc
# -rdynamic: to allow obtaining backtraces from within a program
CFLAGS = -O1 -g -Wall -Werror -Idudect -I. -rdynamic

# Control the build verbosity
ifeq ("$(VERBOSE)","1")
	Q :=
	VECHO = @true
else
	Q := @
	VECHO = @printf
endif

main: main.c 
	${VECHO} "  CC\t$@\n"
	gcc -o main main.c 
	

run: ${DIR}main 

clean:
	rm -f main
