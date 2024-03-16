# Sorting
---
# Table of Contents
- **[Sorting Algoritms](#sorting-algorithms)**
    - [Bubble Sort](#bubble-sort)
    - [Selection Sort](#selection-sort)
    - [Insertion](#insertion-sort)
    - [Counting Sort](#counting-sort)
    - [Merge Sort](#merge-sort)
    - [Quick Sort](#quick-sort)
---

<img align="right" src="/images/sorting.png">

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

## Counting Sort


### Merge Sort

### Quick Sort

