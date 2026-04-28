#include <stdio.h>
#include <string.h>

const char*type(const char*o){
    if(!strcmp(o,"+")||!strcmp(o,"-")||!strcmp(o,"*")||!strcmp(o,"/")||!strcmp(o,"%")) return "Arithmetic";
    if(!strcmp(o,"==")||!strcmp(o,"!=")||!strcmp(o,"<")||!strcmp(o,">")||!strcmp(o,"<=")||!strcmp(o,">=")) return "Relational";
    if(!strcmp(o,"&&")||!strcmp(o,"||")||!strcmp(o,"!")) return "Logical";
    if(!strcmp(o,"=")||!strcmp(o,"+=")||!strcmp(o,"-=")||!strcmp(o,"*=")||!strcmp(o,"/=")) return "Assignment";
    if(!strcmp(o,"&")||!strcmp(o,"|")||!strcmp(o,"^")||!strcmp(o,"~")||!strcmp(o,"<<")||!strcmp(o,">>")) return "Bitwise";
    return "Unknown";
}
int isop(char c){ return strchr("+-*/%=<>!&|^~",c)!=NULL; }

int main(){
    char e[]="supra += 10; if(naruto==goku && rx7!=ae86 || luffy>=5){supra*=2;}";
    printf("Expr: %s\n%-8s %s\n",e,"Op","Type");
    for(int i=0;e[i];){
        char o[3]={0};
        if(!isop(e[i])){ i++; continue; }
        if((e[i]=='='&&e[i+1]=='=')||(e[i]=='!'&&e[i+1]=='=')||(e[i]=='<'&&e[i+1]=='=')||(e[i]=='>'&&e[i+1]=='=')||
           (e[i]=='&'&&e[i+1]=='&')||(e[i]=='|'&&e[i+1]=='|')||(e[i]=='<'&&e[i+1]=='<')||(e[i]=='>'&&e[i+1]=='>')||
           (e[i]=='+'&&e[i+1]=='=')||(e[i]=='-'&&e[i+1]=='=')||(e[i]=='*'&&e[i+1]=='=')||(e[i]=='/'&&e[i+1]=='=')){
            o[0]=e[i]; o[1]=e[i+1]; i+=2;
        } else { o[0]=e[i++]; }
        printf("%-8s %s\n",o,type(o));
    }
    return 0;
}
