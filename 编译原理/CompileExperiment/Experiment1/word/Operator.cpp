//
// Created by sumov on 2020/6/25.
//

#include <cstring>
#include <iostream>
#include "Operator.h"

Operator::~Operator() {

}

bool Operator::parse(char *str) {
    if (!isBegin(str[0]))return false;
    for (int i = 0; str[i]; ++i) {
        if (isEnd(str[i])) {
            wordString[i] = 0;
            return true;
        }
        wordString[i] = str[i];
    }
    return false;
}

char *Operator::format() const {
    return wordString;
}

bool Operator::isBegin(char c) const {
    for (auto op: operatorSet) {
        if (op[0] == c) return true;
    }
    return false;
}

bool Operator::isEnd(char c) const {
    for (auto op:operatorSet) {
        for (int i = 0; op[i]; ++i) {
            if (c == op[i])return false;
        }
    }
    return true;
}

void Operator::wordPrint() {
    std::cout << wordString << std::endl;
}

int Operator::getTypeCode() const {
    return 4;
}

Operator::Operator() {
    operatorSet.push_back("+");
    operatorSet.push_back("-");
    operatorSet.push_back("*");
    operatorSet.push_back("/");
    operatorSet.push_back("=");
    operatorSet.push_back(">");
    operatorSet.push_back("<");
    operatorSet.push_back(">=");
    operatorSet.push_back("<=");
    operatorSet.push_back("!=");
    operatorSet.push_back("==");
    operatorSet.push_back("!");
    operatorSet.push_back("%");

}
