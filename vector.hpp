#pragma once

#include <iostream>
#include <memory>

template < class T, class Alloc = std::allocator<T> > class vector
{
	// Public--<begin>
	public:
	typedef T												value_type; 		//* First parametre of the templated class. (T)
	typedef Alloc											allocator_type; 	//* Second parametre of the templated class. (Alloc)
	typedef	typename allocator_type::reference				reference; 			//* Reference to the allocator_type. (AKA the second parametre of the templated class)
	typedef	typename allocator_type::const_reference		const_reference;	//* Const reference to the allocator_type. (AKA the second parametre of the templated class)
	typedef	typename allocator_type::pointer				pointer;
	typedef	typename allocator_type::const_pointer			const_pointer;
	//TODO: implement the iterators to be used.
	typedef	iterator<pointer>								iterator;
	typedef	iterator<const_pointer>									const_iterator;
	typedef										reverse_iterator;
	typedef	xxx									const_reverse_iterator;
	typedef	xxx									difference_type;
	//TODO <=======================================>
	typedef	size_t								size_type;

	// Public--<end>
};
