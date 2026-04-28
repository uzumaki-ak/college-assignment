#include <stdio.h>
#include <string.h>
#include <ctype.h>

const char*check(const char*line){
    while(*line && isspace((unsigned char)*line)) line++;
    int n=(int)strlen(line); while(n>0 && isspace((unsigned char)line[n-1])) n--;
    if(n>=2 && line[0]=='/' && line[1]=='/') return "Single-line //";
    if(n>=1 && line[0]=='#') return "Single-line #";
    if(n>=4 && line[0]=='/' && line[1]=='*' && line[n-2]=='*' && line[n-1]=='/') return "Single-line /* */";
    if(n>=2 && line[0]=='/' && line[1]=='*') return "Start block";
    if(n>=2 && line[n-2]=='*' && line[n-1]=='/') return "End block";
    return "Not a comment";
}

int main(){
    const char*L[]={"// Naruto comment","/* Supra */","/* Start"," End */","# python","int rx7=5;","goku=goku+1;","   // indented"};
    printf("%-28s %s\n","Line","Result");
    for(int i=0;i<8;i++) printf("%-28s %s\n",L[i],check(L[i]));
    return 0;
}
