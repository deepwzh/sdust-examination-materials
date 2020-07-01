//
// Created by sumov on 2020/6/25.
//

#include <cstring>
#include <iostream>
#include "Identifier.h"

Identifier::~Identifier() = default;

bool Identifier::parse(char *str) {
    if (reservedWord.parse(str))return false;
    if (!isBegin(str[0]))return false;
    for (int i = 0; str[i] != 0; ++i) {
        if (isEnd(str[i])) {
            wordString[i] = 0;
            return true;
        }
        wordString[i] = str[i];
    }
    return true;
}

char *Identifier::format() const {
    return this->wordString;
}

bool Identifier::isBegin(char c) const {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

bool Identifier::isEnd(char c) const {
    return !(
            (c >= 'a' && c <= 'z') ||
            (c >= 'A' && c <= 'Z') ||
            (c >= '0' && c <= '9')
    );
}

void Identifier::wordPrint() {
    std::cout << wordString << std::endl;
}

int Identifier::getTypeCode() const {
    return 2;
}

Identifier::Identifier() = default;
