#include <stdio.h>
#include <ctype.h>
#include <string.h>

int kw(const char*s){
    const char*k[]={"int","float","char","if","else","while","for","return","void"};
    for(int i=0;i<9;i++) if(!strcmp(s,k[i])) return 1; return 0;
}
int op(char c){ return strchr("+-*/=<>!&|^%", c)!=NULL; }

int main(){
    FILE*f=fopen("sample.c","w");
    fputs("int skyline(){int naruto=10; float supra=3.14; if(naruto>5) naruto=naruto+1; return 0;}",f); fclose(f);

    f=fopen("sample.c","r"); if(!f) return 1;
    printf("Tokens from sample.c\n%-10s %s\n","Type","Value");

    int c,j; char b[64];
    while((c=fgetc(f))!=EOF){
        if(isspace(c)) continue;
        if(isalpha(c)||c=='_'){
            b[0]=c; for(j=1;(c=fgetc(f))!=EOF&&(isalnum(c)||c=='_')&&j<63;j++) b[j]=c; b[j]=0;
            if(c!=EOF && !(isalnum(c)||c=='_')) ungetc(c,f);
            printf("%-10s %s\n",kw(b)?"KEYWORD":"IDENT",b); continue;
        }
        if(isdigit(c)){
            b[0]=c; for(j=1;(c=fgetc(f))!=EOF&&(isdigit(c)||c=='.')&&j<63;j++) b[j]=c; b[j]=0;
            if(c!=EOF && !(isdigit(c)||c=='.')) ungetc(c,f);
            printf("%-10s %s\n","NUMBER",b); continue;
        }
        if(op((char)c)){
            b[0]=c; for(j=1;(c=fgetc(f))!=EOF&&op((char)c)&&j<63;j++) b[j]=c; b[j]=0;
            if(c!=EOF && !op((char)c)) ungetc(c,f);
            printf("%-10s %s\n","OP",b); continue;
        }
        if(strchr("{}();,",c)) printf("%-10s %c\n","PUNC",c); else printf("%-10s %c\n","UNK",c);
    }
    fclose(f); return 0;
}
