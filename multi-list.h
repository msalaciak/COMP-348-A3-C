//
//  multi-list.h
//  comp-348-question-2
//
//  Created by Matt Salaciak on 2020-04-12.
//  Copyright © 2020 Matt Salaciak. All rights reserved.
//

#ifndef multi_list_h
#define multi_list_h
#define STRINGSIZE 200
#include <stdio.h>

typedef struct node {
    const char data[STRINGSIZE];
    struct node* next;
    struct node* below;
    int test;
} node;



typedef struct CarModel {
    
   char model_list[STRINGSIZE];
   int counter;
 
    int size;
} CarModel;

typedef struct CarMaker {
   char carMake[STRINGSIZE];
   int counter;
   
  
} CarMaker;

void printCarMakers(node * head);
void printCarModels(node* head);
void printEntireList(node* head);

void insertCarMaker(node * head, int val);

void insertCarModel(node * head, int val, int pos);




#endif /* multi_list_h */
