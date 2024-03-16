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
    - [Set and Multiset](#set-and-multiset)
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

sort(v.beginn(), v.end());  //Sorts vector in ascending order
sort(v.rbegin(), v.rend()); //Sorts vector in descending order
```

## Pair


## Ordered and Unordered Map


## Set and Multiset

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
> https://cses.fi/problemset/task/1643
Can also be done using [Kadane's Algorithm](https://en.wikipedia.org/wiki/Maximum_subarray_problem#Kadane's_algorithm)
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
> https://cses.fi/problemset/task/1652

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
