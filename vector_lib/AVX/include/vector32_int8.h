#pragma once

#include "vector256_int.h"

namespace qlm
{
	class v32int8_t : public v256int_t<int8_t, v32int8_t>
	{
	public:
		// Constructors
		v32int8_t();
		v32int8_t(int8_t value);
		v32int8_t(int8_t e0, int8_t e1, int8_t e2, int8_t e3, int8_t e4, int8_t e5, int8_t e6, int8_t e7,
			int8_t e8, int8_t e9, int8_t e10, int8_t e11, int8_t e12, int8_t e13, int8_t e14, int8_t e15,
			int8_t e16, int8_t e17, int8_t e18, int8_t e19, int8_t e20, int8_t e21, int8_t e22, int8_t e23,
			int8_t e24, int8_t e25, int8_t e26, int8_t e27, int8_t e28, int8_t e29, int8_t e30, int8_t e31);
		v32int8_t(const int8_t* mem_addr);

	public:
		// ALU operations
		virtual v32int8_t Add(const v32int8_t& in) const override;
		virtual v32int8_t Sub(const v32int8_t& in) const override;
		v32int8_t MulLo(const v32int8_t& in) const;
		virtual v32int8_t Div(const v32int8_t& in) const override;

	public:
		// Math functions
		virtual v32int8_t Max(const v32int8_t& in) const override;
		virtual v32int8_t Min(const v32int8_t& in) const override;

	public:
		// Set 
		void Set(int8_t value);
		void Set(int8_t e0, int8_t e1, int8_t e2, int8_t e3, int8_t e4, int8_t e5, int8_t e6, int8_t e7,
			int8_t e8, int8_t e9, int8_t e10, int8_t e11, int8_t e12, int8_t e13, int8_t e14, int8_t e15,
			int8_t e16, int8_t e17, int8_t e18, int8_t e19, int8_t e20, int8_t e21, int8_t e22, int8_t e23,
			int8_t e24, int8_t e25, int8_t e26, int8_t e27, int8_t e28, int8_t e29, int8_t e30, int8_t e31);

	public:
		// Memory operations
		virtual void Load(const int8_t* mem_addr) override;
		virtual void Store(int8_t* mem_addr) const override;

		static v32int8_t GetMask(const int8_t num_elements);

	public:
		// Compare
		v32int8_t Equal(const v32int8_t& in) const;
		v32int8_t Greater(const v32int8_t& in) const;

	public:
		// Operator overloading
		virtual int8_t operator [](const size_t index) const;

	};
}
