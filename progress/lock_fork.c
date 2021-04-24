/*************************************************************************
    > File Name: lock_fork.c
    > Author: wzh
    > Mail: zhwang2021@163.com 
    > Created Time: 2021年04月23日 星期五 20时19分43秒
 ************************************************************************/

#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main(int atgc,const char* argv[])
{
	pid_t pid;
	int i=0;
	for(i=0;i<5;++i)
	{
		pid = fork();
		if(pid==0)
			break;
	}
	switch(i)
	{
		case 0:printf("first process,pid=%d\n",getpid());break;
		case 1:printf("second process,pid=%d\n",getpid());break;
		case 2:printf("third process,pid=%d\n",getpid());break;
		case 3:printf("fourth process,pid=%d\n",getpid());break;
		case 4:printf("fifth process,pid=%d\n",getpid());break;
		case 5:printf("parent process,pid=%d\n",getpid());break;
		default:printf("error");break;
	}
	return 0;
}

