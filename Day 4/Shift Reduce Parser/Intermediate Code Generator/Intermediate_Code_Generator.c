#include <stdio.h>
#include <string.h>
int i,j=0,Z_A=90;
char str[100],left[50],right[50];
void isOperator();
void Display();
void fleft(int);
void fright(int);

struct exp{
    int pos;
    char op;
}k[15];

void main(){
    printf("Hello World!\n");
    printf("Enter Expression\n");
    scanf("%s",str);
    isOperator();
    Display();
}

void isOperator(){
    for(i=0;str[i]!='\0';i++){
        if(str[i]==':'){
            k[j].pos=i;
            k[j++].op=str[i];
        }
        else if(str[i]=='/'){
            k[j].pos=i;
            k[j++].op=str[i];
        }
        else if(str[i]=='*'){
            k[j].pos=i;
            k[j++].op=str[i];
        }
        else if(str[i]=='+'){
            k[j].pos=i;
            k[j++].op=str[i];
        }
        else if(str[i]=='-'){
            k[j].pos=i;
            k[j++].op=str[i];
        }
    }
}

void Display(){
    i =0;
    while (k[i].op!='\0'){
        fleft(k[i].pos);
        fright(k[i].pos);
        str[k[i].pos] = Z_A--; 
        printf("%c:=%s%c%s\t",str[k[i].pos],left,k[i].op,right);
        
        for(j=0;j<strlen(str);j++){
            if(str[j]!='$')
                printf("%C",str[j]);
        }
        printf("\n");
        i++;
    }
    
}

void fleft(int x){
    int w=0, flag=0;
    x--;
    while(x!=-1 && str[x]!='+' && str[x]!='-' && str[x]!='*' && str[x]!='/' && str[x]!=':' && str[x]!='\0' && str[x]!='='){
        if(str[x]!='$' && flag==0){
            left[w++]=str[x];
            left[w]='\0';
            str[x]='$';
            flag=1;
        }
        x--;
    }
}

void fright(int x){
    int w=0, flag=0;
    x++;
    while(x!=-1 && str[x]!='+' && str[x]!='-' && str[x]!='*' && str[x]!='/' && str[x]!=':' && str[x]!='\0' && str[x]!='='){
        if(str[x]!='$'&& flag==0){
            right[w++]=str[x];
            right[w]='\0';
            str[x]='$';
            flag=1;
        }
        x++;
    }
}