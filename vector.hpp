#pragma once

#include <iostream>
#include <memory>

template < class T, class Alloc = std::allocator<T> > class Vector
{
	//! Member types.
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
	typedef	iterator<const_pointer>							const_iterator;
	typedef										reverse_iterator;
	typedef	xxx									const_reverse_iterator;
	typedef	xxx									difference_type;
	//TODO <=======================================>
	typedef	size_t								size_type;
	// Public--<end>
	//!=========================================

	//! Orthodox canonical form (Member functions)
	public:
		Vector( void );
		Vector(const Vector& src);
		Vector& operator=(const Vector& rhs);
		~Vector( void );
	//!=========================================

	//! Iterator member functions.
	public:
		//TODO
	//!=========================================

	//! Capacity member functions.
	public:
		size_type	size() const;
		size_type	max_size() const;
		void		resize(size_type n, value_type val = value_type());
		void		reserve(size_type n);
		bool		empty() const;
		size_type	capacity() const;
	//!=========================================

	//! Element access member functions.
	public:
		reference			back();
		const_reference		back() const; //TODO: Search what's the difference between this notation and the one above it.
		reference			front();
		const_reference		front() const;
		reference			at(size_type n);
		const_reference		at(size_type n) const;
		reference			operator[](size_type n);
		const_reference		operator[](size_type n) const;
	//!=========================================

	//! Modifiers member functions.
	public:
		void			clear();
		void			swap(Vector& x);
		iterator		erase(iterator position);
		iterator		erase(iterator first, iterator last);
		iterator		insert(iterator position, const value_type& val);
		void			insert(iterator position, size_type n, const value_type& val);
		template<class InputIterator>
		void			insert(iterator position, InputIterator first, InputIterator last);
		void			pop_back();
		void			push_back(const value_type& val);
		template<class InputIterator>
		void			assign(InputIterator first, InputIterator last);
		void			assign(size_type n, const value_type &val);
	//!=========================================

	//! Allocator member function
	public:
		allocator_type get_allocator() const;
};
