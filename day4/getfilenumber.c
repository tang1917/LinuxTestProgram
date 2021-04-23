/*************************************************************************
    > File Name: getfilenumber.c
    > Author: wzh
    > Mail: zhwang2021@163.com 
    > Created Time: 2021年04月22日 星期四 22时18分15秒
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>
#include<dirent.h>
//定义函数，指定目录中文件的个数
int get_file_num(const char* root)
{
	int total = 0;
	//读目录
	DIR* dir = NULL;
	dir = opendir(root);
	if(dir==NULL)
	{
		perror("opendir error");
		exit(1);
	}
	//循环读目录中的文件
	struct dirent* ptr = NULL;
	while((ptr=readdir(dir))!=NULL)
	{
		//不处理.和..目录
		if(strcmp(".",ptr->d_name)==0||strcmp("..",ptr->d_name)==0)
		{
			continue;
		}
		//判断是不是普通文件
		//if(ptr->d_type==DT_REG)
		{
			++total;
		}
		//如果是目录，递归
		if(ptr->d_type==DT_DIR)
		{
			//求出子目录
			char path[1024]={0};
			sprintf(path,"%s/%s",root,ptr->d_name);
			total += get_file_num(path);
		}
	}
	//关闭目录
	closedir(dir);
	return total;
}

int main(int argc,const char* argv[])
{
	if(argc<2)
	{
		printf("./a.out path\n");
		exit(1);
	}
	int total = get_file_num(argv[1]);
	printf("%s 目录下普通文件共：%d个\n",argv[1],total);
}

