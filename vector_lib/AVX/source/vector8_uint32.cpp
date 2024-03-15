#include "vector8_uint32.h"
#include <cmath>

namespace qlm
{
	/*********************** Constructors ********************************/
	v8uint32_t::v8uint32_t()
	{}

	v8uint32_t::v8uint32_t(uint32_t value)
	{
		this->Set(value);
	}

	v8uint32_t::v8uint32_t(uint32_t e0, uint32_t e1, uint32_t e2, uint32_t e3, uint32_t e4, uint32_t e5, uint32_t e6, uint32_t e7)
	{
		this->Set(e0, e1, e2, e3, e4, e5, e6, e7);
	}

	v8uint32_t::v8uint32_t(const uint32_t* mem_addr)
	{
		this->Load(mem_addr);
	}

	/***********************ALU operations********************************/
	v8uint32_t v8uint32_t::Add(const v8uint32_t& in) const
	{
		v8uint32_t out;
		out.vec_reg = _mm256_add_epi32(vec_reg, in.vec_reg);
		return out;
	}

	v8uint32_t v8uint32_t::Sub(const v8uint32_t& in) const
	{
		v8uint32_t out;
		out.vec_reg = _mm256_sub_epi32(vec_reg, in.vec_reg);
		return out;
	}

	v8uint32_t v8uint32_t::MulLo(const v8uint32_t& in) const
	{
		v8uint32_t out;
		out.vec_reg = _mm256_mullo_epi32(vec_reg, in.vec_reg);
		return out;
	}

	v8uint32_t v8uint32_t::Div(const v8uint32_t& in) const
	{
		v8uint32_t out;
		out.vec_reg = _mm256_div_epu32(vec_reg, in.vec_reg);
		return out;
	}

	/***********************Logical operations********************************/
	v8uint32_t v8uint32_t::And(const v8uint32_t& in) const
	{
		v8uint32_t out;
		out.vec_reg = _mm256_and_si256(vec_reg, in.vec_reg);
		return out;
	}

	v8uint32_t v8uint32_t::Or(const v8uint32_t& in) const
	{
		v8uint32_t out;
		out.vec_reg = _mm256_or_si256(vec_reg, in.vec_reg);
		return out;
	}

	v8uint32_t v8uint32_t::Xor(const v8uint32_t& in) const
	{
		v8uint32_t out;
		out.vec_reg = _mm256_xor_si256(vec_reg, in.vec_reg);
		return out;
	}

	/*********************** Math functions********************************/
	v8uint32_t v8uint32_t::Max(const v8uint32_t& in) const
	{
		v8uint32_t out;
		out.vec_reg = _mm256_max_epu32(vec_reg, in.vec_reg);
		return out;
	}

	v8uint32_t v8uint32_t::Min(const v8uint32_t& in) const
	{
		v8uint32_t out;
		out.vec_reg = _mm256_min_epu32(vec_reg, in.vec_reg);
		return out;
	}

	/***********************Memory operations********************************/
	void v8uint32_t::Load(const uint32_t* mem_addr)
	{
		vec_reg = _mm256_loadu_epi32(mem_addr);
	}

	void v8uint32_t::Store(uint32_t* mem_addr) const
	{
		_mm256_storeu_epi32(mem_addr, vec_reg);
	}


	/*********************** Set ********************************/
	void v8uint32_t::Set(uint32_t value)
	{
		vec_reg = _mm256_set1_epi32(value);
	}
	void v8uint32_t::Set(uint32_t e0, uint32_t e1, uint32_t e2, uint32_t e3, uint32_t e4, uint32_t e5, uint32_t e6, uint32_t e7)
	{
		vec_reg = _mm256_setr_epi32(e0, e1, e2, e3, e4, e5, e6, e7);
	}

	/*********************** Compare ********************************/
	v8uint32_t v8uint32_t::Equal(const v8uint32_t& in) const
	{
		v8uint32_t out;
		out.vec_reg = _mm256_cmpeq_epi32(vec_reg, in.vec_reg);
		return out;
	}

	v8uint32_t v8uint32_t::Greater(const v8uint32_t& in) const
	{
		v8uint32_t out;
		out.vec_reg = _mm256_movm_epi32(_mm256_cmpgt_epu32_mask(vec_reg, in.vec_reg));
		return out;
	}


	/***********************Operator overloading********************************/
	uint32_t v8uint32_t::operator[](const size_t index) const
	{
		// check if the index is valid
		if (index >= Length())
		{
			return std::nanf("0");
		}
#if defined(_WIN32)
		return vec_reg.m256i_u32[index];
#else
		return vec_reg[index];
#endif
	}
}
