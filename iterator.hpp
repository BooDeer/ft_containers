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
			return *this;
		};
		//* Destructor.
		~iterator( void ) {};
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
		friend bool	operator==(iterator<iter1>& lhs,iterator<iter2>& rhs)
		{
			return (*(lhs.base()) == *(rhs.base())) ? true : false;
		};

		template <typename iter1, typename iter2>
		friend bool	operator!=(iterator<iter1>& lhs, iterator<iter2>& rhs)
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
		iterator	operator+(const int& rhs) const
		{
			return iterator(__Ptr + rhs);
		}
		template <typename iter>
		friend iterator<iter>	operator+(typename iterator<iter>::difference_type __n, iterator<iter>__x)
		{
			__x = __x + __n;
			return __x;
		}
		
		iterator	operator-(const int& rhs) const
		{
			return iterator(__Ptr - rhs);
		}

		template <typename iter>
		friend iterator<iter>	operator-(typename iterator<iter>::difference_type __n, iterator<iter>__x)
		{
			__x = __x - __n;
			return __x;
		}

		template <typename iter>
		friend ptrdiff_t operator-(iterator<iter> __f, iterator<iter> __s)
		{
			return (__f - __s);
		}

		void	operator+=(const int& __n) { __Ptr = __Ptr + __n; }
		
		void	operator-=(const int& __n) { __Ptr = __Ptr - __n; }
		//! ================================
		
		//! Comparison operators.
		template <typename iter>		
		friend bool	operator<(iterator<iter>& lhs, iterator<iter>& rhs)
		{
			return (*(lhs.base()) < *(rhs.base()) ? true : false);
		};

		template <typename iter>		
		friend bool	operator<=(iterator<iter>& lhs, iterator<iter>& rhs)
		{
			return (*(lhs.base()) <= *(rhs.base()) ? true : false);
		};
		
		template <typename iter>		
		friend bool	operator>(iterator<iter>& lhs, iterator<iter>& rhs)
		{
			return (*(lhs.base()) > *(rhs.base()) ? true : false);
		};
		template <typename iter>		
		friend bool	operator>=(iterator<iter>& lhs, iterator<iter>& rhs)
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