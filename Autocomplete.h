#ifndef AUTOCOMPLETE_H
#define AUTOCOMPLETE_H
#include "Trie.h"
class Autocomplete {
private:
    Trie trie;
public:
    void insert(const std::string& word);
    std::vector<std::string> getSuggestions(const std::string& partialWord);
};

#endif
