//
// Created by sumov on 2020/6/25.
//

#ifndef COMPILEEXPERIMENT_OPERATOR_H
#define COMPILEEXPERIMENT_OPERATOR_H

#include <vector>
#include "Word.h"

class Operator : public Word {
private:
    std::vector<char *> operatorSet;
public:
    explicit Operator();

    ~Operator() override;

    bool parse(char *str) override;

    char *format() const override;

    bool isBegin(char c) const override;

    bool isEnd(char c) const override;

    void wordPrint() override;

    int getTypeCode() const override;
};


#endif //COMPILEEXPERIMENT_OPERATOR_H
