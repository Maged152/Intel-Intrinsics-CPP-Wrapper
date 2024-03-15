#pragma once

#include "../../common/vector_common.h"

namespace qlm
{
	template<typename d_t, typename vec_t>
	class vint_t : public Vector<d_t, vec_t>
	{
	public:
		__m256i vec_reg;

	public:
		// Logical operators
		virtual vec_t Or(const vec_t& in) const override
		{
			vec_t out;
			out.vec_reg = _mm256_or_si256(vec_reg, in.vec_reg);
			return out;
		}

		virtual vec_t And(const vec_t& in) const override
		{
			vec_t out;
			out.vec_reg = _mm256_and_si256(vec_reg, in.vec_reg);
			return out;
		}

		virtual vec_t Xor(const vec_t& in) const override
		{
			vec_t out;
			out.vec_reg = _mm256_xor_si256(vec_reg, in.vec_reg);
			return out;
		}

	};
}