//
// Created by sumov on 2020/6/27.
//
#include <bits/stdc++.h>
#include "Production.h"

int main(int argc, char *argv[], char *env[]) {
    std::vector<Production> grammer;
    std::string line;
    while (getline(std::cin, line)) {
        grammer.push_back(Production::parseProduction(line));
    }
    for (Production &p:grammer) {
        auto FIRST = p.getFIRST(grammer);
        p.setFirst(std::vector<char>(FIRST.get_allocator()));
    }
    for (Production p:grammer) {
        p.print();
        putchar('\n');
    }

}