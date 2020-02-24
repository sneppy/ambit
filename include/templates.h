#pragma once

namespace Ambit
{
	/**
	 * Remove reference from T.
	 * If T is not a reference sets Type to T
	 * @{
	 */
	template<typename T>
	struct RemoveReference
	{
		using Type = T;
	};

	template<typename T> struct RemoveReference<T&> { using Type = T; };
	/// @}

	/**
	 * Forces move semantics by casting to rvalue reference
	 * 
	 * @param [in] t reference variable
	 */
	template<typename T>
	constexpr inline typename RemoveReference<T>::Type && move(T && t)
	{
		return static_cast<typename RemoveReference<T>::Type&&>(t);
	}

	/**
	 * Passes lvalues as lvalues and rvalues as lavalues
	 * 
	 * @param [in] t reference variable
	 * @{
	 */
	template<typename T>
	constexpr inline T && forward(typename RemoveReference<T>::Type & t)
	{
		return static_cast<T&&>(t);
	}

	template<typename T>
	constexpr inline T && forward(typename RemoveReference<T>::Type && t)
	{
		return static_cast<T&&>(t);
	}
	/// @}
} // namespace Ambit
