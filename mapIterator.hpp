#pragma once

#include <iostream>
#include "avlBST.hpp"


// template <class __Iter, class Compare = std::less<__Iter> >
// class	mapIterator
// {
// 	public:
// 		//* Types.
// 		typedef __Iter													iterator_type;
// 		typedef std::bidirectional_iterator_tag							iterator_category;
// 		typedef	iterator_type											value_type;
// 		typedef	std::ptrdiff_t											difference_type;
// 		typedef	__Iter*													pointer;
// 		typedef	__Iter&													reference;



// 	//! The canonical form.
// 	public:
// 		//* Default constructor.
// 		mapIterator ( void ) {
// 			LOG("[mapIterator] Default constructor.");
// 		};
// 		// // Constructor with a parameter.
// 		//* Copy constructor.
// 		mapIterator(const mapIterator& src) {
// 			*this = src;
// 		}

// 		mapIterator& operator=( const mapIterator& rhs )
// 		{
// 			this->__Tree = rhs.__Tree;
			
// 			return *this;
// 		}
// 		~mapIterator ( void )
// 		{
// 			//TODO: Implement the destructor.
			
// 		}

// 	//TODO: Insert, delete and other member functions related to the tree shall be converted to private member functions later.
// 	//TODO: (currently public just for the sake of testing)
// 	public:
// 		void	insert(const value_type& node)
// 		{
// 			this->__Tree.insertNode(node);
// 		}

// 		void	deleteNode(const value_type& node)
// 		{
// 			__Tree.deleteNode(node);
// 		}
// 	//! Debug functions.
// 		void	debug( void )
// 		{
// 			this->__Tree.printBT(__Tree.__root);
// 		}




// 	private:
// 		__Iter				*__Tree;
// };