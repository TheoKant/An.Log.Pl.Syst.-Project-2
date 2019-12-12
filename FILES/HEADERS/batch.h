#ifndef _BATCH_H
#define _BATCH_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <ctype.h>
#include <strings.h>
#include "../HEADERS/predicates.h"
#include "../HEADERS/relation.h"
#include "../HEADERS/inbetween.h"




typedef struct
{
	char **batch;
	int size;
} Batch_lines;


typedef struct
{
	Batch_lines *batches;
	int size;
} Batches;




void fillBatches(Batches *batches, char *s, char *filename);

void free_all_batches(Batches * batches);

Batches * createBatches(char *filename, char *s);

void execute_all_batches(char* filename, all_data * datatable); //read all batched from the file

void execute_batch(Batch_lines * batch_lines, all_data * datatable );

void execute_query(char * query, all_data *datatable);

int find_num_of_relations(char * rel_line);

int find_num_of_predicates(char * pred_line);

void fill_predicates(char *pred_str, Predicates *pd, int *alias_array);

void fill_relations(char *rel_str, int* alias_array);

int isnumber(char * number);




#endif