#pragma once

#include <cstdint>

namespace qlm
{
	// base mask class
	template<typename d_t>
	class Mask
	{
	public:
		d_t mask;

	public:
		Mask()
		{}

		Mask(const d_t mask) : mask(mask)
		{}

	public:
		constexpr size_t Size() const
		{
			return sizeof(d_t) * 8;
		}

		void Set(const d_t val)
		{
			mask = val;
		}

		void SetBit(const size_t index)
		{
			if (index < Size()) 
			{
				mask |= (1 << index);
			}
		}

		void ClearBit(const size_t index)
		{
			if (index < Size())
			{
				mask &= ~(1 << index);
			}
		}

	public:
		bool operator [](const size_t index) const
		{
			bool res = false; //  a default value
			if (index < Size())
			{
				res = (mask >> index) & 1;
			}

			return res;
		}

		Mask<d_t> operator |(const Mask<d_t>& in) const
		{
			return Mask<d_t>(in.mask | mask);
		}

		Mask<d_t> operator &(const Mask<d_t>& in) const
		{
			return Mask<d_t>(in.mask & mask);
		}

		Mask<d_t> operator ^(const Mask<d_t>& in) const
		{
			return Mask<d_t>(in.mask ^ mask);
		}

		Mask<d_t> operator ~() const
		{
			return Mask<d_t>(~in.mask);
		}
	};

	
	// derived mask classes
	class Mask4 : public Mask<uint8_t> 
		{
		public:
			Mask4() : Mask<uint8_t>()
			{}

			Mask4(const uint8_t mask) : Mask(mask)
			{} 

			constexpr size_t Size() const 
			{
				return 4;  // Override the base class Size() to return 4
			}

	};

	class Mask8 : public Mask<uint8_t>
	{
	public:
		Mask8()
		{}

		Mask8(const uint8_t mask) : Mask(mask)
		{}
	};

	class Mask16 : public Mask<uint16_t>
	{
	public:
		Mask16()
		{}

		Mask16(const uint16_t mask) : Mask(mask)
		{}
	};

	class Mask32 : public Mask<uint32_t>
	{
	public:
		Mask32()
		{}

		Mask32(const uint32_t mask) : Mask(mask)
		{}
	};

	class Mask64 : public Mask<uint64_t>
	{
	public:
		Mask64()
		{}

		Mask64(const uint64_t mask) : Mask(mask)
		{}
	};
}