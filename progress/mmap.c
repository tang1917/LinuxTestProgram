/*************************************************************************
    > File Name: mmap.c
    > Author: wzh
    > Mail: zhwang2021@163.com 
    > Created Time: 2021年04月24日 星期六 21时46分43秒
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>
#include<sys/mman.h>
#include<fcntl.h>
int main(int argc,const char* argv[])
{
	//打开一个文件
	int fd = open("poetry.txt",O_RDWR);
	int len = lseek(fd,0,SEEK_END);
	if(fd<0)
	{
		perror("open error");
		exit(1);
	}
	//创建内存映射区
	void* ptr = mmap(NULL,len,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
	if(ptr == MAP_FAILED)
	{
		perror("mmap error");
		exit(1);
	}
	printf("%s",(char*)ptr);
	//释放内存，关闭文件
	munmap(ptr,len);
	close(fd);
	return 0;

}
