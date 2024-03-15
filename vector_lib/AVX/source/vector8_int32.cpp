#include "vector8_int32.h"
#include <cmath>

namespace qlm
{
	/*********************** Constructors ********************************/
	v8int32_t::v8int32_t()
	{}

	v8int32_t::v8int32_t(int32_t value)
	{
		this->Set(value);
	}

	v8int32_t::v8int32_t(int32_t e0, int32_t e1, int32_t e2, int32_t e3, int32_t e4, int32_t e5, int32_t e6, int32_t e7)
	{
		this->Set(e0, e1, e2, e3, e4, e5, e6, e7);
	}

	v8int32_t::v8int32_t(const int32_t* mem_addr)
	{
		this->Load(mem_addr);
	}

	/***********************ALU operations********************************/
	v8int32_t v8int32_t::Add(const v8int32_t& in) const
	{
		v8int32_t out;
		out.vec_reg = _mm256_add_epi32(vec_reg, in.vec_reg);
		return out;
	}

	v8int32_t v8int32_t::Sub(const v8int32_t& in) const
	{
		v8int32_t out;
		out.vec_reg = _mm256_sub_epi32(vec_reg, in.vec_reg);
		return out;
	}

	v8int32_t v8int32_t::MulLo(const v8int32_t& in) const
	{
		v8int32_t out;
		out.vec_reg = _mm256_mullo_epi32(vec_reg, in.vec_reg);
		return out;
	}

	v8int32_t v8int32_t::Div(const v8int32_t& in) const
	{
		v8int32_t out;
		out.vec_reg = _mm256_div_epi32(vec_reg, in.vec_reg);
		return out;
	}

	/***********************Logical operations********************************/
	v8int32_t v8int32_t::And(const v8int32_t& in) const
	{
		v8int32_t out;
		out.vec_reg = _mm256_and_si256(vec_reg, in.vec_reg);
		return out;
	}

	v8int32_t v8int32_t::Or(const v8int32_t& in) const
	{
		v8int32_t out;
		out.vec_reg = _mm256_or_si256(vec_reg, in.vec_reg);
		return out;
	}

	v8int32_t v8int32_t::Xor(const v8int32_t& in) const
	{
		v8int32_t out;
		out.vec_reg = _mm256_xor_si256(vec_reg, in.vec_reg);
		return out;
	}

	/*********************** Math functions********************************/
	v8int32_t v8int32_t::Max(const v8int32_t& in) const
	{
		v8int32_t out;
		out.vec_reg = _mm256_max_epi32(vec_reg, in.vec_reg);
		return out;
	}

	v8int32_t v8int32_t::Min(const v8int32_t& in) const
	{
		v8int32_t out;
		out.vec_reg = _mm256_min_epi32(vec_reg, in.vec_reg);
		return out;
	}

	/***********************Memory operations********************************/
	void v8int32_t::Load(const int32_t* mem_addr)
	{
		vec_reg = _mm256_loadu_epi32(mem_addr);
	}

	void v8int32_t::Store(int32_t* mem_addr) const
	{
		_mm256_storeu_epi32(mem_addr, vec_reg);
	}

	v8int32_t v8int32_t::GetMask(const int32_t num_elements)
	{
		v8int32_t v_linear{ 0, 1, 2, 3, 4, 5, 6, 7 };
		v8int32_t v_num_elments{ num_elements };

		v8int32_t mask = v_num_elments.Greater(v_linear);

		return mask;
	}

	/*********************** Set ********************************/
	void v8int32_t::Set(int32_t value)
	{
		vec_reg = _mm256_set1_epi32(value);
	}
	void v8int32_t::Set(int32_t e0, int32_t e1, int32_t e2, int32_t e3, int32_t e4, int32_t e5, int32_t e6, int32_t e7)
	{
		vec_reg = _mm256_setr_epi32(e0, e1, e2, e3, e4, e5, e6, e7);
	}

	/*********************** Compare ********************************/
	v8int32_t v8int32_t::Equal(const v8int32_t& in) const
	{
		v8int32_t out;
		out.vec_reg = _mm256_cmpeq_epi32(vec_reg, in.vec_reg);
		return out;
	}

	v8int32_t v8int32_t::Greater(const v8int32_t& in) const
	{
		v8int32_t out;
		out.vec_reg = _mm256_cmpgt_epi32(vec_reg, in.vec_reg);
		return out;
	}

	/***********************Operator overloading********************************/
	int32_t v8int32_t::operator[](const size_t index) const
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


