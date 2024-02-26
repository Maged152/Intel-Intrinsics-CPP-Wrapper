#include "AVX_Library.h"

namespace qlm
{
	int test()
	{
		//__m512i v = {1};
		//__m512i v2 = {2};
		//auto r = _mm512_add_epi32(v, v2);
		return sizeof(__m512d);
	}
}


