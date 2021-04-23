/*************************************************************************
    > File Name: access.c
    > Author: zll
    > Mail: zhnllion@126.com 
    > Created Time: 2021年04月22日 星期四 16时46分37秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc,char* argv[])
{

	if(argc<2)
	{

		printf("a.out filename\n");
		exit(1);
	}
	int ret = access(argv[1],W_OK);
	if(ret==-1)
	{
		perror("access");
		exit(1);
	}
	printf("you can write this file.\n");
	return 0;
}
