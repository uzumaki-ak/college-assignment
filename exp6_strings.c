#include <stdio.h>
#include <string.h>

int a_star(const char*s){ for(int i=0;s[i];i++) if(s[i]!='a') return 0; return 1; }
int a_star_b_plus(const char*s){ int i=0; while(s[i]=='a') i++; if(s[i]!='b') return 0; while(s[i]=='b') i++; return s[i]=='\0'; }
int abb(const char*s){ return !strcmp(s,"abb"); }

int main(){
    const char*S[]={"","a","aaa","b","bb","ab","aab","aabb","abb","abbb","bbb","ba","abc"};
    printf("%-10s %-8s %-8s %-8s\n","String","a*","a*b+","abb");
    for(int i=0;i<13;i++){
        char d[24]; if(S[i][0]) snprintf(d,sizeof(d),"\"%s\"",S[i]); else strcpy(d,"\"\"(empty)");
        printf("%-10s %-8s %-8s %-8s\n",d,a_star(S[i])?"Match":"No",a_star_b_plus(S[i])?"Match":"No",abb(S[i])?"Match":"No");
    }
    return 0;
}
