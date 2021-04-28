/*************************************************************************
    > File Name: pthread_create.c
    > Author: wzh
    > Mail: zhwang2021@163.com 
    > Created Time: 2021年04月26日 星期一 22时58分47秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>//线程对应的头文件
void* myfunc(void* arg)
{
	//打印子线程的id
	printf("child thread id:%lu\n",pthread_self());
	return NULL;
}
int main(int argc,const char* argv[])
{
	//创建一个子线程
	//线程ID变量
	pthread_t pthid;

	int ret = pthread_create(&pthid,NULL,myfunc,NULL);
	if(ret!=0)
	{
		printf("error number:%d\n",ret);
		//打印错误信息
		printf("%s\n",strerror(ret));
	}
	printf("parent thread id:%lu\n",pthread_self());
    
	//退出主线程
	pthread_exit(NULL);

	for(int i=0;i<5;++i)
	{
		printf("i=%d\n",i);
	}
	sleep(3);
	return 0;
}
