#pragma once

#include <immintrin.h>
#include "types.h"

namespace qlm
{
	template<typename d_t, typename vec_t>
	class Vector
	{
	public:
		virtual Status Add(const vec_t& in, vec_t& out) const = 0;

	public:
		constexpr size_t SimdWidth()
		{
			return sizeof(vec_t);
		}

		constexpr size_t Length()
		{
			return sizeof(vec_t) / sizeof(d_t);
		}

	};
}


