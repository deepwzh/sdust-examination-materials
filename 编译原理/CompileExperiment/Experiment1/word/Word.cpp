//
// Created by sumov on 2020/6/25.
//

#include "Word.h"
#include <cstdlib>
#include <cstring>


Word::Word() {
    wordString = (char *) malloc(sizeof(char) * 100);
    memset(wordString, 0, sizeof(char) * 100);
}

Word::~Word() {
    free(wordString);
}

int Word::stepIncrease() const {
    return strlen(this->wordString);
}
