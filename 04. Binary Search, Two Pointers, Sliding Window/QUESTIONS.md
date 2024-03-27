# Binary Search

## [Array Division](https://cses.fi/problemset/task/1085)
```c++
bool isvalid(vector<int> v, int mid, int n, int k){
    int partitions = 1;
    int runsum = 0;
    for(int i = 0;i < n;i++){
        runsum += v[i];
        if(runsum > mid){
            partitions++;
            runsum = v[i];
        }
    }
    return partitions <= k;
}

void solve(){
    int n, k; cin >> n >> k;
    vi v(n);
    for (auto &i : v){
        cin >> i;
    }    
    int ans = 0;
    int l = *max_element(all(v));
    int r = accumulate(all(v),0ll);
    while (l <= r){
        int mid = l + (r-l)/2;
        if(isvalid(v,mid,n,k)){
            ans = mid;
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    cout << ans << endl; 
}
```