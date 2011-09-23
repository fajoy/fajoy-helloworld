#include<stdio.h>
 
int main(int argc,char *argv[],char *envp[])
{
   printf("Hello World\n");
   
   int i=0;
   for(i=0;i<argc;i++){
	printf("arg[%d]=%s\n",i,argv[i]);
   }
   i=0;
   while(envp[i]){
	printf("envp[%d]=%s\n",i,envp[i]);
	i++;
   }

   return 0;
}


