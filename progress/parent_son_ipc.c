/*************************************************************************
    > File Name: parent_son_ipc.c
    > Author: wzh
    > Mail: zhwang2021@163.com 
    > Created Time: 2021年04月24日 星期六 17时11分00秒
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>


int main(int argc,const char* argv[])
{
	int fd[2];
	int ret = pipe(fd);
	if(ret==-1)
	{
		perror("pipe error");
		exit(1);
	}
	pid_t pid = fork();
	if(pid==-1)
	{
		perror("fork error");
		exit(1);
	}
	//父进程
	//ps fork
	if(pid>0)
	{
		//写管道操作，关闭读端
		close(fd[0]);
		//文件描述符重定向
		//stdout_fileno ->> 管道的写端
		dup2(fd[1],STDOUT_FILENO);
		//执行ps aux
		execlp("ps","ps","aux",NULL);
		perror("excelp");
		exit(1);
	}
	//子进程
	//grep "bash"
	else if(pid==0)
	{
		close(fd[1]);
		dup2(fd[0],STDIN_FILENO);
		execlp("grep","grep","bash",NULL);
	}
	printf("pipe[0]=%d\n",fd[0]);
	printf("pipe[1]=%d\n",fd[1]);
	close(fd[0]);
	close(fd[1]);
	return 0;
	
}

