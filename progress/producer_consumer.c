/*************************************************************************
    > File Name: producer_consumer.c
    > Author: wzh
    > Mail: zhwang2021@163.com 
    > Created Time: 2021年04月27日 星期二 22时53分26秒
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>
#include<pthread.h>

//结点结构
typedef struct node
{
	int data;
	struct node* next;
}Node;
//永远指向链表头部的指针
Node* head = NULL;

//线程同步，互斥锁
pthread_mutex_t mutex;
//阻塞线程 --条件变量类型的变量
pthread_cond_t cond;
//生产者
void* producer(void* arg)
{
	while(1)
	{
		//创建一个链表的结点
		Node* pnew = (Node*)malloc(sizeof(Node));
		//结点的初始化
		pnew->data = rand()%1000;
		//使用互斥锁保护共享数据
		pthread_mutex_lock(&mutex);
		//指针域
		pnew->next = head;
		head = pnew;
		printf("==========produce:%lu,%d\n",pthread_self(),pnew->data);
		//解锁
		pthread_mutex_unlock(&mutex);
		//通知阻塞的消费者线程，接触阻塞
		pthread_cond_signal(&cond);

		sleep(rand()%3);
	}
	return NULL;
}
void* consumer(void* arg)
{
	while(1)
	{
		pthread_mutex_lock(&mutex);
		//判断链表是否为空
		if(head==NULL)
			//线程阻塞
			pthread_cond_wait(&cond,&mutex);
		//链表不为空，删掉一个结点，删除头结点
		Node* pdel = head;
		head = head->next;
		printf("-----customer:%lu,%d\n",pthread_self(),pdel->data);
		free(pdel);
		pthread_mutex_unlock(&mutex);
	}
	return NULL;
}

int main(int argc,const char* argv[])
{
	pthread_t p1,p2;
	//init
	pthread_mutex_init(&mutex,NULL);
	pthread_cond_init(&cond,NULL);

	//创建生产者线程
	pthread_create(&p1,NULL,producer,NULL);
	//创建消费者线程
	pthread_create(&p2,NULL,consumer,NULL);

	//阻塞回收线程
	pthread_join(p1,NULL);
	pthread_join(p2,NULL);

	pthread_mutex_destroy(&mutex);
	pthread_cond_destroy(&cond);
	return 0;
}
