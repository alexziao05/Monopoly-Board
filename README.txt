Project Title: Circular Singly Linked List - Monopoly Board
Author: Alex Huang

Overview:
This project implements:

    1. Insertion
        - At the beginning of the list
        - At the end of the list
        - At a specific position in the list
    2. Deletion
        - At the beginning of the list
        - At the end of the list
        - At a specific position in the list
    3. Search - searches the list to find if a particular node exists in the list
    4. Prints the list in the console
    5. Reverse the list, such that a->b->c becomes c->b->a using a stack
    6. Sorts the list with merge sort
    7. Merges two circular linked list
    8. Displays all nodes with a certain "Color" of space
    9. Update a Node's value

The data structure used to perform such operations is a Circular Singly Linked List.
This program is written in C++ and can be executed from CLion.

How to Run the Code:
Make sure CLion is installed. Libraries that were used in this program are iostream, stack, string, and cctype.

Operations:
1. Insert At Head
Description: inserts a node at the beginning
Best case: O(1)
Worst case: O(1)

2. Insert At Tail
Description: inserts a node at the end
Best case: O(1)
Worst case: O(N)

3. Insert At Position
Description: Given a position, algorithm checks to see if that position is legal. If so, a desired node will be inserted at that position.
Best case: O(1)
Worst case: O(N)

4. Delete At Head
Description: deletes the node at the very beginning
Best case: O(1)
Worst case: O(1)

5. Delete At Tail
Description: deletes the node at the very end
Best case: O(1)
Worst case: O(N)

6. Delete At Position
Description: deletes the node at a specific position
Best case: O(1)
Worst case: O(N)

7. Search
Description: search to see if a particular node exists
Best case: O(1)
Worst case: O(N)

8. Reverse Circular Linked List
Description: reverses the list from a->b->c to c->b->a
Best case: O(1)
Worst case: O(N)

9. Sort Circular Linked List
Description: arranges nodes lexicographically based on propertyName
Best case: O(NLogN)
Worst case: O(NLogN)

10. Print Head Node
Description: prints the first node
Best case: O(1)
Worst case: O(1)

11. Print Last Node
Description: prints the last node
Best case: O(1)
Worst case: O(N)

12. Is List Empty
Description: returns true if list is empty; otherwise, false
Best case: O(1)
Worst case: O(1)

13. Count Nodes
Description: returns the number of nodes in the list
Best case: O(1)
Worst case: O(N)

14. Convert Circular Linked List
Description: converts a circular linked list to a regular linked list, with `tail->next = nullptr`
Best case: O(1)
Worst case: O(N)

15. Update Node Value
Description: changes a specified node's data to something else
Best case: O(1)
Worst case: O(N)

16. Display Specific Node Value
Description: finds all node with a particular color and returns their properties
Best case: O(1)
Worst case: O(N)

17. Merge Circular Linked List
Description: merges two circular linked list into one circular linked list
Best case: O(1)
Worst case: O(N)