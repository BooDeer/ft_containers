#pragma once

#include <iostream>
#include "avlBST.hpp"

namespace	ft
{
	template<class T, class Pointer = T*, class Reference = T&>
	class	mapIterator
	{
		public:
			typedef std::bidirectional_iterator_tag			iterator_category;
			typedef	T										iterator_type;
			typedef typename T::Node						node;
			typedef typename T::value_type					value_type;
			typedef	std::ptrdiff_t							difference_type;
			typedef value_type*									pointer;
			typedef value_type&								reference;


		public:
			typedef	mapIterator<const T>					const_iterator;
			iterator_type									*__Tree;
			node											*__Node;
		

		public:
			operator	const_iterator()
			{
				return const_iterator(__Tree, __Node);
			}

			mapIterator() {}

			mapIterator(iterator_type* src): __Tree(src) {}

			mapIterator(iterator_type* src, node* node_src): __Tree(src), __Node(node_src) {}

			mapIterator(const mapIterator& src)
			{
				*this = src;
			}

			mapIterator&	operator=(const mapIterator& rhs)
			{
				__Tree = rhs.__Tree;
				__Node = rhs.__Node;
				return *this;
			}

			~mapIterator( void ) {}


			value_type&	operator*() const
			{
				return (__Node->key);
			}

			value_type* operator->() const
			{
				return (&operator*());
			}

			mapIterator&	operator++()
			{
				__Node = __Node->next_node(__Node);
				if (__Node == NULL)
					__Node = __Tree->end_node;
				return *this;
			}

			mapIterator	operator++(int)
			{
				mapIterator tmp(*this);
				++(*this);
				return tmp;
			}

			mapIterator&	operator--()
			{
				if(__Node == __Tree->end_node)
					__Node = __Node->max_node(__Tree->__root);
				else
					__Node = __Node->past_node(__Node);
				return (*this);
			}

			mapIterator	operator--(int)
			{
				mapIterator tmp(*this);
				--(*this);
				return tmp;
			}

			friend bool operator==(const mapIterator  &iter, const mapIterator &iter2){
				if (iter.__Node == iter2.__Node)
					return true;
				return false;
			}
		
			friend bool operator!=(const mapIterator  &iter, const mapIterator &iter2){
				return !(iter == iter2);
			}

	};
}
