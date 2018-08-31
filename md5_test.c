#include <stdio.h>
#include <string.h>
#include "md5.h"
#include<stdlib.h>


int main(int argc,char** argv)
{
//	printf("%s\n", md5_encrypt(argv[1], strlen(argv[1])));
	
	FILE* fp = NULL;

	fp = fopen(argv[1], "rb");
	
	fseek(fp,0L,SEEK_END);
	int size = ftell(fp);	
	rewind(fp);
	char *p=malloc(size);
	if(NULL==p) perror("malloc");
	fread(p,1,size,fp);
	printf("%s\n",md5_encrypt(p,size));
	free(p);	
	fclose(fp);

	return 0;
}
