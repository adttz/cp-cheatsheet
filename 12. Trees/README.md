# Trees

## Table Of Contents
1. [Binary Trees](#1-binary-trees)
    - [Structure](#structure)
    - [Traversals](#traversals)
    - [Common Operations](#common-operations)
2. [Binary Search Tree](#2-binary-search-tree)
    - [Common Operations](#common-operations)
    - [Lowest Common Ancestor](#lowest-common-ancestor)
## 1. Binary Trees

### Structure

```cpp
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


// Usage
int main(){
    TreeNode* root = new TreeNode(1);          // root
    root->left = new TreeNode(2);              // left child
    root->right = new TreeNode(3);             // right child
    root->left->left = new TreeNode(4);        // left-left grandchild
}
```
### Traversals

#### Preorder
DFSish, starting from root node
```cpp
void preorder(TreeNode* root) {
    if (!root) return;
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}
```

#### Inorder
- Basically goes from left to right in the tree, giving priority to nodes further from root node
- Gives sorted order in BST
```cpp
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}
```

#### Post-order
Reverse DFSish, starts from leaves
```cpp
void postorder(TreeNode* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}
```

#### Level order

```cpp
void levelOrder(TreeNode* root) {
    if (!root) return;
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* node = q.front(); q.pop();
        cout << node->val << " ";
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }
}

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    if(!root) return ans;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        int sz = q.size();
        vector<int> cur;
        for(int i = 0; i < sz; i++){
            TreeNode* node = q.front(); q.pop();
            cur.push_back(node->val);
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        ans.push_back(cur);
    }
    return ans;
}   
```

### Common Operations
#### Basics
```cpp
// Invert tree
TreeNode* invertTree(TreeNode* root) {
    if (!root) return root;         
    swap(root->left, root->right);
    invertTree(root->left);
    invertTree(root->right);
    return root;
}

// Maximum depth/height
int maxDepth(TreeNode* root) {
    if (!root) return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}
```

#### Tree Matching
```cpp
// Check if two trees are identical
bool isSameTree(TreeNode* p, TreeNode* q) {
    if (!p && !q) return true;
    if (!p || !q) return false;
    return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}


// Check if one tree is subtree of another
bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    if (!root) return false;
    return isSameTree(root, subRoot) || isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}


// Check if tree is symmetric (mirror)
bool isSymmetric(TreeNode* root) {
    if (!root) return true;
    return isMirror(root->left, root->right);
}

bool isMirror(TreeNode* left, TreeNode* right) {
    if (!left && !right) return true;
    if (!left || !right) return false;
    return left->val == right->val && isMirror(left->left, right->right) && isMirror(left->right, right->left);
}
```

#### Check if tree is height-balanced (AVL property)
```cpp
bool isBalanced(TreeNode* root) {
    return checkBalance(root) != -1;
}

int checkBalance(TreeNode* root) {
    if (!root) return 0;
    int left = checkBalance(root->left);
    if (left == -1) return -1;

    int right = checkBalance(root->right);
    if (right == -1) return -1;

    if (abs(left - right) > 1) return -1;
    return 1 + max(left, right);
}

```

#### Diameter of binary tree (longest path between any two nodes)
```cpp
int diameterOfBinaryTree(TreeNode* root) {
    int diameter = 0;
    calculateHeight(root, diameter);
    return diameter;
}

int calculateHeight(TreeNode* node, int& diameter) {
    if (!node) return 0;
    int leftHeight = calculateHeight(node->left, diameter);
    int rightHeight = calculateHeight(node->right, diameter);

    int curr_diameter = leftHeight + rightHeight;
    diameter = max(diameter, curr_diameter);
    return 1 + max(leftHeight, rightHeight);
}
```

## 2. Binary Search Tree

#### Properties
Binary Tree where for every node:
- All values in the left subtree are less than the node’s value
- All values in the right subtree are greater

### Common Operations

#### Search
```cpp
// Search for a value
TreeNode* search(TreeNode* root, int val) {
    if (!root || root->val == val) return root;
    if (val < root->val) return search(root->left, val);
    return search(root->right, val);
}

// Iterative search (more efficient)
TreeNode* searchIterative(TreeNode* root, int val) {
    while (root && root->val != val) {
        root = (val < root->val) ? root->left : root->right;
    }
    return root;
}

// Find minimum value node (leftmost)
TreeNode* findMin(TreeNode* root) {
    if (!root) return nullptr;
    while (root->left) root = root->left;
    return root;
}

// Find maximum value node (rightmost)
TreeNode* findMax(TreeNode* root) {
    if (!root) return nullptr;
    while (root->right) root = root->right;
    return root;
}
```

#### Insertion / Deletion

```cpp
// Insert a value
TreeNode* insert(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val < root->val) root->left = insert(root->left, val);
    else if (val > root->val) root->right = insert(root->right, val);
    // If val == root->val, do nothing (no duplicates)
    return root;
}

// TODO: Delete a value
```