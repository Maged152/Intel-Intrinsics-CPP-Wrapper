#include "vector8_float.h"
#include <cmath>

namespace qlm
{
	/*********************** Constructors ********************************/
	v8float_t::v8float_t()
	{}

	v8float_t::v8float_t(float value)
	{
		this->Set(value);
	}

	v8float_t::v8float_t(float e0, float e1, float e2, float e3, float e4, float e5, float e6, float e7)
	{
		this->Set(e0, e1, e2, e3, e4, e5, e6, e7);
	}

	v8float_t::v8float_t(const float* mem_addr)
	{
		this->Load(mem_addr);
	}

	/***********************ALU operations********************************/
	v8float_t v8float_t::Add(const v8float_t& in) const
	{
		v8float_t out;
		out.vec_reg = _mm256_add_ps(vec_reg, in.vec_reg);
		return out;
	}

	v8float_t v8float_t::Sub(const v8float_t& in) const
	{
		v8float_t out;
		out.vec_reg = _mm256_sub_ps(vec_reg, in.vec_reg);
		return out;
	}

	v8float_t v8float_t::Mul(const v8float_t& in) const
	{
		v8float_t out;
		out.vec_reg = _mm256_mul_ps(vec_reg, in.vec_reg);
		return out;
	}

	v8float_t v8float_t::Div(const v8float_t& in) const
	{
		v8float_t out;
		out.vec_reg = _mm256_div_ps(vec_reg, in.vec_reg);
		return out;
	}

	/***********************Logical operations********************************/
	v8float_t v8float_t::And(const v8float_t& in) const
	{
		v8float_t out;
		out.vec_reg = _mm256_and_ps(vec_reg, in.vec_reg);
		return out;
	}

	v8float_t v8float_t::Or(const v8float_t& in) const
	{
		v8float_t out;
		out.vec_reg = _mm256_or_ps(vec_reg, in.vec_reg);
		return out;
	}

	v8float_t v8float_t::Xor(const v8float_t& in) const
	{
		v8float_t out;
		out.vec_reg = _mm256_xor_ps(vec_reg, in.vec_reg);
		return out;
	}

	/*********************** Math functions********************************/
	v8float_t v8float_t::Sqrt() const
	{
		v8float_t out;
		out.vec_reg = _mm256_sqrt_ps(vec_reg);
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


	/*********************** Set ********************************/
	void v8float_t::Set(float value)
	{
		vec_reg = _mm256_set1_ps(value);
	}
	void v8float_t::Set(float e0, float e1, float e2, float e3, float e4, float e5, float e6, float e7)
	{
		vec_reg = _mm256_setr_ps(e0, e1, e2, e3, e4, e5, e6, e7);
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


