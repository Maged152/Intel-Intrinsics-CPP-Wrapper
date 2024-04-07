#pragma once
#include "vector_common.h"
#include <cmath>

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

	template<typename v_t>
	void Max(const v_t& in1, const v_t& in2, v_t& out)
	{
		for (int i = 0; i < in.Length(); i++)
		{
			out.set(std::max(in1[i], in2[i], i);
		}
	}

	template<typename v_t>
	void Min(const v_t& in1, const v_t& in2, v_t& out)
	{
		for (int i = 0; i < in.Length(); i++)
		{
			out.set(std::min(in1[i], in2[i], i);
		}
	}

	template<typename v_t>
	void Greater(const v_t& in1, const v_t& in2, v_t& out)
	{
		for (int i = 0; i < in.Length(); i++)
		{
			if (in1[i] > in2[i))
				out.set(1, i);
			else
				out.set(0, i);
		}
	}
}