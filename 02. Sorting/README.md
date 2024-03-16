# Sorting
---
# Table of Contents
- **[Sorting Algoritms](#sorting-algorithms)**
    - [Bubble Sort](#bubble-sort)
    - [Selection Sort](#selection-sort)
    - [Insertion](#insertion-sort)
    - [Quick Sort](#quick-sort)
    - [Merge Sort](#merge-sort)
    - [Counting Sort](#counting-sort)
---

![Time Complexity](/images/sorting.png)

# Sorting Algorithms

## Bubble Sort

- Traverse from left and compare adjacent elements and the higher one is placed at right side. 
- The largest element is moved to the rightmost end at first. 
- This process is then continued to find the second largest and place it and so on until the data is sorted.
```c++
int i, j;
for (i = 0; i < n - 1; i++) {
    for (j = 0; j < n - i - 1; j++) {
        if (arr[j] > arr[j + 1])
            swap(a[j], a[j+1]);
    }
}
```
## Selection Sort

Repeatedly selects the smallest element from the unsorted portion of the list and moves it to the sorted portion of the list. 
```c++
int i, j, min_idx; 
for (i = 0; i < n - 1; i++) { 
    min_idx = i; 
    for (j = i + 1; j < n; j++) {   // Find the minimum element in
        if (arr[j] < arr[min_idx])  // unsorted array
            min_idx = j; 
    }
    if (min_idx != i)               // Swap the minimum element
        swap(arr[min_idx], arr[i]); // with the first element(i)
} 
```
## Insertion Sort
Compare current element (key) to its predecessor, if the key is smaller, compare it to the elements before. Move the greater elements up to make space for the swapped element. Append the key to its 
```c++
int i, key, j;
for (i = 1; i < n; i++) {
    key = arr[i];
    j = i - 1;
    while (j >= 0 && arr[j] > key) {    // Move elements of arr[0..i-1],
        arr[j + 1] = arr[j];            // that are greater than key,
        --j;                            // to one position ahead of their 
    }                                   // current position
    arr[j + 1] = key;       // Replace the ith element with the key  
}
```
## Quick Sort
Based on Divide and Conquer. Place the pivot at its correct location in the sorted array with all smaller elements to the left and bigger elements to the right. 
Partition is done recursively on each side of the pivot after the pivot is placed in its correct position and this finally sorts the array.
```c++

```
## Merge Sort


## Counting Sort






