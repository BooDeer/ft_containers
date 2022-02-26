#pragma once

#include <iostream>
#include "utility.hpp"
#include "mapIterator.hpp"

namespace ft
{

	template<class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<std::pair<const Key, T> >
	> class map
	{
		public:
			//* Types.
			typedef	Key												key_type;
			typedef	T												mapped_type;
			typedef ft::pair<const key_type, mapped_type>			value_type;
			typedef Compare											key_compare;
			typedef	Alloc											allocator_type;
			typedef value_type&										reference;
			typedef const value_type&								const_reference;


			typedef typename allocator_type::pointer				pointer;
			typedef typename allocator_type::const_pointer			const_pointer;
			
			//* Iterators.
			// typedef	mapIterator<value_type>							iterator;
			// typedef mapIterator<const value_type>					const_iterator;
			// typedef reverseMapIterator<iterator>					reverse_iterator;
			// typedef reverseMapIterator<const_iterator>				const_reverse_iterator;
			typedef std::ptrdiff_t									difference_type;
			typedef std::size_t										size_type;







































	};
};