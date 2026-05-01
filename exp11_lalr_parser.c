#include <stdio.h>
#include <string.h>
#include <ctype.h>

char t[256][8]; int n;

void tokenize(const char *s) {
    int i=0; n=0;
    while(s[i]) {
        if(isspace(s[i])) i++;
        else if(isalpha(s[i])||s[i]=='_') { while(isalnum(s[i])||s[i]=='_') i++; strcpy(t[n++], "id"); }
        else if(strchr("+*()", s[i])) { t[n][0]=s[i++]; t[n++][1]=0; }
        else i++;
    }
    strcpy(t[n++], "$");
}

int G(int s, char X) {
    if(s==0||s==4) return X=='E'?(s?8:1):X=='T'?2:3;
    if(s==6) return X=='T'?9:3;
    return s==7?10:-1;
}

int main() {
    char *in[]={"naruto + goku * luffy","supra * rx7","(ae86 + evo) * skyline"}, *lhs=" EETTFF";
    int len[]={0,3,1,3,1,3,1};
    for(int z=0; z<3; z++) {
        tokenize(in[z]);
        int st[256]={0}, tp=0, k=0;
        printf("\nInput: %s\n", in[z]);
        while(1) {
            int s=st[tp], v=0; char *c=t[k], a='e';
            if(s==0||s==4||s==6||s==7) {
                if(*c=='i') a='s', v=5; else if(*c=='(') a='s', v=4;
            }
            if(s==1) { if(*c=='+') a='s', v=6; else if(*c=='$') a='a'; }
            else if(s==2) { if(*c=='*') a='s', v=7; else if(strchr("+)$", *c)) a='r', v=2; }
            else if(s==3) { if(strchr("+*)$", *c)) a='r', v=4; }
            else if(s==5) { if(strchr("+*)$", *c)) a='r', v=6; }
            else if(s==8) { if(*c=='+') a='s', v=6; else if(*c==')') a='s', v=11; }
            else if(s==9) { if(*c=='*') a='s', v=7; else if(strchr("+)$", *c)) a='r', v=1; }
            else if(s==10) { if(strchr("+*)$", *c)) a='r', v=3; }
            else if(s==11) { if(strchr("+*)$", *c)) a='r', v=5; }

            if(a=='a') { puts("Accept"); break; }
            if(a=='e') { printf("Error at %s\n", c); break; }
            if(a=='s') { st[++tp]=v; k++; }
            else { tp-=len[v]; st[++tp]=G(st[tp], lhs[v]); printf("reduce r%d\n", v); }
        }
    }
    return 0;
}
