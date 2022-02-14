#pragma once

#include <iostream>



//! The below iterators (Base iterator and iterator_traits) are not mandatory, but needed in the subject
//* The base class for all the iterators.
// template <class Category, class T, class Distance = ptrdiff_t,
//           class Pointer = T*, class Reference = T&>
//   struct iteratorBase {
//     typedef T         value_type;
//     typedef Distance  difference_type;
//     typedef Pointer   pointer;
//     typedef Reference reference;
//     typedef Category  iterator_category;
//   };


// template<class T>
// struct iterator_traits
// {
// 	typedef typename T::difference_type		difference_type;
// 	typedef typename T::value_type			value_type;
// 	typedef typename T::pointer				pointer;
// 	typedef typename T::reference			reference;
// 	typedef typename T::iterator_category	iterator_category;
// };

// template<class T>
// struct iterator_traits<T *>
// {
// 	typedef typename Iterator::difference_type		difference_type;
// 	typedef typename Iterator::value_type			value_type;
// 	typedef typename Iterator::pointer				pointer;
// 	typedef typename Iterator::reference			reference;
// 	typedef typename Iterator::iterator_category	iterator_category;
// };



// template <class Category, class T, class Distance = ptrdiff_t,
//           class Pointer = T*, class Reference = T&>

template <class _Iter>
class	iterator
{
	public:
		typedef _Iter														iterator_type;
		//TODO: requires iterator_traits class to be implemented
		typedef std::random_access_iterator_tag								iterator_category;
		typedef _Iter														value_type;
		typedef ptrdiff_t													difference_type;
		typedef _Iter*														pointer;
		typedef _Iter&														reference;

	//! The canonical form.
	public:
		//* Default constructor.
		iterator( void ): __Ptr(nullptr) {};
		//* Constructor with a parameter. (The pointer to array (mainly when you call iterator begin() in the vector class))
		iterator( pointer ptr ): __Ptr(ptr) {};
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
		bool	operator==(const iterator& rhs) const
		{
			return (*__Ptr == *(rhs.__Ptr)) ? true : false;
		};
		bool	operator!=(const iterator& rhs) const
		{
			return (*__Ptr == *(rhs.__Ptr)) ? false : true;
		};
		reference operator*() const
		{
			return *__Ptr;
		};
		pointer operator->() const
		{
			return __Ptr;
		};
		//TODO: operator "*a = t"
		reference	operator*(iterator_type) //? lvalue can be overloaded the same way you overload pre increment operator. (++a)
		{
			return __Ptr;
		}
		//TODO: operators: "++a, a++, --a, a--"
		iterator	operator++(int)
		{
			iterator tmp;
			tmp.__Ptr = __Ptr++;
			return tmp;
		}
		iterator	operator++( )
		{
			iterator tmp;
			tmp.__Ptr = ++__Ptr;
			return tmp;
		}
		iterator	operator--(int)
		{
			iterator tmp;
			tmp.__Ptr = __Ptr--;
			return tmp;
		}
		iterator	operator--( )
		{
			iterator tmp;
			tmp.__Ptr = --__Ptr;
			return tmp;
		}		
		//TODO: operators: "a +/- b" "b +/- a" ps: (+ or -)
		iterator	operator+(const int rhs) const
		{

		}
		// /*xxx*/ operator+(const Iterator& rhs) const;
		// bool	operator<(const Iterator& rhs) const;
		// bool	operator<=(const Iterator& rhs) const;
		// bool	operator>(const Iterator& rhs) const;
		// bool	operator>=(const Iterator& rhs) const;
		// Iterator&	operator+=(const Iterator &rhs) const;
		// Iteraotr&	operator--(const Iterator &rhs) const;
		//TODO: operator: a[n]

	private:
		pointer			__Ptr;
};


/* 

int a = 110;
a;
int b = function(std::string("test")); // &a;

*/