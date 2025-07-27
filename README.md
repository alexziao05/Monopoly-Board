# Monopoly Board - Circular Singly Linked List Implementation

A C++ implementation of a Monopoly board game using a circular singly linked list data structure. This project demonstrates various linked list operations in the context of a classic board game.

## 📋 Project Overview

This project implements a **Circular Singly Linked List** to represent a Monopoly board, where each property is a node in the list. The circular nature perfectly mimics the continuous loop of a Monopoly board where players move around indefinitely.

**Author:** Alex Huang  
**Language:** C++  
**Standard:** C++20  
**Build System:** CMake  

## 🎯 Features

- **Monopoly Board Representation**: Each property contains:
  - Property name
  - Property color
  - Purchase value
  - Rent amount

- **Circular Linked List Operations**:
  - Insert at head, tail, or specific position
  - Delete from head, tail, or specific position
  - Search for properties
  - Print the entire board
  - Reverse the board order
  - Sort properties
  - Merge multiple boards

## 🏗️ Project Structure

```
Monopoly-Board/
├── main.cpp              # Main implementation file
├── CMakeLists.txt         # CMake build configuration
├── README.md             # This file
├── README.txt            # Original project documentation
├── Monopoly Board Diagram.jpg  # Visual reference
└── cmake-build-debug/    # Build directory
```

## 🚀 Getting Started

### Prerequisites

- C++20 compatible compiler (GCC 10+, Clang 10+, or MSVC 2019+)
- CMake 3.29 or higher
- CLion IDE (recommended) or any C++ development environment

### Building the Project

#### Using CMake (Command Line)

```bash
# Clone or navigate to the project directory
cd /path/to/Monopoly-Board

# Create build directory
mkdir build && cd build

# Generate build files
cmake ..

# Build the project
make

# Run the executable
./untitled
```

#### Using CLion IDE

1. Open CLion
2. Choose "Open Project" and select the `Monopoly-Board` folder
3. CLion will automatically detect the CMakeLists.txt file
4. Build and run the project using the IDE controls

## 📊 Time Complexity Analysis

| Operation | Best Case | Worst Case | Description |
|-----------|-----------|------------|-------------|
| **Insert at Head** | O(1) | O(1) | Always constant time |
| **Insert at Tail** | O(1)* | O(N) | *With tail pointer |
| **Insert at Position** | O(1) | O(N) | Position 0 vs end of list |
| **Delete at Head** | O(1) | O(1) | Always constant time |
| **Delete at Tail** | O(1)* | O(N) | *With tail pointer |
| **Delete at Position** | O(1) | O(N) | Position 0 vs end of list |
| **Search** | O(1) | O(N) | Found at head vs not found |
| **Print List** | O(1) | O(N) | Single node vs full traversal |

## 🎲 Usage Example

The program creates a Monopoly board where each property is represented as a node in a circular linked list:

```cpp
// Create a property
MonopolyBoard property("Boardwalk", "Blue", 400, 50);

// Create circular linked list
CircularLinkedList<MonopolyBoard> board;

// Add properties to the board
board.insertAtTail(property);

// Navigate around the board
board.printList();
```

## 🏛️ Class Structure

### `MonopolyBoard` Class
- Stores property information (name, color, value, rent)
- Provides equality comparison and printing methods

### `Node<T>` Template Class
- Generic node structure for the linked list
- Contains data and pointer to next node

### `CircularLinkedList<T>` Template Class
- Implements all circular linked list operations
- Maintains circular structure with proper head management

## 🔄 Circular List Benefits

The circular nature of the linked list provides several advantages for a Monopoly board:

1. **Infinite Movement**: Players can move around the board continuously
2. **No End Points**: No special handling needed for board boundaries
3. **Natural Loop**: Represents the actual game mechanics accurately
4. **Efficient Traversal**: Easy to implement "Go" space mechanics

## 🛠️ Development Notes

- The project uses modern C++20 features
- Template classes provide type safety and reusability
- Memory management is handled through proper node allocation/deallocation
- The circular structure is maintained through careful pointer management

## 📝 Dependencies

- Standard C++ libraries:
  - `<iostream>` - Input/output operations
  - `<string>` - String handling
  - `<stack>` - Stack operations
  - `<cctype>` - Character classification
  - `<algorithm>` - Algorithmic operations

## 🤝 Contributing

This is an educational project demonstrating data structures and algorithms. Feel free to:
- Suggest improvements to the implementation
- Add new features or operations
- Optimize existing algorithms
- Enhance documentation

## 📜 License

This project is created for educational purposes. Please respect academic integrity guidelines if using this code for coursework.

---

*This implementation serves as a practical example of how classic data structures can be applied to real-world scenarios like board games.*
