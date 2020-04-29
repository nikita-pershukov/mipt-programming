#ifndef KMP_H
#define KMP_H

#include "!_All_include.h"

std::vector<int> PrefixFunction(const std::string &s) {
    int length = s.length();
    std::vector<int> tmp(length);
    tmp[0] = 0;
    for (int i = 1; i < length; ++i) {
        int j = tmp[i-1];
        while (j > 0 && s[i] != s[j])
            j = tmp[j-1];
        if (s[i] == s[j])
            ++j;
        tmp[i] = j;
    }
    return std::move(tmp);
}

std::vector<int> KMP(const std::string &s, const std::string &text) {
    int s_length = s.length();
    int text_length = text.length();
    std::vector<int> res;
    std::vector<int> pi = PrefixFunction(s + '#' + text);
    for (int i = 0; i < text_length; ++i)
        if (pi[s_length + i + 1] == s_length)
            res.push_back(i + 1 - s_length);
    return std::move(res);
}

#endif // KMP_H
