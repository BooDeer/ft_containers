#pragma once

#include <iostream>



//! The below iterators (Base random_access_iterator and iterator_traits) are not mandatory, but needed in the subject
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
// 	typedef typename random_access_iterator::difference_type		difference_type;
// 	typedef typename random_access_iterator::value_type			value_type;
// 	typedef typename random_access_iterator::pointer				pointer;
// 	typedef typename random_access_iterator::reference			reference;
// 	typedef typename random_access_iterator::iterator_category	iterator_category;
// };



// template <class Category, class T, class Distance = ptrdiff_t,
//           class Pointer = T*, class Reference = T&>

template <class _Iter>
class	random_access_iterator
{
	private:
		typedef	random_access_iterator<const _Iter>							const_iterator;
	public:
		typedef _Iter														iterator_type; //* The received value, such as int.
		//TODO: requires iterator_traits class to be implemented
		typedef std::random_access_iterator_tag								iterator_category;
		typedef _Iter														value_type;
		typedef ptrdiff_t													difference_type;
		typedef _Iter*														pointer;
		typedef _Iter&														reference;

	//! The canonical form.
	public:
		//* Default constructor.
		random_access_iterator( void ): __Ptr(nullptr) {};
		//* Constructor with a parameter. (The pointer to array (mainly when you call random_access_iterator begin() in the vector class))
		random_access_iterator( pointer ptr ): __Ptr(ptr) {
		};
		//* Copy constructor.
		random_access_iterator(const random_access_iterator& src) {
			*this = src;
		};
		//* Assignement operator.
		random_access_iterator& operator=(const random_access_iterator& rhs) {
			this->__Ptr = rhs.__Ptr;
			return *this;
};
		//* Destructor.
		~random_access_iterator( void ) {};

		//? The heck does this do and why and how	
		operator const_iterator() const{
	   		return  const_iterator(this->__Ptr);
		}
	//! ================================
		pointer	base()
		{
			return __Ptr;
		}
	//! Public methods.

	//! ================================
	
	//! The public operators.
	public:
		template <typename iter1, typename iter2>
		friend bool	operator==(random_access_iterator<iter1>& lhs,random_access_iterator<iter2>& rhs)
		{
			return (*(lhs.base()) == *(rhs.base())) ? true : false;
		};

		template <typename iter1, typename iter2>
		friend bool	operator!=(random_access_iterator<iter1>& lhs, random_access_iterator<iter2>& rhs)
		{
			return (*(lhs.base()) == *(rhs.base())) ? false : true;
		};
		reference operator*() const
		{
			return *__Ptr;
		};
		pointer operator->() const
		{
			return __Ptr;
		};
		reference	operator*(iterator_type) //? lvalue can be overloaded the same way you overload pre increment operator. (++a)
		{
			return __Ptr;
		}

		//! Arithmetic operators.
		random_access_iterator	operator++(int)
		{
			random_access_iterator tmp;
			tmp.__Ptr = __Ptr++;
			return tmp;
		}
		random_access_iterator	operator++( )
		{
			random_access_iterator tmp;
			tmp.__Ptr = ++__Ptr;
			return tmp;
		}
		random_access_iterator	operator--(int)
		{
			random_access_iterator tmp;
			tmp.__Ptr = __Ptr--;
			return tmp;
		}
		random_access_iterator	operator--( )
		{
			random_access_iterator tmp;
			tmp.__Ptr = --__Ptr;
			return tmp;
		}		
		random_access_iterator	operator+(const int& rhs) const
		{
			return random_access_iterator(__Ptr + rhs);
		}
		template <typename iter>
		friend random_access_iterator<iter>	operator+(typename random_access_iterator<iter>::difference_type __n, random_access_iterator<iter>__x)
		{
			__x = __x + __n;
			return __x;
		}
		
		random_access_iterator	operator-(const int& rhs) const
		{
			return random_access_iterator(__Ptr - rhs);
		}

		template <typename iter>
		friend random_access_iterator<iter>	operator-(typename random_access_iterator<iter>::difference_type __n, random_access_iterator<iter>__x)
		{
			__x = __x - __n;
			return __x;
		}

		template <typename iter>
		friend ptrdiff_t operator-(random_access_iterator<iter> __f, random_access_iterator<iter> __s)
		{
			return (__f - __s);
		}

		void	operator+=(const int& __n) { __Ptr = __Ptr + __n; }
		
		void	operator-=(const int& __n) { __Ptr = __Ptr - __n; }
		//! ================================
		
		//! Comparison operators.
		template <typename iter>		
		friend bool	operator<(random_access_iterator<iter>& lhs, random_access_iterator<iter>& rhs)
		{
			return (*(lhs.base()) < *(rhs.base()) ? true : false);
		};

		template <typename iter>		
		friend bool	operator<=(random_access_iterator<iter>& lhs, random_access_iterator<iter>& rhs)
		{
			return (*(lhs.base()) <= *(rhs.base()) ? true : false);
		};
		
		template <typename iter>		
		friend bool	operator>(random_access_iterator<iter>& lhs, random_access_iterator<iter>& rhs)
		{
			return (*(lhs.base()) > *(rhs.base()) ? true : false);
		};
		template <typename iter>		
		friend bool	operator>=(random_access_iterator<iter>& lhs, random_access_iterator<iter>& rhs)
		{
			return (*(lhs.base()) >= *(rhs.base()) ? true : false);
		};
		//! ================================
		reference	operator[](int i) const
		{
			return (__Ptr[i]);
		};

	private:
		pointer			__Ptr;
};