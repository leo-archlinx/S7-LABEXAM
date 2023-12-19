#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char buffer[20],stk[20];
int i=0,j=0,z,len;
FILE *f1;
void check();

void main(){
    f1 = fopen("output.txt","w");
    if(f1==NULL){
        printf("Error while openning file \n");
        exit(0);
    }
    printf("\nHello World!\n");
    printf("enter the string : \n");
    scanf("%s",buffer);
    len = strlen(buffer);
    printf("STACK\tINPUT\t\tACTION\n");
    fprintf(f1,"STACK\tINPUT\t\tACTION\n");
    for(i=0;j<len;i++,j++){
        if(buffer[j]=='i' && buffer[j+1]=='d'){
            stk[i]=buffer[j];
            stk[i+1]=buffer[j+1];
            stk[i+2]='\0';
            buffer[j]=' ';
            buffer[j+1]=' ';
            printf("%s\t%s \t SHIFT->id\n",stk,buffer);
            fprintf(f1,"%s\t%s \t SHIFT->id\n",stk,buffer);
            check();
        }
        else{
            stk[i]=buffer[j];
            stk[i+1]='\0';
            buffer[j]=' ';
            printf("%s\t%s \t SHIFT->REDUCET TO %c\n",stk,buffer,stk[i]);
            fprintf(f1,"%s\t%s \t SHIFT->REDUCET TO %c\n",stk,buffer,stk[i]);
            check();
        }
    }
}

void check(){
    for(z=0;z<len;z++){
        if(stk[z]=='i'&&stk[z+1]=='d'){
            stk[z]='E';
            stk[z+1]='\0';
            printf("%s\t%s \t REDUCT->E\n",stk,buffer);
            fprintf(f1,"%s\t%s \t REDUCT->E\n",stk,buffer);
            j++;
        }
    }
    for(z=0;z<len;z++){
        if(stk[z]=='E'&& stk[z+1]=='+'&&stk[z+2]=='E'){
            stk[z]='E';
            stk[z+1]='\0';
            printf("%s\t%s \t REDUCE->E\n",stk,buffer);
            fprintf(f1,"%s\t%s \t REDUCE->E\n",stk,buffer);
            i=i-2;
        }
    }
    for(z=0;z<len;z++){
        if(stk[z]=='E'&& stk[z+1]=='*'&&stk[z+2]=='E'){
            stk[z]='E';
            stk[z+1]='\0';
            printf("%s\t%s \t REDUCE->E\n",stk,buffer);
            fprintf(f1,"%s\t%s \t REDUCE->E\n",stk,buffer);
            i=i-2;
        }
    }
    for(z=0;z<len;z++){
        if(stk[z]=='('&& stk[z+1]=='E'&&stk[z+2]==')'){
            stk[z]='E';
            stk[z+1]='\0';
            printf("%s\t%s \t REDUCE->E\n",stk,buffer);
            fprintf(f1,"%s\t%s \t REDUCE->E\n",stk,buffer);
            i=i-2;
        }
    }
}