#include <bits/stdc++.h>

#include "Parser.h"

void read(char *s) {
    char c;
    int i = 0;
    while ((c = getchar()) != EOF) {
        s[i++] = c;
    }
}

int main(int argc, char *argv[], char *env[]) {
    char fileIn[10000];
    memset(fileIn, 0, sizeof(fileIn));
    read(fileIn);
    printf("\n************\n待输入的字符串为:\n%s\n************\n", fileIn);
    Parser parser(fileIn);
    while (true) {
        int status = parser.parseNext();
        if (status == -1) {
            printf("parse success!");
            break;
        }
        if (status == 0) {
            printf("parse error!");
            break;
        }
        parser.showStatus();
    }
}