# Sorting
# Table of Contents
**[Sorting Algoritms](#sorting-algorithms)**
  - [Bubble Sort](#bubble-sort)
  - [Selection Sort](#selection-sort)
  - [Insertion Sort](#insertion-sort)
  - [Quick Sort](#quick-sort)
  - [Heap Sort](#heap-sort)
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
void bubbleSort(vector<int> &arr, int n){
    for (int i = 0; i < n - 1; i++) {  
        for (int j = 0; j < n - i - 1; j++) {  
            if (arr[j] > arr[j + 1])  
                swap(arr[j], arr[j + 1]);  
        }
    }
}
```
## Selection Sort

- Repeatedly selects the smallest element from the unsorted portion of the list and moves it to the sorted portion of the list. 
```c++
void selectionSort(vector<int> &arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i; 
        
        // Find the minimum element in the unsorted part
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) 
                min_idx = j;
        }

        // Swap the found minimum element with the first element of the unsorted part
        if (min_idx != i)
            swap(arr[min_idx], arr[i]);
    }
}
```
## Insertion Sort
- Compare current element (key) to its predecessor, if the key is smaller, compare it to the elements before. Move the greater elements up to make space for the swapped element.
```c++
void insertionSort(vector<int> &arr, int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];  // Current element to be placed correctly
        j = i - 1;

        // Move elements greater than key one step ahead
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        
        arr[j + 1] = key;  // Place key at the correct position
    }
}
```
## Quick Sort
- Three pointers, x, y and pivot (usually chosen as last element)
- Compare y and pivot ; If pivot < y, increment y;
- If pivot >= y, 
  - Increment x
  - Swap values of x and y (not the pointer itself)
  - Increment y

```c++
void swap(int* x, int* y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

int partition(int arr[], int low, int high)
{
	int pivot = arr[high]; 
	int x = (low- 1); 
	for (int y = low; y <= high - 1; y++) {
		if (arr[y] < pivot) {
			x++; 
			swap(&arr[x], &arr[y]);
		}
	}
	swap(&arr[x + 1], &arr[high]);
	return (x + 1);
}

void quickSort(int arr[], int low, int high)
{
	if (low < high) {		
		int p = partition(arr, low, high);
        // quick sort elements on the left recursively
		quickSort(arr, low, p - 1);
		// quick sort elements on the right recursively
		quickSort(arr, p + 1, high);
	}
}
```
## Heap Sort


## Merge Sort

```c++
void merge(vector<int> &v,int l, int r, int mid){
    int n1 = mid - l + 1;
    vector<int> left(n1);
    int n2 = r - mid;
    vector<int> right(n2);
    for(int i = 0; i < n1; i++){
        left[i] = v[l + i];
    }
    for(int i = 0; i < n2; i++){
        right[i] = v[mid + 1 + i];
    } 
    int i = 0, j = 0, k = l;
    while(i < n1 && j < n2){
        if(left[i] <= right[j]){
            v[k] = left[i];
            i++;
        }
        else{
            v[k] = right[j];
            j++;
        }
        k++;
    }
    while(i < n1){
        v[k] = left[i];
        i++; k++;
    }
    while(j < n2){
        v[k] = right[j];
        j++; k++;
    }
}
void mergeSort(vector<int> &array, int l, int r){
    if(l < r){
        int mid = l + (r-l)/2;
        mergeSort(array,l,m);
        mergeSort(array,m+1,r);
        merge(array,l,m,r);
    }
}
```

## Counting Sort
- Stable sorting algorithm
```c++
void countingSort(vector<int>& nums) {
    if (nums.empty()) return nums;  // Edge case: empty array

    int maxValue = *max_element(nums.begin(), nums.end());
    //int minValue = *min_element(nums.begin(), nums.end());

    vector<int> count(maxValue + 1, 0);  // count(maxValue - minValue + 1, 0);
    vector<int> output(nums.size());     

    for (int num : nums) {
        count[num]++;  
        // count[num - minValue]++;   // For handling negative numbers
    }

    for (int i = 1; i <= maxValue; ++i) {
        count[i] += count[i - 1];
    }

    for (int i = nums.size() - 1; i >= 0; --i) {
        output[count[nums[i]] - 1] = nums[i];  
        count[nums[i]]--;                      

        // output[count[nums[i] - minValue] - 1] = nums[i];  // For handling negative numbers
        // count[nums[i] - minValue]--;                      // Adjust count
    }

    nums = output;
}
```




