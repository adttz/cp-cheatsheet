# Strings

## Table of Contents
1. [Hashing](#hashing)
2. [Rabin Karp](#rabin-karp)
3. [KMP Algorithm](#kmp-algorithm)
4. [Z-Algorithm](#z-algorithm)

## Hashing

#### Polynomial rolling hash function
```
hash(s) = s[0] + s[1] * p + s[2] * p^2 + ... + s[n-1] * p^(n-1) mod m
```
#### Hashing a string
```
int compute_hash(string const& s) {
    const int p = 31;
    const int m = 1e9 + 9;
    int hash_value = 0;
    int p_pow = 1;
    for (char c : s) {
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return hash_value;
}
```

#### Improving no-collision probability
- Probability of collision happening is 1 / m
- For comparing 1e6 strings with each other, probability ≈ 1
- Use two different hashes, with different p and m to avoid collisions
```cpp
const int P1 = 127;          // base 1
const int P2 = 131;          // base 2
const int MOD1 = 1000000007; // large prime mod 1
const int MOD2 = 1000000009; // large prime mod 2
```

##  String Matching Algorithms

### Rabin-Karp
- Finding pattern "s" in text "t" in O(n)
```cpp
vector<int> rabin_karp(string const& s, string const& t) {
    const int p = 31; 
    const int m = 1e9 + 9;
    int S = s.size(), T = t.size();

    vector<long long> p_pow(max(S, T)); 
    p_pow[0] = 1; 
    for (int i = 1; i < (int)p_pow.size(); i++) 
        p_pow[i] = (p_pow[i-1] * p) % m;

    vector<long long> h(T + 1, 0); 
    for (int i = 0; i < T; i++)
        h[i+1] = (h[i] + (t[i] - 'a' + 1) * p_pow[i]) % m; 
    long long h_s = 0; 
    for (int i = 0; i < S; i++) 
        h_s = (h_s + (s[i] - 'a' + 1) * p_pow[i]) % m; 

    vector<int> occurrences;
    for (int i = 0; i + S - 1 < T; i++) {
        long long cur_h = (h[i+S] + m - h[i]) % m;
        if (cur_h == h_s * p_pow[i] % m)
            occurrences.push_back(i);
    }
    return occurrences;
}
```

## KMP Algorithm

- Prefix Function (π array)
- π[i] = length of the longest proper prefix of s[0..i] which is also a suffix

```cpp
vector<int> prefix_function(const string &s) {
    int n = s.size();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j]) j++;
        pi[i] = j;
    }
    return pi;
}
```

#### Pattern Matching

```cpp
vector<int> kmp_search(const string &pattern, const string &text) {
    int n = text.size(), m = pattern.size();
    vector<int> pi = prefix_function(pattern);
    vector<int> positions;
    int j = 0;
    for (int i = 0; i < n; i++) {
        while (j > 0 && text[i] != pattern[j])
            j = pi[j - 1];
        if (text[i] == pattern[j]) j++;
        if (j == m) {
            positions.push_back(i - m + 1);
            j = pi[j - 1];
        }
    }
    return positions;
}
```


## Z-Algorithm
```cpp
vector<int> z_function(string s) {
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for(int i = 1; i < n; i++) {
        if(i <= r) {
            z[i] = min(r - i + 1, z[i - l]);        // inside Z-box: use previously computed Z value
        }
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {     // extend Z[i] past r by brute force
            z[i]++;
        }
        if(i + z[i] - 1 > r) {      // update Z-box if extended past r
            l = i; 
            r = i + z[i] - 1;
        }
    }
    return z;
}
```
#### Pattern Matching
```cpp
vector<int> z_search(const string &pattern, const string &text) {
    string concat = pattern + '$' + text;
    vector<int> Z = z_function(concat);

    vector<int> positions;
    int pat_len = pattern.size();

    for (int i = pat_len + 1; i < Z.size(); i++) {
        if (Z[i] == pat_len) {
            positions.push_back(i - pat_len - 1); 
        }
    }
    return positions;
}
```
#### Matching prefix with suffix
```cpp
if (z[i] == n - i) // the suffix s[i..n-1] == prefix s[0..n-i-1]
```