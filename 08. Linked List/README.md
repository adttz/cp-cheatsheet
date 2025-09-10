# Linked List

## Table of Contents
1. [Singly Linked List](#1-singly-linked-list)
    - [Structure](#structure)
    - [Common Operations](#common-operations)
        - [Floyd's Tortoise and Hare](#cycle-detection-floyds-tortoise--hare)
2. [Doubly Linked List](#2-doubly-linked-list)
    - [Structure](#dll-structure)
    - [Common Operations](#dll-common-operations)
3. [Circular Linked List](#circular-linked-list)
4. [Reversal Techniques](#reversal-techniques)


## 1. Singly Linked List
### Structure
```cpp
struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};
```


### Common Operations

#### Traversal
```cpp
// Iterative 
void printList(Node* head) {
    for (Node* cur = head; cur; cur = cur->next)
        cout << cur->data << " ";
    cout << "\n";
}

// Recursive 
void printListRec(Node* head) {
    if (!head) return;
    cout << head->data << " ";
    printListRec(head->next);
}
```

#### Create Linked List from array
```cpp
Node* createList(const vector<int>& arr) {
    Node* head = new Node(arr[0]); 
    Node* prev = head;           
    for (int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i]);
        prev->next = temp;   
        prev = temp;         
    }
    return head;
}
```

#### Find Middle Node (Slow/Fast Pointers)
```cpp
Node* middleNode(Node* head) {
    Node *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
```

#### Cycle Detection (Floyd’s Tortoise & Hare)
```cpp
bool hasCycle(Node* head) {
    Node *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}
```

#### Iterative Reversal
```cpp
Node* reverse(Node* head) {
    Node *prev = nullptr, *cur = head;
    while (cur) {
        Node* nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    return prev;
}
```

#### Recursive Reversal 
```cpp
Node* reverseRec(Node* head) {
    if (!head || !head->next) return head;
    Node* rest = reverseRec(head->next);
    head->next->next = head;
    head->next = nullptr;
    return rest;
}
```

#### Sorting in a data structure
```cpp
struct cmp{
    bool operator()(Node* a, Node* b) {
        return a->val > b->val;  // Min-heap
    }
};
priority_queue<Node*, vector<Node*>, cmp> pq;
```

#### Palindrome Check
```cpp
bool isPalindrome(Node* head) {
    if (!head || !head->next) return true;
    Node *slow = head, *fast = head;
    while (fast && fast->next) { // Find middle
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* second = reverse(slow);
    Node* first = head;
    while (second) {
        if (first->data != second->data) return false;
        first = first->next;
        second = second->next;
    }
    return true;
}
```

## 2. Doubly Linked List

### DLL Structure

```cpp
struct Node {
    int data;
    Node *prev, *next;
    Node(int x) : data(x), prev(nullptr), next(nullptr) {}
};
```

### DLL Common Operations

#### Insert at Head
```cpp
Node* insertHead(Node* head, int val) {
    Node* node = new Node(val);
    node->next = head;
    if (head) head->prev = node;
    return node;
}
```

#### Delete Node
```cpp
void deleteNode(Node*& head, Node* del) {
    if (!del) return;
    if (del->prev) del->prev->next = del->next;
    else head = del->next;
    if (del->next) del->next->prev = del->prev;
    delete del;
}
```

#### Traversal 
```cpp
void printForward(Node* head) {
    for (Node* cur = head; cur; cur = cur->next)
        cout << cur->data << " ";
    cout << "\n";
}
void printBackward(Node* tail) {
    for (Node* cur = tail; cur; cur = cur->prev)
        cout << cur->data << " ";
    cout << "\n";
}
```

### Reversal 

```cpp
Node* reverseDLL(Node* head) {
    Node* cur = head;
    Node* temp = nullptr;
    while (cur) {
        temp = cur->prev;
        cur->prev = cur->next;
        cur->next = temp;
        cur = cur->prev;
    }
    return temp ? temp->prev : nullptr;
}
```
