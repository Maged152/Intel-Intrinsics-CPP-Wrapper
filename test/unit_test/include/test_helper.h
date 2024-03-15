#pragma once

#include <random>
#include <cmath>
#include <string>
#include <iostream>

#define ANSI_TXT_GRN "\033[0;32m"
#define ANSI_TXT_RED "\033[0;31m"
#define ANSI_TXT_MGT "\033[0;35m" //Magenta
#define ANSI_TXT_DFT "\033[0;0m" //Console default

#define GTEST_BOX      "[Parameters] "
#define GTEST_BOX_TIME "[Time      ] "
#define GTEST_BOX_FAST "[Faster    ] "
#define GTEST_BOX_SLOW "[Slower    ] "

#define COUT_GTEST ANSI_TXT_GRN << GTEST_BOX 
#define COUT_GTEST_TIME ANSI_TXT_GRN << GTEST_BOX_TIME
#define COUT_GTEST_FAST ANSI_TXT_GRN << GTEST_BOX_FAST 
#define COUT_GTEST_SLOW ANSI_TXT_GRN << GTEST_BOX_SLOW 

#define COUT_GTEST_MGT COUT_GTEST << ANSI_TXT_MGT
#define COUT_GTEST_MGT_TIME COUT_GTEST_TIME << ANSI_TXT_MGT
#define COUT_GTEST_GRN_FAST COUT_GTEST_FAST << ANSI_TXT_GRN
#define COUT_GTEST_RED_SLOW COUT_GTEST_SLOW << ANSI_TXT_RED

namespace test
{
	enum class vector_t
	{
		AVX_float,
		AVX_double,
		AVX_int32,
		AVX_uint32,
		AVX_int64,
		AVX_uint64
	};

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
		void RandomInit(const double min_value, const double max_value)
		{
			std::random_device rd;
			std::mt19937 gen(rd());
			std::uniform_real_distribution<double> dis(min_value, max_value);

			for (int i = 0; i < len; i++)
			{
				data[i] = (T)dis(gen);
			}
		}

		template<typename fun>
		void Operation(const Array<T>& src, Array<T>& dst, fun& op) const
		{
			for (int i = 0; i < len; i++)
			{
				dst.data[i] = op(data[i], src.data[i]);
			}
		}

		template<typename fun>
		void Operation(Array<T>& dst, fun& op) const
		{
			for (int i = 0; i < len; i++)
			{
				dst.data[i] = op(data[i]);
			}
		}
	};

	template <typename T>
	T abs(T value) 
	{
		if (value < 0) 
		{
			return -value;
		}
		else 
		{
			return value;
		}
	}

	template<typename T>
	inline bool Compare(const Array<T>& arr1, const Array<T>& arr2, const T threshold, const bool show = true)
	{
		bool res = true;
		for (int i = 0; i < arr1.len; i++)
		{
			if (abs(arr1.data[i] - arr2.data[i]) > threshold)
			{
				if (show)
				{
					std::cout << arr1.data[i] << " vs " << arr2.data[i] << "\n";
				}
				res = false;
			}
		}

		return res;
	}
	
	// print
	template<typename T>
	inline void PrintParameter(T parameter, const std::string& para_name)
	{
		std::cout << COUT_GTEST_MGT << para_name
			<< " = "
			<< parameter
			<< ANSI_TXT_DFT << std::endl;
	}

	inline std::ostream& operator << (std::ostream& out, const vector_t vec_type)
	{
		switch (vec_type)
		{
		case vector_t::AVX_float:
			out << "v8float_t";
			break;

		case vector_t::AVX_double:
			out << "v4double_t";
			break;

		case vector_t::AVX_int32:
			out << "v8int32_t";
			break;

		case vector_t::AVX_uint32:
			out << "v8uint32_t";
			break;

		case vector_t::AVX_int64:
			out << "v4int64_t";
			break;

		case vector_t::AVX_uint64:
			out << "v4uint64_t";
			break;

		}

		return out;
	}
}