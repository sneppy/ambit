#include "bitset.h"

using namespace Ambit;

int main()
{
	Bitset<1024> x, y, z;

	x &= y;
	z = x ^ y;

	return 0;
}