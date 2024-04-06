#pragma once
#include "vector_common.h"

namespace scalar
{
	template<typename d_t, typename m_t, typename v_t>
	void MaskLoad(const d_t* mem_addr, const m_t mask, v_t& in)
	{
		for (int i = 0; i < in.Length(); i++)
		{
			if (mask[i])
			{
				in.Set(mem_addr[i], i);
			}
			else
			{
				in.Set(0, i);
			}
		}
	}

	template<typename d_t, typename m_t, typename v_t>
	void MaskStore(const v_t& in, d_t* mem_addr, const m_t mask)
	{
		for (int i = 0; i < in.Length(); i++)
		{
			if (mask[i])
			{
				mem_addr[i] = in[i];
			}
		}
	}

}