//
// Created by sumov on 2020/6/26.
//

#include <iostream>
#include "Double.h"

Double::~Double() {

}

/**
 * -1
 * +1
 * 1.2333
 * 2.33
 * 0.22
 * 1.3e1.2
 * @return
 */
bool Double::parse(char *str) {
    if (!isBegin(str[0]))return false;
    for (int i = 0; str[i]; ++i) {
        if (isEnd(str[i])) {
            wordString[i] = 0;
            return true;
        }
        if (
                str[i] >= '0' && str[i] <= '9' ||
                str[i] == 'e' ||
                str[i] == '.' ||
                str[i] == '-' ||
                str[i] == '+'
                )
            wordString[i] = str[i];
        else return false;
    }
}

char *Double::format() const {
    return wordString;
}

bool Double::isBegin(char c) const {
    if (c == '+') return true;
    if (c == '-')return true;
    return c >= '0' && c <= '9';
}

bool Double::isEnd(char c) const {
    if (separator.isBegin(c)) return true;
    if (blankWord.isBegin(c))return true;
    if (operator1.isBegin(c) && c != '-' && c != '+')return true;
    return false;
}

void Double::wordPrint() {
    std::cout << wordString << std::endl;
}

int Double::getTypeCode() const {
    return 7;
}

Double::Double() {

}
