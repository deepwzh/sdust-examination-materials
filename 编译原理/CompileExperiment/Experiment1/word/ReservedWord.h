//
// Created by sumov on 2020/6/25.
//

#ifndef COMPILEEXPERIMENT_RESERVEDWORD_H
#define COMPILEEXPERIMENT_RESERVEDWORD_H

#include "Word.h"
#include <vector>

class ReservedWord : public Word {
private:
    char **reservedwords;

public:
    explicit ReservedWord();

    ~ReservedWord() override;

    bool parse(char *str) override;

    char *format() const override;

    bool isBegin(char c) const override;

    bool isEnd(char c) const override;

    int getTypeCode() const override;

    void wordPrint() override;
};


#endif //COMPILEEXPERIMENT_RESERVEDWORD_H
