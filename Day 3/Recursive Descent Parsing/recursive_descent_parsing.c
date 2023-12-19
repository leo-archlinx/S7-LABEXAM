#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    i+i*(i/i)$
    GRAMMER
    E->+TE'
    E'->-TE'
    T->FT'
    T'->*FT'|/FT'
    F->(E)|i
*/
char *ch;
char buffer[15];
int i,error=0;
FILE *f1;
void E(); void T(); void Edash(); void Tdash(); void F();

void main(){
    i=0;
    f1 = fopen("output.txt","w");
    if(f1==NULL){
        printf("error while opening file\n");
        exit(0);
    }
    // while((ch = fgetc(f1))!=EOF){
        // buffer[i++] =ch; 
        // printf("%c\t",ch);
    // } 
    // printf("\n%s",buffer);
    printf("Enter the String : \n");
    scanf("%s",buffer);
    fprintf(f1,"\nGiven String : %s \n",buffer);
    ch = buffer;
    printf("\n");
    E();
    if(*ch=='\0')
        printf("\nString Accepted\n");
    else
        printf("\nString not Acceptable @ %d times\n",error);
    
    
    fclose(f1);
}

void E(){
    // E->+TE'
    F();
    if(*ch=='+'){
        printf("%s \t E->+TE'\n",ch);
        fprintf(f1,"%s \t E->+TE'\n",ch);
        ch++;
    }
    else
        error++;
    if(*ch=='$'){
        printf("%s \t $",ch);
        fprintf(f1,"%s \t $",ch);
        ch++;
    }
    T();
    Edash();
}

void T(){
    // T->FT'
    F();
    Tdash();
}

void Edash(){
    //     E'->-TE'
    if(*ch=='-'){
        printf("%s \t E->-TE'\n",ch);
        fprintf(f1,"%s \t E->-TE'\n",ch);
        ch++;
        T();
        Edash();
    }
    else
        error++;
}

void Tdash(){
    // T'->*FT'|/FT'
    if(*ch=='*'||*ch=='/'){
        printf("%s \t *FT'|/FT'\n",ch);
        fprintf(f1,"%s \t *FT'|/FT'\n",ch);
        ch++;
        F();
        Tdash();
    }
    else
        error++;
}

void F(){
    if(*ch=='i'){
        printf("%s \t F->i\n",ch);
        fprintf(f1,"%s \t F->i\n",ch);
        ch++;
    }
    else
        error++;
    if(*ch=='('||*ch==')'){
        printf("%s \t F->(E)\n",ch);
        fprintf(f1,"%s \t F->(E)\n",ch);
        ch++;
        E();
    }
    else
        error++;
}