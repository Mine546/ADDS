#include "DocumentManager.h"

DocumentManager::DocumentManager() {
}


void DocumentManager::addDocument(std::string name, int id, int license_limit) {
    if (documents.find(id) != documents.end()) {
        return;
    }

    Document newDocument;
    newDocument.name = name;
    newDocument.license_limit = license_limit;

    documents[id] = newDocument;
}



void DocumentManager::addPatron(int patronID) {
    if (patrons.find(patronID) != patrons.end()) {
        return;
    }

    patrons.insert(patronID);

}




int DocumentManager::search(std::string name) {
    for (const auto& pair : documents) {
        const Document& doc = pair.second;
        if (doc.name == name) {
            return pair.first;
        }
    }

    return 0;
}



bool DocumentManager::borrowDocument(int docid, int patronID) {
    auto docIt = documents.find(docid);
    if (docIt == documents.end()) {
        return false;
    }

    if (patrons.find(patronID) == patrons.end()) {
        return false;
    }

    if (docIt->second.patrons.size() >= docIt->second.license_limit) {
        return false;
    }

    if (docIt->second.patrons.find(patronID) != docIt->second.patrons.end()) {
        return false;
    }

    docIt->second.patrons.insert(patronID);
    return true;
}



void DocumentManager::returnDocument(int docid, int patronID) {
    auto docIt = documents.find(docid);
    if (docIt == documents.end()) {
        return;
    }

    if (patrons.find(patronID) == patrons.end()) {
        return;
    }

    auto patronIt = docIt->second.patrons.find(patronID);
    if (patronIt == docIt->second.patrons.end()) {
        return;
    }

    docIt->second.patrons.erase(patronIt);
}
