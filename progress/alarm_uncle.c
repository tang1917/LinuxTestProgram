/*************************************************************************
    > File Name: alarm_uncle.c
    > Author: wzh
    > Mail: zhwang2021@163.com 
    > Created Time: 2021年04月25日 星期日 22时37分41秒
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>

int main(int argc,const char* argv[])
{
	//设置定时器
	alarm(1);
	int i=0;
	while(1)
	{
		printf("%d\n",i++);
	}
	return 0;
}

