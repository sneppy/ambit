#pragma once

namespace Ambit
{
	template<unsigned int size>
	struct SizeType {};

	template<> struct SizeType<8u> { using Type = signed long long; using TypeU = unsigned long long; };
	template<> struct SizeType<4u> { using Type = signed int; using TypeU = unsigned int; };

	/**
	 * Platform core types
	 */
	struct PlatformTypes
	{
		using byte = signed char;
		using ubyte = unsigned char;

		using int8 = signed char;
		using int16 = signed short;
		using int32 = signed int;
		using int64 = signed long long;

		using uint8 = unsigned char;
		using uint16 = unsigned short;
		using uint32 = unsigned int;
		using uint64 = unsigned long long;

		using intp = typename SizeType<sizeof(void*)>::Type;
		using uintp = typename SizeType<sizeof(void*)>::TypeU;
		using sizet = uintp;
	};

	using byte = PlatformTypes::byte;
	using ubyte = PlatformTypes::ubyte;

	using int8 = PlatformTypes::int8;
	using int16 = PlatformTypes::int16;
	using int32 = PlatformTypes::int32;
	using int64 = PlatformTypes::int64;
	
	using uint8 = PlatformTypes::uint8;
	using uint16 = PlatformTypes::uint16;
	using uint32 = PlatformTypes::uint32;
	using uint64 = PlatformTypes::uint64;

	using intp = PlatformTypes::intp;
	using uintp = PlatformTypes::uintp;
	using sizet = PlatformTypes::sizet;
} // namespace Ambit