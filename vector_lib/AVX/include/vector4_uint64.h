#pragma once

#include "vector256_int.h"

namespace qlm
{
	class v4uint64_t : public v256int_t<uint64_t, v4uint64_t>
	{
	public:
		__m256i vec_reg;

	public:
		// Constructors
		v4uint64_t();
		v4uint64_t(uint64_t value);
		v4uint64_t(uint64_t e0, uint64_t e1, uint64_t e2, uint64_t e3);
		v4uint64_t(const uint64_t* mem_addr);

	public:
		// ALU operations
		virtual v4uint64_t Add(const v4uint64_t& in) const override;
		virtual v4uint64_t Sub(const v4uint64_t& in) const override;
		virtual v4uint64_t Div(const v4uint64_t& in) const override;
		v4uint64_t MulLo(const v4uint64_t& in) const;

	public:
		// Math functions
		virtual v4uint64_t Max(const v4uint64_t& in) const override;
		virtual v4uint64_t Min(const v4uint64_t& in) const override;

	public:
		// Set 
		void Set(uint64_t value);
		void Set(uint64_t e0, uint64_t e1, uint64_t e2, uint64_t e3);

	public:
		// Memory operations
		virtual void Load(const uint64_t* mem_addr) override;
		virtual void Store(uint64_t* mem_addr) const override;

		static v4uint64_t GetMask(const uint64_t num_elements);

	public:
		// Compare
		v4uint64_t Equal(const v4uint64_t& in) const;
		v4uint64_t Greater(const v4uint64_t& in) const;

	public:
		// Operator overloading
		virtual uint64_t operator [](const size_t index) const;

	};
}


