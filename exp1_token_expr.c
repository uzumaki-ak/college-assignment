#include <stdio.h>
#include <ctype.h>
#include <string.h>

int op(char c){ return strchr("+-*/=<>!&|^%", c)!=NULL; }

int main(){
    char e[]="naruto = 3 + goku * (10 - rx7);";
    int i=0,j; char b[64];
    printf("Expr: %s\n%-10s %s\n",e,"Type","Value");
    while(e[i]){
        if(isspace((unsigned char)e[i])){ i++; continue; }
        if(isalpha((unsigned char)e[i])||e[i]=='_'){
            for(j=0;(isalnum((unsigned char)e[i])||e[i]=='_')&&j<63;i++,j++) b[j]=e[i]; b[j]=0;
            printf("%-10s %s\n","IDENT",b); continue;
        }
        if(isdigit((unsigned char)e[i])){
            for(j=0;(isdigit((unsigned char)e[i])||e[i]=='.')&&j<63;i++,j++) b[j]=e[i]; b[j]=0;
            printf("%-10s %s\n","NUMBER",b); continue;
        }
        if(op(e[i])){
            for(j=0;op(e[i])&&j<63;i++,j++) b[j]=e[i]; b[j]=0;
            printf("%-10s %s\n","OP",b); continue;
        }
        if(strchr("(),;",e[i])) printf("%-10s %c\n","PUNC",e[i]);
        else printf("%-10s %c\n","UNK",e[i]);
        i++;
    }
    return 0;
}
