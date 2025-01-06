# Table of Contents
-   **[Binary Search](#binary-search)**
    - [Lower bound](#lower-bound)
    - [Upper bound](#upper-bound)
- **[Two Pointer](#two-pointer)**
- **[Sliding Window](#sliding-window)**

# Binary Search
> [Binary Search Handbook](https://leetcode.com/problems/binary-search/solutions/423162/Binary-Search-101-The-Ultimate-Binary-Search-Handbook/)
[Leetcode Study Plan](https://leetcode.com/studyplan/binary-search/)
```c++
bool anotherFunction(vector<int> v, int mid, int N, int q){
    //Some check function
}


int l = 0, r = n-1;
while(l <= r){
    int m = l + (r-l)/2
    if(v[m] == target){ //Replaced with if(anotherFunction)
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

For array with even elements,
```c++
mid = left + (right - left)/2       //Left/lower mid
mid = left + (right - left + 1)/2   //Right/upper mid
```
## Upper and Lower bound
Array must be sorted for these to work
#### Lower Bound
> lower_bound (begin, end, value): gives the position of the first element in the [begin, end) range that is at least value
#### Upper Bound
> upper_bound (begin, end, value): gives the position of the first element in the [begin, end) range that is strictly greater than value
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
```c++
int l = 0, r = n-1;
while(l < r){
    l++, r--, etc
}
```

# Sliding Window
