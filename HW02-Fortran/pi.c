/*
Name: Paul Talaga
Date: Aug 10, 2020
Desc: Estimates pi by random number generation.

*/
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h>


#define TOTAL 100000000

int main(){
    unsigned i;
    float x, y, d;
    unsigned in_count = 0;
    for(i = 0; i < TOTAL; i++){
        x = (float)rand() / RAND_MAX - 0.5;
        y = (float)rand() / RAND_MAX - 0.5;
        
        //d = sqrt(x*x + y*y);
        d = x*x + y*y;
        //if(d < 0.5){
        if(d < 0.25){
            in_count++;
        }
    }
    printf("pi: %f \n", (float)in_count * 4.0 / TOTAL);
    return 0;
}