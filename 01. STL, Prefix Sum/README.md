# Standard Template Libray & Basics
```c++
#include<bits/stdc++.h>
using namespace std
```


# Table of Contents
- **[Data Structures](#data-structures)**
    - [Array](#array)
    - [Vector](#vector)
    - [Pair](#pair)
    - [Ordered and Unordered Map](#ordered-and-unordered-nap)
    - [Set and Multiset](#set-and-nultiset)
- **[Getting Started](#getting-started)**
    - [Prefix Sum](#prefix-sum)
    - [Suffix Sum](#suffix-sum)
----

# Data Structures

## Array
```c++
template < class T, size_t N > class array;
```
- T : Type of the elements contained. Aliased as member type array::value_type.
- N : Size of the array, in terms of number of elements.
```c++
int arr[n]; // Array of n elements, with 0 indexing.
string cars[4] = {"Volvo", "BMW", "Ford", "Mazda"};
int val[row][col]; //2d array, must know row and col before defining this
for (int i = 0; i < row; i++)                 
{
    for (int j = 0; j < col; j++)
    {
        cin >> val[i][j]; 
    }   
}
//0 1 2 3 4 ..... n-1
arr.begin() //Returns iterator to beginning
arr.end() // Returns iterator to end

arr.size() //Returns number of elements 
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
vector<int> nums(n,1) // Initialized a vector of length n, having a value 1
vector<string> colour{"Blue", "Red", "Orange"};
```

## Pair


## Ordered and Unordered Map


## Set and Multiset

---
# Getting Started

## Prefix Sum

## Suffix Sum

