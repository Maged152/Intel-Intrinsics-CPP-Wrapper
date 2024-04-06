#pragma once

#include "vector256_int.h"

namespace qlm
{
	class v16int16_t : public v256int_t<int16_t, v16int16_t>
	{
	public:
		// Constructors
		v16int16_t();
		v16int16_t(int16_t value);
		v16int16_t(int16_t e0, int16_t e1, int16_t e2, int16_t e3, int16_t e4, int16_t e5, int16_t e6, int16_t e7,
			       int16_t e8, int16_t e9, int16_t e10, int16_t e11, int16_t e12, int16_t e13, int16_t e14, int16_t e15);
		v16int16_t(const int16_t* mem_addr);

	public:
		// ALU operations
		virtual v16int16_t Add(const v16int16_t& in) const override;
		virtual v16int16_t Sub(const v16int16_t& in) const override;
		v16int16_t MulLo(const v16int16_t& in) const;
		virtual v16int16_t Div(const v16int16_t& in) const override;

	public:
		// Math functions
		virtual v16int16_t Max(const v16int16_t& in) const override;
		virtual v16int16_t Min(const v16int16_t& in) const override;

	public:
		// Set 
		void Set(int16_t value);
		void Set(int16_t e0, int16_t e1, int16_t e2, int16_t e3, int16_t e4, int16_t e5, int16_t e6, int16_t e7,
			     int16_t e8, int16_t e9, int16_t e10, int16_t e11, int16_t e12, int16_t e13, int16_t e14, int16_t e15);
		void Set(int16_t value, const size_t index);

	public:
		// Memory operations
		void MaskLoad(const int16_t* mem_addr, const Mask16 mask);
		void MaskStore(int16_t* mem_addr, const Mask16 mask) const;

	public:
		// Compare
		v16int16_t Equal(const v16int16_t& in) const;
		v16int16_t Greater(const v16int16_t& in) const;

	public:
		// Operator overloading
		virtual int16_t operator [](const size_t index) const;

	};
}


