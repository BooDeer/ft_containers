#pragma once

#include <iostream>
#include "avlBST.hpp"


template <class Avltree>
class	mapIterator
{
	public:
		//* Types.
		typedef Avltree													iterator_type;
		typedef std::bidirectional_iterator_tag							iterator_category;
		typedef	typename iterator_type::value_type						value_type;
		typedef typename iterator_type::Node*							node_pointer;
		typedef	std::ptrdiff_t											difference_type;
		// typedef	iterator_type*											pointer;	//! Check the typedef related to the pointer.
		typedef	value_type&												reference;
		typedef	value_type*												pointer;

	private:
		typedef mapIterator< const Avltree>								const_iterator;

	//! The canonical form.
	public:
		//* Default constructor.
		mapIterator ( void ) {};
		//* Copy constructor.
		mapIterator(const mapIterator& src) {
			*this = src;
		}
		//* Initialization constructor.
		mapIterator(const iterator_type& src){
			__Tree.__root = src.__root;
			__Tree.mv_ch  = src.mv_ch;
			__Tree.end_node = src.end_node;
		}

		mapIterator& operator=(const mapIterator& rhs )
		{
			// this->__Tree = rhs.__Tree;
			__Tree.__root	= rhs.__Tree.__root;
			__Tree.mv_ch	= rhs.__Tree.mv_ch;
			__Tree.end_node = rhs.__Tree.end_node;
			return *this;
		}
		~mapIterator ( void )
		{
			//TODO: Implement the destructor.
			
		}
		operator const_iterator(){
			return const_iterator(this->__Tree);
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
		{ return __x.__Tree.mv_ch == __y.__Tree.mv_ch; }
		friend bool operator!=	(const mapIterator& __x, const mapIterator& __y)
		{
			return __x.__Tree.mv_ch != __y.__Tree.mv_ch; }

		reference	operator*() const	//! Why does the map iterator return a pointer to the pair.
		{
			return __Tree.operator*();
		}

		value_type*		operator->() const
		{
			return __Tree.operator->();
		}
	public:
		iterator_type				__Tree;
};