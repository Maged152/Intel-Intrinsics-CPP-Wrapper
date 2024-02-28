#include "vector_float.h"

namespace qlm
{
	/***********************ALU operations********************************/
	Status vfloat_t::Add(const vfloat_t& in, vfloat_t& out) const
	{
		return Status::VECTOR_SUCCESS;
	}

	/***********************Memory operations********************************/
	Status vfloat_t::Load(float const* mem_addr)
	{
		vec_reg = _mm512_loadu_ps(reinterpret_cast<const void*>(mem_addr));

		return Status::VECTOR_SUCCESS;;
	}
}


