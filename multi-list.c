//
//  multi-list.c
//  comp-348-question-2
//
//  Created by Matt Salaciak on 2020-04-12.
//  Copyright © 2020 Matt Salaciak. All rights reserved.
//

#include "multi-list.h"

void printCarMakers(node* head) {
    node * current = head;


    while (current != NULL) {
        printf("%d\n", current->test);

        current = current->next;
    }
}

void printCarModels(node* head)
{
    node * current = head->below;
  while(current != NULL){
    printf("%d\n", current->test);
      current = current->below;
  }

}


void printEntireList(node* head) {
    node * current = head;


    while (current != NULL) {
        printf("%d\n", current->test);
        printCarModels(current);
        current = current->next;
    }
}


void insertCarMaker(node * head, int val) {
node * current = head;
while (current->next != NULL) {
    current = current->next;
}
    
    current->next = (node *) malloc(sizeof(node));
    current->next->test = val;
    current->next->next = NULL;
    current->next->below = NULL;

}

void insertCarModel(node * head, int val, int pos) {
node * current = head;
    
    while (current->next != NULL) {
        if(current->test == pos) {
            break;
        } else {
            current = current->next;
        }
        
    }
   
while (current->below != NULL) {
    current = current->below;
}
    
    current->below = (node *) malloc(sizeof(node));
    current->below->test = val;
     current->below->next = NULL;
    current->below->below = NULL;


}

void search(node *head, int key){
    while (head != NULL){
        if (head->test == key){
            printf("key found\n");
            printCarModels(head);
            return;
        }
        head = head->next;
}
    printf("Key not found\n");

}
