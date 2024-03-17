# Standard Template Library & Basics
```c++
#include<bits/stdc++.h>
using namespace std
```
---
# Table of Contents
- **[Data Structures](#data-structures)**
    - [Array](#array)
    - [Vector](#vector)
    - [Pair](#pair)
    - [Ordered and Unordered Map](#ordered-and-unordered-map)
        - [Map](#map)
        - [Unordered Map](#unordered-map)
    - [Set and Multiset](#set-and-multiset)
        - [Set](#set)
        - [Multiset](#multiset)
- **[Getting Started](#getting-started)**
    - [Prefix Sum](#prefix-sum)
        - [Maximum Subarray Sum](#maximum-subarray-sum)
        - [2d Prefix Sum](#2d-prefix-sum)
    - [Suffix Sum](#suffix-sum)
---

# Data Structures 

## Array
```c++
template < class T, size_t N > class array;
```
- T : Type of the elements contained. Aliased as member type array::value_type.
- N : Size of the array, in terms of number of elements.
```c++
int arr[n]; // Array of n elements, with 0 indexing.
//0 1 2 3 4 ..... n-1
string cars[4] = {"Volvo", "BMW", "Ford", "Mazda"};
int val[row][col]; //2d array, must know row and col before defining this
for (int i = 0; i < row; i++)                 
{
    for (int j = 0; j < col; j++)
    {
        cin >> val[i][j]; 
    }   
}
```
```c++
arr.begin() //Returns iterator to beginning
arr.end()   // Returns iterator to end
arr.rbegin() 
arr.rend()

arr.size()  //Returns number of elements 
            /*Can only be used in the function 
              it is declared in*/
arr.empty() //Checks if array is empty
```

## Vector
```c++
template < class T, class Alloc = allocator<T> > class vector
```
- T : Type of the elements.
- Alloc : Type of the allocator object used to define the storage allocation model. By default, the allocator class template is used, which defines the simplest memory allocation model and is value-independent.

```c++
vector <object_type> vector_name;
vector<int> nums(n,1) // Initialize a vector of length n, having a value 1
vector<string> colour{"Blue", "Red", "Orange"};

vector<vector<int>> matrix(3, vector<int>(4, 0))
// Define a 2D vector with 3 rows and 4 columns, initialized with zeros
```

```c++
vector<int> v(n);
vector<int> w(m)

v.push_back(x);     //Add element at the end
v.pop_back(y);      //Delete last element

v.swap(w)           //Exchange elements of v and w
v.clear()           //Clears elements of vector

v.erase(i)                                  //Removes a single element 
v.erase(v.begin(), v.begin() + x)           //Erase range [first,last)
v.erase(unique(v.begin(),v.end()),v.end()); //Remove duplicates from vector

sort(v.begin(), v.end());   //Sorts vector in ascending order
sort(v.rbegin(), v.rend()); //Sorts vector in descending order
```

## Pair
```c++
template <class T1, class T2> struct pair;
```
- T1, T2 : the types of the elements that the pair stores.
```c++
pair<int,int> pair1(13,37);
pair<int,int> pair2;
pair2 = make_pair(420,69);
pair<int,char> pair3 = {1, 'a'};

pair<string,int> pair3;
pair3.first = "Take no prisoners"
pair3.second = 90

pair1.swap(pair2);
```
```c++
pair<vector<int>,vector<string>> vp;
vp.first.push_back("abc");
vp.first.push_back("def")
vp.second.push_back(19);
vp.second.push_back(21);  
```
```c++
vector<pair<int,int>> v;
v.push_back(make_pair(1, 3.14));
v.push_back(make_pair(2, 2.718));

vector<pair<int, string>> data = {{1, "apple"}, {2, "banana"}, {3, "cherry"}};
for(int i = 0; i < n; i++){
    cout << data[i].first << " " << data[i].second << endl;
}
for(auto it = data.begin(); it != data.end(); ++it) {
    cout << it->first << " " << it->second << endl;
}
```


## Ordered and Unordered Map
### Map
```c++
template< class Key, class T, class Compare = std::less<Key>,
class Allocator = std::allocator<std::pair<const Key, T>>
> class map;
```
- Increasing order of keys
- Implemented using Red-Black tree
- Time complexity for search/insertion/deletion - O(logN)

```c++
map<key,value> m;
map<char,int> mp;
mp.insert(pair<char, int>('b', 100));
mp['a'] = 200;
mp.insert(pair<char, int>('c',100));

    //map<char, int>::iterator it;
for(auto it = mp.begin(); it != mp.end(); it++){    
    cout << it->first << " = " << it->second << endl;     //mp.begin() points to the first sorted element
}   // a = 200 b = 100 c = 300

map<string,int> mymap = {{"alpha",0},{"beta",0}};
mymap.at("alpha") = 10;
mymap.at("beta") = 20;

cout << "alpha = " << mymap.find("alpha")->second << endl;
for (auto &x: mymap) {
    cout << x.first << ": " << x.second << endl;
}

```
### Unordered Map
```c++
template<class Key, class T, class Hash = std::hash<Key>,class KeyEqual = std::equal_to<Key>,
class Allocator = std::allocator<std::pair<const Key, T>>
> class unordered_map;
```
- No ordering of keys
- Implemented using Hash tables
- Time complexity for search/insertion/deletion- Average O(1), Worst case - O(N)

- If using unordered map for contests, make sure to use this custom hash to prevent getting hacked

- <details>
        <summary>Custom hash</summary>
    <pre><code lang="c++">
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
    // unordered_map < int, int, custom_hash > safe_map;
    </code></pre>
    </details>  

## Set and Multiset

### Set


### Multiset

---
# Getting Started

## Prefix Sum
```c++
vector<int> pf(n);
pf[0] = a[0];
for(int i = 1; i < n; i++){
    pf[i] = pf[i-1] + a[i];
}
```
### Maximum Subarray Sum
> [Q. Given an array of n integers, your task is to find the maximum sum of values in a contiguous, nonempty subarray.
](https://cses.fi/problemset/task/1643)

>Can also be done using [Kadane's Algorithm](https://en.wikipedia.org/wiki/Maximum_subarray_problem#Kadane's_algorithm)
```c++
vector<int> pfx(n + 1, 0);  
for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    pfx[i] = pfx[i - 1] + x;  
}

int max_subarray_sum = pfx[1];
int min_prefix_sum = pfx[0];
for (int i = 1; i <= n; i++) {
    // max subarray sum is the maximum difference between two prefix sums
    max_subarray_sum = max(max_subarray_sum, pfx[i] - min_prefix_sum);
    min_prefix_sum = min(min_prefix_sum, pfx[i]);
}
cout << max_subarray_sum << endl;
```

### 2D Prefix Sum
> [Q. You are given an n x n grid representing the map of a forest. Each square is either empty or contains a tree. The upper-left square has coordinates (1,1), and the lower-right square has coordinates (n,n). Your task is to process q queries of the form: how many trees are inside a given rectangle in the forest?
](https://cses.fi/problemset/task/1652)

![2d prefix sum](/images/2dprefixsum.png)
![Submatrix sum](/images/submatrixsum.png)

## Suffix Sum
```c++
vector<int> sf(n);
sf[n-1] = a[n-1];
for(int i = n - 2; i >= 0; i++){
    sf[i] = sf[i+1] + a[i];
}
```
