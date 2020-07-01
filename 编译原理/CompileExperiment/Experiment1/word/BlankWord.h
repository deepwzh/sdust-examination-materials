//
// Created by sumov on 2020/6/25.
//

#ifndef COMPILEEXPERIMENT_BLANKWORD_H
#define COMPILEEXPERIMENT_BLANKWORD_H

#include "Word.h"

/**
 * 空白字符判断
 */
class BlankWord : public Word {
public:
    bool parse(char *str) override;

    char *format() const override;

    bool isBegin(char c) const override;

    int getTypeCode() const override;

    bool isEnd(char c) const override;

    void wordPrint() override;
};


#endif //COMPILEEXPERIMENT_BLANKWORD_H
