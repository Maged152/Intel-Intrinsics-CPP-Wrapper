#pragma once

#include "vector_common.h"

namespace qlm
{
	class vfloat_t : public Vector<float, vfloat_t>
	{
	protected:
		__m512 vec_reg;

	public:
		// ALU operations
		virtual Status Add(const vfloat_t& in, vfloat_t& out) const override;

		// Memory operations
		virtual Status Load(float const* mem_addr) override;

	};
}


