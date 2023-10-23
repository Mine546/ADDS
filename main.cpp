#include "DocumentManager.h"

int main() {
    DocumentManager documentManager;

    documentManager.addDocument("doc A", 1, 3);
    documentManager.addDocument("doc B", 2, 2);

    documentManager.addPatron(101);
    documentManager.addPatron(102);
    documentManager.addPatron(103);
    documentManager.addPatron(104);
    int docID = documentManager.search("doc A");
    if (docID > 0) {
        std::cout << "document ID: " << docID << std::endl;
    }

    bool borrowed = documentManager.borrowDocument(1, 101);
    if (borrowed) {
        std::cout << "borrowed." << std::endl;
    }

    borrowed = documentManager.borrowDocument(1, 102);
    if (!borrowed) {
        std::cout << "borrow limit reached, could not borrow" << std::endl;
    }

    borrowed = documentManager.borrowDocument(1, 103);
    borrowed = documentManager.borrowDocument(1, 104);
    documentManager.returnDocument(1, 101);

    return 0;
}
