#include <iostream>
#include <string>
#include <stack>
#include <cctype>
#include <algorithm>

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
        return (propertyName == other.propertyName && propertyColor == other.propertyColor && value == other.value &&
                rent == other.rent);
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

    Node(T data) {
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

        // Check if position is legal.
        if (position > numberOfNodes + 1 || position < 1) {
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

        Node<T> *tailNode = headNode;
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

        Node<T> *tailNode = headNode;
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
            return;
        } else if (position > numberOfNodes) {
            return;
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
        if (headNode == nullptr) {
            return false;
        }

        Node<T> *current = headNode;

        do {
            if (current->data.isEqual(value)) {
                cout << "Search: Found Element - PASSED" << endl;
                return true;
            }

            current = current->nextNode;
        } while (current != headNode);

        cout << "Search: Didn't Find Element - FAILED" << endl;
        return false;
    }

    void printList() {
        if (headNode == nullptr) {
            cout << "List is empty" << endl;
            return;
        }

        Node<T> *current = headNode;

        // Traverse the list to check if it is circular
        Node<T> *temp = headNode;
        bool isCircular = false;
        while (temp->nextNode != nullptr) {
            if (temp->nextNode == headNode) {
                isCircular = true;
                break;
            }
            temp = temp->nextNode;
        }

        if (isCircular) {
            do {
                current->data.print();
                cout << " -> ";
                current = current->nextNode;
            } while (current != headNode);
            cout << "(return to head)" << endl;
        } else {
            while (current != nullptr) {
                current->data.print();
                cout << " -> ";
                current = current->nextNode;
            }
            cout << "nullptr" << endl;
        }
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

        // Push all elements of the LinkedList into the stack starting from head
        // Popping it out effectively reverses the LinkedList

        stack<Node<T> *> stack;
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

    /* Start of Merge Sort Implementation */

    Node<T> *split(Node<T> *head) {
        Node<T> *fast = head;
        Node<T> *slow = head;

        while (fast != nullptr && fast->nextNode != nullptr) {
            // Condition to check if reached the end of the list
            fast = fast->nextNode->nextNode; // Moves twice as fast -- effectively splits list into two halves
            if (fast != nullptr) {
                // Has not reached the end of the list
                slow = slow->nextNode; // Room for slow to move forward
            }
        }

        Node<T> *temp = slow->nextNode; // Forms the head of the second list
        slow->nextNode = nullptr; // Terminates the first list
        return temp; // Returns the head of the second list
    }

    Node<T> *merge(Node<T> *nodeA, Node<T> *nodeB) {
        if (nodeA == nullptr) {
            return nodeB;
        }
        if (nodeB == nullptr) {
            return nodeA;
        }

        if (nodeA->data.propertyName < nodeB->data.propertyName) {
            nodeA->nextNode = merge(nodeA->nextNode, nodeB);
            return nodeA;
        } else {
            nodeB->nextNode = merge(nodeA, nodeB->nextNode);
            return nodeB;
        }
    }

    Node<T> *mergeSort(Node<T> *head) {
        if (head == nullptr || head->nextNode == nullptr) {
            return head;
        }

        Node<T> *second = split(head);
        head = mergeSort(head);
        second = mergeSort(second);

        return merge(head, second);
    }

    Node<T> *getTail(Node<T> *head) {
        if (head == nullptr) {
            return nullptr;
        }

        while (head->nextNode != nullptr) {
            head = head->nextNode;
        }

        return head;
    }

    /* End of Merge Sort Implementation */

    void sortCLList() {
        // Convert to a regular linkedList
        convertCLList();

        if (headNode == nullptr || headNode->nextNode == nullptr) {
            return;
        }

        headNode = mergeSort(headNode);

        // Change regular linkedList back to circular LinkedList
        Node<T> *tail = getTail(headNode);
        if (tail != nullptr) {
            tail->nextNode = headNode;
        }
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

    bool isListEmpty() {
        if (headNode == nullptr) {
            return true;
        } else {
            return false;
        }
    }

    int countNodes() {
        int counter = 0;

        if (headNode == nullptr) {
            return 0;
        }

        Node<T> *current = headNode;
        do {
            counter++;
            current = current->nextNode;
        } while (current != headNode);

        return counter;
    }

    //Optional Tasks
    // Level2
    void convertCLList() {
        // Traverse to the end, find last node, and point it towards nullptr
        if (headNode == nullptr) {
            return;
        }

        Node<T> *tailNode = headNode;
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
            if (current->data.isEqual(oldValue)) {
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
        // convert color to lowercase
        transform(color.begin(), color.end(), color.begin(), ::tolower);

        if (headNode == nullptr) {
            return;
        }

        Node<T> *current = headNode;

        do {
            string colorNode = current->data.propertyColor;
            // convert node's color data to lowercase
            transform(colorNode.begin(), colorNode.end(), colorNode.begin(), ::tolower);

            if (colorNode == color) {
                cout << "Color " << color << ": " << current->data.propertyName << ", " << current->data.value << ", "
                        << current->data.rent << endl;
            }

            current = current->nextNode;
        } while (current != headNode);
    }

    Node<T> *getHeadNode() {
        return headNode;
    }

    Node<T> *getTailNode() {
        Node<T> *current = headNode;
        while (current->nextNode != headNode) {
            current = current->nextNode;
        }
        return current;
    }

    void mergeCLList(CircularLinkedList otherList) {
        Node<T> *thisHeadNode = this->headNode;
        Node<T> *otherHeadNode = otherList.headNode;

        // Check if any list is empty

        if (thisHeadNode == nullptr) {
            this->headNode = otherHeadNode;
            return;
        }

        if (otherHeadNode == nullptr) {
            return;
        }

        Node<T> *thisTailNode = thisHeadNode;
        Node<T> *otherTailNode = otherHeadNode;

        // Point the tail to the other's list head
        // Point other's list tail to head

        while (thisTailNode->nextNode != thisHeadNode) {
            thisTailNode = thisTailNode->nextNode;
        }

        while (otherTailNode->nextNode != otherHeadNode) {
            otherTailNode = otherTailNode->nextNode;
        }

        otherTailNode->nextNode = thisHeadNode;
        thisTailNode->nextNode = otherHeadNode;
    }
};

void runProgram() {

    CircularLinkedList<MonopolyBoard> banks;
    MonopolyBoard BankOfAmerica = MonopolyBoard("BankOfAmerica", "Blue", 1, 500);
    MonopolyBoard ChaseBank = MonopolyBoard("ChaseBank", "Yellow", 2, 1000);
    MonopolyBoard WellsFargo = MonopolyBoard("WellsFargo", "Red", 3, 1500);
    MonopolyBoard Citibank = MonopolyBoard("Citibank", "Green", 4, 2000);
    MonopolyBoard GoldmanSachs = MonopolyBoard("GoldmanSachs", "Orange", 5, 2500);
    MonopolyBoard HSBC = MonopolyBoard("HSBC", "Purple", 6, 3000);
    MonopolyBoard PNC = MonopolyBoard("PNC", "Brown", 7, 3500);
    MonopolyBoard TD = MonopolyBoard("TD", "LightBlue", 8, 4000);

    cout << "Insert BankOfAmerica at Head: " << endl;
    banks.insertAtHead(BankOfAmerica);
    banks.printList();

    cout << "\nInsert ChaseBank, WellsFargo, Citibank, HSBC, PNC, and TD at Tail" << endl;
    banks.insertAtTail(ChaseBank);
    banks.insertAtTail(WellsFargo);
    banks.insertAtTail(Citibank);
    banks.insertAtTail(HSBC);
    banks.insertAtTail(PNC);
    banks.insertAtTail(TD);
    banks.printList();

    cout << "\nInsert GoldmanSachs at Position 4: " << endl;
    banks.insertAtPosition(GoldmanSachs, 4);
    banks.printList();

    cout << "\nDelete BankOfAmerica from Head: " << endl;
    banks.deleteAtHead();
    banks.printList();

    cout << "\nDelete TD from Tail: " << endl;
    banks.deleteAtTail();
    banks.printList();

    cout << "\nDelete Wells Fargo From Position 2: " << endl;
    banks.deleteAtPosition(2);
    banks.printList();

    //Optional Level 1 Tasks
    cout << "\nReverse List: " << endl;
    banks.reverseCLList();
    banks.printList();

    cout << "\nSort List: " << endl;
    banks.sortCLList();
    banks.printList();

    cout << "\n";
    banks.printHeadNode();

    cout << "\n";
    banks.printLastNode();

    cout << "\n";
    if (banks.isListEmpty()) {
        cout << "List is empty." << endl;
    } else {
        cout << "List is not empty." << endl;
    }

    cout << "\n";
    banks.printList();
    cout << "Total Nodes: " << banks.countNodes() << endl;

    //Optional Level 2 Tasks
    cout << "\nUpdate ChaseBank with BankOfAmerica: " << endl;
    banks.updateNodeValue(ChaseBank, BankOfAmerica);
    banks.printList();

    cout << "\nDisplay banks with color orange: " << endl;
    banks.displaySpecificColorNode("orange");
    banks.printList();

    CircularLinkedList<MonopolyBoard> cards;
    MonopolyBoard creditCard = MonopolyBoard("CreditCard", "Yellow", 1, 500);
    MonopolyBoard debitCard = MonopolyBoard("DebitCard", "Yellow", 2, 500);
    cards.insertAtHead(creditCard);
    cards.insertAtTail(debitCard);

    cout << "\nMerge list of banks with list of cards: " << endl;
    banks.mergeCLList(cards);
    banks.printList();

    cout << "\nConvert List: " << endl;
    banks.convertCLList();
    banks.printList();
}

// Main function to demonstrate the LinkedList class
int main() {
    runProgram();
    return 0;
}
