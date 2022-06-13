#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<math.h>
#include<string.h>
#include<time.h>

int randInt(int, int);
double randDouble(double, double);
void randomModel(char*);

int compModelASC(const void*, const void*);
int compModelDESC(const void*, const void*);
int compMaxSpeedASC(const void*, const void*);
int compMaxSpeedDESC(const void*, const void*);
int compPriceASC(const void*, const void*);
int compPriceDESC(const void*, const void*);

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

int randInt(int min, int max){
    return min + (rand()% (max + 1 - min)); 
}

double randDouble(double min, double max){
    return min + ((double)rand() / RAND_MAX) * (max - min);
}

void randomModel(char* model){
    int len = randInt(4, 10);
    model[0] = randInt('A', 'Z');
    for(int i = 1; i < len; i++){
        model[i] = randInt('a', 'z');
    }
    model[len] = '\0';
}

int compModelASC(const void* c1, const void* c2){
    Car* car1 = (Car*) c1;
    Car* car2 = (Car*) c2;
    return strcmp(car1->model, car2->model);
}

int compModelDESC(const void* c1, const void* c2){
    Car* car1 = (Car*) c1;
    Car* car2 = (Car*) c2;
    return strcmp(car2->model, car1->model);
}

int compMaxSpeedASC(const void* c1, const void* c2){
    Car* car1 = (Car*) c1;
    Car* car2 = (Car*) c2;
    return car1->maxspeed - car2->maxspeed;
}

int compMaxSpeedDESC(const void* c1, const void* c2){
    Car* car1 = (Car*) c1;
    Car* car2 = (Car*) c2;
    return car2->maxspeed - car1->maxspeed;
}

int compPriceASC(const void* c1, const void* c2){
    Car* car1 = (Car*) c1;
    Car* car2 = (Car*) c2;
    if(fabs(car1->price - car2->price) < 0.01){
        return 0;
    }else if(car1->price > car2->price){
        return 1;
    }
    return - 1;
}

int compPriceDESC(const void* c1, const void* c2){
    Car* car1 = (Car*) c1;
    Car* car2 = (Car*) c2;
    if(fabs(car1->price - car2->price) < 0.01){
        return 0;
    }else if(car1->price < car2->price){
        return 1;
    }
    return - 1;
}