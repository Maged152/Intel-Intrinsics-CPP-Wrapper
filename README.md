# C++ Wrapper for Intel Vector Intrinsics

This C++ library provides a high-level interface for utilizing [Intel vector intrinsics instructions](https://www.intel.com/content/www/us/en/docs/intrinsics-guide/index.html), enhancing performance for data-parallel operations on modern x86 processors.

## Benefits

- **Improved Performance:** Leverage the power of SIMD (Single Instruction, Multiple Data) instructions for significantly faster computations compared to traditional scalar operations.
- **Increased Readability:** Employ a C++ object-oriented approach to simplify code, making it easier to understand and maintain.

## Design Principles

- **Clarity:** Prioritize clear and concise code, making it easy for developers to comprehend the functionalities of the wrapper.
- **Type Safety:** Emphasize type safety by using appropriate C++ data structures and leveraging compiler checks to prevent common errors.
- **Efficiency:** Aim to maintain efficiency by minimizing unnecessary overhead while effectively mapping high-level constructs to low-level intrinsics.

## Vector Data Types

This library defines several C++ classes under the name space `qlm` representing vector data types corresponding 
to different intrinsic instruction sets. Each class provides methods for performing common
operations on the vector elements. Refer to the individual class documentation for detailed information about functionalities and supported intrinsics:

### Naming Convention

The vector data type classes in this library follow a consistent naming convention to enhance readability and understanding:

* The prefix `v` indicates a vector data type.
* The following number represents the number of elements in the vector (e.g., `8` in `v8float_t`).
* The suffix indicates the data type of the elements (e.g., `float` in `v8float_t`).

For example, `v8float_t` represents a vector of eight single-precision floating-point numbers (32-bit floats).


### Supported Data Types

* **Float Vectors:**
    * [`v8float_t`](doc/v8float_t.md)


## Building & Linking


## Example

This is a basic example demonstrating how to use the wrapper for vector addition:

```c++
#include "shakhbat_avx.h" // This header file for AVX Intrinsics

int main() 
{

    float out[8];
    float in[16] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
     
    qlm::v8float_t v1, v2, v3;

    // Load data to the vector registers
    v1.Load(in);
    v2.Load(in + 8);

    // Add vectors
    v3 = v1.Add(v2);

    // Print the vector
    v3.Print();

    // Store the result
    v3.Store(out);

    return 0;
}
