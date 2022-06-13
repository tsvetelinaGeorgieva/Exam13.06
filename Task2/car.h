#ifdef _CAR_H_
#define _CAR_H_

int randInt(int, int);
double randDouble(double, double);
void randomModel(char*);

int compModelASC(const void*, const void*);
int compModelDESC(const void*, const void*);
int compMaxSpeedASC(const void*, const void*);
int compMaxSpeedDESC(const void*, const void*);
int compPriceASC(const void*, const void*);
int compPriceDESC(const void*, const void*);

#endif