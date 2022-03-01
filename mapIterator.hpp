#pragma once

#include <iostream>
#include "avlBST.hpp"


template <class __Iter, class Compare = std::less<__Iter> >
class	mapIterator
{
	public:
		//* Types.
		typedef __Iter													iterator_type;
		typedef std::bidirectional_iterator_tag							iterator_category;
		typedef	iterator_type											value_type;
		typedef	std::ptrdiff_t											difference_type;
		typedef	iterator_type*											pointer;
		typedef	iterator_type&											reference;



	//! The canonical form.
	public:
		//* Default constructor.
		mapIterator ( void ) { LOG("[mapIterator] Default constructor."); };
		//* Copy constructor.
		mapIterator(const mapIterator& src) {
			*this = src;
		}
		//* Initialization constructor.
		mapIterator(iterator_type& src)
		{
			__Tree = src;
		}

		mapIterator& operator=( const mapIterator& rhs )
		{
			LOG("assignement");
			this->__Tree = rhs.__Tree;
			return *this;
		}
		~mapIterator ( void )
		{
			//TODO: Implement the destructor.
			
		}


	//! Arithmetic operations.
	public:
		mapIterator& operator++()
		{
			++__Tree;
			return *this;
		}
		mapIterator operator++(int)
		{
			mapIterator	temp(*this);

			++(*this);
			return temp;
		}
		mapIterator& operator--()
		{
			--__Tree;
			return *this;
		}
		mapIterator operator--(int)
		{
			mapIterator	temp(*this);

			--(*this);
			return temp;
		}
		friend bool operator==(const mapIterator& __x, const mapIterator& __y)
		{ return __x.__Tree == __y.__Tree; }
		friend bool operator!=	(const mapIterator& __x, const mapIterator& __y)
		{ return __x.__Tree != __y.__Tree; }

		reference	operator*() const
		{
			return *__Tree;
		}

		pointer		operator->() const
		{
			return __Tree.operator->();
		}
	private:
		iterator_type				__Tree;
};