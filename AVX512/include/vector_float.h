#pragma once

#include "vector_common.h"

namespace qlm
{
	class vfloat_t : public Vector<float, vfloat_t>
	{
	protected:
		__m512 vec_reg;

	public:
		virtual Status Add(const vfloat_t& in, vfloat_t& out) const override;

	};
}


