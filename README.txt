Project Title: Circular Singly Linked List: Monopoly Board Implementation
Author: Alex Huang

Overview:
This project implements several operations on a circular singly linked list, such as insertion, deletion, search, reversal, sorting, and merging. Each operation has varying time complexities depending on the case (best or worst).

Language: C++
IDE: CLion

How to Run the Program in CLion:
1. Install CLion.
2. Open CLion and create a new C++ project.
3. Include the libraries <iostream>, <stack>, <string>, <algorithm>, and <cctype>.
4. Build and run the project.

Time Complexities of Operations (Best and Worst Case):

Insert At Head
Best case: O(1)
Explanation: Only requires updating the head pointer and the new node’s next to the current head. This takes constant time, regardless of the list size.
Worst case: O(1)
Explanation: No matter the list size, insertion at the head always takes constant time.

Insert At Tail
Best case: O(1)
Explanation: If the list maintains a tail pointer, you can directly insert the node at the end without traversal, taking constant time.
Worst case: O(N)
Explanation: If there is no tail pointer, you need to traverse the list to find the last node, which takes O(N) in the worst case, where N is the number of nodes.

Insert At Position
Best case: O(1)
Explanation: If the position is the head (position 0), it’s equivalent to inserting at the head, which takes constant time.
Worst case: O(N)
Explanation: In the worst case, you have to traverse the entire list to insert at the last position or close to the end, which takes O(N).

Delete At Head
Best case: O(1)
Explanation: Deleting the head node only requires updating the head pointer, which is done in constant time.
Worst case: O(1)
Explanation: As with the best case, deleting the head node is always O(1) since no traversal is required.

Delete At Tail
Best case: O(1)
Explanation: If a tail pointer is maintained, the deletion can be done in constant time by updating the tail pointer.
Worst case: O(N)
Explanation: Without a tail pointer, you need to traverse the list to update the second-to-last node's next pointer, which takes O(N).

Delete At Position
Best case: O(1)
Explanation: Deleting at position 0 (the head) is the best case, which is constant time.
Worst case: O(N)
Explanation: In the worst case, you have to traverse to the last position or near the end to perform the deletion, which takes O(N).

Search
Best case: O(1)
Explanation: If the node being searched for is at the head, the search completes in constant time.
Worst case: O(N)
Explanation: In the worst case, the node is at the last position or not present at all, requiring traversal of the entire list, which takes O(N).

Print List
Best case: O(1)
Explanation: In the best case, the list has only one node.
Worst case: O(N)
Explanation: The worst case is that you need to traverse the entire list to print each node's value. In a circular list, you typically continue traversing until you return to the starting node, which again takes O(N) time.