//
// Created by sumov on 2020/6/27.
//

#ifndef COMPILEEXPERIMENT_PRODUCTION_H
#define COMPILEEXPERIMENT_PRODUCTION_H

#include <bits/stdc++.h>

/**
 * 文法的产生式类
 * 我们用$代替空, 用#代指结束
 */
class Production {
private:
    char left;
    std::vector<char> right, FIRST, FELLOW;
public:

    void addFIRST(char c) {
        FIRST.push_back(c);
    }

    void addFELLOW(char c) {
        FELLOW.push_back(c);
    }

    char getLeft() const {
        return left;
    }

    void setLeft(char l) {
        Production::left = l;
    }

    const std::vector<char> &getRight() const {
        return right;
    }

    void setRight(const std::vector<char> &r) {
        for (char c: r) {
            this->right.push_back(c);
        }
    }

    const std::vector<char> &getFirst() const {
        return FIRST;
    }

    void setFirst(const std::vector<char> &first) {
        this->FIRST.clear();
        for (char c:first) this->FIRST.push_back(c);
    }

    const std::vector<char> &getFellow() const {
        return FELLOW;
    }

    void setFellow(const std::vector<char> &fellow) {
        this->FELLOW.clear();
        for (char c:fellow) FELLOW.push_back(c);
    }

    void clear() {
        FIRST.clear();
        FELLOW.clear();
    }

    static Production parseProduction(std::string proStr) {
        Production result;
        result.left = proStr[0];
        for (int i = 3; i < proStr.size(); ++i)
            result.right.push_back(proStr[i]);
        return result;
    }

    void print() {
        putchar(left);
        printf("->");
        for (char c:right)putchar(c);
        putchar('\t');
        for (char c:FIRST) {
            putchar(c);
            putchar(' ');
        }
        putchar('\t');
        for (char c:FELLOW) {
            putchar(c);
            putchar(' ');
        }
    }

    /**
     * 基本步骤
     *  对右侧所有字符从左到右进行分析, 对于每个字符
     *      1.  如果是终结符, 那么在result中添加后直接返回
     *      2.  如果是非终结符, 那么递归求非终结符的FIRST集
     *      3.  如果非终结符的FIRST集中不含$, 那么将FIRST集中所有的字符加入result, 返回
     *      4.  如果非终结符的FIRST集中含$, 那么将FIRST集中的所有非$字符加入result, 重复
     *  如果遍历完了且没有直接退出, 那么在result中加入$并去重.
     * @param grammer
     * @return
     */
    std::set<char> getFIRST(std::vector<Production> grammer) {
        if (!this->FIRST.empty())return std::set<char>(this->FIRST.get_allocator());
        std::set<char> result;
        //  先求一下非终结符集合
        std::set<char> nonTerminalSet;
        for (const Production &p:grammer)nonTerminalSet.insert(p.getLeft());
        //  开始遍历
        for (char sympol: right) {
            if (nonTerminalSet.count(sympol)) { //  如果是终结符
                //  递归求其FIRST集合
                //  先找到所有匹配的产生式
                std::vector<Production> pros = getMatchProduction(grammer, sympol);
                std::set<char> rightFIRST;
                for (Production p:pros) {   //   求所有产生式的FIRST集合
                    for (char c: p.getFIRST(grammer)) {
                        rightFIRST.insert(c);
                    }
                }
                //  如果当前非终结符的FIRST集合中有$, 那么把当前集合的所有元素压入result, 并继续循环
                if (rightFIRST.count('$') == 0) {
                    for (char c: rightFIRST)
                        result.insert(c);
                } else {    //  如果没有, 那么把result中的$删除并取并集
                    for (char c: rightFIRST)
                        result.insert(c);
                    result.erase('$');
                    //  走到头了, 将result返回
                    return result;
                }
            } else {    //  如果不是
                result.insert(sympol);
                return result;
            }
        }
        return result;
    }

    /**
     *  获得当前产生式left的FELLOW集
     * @param grammer
     * @return
     */
    std::set<char> getFELLOW(std::vector<Production> grammer) {
        if (!FELLOW.empty()) return std::set<char>(FELLOW.get_allocator());
        for (Production &p:grammer) {
            if (!(p == *this) && p.left == this->left && !p.FELLOW.empty())return p.getFELLOW(grammer);
        }
    }

    static std::vector<Production> getMatchProduction(
            std::vector<Production> grammer, char c
    ) {
        std::vector<Production> result;
        for (Production p: grammer)
            if (p.left == c) result.push_back(p);
        return result;
    }

    bool operator==(const Production &production) const {
        return this->left == production.left &&
               [](const std::vector<char> &v1, const std::vector<char> &v2) -> bool {
                   if (v1.size() != v2.size()) return false;
                   else for (int i = 0; i < v1.size(); ++i)if (v1[i] != v2[i])return false;
                   return true;
               }(this->right, production.right);
    }
};

//namespace production_process {
//
///**
// * 消除左递归
// * @param grammer
// */
//    void eliminateLeftRecursion(std::vector<Production> &grammer) {
//        //  暂时没想好怎么写
//    }
//
///**
// * 对所有文法重求FIRST集合
// * 默认已经消除左递归
// * @param grammer
// */
//    void recreateFIRST(std::vector<Production> &grammer) {
//        //  先求一遍非终结符集合
//        std::set<char> nonTerminalSet;
//        for (const auto &p:grammer) nonTerminalSet.insert(p.getLeft());
//        //  第一遍循环, 对产生式右侧第一个字符为终结符的进行讨论
//        for (Production &production:grammer) {
//            const auto &right = production.getRight();
//            //  如果right中第一个字符为非终结符, 那么跳
//            if (nonTerminalSet.count(right[0])) continue;
//            else {  //  如果right中第一个字符是终结符, 那么在本产生式的FIRST集合中添加一个字符
//                production.addFIRST(right[0]);
//            }
//        }
//        //  第二遍循环, 对产生式右侧第一个字符为非终结符的进行讨论
//        //  本次循环
//
//    }
//
///**
// * 对所有文法重求FELLOW
// * 默认已经消除左递归
// * 默认已经求FIRST了
// * @param grammer
// */
//    void recreateFELLOW(std::vector<Production> &grammer) {
//
//    }
//}

#endif //COMPILEEXPERIMENT_PRODUCTION_H
