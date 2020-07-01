//
// Created by sumov on 2020/6/25.
//

#ifndef COMPILEEXPERIMENT_PARSER_H
#define COMPILEEXPERIMENT_PARSER_H


#include <vector>
#include "word/Word.h"

/**
 * 这都啥啊...
 */
class Parser {
private:
    int pointer;
    char *parsedString;
    std::vector<Word *> words;
    Word *nowWord;
public:
    Parser(char *str);

    ~Parser();

    int parseNext();

    void showStatus();
};


#endif //COMPILEEXPERIMENT_PARSER_H
