# Binary Search, Two Pointers, Sliding Window

## Table of Contents
1. [Binary Search](#binary-search)
    - [Upper bound and Lower bound](#upper-bound-and-lower-bound)
    - [Binary Search on Answer](#binary-search-on-answer)
    - [Binary Search on Two Arrays](#binary-search-on-two-arrays-partitioning)
    - [Minimize / Maximize Average](#minimize--maximize-average)
2. [Two Pointer](#two-pointer)
3. [Sliding Window](#sliding-window)

## Binary Search

```c++
int left = 0, right = n-1;
while(l <= r){
    int mid = left + (right - left)/2;
    if(v[mid] == target){   
        return mid;
    }
    if(v[mid] < target){
        left = mid + 1;
        }
    else{
        right = mid - 1;
    }
} 
```

For array with even elements
```c++
mid = left + (right - left)/2       //Left/lower mid
mid = left + (right - left + 1)/2   //Right/upper mid
```

If question indicates answer could be at mid, do not exclude it by doing right = mid - 1
```cpp
while(left < right){
    if(check(mid)){
        right = mid;
    }
    else{
        left = mid + 1;
    }
}
return left;
```

### Binary Search with Precision (Floating Point)
- Use either a fixed number of iterations or difference greater than epsilon
- Number of iterations required:
N >= log2(L `/ ε)

```cpp
double left = 0, right = *max_element();
for(int i = 0; i < 100; i++){
    double mid = left + (right - left) / 2.0;
    if(check(mid)){
        ans = mid;
        left/right = mid;
    }
    else{
        right/left = mid;
    }
}

check(left);        // Imp for edgecase
```
```cpp
double left = 0, right = 1e9;
double eps = 1e-6;
while(right - left > eps){
    double mid = left + (right - left) / 2;
    // Rest of the code
}
```
```cpp
cout << fixed << setprecision(10) << ans << "\n";
```

### Upper bound and Lower bound
#### Lower Bound
Returns iterator to the first element in the [begin, end) range that is at least value (≥ val)
#### Upper Bound
Returns iterator to the first element in the [begin, end) range that is strictly greater than value (> val)
```c++
vector<int> v={10,10,10,20,20,30,30,20};
sort(v.begin(), v.end());                

vector<int>::iterator low,up;             // 10 10 10 20 20 20 30 30
low=lower_bound(v.begin(), v.end(), 20);  //          ^
up= upper_bound(v.begin(), v.end(), 20);  //                   ^

cout << "lower_bound index " << (low- v.begin()) << endl;   // 3
cout << "upper_bound index " << (up - v.begin()) << endl;   // 6
```
### Binary Search on Answer
- For some checker functions, consider having the return statement inside the for loop as well to prevent overflow, or use __int128 for sum
- Choose right such that any addition/multiplication to it will keep it under 9e18 (long long int limit)
    - If n = 2e5, right = 1e13 is safe
```cpp
int left = 0, right = 1e9, ans = -1;
while(left <= right){
    int mid = left + (right - left)/2;
    if(check(mid)){
        ans = mid;
        right = mid - 1; // or left = mid + 1 for maximizing
    }
    else{
        left = mid + 1;
    }
}
```

### Binary Search on Two Arrays (Partitioning)
- Always binary search on smaller array
```cpp
int left = max(0, k - m), right = min(k, n);
while(left <= right){
    int i = left + (right - left) / 2;
    int j = k - i;

    int Aleft  = (i == 0) ? INT_MIN : A[i - 1];
    int Aright = (i == n) ? INT_MAX : A[i];
    int Bleft  = (j == 0) ? INT_MIN : B[j - 1];
    int Bright = (j == m) ? INT_MAX : B[j];

    if(Aleft <= Bright && Bleft <= Aright){
        return max(Aleft, Bleft);
    }
    else if(Aleft > Bright){
        right = i - 1;
    }
    else{
        left = i + 1;
    }
}
```

### Minimize / Maximize Average
```cpp
// Sum - k (Average x n) = 0
// (a1 - k) + (a2 - k) + ... + (an - k) <= 0
while(right - left > eps){
    double mid = ...
    // Use (sum) + eps in check function wherever possible to avoid precision error
}
```

# Two Pointer

# Sliding Window
