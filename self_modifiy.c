#include <stdio.h>
#include <string.h>
#include <sys/mman.h>
static int counter = 0;
extern int Here, Start,End;

int main()
{
	unsigned page = (unsigned) &Here & ~( getpagesize() - 1 );
	/* chmod u=rwx page */
	if (mprotect((char*) page,
				getpagesize(),
				PROT_READ | PROT_WRITE | PROT_EXEC ) ) {
		perror( "mprotect failed" );
	}
	memcpy(&Here, &Start,  (int)&End - (int) &Start);
	asm volatile( "Here:" );
	printf("/* Program invoked.\n");
	printf("Hello World!\n");
	printf("  #%d */\n", ++counter);
	printf("%d\n",getpagesize());
	return 0;
}

void dummyCodeContext()
{
	int (*callPrintf)( const char *format, ... );
	asm volatile( "Start:" );
	(*(callPrintf=&printf))( "/* Dummy code context invoked.\n");
	asm volatile( "End:" );
}

