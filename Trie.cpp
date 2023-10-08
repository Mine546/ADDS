// Trie.cpp
#include "Trie.h"

TrieNode::TrieNode() : isEndOfWord(false) {}

Trie::Trie() : root(new TrieNode()) {}

void Trie::insert(const std::string& word) {
    TrieNode* current = root;
    for (char c : word) {
        if (current->children.find(c) == current->children.end()) {
            current->children[c] = new TrieNode();
        }
        current = current->children[c];
    }
    current->isEndOfWord = true;
}

std::vector<std::string> Trie::getSuggestions(const std::string& partialWord) {
    TrieNode* current = root;
    for (char c : partialWord) {
        if (current->children.find(c) == current->children.end()) {
            return {};  // No suggestions if the prefix is not found
        }
        current = current->children[c];
    }
    std::vector<std::string> suggestions;
    getAllWordsWithPrefix(current, partialWord, suggestions);
    return suggestions;
}

void Trie::getAllWordsWithPrefix(TrieNode* node, std::string prefix, std::vector<std::string>& suggestions) {
    if (node->isEndOfWord) {
        suggestions.push_back(prefix);
    }

    for (auto& child : node->children) {
        getAllWordsWithPrefix(child.second, prefix + child.first, suggestions);
    }
}
