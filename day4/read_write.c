/*************************************************************************
    > File Name: read_write.c
    > Author: zll
    > Mail: zhnllion@126.com 
    > Created Time: 2021年04月22日 星期四 10时48分58秒
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>
#include<fcntl.h>

int main(int argc,const char* argv[])
{

	//打开一个文件
	int fd = open("english.txt",O_RDWR);
	printf("fd=%d\n",fd);
	//打开另一个文件
	int fd1 = open("temp.txt",O_WRONLY|O_CREAT,0664);
	printf("fd1=%d\n",fd1);

	//read
	char buf[4096];
	int len = read(fd,buf,sizeof(buf));

	while(len>0)
	{

		//数据写入文件中
		int ret = write(fd1,buf,len);
		printf("ret=%d\n",ret);
		//read
		len = read(fd,buf,sizeof(buf));
	}
	close(fd);
	close(fd1);
	return 0;
}
