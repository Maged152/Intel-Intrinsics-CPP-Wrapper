#include "vector32_uint8.h"
#include <cmath>

namespace qlm
{
	/*********************** Constructors ********************************/
	v32uint8_t::v32uint8_t()
	{}

	v32uint8_t::v32uint8_t(uint8_t value)
	{
		this->Set(value);
	}

	v32uint8_t::v32uint8_t(uint8_t e0, uint8_t e1, uint8_t e2, uint8_t e3, uint8_t e4, uint8_t e5, uint8_t e6, uint8_t e7,
		uint8_t e8, uint8_t e9, uint8_t e10, uint8_t e11, uint8_t e12, uint8_t e13, uint8_t e14, uint8_t e15,
		uint8_t e16, uint8_t e17, uint8_t e18, uint8_t e19, uint8_t e20, uint8_t e21, uint8_t e22, uint8_t e23,
		uint8_t e24, uint8_t e25, uint8_t e26, uint8_t e27, uint8_t e28, uint8_t e29, uint8_t e30, uint8_t e31)
	{
		this->Set(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15,
			e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31);
	}

	v32uint8_t::v32uint8_t(const uint8_t* mem_addr)
	{
		this->Load(mem_addr);
	}

	/***********************ALU operations********************************/
	v32uint8_t v32uint8_t::Add(const v32uint8_t& in) const
	{
		v32uint8_t out;
		out.vec_reg = _mm256_add_epi8(vec_reg, in.vec_reg);
		return out;
	}

	v32uint8_t v32uint8_t::Sub(const v32uint8_t& in) const
	{
		v32uint8_t out;
		out.vec_reg = _mm256_sub_epi8(vec_reg, in.vec_reg);
		return out;
	}

	v32uint8_t v32uint8_t::Div(const v32uint8_t& in) const
	{
		v32uint8_t out;
		out.vec_reg = _mm256_div_epu8(vec_reg, in.vec_reg);
		return out;
	}

	/*********************** Math functions********************************/
	v32uint8_t v32uint8_t::Max(const v32uint8_t& in) const
	{
		v32uint8_t out;
		out.vec_reg = _mm256_max_epu8(vec_reg, in.vec_reg);
		return out;
	}

	v32uint8_t v32uint8_t::Min(const v32uint8_t& in) const
	{
		v32uint8_t out;
		out.vec_reg = _mm256_min_epu8(vec_reg, in.vec_reg);
		return out;
	}

	/***********************Memory operations********************************/
	void v32uint8_t::Load(const uint8_t* mem_addr)
	{
		vec_reg = _mm256_loadu_epi8(mem_addr);
	}

	void v32uint8_t::Store(uint8_t* mem_addr) const
	{
		_mm256_storeu_epi8(mem_addr, vec_reg);
	}

	/*********************** Set ********************************/
	void v32uint8_t::Set(uint8_t value)
	{
		vec_reg = _mm256_set1_epi8(value);
	}
	void v32uint8_t::Set(uint8_t e0, uint8_t e1, uint8_t e2, uint8_t e3, uint8_t e4, uint8_t e5, uint8_t e6, uint8_t e7,
		uint8_t e8, uint8_t e9, uint8_t e10, uint8_t e11, uint8_t e12, uint8_t e13, uint8_t e14, uint8_t e15,
		uint8_t e16, uint8_t e17, uint8_t e18, uint8_t e19, uint8_t e20, uint8_t e21, uint8_t e22, uint8_t e23,
		uint8_t e24, uint8_t e25, uint8_t e26, uint8_t e27, uint8_t e28, uint8_t e29, uint8_t e30, uint8_t e31)
	{
		vec_reg = _mm256_setr_epi8(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15,
			e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31);
	}

	/*********************** Compare ********************************/
	v32uint8_t v32uint8_t::Equal(const v32uint8_t& in) const
	{
		v32uint8_t out;
		out.vec_reg = _mm256_cmpeq_epi8(vec_reg, in.vec_reg);
		return out;
	}

	v32uint8_t v32uint8_t::Greater(const v32uint8_t& in) const
	{
		v32uint8_t out;
		out.vec_reg = _mm256_movm_epi8(_mm256_cmpgt_epu8_mask(vec_reg, in.vec_reg));
		return out;
	}

	/***********************Operator overloading********************************/
	uint8_t v32uint8_t::operator[](const size_t index) const
	{
		// check if the index is valid
		if (index >= Length())
		{
			return std::nanf("0");
		}
#if defined(_WIN32)
		return vec_reg.m256i_i32[index];
#else
		return vec_reg[index];
#endif
	}
}


