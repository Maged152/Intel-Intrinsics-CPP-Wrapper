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

	v8uint32_t::v8uint32_t(const Mask8 mask)
	{
		this->Set(mask);
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
	void v8uint32_t::MaskLoad(const uint32_t* mem_addr, const Mask8 mask)
	{
		const v8uint32_t v_mask{ mask };
		vec_reg = _mm256_maskload_epi32((int32_t*)mem_addr, v_mask.vec_reg);
	}


	void v8uint32_t::MaskStore(uint32_t* mem_addr, const Mask8 mask) const
	{
		const v8uint32_t v_mask{ mask };
		_mm256_maskstore_epi32((int32_t*)mem_addr, v_mask.vec_reg, vec_reg);
	}

	/*********************** Set ********************************/
	void v8uint32_t::Set(uint32_t value)
	{
		vec_reg = _mm256_set1_epi32(value);
	}

	void v8uint32_t::Set(const uint32_t value, const int index)
	{
#if _MSC_VER && !__INTEL_COMPILER
		vec_reg.m256i_u32[index] = value;
#else
		vec_reg[index] = value;
#endif
	}

	void v8uint32_t::Set(uint32_t e0, uint32_t e1, uint32_t e2, uint32_t e3, uint32_t e4, uint32_t e5, uint32_t e6, uint32_t e7)
	{
		vec_reg = _mm256_setr_epi32(e0, e1, e2, e3, e4, e5, e6, e7);
	}

	void v8uint32_t::Set(const Mask8 mask)
	{
		constexpr uint32_t max_val = std::numeric_limits<uint32_t>::max();
		constexpr uint32_t min_val = std::numeric_limits<uint32_t>::min();

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
#if _MSC_VER && !__INTEL_COMPILER
		return vec_reg.m256i_u32[index];
#else
		return vec_reg[index];
#endif
	}
}
