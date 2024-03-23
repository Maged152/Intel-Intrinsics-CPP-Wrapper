#pragma once

#include "vector256_int.h"

namespace qlm
{
	class v32uint8_t : public v256int_t<uint8_t, v32uint8_t>
	{
	public:
		// Constructors
		v32uint8_t();
		v32uint8_t(uint8_t value);
		v32uint8_t(uint8_t e0, uint8_t e1, uint8_t e2, uint8_t e3, uint8_t e4, uint8_t e5, uint8_t e6, uint8_t e7,
			uint8_t e8, uint8_t e9, uint8_t e10, uint8_t e11, uint8_t e12, uint8_t e13, uint8_t e14, uint8_t e15,
			uint8_t e16, uint8_t e17, uint8_t e18, uint8_t e19, uint8_t e20, uint8_t e21, uint8_t e22, uint8_t e23,
			uint8_t e24, uint8_t e25, uint8_t e26, uint8_t e27, uint8_t e28, uint8_t e29, uint8_t e30, uint8_t e31);
		v32uint8_t(const uint8_t* mem_addr);
		v32uint8_t(const Mask32 mask);

	public:
		// ALU operations
		virtual v32uint8_t Add(const v32uint8_t& in) const override;
		virtual v32uint8_t Sub(const v32uint8_t& in) const override;
		v32uint8_t MulLo(const v32uint8_t& in) const;
		virtual v32uint8_t Div(const v32uint8_t& in) const override;

	public:
		// Math functions
		virtual v32uint8_t Max(const v32uint8_t& in) const override;
		virtual v32uint8_t Min(const v32uint8_t& in) const override;

	public:
		// Set 
		void Set(const uint8_t value);
		void Set(const uint8_t value, const int index);
		void Set(uint8_t e0, uint8_t e1, uint8_t e2, uint8_t e3, uint8_t e4, uint8_t e5, uint8_t e6, uint8_t e7,
			uint8_t e8, uint8_t e9, uint8_t e10, uint8_t e11, uint8_t e12, uint8_t e13, uint8_t e14, uint8_t e15,
			uint8_t e16, uint8_t e17, uint8_t e18, uint8_t e19, uint8_t e20, uint8_t e21, uint8_t e22, uint8_t e23,
			uint8_t e24, uint8_t e25, uint8_t e26, uint8_t e27, uint8_t e28, uint8_t e29, uint8_t e30, uint8_t e31);

		void Set(const Mask32 mask);
	public:
		// Memory operations
		virtual void Load(const uint8_t* mem_addr) override;
		virtual void Store(uint8_t* mem_addr) const override;

	public:
		// Compare
		v32uint8_t Equal(const v32uint8_t& in) const;
		v32uint8_t Greater(const v32uint8_t& in) const;

	public:
		// Operator overloading
		virtual uint8_t operator [](const size_t index) const;
	};
}
