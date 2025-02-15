#ifndef _THREADPOOL_H
#define _THREADPOOL_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <ctype.h>
#include <strings.h>
#include <pthread.h>
#include <unistd.h>
#include "../HEADERS/job_list.h"

#define MAX_THREADS 1

//STRUCT

typedef struct {
	job_list *queue;
	char **results;
	pthread_t threads[MAX_THREADS];
	pthread_mutex_t get_job;
	pthread_mutex_t thread_join;
	pthread_mutex_t thread_create;
} threadpool;



void  execute_all_batches_threads ( char *filename , all_data *datatable , threadpool *thp );

void start_threads ( threadpool *thp );

void *thread_test ( void *);

void join_threads ( threadpool * );

//CONSTRUCTOR

threadpool *threadpool_create ( threadpool * );

void threadpool_destroy ( threadpool * );


#endif