# v4uint64_t class

# Description

The `v4uint64_t` class represents a vector of 4 unsigned integer 
numbers (64-bit). 
It provides methods for performing common vector operations 
using corresponding Intel vector intrinsics instructions.

# Constructors
* default constructor (no initialization)
```c++
v4uint64_t()
```

* Initialize vector register with single value to all elements.
```c++
v4uint64_t(uint64_t value)
```

* Initialize vector register with supplied values.
```c++
v4uint64_t(uint64_t e0, uint64_t e1, uint64_t e2, uint64_t e3)
```


* Initialize vector register with data loaded from memory.
```c++
v4uint64_t(const uint64_t* mem_addr)
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
Load 256-bits (composed of 4 packed unsigned integer (64-bit) elements) from memory.

```c++
void Load(const uint64_t* mem_addr)
```
Instruction Set  : `AVX512F` + `AVX512VL`

## Linear load with mask
Load 256-bits (composed of 4 packed unsigned integer (64-bit) elements) 
from memory using mask(elements are zeroed out a bit of the corresponding element is not set).

```c++
void Load(const uint64_t* mem_addr, const Mask4 mask)
```
Instruction Set  : `AVX2`

## Linear store
Store 256-bits (composed of 4 packed unsigned integer (64-bit) elements) from into memory.
```c++
void Store(uint64_t* mem_addr) const
```
Instruction Set  : `AVX512F` + `AVX512VL`

## Linear store with mask
Store 256-bits (composed of 4 packed unsigned integer (64-bit) elements) from into 
memory using mask(elements are zeroed out a bit of the corresponding element is not set).
```c++
void Store(uint64_t* mem_addr, const Mask4 mask) const
```
Instruction Set  : `AVX2`

## Set Single 
Broadcast unsigned integer (64-bit) value to all elements 
```c++
void Set(uint64_t value);
```
Instruction Set  : `AVX`

## Set Vector 
Set packed unsigned integer (64-bit) elements with supplied values.
```c++
void Set(uint64_t e0, uint64_t e1, uint64_t e2, uint64_t e3);
```
Instruction Set  : `AVX`

# Arithmetic Operations

## Addition
Performs element-wise addition of `this` vector and the `other` vector, and
returns a vector containing the result.

```c++
v4uint64_t Add(const v4uint64_t& other) const
```
Instruction Set  : `AVX2`

## Subtraction
Performs element-wise subtraction of `this` vector and the `other` vector, and
returns a vector containing the result.

```c++
v4uint64_t Sub(const v4uint64_t& other) const
```
Instruction Set  : `AVX2`

## Multiplication Low
Performs element-wise multiplication of `this` vector and the `other` vector,
producing intermediate 128-bit integers, and store the low 64 bits and
returns a vector containing the result.

```c++
v4uint64_t MulLo(const v4uint64_t& other) const
```
Instruction Set  : `AVX512DQ` + `AVX512VL`

## Division
Performs element-wise division of `this` vector and the `other` vector, and
returns a vector containing the result.

```c++
v4uint64_t Div(const v4uint64_t& other) const
```
Instruction Set  : `AVX`

# Logical Operations
## Or
Performs element-wise bitwise OR of `this` vector and the `other` vector, and
returns a vector containing the result.

```c++
v4uint64_t Or(const v4uint64_t& other) const
```
Instruction Set  : `AVX2`

## And
Performs element-wise  bitwise AND of `this` vector and the `other` vector, and
returns a vector containing the result.

```c++
v4uint64_t And(const v4uint64_t& other) const
```
Instruction Set  : `AVX2`

## Xor
Performs element-wise  bitwise XOR of `this` vector and the `other` vector, and
returns a vector containing the result.

```c++
v4uint64_t Xor(const v4uint64_t& other) const
```
Instruction Set  : `AVX2`

# Math Function

## Maximum  
compare element-wise between `this` vector and the `other` vector, and 
returns a vector containing the max elements.

```c++
v4uint64_t Max(const v4uint64_t& other) const
```
Instruction Set  : `AVX512F' + 'AVX512VL`

## Minimum 
compare element-wise between `this` vector and the `other` vector, and 
returns a vector containing the min elements.
```c++
v4uint64_t Min(const v4uint64_t& other) const
```
Instruction Set  : `AVX512F' + 'AVX512VL`

## Equal
Checks if `this` vector and the `other` vector are equals.

```c++
v4uint64_t Equal(const v4uint64_t& in) const;
```
Instruction Set  : `AVX2`

## Greater
Checks if `this` vector is greater than `other` vector.

```c++
v4uint64_t Greater(const v4uint64_t& in) const;
```
Instruction Set  : (`AVX512F` + `AVX512VL`) & (`AVX512DQ` + `AVX512VL`)