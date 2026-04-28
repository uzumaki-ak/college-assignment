#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct{ char k; int n; } Act;
char tok[256][8]; int n;

void tokenize(const char *s){
    int i=0; n=0;
    while(s[i]){
        if(isspace((unsigned char)s[i])){ i++; continue; }
        if(isalpha((unsigned char)s[i])||s[i]=='_'){ while(isalnum((unsigned char)s[i])||s[i]=='_') i++; strcpy(tok[n++],"id"); continue; }
        if(strchr("+*()",s[i])){ tok[n][0]=s[i]; tok[n++][1]=0; i++; continue; }
        i++;
    }
    strcpy(tok[n++],"$");
}

Act act(int s,const char*t){
    if(s==0&&(!strcmp(t,"id"))) return (Act){'s',5}; if(s==0&&(!strcmp(t,"("))) return (Act){'s',4};
    if(s==1&&(!strcmp(t,"+"))) return (Act){'s',6};  if(s==1&&(!strcmp(t,"$"))) return (Act){'a',0};
    if(s==2&&(!strcmp(t,"+"))) return (Act){'r',2};  if(s==2&&(!strcmp(t,"*"))) return (Act){'s',7}; if(s==2&&(!strcmp(t,")"))) return (Act){'r',2}; if(s==2&&(!strcmp(t,"$"))) return (Act){'r',2};
    if(s==3&&(!strcmp(t,"+"))) return (Act){'r',4};  if(s==3&&(!strcmp(t,"*"))) return (Act){'r',4}; if(s==3&&(!strcmp(t,")"))) return (Act){'r',4}; if(s==3&&(!strcmp(t,"$"))) return (Act){'r',4};
    if(s==4&&(!strcmp(t,"id"))) return (Act){'s',5}; if(s==4&&(!strcmp(t,"("))) return (Act){'s',4};
    if(s==5&&(!strcmp(t,"+"))) return (Act){'r',6};  if(s==5&&(!strcmp(t,"*"))) return (Act){'r',6}; if(s==5&&(!strcmp(t,")"))) return (Act){'r',6}; if(s==5&&(!strcmp(t,"$"))) return (Act){'r',6};
    if(s==6&&(!strcmp(t,"id"))) return (Act){'s',5}; if(s==6&&(!strcmp(t,"("))) return (Act){'s',4};
    if(s==7&&(!strcmp(t,"id"))) return (Act){'s',5}; if(s==7&&(!strcmp(t,"("))) return (Act){'s',4};
    if(s==8&&(!strcmp(t,"+"))) return (Act){'s',6};  if(s==8&&(!strcmp(t,")"))) return (Act){'s',11};
    if(s==9&&(!strcmp(t,"+"))) return (Act){'r',1};  if(s==9&&(!strcmp(t,"*"))) return (Act){'s',7}; if(s==9&&(!strcmp(t,")"))) return (Act){'r',1}; if(s==9&&(!strcmp(t,"$"))) return (Act){'r',1};
    if(s==10&&(!strcmp(t,"+"))) return (Act){'r',3}; if(s==10&&(!strcmp(t,"*"))) return (Act){'r',3}; if(s==10&&(!strcmp(t,")"))) return (Act){'r',3}; if(s==10&&(!strcmp(t,"$"))) return (Act){'r',3};
    if(s==11&&(!strcmp(t,"+"))) return (Act){'r',5}; if(s==11&&(!strcmp(t,"*"))) return (Act){'r',5}; if(s==11&&(!strcmp(t,")"))) return (Act){'r',5}; if(s==11&&(!strcmp(t,"$"))) return (Act){'r',5};
    return (Act){'e',0};
}

int gt(int s,char A){
    if(s==0&&A=='E') return 1; if(s==0&&A=='T') return 2; if(s==0&&A=='F') return 3;
    if(s==4&&A=='E') return 8; if(s==4&&A=='T') return 2; if(s==4&&A=='F') return 3;
    if(s==6&&A=='T') return 9; if(s==6&&A=='F') return 3;
    if(s==7&&A=='F') return 10;
    return -1;
}

int main(){
    const char *lhs=" EETTFF"; int len[]={0,3,1,3,1,3,1};
    char *in[]={"naruto + goku * luffy","supra * rx7","(ae86 + evo) * skyline"};
    for(int z=0;z<3;z++){
        int st[256],top=0,i=0; tokenize(in[z]); st[top]=0;
        printf("\nInput: %s\n",in[z]);
        while(1){
            Act a=act(st[top],tok[i]);
            if(a.k=='a'){ puts("Accept"); break; }
            if(a.k=='e'){ printf("Error at %s\n",tok[i]); break; }
            if(a.k=='s'){ st[++top]=a.n; i++; continue; }
            top -= len[a.n]; int g=gt(st[top],lhs[a.n]); if(g<0){ puts("Goto error"); break; } st[++top]=g;
            printf("reduce r%d\n",a.n);
        }
    }
    return 0;
}
