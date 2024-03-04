# v8float_t class

# Description

The `v8float_t` class represents a vector of eight single-precision 
floating-point numbers (32-bit floats). 
It provides methods for performing common vector operations 
using corresponding Intel vector intrinsics instructions.

# Constructors

# Arithmetic Functions

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

