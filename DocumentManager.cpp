#include "DocumentManager.h"

DocumentManager::DocumentManager() {
    // Constructor, if needed.
}


void DocumentManager::addDocument(std::string name, int id, int license_limit) {
    // Check if the document already exists
    if (documents.find(id) != documents.end()) {
        std::cout << "document with ID " << id << " exists, can not duplicate" << std::endl;
        return;
    }

    // Create a new Document object
    Document newDocument;
    newDocument.name = name;
    newDocument.license_limit = license_limit;

    // Add the document to the collection
    documents[id] = newDocument;

    std::cout << "document with ID " << id << " added" << std::endl;
}



void DocumentManager::addPatron(int patronID) {
    // Check if the patron already exists
    if (patrons.find(patronID) != patrons.end()) {
        std::cout << "patron with ID " << patronID << " exists, can not duplicate" << std::endl;
        return;
    }

    // Add the patron to the collection
    patrons.insert(patronID);

    std::cout << "patron with ID " << patronID << " added" << std::endl;
}




int DocumentManager::search(std::string name) {
    for (const auto& pair : documents) {
        const Document& doc = pair.second;
        if (doc.name == name) {
            // Document with the specified name found, return its ID
            std::cout << "document with name '" << name << "' found with ID " << pair.first << "." << std::endl;
            return pair.first;
        }
    }

    // Document not found
    std::cout << "document with name '" << name << "' not found." << std::endl;
    return 0; // Return 0 to indicate that the document was not found.
}



bool DocumentManager::borrowDocument(int docid, int patronID) {
    // Check if the document exists
    auto docIt = documents.find(docid);
    if (docIt == documents.end()) {
        std::cout << "document with ID " << docid << " doesn't exist" << std::endl;
        return false;
    }

    // Check if the patron exists
    if (patrons.find(patronID) == patrons.end()) {
        std::cout << "patron with ID " << patronID << " doesn't" << std::endl;
        return false;
    }

    // Check if the document has reached its license limit
    if (docIt->second.patrons.size() >= docIt->second.license_limit) {
        std::cout << "document with ID " << docid << " borrow limit reached, could not borrow" << std::endl;
        return false;
    }

    // Check if the patron has already borrowed the document
    if (docIt->second.patrons.find(patronID) != docIt->second.patrons.end()) {
        std::cout << "patron with ID " << patronID << " has already borrowed document with ID " << docid << ", borrow failed" << std::endl;
        return false;
    }

    // Allow the patron to borrow the document
    docIt->second.patrons.insert(patronID);
    std::cout << "patron with ID " << patronID << " successfully borrowed document with ID " << docid << std::endl;
    return true;
}



void DocumentManager::returnDocument(int docid, int patronID) {
    // Check if the document exists
    auto docIt = documents.find(docid);
    if (docIt == documents.end()) {
        std::cout << "document with ID " << docid << " does not exist, return failed" << std::endl;
        return;
    }

    // Check if the patron exists
    if (patrons.find(patronID) == patrons.end()) {
        std::cout << "patron with ID " << patronID << " does not exist, return failed." << std::endl;
        return;
    }

    // Check if the patron has borrowed the document
    auto patronIt = docIt->second.patrons.find(patronID);
    if (patronIt == docIt->second.patrons.end()) {
        std::cout << "patron with ID " << patronID << " has not borrowed document with ID " << docid << ", return failed" << std::endl;
        return;
    }

    // Allow the patron to return the document
    docIt->second.patrons.erase(patronIt);
    std::cout << "patron with ID " << patronID << " successfully returned document with ID " << docid << std::endl;
}
