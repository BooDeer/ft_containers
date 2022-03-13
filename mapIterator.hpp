#pragma once

#include <iostream>
#include "avlBST.hpp"




namespace	ft
{
	template<class T, class Pointer = T*, class Reference = T&>
	class	mapIterator
	{
		public:
			//* Member types.
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
			//! Default Constructor.
			mapIterator() {}
			//! AvlBST Constructor.
			mapIterator(iterator_type* src): __Tree(src) {}
			//! AvlBSt and node constructor.
			mapIterator(iterator_type* src, node* node_src): __Tree(src), __Node(node_src) {}

			//! Copy constructor.
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
			//! Dedededededestructuuuuuuro. 💣💥💣💥💣💥💣💥
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
		
			// template <class it_1, class it_2>
			friend bool operator!=(const mapIterator  &iter, const mapIterator &iter2){
				return !(iter == iter2);
			}

	};
}

// template <class Avltree>
// class	mapIterator
// {
// 	public:
// 		//* Types.
// 		typedef Avltree													iterator_type;
// 		typedef std::bidirectional_iterator_tag							iterator_category;
// 		typedef	typename iterator_type::value_type						value_type;
// 		typedef typename iterator_type::Node*							node_pointer;
// 		typedef	std::ptrdiff_t											difference_type;
// 		// typedef	iterator_type*											pointer;	//! Check the typedef related to the pointer.
// 		typedef	value_type&												reference;
// 		typedef	value_type*												pointer;

// 	private:
// 		typedef mapIterator< const Avltree>								const_iterator;

// 	//! The canonical form.
// 	public:
// 		//* Default constructor.
// 		mapIterator ( void ) {};
// 		//* Copy constructor.
// 		mapIterator(const mapIterator& src) {
// 			*this = src;
// 		}
// 		//* Initialization constructor.
// 		mapIterator(const iterator_type& src){
// 			__Tree.__root = src.__root;
// 			__Tree.mv_ch  = src.mv_ch;
// 			__Tree.end_node = src.end_node;
// 		}

// 		mapIterator& operator=(const mapIterator& rhs )
// 		{
// 			// this->__Tree = rhs.__Tree;
// 			__Tree.__root	= rhs.__Tree.__root;
// 			__Tree.mv_ch	= rhs.__Tree.mv_ch;
// 			__Tree.end_node = rhs.__Tree.end_node;
// 			return *this;
// 		}
// 		~mapIterator ( void )
// 		{
// 			//TODO: Implement the destructor.
			
// 		}
// 		operator const_iterator(){
// 			return const_iterator(this->__Tree);
// 		}

// 	//! Arithmetic operations.
// 	public:
// 		mapIterator& operator++()
// 		{
// 			++__Tree;
// 			return *this;
// 		}
// 		mapIterator operator++(int)
// 		{
// 			mapIterator	temp(*this);

// 			++(*this);
// 			return temp;
// 		}
// 		mapIterator& operator--()
// 		{
// 			--__Tree;
// 			return *this;
// 		}
// 		mapIterator operator--(int)
// 		{
// 			mapIterator	temp(*this);

// 			--(*this);
// 			return temp;
// 		}
// 		friend bool operator==(const mapIterator& __x, const mapIterator& __y)
// 		{ return __x.__Tree.mv_ch == __y.__Tree.mv_ch; }
// 		friend bool operator!=	(const mapIterator& __x, const mapIterator& __y)
// 		{
// 			return __x.__Tree.mv_ch != __y.__Tree.mv_ch; }

// 		reference	operator*() const	//! Why does the map iterator return a pointer to the pair.
// 		{
// 			return __Tree.operator*();
// 		}

// 		value_type*		operator->() const
// 		{
// 			return __Tree.operator->();
// 		}
// 	public:
// 		iterator_type				__Tree;
// };