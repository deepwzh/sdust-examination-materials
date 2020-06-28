//
// Created by sumov on 2020/6/25.
//

#include <cstdlib>
#include <cstring>
#include <iostream>
#include "ReservedWord.h"

ReservedWord::~ReservedWord() {

}

bool ReservedWord::parse(char *str) {
    for (int i = 0; reservedwords[i][0] != 0; ++i)
        if (strcmp(reservedwords[i], str) == 0) {
            strcpy(wordString, str);
            return true;
        }
    return false;
}

char *ReservedWord::format() const {
    return wordString;
}

bool ReservedWord::isBegin(char c) const {
    for (int i = 0; reservedwords[i][0] != 0; ++i)
        if (c == reservedwords[i][0])return true;
    return false;
}

bool ReservedWord::isEnd(char c) const {
    return ![](char c) -> bool {
        return c >= 'a' && c <= 'z' ||
               c >= 'A' && c <= 'Z';
    }(c);
}

void ReservedWord::wordPrint() {
    std::cout << this->wordString << std::endl;
}

ReservedWord::ReservedWord() {
    this->reservedwords = (char **) malloc(100 * sizeof(char *));
    for (int i = 0; i < 100; ++i) {
        this->reservedwords[i] = (char *) malloc(1000 * sizeof(char));
        memset(this->reservedwords[i], 0, 1000 * sizeof(char));
    }
    strcpy(reservedwords[0], "if");
    strcpy(reservedwords[1], "int");
    strcpy(reservedwords[2], "for");
    strcpy(reservedwords[3], "while");
    strcpy(reservedwords[4], "do");
    strcpy(reservedwords[5], "return");
    strcpy(reservedwords[6], "break");
    strcpy(reservedwords[7], "continue");
    strcpy(reservedwords[8], "double");

}

int ReservedWord::getTypeCode() const {
    return 1;
}
