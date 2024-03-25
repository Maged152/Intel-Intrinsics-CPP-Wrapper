#include "vector32_int8.h"
#include "vector32_uint8.h"
#include <cmath>

namespace qlm
{
	/*********************** Constructors ********************************/
	v32int8_t::v32int8_t()
	{}

	v32int8_t::v32int8_t(int8_t value)
	{
		this->Set(value);
	}

	v32int8_t::v32int8_t(int8_t e0, int8_t e1, int8_t e2, int8_t e3, int8_t e4, int8_t e5, int8_t e6, int8_t e7,
		int8_t e8, int8_t e9, int8_t e10, int8_t e11, int8_t e12, int8_t e13, int8_t e14, int8_t e15, 
		int8_t e16, int8_t e17, int8_t e18, int8_t e19, int8_t e20, int8_t e21, int8_t e22, int8_t e23,
		int8_t e24, int8_t e25, int8_t e26, int8_t e27, int8_t e28, int8_t e29, int8_t e30, int8_t e31)
	{
		this->Set(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15,
			e16, e17,  e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31);
	}

	v32int8_t::v32int8_t(const int8_t* mem_addr)
	{
		this->Load(mem_addr);
	}

	/***********************ALU operations********************************/
	v32int8_t v32int8_t::Add(const v32int8_t& in) const
	{
		v32int8_t out;
		out.vec_reg = _mm256_add_epi8(vec_reg, in.vec_reg);
		return out;
	}

	v32int8_t v32int8_t::Sub(const v32int8_t& in) const
	{
		v32int8_t out;
		out.vec_reg = _mm256_sub_epi8(vec_reg, in.vec_reg);
		return out;
	}

	v32int8_t v32int8_t::Div(const v32int8_t& in) const
	{
		v32int8_t out;
		out.vec_reg = _mm256_div_epi8(vec_reg, in.vec_reg);
		return out;
	}

	/*********************** Math functions********************************/
	v32int8_t v32int8_t::Max(const v32int8_t& in) const
	{
		v32int8_t out;
		out.vec_reg = _mm256_max_epi8(vec_reg, in.vec_reg);
		return out;
	}

	v32int8_t v32int8_t::Min(const v32int8_t& in) const
	{
		v32int8_t out;
		out.vec_reg = _mm256_min_epi8(vec_reg, in.vec_reg);
		return out;
	}

	/***********************Memory operations********************************/
	void v32int8_t::Load(const int8_t* mem_addr)
	{
		vec_reg = _mm256_loadu_epi8(mem_addr);
	}

	void v32int8_t::Load(const int8_t* mem_addr, const Mask32 mask)
	{
		v32uint8_t src{ (uint8_t)0 };
		vec_reg = _mm256_mask_loadu_epi8(src.vec_reg, mask.mask, mem_addr);
	}

	void v32int8_t::Store(int8_t* mem_addr) const
	{
		_mm256_storeu_epi8(mem_addr, vec_reg);
	}

	void v32int8_t::Store(int8_t* mem_addr, const Mask32 mask) const
	{
		_mm256_mask_storeu_epi8(mem_addr, mask.mask, vec_reg);
	}

	/*********************** Set ********************************/
	void v32int8_t::Set(int8_t value)
	{
		vec_reg = _mm256_set1_epi8(value);
	}
	void v32int8_t::Set(int8_t e0, int8_t e1, int8_t e2, int8_t e3, int8_t e4, int8_t e5, int8_t e6, int8_t e7,
		int8_t e8, int8_t e9, int8_t e10, int8_t e11, int8_t e12, int8_t e13, int8_t e14, int8_t e15,
		int8_t e16, int8_t e17, int8_t e18, int8_t e19, int8_t e20, int8_t e21, int8_t e22, int8_t e23,
		int8_t e24, int8_t e25, int8_t e26, int8_t e27, int8_t e28, int8_t e29, int8_t e30, int8_t e31)
	{
		vec_reg = _mm256_setr_epi8(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15,
			e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31);
	}

	/*********************** Compare ********************************/
	v32int8_t v32int8_t::Equal(const v32int8_t& in) const
	{
		v32int8_t out;
		out.vec_reg = _mm256_cmpeq_epi8(vec_reg, in.vec_reg);
		return out;
	}

	v32int8_t v32int8_t::Greater(const v32int8_t& in) const
	{
		v32int8_t out;
		out.vec_reg = _mm256_cmpgt_epi8(vec_reg, in.vec_reg);
		return out;
	}

	/***********************Operator overloading********************************/
	int8_t v32int8_t::operator[](const size_t index) const
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


