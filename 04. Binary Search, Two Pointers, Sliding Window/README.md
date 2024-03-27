# Table of Contents
- **[Binary Search](#binary-search)**
    - [Upper and Lower Bound](#upper-and-lower-bound)
- **[Two Pointer](#two-pointer)**
- **[Sliding Window](#sliding-window)**

# Binary Search
> [Guide](https://leetcode.com/problems/binary-search/solutions/423162/Binary-Search-101-The-Ultimate-Binary-Search-Handbook/)
```c++
int l = 0, r = n-1;
while(l <= r){
    int m = l + (r-l)/2
    if(v[m] == target){
        return mid;
    }
    if(v[m] < target){
        l = m + 1;
    }
    else{
        r = m - 1;
    }
} 
```
OR
```c++
int l = -1, r = n;
while (r - l > 1) {
    int m = (l + r) / 2;
    if (k < a[m]) {
        r = m; // a[l] <= k < a[m] <= a[r]
    } else {
        l = m; // a[l] <= a[m] <= k < a[r]
    }
}
// l will be lower bound, r will be upper bound
```
For array with even elements,
```c++
mid = left + (right - left)/2       //Left/lower mid
mid = left + (right - left + 1)/2   //Right/upper mid
```
## Upper and Lower bound
Array must be sorted for these to work
#### Lower Bound
> lower_bound(begin, end, value): gives the position of the first element in the [begin, end) range that is at least value
#### Upper Bound
> upper_bound(begin, end, value): gives the position of the first element in the [begin, end) range that is strictly greater than value
```c++
    vector<int> v={10,20,30,30,20,10,10,20};

    sort(v.begin(), v.end());                

    vector<int>::iterator low,up;             // 10 10 10 20 20 20 30 30
    low=lower_bound(v.begin(), v.end(), 20);  //          ^
    up= upper_bound(v.begin(), v.end(), 20);  //                   ^

    cout << "lower_bound index " << (low- v.begin()) << endl;// 3
    cout << "upper_bound index " << (up - v.begin()) << endl;// 6
```

# Two Pointer

# Sliding Window
https://codeforces.com/problemset/problem/279/B