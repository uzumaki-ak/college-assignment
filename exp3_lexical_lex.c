#include <stdio.h>
#include <ctype.h>
#include <string.h>

int kw(const char*s){
    const char*k[]={"if","else","while","for","int","float","char","return","void","do"};
    for(int i=0;i<10;i++) if(!strcmp(s,k[i])) return 1; return 0;
}

int main(){
    char s[]="int naruto=(goku+2)*supra; if(naruto>=10){return naruto;}";
    int i=0,j; char b[64];
    printf("Source: %s\n%-10s %s\n",s,"Token","Lexeme");
    while(s[i]){
        if(isspace((unsigned char)s[i])){ i++; continue; }
        if(isalpha((unsigned char)s[i])||s[i]=='_'){
            for(j=0;(isalnum((unsigned char)s[i])||s[i]=='_')&&j<63;i++,j++) b[j]=s[i]; b[j]=0;
            printf("%-10s %s\n",kw(b)?"KEYWORD":"IDENT",b); continue;
        }
        if(isdigit((unsigned char)s[i])){
            int dot=0; for(j=0;(isdigit((unsigned char)s[i])||(!dot&&s[i]=='.'))&&j<63;i++,j++){ if(s[i]=='.') dot=1; b[j]=s[i]; } b[j]=0;
            printf("%-10s %s\n",dot?"FLOAT":"INTEGER",b); continue;
        }
        if((s[i]=='='&&s[i+1]=='=')||(s[i]=='!'&&s[i+1]=='=')||(s[i]=='<'&&s[i+1]=='=')||(s[i]=='>'&&s[i+1]=='=')){
            printf("%-10s %c%c\n","RELOP",s[i],s[i+1]); i+=2; continue;
        }
        if(strchr("<>",s[i])){ printf("%-10s %c\n","RELOP",s[i++]); continue; }
        if(s[i]=='='){ printf("%-10s =\n","ASSIGN"); i++; continue; }
        if(strchr("+-*/",s[i])){ printf("%-10s %c\n","ARITH",s[i++]); continue; }
        if(strchr("(){};,",s[i])){ printf("%-10s %c\n","PUNC",s[i++]); continue; }
        printf("%-10s %c\n","UNKNOWN",s[i++]);
    }
    return 0;
}
