#ifndef DOCUMENT_MANAGER_H
#define DOCUMENT_MANAGER_H

#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>

class DocumentManager {
public:
    DocumentManager();

    void addDocument(std::string name, int id, int license_limit);
    void addPatron(int patronID);
    int search(std::string name);
    bool borrowDocument(int docid, int patronID);
    void returnDocument(int docid, int patronID);

private:
    struct Document {
        std::string name;
        int license_limit;
        std::unordered_set<int> patrons;
    };

    std::unordered_map<int, Document> documents;
    std::unordered_set<int> patrons;
};

#endif // DOCUMENT_MANAGER_H
