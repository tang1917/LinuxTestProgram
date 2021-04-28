/*************************************************************************
    > File Name: sigaction.c
    > Author: wzh
    > Mail: zhwang2021@163.com 
    > Created Time: 2021年04月26日 星期一 12时59分39秒
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>
#include<signal.h>

void myfunc(int no)
{
	printf("hello,world\n");
	sleep(3);
	printf("wake up\n");
}
int main(int argc,const char* argv[])
{
	struct sigaction act;
	//初始化
	act.sa_flags = 0;
	sigemptyset(&act.sa_mask);
	//添加屏蔽信号
	sigaddset(&act.sa_mask,SIGQUIT);
	act.sa_handler = myfunc;
	sigaction(SIGINT,&act,NULL);
	while(1);
}
