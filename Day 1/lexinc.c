#include <stdio.h>
#include <string.h>

struct SampleStruct {
    int var;
    char string[50];
};

void main(){
    struct SampleStruct sample;
    strcpy(sample.string,"Hello World !");
    sample.var = 30;
    printf("%s\t",sample.string);
    printf("%d",sample.var);
}