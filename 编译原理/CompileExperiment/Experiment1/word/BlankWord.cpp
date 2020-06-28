//
// Created by sumov on 2020/6/25.
//

#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include "BlankWord.h"

bool BlankWord::parse(char *str) {
    if (str[0] == ' ') {
        wordString[0] = ' ';
        wordString[1] = 0;
        return true;
    }
    if (str[0] == '\n') {
        wordString[0] = '\n';
        wordString[1] = 0;
        return true;
    }
    return false;
}

char *BlankWord::format() const {
    if (wordString[0] == '\n') {
        return "\\n";
    } else return wordString;
}

bool BlankWord::isBegin(char c) const {
    if (c == ' ')return true;
    if (c == '\n')return true;
    if (c == '\t')return true;
    return false;
}

bool BlankWord::isEnd(char c) const {
    return !isBegin(c);
}

void BlankWord::wordPrint() {
    std::cout << wordString << std::endl;
}

int BlankWord::getTypeCode() const {
    return 0;
}
