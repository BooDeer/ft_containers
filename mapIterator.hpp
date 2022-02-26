#pragma once

#include <iostream>
#include "avlBST.hpp"


template <class __Iter>
class	mapIterator
{
	public:
		//* Types.
		typedef __Iter													iterator_type;
		typedef std::bidirectional_iterator_tag							iterator_category;
		typedef	iterator_type											value_type;
		typedef	std::ptrdiff_t											difference_type;
		typedef	__Iter*													pointer;
		typedef	__Iter&													reference;



	//! The canonical form.
	public:
		//* Default constructor.
		mapIterator ( void ): __Tree(nullptr) {};
		// // Constructor with a parameter.
		//* Copy constructor.
		mapIterator(const mapIterator& src) {
			*this = src;
		}

		mapIterator& operator=( const mapIterator& rhs )
		{
			this->__Tree = rhs.__Tree;
			
			return *this;
		}
		~mapIterator ( void )
		{
			//TODO: Implement the destructor.
			
		}
		









	private:
		AvlBST<__Iter>				__Tree;
};