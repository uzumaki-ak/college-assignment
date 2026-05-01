#include <stdio.h>
#include <ctype.h>
#include <string.h>

int k(char* s) {
    char* w[] = {"if","else","while","for","int","float","char","return","void","do"};
    for(int i=0; i<10; i++) if(!strcmp(s, w[i])) return 1; return 0;
}

int main() {
    char s[]="int naruto=(goku+2)*supra; if(naruto>=10){return naruto;}", b[64]; int i=0, j, f;
    printf("Source: %s\n%-10s %s\n", s, "Token", "Lexeme");
    while(s[i]) {
        if(isspace(s[i])) { i++; continue; }
        b[j=0]=s[i];
        if(isalpha(s[i])||s[i]=='_') {
            while(isalnum(s[i])||s[i]=='_') b[j++]=s[i++]; b[j]=0;
            printf("%-10s %s\n", k(b)?"KEYWORD":"IDENT", b);
        } else if(isdigit(s[i])) {
            for(f=0; isdigit(s[i])||s[i]=='.';) { if(s[i]=='.') f=1; b[j++]=s[i++]; } b[j]=0;
            printf("%-10s %s\n", f?"FLOAT":"INTEGER", b);
        } else if(strchr("=!<>",s[i]) && s[i+1]=='=') {
            printf("%-10s %c%c\n", "RELOP", s[i], s[i+1]); i+=2;
        } else if(strchr("<>", s[i])) printf("%-10s %c\n", "RELOP", s[i++]);
        else if(s[i]=='=') printf("%-10s =\n", "ASSIGN"), i++;
        else if(strchr("+-*/", s[i])) printf("%-10s %c\n", "ARITH", s[i++]);
        else if(strchr("(){};,", s[i])) printf("%-10s %c\n", "PUNC", s[i++]);
        else printf("%-10s %c\n", "UNKNOWN", s[i++]);
    }
    return 0;
}
