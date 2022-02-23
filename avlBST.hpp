#pragma once

#include <iostream>

template <class __T> // int 1 2 3 4
class AvlBST
{
	public:
		AvlBST( void );
		AvlBST( const AvlBST& src );
		AvlBST& operator=( const AvlBST& rhs);
		~AvlBST( void );
	protected:

	private:
		AvlBST*	__PAR;					//* The parent node.
		AvlBST*	__RC;					//* The right child node.
		AvlBST* __LC;					//* The left child node.
		__T		__Value;
};