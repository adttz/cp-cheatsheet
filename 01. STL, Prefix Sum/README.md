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
        - ***[Map](#map)***
        - ***[Unordered Map](#unordered-map)***
    - [Set and Multiset](#set-and-multiset)
        - ***[Set](#set)***
        - ***[Multiset](#multiset)***
- **[Getting Started](#getting-started)**
    - [Time Complexities](#time-complexities)
    - [Prefix Sum](#prefix-sum)
        - ***[Maximum Subarray Sum](#maximum-subarray-sum)***
        - ***[2d Prefix Sum](#2d-prefix-sum)***
    - [Suffix Sum](#suffix-sum)
    - [Modular Arithmetic](#modular-arithmetic)
---

# Data Structures 

## Array
```c++
template < class T, size_t N > class array;
```
- T : Type of the elements contained. Aliased as member type array::value_type.
- N : Size of the array, in terms of number of elements.
<br />

```c++
int arr[n]; // Array of n elements, with 0 indexing.
//0 1 2 3 4 ..... n-1

string cars[4] = {"Volvo", "BMW", "Ford", "Mazda"};
int val[row][col]; //2d array, must know row and col before defining this
for (int i = 0; i < row; i++){
    for (int j = 0; j < col; j++){
        cin >> val[i][j]; 
    }   
}
```
<br />

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
- Alloc : Type of the allocator object used to define the storage allocation model.
<br />

```c++
vector <object_type> vector_name;
vector<int> nums(n,1) // Initialize a vector of length n, having a value 1
vector<string> colour{"Blue", "Red", "Orange"};

vector< vector<int> > matrix(3, vector<int>(4, 0))
// Define a 2D vector with 3 rows and 4 columns, initialized with zeros
```

<br />

```c++
vector<int> v(n);
vector<int> w(m)

v.push_back(x);     //Add element at the end
v.pop_back();       //Delete last element

v.swap(w)           //Exchange elements of v and w
v.clear()           //Clears elements of vector

v.erase(i)          //Removes a single element at index i
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

<br />

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


- Pair of vectors:

```c++
pair<vector<int>,vector<string>> vp;
vp.first.push_back("abc");
vp.first.push_back("def")
vp.second.push_back(19);
vp.second.push_back(21);  
```

- Vector of pairs

```c++
vector<pair<int,int>> v;
v.push_back(make_pair(1, 3.14));
v.push_back(make_pair(2, 2.718));

vector<pair<int, char>> data = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
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
<br />

- Increasing order of keys
- Implemented using Red-Black tree
- Time complexity for search/insertion/deletion - <ins> O(logN) </ins>

<br />

```c++
map<key,value> m;
map<char,int> mp;
mp.insert(pair<char, int>('b', 100));
mp['a'] = 200;
mp.insert(pair<char, int>('c',100));
```

<br />

```c++
//Alternatively, for defining iterator : map<char, int>::iterator it;
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

<br />

```c++
map<char,int> mymap;
map<char,int>::iterator itlow,itup;

mymap['a']=20;
mymap['b']=40;
mymap['c']=60;
mymap['d']=80;
mymap['e']=100;

itlow=mymap.lower_bound('b');  // itlow points to b
itup=mymap.upper_bound('d');   // itup points to e (not d!)
mymap.erase(itlow,itup);       // erases [itlow,itup)

for (auto it=mymap.begin(); it!=mymap.end(); ++it){
    cout << it->first << " = " << it->second << '\n';
}   // a = 20 e = 100
```
### Unordered Map
// add .count() and some other functions

```c++
template<class Key, class T, class Hash = std::hash<Key>,class KeyEqual = std::equal_to<Key>,
class Allocator = std::allocator<std::pair<const Key, T>>
> class unordered_map;
```
<br />

- No ordering of keys
- Implemented using Hash tables
- Time complexity for search/insertion/deletion- <ins> Average O(1)</ins> , <ins>Worst case - O(N) </ins>

- If using unordered map for contests, make sure to use this custom hash to avoid getting hacked
    <details>
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
    //Usage: unordered_map < int, int, custom_hash > safe_map;
    </code></pre>
    </details>  

## Set and Multiset

### Set


### Multiset

---
# Getting Started

## Time Complexities


- O(1) The running time of a constant-time algorithm does not depend on the input size. A typical constant-time algorithm is a direct formula that calculates the answer.

- O(logn) A logarithmic algorithm often halves the input size at each step. The running time of such an algorithm is logarithmic, because log2 n equals the number of times n must be divided by 2 to get 1.

- O(n<sup>1/2</sup>) A square root algorithm is slower than O(logn) but faster than O(n).

- O(n) A linear algorithm goes through the input a constant number of times. This is often the best possible time complexity, because it is usually necessary to access each input element at least once before reporting the answer.

- O(nlogn) This time complexity often indicates that the algorithm sorts the input, because the time complexity of efficient sorting algorithms is O(nlogn).
Another possibility is that the algorithm uses a data structure where each operation takes O(logn) time.

- O(n<sup>2</sup>) A quadratic algorithm often contains two nested loops. It is possible to go through all pairs of the input elements in O(n<sup>2</sup>) time.

- O(n<sup>3</sup>) A cubic algorithm often contains three nested loops. It is possible to go through all triplets of the input elements in O(n<sup>3</sup>) time.

- O(2<sup>n</sup>)This time complexity often indicates that the algorithm iterates through all subsets of the input elements. For example, the subsets of {1,2,3} are {1}, {2}, {3}, {1,2}, {1,3}, {2,3} and {1,2,3}.

- O(n!) This time complexity often indicates that the algorithm iterates through all permutations of the input elements. For example, the permutations of {1,2,3} are (1,2,3), (1,3,2), (2,1,3), (2,3,1), (3,1,2) and (3,2,1).

<center>

| Input Size          | Required time complexity  |
|---------------------|---------------------------|
| n <= 10             | O(n!)                     |
| n <= 20             | O(2<sup>n</sup>)          |
| n <= 500            | O(n<sup>3</sup>)          |
| n <= 5000           | O(n<sup>2</sup>)          |
| n <= 10<sup>6</sup> | O(n logn) or O(n)         |
| n is large          | O(1) or O(logn)           |

</center>

## Prefix Sum
```c++
vector<int> pf(n);
pf[0] = a[0];
for(int i = 1; i < n; i++){
    pf[i] = pf[i-1] + a[i];
}
```
### Maximum Subarray Sum
> [Given an array of n integers, find maximum sum of values in a contiguous, nonempty subarray.
](https://cses.fi/problemset/task/1643)

<details>
        <summary>Using prefix sum</summary>
    <pre><code lang="c++">
    vector<int> pfx(n);
    pfx[0] = v[0];  
    for (int i = 0; i < n; i++) {
        pfx[i] = pfx[i - 1] + v[i];  
    }
    int max_subarray_sum = pfx[0];
    int min_prefix_sum = 0;
    for (int i = 0; i < n; i++) {
        // max subarray sum is the maximum difference between two prefix sums
        max_subarray_sum = max(max_subarray_sum, pfx[i] - min_prefix_sum);
        min_prefix_sum = min(min_prefix_sum, pfx[i]);
    }
    cout << max_subarray_sum << endl;
    </code></pre>
    </details>  
<details>
        <summary>Using DP</summary>
    <pre><code lang="c++">
    vector<int> dp(nums.size());
    dp[0] = nums[0];
    int ans = dp[0];
    for(int i = 1; i < nums.size(); i++){
        dp[i] = nums[i] + (dp[i-1] > 0 ? dp[i-1] : 0);
        ans = max(ans,dp[i]);
    }
    cout << ans << endl;
    </code></pre>
    </details>  

<details>
        <summary>Using Kadane's</summary>
    <pre><code lang="c++">
    int mx = 0, curr = 0;
    for(int i = 0; i < n; i++){
        curr += v[i];
        curr = max(curr,0ll);
        mx = max(mx,curr);
    };
    </code></pre>
    </details>  


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
## Modular Arithmetic
m = 1e9 + 7
Calculate n!, modulo m:
```c++
long long x = 1;
for (int i = 2; i <= n; i++) {
    x = (x*i)%m;
}
cout << x%m << "\n";
```

If remainder is negative,
```c++
sum = (sum % mod + mod) % mod;
```
or
```c++
x = x%m;
if (x < 0) x += m;
```
