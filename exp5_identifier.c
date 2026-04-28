#include <stdio.h>
#include <ctype.h>
#include <string.h>

int kw(const char*s){
    const char*k[]={"int","float","char","if","else","while","for","return","void","do","break"};
    for(int i=0;i<11;i++) if(!strcmp(s,k[i])) return 1; return 0;
}
const char*ok(const char*t){
    if(!(isalpha((unsigned char)t[0])||t[0]=='_')) return isdigit((unsigned char)t[0])?"INVALID: starts digit":"INVALID";
    for(int i=1;t[i];i++) if(!(isalnum((unsigned char)t[i])||t[i]=='_')) return "INVALID: bad char";
    if(kw(t)) return "INVALID: keyword";
    return "VALID";
}

int main(){
    const char*T[]={"naruto","supra1","2start","my-var","total_sum","if","int","MAX_RX7","goku","123abc","data@base","__vegeta__"};
    printf("%-12s %s\n","Identifier","Result");
    for(int i=0;i<12;i++) printf("%-12s %s\n",T[i],ok(T[i]));
    return 0;
}
