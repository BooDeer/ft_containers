#pragma once

#include <iostream>

template <typename T>
typedef struct Node
{
	struct Node		*parent;		//* The parent node.
	struct Node		*rchild;		//* The right child node.
	struct Node		*lchild;		//* The left child node.
	T				*data;			//* Pointer to the data hold by the node.

	Node (Node *__pr, Node *__rch, Node *__lch, T* __data): parent(__pr), rchild(__rch), lchild(__lch), data(__data);
}	node;


template <class __T, class __Compare = std::less<__T>, class __Allocator = std::allocator<__T> >
class AvlBST
{
	public:
		//* Types.
		typedef __T									value_type;
	
	public:
		//* Copy contructor.
		AvlBST( const AvlBST& src )
		{
			*this = src;
		};
		//* Assignement operator.
		AvlBST& operator=( const AvlBST& rhs)
		{
			__PAR	= rhs.__PAR;
			__RC	= rhs.__RC;
			__LC	= rhs.__LC;
			__Value	= rhs.__Value;
			return *this;
		};
		//* Destructor
		~AvlBST( void )
		{
			//TODO: to be implemented.
			
		};
	//! Insertion methods.
	public:
		AvlBST( void ): __PAR(nullptr), __RC(nullptr), __LC(nullptr), __Value(__T()) {};
		void	insert(value_type __src)
		{
			if ()
		};




	//! ======================================================================================
	private:
		//? Should I keep the default constructor private or not?
		//* Private attributes.
		AvlBST*								__PAR;					//* The parent node.
		AvlBST*								__RC;					//* The right child node.
		AvlBST* 							__LC;					//* The left child node.
		__T									__Value;				//* The hold data.
		node								__root;
		__Compare							__cmp;
};

/* 

const char * hamada
char const * hamada
char * const ha

*/