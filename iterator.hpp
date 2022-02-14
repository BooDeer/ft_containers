#pragma once

#include <iostream>





// template <class Category, class T, class Distance = ptrdiff_t,
//           class Pointer = T*, class Reference = T&>
//   struct iterator {
//     typedef T         value_type;
//     typedef Distance  difference_type;
//     typedef Pointer   pointer;
//     typedef Reference reference;
//     typedef Category  iterator_category;
//   };


// template<class Iterator>
// struct iterator_traits
// {
// 	typedef typename Iterator::difference_type		difference_type;
// 	typedef typename Iterator::value_type			value_type;
// 	typedef typename Iterator::pointer				pointer;
// 	typedef typename Iterator::reference			reference;
// 	typedef typename Iterator::iterator_category	iterator_category;
// };




template <class _Iter>
class	iterator
{
	public:
		typedef _Iter														iterator_type;
		//TODO: requires iterator_traits class to be implemented
		// typedef typename iterator_traits<iterator_type>::iterator_category	iterator_category;
		// typedef typename iterator_traits<iterator_type>::value_type			value_type;
		// typedef typename iterator_traits<iterator_type>::difference_type	difference_type;
		// typedef typename iterator_traits<iterator_type>::pointer			pointer;
		// typedef typename iterator_traits<iterator_type>::reference			reference;

	//! The canonical form.
	public:
		//* Default constructor.
		iterator( void ): __Ptr(nullptr) {};
		//* Constructor with a parameter. (The pointer to array (mainly when you call iterator begin() in the vector class))
		iterator( const iterator_type ptr): __Ptr(ptr) {};
		//* Copy constructor.
		iterator(const iterator& src) {
			*this = src;
		};
		//* Assignement operator.
		iterator& operator=(const iterator& rhs) {
			this->__Ptr = rhs.__Ptr;
			LOG("Passing: " << __Ptr[0]);
			return *this;
		};
		//* Destructor.
		~iterator( void ) {};
	//! ================================

	//! The public operators.
	public:
		// bool	operator==(const Iterator& rhs) const
		// {
		// };
		// bool	operator!=(const Iterator& rhs) const;
		iterator_type operator*(const iterator& rhs) const
		{
			return *__Ptr;
		};
		// /*xxx*/ operator->(const Iterator& rhs) const;
		// //TODO: operator "*a = t"
		// //TODO: operators: "++a, a++, --a, a--"
		// /*xxx*/ operator++(const Iterator& rhs) const;
		// //TODO: operators: "a +/- b" "b +/- a" ps: (+ or -)
		// /*xxx*/ operator+(const Iterator& rhs) const;
		// bool	operator<(const Iterator& rhs) const;
		// bool	operator<=(const Iterator& rhs) const;
		// bool	operator>(const Iterator& rhs) const;
		// bool	operator>=(const Iterator& rhs) const;
		// Iterator&	operator+=(const Iterator &rhs) const;
		// Iteraotr&	operator--(const Iterator &rhs) const;
		//TODO: operator: a[n]

	private:
		iterator_type			__Ptr;
};