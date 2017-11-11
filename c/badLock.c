#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

pthread_mutex_t lock;

void doSomeThing()
{
    pthread_mutex_lock(&lock);

    printf("Hello World");

}

int main(void)
{
    doSomeThing();

    return 0;
}