/*************************************************************************
    > File Name: signal_seize.c
    > Author: wzh
    > Mail: zhwang2021@163.com 
    > Created Time: 2021年04月26日 星期一 10时40分08秒
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<signal.h>
#include<string.h>

void myfunc(int no)
{
	printf("catch you signal:%d\n",no);
}
int main(int argc,const char* argv[])
{
	//捕捉ctrl+c
	//注册捕捉函数
	signal(SIGINT,myfunc);
	while(1)
	{
		sleep(1);
		printf("hello,world.\n");
	}
	return 0;
}




