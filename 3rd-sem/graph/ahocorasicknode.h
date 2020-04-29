#ifndef AHOCORASICKNODE_H
#define AHOCORASICKNODE_H

#include "!_All_include.h"

class ahoCorasickNode
{
public:
    ahoCorasickNode();
    bool GetLeaf();
    int GetParent();
    char GetParentChar();
    int GetLink();
    int GetLeng();
    std::string GetWord();
    std::map<char, int>& Next();
    std::map<char, int>& Go();
    void SetLeaf(const bool leaf);
    void SetParent(const int p);
    void SetParentChar(const char pch);
    void SetLink(const int link);
    void SetLeng(const int leng);
    void SetWord(const std::string word);
private:
    bool _leaf = false;
    int _p = -1;
    char _pch;
    int _link = -1;
    int _leng = -1;
    std::string _word;
    std::map<char, int> _next;
    std::map<char, int> _go;
};

#include "ahocorasicknode.h.impl"

#endif // AHOCORASICKNODE_H
