//
// Created by sumov on 2020/6/25.
//

#ifndef COMPILEEXPERIMENT_WORD_H
#define COMPILEEXPERIMENT_WORD_H


class Word {
protected:
    char *wordString;
public:
    explicit Word();

    virtual ~Word();

    int stepIncrease() const;

    virtual bool parse(char *str) = 0;

    virtual char *format() const = 0;

    virtual bool isBegin(char c) const = 0;

    virtual bool isEnd(char c) const = 0;

    virtual void wordPrint() = 0;

    virtual int getTypeCode() const = 0;
};


#endif //COMPILEEXPERIMENT_WORD_H
