#ifndef ahoCorasick_H
#define ahoCorasick_H

#include "!_All_include.h"
#include "ahocorasicknode.h"

class ahoCorasick {
private:
    typedef std::pair<int, std::string> ahoCorasickElement;
    class ahoCorasick_comp {
    public:
        bool operator()(ahoCorasickElement a, ahoCorasickElement b) {
            return a.first < b.first;
        }
    };
public:
    ahoCorasick();
    void AddString(const std::string& s);
    int Go(int v, char c);
    int GetLink(int v);
    std::vector<std::pair<std::string, std::set<int> > > CountEntry (const std::string& s);
private:
    int _size;
    std::vector<ahoCorasickNode> _states;
};

#include "ahocorasick.h.impl"

#endif // ahoCorasick_H
