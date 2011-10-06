#include <stdio.h>
#include <string.h>
#include <sys/mman.h>
static int testValue = 0;
extern int DstStart,DstEnd,SrcStart,SrcEnd;

int (*callPrintf)( const char *format, ... );
int main()
{	

	printf("pageSize=%d\n",getpagesize());
	printf("&Src Start=%p  End=%p Size=%d\n",&SrcStart,&SrcEnd,(int)&SrcEnd - (int) &SrcStart);
	printf("&Dst Start=%p  End=%p Size=%d\n",&DstStart,&DstEnd,(int)&DstEnd - (int) &DstStart);

	unsigned page = (unsigned) &DstStart & ~( getpagesize() - 1 );
	/* chmod memory page=rwx page */
	if (mprotect((char*) page,
				getpagesize(),
				PROT_READ | PROT_WRITE | PROT_EXEC ) ) {
		perror( "mprotect failed" );
	}
	memcpy(&DstStart, &SrcStart,  (int)&SrcEnd - (int) &SrcStart);
	callPrintf=printf;
	asm volatile( "DstStart:" );
	(*callPrintf)("HelloWorld\n");
	asm volatile( "DstEnd:" );
	return 0;
}

void dummyCodeContext()
{	
	asm volatile( "SrcStart:" );
        (*callPrintf)( "Hello This Modify Code\n");
	asm volatile( "SrcEnd:" );
}

