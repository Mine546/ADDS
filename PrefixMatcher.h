#ifndef PREFIXMATCHER_H
#define PREFIXMATCHER_H
#include "Trie.h"
class PrefixMatcher {
private:
    Trie trie;
public:
    void insert(const std::string& address, int routerNumber);
    int selectRouter(const std::string& networkAddress);
};

#endif
