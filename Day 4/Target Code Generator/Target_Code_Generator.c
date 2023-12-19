#include <stdio.h>
#include <stdlib.h>
FILE *f1;

void main(){
    char res[10],eq[10],op1[10],op[10],op2[10];
    printf("Hello World\n");
    f1 = fopen("input.txt","r");
    if(f1==NULL){
        printf("Error while opening file\n");
        exit(0);
    }
    while(fscanf(f1,"%s %s %s %s %s",res,eq,op1,op,op2)!=EOF){
        printf("MOV AX,[%s]\n",res);
        switch(op[0]){
            case '+':
                printf("ADD AX, [%s]\n",op2);
                break;
            case '-':
                printf("SUB AX, [%s]\n",op2);
                break;
            case '*':
                printf("MOV BX,[%s]\nMUL BX\n",op2);
                break;
            case '/':
                printf("MOV BX,[%s]\nDIV BX\n",op2);
                break;
        }
        printf("MOV [%s],AX\n",res);
    }
}