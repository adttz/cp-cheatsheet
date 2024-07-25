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
int i, j;
for (i = 0; i < n - 1; i++) {
    for (j = 0; j < n - i - 1; j++) {
        if (arr[j] > arr[j + 1])
            swap(a[j], a[j+1]);
    }
}
```
## Selection Sort

- Repeatedly selects the smallest element from the unsorted portion of the list and moves it to the sorted portion of the list. 
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
- Compare current element (key) to its predecessor, if the key is smaller, compare it to the elements before. Move the greater elements up to make space for the swapped element.
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

int main(){
    quickSort(arr, 0, size - 1);
}
```
## Heap Sort


## Merge Sort

```c++
void merge(int a[],int l, int r, int mid){
    int n1 = mid - l + 1;
    vector<int> left(n1);
    int n2 = r - mid;
    vector<int> right(n2);
    for(int i = 0; i < n1; i++){
        left[i] = a[l+i];
    }
    for(int j = 0; j < n2; j++){
        right[i] = a[m + 1 + j];
    } 
    int i = 0, j = 0, k = l;
    while(i < n1 && j < n2){
        if(left[i] <= right[i]){
            a[k] = left[i];
            i++;
        }
        else{
            a[k] = right[j];
            j++;
        }
        k++;
    }
    while(i < n1){
        a[k] = left[i];
        i++; k++;
    }
    while(j < n2){
        a[k] = right[j];
        j++; k++;
    }
}
// Call it in main using mergeSort(a,0,n-1)
void mergeSort(int *array, int l, int r){
    int mid = l + (r-l)/2;
    while(l < r){
        mergeSort(array,l,m);
        mergeSort(array,m+1,r);
        merge(array,l,m,r);
    }
}
```

## Counting Sort
- Stable sorting algorithm
```c++
vector<int> sortArray(vector<int>& nums) {
        if (nums.empty()) return nums;

        int minValue = *min_element(nums.begin(), nums.end());  // 0 for non-negative
        int maxValue = *max_element(nums.begin(), nums.end());

        int range = maxValue - minValue + 1;    // m + 1 for non-negative
        vector<int> count(range, 0);
        vector<int> output(nums.size());

        for (int num : nums) {
            count[num - minValue]++;
        }

        for (int i = 1; i < range; ++i) {
            count[i] += count[i - 1];
        }

        for (int i = nums.size() - 1; i >= 0; --i) {
            output[count[nums[i] - minValue] - 1] = nums[i];
            count[nums[i] - minValue]--;
        }

        return output;
    }
```




