#pragma once

#include "../../common/vector_common.h"

namespace qlm
{
	class v8float_t : public Vector<float, v8float_t>
	{
	public:
		__m256 vec_reg;

	public:
		// ALU operations
		virtual v8float_t& Add(const v8float_t& in) const override;
		virtual v8float_t& Sub(const v8float_t& in) const override;
		virtual v8float_t& Mul(const v8float_t& in) const override;
		virtual v8float_t& Div(const v8float_t& in) const override;

	public:
		// Logical operators
		virtual v8float_t& Or(const v8float_t& in) const override;
		virtual v8float_t& And(const v8float_t& in) const override;
		virtual v8float_t& Xor(const v8float_t& in) const override;

	public:
		// Math functions
		virtual v8float_t& Sqrt() const override;

	public:
		// Memory operations
		virtual void Load(const float* mem_addr) override;
		virtual void Store(float* mem_addr) const override;

	public:
		// Compare
		template<Compare_t comp>
		v8float_t& Compare(const v8float_t& in) const
		{
			v8float_t out;
			out.vec_reg = _mm256_cmp_ps(vec_reg, in.vec_reg, static_cast<int>(comp));
			return out;
		}

	public:
		// Operator overloading
		virtual float operator [](const size_t index) const;

	};
}


