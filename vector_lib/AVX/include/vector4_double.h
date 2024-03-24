#pragma once

#include "../../common/vector_common.h"

namespace qlm
{
	class v4double_t : public Vector<double, v4double_t>
	{
	public:
		__m256d vec_reg;

	public:
		// Constructors
		v4double_t();
		v4double_t(double value);
		v4double_t(double e0, double e1, double e2, double e3);
		v4double_t(const double* mem_addr);

	public:
		// ALU operations
		virtual v4double_t Add(const v4double_t& in) const override;
		virtual v4double_t Sub(const v4double_t& in) const override;
		v4double_t Mul(const v4double_t& in) const;
		virtual v4double_t Div(const v4double_t& in) const override;

	public:
		// Logical operators
		virtual v4double_t Or(const v4double_t& in) const override;
		virtual v4double_t And(const v4double_t& in) const override;
		virtual v4double_t Xor(const v4double_t& in) const override;

	public:
		// Math functions
		v4double_t Sqrt() const;
		virtual v4double_t Max(const v4double_t& in) const override;
		virtual v4double_t Min(const v4double_t& in) const override;
		v4double_t Ceil() const;
		v4double_t Floor() const;
		template<RoundMode round>
		v4double_t Round() const
		{
			v4double_t out;
			out.vec_reg = _mm256_round_pd(vec_reg, static_cast<int>(round));
			return out;
		}

	public:
		// Set 
		void Set(double value);
		void Set(double e0, double e1, double e2, double e3);

	public:
		// Memory operations
		virtual void Load(const double* mem_addr) override;
		void Load(const double* mem_addr, const Mask4 mask);

		virtual void Store(double* mem_addr) const override;
		void Store(double* mem_addr, const Mask4 mask) const;

	public:
		// Compare
		template<CompareMode comp>
		v4double_t& Compare(const v4double_t& in) const
		{
			v4double_t out;
			out.vec_reg = _mm256_cmp_pd(vec_reg, in.vec_reg, static_cast<int>(comp));
			return out;
		}

	public:
		// Operator overloading
		virtual double operator [](const size_t index) const;

	};
}


