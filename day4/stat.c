/*************************************************************************
    > File Name: stat.c
    > Author: zll
    > Mail: zhnllion@126.com 
    > Created Time: 2021年04月22日 星期四 15时46分06秒
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>

int main(int argc,const char* argv[])
{

	struct stat st;
	int ret = stat("english.txt",&st);
	if(ret==-1)
	{

		perror("stat error");
		exit(1);
	}
	printf("file size = %d\n",(int)st.st_size);
	if((st.st_mode & S_IFMT)==S_IFREG)
	{

		printf("这个文件是一个普通文件\n");
	}

	return 0;
}
