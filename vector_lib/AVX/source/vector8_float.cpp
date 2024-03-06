#include "vector8_float.h"
#include <cmath>

namespace qlm
{
	/***********************ALU operations********************************/
	v8float_t& v8float_t::Add(const v8float_t& in) const
	{
		v8float_t out;
		out.vec_reg = _mm256_add_ps(vec_reg, in.vec_reg);
		return out;
	}

	v8float_t& v8float_t::Sub(const v8float_t& in) const
	{
		v8float_t out;
		out.vec_reg = _mm256_sub_ps(vec_reg, in.vec_reg);
		return out;
	}

	v8float_t& v8float_t::Mul(const v8float_t& in) const
	{
		v8float_t out;
		out.vec_reg = _mm256_mul_ps(vec_reg, in.vec_reg);
		return out;
	}

	v8float_t& v8float_t::Div(const v8float_t& in) const
	{
		v8float_t out;
		out.vec_reg = _mm256_div_ps(vec_reg, in.vec_reg);
		return out;
	}

	/***********************Logical operations********************************/
	v8float_t& v8float_t::And(const v8float_t& in) const
	{
		v8float_t out;
		out.vec_reg = _mm256_and_ps(vec_reg, in.vec_reg);
		return out;
	}

	v8float_t& v8float_t::Or(const v8float_t& in) const
	{
		v8float_t out;
		out.vec_reg = _mm256_or_ps(vec_reg, in.vec_reg);
		return out;
	}

	v8float_t& v8float_t::Xor(const v8float_t& in) const
	{
		v8float_t out;
		out.vec_reg = _mm256_xor_ps(vec_reg, in.vec_reg);
		return out;
	}

	/***********************Memory operations********************************/
	void v8float_t::Load(const float* mem_addr)
	{
		vec_reg = _mm256_loadu_ps(mem_addr);
	}

	void v8float_t::Store(float* mem_addr) const
	{
		_mm256_storeu_ps(mem_addr, vec_reg);
	}

	/***********************Operator overloading********************************/
	float v8float_t::operator[](const size_t index) const
	{
		// check if the index is valid
		if (index >= Length())
		{
			return std::nanf("0");
		}
#if defined(_WIN32)
		return vec_reg.m256_f32[index];
#else
		return vec_reg[index];
#endif
	}
}


