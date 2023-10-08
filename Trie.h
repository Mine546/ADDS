#ifndef TRIE_H
#define TRIE_H
#include <iostream>
#include <vector>
#include <unordered_map>

class TrieNode {
public:
    std::unordered_map<char, TrieNode*> children;
    bool isEndOfWord;
    TrieNode();
};

class Trie {
private:
    TrieNode* root;
public:
    Trie();
    void insert(const std::string& word);
    std::vector<std::string> getSuggestions(const std::string& partialWord);
private:
    void getAllWordsWithPrefix(TrieNode* node, std::string prefix, std::vector<std::string>& suggestions);
};

#endif
