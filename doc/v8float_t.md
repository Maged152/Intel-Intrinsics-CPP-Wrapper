# v8float_t class

# Description

The `v8float_t` class represents a vector of eight single-precision 
floating-point numbers (32-bit floats). 
It provides methods for performing common vector operations 
using corresponding Intel vector intrinsics instructions.

# Constructors
* default constructor (no initialization)
```c++
v8float_t()
```

* Initialize vector register with single value to all elements.
```c++
v8float_t(float value)
```

* Initialize vector register with supplied values.
```c++
v8float_t(float e0, float e1, float e2, float e3, float e4, float e5, float e6, float e7)
```


* Initialize vector register with data loaded from memory.
```c++
v8float_t(const float* mem_addr)
```

# Operator overloading

| Operator   | Description                 | Instruction Set |
|------------|-----------------------------|-----------------|
| `[]`       | Vector access               | `AVX`           |
| `+`        | Arithmetic addition         | `AVX`           |
| `-`        | Arithmetic subtraction      | `AVX`           |
| `*`        | Arithmetic multiplication   | `AVX`           |
| `/`        | Arithmetic division         | `AVX`           |
| `&`        | Logical and                 | `AVX`           |
| `\|`        | Logical or                  | `AVX`           |
| `^`        | Logical xor                 | `AVX`           |

# Memory Operations

## Linear load
Load 256-bits (composed of 8 packed single-precision (32-bit) floating-point elements) from memory.

```c++
void Load(const float* mem_addr)
```
Instruction Set  : `AVX`

## Linear load with mask
Load 256-bits (composed of 8 packed single-precision (32-bit) floating-point elements) 
from memory using mask(elements are zeroed out a bit of the corresponding element is not set).

```c++
void MaskLoad(const float* mem_addr, const Mask8 mask)
```
Instruction Set  : `AVX`

## Linear store
Store 256-bits (composed of 8 packed single-precision (32-bit) floating-point elements) into memory.
```c++
void Store(float* mem_addr) const
```
Instruction Set  : `AVX`

## Linear store with mask
Store 256-bits (composed of 8 packed single-precision (32-bit) floating-point elements)
into memory using mask(elements are zeroed out a bit of the corresponding element is not set).
```c++
void MaskStore(float* mem_addr, const Mask8 mask) const
```
Instruction Set  : `AVX`


## Set Single 
Broadcast single-precision (32-bit) floating-point value to all elements 
```c++
void Set(float value);
```
Instruction Set  : `AVX`

## Set Vector 
Set packed single-precision (32-bit) floating-point elements with supplied values.
```c++
void Set(float e0, float e1, float e2, float e3, float e4, float e5, float e6, float e7);
```
Instruction Set  : `AVX`

# Arithmetic Operations

## Addition
Performs element-wise addition of `this` vector and the `other` vector, and
returns a vector containing the result.

```c++
v8float_t Add(const v8float_t& other) const
```
Instruction Set  : `AVX`

## Subtraction
Performs element-wise subtraction of `this` vector and the `other` vector, and
returns a vector containing the result.

```c++
v8float_t Sub(const v8float_t& other) const
```
Instruction Set  : `AVX`

## Multiplication
Performs element-wise multiplication of `this` vector and the `other` vector, and
returns a vector containing the result.

```c++
v8float_t Mul(const v8float_t& other) const
```
Instruction Set  : `AVX`

## Division
Performs element-wise division of `this` vector and the `other` vector, and
returns a vector containing the result.

```c++
v8float_t Div(const v8float_t& other) const
```
Instruction Set  : `AVX`

# Logical Operations
## Or
Performs element-wise bitwise OR of `this` vector and the `other` vector, and
returns a vector containing the result.

```c++
v8float_t Or(const v8float_t& other) const
```
Instruction Set  : `AVX`

## And
Performs element-wise  bitwise AND of `this` vector and the `other` vector, and
returns a vector containing the result.

```c++
v8float_t And(const v8float_t& other) const
```
Instruction Set  : `AVX`

## Xor
Performs element-wise  bitwise XOR of `this` vector and the `other` vector, and
returns a vector containing the result.

```c++
v8float_t Xor(const v8float_t& other) const
```
Instruction Set  : `AVX`

# Math Function

## Square Root 
Performs the square root of `this` vector and
returns a vector containing the result.

```c++
v8float_t Sqrt() const
```
Instruction Set  : `AVX`

## Maximum  
compare element-wise between `this` vector and the `other` vector, and 
returns a vector containing the max elements.

```c++
v8float_t Max(const v8float_t& other) const
```
Instruction Set  : `AVX`

## Minimum 
compare element-wise between `this` vector and the `other` vector, and 
returns a vector containing the min elements.
```c++
v8float_t Min(const v8float_t& other) const
```
Instruction Set  : `AVX`

## Ceil 
Round the packed single-precision (32-bit) floating-point elements in `this` up 
to an integer value, and return the results as a vector of packed single-precision 
floating-point elements.

```c++
v8float_t Ceil() const
```
Instruction Set  : `AVX`

## Floor
Round the packed single-precision (32-bit) floating-point elements in `this` down 
to an integer value, and return the results as a vector of packed single-precision 
floating-point elements.

```c++
v8float_t Floor() const
```
Instruction Set  : `AVX`

## Round
Rounds `this` vector  based on the rounding mode specified by `round`
returns a vector containing the result.

```c++
template<RoundMode round>
v8float_t Round() const
```
Instruction Set  : `AVX`

## Compare
Compares `this` vector and the `other` vector,  based on the comparison operand specified by `comp`
returns a vector containing the result.

```c++
template<CompareMode comp>
v8float_t Compare(const v8float_t& other) const
```
Instruction Set  : `AVX`