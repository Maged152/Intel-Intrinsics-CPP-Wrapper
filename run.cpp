#include "shakhbat_avx.h"
#include <iostream>

int main()
{
	float arr[20];
	for (int i = 0; i < 20; i++)
	{
		arr[i] = i;
	}
	 
	qlm::v8float_t v1, v2, v3;

	v1.Load(arr);
	v2.Load(arr + 8);

	v1.Print();
	v2.Print();

	v3 = v1.Add(v2);
	v3.Print();



	return 0;
}