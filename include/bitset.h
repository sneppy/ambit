#pragma once

#include "platform.h"
#include "intrinsics.h"
#include "math.h"

namespace Ambit
{
	template<uint32 n>
	class Bitset
	{
		template<uint32> friend class Bitset;

	public:
		/// Bitset size
		constexpr static uint32 size = align2Up(n, 8192);

		/// Bit count
		constexpr static uint32 count = n;

	protected:
		/// Bitset data
		char data[size];

	public:
		/**
		 * Bitset compound or operation
		 * 
		 * @param other other bitset
		 * @return ref to self
		 */
		template<uint32 m>
		__attribute__((always_inline)) inline Bitset & operator|=(const Bitset<m> & other)
		{
			constexpr uint32 opSize = min(size, Bitset<m>::size);
			__builtin_ia32_bbor((void*)data, (void*)other.data, opSize);
			return *this;
		}

		/**
		 * Bitset compound xor operation
		 * 
		 * @param other other bitset
		 * @return ref to self
		 */
		template<uint32 m>
		__attribute__((always_inline)) inline Bitset & operator&=(const Bitset<m> & other)
		{
			constexpr uint32 opSize = min(size, Bitset<m>::size);
			__builtin_ia32_bband((void*)data, (void*)other.data, opSize);
			return *this;
		}

		/**
		 * Bitset compound xor operation
		 * 
		 * @param other other bitset
		 * @return ref to self
		 */
		template<uint32 m>
		__attribute__((always_inline)) inline Bitset & operator^=(const Bitset<m> & other)
		{
			constexpr uint32 opSize = min(size, Bitset<m>::size);
			__builtin_ia32_bbxor((void*)data, (void*)other.data, opSize);
			return *this;
		}

		/**
		 * Bitset compound or operation
		 * 
		 * @param other other bitset
		 * @return ref to self
		 */
		template<uint32 m>
		__attribute__((always_inline)) inline Bitset operator|(const Bitset<m> & other) const
		{
			Bitset out{*this};
			return out |= other;
		}

		/**
		 * Bitset compound xor operation
		 * 
		 * @param other other bitset
		 * @return ref to self
		 */
		template<uint32 m>
		__attribute__((always_inline)) inline Bitset operator&(const Bitset<m> & other) const
		{
			Bitset out{*this};
			return out &= other;
		}

		/**
		 * Bitset compound xor operation
		 * 
		 * @param other other bitset
		 * @return ref to self
		 */
		template<uint32 m>
		__attribute__((always_inline)) inline Bitset operator^(const Bitset<m> & other) const
		{
			Bitset out{*this};
			return out ^= other;
		}
	};
} // namespace Ambit