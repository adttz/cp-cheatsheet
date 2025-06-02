# Bit Manipulation 

## Table of Contensts
1. [Basics](#basics)
    - [Operators](#operators)
    - [Operations on bits](#operations-on-bits)
    - [Bitwise Equations](#bitwise-equations)
2. [GCC Built-in Functions](#gcc-built-in-functions-for-bit-manipulation)
3. [Bit Masking](#bit-masking)

## Basics

### Operators

| Operator | Meaning       | Usage `a op b` | Example        | Result (binary) |
|----------|---------------|----------------|----------------|------------------|
| `&`      | AND           | Sets bit if both are 1 | `5 & 3` → `101 & 011` | `001` (1)     |
| `\|`      | OR            | Sets bit if at least one is 1 | `5 \| 3` → `101 \| 011` | `111` (7)     |
| `^`      | XOR           | Sets bit if bits differ | `5 ^ 3` → `101 ^ 011` | `110` (6)     |
| `~`      | NOT (1's comp) | Flips all bits | `~5` → `~000...0101` | `111...1010` (-6) |
| `<<`     | Left Shift    | Multiplies by `2^n` | `5 << 1ll` → `1010` | 10             |
| `>>`     | Right Shift   | Divides by `2^n` | `5 >> 1ll` → `10` | 2               |

```cpp
x << k = x * pow(2, k)
x >> k = floor(x / pow(2, k))
```
 
### Operations on Bits

```cpp
// Check if i-th bit (0-indexed) is set
bool isSet(int n, int i) {
    return ((n >> i) & 1);
}

// Set i-th bit
n |= (1 << i);

// Clear i-th bit
n &= ~(1 << i);

// Toggle i-th bit
n ^= (1 << i);

// Turn off rightmost set bit
n &= (n - 1);

// Isolate rightmost set bit
int x = n & (-n); 

// Check if power of 2
bool isPowerOfTwo(int n) {
    return n && !(n & (n - 1));
}

// Count set bits (Brian Kernighan’s Algo)
int countSetBits(int n) {
    int cnt = 0;
    while (n) {
        n &= (n - 1); // Turn off rightmost set bit
        cnt++;
    }
    return cnt;
}
```
### Bitwise Equations
```cpp
// Addition using bitwise ops
a + b = a | b + a & b
a + b = a ^ b + 2 * (a & b)

// Bitwise Operation Properties
a | b = a ^ b + a & b
(a & b) ^ (a | b) = a ^ b

a ^ (a & b) = (a | b) ^ b
b ^ (a & b) = (a | b) ^ a

// Subtraction using bitwise ops
a - b = (a ^ (a & b)) - ((a | b) ^ a)
a - b = ((a | b) ^ b) - ((a | b) ^ a)
a - b = (a ^ (a & b)) - (b ^ (a & b))
a - b = ((a | b) ^ b) - (b ^ (a & b))
``` 


## GCC Built-in Functions for Bit Manipulation
```cpp
__builtin_popcount(unsigned int x)
```
- Returns the number of set bits (1s) in x
- __builtin_popcount(0b0001'0010'1100) == 4

```cpp
__builtin_ffs(int x)
```
- Finds index (1-based) of first set bit (from right)
- __builtin_ffs(0b0001'0010'1100) == 3

```cpp
__builtin_clz(unsigned int x)
```
- Count of leading zeros (before first 1 from left)
- __builtin_clz(0b0001'0010'1100) == 23

```cpp
__builtin_ctz(unsigned int x)
```
- Count of trailing zeros (after last 1 from right)
- __builtin_ctz(0b0001'0010'1100) == 2

```cpp
__builtin_parity(unsigned int x)
```
- Returns 1 if number of 1s is odd, else 0
- __builtin_parity(0b0001'0010'1100) == 0



