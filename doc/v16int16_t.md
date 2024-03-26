# v16int16_t class

# Description

The `v16int16_t` class represents a vector of 16 signed integer 
numbers (**16-bit**). 
It provides methods for performing common vector operations 
using corresponding Intel vector intrinsics instructions.

# Constructors
* default constructor (no initialization)
```c++
v16int16_t()
```

* Initialize vector register with single value to all elements.
```c++
v16int16_t(int16_t value)
```

* Initialize vector register with supplied values.
```c++
v16int16_t(int16_t e0, int16_t e1, int16_t e2, int16_t e3, int16_t e4, int16_t e5, int16_t e6, int16_t e7,
           int16_t e8, int16_t e9, int16_t e10, int16_t e11, int16_t e12, int16_t e13, int16_t e14, int16_t e15)
```


* Initialize vector register with data loaded from memory.
```c++
v16int16_t(const int16_t* mem_addr)
```

# Operator overloading

| Operator   | Description                 | Instruction Set |
|------------|-----------------------------|-----------------|
| `[]`       | Vector access               | `AVX2`          |
| `+`        | Arithmetic addition         | `AVX2`          |
| `-`        | Arithmetic subtraction      | `AVX2`          |
| `*`        | Arithmetic multiplication   | `AVX2`          |
| `/`        | Arithmetic division         | `AVX2`          |
| `&`        | Logical and                 | `AVX2`          |
| `\|`       | Logical or                  | `AVX2`          |
| `^`        | Logical xor                 | `AVX2`          |

# Memory Operations

## Linear load
Load 256-bits (composed of 16 packed signed integer (16-bit) elements) from memory.

```c++
void Load(const int16_t* mem_addr)
```
Instruction Set  : `AVX512BW` + `AVX512VL`

## Linear load with mask
Load 256-bits (composed of 16 packed signed integer (16-bit) elements) from memory.
using mask(elements are zeroed out a bit of the corresponding element is not set).
```c++
void Load(const int16_t* mem_addr, const Mask16 mask)
```
Instruction Set  : `AVX512BW` + `AVX512VL`

## Linear store
Store 256-bits (composed of 16 packed signed integer (16-bit) elements) into memory.
```c++
void Store(int16_t* mem_addr) const
```
Instruction Set  : `AVX512BW` + `AVX512VL`

## Linear store with mask
Store 256-bits (composed of 16 packed signed integer (16-bit) elements) into memory.
using mask(elements are zeroed out a bit of the corresponding element is not set).
```c++
void Store(int16_t* mem_addr, const Mask16 mask) const
```
Instruction Set  : `AVX512BW` + `AVX512VL`


## Set Single 
Broadcast signed integer (16-bit) value to all elements 
```c++
void Set(int16_t value);
```
Instruction Set  : `AVX`

## Set Vector 
Set packed signed integer (16-bit) elements with supplied values.
```c++
void Set(int16_t e0, int16_t e1, int16_t e2, int16_t e3, int16_t e4, int16_t e5, int16_t e6, int16_t e7,
         int16_t e8, int16_t e9, int16_t e10, int16_t e11, int16_t e12, int16_t e13, int16_t e14, int16_t e15);
```
Instruction Set  : `AVX`

# Arithmetic Operations

## Addition
Performs element-wise addition of `this` vector and the `other` vector, and
returns a vector containing the result.

```c++
v16int16_t Add(const v16int16_t& other) const
```
Instruction Set  : `AVX2`

## Subtraction
Performs element-wise subtraction of `this` vector and the `other` vector, and
returns a vector containing the result.

```c++
v16int16_t Sub(const v16int16_t& other) const
```
Instruction Set  : `AVX2`

## Multiplication Low
Performs element-wise multiplication of `this` vector and the `other` vector,
producing intermediate 32-bit integers, and store the low 16 bits and
returns a vector containing the result.

```c++
v16int16_t MulLo(const v16int16_t& other) const
```
Instruction Set  : `AVX2`

## Division
Performs element-wise division of `this` vector and the `other` vector, and
returns a vector containing the result.

```c++
v16int16_t Div(const v16int16_t& other) const
```
Instruction Set  : `AVX`

# Logical Operations
## Or
Performs element-wise bitwise OR of `this` vector and the `other` vector, and
returns a vector containing the result.

```c++
v16int16_t Or(const v16int16_t& other) const
```
Instruction Set  : `AVX2`

## And
Performs element-wise  bitwise AND of `this` vector and the `other` vector, and
returns a vector containing the result.

```c++
v16int16_t And(const v16int16_t& other) const
```
Instruction Set  : `AVX2`

## Xor
Performs element-wise  bitwise XOR of `this` vector and the `other` vector, and
returns a vector containing the result.

```c++
v16int16_t Xor(const v16int16_t& other) const
```
Instruction Set  : `AVX2`

# Math Function

## Maximum  
compare element-wise between `this` vector and the `other` vector, and 
returns a vector containing the max elements.

```c++
v16int16_t Max(const v16int16_t& other) const
```
Instruction Set  : `AVX2`

## Minimum 
compare element-wise between `this` vector and the `other` vector, and 
returns a vector containing the min elements.
```c++
v16int16_t Min(const v16int16_t& other) const
```
Instruction Set  : `AVX2`

## Equal
Checks if `this` vector and the `other` vector are equals.

```c++
v16int16_t Equal(const v16int16_t& in) const;
```
Instruction Set  : `AVX2`

## Greater
Checks if `this` vector is greater than `other` vector.

```c++
v16int16_t Greater(const v16int16_t& in) const;
```
Instruction Set  : `AVX2`