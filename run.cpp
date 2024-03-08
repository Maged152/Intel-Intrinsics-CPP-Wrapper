#include "shakhbat_avx.h"
#include <iostream>

int main()
{
	float arr[16] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
	 
	qlm::v8float_t v1;
	qlm::v8float_t v2{2};
	qlm::v8float_t v3{10,11,12,13,14,15,16,17};
	qlm::v8float_t v4{arr};

	v1.Print();
	v2.Print();
	v3.Print();
	v4.Print();



	return 0;
}