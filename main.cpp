#include <iostream>
#include <string>
#include <stack>
using namespace std;

// Data class to store a string and an integer
class MonopolyBoard {
public:
    string propertyName;
    string propertyColor;
    int value;
    int rent;

    MonopolyBoard() {
        propertyName = "";
        propertyColor = "";
        value = 0;
        rent = 0;
    }

    MonopolyBoard(string propertyName, string propertyColor, int value, int rent) {
        /*Define overloaded constructor here*/
        this->propertyName = propertyName;
        this->propertyColor = propertyColor;
        this->value = value;
        this->rent = rent;
    }

    bool isEqual(MonopolyBoard other) {
        /*Define is equal here*/
        return (propertyName == other.propertyName && propertyColor == other.propertyColor && value == other.value && rent == other.rent);
    }

    void print() {
        /*Define Print Here*/
        cout << "(" << propertyName << ", " << propertyColor << ", " << value << ", " << rent << ")";
    }
};

// Template Node class
template<typename T>
class Node {
public:
    T data;
    Node *nextNode;

    Node (T data) {
        this->data = data;
        nextNode = nullptr;
    }
};

// Template LinkedList class
template<typename T>
class CircularLinkedList {
private:
    Node<T> *headNode;

public:
    CircularLinkedList() {
        headNode = nullptr;
    }

    // Core Tasks
    void insertAtHead(T data) {
        insertNodeAtHead(new Node<T>(data));
    }

    void insertNodeAtHead(Node<T> *newNode) {
        if (headNode == nullptr) {
            headNode = newNode;
            newNode->nextNode = headNode;
        } else {
            Node<T> *current = headNode;
            while (current->nextNode != headNode) {
                current = current->nextNode;
            }
            current->nextNode = newNode;
            newNode->nextNode = headNode;
            headNode = newNode;
        }
    }

    void insertAtTail(T data) {
        insertNodeAtTail(new Node<T>(data));
    }

    void insertNodeAtTail(Node<T> *newNode) {
        if (headNode == nullptr) {
            headNode = newNode;
            newNode->nextNode = headNode;
        } else {
            Node<T> *current = headNode;
            while (current->nextNode != headNode) {
                current = current->nextNode;
            }
            current->nextNode = newNode;
            newNode->nextNode = headNode;
        }
    }

    void insertAtPosition(T data, int position) {
        insertNodeAtPosition(new Node<T>(data), position);
    }

    void insertNodeAtPosition(Node<T> *newNode, int position) {
        int numberOfNodes = countNodes();

        if (position > numberOfNodes + 1 || position < 1) {
            cout << "Position out of bounds" << endl;
            return;
        }

        if (position == 1) {
            insertNodeAtHead(newNode);
        } else if (position == numberOfNodes + 1) {
            insertNodeAtTail(newNode);
        } else {
            int counter = 1;
            Node<T> *prevNode = headNode;
            while (counter < position - 1) {
                prevNode = prevNode->nextNode;
                counter++;
            }

            Node<T> *nextNode = prevNode->nextNode;
            newNode->nextNode = nextNode;
            prevNode->nextNode = newNode;
        }

    }

    void deleteAtHead() {
        if (headNode == nullptr) {
            return;
        }

        if (headNode->nextNode == headNode) {
            delete headNode;
            headNode = nullptr;
            return;
        }

        Node <T> *tailNode = headNode;
        while (tailNode->nextNode != headNode) {
            tailNode = tailNode->nextNode;
        }

        Node<T> *toDelete = headNode;
        headNode = headNode->nextNode;
        delete toDelete;
        tailNode->nextNode = headNode;
    }

    void deleteAtTail() {
        if (headNode == nullptr) {
            return;
        }

        if (headNode->nextNode == headNode) {
            delete headNode;
            headNode = nullptr;
            return;
        }

        Node <T> *tailNode = headNode;
        while (tailNode->nextNode->nextNode != headNode) {
            tailNode = tailNode->nextNode;
        }

        Node<T> *toDelete = tailNode->nextNode;
        tailNode->nextNode = headNode;
        delete toDelete;
    }

