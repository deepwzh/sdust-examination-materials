//
// Created by sumov on 2020/6/25.
//

#ifndef COMPILEEXPERIMENT_SEPARATOR_H
#define COMPILEEXPERIMENT_SEPARATOR_H

#include <vector>
#include "Word.h"

class Separator : public Word {
private:
    std::vector<char> separatorSet;
public:
    explicit Separator();

    ~Separator() override;

    bool parse(char *str) override;

    char *format() const override;

    bool isBegin(char c) const override;

    bool isEnd(char c) const override;

    void wordPrint() override;

    int getTypeCode() const override;
};


#endif //COMPILEEXPERIMENT_SEPARATOR_H
