#include <iostream>
#include <vector>
#include <unordered_map>
#ifndef TRIENODE_CPP
#define TRIENODE_CPP
using namespace std;
class TrieNode {
    private:
    void getAllWordsWithPrefix(TrieNode* node, string prefix, vector<string>& suggestions) {
        if (node->isEndOfWord) {
            suggestions.push_back(prefix);
        }

        for (auto& child : node->children) {
            getAllWordsWithPrefix(child.second, prefix + child.first, suggestions);
        }
    }


public:
    unordered_map<char, TrieNode*> children;
    bool isEndOfWord;

    TrieNode() : isEndOfWord(false) {}
};

#endif