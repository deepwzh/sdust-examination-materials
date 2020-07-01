//
// Created by sumov on 2020/6/26.
//
#include <bits/stdc++.h>

using namespace std;

#define SUMOVER_DEBUG 1

/**
 * 在这里, 我们用$代替空, 用#代替结束
 */
struct Grammer {
    char left;
    vector<char> right;
    vector<char> FIRST, FELLOW;

    bool inFIRST(char c) {
        if (FIRST[0] == '$')return true;
        for (char s:FIRST)if (s == c) return true;
        return false;
    }

    bool inFELLOW(char c) {
        for (char s:FELLOW) if (s == c)return true;
        return false;
    }

    void printG() {
        printf("%c->", left);
        for (char c: right) printf("%c", c);
    }

    void printFIRST() {
        for (char c:FIRST) {
            cout << c << ' ';
        }
    }

    void printFELLOW() {
        for (char c:FELLOW) {
            cout << c << ' ';
        }
    }

    void setLeft(char c) { left = c; }

    void setRight(char *s) { for (int i = 0; s[i]; ++i)right.push_back(s[i]); }

    void addRight(char c) { right.push_back(c); }

    void setFIRST(char *s) { for (int i = 0; s[i]; ++i) FIRST.push_back(s[i]); }

    void addFIRST(char c) { FIRST.push_back(c); }

    void setFELLOW(char *s) { for (int i = 0; s[i]; ++i) FELLOW.push_back(s[i]); }

    void reset() {
        FIRST.clear();
        FELLOW.clear();
        right.clear();
    }
};

vector<Grammer> grammers;
stack<char> parsedStack;
string parsedString;


/*
（1）E->TG
（2）G->+TG|—TG
（3）G->ε
（4）T->FS
（5）S->*FS|/FS
（6）S->ε
（7）F->(E)
（8）F->i
 */
void init() {
    Grammer grammer;
    char lefts[100] = "EGGGTSSSFF";
    char rights[100][100] = {
            "TG",
            "+TG",
            "-TG",
            "$",
            "FS",
            "*FS",
            "/FS",
            "$",
            "(E)",
            "i"
    };
    char FIRST[100][100] = {
            "(i",
            "+",
            "-",
            "$",
            "(i",
            "*",
            "/",
            "$",
            "(",
            "i"
    };
    char FELLOW[100][100] = {
            "E#",
            "G#",
            "T+-#",
            "F*/+-#",
            "S+-#"
    };
    for (int i = 0; i < 10; ++i) {
        grammer.reset();
        grammer.setLeft(lefts[i]);
        grammer.setRight(rights[i]);
        grammer.setFIRST(FIRST[i]);
        for (int j = 0; j < 5; ++j) {
            if (FELLOW[j][0] == grammer.left) {
                grammer.setFELLOW(FELLOW[j] + 1);
            }
        }
        grammers.push_back(grammer);
    }
    parsedStack.push('#');
    parsedStack.push('E');
}

void grammerPrint() {
    printf("GRAMMER\tFIRST\tFELLOW\n");
    for (Grammer g:grammers) {
        g.printG();
        putchar('\t');
        g.printFIRST();
        putchar('\t');
        g.printFELLOW();
        putchar('\n');
    }
}

/**
 * 若解析出错, 则直接返回-1, 若解析成功, 则返回0
 * @param pointer
 * @return
 */
int parse(int pointer = 0) {
    bool parseError = true;
    while (true) {
        char stackTop = parsedStack.top();
        parsedStack.pop();
        bool parseSueccess = false;
        for (Grammer g:grammers) {      //  遍历查找所有的文法
            if (g.left == stackTop && g.inFIRST(parsedString[pointer])) {   //  如果找到且FIRST集中含有当前string指的字符
                parseSueccess = true;     //  当前阶段解析成功

                vector<char> right = g.right;   //  复制一份拷贝
                //  将right翻转, 并压入栈中
                reverse(right.begin(), right.end());

                for (char c: right) {
                    if (c == '$')continue;
                    parsedStack.push(c);
                }
                //  若栈顶有与字符串中相匹配的终结符, 那么直接匹配, 并弹出. 直到找不到下一个匹配或栈空
                while (true) {

                    if (parsedStack.empty()) {  //  栈空, 结束匹配并返回解析成功
                        return 0;
                    }// 栈不空的话那么判断一下
                    //  如果当前栈顶为非终结符
                    bool isNonTerminal = false;
                    for (Grammer &g1:grammers)
                        if (g1.left == parsedStack.top()) {
                            isNonTerminal = true;
                            //  如果当前栈顶的非终结符的FELLOW中有当前字符串的头, 那么弹出并继续
                            if (g1.inFELLOW(parsedString[pointer])) {
                                parsedStack.pop();
                            }
                            break;
                        }
                    //  如果发现栈顶是非终结符, 那么直接结束当前循环并进行下个循环
                    if (isNonTerminal)break;
                    //  如果是终结符, 那么判断一下
                    //  当前栈顶字符和字符串所指的字符相同
                    if (parsedStack.top() == parsedString[pointer]) {
                        pointer++;
                        parsedStack.pop();
                    } else {    //  当前栈顶字符和字符串所指的字符串不匹配, 直接error
                        return -1;
                    }
                }
                //  很明显, 如果匹配到的话, 那么直接跳就行了
                break;
            }
        }
        if (parseSueccess)continue;
        else return -1;//  如果不含的话, 那么直接跳出并报错.
    }
}
#define ARGUEMENT 0
int main(int argc, char *argv[], char *env[]) {
#if ARGUEMENT
    char *name, *number, *CLass;
    if (argc == 4) {
        name = argv[1];
        number = argv[2];
        CLass = argv[3];
    } else {
        printf("%d no name, number, class!", argc);
        exit(-1);
    }
    printf("编制人: %s %s %s\n", name, number, CLass);
#endif
    init();
#if SUMOVER_DEBUG
    grammerPrint();
#endif
    printf("输入待解析的字符串.(以#结束)\n");
    {
        char c;
        do {
            c = getchar();
            if (c == ' ')continue;
            if (c == '\n')continue;
            parsedString += c;
        } while (c != '#');
    }
    cout << "待解析的字符串为\"" << parsedString << "\"" << endl;
    printf("start parsing....\n");
    if (parse() == -1) {
        printf("解析错误!\n");
    } else {
        printf("解析成功!");
        cout << "待解析字符串`" << parsedString << "`是符合文法的字符串" << endl;
    }
}

#if 0
i+i*i#
#endif