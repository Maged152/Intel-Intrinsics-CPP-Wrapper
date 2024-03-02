#pragma once
#include <random>
#include <camth>

namespace test
{
	template<typename T>
	class Array
	{
	public :
		T* data;
		size_t len;

	public:
		Array(const size_t len) : len(len)
		{
			data = new T[len];
		}

		~Array()
		{
			if (data != nullptr)
			{
				delete[] data;
			}
		}

	public:
		void RandomInit(const T min_value, const T max_value)
		{
			std::random_device rd;
			std::mt19937 gen(rd());
			std::uniform_real_distribution<T> dis(min_value, max_value);

			for (int i = 0; i < len; i++)
			{
				data[i] = dis(gen);
			}
		}

		template<typename op>
		void Operation(const Array<T>& src, Array<T>& dst) const
		{
			for (int i = 0; i < len; i++)
			{
				dst.data[i] = op(data[i], src.data[i]);
			}
		}
	};

	template<typename T>
	inline bool Compare(const Array<T>& arr1, const Array<T>& arr2, const T threshold)
	{
		for (int i = 0; i < arr1.len; i++)
		{
			if (std::abs(arr1.data[i] - arr2.data[i]) > threshold)
			{
				return false;
			}
		}

		return true;
	}

}