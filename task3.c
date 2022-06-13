#include<stdio.h>

int main(){
    int number;
    printf("Enter number: ");
    scanf("%d", &number);
    int copyNum = number;
    int count = 0;
    while(copyNum != 0){
        count++;
        copyNum /= 10;
    }

    char codNum[count + 1];
    for(int p = count; p >= 0; p--){
        codNum[p] = (char)number % 10;
        number /= 10;
    }

    codNum[count + 1] = '\0';    

     for(int j = 0; j <= count; j++){
        printf("%c", codNum[j]);
    }

    for(int i = 0; i <= count; i++){
        if(i % 2 == 0){
            //codNum[i] = 'A' + 1;
            switch(codNum[i]){
                case 0:
                    codNum[i] = 'A';
                    break;
                case 1:
                    codNum[i] = 'B';
                    break;
                case 2:
                    codNum[i] = 'C';
                    break;
                case 3:
                    codNum[i] = 'D';
                    break;
                case 4:
                    codNum[i] = 'E';
                    break;
                case 5:
                    codNum[i] = 'F';
                    break;
                case 6:
                    codNum[i] = 'G';
                    break;
                case 7:
                    codNum[i] = 'H';
                    break;
                case 8:
                    codNum[i] = 'I';
                    break;
                case 9:
                    codNum[i] = 'J';
                    break;
            }
        }else{
            switch(codNum[i]){
                case 0:
                    codNum[i] = '!';
                    break;
                case 1:
                    codNum[i] = '#';
                    break;
                case 2:
                    codNum[i] = '/';
                    break;
                case 3:
                    codNum[i] = '~';
                    break;
                case 4:
                    codNum[i] = '=';
                    break;
                case 5:
                    codNum[i] = '\'';
                    break;
                case 6:
                    codNum[i] = '\\';
                    break;
                case 7:
                    codNum[i] = '>';
                    break;
                case 8:
                    codNum[i] = '.';
                    break;
                case 9:
                    codNum[i] = ',';
                    break;
            }
        }
    }

    for(int j = 0; j < count; j++){
        printf("%c ", codNum[j]);
    }
    return 0;
}