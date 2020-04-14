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
#include <stdlib.h>
#include <string.h>

typedef struct CarInfo {
    char manufacturer[STRINGSIZE];
    char model[STRINGSIZE];
    char trim[STRINGSIZE];
    char km[STRINGSIZE];
    char year[STRINGSIZE];
    char type[STRINGSIZE];
    char driveTrain[STRINGSIZE];
    char trans[STRINGSIZE];
    char IDnum[STRINGSIZE];
    char status[STRINGSIZE];
} CarInfo;



typedef struct CarModel {
    
    char model_listing[STRINGSIZE];
    char brand[STRINGSIZE];
    int counter;
    int size;
    CarInfo make;

} CarModel;


typedef struct CarMaker {
    char manufacturer[STRINGSIZE];
    struct CarMaker* next;
    struct CarMaker* below;
    CarModel car;
    CarInfo make;
    int size;
 
} CarMaker;





void printCarMakers(CarMaker * head);
void printCarModels(CarMaker* head);
void printEntireList(CarMaker* head);
void insertCarMaker(CarMaker * head, char *maker, CarInfo * make, CarModel *model);
void insertCarModel(CarMaker * head, CarModel *model ,char *maker, CarInfo * make);
void searchInventory(CarMaker *head, char *maker);
void convertListings2Catalougue(CarMaker *head,char *fileName);
void Add2Inventory (CarMaker *head, char * car);
void saveCatalogue2File(CarMaker *head,char *fileName);




#endif /* multi_list_h */
