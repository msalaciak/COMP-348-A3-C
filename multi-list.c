//
//  multi-list.c
//  comp-348-question-2
//
//  Created by Matt Salaciak on 2020-04-12.
//  Copyright © 2020 Matt Salaciak. All rights reserved.
//

#include "multi-list.h"

//the print methods below all funciton similary
//they traverse the list using pointers either current - > next or current -> below
// for carMakers we only use current -> next because those are the "top " level of the link
// for CarModels we go through each top level by using the  current -> next
//but once at that pointer we use current- >below to go to the down the levels of the list at that point

void printCarMakers(CarMaker* head) {
    CarMaker * current = head;
    
    
    while (current != NULL) {
        printf("%s \n", current->manufacturer);
        
        current = current->next;
    }
    printf("\n");
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
    printf("\n");
    
    
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
    
    printf("\n");
    
    
    
}

// Inserts a CarMaker object into the list, if its null it creates the first "node"
//if its not null it will keep going to the next - > null point and add it there
// it only uses current -> next because we are only adding to the top layer since it is carMakers

void insertCarMaker(CarMaker * head,char *maker, CarInfo * make, CarModel *model) {
    CarMaker * current = head;
    
    if(head == NULL){
        current->next = (CarMaker *) malloc(sizeof(CarMaker));
        strcpy(head->manufacturer,maker);
        head->make = *make;
        head->car = *model;
        head->next = NULL;
        head->below = NULL;
        head->size++;
        return;
        
    }
    
    while (current->next != NULL) {
        current = current->next;
    }
    
    current->next = (CarMaker *) malloc(sizeof(CarMaker));
    
    strcpy(current->next->manufacturer,maker);
    current->next->make = *make;
    current->next->next = NULL;
    current->next->below = NULL;
    current->next->car = *model;
    current->size++;
    
}


//essentially works like insertCarMaker but this time it takes CarModel and CarInfo structs
//it traverses the list and compares the current positon manufacturer to the one being inserted, if it is the same it will add it to that
//CarMaker, if it is not, it will add it to the one it will be created
// once at its top level posiiton in the list, it will use current->below to traverse the levels of the list at that point

void insertCarModel(CarMaker * head, CarModel *model, char *maker, CarInfo * make) {
    CarMaker * current = head;
    while (current->next != NULL) {
        
        
        if (strcmp(current->manufacturer,maker) == 1) {
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
    current->below->make = *make;
    
    
}


//search inventory traverses the list very similar to how the print function is implemeneted,
//but it will do a strcmp to the inserted search parameter and the paramteres of the given carModel/CarInfo struct
//if it is a match it will print and keep going until null
//if there is no match it will say a message and exit
void searchInventory(CarMaker *head, char *maker){
    printf("you searched for...");
    printf("%s\n" , maker);
    
    
    
    CarMaker * current = head;
    CarMaker * currentBelow = head->below;
    int found =0;
    while (current != NULL){
        currentBelow = current ->below;
        if ((strcmp(current->make.manufacturer,maker) == 0)
            ||(strcmp( current->make.model, maker) == 0)
            || (strcmp( current->make.trim, maker) == 0)
            || (strcmp( current->make.km, maker) == 0)
            || (strcmp( current->make.year, maker) == 0)
            || (strcmp( current->make.type, maker) == 0)
            || (strcmp( current->make.driveTrain, maker) == 0)
            || (strcmp( current->make.trans, maker) == 0)
            || (strcmp( current->make.IDnum, maker) == 0)
            || (strcmp( current->make.status, maker) == 0)){
            
            found=1;
            
            
            
            while(currentBelow !=NULL) {
                printf("%s,", currentBelow->car.brand);
                printf("%s\n", currentBelow->car.model_listing);
                 printf("\n");
                currentBelow = currentBelow ->below;
            }
            
            
        }
        
        
        
        
        current = current->next;
    }
    
    if(found ==0){
        printf("The search for...");
        printf("%s ",maker);
        printf("...was not found sorry!\n");
        printf("\n");
    }
    
    
}

//this method is very much similar to the method implemeneted in Q5 with ruby
// takes the CarMaker head struct, and the char to the file path
//parses what is necessary, since it is already sorted and organized from the text file outputted by Q5
//it is just simiply using a delimter to find what is needed
//creates CarModel, CarInfo and CarMaker structs so they are filled and inserted into the list

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
    
    //lines from the file so this is used for all the loops to count where eveything is at
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
    
    
    
    
  //parse through the lines so each paramter of the CarInfo struct can be added
//how this is done is a switch counter is kept, when its a certain number it will call strcpy to copy the parsed char string to the struct
    
    
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
        ptr = strtok(line[parseCounter], delim);
        strcpy(carModels[parseCounter].brand, ptr);
        strcpy(manufacturers[parseCounter].manufacturer, ptr);
        
        
        parseCounter++;
    }
    
    
    //create car inventory system
    
    //    //input first elements
    head->next = NULL;
    head->below= NULL;
    
    //loop through each struct and insert it!
    for(lineCounter=0; lineCounter < amountOfLines; lineCounter++){
        
        insertCarMaker(head,manufacturers[lineCounter].manufacturer,&carData[lineCounter], &carModels[lineCounter]);
        insertCarModel(head, &carModels[lineCounter], carData[lineCounter].manufacturer,&carData[lineCounter] );
        
    }
    
    
    
}

//same function are before but instead of going through a loop, CarModel, CarInfo and CarMaker are created once and inserted once
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
    
        
    char infoParsed[256];
    strcpy(infoParsed, car);
    
    char *listingParse = strtok(infoParsed, ",");
    int switchCounter =0;
    while (listingParse != NULL)
    {
        
        switch (switchCounter)
        {
            case 0:  strcpy(newCarInfo.manufacturer, listingParse);
                break;
            case 1:strcpy(newCarInfo.model, listingParse);
                break;
            case 2:strcpy(newCarInfo.trim, listingParse);
                break;
            case 3: strcpy(newCarInfo.km, listingParse);
                break;
            case 4:strcpy(newCarInfo.year, listingParse);
                break;
            case 5:strcpy(newCarInfo.type, listingParse);
                break;
            case 6: strcpy(newCarInfo.driveTrain, listingParse);
                break;
            case 7: strcpy(newCarInfo.trans, listingParse);
                break;
            case 8: strcpy(newCarInfo.IDnum, listingParse);
                break;
            case 9:strcpy(newCarInfo.status, listingParse);
                break;
                
        }
        
        
        
        listingParse = strtok(NULL, ",");
        switchCounter++;
        
        
    }
    
    
    
    
    char listing[256];
    strcpy(listing, car);
    char delim[] = ",";
    
    char *ptr = strtok(listing, delim);
    
    strcpy(newCar.brand, ptr);
    strcpy(newMaker.manufacturer, ptr);
    

    
    insertCarMaker(head,newMaker.manufacturer, &newCarInfo, &newCar);
    insertCarModel(head, &newCar, newCar.brand,&newCarInfo);
    
    
    
}


//this is a modify print entire list function from above,
//but instead of using printf, i use fprintf so we can save the ouput to a file

void saveCatalogue2File(CarMaker *head, char *fileName){
    FILE *f = fopen(fileName, "w");
    
    CarMaker * current = head;
       CarMaker * currentBelow = head ->below;
       while(current != NULL) {
           currentBelow = current ->below;
           while(currentBelow !=NULL) {
               fprintf(f,"%s,", currentBelow->car.brand);
               fprintf(f,"%s \n", currentBelow->car.model_listing);
               currentBelow = currentBelow ->below;
           }
           current = current->next;
       }
    
    fclose(f);
}


