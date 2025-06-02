# C++ STL & Basics 

## Table of Contents

1. [Vectors](#1-vectors) 
2. [Sets and Multisets](#2-sets-and-multisets)  
3. [Maps and Unordered Maps](#3-maps-and-unordered-maps)  
4. [Stacks and Queues](#4-stacks-and-queues)  
5. [Priority Queues](#5-priority-queues)  
6. [Deques and Lists](#6-deques-and-lists)  
7. [Pairs and Tuples](#7-pairs-and-tuples)  
8. [STL Algorithms](#8-stl-algorithms)  
9. [Prefix and Suffix Sum](#9-prefix-and-suffix-sum)  
10. [Basic Math](#10-basic-math)
11. [Modular Arithmetic](#11-modular-arithmetic)

## 1. Vectors
```cpp
vector<int> v;                 // Empty vector
vector<int> v(5, 2);           // {2, 2, 2, 2, 2}
vector<int> nums{1, 2. 3};
vector<vector<int>> v(n, vector<int>(m,0));

v.push_back(10);               // Add at end
v.pop_back();                  // Remove last

v.erase(v.begin() + i);                             // Remove element at index i 
v.erase(unique(v.begin(), v.end()), v.end());       // Set operation
v.erase(remove(v.begin(), v.end(), x), v.end());    // Remove all instances of x

auto it = find(v.begin(), v.end(), x);
if (it != v.end()) {
    v.erase(it);                // Removes only the first occurrence
}

int x = v.front()/back();      // First/Last element
int n = v.size();              // Size

sort(v.begin(), v.end());      // Ascending sort
reverse(v.begin(), v.end());   // Reverse

for (int i : v) cout << i << " ";
for (auto it = v.begin(); it != v.end(); it++){
    cout << *it << " ";
}
```



## 2. Sets and Multisets

### Set (unique elements)
```cpp
set<int> s;
s.insert(10);
s.erase(10);
bool exists = s.count(5);   // 1 if exists

set<int>::iterator it;
it = s.begin();
it = s.end();       // Not in set, use *(it--) for largest value in set
it = s.lower_bound(val);      // Iterator to first element ≥ val
it = s.upper_bound(val);      // Iterator to first element > val

for (auto it = s.begin(); it != s.end(); it++){
    cout << *it << " ";
}
```
- O(logN) insertion/deletion

### Multiset (allows duplicates)
```cpp
#include <set>

multiset<int> ms;
ms.insert(1);
ms.insert(1);
ms.erase(ms.find(1));   // Erase one instance
ms.erase(1);            // Erase all instances
for(int i = 0; i < n; i++){
    auto it = ms.lower_bound(v[i]);
}
```



## 3. Maps and Unordered Maps

### Map (ordered keys)
```cpp
map<string, int> m;     // map<key, value> m;
m["apple"] = 5;
m["banana"]++;
cout << m["apple"];     // 5
m.erase("banana");

m.clear();     // Clear map

for (auto it = m.begin(); it != m.end(); it++)
    cout << it->first << " " << it->second << "\n";
```

### Unordered Map (faster, random order)
- No ordering of keys
- Implemented using Hash tables
- Time complexity for search/insertion/deletion- <ins> Average O(1)</ins> , <ins>Worst case - O(N) </ins>
- If using unordered map for contests, make sure to use this custom hash to avoid getting hacked
    <details>
        <summary>Custom hash</summary>
    <pre><code lang="c++">
    //Usage: unordered_map<int, int, custom_hash> safe_map;
    struct custom_hash {
        static uint64_t splitmix64(uint64_t x) {
            x += 0x9e3779b97f4a7c15;
            x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
            x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
            return x ^ (x >> 31);
        }
        size_t operator()(uint64_t x) const {
            static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
            return splitmix64(x + FIXED_RANDOM);
        }
    };
    </code></pre>
    </details>       

```c++
unordered_map<string, int> umap = { {"One", 1}, {"Two", 2}, {"Three", 3} }; 
if (umap.find(key) == umap.end())
    cout << key << "Not Found" << endl;
```


## 4. Stacks and Queues

### Stack
- LIFO (Last in, first out)

```c++
stack<int> s;
s.push(2);
s.push(3);
s.push(5);
s.top(); // Points to the last / newest element
while(!s.empty()){
    cout << s.top() << endl;    // 5 3 2
    s.pop();
}
```
#### Monotonic Stack
- Stack whose elements are monotonically increasing or decreasing
- Used for 
    - previous/next - smaller/larger 
    - calculating the maximum area under histograms
    - evaluating expressions with infix to postfix conversion
    - stock span, building and trapping rainwater, etc.

```c++
stack<int> s;
vector<int> ans(n);
for (int i = n-1; i >= 0; i--){
    
    //while element at top of stack is less than or equal to
    //current array element, we pop elements from the stack.
    
    while (!s.empty () and s.top () <= arr[i]){
        s.pop ();
    }
    if (s.empty ()){            //if stack becomes empty, we store -1 in the answer list 
        ans[i] = -1;
    }
    else ans[i] = s.top();      //else, we store the top element of the stack.

    s.push(arr[i]);
}
return ans;
```
### Queue

- FIFO (First in, first out)
- Insertion and Deletion happen on different ends
- Enqueue : Addition of element at the end of the queue
- Dequeue : Removal of element from front of the queue


```c++
queue <string> q;
q.push("ABC");
q.push("DEF");
q.push("GHI");
while(!q.empty()){
    cout << q.front() << endl;    // ABC DEF GHI
    q.pop();
}
```



## 5. Priority Queues

```cpp
// Max-heap
priority_queue<int> pq;     
pq.push(10);
pq.push(5);
pq.top();    // 10
pq.pop();    // Remove 10

// No direct iterator, use while loop
while (!pq.empty()) {
    cout << pq.top() << " ";
    pq.pop();
}

// Min-heap
priority_queue<int, vector<int>, greater<int>> pq;      
```



## 6. Deques and Lists

### Deque (Double-ended Queue)
```cpp
deque<int> dq;
dq.push_back(1);
dq.push_front(2);
dq.pop_back();
dq.pop_front();

for (auto it = dq.begin(); it != dq.end(); it++){
    cout << *it << " ";
}
```

### List (Doubly Linked List)
```cpp
list<int> lst = {1, 2, 3};
lst.push_back(4);
lst.push_front(0);
lst.pop_back();
lst.pop_front();

for (auto it = lst.begin(); it != lst.end(); it++){
    cout << *it << " ";
}
```



## 7. Pairs and Tuples

### Pair
```cpp
pair<int, int> p = {1, 2};
cout << p.first << " " << p.second;

pair<int,int> pair2;
pair2 = make_pair(420,69);
```

### Vector of Pairs
```cpp
vector<pair<int,int>> v;
int a, b; cin >> a >> b;
v.push_back({a, b});
v.emplace_back(a, b);

vector<pair<int, int>> vp = {{1, 2}, {3, 4}};

for(int i = 0; i < n; i++){
    cout << data[i].first << " " << data[i].second;
}
for(auto it = data.begin(); it != data.end(); it++) {
    cout << it->first << " " << it->second;l
}

// Sort a vector by its second element
bool comp(const pair<int,int> &a,const pair<int,int> &b)
{
    return a.second<b.second;
}

sort(v.begin(), v.end(), [](const pair<int,int> &left, const pair<int,int> &right) {
    return left.second < right.second;
});
```

### Tuple

```cpp
tuple<int, string, char> t = make_tuple(1, "hello", 'a');
cout << get<0>(t) << " " << get<1>(t) << " " << get<2>(t);
get<1>(t) = "world";

int x; string s; char c;
tie(x, s, c) = t;   // Unpacking tuple


vector<tuple<int, string, char>> vt;
vt.push_back({1, "apple", 'a'});
for (int i = 0; i < vt.size(); i++) {
    cout << get<0>(vt[i]) << " " << get<1>(vt[i]) << " " << get<2>(vt[i]) << "\n";
}

for (auto &[id, name, ch] : vt) {
    cout << id << " " << name << " " << ch << "\n";
}

sort(vt.begin(), vt.end(), [](const tuple<int, string, char> &a, const tuple<int, string, char> &b) {
    return get<1>(a) < get<1>(b);
});
```

## 8. STL Algorithms
```cpp
sort(v.begin(), v.end());
reverse(v.begin(), v.end());
int mx = *max_element(v.begin(), v.end());
int mn = *min_element(v.begin(), v.end());
int sum = accumulate(v.begin(), v.end(), 0);
int ct = count(v.begin(), v.end(), 3);
auto it = find(v.begin(), v.end(), 5); // returns iterator

if (it != v.end())
    cout << "Found at index " << it - v.begin();
```


## 9. Prefix and Suffix Sum
```cpp
vector<int> pf(n);
pf[0] = v[0];
for(int i = 1; i < n; i++){
    pf[i] = pf[i-1] + v[i];
}

vector<int> sf(n);
sf[n-1] = v[n-1];
for(int i = n - 2; i >= 0; i--){
    sf[i] = sf[i+1] + v[i];
}
```

## 10. Basic Math

### Ceil and Floor

```cpp
int ceil_div(int a, int b){
    return (a + b - 1) / b;     // Not valid for negative numbers
}

// Valid for both positive and negative numbers
int x = ceil(a * 1.0 / b);
int y = floor(a * 1.0 / b);
```

### GCD and LCM

```cpp
// Euclidian Algorithm
int gcd(int a, int b){
    if(a == 0){
        return b;
    }
    return gcd(b % a, a);
}

int lcm(int a, int b){
    return (a / gcd(a,b)) * b;
}
```
### Sieve of Eratosthenes

```cpp
vector<bool> is_prime(n+1, true);
is_prime[0] = is_prime[1] = false;
for (int i = 2; i * i <= n; i++) {
    if (is_prime[i]) {
        for (int j = i * i; j <= n; j += i)
            is_prime[j] = false;
    }
}
```
### Binary Exponentiation

```cpp
int binpow(int a, int b){
    int res = 1;
    while(b > 0){
        if(b & 1){      // if n is odd
            res *= a;
        }
        a *= a;
        b >>= 1;        // n = n / 2
    }
    return res;
}
```


## 11. Modular Arithmetic
```
https://codeforces.com/blog/entry/72527
https://usaco.guide/gold/modular?lang=cpp
```

```cpp
const int mod = 1e9 + 7;

int binpow(int a, int b){
    int res = 1;
    a %= mod;
    while (b > 0) {
        if (b & 1){
            res = (res * a) % mod;
        }
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}
```