    void deleteAtPosition(int position) {
        int numberOfNodes = countNodes();

        if (numberOfNodes == 0) {
            cout << "List is empty, there is nothing to delete" << endl;
        } else if (position > numberOfNodes) {
            cout << "Position out of bounds" << endl;
        } else if (position == 1) {
            deleteAtHead();
        } else if (position == numberOfNodes) {
            deleteAtTail();
        } else {
            int counter = 1;
            Node<T> *prevNode = headNode;
            while (counter < position - 1) {
                prevNode = prevNode->nextNode;
                counter++;
            }
            Node<T> *succNode = prevNode->nextNode->nextNode;
            Node<T> *toDelete = prevNode->nextNode;
            prevNode->nextNode = succNode;
            delete toDelete;
        }


    }

    void search(T value) {
        cout << "Search unwritten" << endl;
    }

    void printList() {
        if (headNode == nullptr) {
            cout << "List is empty" << endl;
            return;
        }

        Node<T> *current = headNode;
        do {
            current->data.print();
            cout << " -> ";
            current = current->nextNode;
        } while (current != headNode);

        cout << "(return to head)" << endl;
    }

    //Optional Tasks
    //Level 1
    void reverseCLList() {
        if (headNode == nullptr || headNode->nextNode == headNode) {
            return;
        }

        Node<T> *tailNode = headNode;
        while (tailNode->nextNode != headNode) {
            tailNode = tailNode->nextNode;
        }
        tailNode->nextNode = nullptr;

        stack <Node<T>*> stack;
        Node<T> *currNode = headNode;

        while (currNode != nullptr) {
            stack.push(currNode);
            currNode = currNode->nextNode;
        }

        headNode = stack.top();
        stack.pop();
        Node<T> *prevNode = headNode;

        while (!stack.empty()) {
            prevNode->nextNode = stack.top();
            prevNode = prevNode->nextNode;
            stack.pop();
        }

        prevNode->nextNode = headNode;
    }

    void sortCLList() {
        cout << "Sort List unwritten" << endl;
    }

    void printHeadNode() {
        cout << "Printing head node: ";
        headNode->data.print();
        cout << endl;
    }

    void printLastNode() {
        Node<T> *current = headNode;
        do {
            current = current->nextNode;
        } while (current->nextNode != headNode);
        cout << "Printing last node: ";
        current->data.print();
        cout << endl;
    }

    void isListEmpty() {
        if (headNode == nullptr) {
            cout << "List is empty" << endl;
        } else {
            cout << "List is not empty" << endl;
        }
    }

    int countNodes() {
        int counter = 1;

        if (headNode == nullptr) {
            cout << "Count nodes: 0" << endl;
            return 0;
        }

        Node<T> *current = headNode;
        do {
            counter++;
            current = current->nextNode;
        } while (current->nextNode != headNode);

        cout << "Count nodes: " << counter << endl;

        return counter;
    }

    //Optional Tasks
    // Level2
    void convertCLList() {
        cout << "Convert Circular List Unwritten." << endl;
    }

    void updateNodeValue() {
        cout << "update Node value unwritten" << endl;
    }

    void displaySpecificColorNode() {
        cout << "Display Specific color Node" << endl;
    }

    void mergeCLList() {
        cout << "Merge Circular Linked List Unwritten" << endl;
    }
};

// Main function to demonstrate the LinkedList class
int main() {
    // Create a LinkedList of Data objects
    CircularLinkedList<MonopolyBoard> list;
    // Insert elements at the end
    list.insertAtHead(MonopolyBoard("Chase", "Blue", 1, 500));
    list.insertAtTail(MonopolyBoard("SoFi", "Yellow", 2, 1000));
    list.insertAtTail(MonopolyBoard("Wells Fargo", "Red", 3, 750));
    list.insertAtPosition(MonopolyBoard("Bank Of America", "Purple", 4, 1500), 3);
    //list.deleteAtHead();
    //list.deleteAtTail();
    list.deleteAtPosition(2);
    //Optional Level 1 Tasks
    //list.reverseCLList();
    list.sortCLList();
    list.printHeadNode();
    list.printLastNode();
    list.isListEmpty();
    list.countNodes();
    //Optional Level 2 Tasks
    list.convertCLList();
    list.updateNodeValue();
    list.displaySpecificColorNode();
    list.mergeCLList();
    list.printList();
    return 0;
}
