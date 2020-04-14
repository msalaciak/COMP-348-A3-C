////Matthew Salaciak
//29644490
//  multi-list.h
//  comp-348-question-2
//
//Header file that contains the structs and methods for our multi-list "struct"
//

#ifndef multi_list_h
#define multi_list_h
#define STRINGSIZE 200
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//carInfo is a struct that just holds the parsed information per car - this was very useful when designing the search method
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


//the carModel struct, it holds the entire listing information, a CarInfo object, and other variables
typedef struct CarModel {
    
    char model_listing[STRINGSIZE];
    char brand[STRINGSIZE];
    int counter;
    int size;
    CarInfo make;

} CarModel;

//CarMaker struct, this holds information related to the CarMaker but also it is our node struct
//it contains pointers to next and below (below being the multi list dimension)
//it also contains a CarModel and CarInfo struct to hold their information
typedef struct CarMaker {
    char manufacturer[STRINGSIZE];
    struct CarMaker* next;
    struct CarMaker* below;
    CarModel car;
    CarInfo make;
    int size;
 
} CarMaker;




//funcitons to print (printCarMakers and printCarModels was mainly used for debugging in the beginning.)
void printCarMakers(CarMaker * head);
void printCarModels(CarMaker* head);
void printEntireList(CarMaker* head);

//insert functions, these functions insert CarMaker,CarModel structs into the multi-list
void insertCarMaker(CarMaker * head, char *maker, CarInfo * make, CarModel *model);
void insertCarModel(CarMaker * head, CarModel *model ,char *maker, CarInfo * make);

// search function
void searchInventory(CarMaker *head, char *maker);

//convert text file from ruby Q5 output and makes inventor system
void convertListings2Catalougue(CarMaker *head,char *fileName);

// adds a line to the inventory system
void Add2Inventory (CarMaker *head, char * car);

//saves everything to text file
void saveCatalogue2File(CarMaker *head,char *fileName);




#endif /* multi_list_h */
