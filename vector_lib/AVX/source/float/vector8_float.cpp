#include "float/vector8_float.h"
#include <cmath>

namespace qlm
{
	/***********************ALU operations********************************/
	Status v8float_t::Add(const v8float_t& in, v8float_t& out) const
	{
		out.vec_reg = _mm256_add_ps(vec_reg, in.vec_reg);
		return Status::VECTOR_SUCCESS;
	}

	/***********************Memory operations********************************/
	Status v8float_t::Load(const float* mem_addr)
	{
		vec_reg = _mm256_loadu_ps(mem_addr);

		return Status::VECTOR_SUCCESS;
	}

	Status v8float_t::Store(float* mem_addr) const
	{
		_mm256_storeu_ps(mem_addr, vec_reg);

		return Status::VECTOR_SUCCESS;
	}
	/***********************Operator overloading********************************/
	float v8float_t::operator[](const size_t index) const
	{
		// check if the index is valid
		if (index >= Length())
		{
			return std::nanf("0");
		}
#if defined(_WIN32)
		return vec_reg.m256_f32[index];
#else
		return vec_reg[index];
#endif
	}
}


