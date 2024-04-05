#include "vector4_double.h"
#include "vector4_uint64.h"
#include <cmath>

namespace qlm
{
	/*********************** Constructors ********************************/
	v4double_t::v4double_t()
	{}

	v4double_t::v4double_t(double value)
	{
		this->Set(value);
	}

	v4double_t::v4double_t(double e0, double e1, double e2, double e3)
	{
		this->Set(e0, e1, e2, e3);
	}

	v4double_t::v4double_t(const double* mem_addr)
	{
		this->Load(mem_addr);
	}

	/***********************ALU operations********************************/
	v4double_t v4double_t::Add(const v4double_t& in) const
	{
		v4double_t out;
		out.vec_reg = _mm256_add_pd(vec_reg, in.vec_reg);
		return out;
	}

	v4double_t v4double_t::Sub(const v4double_t& in) const
	{
		v4double_t out;
		out.vec_reg = _mm256_sub_pd(vec_reg, in.vec_reg);
		return out;
	}

	v4double_t v4double_t::Mul(const v4double_t& in) const
	{
		v4double_t out;
		out.vec_reg = _mm256_mul_pd(vec_reg, in.vec_reg);
		return out;
	}

	v4double_t v4double_t::Div(const v4double_t& in) const
	{
		v4double_t out;
		out.vec_reg = _mm256_div_pd(vec_reg, in.vec_reg);
		return out;
	}

	/***********************Logical operations********************************/
	v4double_t v4double_t::And(const v4double_t& in) const
	{
		v4double_t out;
		out.vec_reg = _mm256_and_pd(vec_reg, in.vec_reg);
		return out;
	}

	v4double_t v4double_t::Or(const v4double_t& in) const
	{
		v4double_t out;
		out.vec_reg = _mm256_or_pd(vec_reg, in.vec_reg);
		return out;
	}

	v4double_t v4double_t::Xor(const v4double_t& in) const
	{
		v4double_t out;
		out.vec_reg = _mm256_xor_pd(vec_reg, in.vec_reg);
		return out;
	}

	/*********************** Math functions********************************/
	v4double_t v4double_t::Sqrt() const
	{
		v4double_t out;
		out.vec_reg = _mm256_sqrt_pd(vec_reg);
		return out;
	}

	v4double_t v4double_t::Max(const v4double_t& in) const
	{
		v4double_t out;
		out.vec_reg = _mm256_max_pd(vec_reg, in.vec_reg);
		return out;
	}

	v4double_t v4double_t::Min(const v4double_t& in) const
	{
		v4double_t out;
		out.vec_reg = _mm256_min_pd(vec_reg, in.vec_reg);
		return out;
	}

	v4double_t  v4double_t::Ceil() const
	{
		v4double_t out;
		out.vec_reg = _mm256_ceil_pd(vec_reg);
		return out;
	}

	v4double_t  v4double_t::Floor() const
	{
		v4double_t out;
		out.vec_reg = _mm256_floor_pd(vec_reg);
		return out;
	}

	/***********************Memory operations********************************/
	void v4double_t::Load(const double* mem_addr)
	{
		vec_reg = _mm256_loadu_pd(mem_addr);
	}

	void v4double_t::MaskLoad(const double* mem_addr, const Mask4 mask)
	{
		const v4uint64_t v_mask{ mask };
		vec_reg = _mm256_maskload_pd(mem_addr, v_mask.vec_reg);
	}
	void v4double_t::Store(double* mem_addr) const
	{
		_mm256_storeu_pd(mem_addr, vec_reg);
	}

	void v4double_t::MaskStore(double* mem_addr, const Mask4 mask) const
	{
		const v4uint64_t v_mask{ mask };
		_mm256_maskstore_pd(mem_addr, v_mask.vec_reg, vec_reg);
	}


	/*********************** Set ********************************/
	void v4double_t::Set(double value)
	{
		vec_reg = _mm256_set1_pd(value);
	}
	void v4double_t::Set(double e0, double e1, double e2, double e3)
	{
		vec_reg = _mm256_setr_pd(e0, e1, e2, e3);
	}

	/***********************Operator overloading********************************/
	double v4double_t::operator[](const size_t index) const
	{
		// check if the index is valid
		if (index >= Length())
		{
			return std::nanf("0");
		}
#if _MSC_VER && !__INTEL_COMPILER
		return vec_reg.m256d_f64[index];
#else
		return vec_reg[index];
#endif
	}
}


