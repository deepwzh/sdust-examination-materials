//
// Created by sumov on 2020/6/26.
//

#ifndef COMPILEEXPERIMENT_DOUBLE_H
#define COMPILEEXPERIMENT_DOUBLE_H

#include "Word.h"
#include "Separator.h"
#include "BlankWord.h"
#include "Operator.h"

/**
 * ( +|-|ε ) dd*(.dd* | ε)( e ( +|-|ε ) dd*|ε)
 */
class Double : public Word {
private:
    Separator separator;
    BlankWord blankWord;
    Operator operator1;

public:
    explicit Double();

    ~Double() override;

    bool parse(char *str) override;

    char *format() const override;

    bool isBegin(char c) const override;

    bool isEnd(char c) const override;

    void wordPrint() override;

    int getTypeCode() const override;
};


#endif //COMPILEEXPERIMENT_DOUBLE_H
