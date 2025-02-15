#ifndef _RELATION_H_
#define _RELATION_H_

#include "../HEADERS/tuple.h"


typedef struct relation {
	tuple *tuples;
	int num_tuples;
	uint64_t l;//minimum value
  	uint64_t u;//maximum value
  	float f;//number of values
  	float d;//number of distinct values
  	char * d_table;//used for finding the d
  	uint64_t prev_l;//used for restoring the previous value when we create the exec trees
  	uint64_t prev_u;//used for restoring the previous value when we create exec _TREES_H__
  	float prev_f;// ""
 	float prev_d;// ""
  	char restored;
} relation ;


typedef struct relation_data{
  uint64_t numColumns;
  uint64_t numTuples;
  relation **columns;     //pinakas apo deiktes stin arxi kathe column
} relation_data;


typedef struct all_data{
  relation_data ** table;  //array of pointers to relation_data
  int num_relations;       //number of total relations
} all_data;;


relation_data *relation_data_create ( relation_data * );

relation_data *relation_data_create_relations ( relation_data * , uint64_t , uint64_t );


relation * relation_create ( relation * /*relation to be created*/ ) ;

relation * relation_createtuples ( relation * , int /*tota tuples of relation*/) ;


relation_data *relation_copy ( relation_data * , relation_data * ); 

void relation_setkey ( relation * , int  /*position of tuple that we want to set*/ , uint64_t /*key we want to set*/ ) ;

uint64_t relation_getkey ( relation * , int /*position of tuple that we want to get*/) ;

void relation_setpayload ( relation * , int /*position of tuple that we want to set*/ , uint64_t /*payload we want to set*/ ) ;

uint64_t relation_getpayload ( relation * , int tup /*position of tuple that we want to get*/) ;

int relation_getnumtuples ( relation * ) ;

int relation_checkifsorted ( relation *  ) ;

int isEqual(relation * , relation * , uint64_t , uint64_t );

int isGreater (relation * , relation * , int , int );

void relation_print ( relation * ) ;

void relation_free ( relation * ) ;




#endif