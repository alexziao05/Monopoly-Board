#include <iostream>
#include <string>
#include <stack>
#include <cctype>
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

    bool search(T value) {
        Node<T> *current = headNode;
        do {
            if (current->data.isEqual(value)) {
                cout << "Found element" <<  endl;
                return true;
            }
            current = current->nextNode;
        } while (current != headNode);

        cout << "No such element" << endl;
        return false;
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
        if (headNode == nullptr) {
            return;
        }

        Node <T> *tailNode = headNode;
        while (tailNode->nextNode != headNode) {
            tailNode = tailNode->nextNode;
        }

        tailNode->nextNode = nullptr;
    }

    void updateNodeValue(T oldValue, T newValue) {
        if (headNode == nullptr) {
            cout << "List is empty" << endl;
            return;
        }

        int counter = 1;
        Node<T> *current = headNode;
        do {
            if(current->data.isEqual(oldValue)) {
                deleteAtPosition(counter);
                insertAtPosition(newValue, counter);
                return;
            }
            current = current->nextNode;
            counter++;
        } while (current != headNode);

        cout << "Node doesn't exist" << endl;
    }

    void displaySpecificColorNode(string color) {

        transform(color.begin(), color.end(), color.begin(), ::tolower);

        if (headNode == nullptr) {
            return;
        }

        Node<T> *current = headNode;

        do {

            string colorNode = current->data.propertyColor;
            transform(colorNode.begin(), colorNode.end(), colorNode.begin(), ::tolower);

            if (colorNode == color) {
                cout << "Color " << color << ": " << current->data.propertyName << ", " << current->data.value << ", " << current->data.rent << endl;
            }

            current = current->nextNode;

        }  while (current != headNode);
    }

    Node<T>* getHeadNode() {
        return headNode;
    }

    void mergeCLList(CircularLinkedList otherList) {
        Node<T> *thisHeadNode = this->headNode;
        Node<T> *otherHeadNode = otherList.headNode;

        if (thisHeadNode == nullptr) {
            this->headNode = otherHeadNode;
            return;
        }

        if (otherHeadNode == nullptr) {
            return;
        }

        Node<T> *thisTailNode = thisHeadNode;
        Node<T> *otherTailNode = otherHeadNode;

        while(thisTailNode->nextNode != thisHeadNode) {
            thisTailNode = thisTailNode->nextNode;
        }

        while(otherTailNode->nextNode != otherHeadNode) {
            otherTailNode = otherTailNode->nextNode;
        }

        otherTailNode -> nextNode = thisHeadNode;
        thisTailNode -> nextNode = otherHeadNode;
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
    //list.deleteAtPosition(2);
    // list.search(MonopolyBoard("Chase", "Blue", 1, 500));
    //Optional Level 1 Tasks
    // list.reverseCLList();
    list.sortCLList();
    // list.printHeadNode();
    // list.printLastNode();
    // list.isListEmpty();
    // list.countNodes();
    //Optional Level 2 Tasks
    //list.convertCLList();
    //list.updateNodeValue(MonopolyBoard("Chase", "Blue", 1, 500), MonopolyBoard("Chase", "Blue", 1, 10000));
    //list.displaySpecificColorNode("blue");

    /* New Circular List */
    CircularLinkedList<MonopolyBoard> list2;
    list2.insertAtHead(MonopolyBoard("Debit", "Card", 1, 5000));
    list2.insertAtTail(MonopolyBoard("Credit", "Card", 2, 1000));
    /* End of New Circular List */

    list.mergeCLList(list2);
    list.printList();
    return 0;
}
