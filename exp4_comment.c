#include <stdio.h>
#include <string.h>
#include <ctype.h>

const char* c(const char* l) {
    while(isspace(*l)) l++;
    int n=strlen(l); while(n && isspace(l[n-1])) n--;
    if(n>1 && l[0]=='/' && l[1]=='/') return "Single-line //";
    if(n && l[0]=='#') return "Single-line #";
    if(n>3 && l[0]=='/' && l[1]=='*' && l[n-2]=='*' && l[n-1]=='/') return "Single-line /* */";
    return (n>1 && l[0]=='/' && l[1]=='*') ? "Start block" : (n>1 && l[n-2]=='*' && l[n-1]=='/') ? "End block" : "Not a comment";
}

int main() {
    const char* L[]={"// Naruto comment","/* Supra */","/* Start"," End */","# python","int rx7=5;","goku=goku+1;","   // indented"};
    printf("%-28s %s\n","Line","Result");
    for(int i=0; i<8; i++) printf("%-28s %s\n", L[i], c(L[i]));
    return 0;
}
