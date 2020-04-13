//
//  multi-list.c
//  comp-348-question-2
//
//  Created by Matt Salaciak on 2020-04-12.
//  Copyright © 2020 Matt Salaciak. All rights reserved.
//

#include "multi-list.h"

void printCarMakers(CarMaker* head) {
    CarMaker * current = head;
    
    
    while (current != NULL) {
        printf("%s ", current->manufacturer);
        
        current = current->next;
    }
}

void printCarModels(CarMaker* head)
{
    CarMaker * current = head->below;
    while(current != NULL){
        printf("%s \n", current->car.model_listing);
        current = current->below;
    }
    
}


void printEntireList(CarMaker* head) {
    CarMaker * current = head;
    
    
    while (current != NULL) {
        printCarMakers(current);
        printCarModels(current);
        current = current->next;
    }
}


void insertCarMaker(CarMaker * head, char *maker) {
    CarMaker * current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    
    current->next = (CarMaker *) malloc(sizeof(CarMaker));
  
    strcpy(current->next->manufacturer,maker);
    current->next->next = NULL;
    current->next->below = NULL;
    current->size++;
    
}

void insertCarModel(CarMaker * head, CarModel *model, char *maker) {
    CarMaker * current = head;
    
    while (current->next != NULL) {
        if(current->manufacturer == maker) {
            break;
        } else {
            current = current->next;
        }
        
    }
    
       
    while (current->below != NULL) {
        current = current->below;
    }
    
    current->below = (CarMaker *) malloc(sizeof(CarMaker));
    current->below->car = *model;
//    strcpy(current->below->car.model_listing,model);
    current->below->next = NULL;
    current->below->below = NULL;
    
    
}

void search(CarMaker *head, char *maker){
    printf("%s \n" , maker);
  
    while (head != NULL){
        if (strcmp(head->manufacturer,maker) == 0){
            printf("key found\n");
            printCarModels(head);
            return;
        }
        head = head->next;
    }
    printf("Key not found\n");
    
}
