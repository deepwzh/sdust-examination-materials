//
// Created by sumov on 2020/6/25.
//

#include <iostream>
#include "UnsignedInteger.h"

UnsignedInteger::~UnsignedInteger() {

}

bool UnsignedInteger::parse(char *str) {
    if (!isBegin(str[0]))return false;
    for (int i = 0; str[i]; ++i) {
        if (isEnd(str[i])) {
            wordString[i] = 0;
            return true;
        }
        if ((str[i] >= '0' && str[i] <= '9'))wordString[i] = str[i];
        else return false;
    }
    return true;
}

char *UnsignedInteger::format() const {
    return wordString;
}

bool UnsignedInteger::isBegin(char c) const {
    return c >= '0' && c <= '9';
}

bool UnsignedInteger::isEnd(char c) const {
    return !isBegin(c) &&
           !(c >= 'a' && c <= 'z') &&
           !(c >= 'A' && c <= 'Z');
}

void UnsignedInteger::wordPrint() {
    std::cout << wordString << std::endl;
}

int UnsignedInteger::getTypeCode() const {
    return 3;
}
