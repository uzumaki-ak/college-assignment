#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *p, ns[9][9], id[9]; double vs[9], cur; int n, t;

int L() {
    while(isspace(*p)) p++;
    if(!*p) return t=0;
    if(isalpha(*p)) { int i=0; while(isalnum(*p)) id[i++]=*p++; id[i]=0; return t=1; }
    if(isdigit(*p)) { cur=strtod(p, &p); return t=2; }
    return t=*p++;
}

double E();
double F() {
    double r=0;
    if(t==2) { r=cur; L(); }
    else if(t==1) { for(int i=0; i<n; i++) if(!strcmp(ns[i],id)) r=vs[i]; L(); }
    else { L(); r=E(); L(); }
    return r;
}

double T() {
    double r=F();
    while(t=='*'||t=='/') { int o=t; L(); double x=F(); r=o=='*'?r*x:r/x; }
    return r;
}

double E() {
    double r=T();
    while(t=='+'||t=='-') { int o=t; L(); double x=T(); r=o=='+'?r+x:r-x; }
    return r;
}

int main() {
    char s[]="naruto=10; goku=3+2; supra=naruto*goku-4; rx7=(naruto+goku)/5;";
    p=s; L();
    printf("Source: %s\n", s);
    while(t) {
        char k[9]; strcpy(k, id); L(); L(); double v=E(); L();
        int i=0; while(i<n && strcmp(ns[i],k)) i++;
        if(i==n) strcpy(ns[n++], k);
        vs[i]=v;
        printf("Parsed: %s = %.4g\n", k, v);
    }
    puts("Final values:");
    for(int i=0; i<n; i++) printf("%s = %.4g\n", ns[i], vs[i]);
    return 0;
}
