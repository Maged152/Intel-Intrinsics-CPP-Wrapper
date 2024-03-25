#include "vector16_int16.h"
#include "vector16_uint16.h"
#include <cmath>

namespace qlm
{
	/*********************** Constructors ********************************/
	v16int16_t::v16int16_t()
	{}

	v16int16_t::v16int16_t(int16_t value)
	{
		this->Set(value);
	}

	v16int16_t::v16int16_t(int16_t e0, int16_t e1, int16_t e2, int16_t e3, int16_t e4, int16_t e5, int16_t e6, int16_t e7,
		                   int16_t e8, int16_t e9, int16_t e10, int16_t e11, int16_t e12, int16_t e13, int16_t e14, int16_t e15)
	{
		this->Set(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15);
	}

	v16int16_t::v16int16_t(const int16_t* mem_addr)
	{
		this->Load(mem_addr);
	}

	/***********************ALU operations********************************/
	v16int16_t v16int16_t::Add(const v16int16_t& in) const
	{
		v16int16_t out;
		out.vec_reg = _mm256_add_epi16(vec_reg, in.vec_reg);
		return out;
	}

	v16int16_t v16int16_t::Sub(const v16int16_t& in) const
	{
		v16int16_t out;
		out.vec_reg = _mm256_sub_epi16(vec_reg, in.vec_reg);
		return out;
	}

	v16int16_t v16int16_t::MulLo(const v16int16_t& in) const
	{
		v16int16_t out;
		out.vec_reg = _mm256_mullo_epi16(vec_reg, in.vec_reg);
		return out;
	}

	v16int16_t v16int16_t::Div(const v16int16_t& in) const
	{
		v16int16_t out;
		out.vec_reg = _mm256_div_epi16(vec_reg, in.vec_reg);
		return out;
	}

	/*********************** Math functions********************************/
	v16int16_t v16int16_t::Max(const v16int16_t& in) const
	{
		v16int16_t out;
		out.vec_reg = _mm256_max_epi16(vec_reg, in.vec_reg);
		return out;
	}

	v16int16_t v16int16_t::Min(const v16int16_t& in) const
	{
		v16int16_t out;
		out.vec_reg = _mm256_min_epi16(vec_reg, in.vec_reg);
		return out;
	}

	/***********************Memory operations********************************/
	void v16int16_t::Load(const int16_t* mem_addr)
	{
		vec_reg = _mm256_loadu_epi16(mem_addr);
	}

	void v16int16_t::Load(const int16_t* mem_addr, const Mask16 mask)
	{
		v16uint16_t src{ (uint16_t)0 };
		vec_reg = _mm256_mask_loadu_epi16(src.vec_reg, mask.mask, mem_addr);
	}

	void v16int16_t::Store(int16_t* mem_addr) const
	{
		_mm256_storeu_epi16(mem_addr, vec_reg);
	}

	void v16int16_t::Store(int16_t* mem_addr, const Mask16 mask) const
	{
		_mm256_mask_storeu_epi16(mem_addr, mask.mask, vec_reg);
	}

	/*********************** Set ********************************/
	void v16int16_t::Set(int16_t value)
	{
		vec_reg = _mm256_set1_epi16(value);
	}
	void v16int16_t::Set(int16_t e0, int16_t e1, int16_t e2, int16_t e3, int16_t e4, int16_t e5, int16_t e6, int16_t e7,
		                 int16_t e8, int16_t e9, int16_t e10, int16_t e11, int16_t e12, int16_t e13, int16_t e14, int16_t e15)
	{
		vec_reg = _mm256_setr_epi16(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15);
	}

	/*********************** Compare ********************************/
	v16int16_t v16int16_t::Equal(const v16int16_t& in) const
	{
		v16int16_t out;
		out.vec_reg = _mm256_cmpeq_epi16(vec_reg, in.vec_reg);
		return out;
	}

	v16int16_t v16int16_t::Greater(const v16int16_t& in) const
	{
		v16int16_t out;
		out.vec_reg = _mm256_cmpgt_epi16(vec_reg, in.vec_reg);
		return out;
	}

	/***********************Operator overloading********************************/
	int16_t v16int16_t::operator[](const size_t index) const
	{
		// check if the index is valid
		if (index >= Length())
		{
			return std::nanf("0");
		}
#if _MSC_VER && !__INTEL_COMPILER
		return vec_reg.m256i_i32[index];
#else
		return vec_reg[index];
#endif
	}
}


