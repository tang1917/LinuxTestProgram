/*************************************************************************
    > File Name: block_read.c
    > Author: zll
    > Mail: zhnllion@126.com 
    > Created Time: 2021年04月22日 星期四 14时41分08秒
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

//阻塞读终端
int main()
{
	char buf[10];
	int n;
	n = read(STDIN_FILENO,buf,10);
	if(n<0)
	{
		perror("read STDIN_FILENO");
		exit(1);
	}
	write(STDOUT_FILENO,buf,n);
	return 0;

}
