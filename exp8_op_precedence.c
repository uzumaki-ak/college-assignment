#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char *p;
void ws(){ while(isspace((unsigned char)*p)) p++; }

double expr();

double number(){
    ws(); char *e=p; double v=strtod(p,&e); p=e; return v;
}
double factor(){
    ws(); if(*p=='('){ p++; double v=expr(); ws(); if(*p==')') p++; return v; }
    return number();
}
double term(){
    double v=factor(); ws();
    while(*p=='*'||*p=='/'){ char o=*p++; double r=factor(); v=(o=='*')?v*r:v/r; ws(); }
    return v;
}
double expr(){
    double v=term(); ws();
    while(*p=='+'||*p=='-'){ char o=*p++; double r=term(); v=(o=='+')?v+r:v-r; ws(); }
    return v;
}

int main(){
    char *E[]={"3 + 5 * 2","10 - 4 / 2","(3 + 5) * 2","6 + 2 * 3 - 4 / 2"};
    for(int i=0;i<4;i++){ p=E[i]; printf("%s = %.4g\n",E[i],expr()); }
    return 0;
}
