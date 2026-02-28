# Modular Arithmetic in DSA

Complete revision guide for understanding and using modulo in Data Structures and Algorithms.

---

## 1. What is Modulo?

For integers `a` and `b`:

```
a % b = remainder when a is divided by b
```

Mathematically:

```
a = b * q + r
where 0 ≤ r < b
```

Example:

```
17 % 5 = 2
```

---

## 2. Why Modulo is Important in DSA

### 1. Prevent Overflow

Used when numbers become very large (factorial, power problems, combinatorics).

### 2. Cyclic Nature

Useful in:

- Circular arrays  
- Rotations  
- Clock problems  
- Josephus problem  

### 3. Hashing

Keeps index inside array size.

### 4. Number Theory

Used in:

- GCD / LCM  
- Prime problems  
- Combinations (nCr)  
- Modular inverse  

---

## 3. Basic Properties of Modulo

Let `a`, `b`, and `m` be integers.

### 3.1 Addition

```
(a + b) % m = ((a % m) + (b % m)) % m
```

---

### 3.2 Subtraction

```
(a - b) % m = ((a % m) - (b % m) + m) % m
```

Always add `+m` to avoid negative result.

---

### 3.3 Multiplication

```
(a * b) % m = ((a % m) * (b % m)) % m
```

---

### 3.4 Division (Not Directly Allowed)

```
(a / b) % m ≠ ((a % m) / (b % m)) % m
```

Division requires **modular inverse**.

---

## 4. Fast Exponentiation (Binary Exponentiation)

Used to calculate:

```
(a^b) % m
```

Time Complexity: `O(log b)`

### C++ Code

```cpp
long long power(long long a, long long b, long long m) {
    long long result = 1;
    a = a % m;

    while (b > 0) {
        if (b % 2 == 1)
            result = (result * a) % m;

        a = (a * a) % m;
        b = b / 2;
    }

    return result;
}
```

---

## 5. Modular Inverse

We want a number `b⁻¹` such that:

```
(b * b⁻¹) % m = 1
```

Condition:

```
gcd(b, m) = 1
```

---

### Using Fermat’s Little Theorem

If `m` is prime:

```
b⁻¹ % m = b^(m - 2) % m
```

Example:

Find inverse of `3 mod 11`

```
3^(11 - 2) % 11
= 3^9 % 11
= 4
```

Check:

```
(3 * 4) % 11 = 1
```

---

## 6. Why 10^9 + 7 is Used

```
mod = 1000000007
```

Reasons:

- It is prime  
- Fits in integer range  
- Supports modular inverse  
- Reduces overflow problems  

---


### nCr % mod

Formula:

```
nCr = n! / (r! * (n-r)!)
```

Under modulo:

```
nCr = n! * inv(r!) * inv((n-r)!) % mod
```

Where inverse is:

```
power(x, mod - 2, mod)
```

---

## Handling Negative Modulo

Different languages behave differently for negative numbers.

Safe formula:

```
((a % m) + m) % m
```

---