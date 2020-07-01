//
// Created by sumov on 2020/6/25.
//

#include <cstdlib>
#include <cstring>
#include "Parser.h"
#include "word/BlankWord.h"
#include "word/Identifier.h"
#include "word/Operator.h"
#include "word/ReservedWord.h"
#include "word/Separator.h"
#include "word/UnsignedInteger.h"
#include "word/Double.h"
#include <cstdio>
#include <cstdlib>

void Parser::showStatus() {
    char *format = nowWord->format();
    printf("(%d,\"%s\")\t", nowWord->getTypeCode(), format);
}

int Parser::parseNext() {
    bool parseSuccess = false;
    for (auto word:words) {
        if (word->parse(parsedString + pointer)) {
            parseSuccess = true;
            pointer += word->stepIncrease();
            nowWord = word;
            break;
        } else parseSuccess = false;
    }
    if (!parseSuccess && pointer == strlen(parsedString)) {
        return -1;
    }
    if (parseSuccess)return 1;
    return 0;
}

Parser::Parser(char *str) : pointer(0) {
    parsedString = (char *) malloc(1000 * sizeof(char));
    strcpy(parsedString, str);
    words.push_back(new BlankWord());
    words.push_back(new Identifier());
    words.push_back(new Operator());
    words.push_back(new ReservedWord());
    words.push_back(new Separator());
    words.push_back(new UnsignedInteger());
    words.push_back(new Double());
    nowWord = nullptr;
}

Parser::~Parser() {
    free(parsedString);

}
