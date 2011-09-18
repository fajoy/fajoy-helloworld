CC=/usr/bin/gcc

all:
	$(CC) -o helloworld helloworld.c

clean:
	@rm *.o *~
