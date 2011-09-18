CC=/usr/bin/gcc
main=helloworld
maindir=$(shell pwd)

all:
	$(CC) -o $(main) $(main).c

run:$(main).c
	$(CC) -o $(main).o $(main).c
	$(maindir)/$(main).o

clean:
	@rm *.o *~
