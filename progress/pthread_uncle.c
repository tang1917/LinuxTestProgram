/*************************************************************************
    > File Name: pthread_uncle.c
    > Author: wzh
    > Mail: zhwang2021@163.com 
    > Created Time: 2021年04月27日 星期二 16时02分43秒
 ************************************************************************/

#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>
#include<pthread.h>
#include<unistd.h>

#define MAX 10000
//全局变量
int number;
//创建一把互斥锁
pthread_mutex_t mutex;

//线程处理函数
void* funcA_num(void* arg)
{
	for(int i=0;i<MAX;++i)
	{
		//访问全局变量之前加速
		pthread_mutex_lock(&mutex);
		int cur = number;
		cur++;
		number = cur;
		printf("Thread A,id=%lu,number=%d\n",pthread_self(),number);
		//解锁
		pthread_mutex_unlock(&mutex);
		usleep(10);

	}
	return NULL;
}
void* funcB_num(void* arg)
{
	for(int i=0;i<MAX;++i)
	{
		//访问全局变量之前加速
		pthread_mutex_lock(&mutex);
		int cur = number;
		cur++;
		number = cur;
		printf("Thread B,id=%lu,number=%d\n",pthread_self(),number);
		//解锁
		pthread_mutex_unlock(&mutex);
		usleep(10);

	}
	return NULL;
}


int main(int argc,const char* argv[])
{
	pthread_t p1,p2;
	//初始化互斥锁
	pthread_mutex_init(&mutex,NULL);

	//创建两个子进程
	pthread_create(&p1,NULL,funcA_num,NULL);
	pthread_create(&p2,NULL,funcB_num,NULL);

	//阻塞，资源回收
	pthread_join(p1,NULL);
	pthread_join(p2,NULL);

	//释放互斥锁资源
	pthread_mutex_destroy(&mutex);
	return 0;
}




