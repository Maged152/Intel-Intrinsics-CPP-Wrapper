#include "vector4_int64.h"
#include <cmath>

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
		out.vec_reg = _mm256_mullo_epi64(vec_reg, in.vec_reg);
		return out;
	}

	/*********************** Math functions********************************/
	v4int64_t v4int64_t::Max(const v4int64_t& in) const
	{
		v4int64_t out;
		out.vec_reg = _mm256_max_epi64(vec_reg, in.vec_reg);
		return out;
	}

	v4int64_t v4int64_t::Min(const v4int64_t& in) const
	{
		v4int64_t out;
		out.vec_reg = _mm256_min_epi64(vec_reg, in.vec_reg);
		return out;
	}

	/***********************Memory operations********************************/
	void v4int64_t::Load(const int64_t* mem_addr)
	{
		vec_reg = _mm256_loadu_epi64(mem_addr);
	}

	void v4int64_t::Store(int64_t* mem_addr) const
	{
		_mm256_storeu_epi64(mem_addr, vec_reg);
	}

	v4int64_t v4int64_t::GetMask(const int64_t num_elements)
	{
		v4int64_t v_linear{ 0, 1, 2, 3 };
		v4int64_t v_num_elments{ num_elements };

		v4int64_t mask = v_num_elments.Greater(v_linear);

		return mask;
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
#if defined(_WIN32)
		return vec_reg.m256i_i64[index];
#else
		return vec_reg[index];
#endif
	}
}


