//
// Created by sumov on 2020/6/25.
//

#include <iostream>
#include "Separator.h"

Separator::~Separator() {

}

bool Separator::parse(char *str) {
    if (isBegin(str[0])) {
        wordString[0] = str[0];
        wordString[1] = 0;
        return true;
    } else return false;
}

char *Separator::format() const {
    return wordString;
}

bool Separator::isBegin(char c) const {
    for (char se: separatorSet) if (c == se) return true;
    return false;
}

bool Separator::isEnd(char c) const {
    return !isBegin(c);
}

void Separator::wordPrint() {
    std::cout << wordString << std::endl;
}

int Separator::getTypeCode() const {
    return 5;
}

Separator::Separator() {
    separatorSet.push_back(',');
    separatorSet.push_back(';');
    separatorSet.push_back('{');
    separatorSet.push_back('}');
    separatorSet.push_back('(');
    separatorSet.push_back(')');
}
