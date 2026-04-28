#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char *p;
void ws(){ while(isspace((unsigned char)*p)) p++; }

double expr();

double factor(){ ws(); if(*p=='('){ p++; double v=expr(); ws(); if(*p==')') p++; return v; } char *e=p; double v=strtod(p,&e); p=e; return v; }
double term(){ double v=factor(); ws(); while(*p=='*'||*p=='/'){ char o=*p++; double r=factor(); v=(o=='*')?v*r:v/r; ws(); } return v; }
double expr(){ double v=term(); ws(); while(*p=='+'||*p=='-'){ char o=*p++; double r=term(); v=(o=='+')?v+r:v-r; ws(); } return v; }

int main(){
    char *E[]={"3 + 5","10 - 4 * 2","(3 + 5) * 2","100 / (4 + 1) * 3","2 + 3 * 4 - 6 / 2"};
    puts("YACC-style calculator");
    for(int i=0;i<5;i++){ p=E[i]; printf("%-24s = %.4g\n",E[i],expr()); }
    return 0;
}
