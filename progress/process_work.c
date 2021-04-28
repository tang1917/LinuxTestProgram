/*************************************************************************
    > File Name: process_work.c
    > Author: wzh
    > Mail: zhwang2021@163.com 
    > Created Time: 2021年04月26日 星期一 20时14分43秒
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<string.h>
#include<signal.h>
#include<sys/time.h>
#include<time.h>
#include<fcntl.h>

void dowork(int no)
{
	//得到当前系统的时间
	time_t curtime;
	time(&curtime);
	//格式化时间
	char* pt= ctime(&curtime);
	//将时间写入文件
	int fd = open("/home/wzh/文档/mynotes/time.txt",O_CREAT|O_WRONLY|O_APPEND,0664);
	write(fd,pt,strlen(pt)+1);
	close(fd);
}
int main()
{
	pid_t pid = fork();
	if(pid>0)
	{
		//父进程退出
		exit(1);
	}
	else if(pid==0)
	{
		//变成了会长，脱离控制终端，守护进程
		setsid();
		//改变进程的工作目录。省略
		//重置文件掩码
		umask(0);
		//关闭文件描述符
		close(STDIN_FILENO);
		close(STDOUT_FILENO);
		close(STDERR_FILENO);
		//执行核心操作
		//注册信号捕捉
		struct sigaction act;
		act.sa_flags = 0;
		act.sa_handler = dowork;
		sigemptyset(&act.sa_mask);
		sigaction(SIGALRM,&act,NULL);
		//创建定时器
		struct itimerval val;
		//第一次触发定时器时间
		val.it_value.tv_usec = 0;
		val.it_value.tv_sec = 2;
		//循环周期
		val.it_interval.tv_usec = 0;
		val.it_interval.tv_sec = 3;
		setitimer(ITIMER_REAL,&val,NULL);
		while(1);
	}
	return 0;
}
