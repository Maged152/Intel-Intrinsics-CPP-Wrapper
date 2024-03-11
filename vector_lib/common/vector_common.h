#pragma once

#include <immintrin.h>
#include "types.h"
#include <iostream>

namespace qlm
{
	template<typename d_t, typename vec_t>
	class Vector
	{
	public:
		// ALU operations
		virtual vec_t Add(const vec_t& in) const = 0;
		virtual vec_t Sub(const vec_t& in) const = 0;
		virtual vec_t Mul(const vec_t& in) const = 0;
		virtual vec_t Div(const vec_t& in) const = 0;

	public:
		// Logical operations
		virtual vec_t Or(const vec_t& in) const = 0;
		virtual vec_t And(const vec_t& in) const = 0;
		virtual vec_t Xor(const vec_t& in) const = 0;

	public:
		// Math functions
		virtual vec_t Max(const vec_t& in) const = 0;
		virtual vec_t Min(const vec_t& in) const = 0;

	public:
		// Memory operations
		virtual void Load(const d_t* mem_addr) = 0;
		virtual void Store(d_t* mem_addr) const = 0;

	public:
		// Operators overloading
		virtual d_t operator [](const size_t index) const = 0;

		vec_t operator +(const vec_t& in) const
		{
			return this->Add(in);
		}
		vec_t operator -(const vec_t& in) const
		{
			return this->Sub(in);
		}
		vec_t operator *(const vec_t& in) const
		{
			return this->Mul(in);
		}

		vec_t operator |(const vec_t& in) const
		{
			return this->Or(in);
		}

		vec_t operator &(const vec_t& in) const
		{
			return this->And(in);
		}
		vec_t operator ^(const vec_t& in) const
		{
			return this->Xor(in);
		}

		vec_t operator /(const vec_t& in) const
		{

		}

	public:
		constexpr size_t SimdWidth() const
		{
			return sizeof(std::declval<vec_t>().vec_reg);
		}

		constexpr size_t Length() const
		{
			return SimdWidth() / sizeof(d_t);
		}

		void Print() const
		{
			std::cout << "[";
			for (int i = 0; i < Length(); i++)
			{
				std::cout << this->operator[](i) << " ";
			}
			std::cout << "]\n";
		}

	};
}


