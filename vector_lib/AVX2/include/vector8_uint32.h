#pragma once

#include "../../common/vector_common.h"

namespace qlm
{
	class v8uint32_t : public Vector<uint32_t, v8uint32_t>
	{
	public:
		__m256i vec_reg;

	public:
		// Constructors
		v8uint32_t();
		v8uint32_t(uint32_t value);
		v8uint32_t(uint32_t e0, uint32_t e1, uint32_t e2, uint32_t e3, uint32_t e4, uint32_t e5, uint32_t e6, uint32_t e7);
		v8uint32_t(const uint32_t* mem_addr);

	public:
		// ALU operations
		virtual v8uint32_t Add(const v8uint32_t& in) const override;
		virtual v8uint32_t Sub(const v8uint32_t& in) const override;
		virtual v8uint32_t Mul(const v8uint32_t& in) const override;
		virtual v8uint32_t Div(const v8uint32_t& in) const override;

	public:
		// Logical operators
		virtual v8uint32_t Or(const v8uint32_t& in) const override;
		virtual v8uint32_t And(const v8uint32_t& in) const override;
		virtual v8uint32_t Xor(const v8uint32_t& in) const override;

	public:
		// Math functions
		virtual v8uint32_t Max(const v8uint32_t& in) const override;
		virtual v8uint32_t Min(const v8uint32_t& in) const override;

	public:
		// Set 
		void Set(uint32_t value);
		void Set(uint32_t e0, uint32_t e1, uint32_t e2, uint32_t e3, uint32_t e4, uint32_t e5, uint32_t e6, uint32_t e7);

	public:
		// Memory operations
		virtual void Load(const uint32_t* mem_addr) override;
		virtual void Store(uint32_t* mem_addr) const override;

	public:
		// Compare
		v8uint32_t Equal(const v8uint32_t& in) const;
		v8uint32_t Greater(const v8uint32_t& in) const;

	public:
		// Operator overloading
		virtual uint32_t operator [](const size_t index) const;

	};
}


