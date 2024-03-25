#pragma once

#include "vector256_int.h"

namespace qlm
{
	class v16uint16_t : public v256int_t<uint16_t, v16uint16_t>
	{
	public:
		// Constructors
		v16uint16_t();
		v16uint16_t(uint16_t value);
		v16uint16_t(uint16_t e0, uint16_t e1, uint16_t e2, uint16_t e3, uint16_t e4, uint16_t e5, uint16_t e6, uint16_t e7,
			        uint16_t e8, uint16_t e9, uint16_t e10, uint16_t e11, uint16_t e12, uint16_t e13, uint16_t e14, uint16_t e15);
		v16uint16_t(const uint16_t* mem_addr);
		v16uint16_t(const Mask16 mask);

	public:
		// ALU operations
		virtual v16uint16_t Add(const v16uint16_t& in) const override;
		virtual v16uint16_t Sub(const v16uint16_t& in) const override;
		v16uint16_t MulLo(const v16uint16_t& in) const;
		virtual v16uint16_t Div(const v16uint16_t& in) const override;

	public:
		// Math functions
		virtual v16uint16_t Max(const v16uint16_t& in) const override;
		virtual v16uint16_t Min(const v16uint16_t& in) const override;

	public:
		// Set 
		void Set(uint16_t value);
		void Set(const uint16_t value, const int index);
		void Set(uint16_t e0, uint16_t e1, uint16_t e2, uint16_t e3, uint16_t e4, uint16_t e5, uint16_t e6, uint16_t e7,
			     uint16_t e8, uint16_t e9, uint16_t e10, uint16_t e11, uint16_t e12, uint16_t e13, uint16_t e14, uint16_t e15);
		void Set(const Mask16 mask);
	
	public:
		// Memory operations
		virtual void Load(const uint16_t* mem_addr) override;
		void Load(const uint16_t* mem_addr, const Mask16 mask);

		virtual void Store(uint16_t* mem_addr) const override;
		void Store(uint16_t* mem_addr, const Mask16 mask) const;

	public:
		// Compare
		v16uint16_t Equal(const v16uint16_t& in) const;
		v16uint16_t Greater(const v16uint16_t& in) const;

	public:
		// Operator overloading
		virtual uint16_t operator [](const size_t index) const;

	};
}


