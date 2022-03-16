#pragma once


# include <iostream>




namespace ft
{


	template <class _Tp>
	struct is_integral: public std::false_type {};
	template <>
	struct is_integral<bool>: public std::true_type {};
	template <>
	struct is_integral<char>: public std::true_type {};
	template <>
	struct is_integral<signed char>: public std::true_type {};
	template <>
	struct is_integral<unsigned char>: public std::true_type {};
	template <>
	struct is_integral<wchar_t>: public std::true_type {};
	template <>
	struct is_integral<char16_t>: public std::true_type {};
	template <>
	struct is_integral<char32_t>: public std::true_type {};
	template <>
	struct is_integral<short>: public std::true_type {};
	template <>
	struct is_integral<unsigned short>: public std::true_type {};
	template <>
	struct is_integral<int>: public std::true_type {};
	template <>
	struct is_integral<unsigned int>: public std::true_type {};
	template <>
	struct is_integral<long>: public std::true_type {};
	template <>
	struct is_integral<unsigned long>: public std::true_type {};
	template <>
	struct is_integral<long long>: public std::true_type {};
	template <>
	struct is_integral<unsigned long long>: public std::true_type {};
	template <>
	struct is_integral<__int128_t>: public std::true_type {};
	template <>
	struct is_integral<__uint128_t>: public std::true_type {};
	template <>
	struct is_integral<float>: public std::true_type {};
	template <>
	struct is_integral<double>: public std::true_type {};
	template <>
	struct is_integral<long double>: public std::true_type {};
	
	template <class InputIterator1, class InputIterator2>
	bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
	{
		while (first1!=last1) {
			if (!(*first1 == *first2))
				return false;
			++first1; ++first2;
		}
		return true;
	}
	template <class InputIterator1, class InputIterator2>
  	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
                                InputIterator2 first2, InputIterator2 last2)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || *first2 < *first1) 
				return false;
			else if (*first1 < *first2)
				return true;
			++first1; 
			++first2;
		}
		return (first2!=last2);
	}
	template<class T>
	struct iterator_traits
	{
		typedef typename T::difference_type		difference_type;
		typedef typename T::value_type			value_type;
		typedef typename T::pointer				pointer;
		typedef typename T::reference			reference;
		typedef typename T::iterator_category	iterator_category;
	};

	template<class T>
	struct iterator_traits<T *>
	{
		typedef std::ptrdiff_t							difference_type;
		typedef T										value_type;
		typedef T*										pointer;
		typedef T&										reference;
		typedef std::random_access_iterator_tag			iterator_category;
	};

	template<class T>
	struct iterator_traits<const T *>
	{
		typedef std::ptrdiff_t							difference_type;
		typedef T										value_type;
		typedef const T*								pointer;
		typedef const T&								reference;
		typedef std::random_access_iterator_tag			iterator_category;
	};
}