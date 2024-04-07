#include "vector4_uint64.h"
#include "../../common/scalar.h"

namespace qlm
{
	/*********************** Constructors ********************************/
	v4uint64_t::v4uint64_t()
	{}

	v4uint64_t::v4uint64_t(uint64_t value)
	{
		this->Set(value);
	}

	v4uint64_t::v4uint64_t(uint64_t e0, uint64_t e1, uint64_t e2, uint64_t e3)
	{
		this->Set(e0, e1, e2, e3);
	}

	v4uint64_t::v4uint64_t(const uint64_t* mem_addr)
	{
		this->Load(mem_addr);
	}

	v4uint64_t::v4uint64_t(const Mask4 mask)
	{
		this->Set(mask);
	}

	/***********************ALU operations********************************/
	v4uint64_t v4uint64_t::Add(const v4uint64_t& in) const
	{
		v4uint64_t out;
		out.vec_reg = _mm256_add_epi64(vec_reg, in.vec_reg);
		return out;
	}

	v4uint64_t v4uint64_t::Sub(const v4uint64_t& in) const
	{
		v4uint64_t out;
		out.vec_reg = _mm256_sub_epi64(vec_reg, in.vec_reg);
		return out;
	}

	v4uint64_t v4uint64_t::Div(const v4uint64_t& in) const
	{
		v4uint64_t out;
		out.vec_reg = _mm256_div_epu64(vec_reg, in.vec_reg);
		return out;
	}

	v4uint64_t v4uint64_t::MulLo(const v4uint64_t& in) const
	{
		v4uint64_t out;
		out.vec_reg = _mm256_mul_epu32(vec_reg, in.vec_reg);
		return out;
	}

	/*********************** Math functions********************************/
	v4uint64_t v4uint64_t::Max(const v4uint64_t& in) const
	{
		v4uint64_t out;
		scalar::Max(*this, in, out);
		return out;
	}

	v4uint64_t v4uint64_t::Min(const v4uint64_t& in) const
	{
		v4uint64_t out;
		scalar::Min(*this, in, out);
		return out;
	}

	/***********************Memory operations********************************/

	void v4uint64_t::MaskLoad(const uint64_t* mem_addr, const Mask4 mask)
	{
		const v4uint64_t v_mask{ mask };
		vec_reg = _mm256_maskload_epi64((int64_t*)mem_addr, v_mask.vec_reg);
	}

	void v4uint64_t::MaskStore(uint64_t* mem_addr, const Mask4 mask) const
	{
		const v4uint64_t v_mask{ mask };
		_mm256_maskstore_epi64((int64_t*)mem_addr, v_mask.vec_reg, vec_reg);
	}

	/*********************** Set ********************************/
	void v4uint64_t::Set(uint64_t value)
	{
		vec_reg = _mm256_set1_epi64x(value);
	}

	void v4uint64_t::Set(const uint64_t value, const int index)
	{
#if _MSC_VER && !__INTEL_COMPILER
		vec_reg.m256i_u64[index] = value;
#else
		vec_reg[index] = value;
#endif
	}

	void v4uint64_t::Set(uint64_t e0, uint64_t e1, uint64_t e2, uint64_t e3)
	{
		vec_reg = _mm256_setr_epi64x(e0, e1, e2, e3);
	}

	void v4uint64_t::Set(const Mask4 mask)
	{
		constexpr uint64_t max_val = std::numeric_limits<uint64_t>::max();
		constexpr uint64_t min_val = std::numeric_limits<uint64_t>::min();

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
	v4uint64_t v4uint64_t::Equal(const v4uint64_t& in) const
	{
		v4uint64_t out;
		out.vec_reg = _mm256_cmpeq_epi64(vec_reg, in.vec_reg);
		return out;
	}

	v4uint64_t v4uint64_t::Greater(const v4uint64_t& in) const
	{
		v4uint64_t out;
		scalar::Greater(*this, in, out);
		return out;
	}

	/***********************Operator overloading********************************/
	uint64_t v4uint64_t::operator[](const size_t index) const
	{
		// check if the index is valid
		if (index >= Length())
		{
			return std::nanf("0");
		}
#if _MSC_VER && !__INTEL_COMPILER
		return vec_reg.m256i_u64[index];
#else
		return vec_reg[index];
#endif
	}
}


