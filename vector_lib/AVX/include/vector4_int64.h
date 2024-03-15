#pragma once

#include "vector256_int.h"

namespace qlm
{
	class v4int64_t : public v256int_t<int64_t, v4int64_t>
	{
	public:
		__m256i vec_reg;

	public:
		// Constructors
		v4int64_t();
		v4int64_t(int64_t value);
		v4int64_t(int64_t e0, int64_t e1, int64_t e2, int64_t e3);
		v4int64_t(const int64_t* mem_addr);

	public:
		// ALU operations
		virtual v4int64_t Add(const v4int64_t& in) const override;
		virtual v4int64_t Sub(const v4int64_t& in) const override;
		virtual v4int64_t Div(const v4int64_t& in) const override;
		v4int64_t MulLo(const v4int64_t& in) const;

	public:
		// Math functions
		virtual v4int64_t Max(const v4int64_t& in) const override;
		virtual v4int64_t Min(const v4int64_t& in) const override;

	public:
		// Set 
		void Set(int64_t value);
		void Set(int64_t e0, int64_t e1, int64_t e2, int64_t e3);

	public:
		// Memory operations
		virtual void Load(const int64_t* mem_addr) override;
		virtual void Store(int64_t* mem_addr) const override;

		static v4int64_t GetMask(const int64_t num_elements);

	public:
		// Compare
		v4int64_t Equal(const v4int64_t& in) const;
		v4int64_t Greater(const v4int64_t& in) const;

	public:
		// Operator overloading
		virtual int64_t operator [](const size_t index) const;

	};
}


