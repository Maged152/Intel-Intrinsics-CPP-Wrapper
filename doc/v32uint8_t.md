# v32uuint8_t class

# Description

The `v32uuint8_t` class represents a vector of 32 unsigned integer 
numbers (**8-bit**). 
It provides methods for performing common vector operations 
using corresponding Intel vector intrinsics instructions.

# Constructors
* default constructor (no initialization)
```c++
v32uuint8_t()
```

* Initialize vector register with single value to all elements.
```c++
v32uuint8_t(uint8_t value)
```

* Initialize vector register with supplied values.
```c++
v32uuint8_t(uint8_t e0, uint8_t e1, uint8_t e2, uint8_t e3, uint8_t e4, uint8_t e5, uint8_t e6, uint8_t e7,
        uint8_t e8, uint8_t e9, uint8_t e10, uint8_t e11, uint8_t e12, uint8_t e13, uint8_t e14, uint8_t e15, 
        uint8_t e16, uint8_t e17, uint8_t e18, uint8_t e19, uint8_t e20, uint8_t e21, uint8_t e22, uint8_t e23,
        uint8_t e24, uint8_t e25, uint8_t e26, uint8_t e27, uint8_t e28, uint8_t e29, uint8_t e30, uint8_t e31)
```


* Initialize vector register with data loaded from memory.
```c++
v32uuint8_t(const uint8_t* mem_addr)
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
Load 256-bits (composed of 32 packed unsigned integer (8-bit) elements) from memory.

```c++
void Load(const uint8_t* mem_addr)
```
Instruction Set  : `AVX512BW` + `AVX512VL`

## Linear load with mask
Load 256-bits (composed of 32 packed unsigned integer (8-bit) elements) from memory.
using mask(elements are zeroed out a bit of the corresponding element is not set).
```c++
void Load(const uint8_t* mem_addr, const Mask32 mask)
```
Instruction Set  : `AVX512BW` + `AVX512VL`

## Linear store
Store 256-bits (composed of 32 packed unsigned integer (8-bit) elements) from memory.
```c++
void Store(uint8_t* mem_addr) const
```
Instruction Set  : `AVX512BW` + `AVX512VL`

## Linear store with mask
Store 256-bits (composed of 32 packed unsigned integer (8-bit) elements) from memory.
using mask(elements are zeroed out a bit of the corresponding element is not set).
```c++
void Store(uint8_t* mem_addr, const Mask32 mask) const
```
Instruction Set  : `AVX512BW` + `AVX512VL`


## Set Single 
Broadcast unsigned integer (8-bit) value to all elements 
```c++
void Set(uint8_t value);
```
Instruction Set  : `AVX`

## Set Vector 
Set packed unsigned integer (8-bit) elements with supplied values.
```c++
void Set(uint8_t e0, uint8_t e1, uint8_t e2, uint8_t e3, uint8_t e4, uint8_t e5, uint8_t e6, uint8_t e7,
        uint8_t e8, uint8_t e9, uint8_t e10, uint8_t e11, uint8_t e12, uint8_t e13, uint8_t e14, uint8_t e15,
        uint8_t e16, uint8_t e17, uint8_t e18, uint8_t e19, uint8_t e20, uint8_t e21, uint8_t e22, uint8_t e23,
        uint8_t e24, uint8_t e25, uint8_t e26, uint8_t e27, uint8_t e28, uint8_t e29, uint8_t e30, uint8_t e31)
```
Instruction Set  : `AVX`

# Arithmetic Operations

## Addition
Performs element-wise addition of `this` vector and the `other` vector, and
returns a vector containing the result.

```c++
v32uuint8_t Add(const v32uuint8_t& other) const
```
Instruction Set  : `AVX2`

## Subtraction
Performs element-wise subtraction of `this` vector and the `other` vector, and
returns a vector containing the result.

```c++
v32uuint8_t Sub(const v32uuint8_t& other) const
```
Instruction Set  : `AVX2`

## Division
Performs element-wise division of `this` vector and the `other` vector, and
returns a vector containing the result.

```c++
v32uuint8_t Div(const v32uuint8_t& other) const
```
Instruction Set  : `AVX`

# Logical Operations
## Or
Performs element-wise bitwise OR of `this` vector and the `other` vector, and
returns a vector containing the result.

```c++
v32uuint8_t Or(const v32uuint8_t& other) const
```
Instruction Set  : `AVX2`

## And
Performs element-wise  bitwise AND of `this` vector and the `other` vector, and
returns a vector containing the result.

```c++
v32uuint8_t And(const v32uuint8_t& other) const
```
Instruction Set  : `AVX2`

## Xor
Performs element-wise  bitwise XOR of `this` vector and the `other` vector, and
returns a vector containing the result.

```c++
v32uuint8_t Xor(const v32uuint8_t& other) const
```
Instruction Set  : `AVX2`

# Math Function

## Maximum  
compare element-wise between `this` vector and the `other` vector, and 
returns a vector containing the max elements.

```c++
v32uuint8_t Max(const v32uuint8_t& other) const
```
Instruction Set  : `AVX2`

## Minimum 
compare element-wise between `this` vector and the `other` vector, and 
returns a vector containing the min elements.
```c++
v32uuint8_t Min(const v32uuint8_t& other) const
```
Instruction Set  : `AVX2`

## Equal
Checks if `this` vector and the `other` vector are equals.

```c++
v32uuint8_t Equal(const v32uuint8_t& in) const;
```
Instruction Set  : `AVX2`

## Greater
Checks if `this` vector is greater than `other` vector.

```c++
v32uuint8_t Greater(const v32uuint8_t& in) const;
```
Instruction Set  : `AVX2`