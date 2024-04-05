#include "vector16_uint16.h"
#include <cmath>

namespace qlm
{
	/*********************** Constructors ********************************/
	v16uint16_t::v16uint16_t()
	{}

	v16uint16_t::v16uint16_t(uint16_t value)
	{
		this->Set(value);
	}

	v16uint16_t::v16uint16_t(uint16_t e0, uint16_t e1, uint16_t e2, uint16_t e3, uint16_t e4, uint16_t e5, uint16_t e6, uint16_t e7,
		uint16_t e8, uint16_t e9, uint16_t e10, uint16_t e11, uint16_t e12, uint16_t e13, uint16_t e14, uint16_t e15)
	{
		this->Set(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15);
	}

	v16uint16_t::v16uint16_t(const uint16_t* mem_addr)
	{
		this->Load(mem_addr);
	}

	v16uint16_t::v16uint16_t(const Mask16 mask)
	{
		this->Set(mask);
	}

	/***********************ALU operations********************************/
	v16uint16_t v16uint16_t::Add(const v16uint16_t& in) const
	{
		v16uint16_t out;
		out.vec_reg = _mm256_add_epi16(vec_reg, in.vec_reg);
		return out;
	}

	v16uint16_t v16uint16_t::Sub(const v16uint16_t& in) const
	{
		v16uint16_t out;
		out.vec_reg = _mm256_sub_epi16(vec_reg, in.vec_reg);
		return out;
	}

	v16uint16_t v16uint16_t::MulLo(const v16uint16_t& in) const
	{
		v16uint16_t out;
		out.vec_reg = _mm256_mullo_epi16(vec_reg, in.vec_reg);
		return out;
	}

	v16uint16_t v16uint16_t::Div(const v16uint16_t& in) const
	{
		v16uint16_t out;
		out.vec_reg = _mm256_div_epu16(vec_reg, in.vec_reg);
		return out;
	}

	/*********************** Math functions********************************/
	v16uint16_t v16uint16_t::Max(const v16uint16_t& in) const
	{
		v16uint16_t out;
		out.vec_reg = _mm256_max_epu16(vec_reg, in.vec_reg);
		return out;
	}

	v16uint16_t v16uint16_t::Min(const v16uint16_t& in) const
	{
		v16uint16_t out;
		out.vec_reg = _mm256_min_epu16(vec_reg, in.vec_reg);
		return out;
	}

	/***********************Memory operations********************************/
	void v16uint16_t::MaskLoad(const uint16_t* mem_addr, const Mask16 mask)
	{
		v16uint16_t src{ (uint16_t)0 };
		vec_reg = _mm256_mask_loadu_epi16(src.vec_reg, mask.mask, mem_addr);
	}

	void v16uint16_t::MaskStore(uint16_t* mem_addr, const Mask16 mask) const
	{
		_mm256_mask_storeu_epi16(mem_addr, mask.mask, vec_reg);
	}

	/*********************** Set ********************************/
	void v16uint16_t::Set(uint16_t value)
	{
		vec_reg = _mm256_set1_epi16(value);
	}

	void v16uint16_t::Set(const uint16_t value, const int index)
	{
#if _MSC_VER && !__INTEL_COMPILER
		vec_reg.m256i_i32[index] = value;
#else
		vec_reg[index] = value;
#endif
	}

	void v16uint16_t::Set(uint16_t e0, uint16_t e1, uint16_t e2, uint16_t e3, uint16_t e4, uint16_t e5, uint16_t e6, uint16_t e7,
		uint16_t e8, uint16_t e9, uint16_t e10, uint16_t e11, uint16_t e12, uint16_t e13, uint16_t e14, uint16_t e15)
	{
		vec_reg = _mm256_setr_epi16(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15);
	}

	void v16uint16_t::Set(const Mask16 mask)
	{
		constexpr uint16_t max_val = std::numeric_limits<uint16_t>::max();
		constexpr uint16_t min_val = std::numeric_limits<uint16_t>::min();

		for (int i = 0; i < mask.Size(); i++)
		{
			if (mask[i])
			{
				Set(max_val, mask.Size() - i - 1);
			}
			else
			{
				Set(min_val, mask.Size() - i - 1);
			}
		}
	}

	/*********************** Compare ********************************/
	v16uint16_t v16uint16_t::Equal(const v16uint16_t& in) const
	{
		v16uint16_t out;
		out.vec_reg = _mm256_cmpeq_epi16(vec_reg, in.vec_reg);
		return out;
	}

	v16uint16_t v16uint16_t::Greater(const v16uint16_t& in) const
	{
		v16uint16_t out;
		out.vec_reg = _mm256_movm_epi16(_mm256_cmpgt_epu16_mask(vec_reg, in.vec_reg));
		return out;
	}

	/***********************Operator overloading********************************/
	uint16_t v16uint16_t::operator[](const size_t index) const
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


