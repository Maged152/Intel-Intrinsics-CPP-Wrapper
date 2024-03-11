#pragma once

#include "../../common/vector_common.h"

namespace qlm
{
	class v8int32_t : public Vector<int32_t, v8int32_t>
	{
	public:
		__m256i vec_reg;

	public:
		// Constructors
		v8int32_t();
		v8int32_t(int32_t value);
		v8int32_t(int32_t e0, int32_t e1, int32_t e2, int32_t e3, int32_t e4, int32_t e5, int32_t e6, int32_t e7);
		v8int32_t(const int32_t* mem_addr);

	public:
		// ALU operations
		virtual v8int32_t Add(const v8int32_t& in) const override;
		virtual v8int32_t Sub(const v8int32_t& in) const override;
		virtual v8int32_t Mul(const v8int32_t& in) const override;
		virtual v8int32_t Div(const v8int32_t& in) const override;

	public:
		// Logical operators
		virtual v8int32_t Or(const v8int32_t& in) const override;
		virtual v8int32_t And(const v8int32_t& in) const override;
		virtual v8int32_t Xor(const v8int32_t& in) const override;

	public:
		// Math functions
		virtual v8int32_t Max(const v8int32_t& in) const override;
		virtual v8int32_t Min(const v8int32_t& in) const override;

	public:
		// Set 
		void Set(int32_t value);
		void Set(int32_t e0, int32_t e1, int32_t e2, int32_t e3, int32_t e4, int32_t e5, int32_t e6, int32_t e7);

	public:
		// Memory operations
		virtual void Load(const int32_t* mem_addr) override;
		virtual void Store(int32_t* mem_addr) const override;

	public:
		// Compare
		v8int32_t& Equal(const v8int32_t& in) const;
		v8int32_t& Greater(const v8int32_t& in) const;

	public:
		// Operator overloading
		virtual int32_t operator [](const size_t index) const;

	};
}


