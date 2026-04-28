#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

enum {ID,NUM,PLUS,MINUS,MUL,DIV,ASSIGN,SEMI,LP,RP,END};
typedef struct{ int t; char s[32]; double v; } Tok;

char *src; Tok tk;
char name[32][32]; double val[32]; int nenv=0;

void next(){
    while(*src && isspace((unsigned char)*src)) src++;
    if(!*src){ tk.t=END; return; }
    if(isalpha((unsigned char)*src)||*src=='_'){
        int i=0; while((isalnum((unsigned char)*src)||*src=='_')&&i<31) tk.s[i++]=*src++; tk.s[i]=0; tk.t=ID; return;
    }
    if(isdigit((unsigned char)*src)||*src=='.'){
        char *e; tk.v=strtod(src,&e); int n=(int)(e-src); if(n>31)n=31; strncpy(tk.s,src,n); tk.s[n]=0; src=e; tk.t=NUM; return;
    }
    switch(*src++){
        case '+': tk.t=PLUS; break; case '-': tk.t=MINUS; break; case '*': tk.t=MUL; break; case '/': tk.t=DIV; break;
        case '=': tk.t=ASSIGN; break; case ';': tk.t=SEMI; break; case '(': tk.t=LP; break; case ')': tk.t=RP; break;
        default: tk.t=END;
    }
}

double getv(const char*s){ for(int i=0;i<nenv;i++) if(!strcmp(name[i],s)) return val[i]; return 0; }
void setv(const char*s,double v){ for(int i=0;i<nenv;i++) if(!strcmp(name[i],s)){ val[i]=v; return; } strcpy(name[nenv],s); val[nenv++]=v; }

void need(int t){ if(tk.t!=t){ printf("Syntax error near %s\n",tk.s); exit(1);} next(); }

double expr();
double factor(){ if(tk.t==NUM){ double v=tk.v; next(); return v; } if(tk.t==ID){ double v=getv(tk.s); next(); return v; } if(tk.t==LP){ next(); double v=expr(); need(RP); return v; } printf("Bad factor\n"); exit(1); }
double term(){ double v=factor(); while(tk.t==MUL||tk.t==DIV){ int o=tk.t; next(); double r=factor(); v=(o==MUL)?v*r:v/r; } return v; }
double expr(){ double v=term(); while(tk.t==PLUS||tk.t==MINUS){ int o=tk.t; next(); double r=term(); v=(o==PLUS)?v+r:v-r; } return v; }

void stmt(){ char id[32]; if(tk.t!=ID){ printf("Expected id\n"); exit(1);} strcpy(id,tk.s); next(); need(ASSIGN); double v=expr(); need(SEMI); setv(id,v); printf("Parsed: %s = %.4g\n",id,v); }

int main(){
    char code[]="naruto=10; goku=3+2; supra=naruto*goku-4; rx7=(naruto+goku)/5;";
    src=code; next();
    printf("Source: %s\n",code);
    while(tk.t!=END) stmt();
    puts("Final values:");
    for(int i=0;i<nenv;i++) printf("%s = %.4g\n",name[i],val[i]);
    return 0;
}
