#include "shakhbat_avx.h"
#include <iostream>

int main()
{
	float arr[16] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
	 
	qlm::v8float_t v1, v2, v3;

	v1.Load(arr);
	v2.Load(arr + 8);

	v1.Print();
	v2.Print();

	v3 = v1 - v2;
	v3.Print();



	return 0;
}