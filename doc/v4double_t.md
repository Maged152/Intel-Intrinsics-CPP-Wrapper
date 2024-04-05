# v4double_t class

# Description

The `v4double_t` class represents a vector of 4 double-precision 
floating-point numbers (64-bit floats). 
It provides methods for performing common vector operations 
using corresponding Intel vector intrinsics instructions.

# Constructors
* default constructor (no initialization)
```c++
v4double_t()
```

* Initialize vector register with single value to all elements.
```c++
v4double_t(double value)
```

* Initialize vector register with supplied values.
```c++
v4double_t(double e0, double e1, double e2, double e3)
```


* Initialize vector register with data loaded from memory.
```c++
v4double_t(const double* mem_addr)
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
Load 256-bits (composed of 4 packed double-precision (64-bit) 
floating-point elements) from memory.

```c++
void Load(const double* mem_addr)
```
Instruction Set  : `AVX`

## Linear load with mask
Load 256-bits (composed of 4 packed double-precision (64-bit) 
floating-point elements) from memory using mask(elements are zeroed out 
a bit of the corresponding element is not set).

```c++
void MaskLoad(const double* mem_addr, const Mask4 mask)
```
Instruction Set  : `AVX`

## Linear store
Store 256-bits (composed of 4 packed double-precision (64-bit) 
floating-point elements) from into memory.
```c++
void Store(double* mem_addr) const
```
Instruction Set  : `AVX`

## Linear store with mask
Store 256-bits (composed of 4 packed double-precision (64-bit) 
floating-point elements) from into memory using mask(elements are zeroed out 
a bit of the corresponding element is not set).
```c++
MaskStore(double* mem_addr, const Mask4 mask) const
```
Instruction Set  : `AVX`

## Set Single 
Broadcast double-precision (64-bit) floating-point 
value to all elements 
```c++
void Set(double value);
```
Instruction Set  : `AVX`

## Set Vector 
Set packed double-precision (64-bit) floating-point 
elements with supplied values.
```c++
void Set(double e0, double e1, double e2, double e3);
```
Instruction Set  : `AVX`

# Arithmetic Operations

## Addition
Performs element-wise addition of `this` vector and the `other` vector, and
returns a vector containing the result.

```c++
v4double_t Add(const v4double_t& other) const
```
Instruction Set  : `AVX`

## Subtraction
Performs element-wise subtraction of `this` vector and the `other` vector, and
returns a vector containing the result.

```c++
v4double_t Sub(const v4double_t& other) const
```
Instruction Set  : `AVX`

## Multiplication
Performs element-wise multiplication of `this` vector and the `other` vector, and
returns a vector containing the result.

```c++
v4double_t Mul(const v4double_t& other) const
```
Instruction Set  : `AVX`

## Division
Performs element-wise division of `this` vector and the `other` vector, and
returns a vector containing the result.

```c++
v4double_t Div(const v4double_t& other) const
```
Instruction Set  : `AVX`

# Logical Operations
## Or
Performs element-wise bitwise OR of `this` vector and the `other` vector, and
returns a vector containing the result.

```c++
v4double_t Or(const v4double_t& other) const
```
Instruction Set  : `AVX`

## And
Performs element-wise  bitwise AND of `this` vector and the `other` vector, and
returns a vector containing the result.

```c++
v4double_t And(const v4double_t& other) const
```
Instruction Set  : `AVX`

## Xor
Performs element-wise  bitwise XOR of `this` vector and the `other` vector, and
returns a vector containing the result.

```c++
v4double_t Xor(const v4double_t& other) const
```
Instruction Set  : `AVX`

# Math Function

## Square Root 
Performs the square root of `this` vector and
returns a vector containing the result.

```c++
v4double_t Sqrt() const
```
Instruction Set  : `AVX`

## Maximum  
compare element-wise between `this` vector and the `other` vector, and 
returns a vector containing the max elements.

```c++
v4double_t Max(const v4double_t& other) const
```
Instruction Set  : `AVX`

## Minimum 
compare element-wise between `this` vector and the `other` vector, and 
returns a vector containing the min elements.
```c++
v4double_t Min(const v4double_t& other) const
```
Instruction Set  : `AVX`

## Ceil 
Round the packed double-precision (64-bit) floating-point elements in `this` up 
to an integer value, and return the results as a vector of packed double-precision 
floating-point elements.

```c++
v4double_t Ceil() const
```
Instruction Set  : `AVX`

## Floor
Round the packed double-precision (64-bit) floating-point elements in `this` down 
to an integer value, and return the results as a vector of packed double-precision 
floating-point elements.

```c++
v4double_t Floor() const
```
Instruction Set  : `AVX`

## Round
Rounds `this` vector  based on the rounding mode specified by `round`
returns a vector containing the result.

```c++
template<RoundMode round>
v4double_t Round() const
```
Instruction Set  : `AVX`

## Compare
Compares `this` vector and the `other` vector,  based on the comparison operand specified by `comp`
returns a vector containing the result.

```c++
template<CompareMode comp>
v4double_t Compare(const v4double_t& other) const
```
Instruction Set  : `AVX`