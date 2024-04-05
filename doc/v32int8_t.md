# v32int8_t class

# Description

The `v32int8_t` class represents a vector of 32 signed integer 
numbers (**8-bit**). 
It provides methods for performing common vector operations 
using corresponding Intel vector intrinsics instructions.

# Constructors
* default constructor (no initialization)
```c++
v32int8_t()
```

* Initialize vector register with single value to all elements.
```c++
v32int8_t(int8_t value)
```

* Initialize vector register with supplied values.
```c++
v32int8_t(int8_t e0, int8_t e1, int8_t e2, int8_t e3, int8_t e4, int8_t e5, int8_t e6, int8_t e7,
        int8_t e8, int8_t e9, int8_t e10, int8_t e11, int8_t e12, int8_t e13, int8_t e14, int8_t e15, 
        int8_t e16, int8_t e17, int8_t e18, int8_t e19, int8_t e20, int8_t e21, int8_t e22, int8_t e23,
        int8_t e24, int8_t e25, int8_t e26, int8_t e27, int8_t e28, int8_t e29, int8_t e30, int8_t e31)
```


* Initialize vector register with data loaded from memory.
```c++
v32int8_t(const int8_t* mem_addr)
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
Load 256-bits (composed of 32 packed signed integer (8-bit) elements) from memory.

```c++
void Load(const int8_t* mem_addr)
```
Instruction Set  : `AVX`

## Linear load with mask
Load 256-bits (composed of 32 packed signed integer (8-bit) elements) from memory.
using mask(elements are zeroed out a bit of the corresponding element is not set).
```c++
void MaskLoad(const int8_t* mem_addr, const Mask32 mask)
```
Instruction Set  : `AVX512BW` + `AVX512VL`

## Linear store
Store 256-bits (composed of 32 packed signed integer (8-bit) elements) from memory.
```c++
void Store(int8_t* mem_addr) const
```
Instruction Set  : `AVX`

## Linear store with mask
Store 256-bits (composed of 32 packed signed integer (8-bit) elements) from memory.
using mask(elements are zeroed out a bit of the corresponding element is not set).
```c++
void MaskStore(int8_t* mem_addr, const Mask32 mask) const
```
Instruction Set  : `AVX512BW` + `AVX512VL`


## Set Single 
Broadcast signed integer (8-bit) value to all elements 
```c++
void Set(int8_t value);
```
Instruction Set  : `AVX`

## Set Vector 
Set packed signed integer (8-bit) elements with supplied values.
```c++
void Set(int8_t e0, int8_t e1, int8_t e2, int8_t e3, int8_t e4, int8_t e5, int8_t e6, int8_t e7,
        int8_t e8, int8_t e9, int8_t e10, int8_t e11, int8_t e12, int8_t e13, int8_t e14, int8_t e15,
        int8_t e16, int8_t e17, int8_t e18, int8_t e19, int8_t e20, int8_t e21, int8_t e22, int8_t e23,
        int8_t e24, int8_t e25, int8_t e26, int8_t e27, int8_t e28, int8_t e29, int8_t e30, int8_t e31)
```
Instruction Set  : `AVX`

# Arithmetic Operations

## Addition
Performs element-wise addition of `this` vector and the `other` vector, and
returns a vector containing the result.

```c++
v32int8_t Add(const v32int8_t& other) const
```
Instruction Set  : `AVX2`

## Subtraction
Performs element-wise subtraction of `this` vector and the `other` vector, and
returns a vector containing the result.

```c++
v32int8_t Sub(const v32int8_t& other) const
```
Instruction Set  : `AVX2`

## Division
Performs element-wise division of `this` vector and the `other` vector, and
returns a vector containing the result.

```c++
v32int8_t Div(const v32int8_t& other) const
```
Instruction Set  : `AVX`

# Logical Operations
## Or
Performs element-wise bitwise OR of `this` vector and the `other` vector, and
returns a vector containing the result.

```c++
v32int8_t Or(const v32int8_t& other) const
```
Instruction Set  : `AVX2`

## And
Performs element-wise  bitwise AND of `this` vector and the `other` vector, and
returns a vector containing the result.

```c++
v32int8_t And(const v32int8_t& other) const
```
Instruction Set  : `AVX2`

## Xor
Performs element-wise  bitwise XOR of `this` vector and the `other` vector, and
returns a vector containing the result.

```c++
v32int8_t Xor(const v32int8_t& other) const
```
Instruction Set  : `AVX2`

# Math Function

## Maximum  
compare element-wise between `this` vector and the `other` vector, and 
returns a vector containing the max elements.

```c++
v32int8_t Max(const v32int8_t& other) const
```
Instruction Set  : `AVX2`

## Minimum 
compare element-wise between `this` vector and the `other` vector, and 
returns a vector containing the min elements.
```c++
v32int8_t Min(const v32int8_t& other) const
```
Instruction Set  : `AVX2`

## Equal
Checks if `this` vector and the `other` vector are equals.

```c++
v32int8_t Equal(const v32int8_t& in) const;
```
Instruction Set  : `AVX2`

## Greater
Checks if `this` vector is greater than `other` vector.

```c++
v32int8_t Greater(const v32int8_t& in) const;
```
Instruction Set  : `AVX2`