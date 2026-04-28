#include <stdio.h>
#include <string.h>
#include <ctype.h>

char tok[256][8]; int n;

void tokenize(const char *s){
    int i=0; n=0;
    while(s[i]){
        if(isspace((unsigned char)s[i])){ i++; continue; }
        if(isalpha((unsigned char)s[i])||s[i]=='_'){ while(isalnum((unsigned char)s[i])||s[i]=='_') i++; strcpy(tok[n++],"id"); continue; }
        if(isdigit((unsigned char)s[i])){ while(isdigit((unsigned char)s[i])) i++; strcpy(tok[n++],"num"); continue; }
        if(strchr("+*()",s[i])){ tok[n][0]=s[i]; tok[n++][1]=0; i++; continue; }
        i++;
    }
    strcpy(tok[n++],"$");
}

int term(const char*s){ return !strcmp(s,"id")||!strcmp(s,"num")||!strcmp(s,"+")||!strcmp(s,"*")||!strcmp(s,"(")||!strcmp(s,")")||!strcmp(s,"$"); }
int prod(const char*X,const char*a,const char*o[],int *m){
    *m=0;
    if(!strcmp(X,"E")){ if(!strcmp(a,"id")||!strcmp(a,"num")||!strcmp(a,"(")){ o[0]="T"; o[1]="Q"; *m=2; return 1; } }
    else if(!strcmp(X,"Q")){ if(!strcmp(a,"+")){ o[0]="+"; o[1]="T"; o[2]="Q"; *m=3; return 1; } if(!strcmp(a,")")||!strcmp(a,"$")) return 1; }
    else if(!strcmp(X,"T")){ if(!strcmp(a,"id")||!strcmp(a,"num")||!strcmp(a,"(")){ o[0]="F"; o[1]="R"; *m=2; return 1; } }
    else if(!strcmp(X,"R")){ if(!strcmp(a,"*")){ o[0]="*"; o[1]="F"; o[2]="R"; *m=3; return 1; } if(!strcmp(a,"+")||!strcmp(a,")")||!strcmp(a,"$")) return 1; }
    else if(!strcmp(X,"F")){ if(!strcmp(a,"id")){ o[0]="id"; *m=1; return 1; } if(!strcmp(a,"num")){ o[0]="num"; *m=1; return 1; } if(!strcmp(a,"(")){ o[0]="("; o[1]="E"; o[2]=")"; *m=3; return 1; } }
    return 0;
}

int parse(const char *s){
    char st[128][8]; int top=0, i=0;
    tokenize(s); strcpy(st[top++],"$"); strcpy(st[top++],"E");
    printf("\nInput: %s\n",s);
    while(strcmp(st[top-1],"$")){
        char *X=st[top-1], *a=tok[i];
        if(term(X)){
            if(!strcmp(X,a)){ printf("match %s\n",a); top--; i++; }
            else { printf("error at %s\n",a); return 0; }
        }else{
            const char*o[4]; int m=0;
            if(!prod(X,a,o,&m)){ printf("no rule (%s,%s)\n",X,a); return 0; }
            top--; printf("%s ->",X); if(!m) printf(" eps");
            for(int k=0;k<m;k++) printf(" %s",o[k]); printf("\n");
            for(int k=m-1;k>=0;k--) strcpy(st[top++],o[k]);
        }
    }
    if(!strcmp(tok[i],"$")){ puts("Accepted"); return 1; }
    puts("Rejected"); return 0;
}

int main(){
    parse("naruto + goku * luffy");
    parse("supra * (rx7 + 7)");
    parse("goku + vegeta");
    return 0;
}
