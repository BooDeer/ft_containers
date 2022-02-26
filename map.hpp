#pragma once

#include <iostream>
#include "utility.hpp"
#include "mapIterator.hpp"
#include "avlBST.hpp"

namespace ft
{

	template<class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T> >
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
			// typedef	mapIterator<AvlBST<value_type, key_compare> >							iterator;
			// typedef mapIterator<const AvlBST<value_type, key_compare> >						const_iterator;
			// typedef reverseMapIterator<iterator>									reverse_iterator;
			// typedef reverseMapIterator<const_iterator>							const_reverse_iterator;
			typedef std::ptrdiff_t									difference_type;
			typedef std::size_t										size_type;






		public:
		//! The canonical form =====================================================================
		//* Default constructor.
		explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()): __Size(0), __Alloc(alloc), __cmp(comp) {
			LOG("[map] Default constructor.");
		};
		//* Copy constructor.
		map (const map& src): __Size(src.__Size), __cmp(src.__cmp)
		{
			//TODO: implement copy constructor.

		}

		//! The canonical form =====================================================================



		//! Capacity Member functions.
		public:
			size_type	size() const
			{
				return __Size;
			};

			bool		empty() const
			{
				return __Size;
			}

			size_type	max_size() const	//! Incorrect.
			{
				return __Alloc.max_size();
			}








		private:
			size_t											__Size;
			AvlBST<value_type, key_compare>					__TreeRoot;
			// size_t			__Capacity; //<==== Not sure if there's a Capacity counter since it's a BST.
			allocator_type									__Alloc;
			key_compare										__cmp;

	};
};