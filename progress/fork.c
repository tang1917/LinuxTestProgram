/*************************************************************************
    > File Name: fork.c
    > Author: wzh
    > Mail: zhwang2021@163.com 
    > Created Time: 2021年04月23日 星期五 19时11分36秒
 ************************************************************************/

#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main(int argc,const char* argv[])
{
	pid_t pid;
	for(int i=0;i<4;++i)
	{
		printf("-----------i=%d\n",i);
	}
	pid = fork();
	//父进程
	if(pid>0)
	{
		printf("parent process,pid=%d\n",getpid());
	}
	//子进程
	else if(pid==0)
	{
		printf("child process,pid=%d,ppid=%d\n",getpid(),getppid());
	}
	for(int i=0;i<4;++i)
	{
		printf("i=%d\n",i);
	}
	return 0;
}
