//
// Created by sumov on 2020/6/25.
//

#ifndef COMPILEEXPERIMENT_UNSIGNEDINTEGER_H
#define COMPILEEXPERIMENT_UNSIGNEDINTEGER_H

#include "Word.h"

class UnsignedInteger : public Word {
public:
    ~UnsignedInteger() override;

    bool parse(char *str) override;

    char *format() const override;

    bool isBegin(char c) const override;

    bool isEnd(char c) const override;

    void wordPrint() override;

    int getTypeCode() const override;
};


#endif //COMPILEEXPERIMENT_UNSIGNEDINTEGER_H
