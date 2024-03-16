# v32uint8_t class

# Description

The `v32uint8_t` class represents a vector of 16 unsigned integer 
numbers (**16-bit**). 
It provides methods for performing common vector operations 
using corresponding Intel vector intrinsics instructions.

# Constructors
* default constructor (no initialization)
```c++
v32uint8_t()
```

* Initialize vector register with single value to all elements.
```c++
v32uint8_t(uint16_t value)
```

* Initialize vector register with supplied values.
```c++
v32uint8_t(uint16_t e0, uint16_t e1, uint16_t e2, uint16_t e3, uint16_t e4, uint16_t e5, uint16_t e6, uint16_t e7,
           uint16_t e8, uint16_t e9, uint16_t e10, uint16_t e11, uint16_t e12, uint16_t e13, uint16_t e14, uint16_t e15)
```


* Initialize vector register with data loaded from memory.
```c++
v32uint8_t(const uint16_t* mem_addr)
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
Load 256-bits (composed of 16 packed unsigned integer (16-bit) elements) from memory.

```c++
void Load(const uint16_t* mem_addr)
```
Instruction Set  : `AVX512BW` + `AVX512VL`

## Linear store
Store 256-bits (composed of 16 packed unsigned integer (16-bit) elements) from into memory.
```c++
void Store(uint16_t* mem_addr) const
```
Instruction Set  : `AVX512BW` + `AVX512VL`

## Set Single 
Broadcast unsigned integer (16-bit) value to all elements 
```c++
void Set(uint16_t value);
```
Instruction Set  : `AVX`

## Set Vector 
Set packed unsigned integer (16-bit) elements with supplied values.
```c++
void Set(uint16_t e0, uint16_t e1, uint16_t e2, uint16_t e3, uint16_t e4, uint16_t e5, uint16_t e6, uint16_t e7,
         uint16_t e8, uint16_t e9, uint16_t e10, uint16_t e11, uint16_t e12, uint16_t e13, uint16_t e14, uint16_t e15);
```
Instruction Set  : `AVX`

# Arithmetic Operations

## Addition
Performs element-wise addition of `this` vector and the `other` vector, and
returns a vector containing the result.

```c++
v32uint8_t Add(const v32uint8_t& other) const
```
Instruction Set  : `AVX2`

## Subtraction
Performs element-wise subtraction of `this` vector and the `other` vector, and
returns a vector containing the result.

```c++
v32uint8_t Sub(const v32uint8_t& other) const
```
Instruction Set  : `AVX2`

## Division
Performs element-wise division of `this` vector and the `other` vector, and
returns a vector containing the result.

```c++
v32uint8_t Div(const v32uint8_t& other) const
```
Instruction Set  : `AVX`

# Logical Operations
## Or
Performs element-wise bitwise OR of `this` vector and the `other` vector, and
returns a vector containing the result.

```c++
v32uint8_t Or(const v32uint8_t& other) const
```
Instruction Set  : `AVX2`

## And
Performs element-wise  bitwise AND of `this` vector and the `other` vector, and
returns a vector containing the result.

```c++
v32uint8_t And(const v32uint8_t& other) const
```
Instruction Set  : `AVX2`

## Xor
Performs element-wise  bitwise XOR of `this` vector and the `other` vector, and
returns a vector containing the result.

```c++
v32uint8_t Xor(const v32uint8_t& other) const
```
Instruction Set  : `AVX2`

# Math Function

## Maximum  
compare element-wise between `this` vector and the `other` vector, and 
returns a vector containing the max elements.

```c++
v32uint8_t Max(const v32uint8_t& other) const
```
Instruction Set  : `AVX2`

## Minimum 
compare element-wise between `this` vector and the `other` vector, and 
returns a vector containing the min elements.
```c++
v32uint8_t Min(const v32uint8_t& other) const
```
Instruction Set  : `AVX2`

## Equal
Checks if `this` vector and the `other` vector are equals.

```c++
v32uint8_t Equal(const v32uint8_t& in) const;
```
Instruction Set  : `AVX2`

## Greater
Checks if `this` vector is greater than `other` vector.

```c++
v32uint8_t Greater(const v32uint8_t& in) const;
```
Instruction Set  : `AVX512BW` + `AVX512VL`