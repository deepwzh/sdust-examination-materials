//
// Created by sumov on 2020/6/25.
//

#ifndef COMPILEEXPERIMENT_IDENTIFIER_H
#define COMPILEEXPERIMENT_IDENTIFIER_H

#include "Word.h"
#include "ReservedWord.h"

class Identifier : public Word {
private:
    ReservedWord reservedWord;
public:
    explicit Identifier();

    bool parse(char *str) override;

    char *format() const override;

    bool isBegin(char c) const override;

    bool isEnd(char c) const override;

    void wordPrint() override;

    int getTypeCode() const override;

public:
    ~Identifier() override;
};


#endif //COMPILEEXPERIMENT_IDENTIFIER_H
