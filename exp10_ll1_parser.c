#include <stdio.h>
#include <string.h>
#include <ctype.h>

char t[99][8]; int k, n;

void tokenize(const char *s) {
    int i=0; n=0;
    while(s[i]) {
        if(isspace(s[i])) i++;
        else if(isalpha(s[i])||s[i]=='_') { while(isalnum(s[i])||s[i]=='_') i++; strcpy(t[n++], "id"); }
        else if(isdigit(s[i])) { while(isdigit(s[i])) i++; strcpy(t[n++], "num"); }
        else if(strchr("+*()", s[i])) { t[n][0]=s[i++]; t[n++][1]=0; }
        else i++;
    }
    strcpy(t[n++], "$");
}

void parse(const char *s) {
    char st[99][8]; int tp=0; k=0; tokenize(s);
    strcpy(st[tp++], "$"); strcpy(st[tp++], "E");
    printf("\nInput: %s\n", s);
    while(tp) {
        char *X=st[--tp], *a=t[k];
        if(!strcmp(X, a)) { if(strcmp(X, "$")) { printf("match %s\n", a); k++; } continue; }
        const char *r[3]; int m=0;
        if(!strcmp(X, "E")) { r[0]="T"; r[1]="Q"; m=2; }
        else if(!strcmp(X, "Q")) { if(*a=='+') { r[0]="+"; r[1]="T"; r[2]="Q"; m=3; } }
        else if(!strcmp(X, "T")) { r[0]="F"; r[1]="R"; m=2; }
        else if(!strcmp(X, "R")) { if(*a=='*') { r[0]="*"; r[1]="F"; r[2]="R"; m=3; } }
        else if(!strcmp(X, "F")) { if(*a=='(') { r[0]="("; r[1]="E"; r[2]=")"; m=3; } else { r[0]=a; m=1; } }
        
        printf("%s ->", X); if(!m) printf(" eps");
        for(int j=0; j<m; j++) printf(" %s", r[j]); printf("\n");
        while(m--) strcpy(st[tp++], r[m]);
    }
    puts(k==n-1 ? "Accepted" : "Rejected");
}

int main() {
    parse("naruto + goku * luffy");
    parse("supra * (rx7 + 7)");
    parse("goku + vegeta");
    return 0;
}
