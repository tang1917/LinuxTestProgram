/*************************************************************************
    > File Name: signal_producer_consumer.c
    > Author: wzh
    > Mail: zhwang2021@163.com 
    > Created Time: 2021年04月28日 星期三 11时33分39秒
 ************************************************************************/

#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>

//创建信号量
sem_t sem_p,sem_c;
typedef struct node
{
	int data;
	struct node* next;
}Node;

Node* head = NULL;
void* producer(void* arg)
{
	while(1)
	{
		sem_wait(&sem_p);
		Node* pnew = (Node*)malloc(sizeof(Node));
		pnew->data = rand()%1000;
		pnew->next = head;
		head = pnew;
		printf("++++生产者：%lu,%d\n",pthread_self(),pnew->data);
		sem_post(&sem_c);
		sleep(rand()%5);
	}
	return NULL;
}
void* consumer(void* arg)
{
	while(1)
	{
		sem_wait(&sem_c);
		Node* del = head;
		head = head->next;
		printf("--------消费者：%lu,%d\n",pthread_self(),del->data);
		free(del);
		sem_post(&sem_p);

		sleep(rand()%5);
	}
	return NULL;
	
}
int main(int argc,char* argv[])
{
	//初始化信号量
	sem_init(&sem_p,0,4);
	sem_init(&sem_c,0,0);

	pthread_t p1,p2;
	//创建线程
	pthread_create(&p1,NULL,producer,NULL);
	pthread_create(&p2,NULL,consumer,NULL);

	
	//回收线程
	pthread_join(p1,NULL);
	pthread_join(p2,NULL);
	//销毁信号量
	sem_destroy(&sem_p);
	sem_destroy(&sem_c);

	return 0;

}
