#include <stdio.h>
#include <string.h>

const char* t(char* o) {
    char b[5]; sprintf(b, " %s ", o);
    if(strstr(" + - * / % ", b)) return "Arithmetic";
    if(strstr(" == != <= >= < > ", b)) return "Relational";
    if(strstr(" && || ! ", b)) return "Logical";
    if(strstr(" += -= *= /= = ", b)) return "Assignment";
    if(strstr(" & | ^ ~ << >> ", b)) return "Bitwise";
    return "Unknown";
}

int main() {
    char e[]="supra += 10; if(naruto==goku && rx7!=ae86 || luffy>=5){supra*=2;}", o[3]={0};
    printf("Expr: %s\n%-8s %s\n", e, "Op", "Type");
    for(int i=0; e[i]; ) {
        if(!strchr("+-*/%=<>!&|^~", e[i])) { i++; continue; }
        o[0]=e[i]; o[1]=strchr("=|<>&", e[i+1]) ? e[i+1] : 0; o[2]=0;
        i += o[1] ? 2 : 1;
        printf("%-8s %s\n", o, t(o));
    }
    return 0;
}
