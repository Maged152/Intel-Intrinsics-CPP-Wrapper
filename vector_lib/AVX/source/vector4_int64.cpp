#include "vector4_int64.h"
#include "vector4_uint64.h"
#include "../../common/scalar.h"

namespace qlm
{
	/*********************** Constructors ********************************/
	v4int64_t::v4int64_t()
	{}

	v4int64_t::v4int64_t(int64_t value)
	{
		this->Set(value);
	}

	v4int64_t::v4int64_t(int64_t e0, int64_t e1, int64_t e2, int64_t e3)
	{
		this->Set(e0, e1, e2, e3);
	}

	v4int64_t::v4int64_t(const int64_t* mem_addr)
	{
		this->Load(mem_addr);
	}

	/***********************ALU operations********************************/
	v4int64_t v4int64_t::Add(const v4int64_t& in) const
	{
		v4int64_t out;
		out.vec_reg = _mm256_add_epi64(vec_reg, in.vec_reg);
		return out;
	}

	v4int64_t v4int64_t::Sub(const v4int64_t& in) const
	{
		v4int64_t out;
		out.vec_reg = _mm256_sub_epi64(vec_reg, in.vec_reg);
		return out;
	}

	v4int64_t v4int64_t::Div(const v4int64_t& in) const
	{
		v4int64_t out;
		out.vec_reg = _mm256_div_epi64(vec_reg, in.vec_reg);
		return out;
	}

	v4int64_t v4int64_t::MulLo(const v4int64_t& in) const
	{
		v4int64_t out;
		out.vec_reg = _mm256_mul_epi32(vec_reg, in.vec_reg);
		return out;
	}

	/*********************** Math functions********************************/
	v4int64_t v4int64_t::Max(const v4int64_t& in) const
	{
		v4int64_t out;
		scalar::Max(*this, in, out);
		return out;
	}

	v4int64_t v4int64_t::Min(const v4int64_t& in) const
	{
		v4int64_t out;
		scalar::Min(*this, in, out);
		return out;
	}

	/***********************Memory operations********************************/
	void v4int64_t::MaskLoad(const int64_t* mem_addr, const Mask4 mask)
	{
		const v4uint64_t v_mask{ mask };
		vec_reg = _mm256_maskload_epi64(mem_addr, v_mask.vec_reg);
	}

	void v4int64_t::MaskStore(int64_t* mem_addr, const Mask4 mask) const
	{
		const v4uint64_t v_mask{ mask };
		_mm256_maskstore_epi64(mem_addr, v_mask.vec_reg, vec_reg);
	}

	/*********************** Set ********************************/
	void v4int64_t::Set(int64_t value)
	{
		vec_reg = _mm256_set1_epi64x(value);
	}
	void v4int64_t::Set(int64_t e0, int64_t e1, int64_t e2, int64_t e3)
	{
		vec_reg = _mm256_setr_epi64x(e0, e1, e2, e3);
	}

	void v4int64_t::Set(const int64_t value, const int index)
	{
#if _MSC_VER && !__INTEL_COMPILER
		vec_reg.m256i_i64[index] = value;
#else
		vec_reg[index] = value;
#endif
	}
	/*********************** Compare ********************************/
	v4int64_t v4int64_t::Equal(const v4int64_t& in) const
	{
		v4int64_t out;
		out.vec_reg = _mm256_cmpeq_epi64(vec_reg, in.vec_reg);
		return out;
	}

	v4int64_t v4int64_t::Greater(const v4int64_t& in) const
	{
		v4int64_t out;
		out.vec_reg = _mm256_cmpgt_epi64(vec_reg, in.vec_reg);
		return out;
	}

	/***********************Operator overloading********************************/
	int64_t v4int64_t::operator[](const size_t index) const
	{
		// check if the index is valid
		if (index >= Length())
		{
			return std::nanf("0");
		}
#if _MSC_VER && !__INTEL_COMPILER
		return vec_reg.m256i_i64[index];
#else
		return vec_reg[index];
#endif
	}
}


