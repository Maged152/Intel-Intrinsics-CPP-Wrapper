#include "vector4_uint64.h"
#include <cmath>

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
		out.vec_reg = _mm256_mullo_epi64(vec_reg, in.vec_reg);
		return out;
	}

	/*********************** Math functions********************************/
	v4uint64_t v4uint64_t::Max(const v4uint64_t& in) const
	{
		v4uint64_t out;
		out.vec_reg = _mm256_max_epu64(vec_reg, in.vec_reg);
		return out;
	}

	v4uint64_t v4uint64_t::Min(const v4uint64_t& in) const
	{
		v4uint64_t out;
		out.vec_reg = _mm256_min_epu64(vec_reg, in.vec_reg);
		return out;
	}

	/***********************Memory operations********************************/
	void v4uint64_t::Load(const uint64_t* mem_addr)
	{
		vec_reg = _mm256_loadu_epi64(mem_addr);
	}

	void v4uint64_t::Store(uint64_t* mem_addr) const
	{
		_mm256_storeu_epi64(mem_addr, vec_reg);
	}

	v4uint64_t v4uint64_t::GetMask(const uint64_t num_elements)
	{
		v4uint64_t v_linear{ 0, 1, 2, 3 };
		v4uint64_t v_num_elments{ num_elements };

		v4uint64_t mask = v_num_elments.Greater(v_linear);

		return mask;
	}

	/*********************** Set ********************************/
	void v4uint64_t::Set(uint64_t value)
	{
		vec_reg = _mm256_set1_epi64x(value);
	}
	void v4uint64_t::Set(uint64_t e0, uint64_t e1, uint64_t e2, uint64_t e3)
	{
		vec_reg = _mm256_setr_epi64x(e0, e1, e2, e3);
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
		out.vec_reg = _mm256_movm_epi64(_mm256_cmpgt_epu64_mask(vec_reg, in.vec_reg));
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
#if defined(_WIN32)
		return vec_reg.m256i_i64[index];
#else
		return vec_reg[index];
#endif
	}
}


