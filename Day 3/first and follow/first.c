#include <stdio.h>
#include <ctype.h>
#include <string.h>

int n,m,i,j;
char productions[15][15], f[15];
void first(char c);
void follow(char c);

void main(){
    int z; char c;
    printf("Hello World !\n");
    printf("Enter the no of productions\n");
    scanf("%d",&n);
    printf("Enter the productions : \n");
    for(i=0;i<n;i++){
        scanf("%s",productions[i]);
        getchar();
    }
    // printf("%c\n",productions[1][0]);
    do{
        printf("Element whose first and follow is to be found : ");
        scanf("%c",&c);
        m = 0;
        first(c);
        printf("First of %c { ",c);
        for(i=0;i<m;i++)
            printf("%c ",f[i]);
        printf("}\n");
        strcpy(f," ");

        m=0;
        follow(c);
        printf("Follow of %c { ",c);
        for(i=0;i<m;i++)
            printf("%c ",f[i]);
        printf("}\n");


        printf("\nContinue ? (0/1) : ");
        scanf("%d",&z);
        getchar();
    }while(z==1);
}

void first(char c){
    if(!isupper(c))
        f[m++]=c;
    for(int k=0;k<n;k++){
        if(productions[k][0]==c){
            if(islower(productions[k][2]))
                f[m++]=productions[k][2];
            else
                first(productions[k][2]);
        }
    }
}

void follow(char c){
    if(productions[0][0]==c)
        f[m++]='$';
    for(i=0;i<n;i++){
        for(j=2;j<strlen(productions[i]);j++){
            if(productions[i][j]==c){
                if(productions[i][j+1]!='\0')
                    first(productions[i][j+1]);
                if(productions[i][j]=='\0' && c!=productions[i][0])
                    follow(productions[i][0]);
            }
        }
    }
}