#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define SIZE 100000000

int *arr;
long long total_sum=0;
typedef struct{
    int start;
    int end;
}  ThreadData;
pthread_mutex_t lock;
void *worker(void *arg)
{
   ThreadData *data = (ThreadData *)arg;
   long long local_sum=0;
   for(int i=data->start; i < data->end; i++)
        local_sum+=arr[i];
   pthread_mutex_lock(&lock);
   total_sum+=local_sum;
   pthread_mutex_unlock(&lock);
   return NULL;
}
int main(int argc,char *argv[])
{
    if(argc !=2)
    {
        printf("Usage : %s <threads>\n", argv[0]);
        return 1;
    }
    int threads = atoi(argv[1]);
    arr = malloc(sizeof(int)*SIZE);
    for(int i =0; i<SIZE;i++)
        arr[i]=1;
    pthread_t tid[threads];
    ThreadData data[threads];
    pthread_mutex_init(&lock,NULL);
    int chunk = SIZE / threads;
    for(int i=0; i<threads;i++)
    {
        data[i].start = i * chunk;
        if(i == threads - 1)
           data[i].end= SIZE;
        else
            data[i].end=(i+1)*chunk;
        pthread_create(&tid[i], NULL,worker,&data[i]);
    }
    for(int i=0; i< threads; i++)
        pthread_join(tid[i],NULL);
    printf("Total SUM = %lld\n", total_sum);
    pthread_mutex_destroy(&lock);
    free(arr);
    return 0;
}
