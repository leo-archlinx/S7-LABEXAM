#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h> 

int isKeyword(char buffer[]){
    char keyword[40][40] = {"int","void","float","for","if","do","for","char","main"};
    for(int i=0;i<10;i++){
        if(strcmp(keyword[i],buffer)==0){
            return 1;
        }
    }
    return 0;
}


int isOperator(char ch){
    char operators[] = "+-*/%";
    for(int i =0; i<5;i++){
        if(ch == operators[i]){
            return 1;
        }
    }
    return 0;
}

void main(){
    char ch,buffer[15];
    FILE *f1,*f2;
    int j=0, line=1;
    f1 = fopen("input.txt","r");
    f2 = fopen("output.txt","w");
    if(f1==NULL || f2==NULL){
        printf("Error while opening files\n");
        exit(0);
    }
    
    printf("Hello World\n");
    fprintf(f2,"Line No\t Token\t Lexime\t\n");
    fprintf(f2,"-----------------------------\n");
    printf("Line No\t Token\t Lexime\t\n");
    printf("-----------------------------\n");
    while((ch = fgetc(f1))!=EOF){
        if(isalnum(ch)){
            buffer[j++] = ch;
        }
        else if(isOperator(ch) || ch == ';'){
            if(j!=0){
                buffer[j]='\0';
                j= 0;
                printf("%d\t %s is identifier\n",line,buffer);
                fprintf(f2,"%d\t %s\t  identifier\n",line,buffer);
            }
        printf(ch==';' ? "%d\t %c is Special symbol\n" : "%d\t%c is identifier\n",line,ch);
        fprintf(f2,ch==';' ? "%d\t %c\t Special symbol\n" : "%d\t%c\t identifier\n",line,ch);
        }
        else if((ch==' ' || ch == '\n') && (j!=0)){
            if(ch=='\n')
                line++;
            buffer[j]='\0';
            j=0;
            printf(isKeyword(buffer) ? "%d\t%s is keyword\n" : "%d\t%s is identifier\n",line,buffer);
            fprintf(f2,isKeyword(buffer) ? "%d\t%s\t keyword\n" : "%d\t%s\t identifier\n",line,buffer);
            }
        else if(ch =='\n'){
            line++;
            }
    }

    fclose(f1);
    fclose(f2);
}