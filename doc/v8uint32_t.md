# v8uint32_t class

# Description

The `v8uint32_t` class represents a vector of eight unsigned integer 
numbers (32-bit). 
It provides methods for performing common vector operations 
using corresponding Intel vector intrinsics instructions.

# Constructors
* default constructor (no initialization)
```c++
v8uint32_t()
```

* Initialize vector register with single value to all elements.
```c++
v8uint32_t(uint32_t value)
```

* Initialize vector register with supplied values.
```c++
v8uint32_t(uint32_t e0, uint32_t e1, uint32_t e2, uint32_t e3, uint32_t e4, uint32_t e5, uint32_t e6, uint32_t e7)
```


* Initialize vector register with data loaded from memory.
```c++
v8uint32_t(const uint32_t* mem_addr)
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
| `\|`        | Logical or                  | `AVX2`           |
| `^`        | Logical xor                 | `AVX2`           |

# Memory Operations

## Linear load
Load 256-bits (composed of 8 packed unsigned integer (32-bit) elements) from memory.

```c++
void Load(const uint32_t* mem_addr)
```
Instruction Set  : `AVX512F` + `AVX512VL`

## Linear load with mask
Load 256-bits (composed of 8 packed unsigned integer (32-bit) elements) from memory
using mask(elements are zeroed out a bit of the corresponding element is not set).

```c++
void Load(const uint32_t* mem_addr, const Mask8 mask)
```
Instruction Set  : `AVX2`

## Linear store
Store 256-bits (composed of 8 packed unsigned integer (32-bit) elements) into memory.
```c++
void Store(uint32_t* mem_addr) const
```
Instruction Set  : `AVX512F` + `AVX512VL`

## Linear store with mask
Store 256-bits (composed of 8 packed unsigned integer (32-bit) elements) into memory
using mask(elements are zeroed out a bit of the corresponding element is not set).
```c++
void Store(uint32_t* mem_addr, const Mask8 mask) const
```
Instruction Set  : `AVX2`

## Set Single 
Broadcast unsigned integer (32-bit) value to all elements 
```c++
void Set(uint32_t value);
```
Instruction Set  : `AVX`

## Set Vector 
Set packed unsigned integer (32-bit) elements with supplied values.
```c++
void Set(uint32_t e0, uint32_t e1, uint32_t e2, uint32_t e3, uint32_t e4, uint32_t e5, uint32_t e6, uint32_t e7);
```
Instruction Set  : `AVX`

# Arithmetic Operations

## Addition
Performs element-wise addition of `this` vector and the `other` vector, and
returns a vector containing the result.

```c++
v8uint32_t Add(const v8uint32_t& other) const
```
Instruction Set  : `AVX2`

## Subtraction
Performs element-wise subtraction of `this` vector and the `other` vector, and
returns a vector containing the result.

```c++
v8uint32_t Sub(const v8uint32_t& other) const
```
Instruction Set  : `AVX2`

## Multiplication Low
Performs element-wise multiplication of `this` vector and the `other` vector,
producing intermediate 64-bit integers, and store the low 32 bits and
returns a vector containing the result.

```c++
v8uint32_t MulLo(const v8uint32_t& other) const
```
Instruction Set  : `AVX2`

## Division
Performs element-wise division of `this` vector and the `other` vector, and
returns a vector containing the result.

```c++
v8uint32_t Div(const v8uint32_t& other) const
```
Instruction Set  : `AVX`

# Logical Operations
## Or
Performs element-wise bitwise OR of `this` vector and the `other` vector, and
returns a vector containing the result.

```c++
v8uint32_t Or(const v8uint32_t& other) const
```
Instruction Set  : `AVX2`

## And
Performs element-wise  bitwise AND of `this` vector and the `other` vector, and
returns a vector containing the result.

```c++
v8uint32_t And(const v8uint32_t& other) const
```
Instruction Set  : `AVX2`

## Xor
Performs element-wise  bitwise XOR of `this` vector and the `other` vector, and
returns a vector containing the result.

```c++
v8uint32_t Xor(const v8uint32_t& other) const
```
Instruction Set  : `AVX2`

# Math Function

## Maximum  
compare element-wise between `this` vector and the `other` vector, and 
returns a vector containing the max elements.

```c++
v8uint32_t Max(const v8uint32_t& other) const
```
Instruction Set  : `AVX2`

## Minimum 
compare element-wise between `this` vector and the `other` vector, and 
returns a vector containing the min elements.
```c++
v8uint32_t Min(const v8uint32_t& other) const
```
Instruction Set  : `AVX2`

## Equal
Checks if `this` vector and the `other` vector are equals.

```c++
v8uint32_t Equal(const v8uint32_t& in) const;
```
Instruction Set  : `AVX2`

## Greater
Checks if `this` vector is greater than `other` vector.

```c++
v8uint32_t Greater(const v8uint32_t& in) const;
```
Instruction Set  : `AVX2`