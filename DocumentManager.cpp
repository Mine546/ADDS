#include "DocumentManager.h"

DocumentManager::DocumentManager() {
    // Constructor, if needed.
}


void DocumentManager::addDocument(std::string name, int id, int license_limit) {
    // Check if the document already exists
    if (documents.find(id) != documents.end()) {
        return;
    }

    // Create a new Document object
    Document newDocument;
    newDocument.name = name;
    newDocument.license_limit = license_limit;

    // Add the document to the collection
    documents[id] = newDocument;
}



void DocumentManager::addPatron(int patronID) {
    // Check if the patron already exists
    if (patrons.find(patronID) != patrons.end()) {
        return;
    }

    // Add the patron to the collection
    patrons.insert(patronID);

}




int DocumentManager::search(std::string name) {
    for (const auto& pair : documents) {
        const Document& doc = pair.second;
        if (doc.name == name) {
            // Document with the specified name found, return its ID
            return pair.first;
        }
    }

    // Document not found
    return 0; // Return 0 to indicate that the document was not found.
}



bool DocumentManager::borrowDocument(int docid, int patronID) {
    // Check if the document exists
    auto docIt = documents.find(docid);
    if (docIt == documents.end()) {
        return false;
    }

    // Check if the patron exists
    if (patrons.find(patronID) == patrons.end()) {
        return false;
    }

    // Check if the document has reached its license limit
    if (docIt->second.patrons.size() >= docIt->second.license_limit) {
        return false;
    }

    // Check if the patron has already borrowed the document
    if (docIt->second.patrons.find(patronID) != docIt->second.patrons.end()) {
        return false;
    }

    // Allow the patron to borrow the document
    docIt->second.patrons.insert(patronID);
    return true;
}



void DocumentManager::returnDocument(int docid, int patronID) {
    // Check if the document exists
    auto docIt = documents.find(docid);
    if (docIt == documents.end()) {
        return;
    }

    // Check if the patron exists
    if (patrons.find(patronID) == patrons.end()) {
        return;
    }

    // Check if the patron has borrowed the document
    auto patronIt = docIt->second.patrons.find(patronID);
    if (patronIt == docIt->second.patrons.end()) {
        return;
    }

    // Allow the patron to return the document
    docIt->second.patrons.erase(patronIt);
}
