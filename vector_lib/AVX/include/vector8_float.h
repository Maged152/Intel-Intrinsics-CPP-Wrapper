#pragma once

#include "../../common/vector_common.h"

namespace qlm
{
	class v8float_t : public Vector<float, v8float_t>
	{
	public:
		__m256 vec_reg;

	public:
		// Constructors
		v8float_t();
		v8float_t(float value);
		v8float_t(float e0, float e1, float e2, float e3, float e4, float e5, float e6, float e7);
		v8float_t(const float* mem_addr);

	public:
		// ALU operations
		virtual v8float_t Add(const v8float_t& in) const override;
		virtual v8float_t Sub(const v8float_t& in) const override;
		v8float_t Mul(const v8float_t& in) const;
		virtual v8float_t Div(const v8float_t& in) const override;

	public:
		// Logical operators
		virtual v8float_t Or(const v8float_t& in) const override;
		virtual v8float_t And(const v8float_t& in) const override;
		virtual v8float_t Xor(const v8float_t& in) const override;

	public:
		// Math functions
		v8float_t Sqrt() const;
		virtual v8float_t Max(const v8float_t& in) const override;
		virtual v8float_t Min(const v8float_t& in) const override;
		v8float_t Ceil() const;
		v8float_t Floor() const;
		template<RoundMode round>
		v8float_t Round() const
		{
			v8float_t out;
			out.vec_reg = _mm256_round_ps(vec_reg, static_cast<int>(round));
			return out;
		}

	public:
		// Set 
		void Set(float value);
		void Set(float e0, float e1, float e2, float e3, float e4, float e5, float e6, float e7);

	public:
		// Memory operations
		virtual void Load(const float* mem_addr) override;
		virtual void Store(float* mem_addr) const override;

	public:
		// Compare
		template<CompareMode comp>
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


