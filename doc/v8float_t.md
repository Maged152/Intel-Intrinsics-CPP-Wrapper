# v8float_t class

# Description

The `v8float_t` class represents a vector of eight single-precision 
floating-point numbers (32-bit floats). 
It provides methods for performing common vector operations 
using corresponding Intel vector intrinsics instructions.

# Constructors

# Operator overloading

| Operator   | Description                 | Instruction Set |
|------------|-----------------------------|-----------------|
| `+`        | Arithmetic addition         | `AVX`           |
| `-`        | Arithmetic subtraction      | `AVX`           |
| `*`        | Arithmetic multiplication   | `AVX`           |
| `/`        | Arithmetic division         | `AVX`           |
| `[]`       | Vector access               | `AVX`           |

# Memory Operations

## Linear load
Load 256-bits (composed of 8 packed single-precision (32-bit) floating-point elements) from memory.

```c++
void Load(const float* mem_addr)
```
Instruction Set  : `AVX`

## Linear store
Store 256-bits (composed of 8 packed single-precision (32-bit) floating-point elements) from into memory.
```c++
void Store(float* mem_addr) const
```
Instruction Set  : `AVX`

# Arithmetic Operations

## Addition
Performs element-wise addition of `this` vector and the `other` vector, and
returns a vector containing the result.

```c++
v8float_t& Add(const v8float_t& other) const
```
Instruction Set  : `AVX`

## Subtraction
Performs element-wise subtraction of `this` vector and the `other` vector, and
returns a vector containing the result.

```c++
v8float_t& Sub(const v8float_t& other) const
```
Instruction Set  : `AVX`

## Multiplication
Performs element-wise multiplication of `this` vector and the `other` vector, and
returns a vector containing the result.

```c++
v8float_t& Mul(const v8float_t& other) const
```
Instruction Set  : `AVX`

## Division
Performs element-wise division of `this` vector and the `other` vector, and
returns a vector containing the result.

```c++
v8float_t& Div(const v8float_t& other) const
```
Instruction Set  : `AVX`

