#pragma once

#include "platform.h"
#include "templates.h"

namespace Ambit
{
	/**
	 * @{
	 */
	template<typename T>
	constexpr inline T min(const T & a, const T & b)
	{
		return a < b ? a : b;
	}

	template<typename T, typename ... U>
	constexpr inline T min(const T & a, const T & b, U && ... c)
	{
		return a < b ? min(a, forward<U>(c) ...) : min(b, forward<U>(c) ...);
	}
	/// @}

	/**
	 * @{
	 */
	template<typename T>
	constexpr inline T max(const T & a, const T & b)
	{
		return a > b ? a : b;
	}

	template<typename T, typename ... U>
	constexpr inline T max(const T & a, const T & b, U && ... c)
	{
		return a > b ? max(a, forward<U>(c) ...) : max(b, forward<U>(c) ...);
	}
	/// @}

	/**
	 * Align up to power of two
	 * 
	 * @param n number to align
	 * @param p power of two
	 */
	template<typename T, typename U = T>
	constexpr inline T align2Up(const T & n, const U & p)
	{
		const U m = p - 1;
		const U t = n & m;
		return t ? (n & ~m) + p : n;
	}

	/**
	 * Align down to power of two
	 */
	template<typename T, typename U = T>
	constexpr inline T align2Down(const T & n, const U & p)
	{
		const U m = p - 1;
		const U t = n & m;
		return t ? (n & ~m) : n;
	}
} // namespace Ambit
