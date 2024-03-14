# v8int32_t class

# Description

The `v8int32_t` class represents a vector of eight signed integer 
numbers (32-bit). 
It provides methods for performing common vector operations 
using corresponding Intel vector intrinsics instructions.

# Constructors
* default constructor (no initialization)
```c++
v8int32_t()
```

* Initialize vector register with single value to all elements.
```c++
v8int32_t(int32_t value)
```

* Initialize vector register with supplied values.
```c++
v8int32_t(int32_t e0, int32_t e1, int32_t e2, int32_t e3, int32_t e4, int32_t e5, int32_t e6, int32_t e7)
```


* Initialize vector register with data loaded from memory.
```c++
v8int32_t(const int32_t* mem_addr)
```

# Operator overloading

| Operator   | Description                 | Instruction Set |
|------------|-----------------------------|-----------------|
| `[]`       | Vector access               | `AVX2`           |
| `+`        | Arithmetic addition         | `AVX2`           |
| `-`        | Arithmetic subtraction      | `AVX2`           |
| `*`        | Arithmetic multiplication   | `AVX2`           |
| `/`        | Arithmetic division         | `AVX2`           |
| `&`        | Logical and                 | `AVX2`           |
| `|`        | Logical or                  | `AVX2`           |
| `^`        | Logical xor                 | `AVX2`           |

# Memory Operations

## Linear load
Load 256-bits (composed of 8 packed signed integer (32-bit) elements) from memory.

```c++
void Load(const int32_t* mem_addr)
```
Instruction Set  : `AVX512F` + `AVX512VL`

## Linear store
Store 256-bits (composed of 8 packed signed integer (32-bit) elements) from into memory.
```c++
void Store(int32_t* mem_addr) const
```
Instruction Set  : `AVX512F` + `AVX512VL`

## Set Single 
Broadcast signed integer (32-bit) value to all elements 
```c++
void Set(int32_t value);
```
Instruction Set  : `AVX2`

## Set Vector 
Set packed signed integer (32-bit) elements with supplied values.
```c++
void Set(int32_t e0, int32_t e1, int32_t e2, int32_t e3, int32_t e4, int32_t e5, int32_t e6, int32_t e7);
```
Instruction Set  : `AVX2`

# Arithmetic Operations

## Addition
Performs element-wise addition of `this` vector and the `other` vector, and
returns a vector containing the result.

```c++
v8int32_t Add(const v8int32_t& other) const
```
Instruction Set  : `AVX2`

## Subtraction
Performs element-wise subtraction of `this` vector and the `other` vector, and
returns a vector containing the result.

```c++
v8int32_t Sub(const v8int32_t& other) const
```
Instruction Set  : `AVX2`

## Multiplication Low
Performs element-wise multiplication of `this` vector and the `other` vector,
producing intermediate 64-bit integers, and store the low 32 bits and
returns a vector containing the result.

```c++
v8int32_t MulLo(const v8int32_t& other) const
```
Instruction Set  : `AVX2`

## Division
Performs element-wise division of `this` vector and the `other` vector, and
returns a vector containing the result.

```c++
v8int32_t Div(const v8int32_t& other) const
```
Instruction Set  : `AVX2`

# Logical Operations
## Or
Performs element-wise bitwise OR of `this` vector and the `other` vector, and
returns a vector containing the result.

```c++
v8int32_t Or(const v8int32_t& other) const
```
Instruction Set  : `AVX2`

## And
Performs element-wise  bitwise AND of `this` vector and the `other` vector, and
returns a vector containing the result.

```c++
v8int32_t And(const v8int32_t& other) const
```
Instruction Set  : `AVX2`

## Xor
Performs element-wise  bitwise XOR of `this` vector and the `other` vector, and
returns a vector containing the result.

```c++
v8int32_t Xor(const v8int32_t& other) const
```
Instruction Set  : `AVX2`

# Math Function

## Maximum  
compare element-wise between `this` vector and the `other` vector, and 
returns a vector containing the max elements.

```c++
v8int32_t Max(const v8int32_t& other) const
```
Instruction Set  : `AVX2`

## Minimum 
compare element-wise between `this` vector and the `other` vector, and 
returns a vector containing the min elements.
```c++
v8int32_t Min(const v8int32_t& other) const
```
Instruction Set  : `AVX2`

## Equal
Checks if `this` vector and the `other` vector are equals.

```c++
v8int32_t Equal(const v8int32_t& in) const;
```
Instruction Set  : `AVX2`

## Greater
Checks if `this` vector is greater than `other` vector.

```c++
v8int32_t Greater(const v8int32_t& in) const;
```
Instruction Set  : `AVX2`