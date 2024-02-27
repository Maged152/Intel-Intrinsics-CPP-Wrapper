#include "shakhbat_AVX512.h"
#include <iostream>

int main()
{
	qlm::vfloat_t v1{};

	std::cout << v1.Length() << std::endl;
	return 0;
}