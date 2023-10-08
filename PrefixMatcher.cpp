// PrefixMatcher.cpp
#include "PrefixMatcher.h"

void PrefixMatcher::insert(const std::string& address, int routerNumber) {
    trie.insert(address + std::to_string(routerNumber));
}

int PrefixMatcher::selectRouter(const std::string& networkAddress) {
    std::vector<std::string> suggestions = trie.getSuggestions(networkAddress);
    int longestMatchingPrefix = 0;
    int selectedRouter = -1;

    for (const std::string& suggestion : suggestions) {
        // Extract the router number from the suggestion
        int routerNumber = std::stoi(suggestion.substr(networkAddress.size()));
        if (routerNumber > longestMatchingPrefix) {
            longestMatchingPrefix = routerNumber;
            selectedRouter = routerNumber;
        }
    }

    return selectedRouter;
}
