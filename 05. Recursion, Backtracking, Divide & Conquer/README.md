# Recursion, Backtracking, DnC

## Table Of Contents
1. [Recursion](#recursion)
2. [Backtracking](#backtracking)
3. [Divide & Conquer](#divide-&-conquer)

## Recursion

#### Basic Structure
```cpp
int func(int ... n){
    if(n > target){
        return;     // Pruning
    }
    if(n == target){
        return ans;     // Base case
    }
    return func(n - 1) ...      // Recursive call
}
```

#### Take v/s don't take
```cpp
int rec(int x, int sum){
    if(x == n){
        return abs((total_sum - sum) - sum);
    }
    return min(rec(x + 1, sum + v[x]), rec(x + 1, sum));
               // Take                 // Don't take
}

int knapsack(int i, int weight, int value){
    if (i == n) return value; 
    int res = knapsack(i + 1, weight, value); 
    if (weight + w[i] <= k) {
        res = max(res, knapsack(i + 1, weight + w[i], value + v[i])); 
    }
    return res;
}
```

- Also can be done with bitmasking
```cpp
int func(){
    for(int mask = 0; mask < 1 << n; mask++){
        int tmp = 0;
        for(int i = 0; i < n; i++){
            if((1 << i) & mask){
                // Take
            }
            else{
                // Don't take;
            }
        }
        // Process ans
    }
    return ans;
}
```

## Backtracking
```cpp
void backtrack(vector<int> &v, vector<int> &tmp, vector<vector<int>> &ans, int start){
    if(pruning_case){
        return;
    }
    if(base_case){
        ans.push_back(tmp);
        return;
    }
    for(int i = start; i < n; i++){
        if(isValid(v, i)){
            tmp.push_back(v[i]);        // Explore taking current element
            backtrack(v, tmp, ans, i + 1);
            tmp.pop_back();             // Backtrack
        }
    }
}

vector<vector<int>> runner(vector<int> &v){
    sort(v.begin(), v.end());   // Important for handling duplicates
    vector<int> tmp;
    vector<vector<int>> ans;    
    backtrack(v, tmp, ans, 0);
    return ans;
}
```

#### Few variations
```cpp
// To skip duplicates
if(i > start && v[i] == v[i-1]) continue; 

// For generating permutations, use vis array
if(!vis[i]){
    tmp.push_back(v[i]);        
    vis[i] = true;
    backtrack(v, tmp, ans, i + 1, vis);
    tmp.pop_back();             
    vis[i] = false;
}

// For permutations with duplicates, use cursed bitmasking
for(int i = 0; i < nums.size(); i++) {
    if((1 << i) & mask) continue;
    if(i > 0 && nums[i] == nums[i - 1] && !(mask & (1 << (i - 1)))) continue;

    temp.push_back(nums[i]);
    rec(nums, temp, ans, mask | (1 << i));
    temp.pop_back();
}
```
## Divide & Conquer


#### Count Inversions
```cpp
int merge(vector<int> &arr, int l, int mid, int r) {
    int n1 = mid - l + 1;
    int n2 = r - mid;

    vector<int> left(n1), right(n2);
    for (int i = 0; i < n1; i++) left[i] = arr[l + i];
    for (int i = 0; i < n2; i++) right[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = l;
    int inv = 0;
    while (i < n1 && j < n2) {
        if (left[i] <= right[j]){
            arr[k++] = left[i++];
        }
        else{
            arr[k++] = right[j++];
            inv += n1 - i;
        }
    }

    while (i < n1) arr[k++] = left[i++];
    while (j < n2) arr[k++] = right[j++];

    return inv;
}

int mergeSort(vector<int> &arr, int l, int r) {
    int count = 0;
    if(l < r){
        int mid = l + (r - l) / 2;
        count += mergeSort(arr, l, mid);        // In first half
        count += mergeSort(arr, mid + 1, r);    // In second half
        count += merge(arr, l, mid, r);         // Between both halves
    }
    return count;
}
```