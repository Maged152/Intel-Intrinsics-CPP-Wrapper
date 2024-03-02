#pragma once

#include "../../common/vector_common.h"

namespace qlm
{
	class v8float_t : public Vector<float, v8float_t>
	{
	public:
		__m256 vec_reg;

	public:
		// ALU operations
		virtual Status Add(const v8float_t& in, v8float_t& out) const override;

	public:
		// Memory operations
		virtual Status Load(const float* mem_addr) override;
		virtual Status Store(float* mem_addr) const override;

	public:
		// Operator overloading
		virtual float operator [](const size_t index) const;

	};
}


