#include <stdio.h>
#include <ctype.h>
#include <string.h>

int is_kw(char* s) {
    char* k[] = {"int","float","char","if","else","while","for","return","void"};
    for(int i=0; i<9; i++) if(!strcmp(s, k[i])) return 1;
    return 0;
}

int main() {
    FILE* f = fopen("sample.c", "w+");
    fputs("int skyline(){int naruto=10; float supra=3.14; if(naruto>5) naruto=naruto+1; return 0;}", f);
    rewind(f);
    printf("Tokens from sample.c\n%-10s %s\n", "Type", "Value");
    int c, j; char b[64];
    while ((c = fgetc(f)) != EOF) {
        if (isspace(c)) continue;
        b[j = 0] = c;
        if (isalpha(c) || c == '_') {
            while ((c = fgetc(f)) != EOF && (isalnum(c) || c == '_')) b[++j] = c;
            b[++j] = 0; if (c != EOF) ungetc(c, f);
            printf("%-10s %s\n", is_kw(b) ? "KEYWORD" : "IDENT", b);
        } else if (isdigit(c)) {
            while ((c = fgetc(f)) != EOF && (isdigit(c) || c == '.')) b[++j] = c;
            b[++j] = 0; if (c != EOF) ungetc(c, f);
            printf("%-10s %s\n", "NUMBER", b);
        } else if (strchr("+-*/=<>!&|^%", c)) {
            while ((c = fgetc(f)) != EOF && strchr("+-*/=<>!&|^%", c)) b[++j] = c;
            b[++j] = 0; if (c != EOF) ungetc(c, f);
            printf("%-10s %s\n", "OP", b);
        } else printf("%-10s %c\n", strchr("{}();,", c) ? "PUNC" : "UNK", c);
    }
    fclose(f); return 0;
}
