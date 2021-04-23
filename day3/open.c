/*************************************************************************
    > File Name: open.c
    > Author: zll
    > Mail: zhnllion@126.com 
    > Created Time: 2021年04月21日 星期三 22时35分42秒
 ************************************************************************/

#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
int main(int argc,const char* argv[])
{
	//打开一个文件 hello 
    int fd = open("hello",O_RDWR|O_CREAT,0777);
	if(fd==-1)
	{
		printf("打开失败\n");

	}
	close(fd);
	return 0;
}
