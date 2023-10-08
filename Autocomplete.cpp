// Autocomplete.cpp
#include "Autocomplete.h"

void Autocomplete::insert(const std::string& word) {
    trie.insert(word);
}

std::vector<std::string> Autocomplete::getSuggestions(const std::string& partialWord) {
    return trie.getSuggestions(partialWord);
}
