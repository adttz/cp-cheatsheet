# Math

## Prime Numbers
### Prime Factorization using Sieve
- Precomputes smallest prime factor (spf[i]) for each number and number of prime factors (with multiplicity)

```cpp
vector<int> spf(N + 1);
vector<int> cnt(N + 1); 

void precomp(){
    // Compute smallest prime factor 
    for (int i = 2; i <= N; i++) {
        if (spf[i] == 0) {
            for (int j = i; j <= N; j += i) {
                if (spf[j] == 0){
                    spf[j] = i;
                }
            }
        }
    }

    // Compute number of prime factors 
    cnt[1] = 0;
    for (int i = 2; i <= N; i++) {
        cnt[i] = cnt[i / spf[i]] + 1;
    }
}
```

### Euler's totient function

### Fermat's Little Theorem
- If p is a prime and a is not divisible by p:
```
a^(p - 1) ≡ 1 mod p
```
- Reduces large exponents modulo (p - 1):
```
a^k ≡ a^(k % (p - 1)) mod p

a^(b^c) ≡ a^(b^c % (p - 1)) mod p
```
Triangulation
https://codeforces.com/contest/1942/problem/C1