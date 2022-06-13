#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<math.h>
#include<string.h>
#include<time.h>
#include "car.h"

typedef struct Car{
    char model[21];
    uint8_t maxspeed;
    double price;

} Car;


int main(){
    srand(time(NULL));

    int (*getComparator[])(const void*, const void*) = {
        compModelASC,
        compModelDESC,
        compMaxSpeedASC,
        compMaxSpeedDESC,
        compPriceASC,
        compPriceDESC
    };

    int comp;
    printf("1. compModelASC\n2. compModelDESC\n3. compMaxSpeedASC\n4.compMaxSpeedDESC\n5.compPriceASC\n6.compPriceDesc\nEnter option: \n");
    scanf("%d", &comp);

    Car cars[10];
    for(int i = 0; i < 10; i++){
        randomModel(cars[i].model);
        cars[i].maxspeed = randInt(100, 300);
        cars[i].price = randDouble(1000.0, 100000.00);
    }

    qsort(cars, 10, sizeof(cars[0]), getComparator[comp-1]);
    for(int i = 0; i < 10; i++){
        printf("%d.\n", (i+1));
        printf("Model: %s\n", cars[i].model);
        printf("MaxSpeed: %d\n", cars[i].maxspeed);
        printf("Price: %.2lf\n\n", cars[i].price);
    }
    
    return 0;
}