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




typedef struct CarModel {
    
    char model_listing[STRINGSIZE];
    int counter;
    int size;
} CarModel;

typedef struct CarMaker {
    char manufacturer[STRINGSIZE];
    struct CarMaker* next;
    struct CarMaker* below;
    int test;
    CarModel car;
    int size;
} CarMaker;



void printCarMakers(CarMaker * head);
void printCarModels(CarMaker* head);
void printEntireList(CarMaker* head);

void insertCarMaker(CarMaker * head, char *maker);

void insertCarModel(CarMaker * head, CarModel *model, char *maker);

void search(CarMaker *head, int key);




#endif /* multi_list_h */
