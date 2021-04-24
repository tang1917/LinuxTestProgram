/*************************************************************************
    > File Name: execl.c
    > Author: wzh
    > Mail: zhwang2021@163.com 
    > Created Time: 2021年04月23日 星期五 21时49分52秒
 ************************************************************************/

#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main(int argc,char* argv[])
{
	//父进程数数
	for(int i=0;i<8;++i)
	{
		printf("parent i=%d\n",i);
	}
	//创建一个子进程
	pid_t pid = fork();

	//让子进程执行ls命令
	if(pid==0)
	{
		execl("/bin/ls","ls","-l",NULL);
	}
	for(int i=0;i<3;++i)
	{
		printf("+++++++++++++++++i=%d\n",i);
	}
	return 0;
}
