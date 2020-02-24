
Ambit demo
============

[In-Memory Accelerator for Bulk Bitwise Operations Using Commodity DRAM Technology](https://people.inf.ethz.ch/omutlu/pub/ambit-bulk-bitwise-dram_micro17.pdf)

Usage
-----

Example usage of the `Bitset` class:

```cpp
#include "ambit/bitset.h"

using namespace Ambit;

int32 main()
{
	Bitset<1024> x, y, z;

	x &= y;
	z = x ^ y;

	return 0;
}
```