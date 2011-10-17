#ifndef FR_PLANQUART_JNI_CXX_PAIR_HPP
#define FR_PLANQUART_JNI_CXX_PAIR_HPP

namespace fr
{
namespace Planquart
{
namespace JNI
{
namespace cxx
{
	/**
	 * Pair of values
	 *
	 * This class couples together a pair of values, which may be of different
	 * types (T1 and T2). The individual values can be accessed through the
	 * public members first and second.
	 *
	 * This class is a replacement for std::pair which may not be
	 * available depending on the NDK implementation.
	 */
	template <typename _T1, typename _T2>
		struct pair
		{
			/**
			 * Alias of template parameter _T1
			 */
			typedef _T1 first_type;
			/**
			 * Alias of template parameter _T2
			 */
			typedef _T2 second_type;


			/**
			 * Copy of the first object
			 */
			_T1 first;
			/**
			 * Copy of the second object
			 */
			_T2 second;

			/**
			 * The default constructor creates first and second using their
			 * respective default constructor
			 */
			pair()
				:first(), second()
			{
			}

			/**
			 * Construct a new pair of value with the two given values
			 */
			pair(const _T1& __first, const _T2& __second)
				:first(__first), second(__second)
			{
			}

			/**
			 * Copy constructor for the pair object
			 */
			template <typename _U1, typename _U2>
				pair(const pair<_U1, _U2>& __pair)
				:first(__pair.first), second(__pair.second)
				{
				}

			/**
			 * Assignment operator
			 */
			pair& operator=(const pair& __pair)
			{
				first = __pair.first;
				second = __pair.second;
				return *this;
			}

			template <typename _U1, typename _U2>
				pair& operator=(const pair<_U1, _U2>& __pair)
				{
					first = __pair.first;
					second = __pair.second;
					return *this;
				}

		};

		/**
		 * Two pairs of the same type are equal if and only if their
		 * members are equal
		 */
		template <typename _T1, typename _T2>
			bool operator==(const pair<_T1, _T2>& __pair1,
							const pair<_T1, _T2>& __pair2)
			{
				return __pair1.first == __pair2.second &&
					   __pair1.second == __pair2.second;
			}
}
}
}
}

#endif /* FR_PLANQUART_JNI_CXX_PAIR_HPP */

