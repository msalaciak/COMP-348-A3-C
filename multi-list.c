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
    
    CarMaker * current = head;
    CarMaker * currentBelow = head ->below;
    while(current != NULL) {
        currentBelow = current ->below;
        while(currentBelow !=NULL) {
            printf("%s \n", currentBelow->car.model_listing);
            currentBelow = currentBelow ->below;
        }
        current = current->next;
    }
    
    
    
}


void printEntireList(CarMaker* head) {
    
    CarMaker * current = head;
    CarMaker * currentBelow = head ->below;
    while(current != NULL) {
        currentBelow = current ->below;
        while(currentBelow !=NULL) {
            printf("%s,", currentBelow->car.brand);
            printf("%s \n", currentBelow->car.model_listing);
            currentBelow = currentBelow ->below;
        }
        current = current->next;
    }
    
    
    
    
    
}


void insertCarMaker(CarMaker * head, char *maker, CarInfo * make) {
    CarMaker * current = head;
    
    while (current->next != NULL) {
        current = current->next;
    }
    
    current->next = (CarMaker *) malloc(sizeof(CarMaker));
    
    strcpy(current->next->manufacturer,maker);
    current->next->make = *make;
    current->next->next = NULL;
    current->next->below = NULL;
    current->size++;
    
}

void insertCarModel(CarMaker * head, CarModel *model, char *maker) {
    CarMaker * current = head;
    while (current->next != NULL) {
        
        
        if (strcmp(current->manufacturer,maker) == 0) {
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
    current->below->next = NULL;
    current->below->below = NULL;
    
    
}

void searchInventory(CarMaker *head, char *maker){
    printf("you searched for...");
    printf("%s\n" , maker);
    int found =0;
    while (head != NULL){
        if ((strcmp(head->manufacturer,maker) == 0) || (strcmp( head->make.model, maker) == 0)
            || (strcmp( head->make.trim, maker) == 0)
            || (strcmp( head->make.km, maker) == 0)
            || (strcmp( head->make.year, maker) == 0)
            || (strcmp( head->make.type, maker) == 0)
            || (strcmp( head->make.driveTrain, maker) == 0)
            || (strcmp( head->make.trans, maker) == 0)
            || (strcmp( head->make.IDnum, maker) == 0)
            || (strcmp( head->make.status, maker) == 0)){
           
            found=1;
            CarMaker * currentBelow = head->below;
            
            while(currentBelow !=NULL) {
                printf("%s,", currentBelow->car.brand);
                printf("%s\n", currentBelow->car.model_listing);
                currentBelow = currentBelow ->below;
            }
            
            
            
        }
      


        head = head->next;
       
    }

    if(found ==0){
        printf("The search for...");
        printf("%s ",maker);
    printf("...was not found sorry!\n");
    }
    
}


void convertListings2Catalougue(CarMaker *head,char *fileName){
    FILE *file;
    
    //set a decent size char memory to read into
    char line[900][900];
    
    //ints to count lines
    int lineCounter = 0;
    int amountOfLines = 0;
    
    //open file to read
    file = fopen(fileName, "r");
    
    
    //read file into char line
    while(fgets(line[lineCounter], 900, file))
    {
        line[lineCounter][strlen(line[lineCounter]) - 1] = '\0';
        lineCounter++;
        
    }
    
    
    amountOfLines = lineCounter;
    
    
    
    
    //based on the amount of lines read, create carMarker structs from the array
    struct CarMaker manufacturers[amountOfLines];
    struct CarModel carModels[amountOfLines];
    struct CarInfo carData [amountOfLines];
    
    //parse through strings and grab everything after the first ',' occurance
    //add this information to the CarModel struct array
    for(lineCounter = 0; lineCounter < amountOfLines; ++lineCounter)
    {
        char *parsedInventory = line[lineCounter];
        while (*parsedInventory != 0 && *(parsedInventory++) != ',') {}
        strcpy(carModels[lineCounter].model_listing, parsedInventory);
        
        
    }
    
    
    for(lineCounter = 0; lineCounter < amountOfLines; ++lineCounter)
    {
        char *parsedInventory = line[lineCounter];
        while (*parsedInventory != 0 && *(parsedInventory++) != ',') {}
        //        strcpy(carModels[lineCounter].model_listing, parsedInventory);
        //        printf("%s \n",parsedInventory);
        
        
    }
    
    
    // Keep printing tokens while one of the
    // delimiters present in str[].
    for(int k =0; k<amountOfLines; k++) {
        char *fileParsed = line[k];
        char *listingParse = strtok(fileParsed, ",");
        int switchCounter =0;
        while (listingParse != NULL)
        {
            
            switch (switchCounter)
            {
                case 0:  strcpy(carData[k].manufacturer, listingParse);
                    break;
                case 1:strcpy(carData[k].model, listingParse);
                    break;
                case 2:strcpy(carData[k].trim, listingParse);
                    break;
                case 3: strcpy(carData[k].km, listingParse);
                    break;
                case 4:strcpy(carData[k].year, listingParse);
                    break;
                case 5:strcpy(carData[k].type, listingParse);
                    break;
                case 6: strcpy(carData[k].driveTrain, listingParse);
                    break;
                case 7: strcpy(carData[k].trans, listingParse);
                    break;
                case 8: strcpy(carData[k].IDnum, listingParse);
                    break;
                case 9:strcpy(carData[k].status, listingParse);
                    break;
        
            }
            
           
          
            listingParse = strtok(NULL, ",");
            switchCounter++;
            
            
        }
        
    }
    
    //parse through the start of each line to grab the manufacturuer name so we can assign it in the CarMaker Struct
    char delim[] = ",";
    
    char *ptr = strtok(line[0], delim);
    
    int parseCounter = 0;
    while (parseCounter <amountOfLines)
    {
        strcpy(carModels[parseCounter].brand, ptr);
        strcpy(manufacturers[parseCounter].manufacturer, ptr);
        
        ptr = strtok(line[parseCounter+1], delim);
        
        
        parseCounter++;
    }
    
    
    
    //create car inventory system
    
    //    //input first elements
    head -> size =0;
    strcpy(head->manufacturer,manufacturers[0].manufacturer);
    head->next = NULL;
    head->below = NULL;
    head->make = carData[0];
    
    insertCarModel(head, &carModels[0], manufacturers[0].manufacturer); //first - 1st below
    
    //starts at lineCounter 1 because we already used the first array position to initialize the multi-linked list
    for(lineCounter=1; lineCounter < amountOfLines; lineCounter++){
        insertCarMaker(head,manufacturers[lineCounter].manufacturer,&carData[lineCounter]);
        insertCarModel(head, &carModels[lineCounter], carModels[lineCounter].brand);
                
    }
    
    
    
}

void Add2Inventory (CarMaker *head, char * car) {
    
    //    char line[900][900];
    
    //ints to count lines
    int lineCounter = 1;
    int amountOfLines = 1;
    
    
    amountOfLines = lineCounter;
    struct CarModel newCar;
    struct CarMaker newMaker;
    struct CarInfo newCarInfo;
    
    
    
    
    
    char *parsedInventory = car;
    while (*parsedInventory != 0 && *(parsedInventory++) != ',') {}
    strcpy(newCar.model_listing, parsedInventory);
    
    
    
    
    
    
    char listing[25];
    strcpy(listing, car);
    char delim[] = ",";
    
    char *ptr = strtok(listing, delim);
    
    strcpy(newCar.brand, ptr);
    strcpy(newMaker.manufacturer, ptr);
    
    insertCarMaker(head,newMaker.manufacturer, &newCarInfo);
    insertCarModel(head, &newCar, newCar.brand);
    
    
    
}

