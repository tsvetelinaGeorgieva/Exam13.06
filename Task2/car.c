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