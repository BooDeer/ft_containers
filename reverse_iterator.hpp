#pragma once

#include <iostream>
#include "iterator_traits.hpp"
namespace ft
{

	template <typename _Iter>
	class	reverse_iterator
	{
		public:
			public:
			typedef	_Iter 										 		iterator_type;
			typedef typename iterator_traits<_Iter>::difference_type	difference_type;
			typedef typename iterator_traits<_Iter>::reference      	reference;
			typedef typename iterator_traits<_Iter>::pointer        	pointer;

		public:
			//! The canonical form.
			reverse_iterator( void ): __Current(nullptr) {};
			explicit reverse_iterator(iterator_type it): __Current(it) {};
			template<typename Iter>
			reverse_iterator	(const reverse_iterator<Iter>& rev_it)
			{
				this->__Current = rev_it.base();
			};
			reverse_iterator& operator=(const reverse_iterator<_Iter>& rhs)
			{
				__Current = rhs.base();
				return *this;
			}
			
			~reverse_iterator( void ) {};
			
			iterator_type	base() const
			{
				return (__Current);
			}
			//! The overloaded operators.
			reference	operator*() const
			{
				iterator_type __tmp = __Current;
				return *--__tmp;
			}

			reverse_iterator operator+(difference_type n) const
			{
				return (reverse_iterator(__Current - n));
			}
			// reverse_iterator operator++() {
			// 	return (reverse_iterator(__Current--));
			// } ;
			reverse_iterator operator++(){
				--__Current;
				return (*this);
			}
			reverse_iterator operator++(int) {
				reverse_iterator tmp = *this;
				--__Current;
				return (tmp);
			};
			reverse_iterator operator--() {
				++__Current;
				return (*this);
			};
			reverse_iterator operator--(int) {
				reverse_iterator tmp = *this;
				++__Current;
				return (tmp);
			};
			reverse_iterator& operator+=(difference_type n)
			{
				__Current -= n;
				return (*this);
			}
			
			reverse_iterator& operator-=(difference_type n)
			{
				__Current += n;
				return (*this);
			}
			reverse_iterator operator-(difference_type n) const
			{
				return (reverse_iterator(__Current + n));
			}

			pointer	operator->() const {
				return &(operator*());
				// return nullptr;
			}

			reference	operator[](difference_type __n) const {
				return *(*this + __n);
			}	
			template <class iter1, class iter2>
			friend bool operator< (const reverse_iterator<iter1>& lhs, const reverse_iterator<iter2>& rhs);
			
			
			// template <typename iter>
			// friend reverse_iterator<iter> operator+(typename reverse_iterator<iter>::difference_type __n, const reverse_iterator<iter>& __x)
			// {
			// 	reverse_iterator<iter>(__x + __n);
			// }
			// template <typename iter, typename iter2>
			// friend reverse_iterator<iter> operator-(typename reverse_iterator<iter>::difference_type __n, const reverse_iterator<iter>& __x)
			// {
			// 	reverse_iterator<iter>(__x - __n);
			// }
			// template <typename iter1, typename iter2>
			// friend bool	operator==(const reverse_iterator<iter1>& lhs, const reverse_iterator<iter2>& rhs)
			// {
			// 	return ((lhs.base()) == (rhs.base()));
			// };

			// template <typename iter1, typename iter2>
			// friend bool	operator!=(const reverse_iterator<iter1>& lhs, const reverse_iterator<iter2>& rhs)
			// {
			// 	return (lhs.base() == rhs.base()) ? false : true;
			// };
			// template <typename iter1, typename iter2>
			// friend bool operator< (const reverse_iterator<iter1>& lhs, const reverse_iterator<iter2>& rhs)
			// {
			// 	return (lhs.base() < rhs.base());
			// };
			// template <typename iter1, typename iter2>
			// friend bool operator<= (const reverse_iterator<iter1>& lhs, const reverse_iterator<iter2>& rhs)
			// {
			// 	return (lhs.base() <= rhs.base());
			// };
			// template <typename iter1, typename iter2>
			// friend bool operator> (const reverse_iterator<iter1>& lhs, const reverse_iterator<iter2>& rhs)
			// {
			// 	return (lhs.base() > rhs.base());
			// };
			// template <typename iter1, typename iter2>
			// friend bool operator>= (const reverse_iterator<iter1>& lhs, const reverse_iterator<iter2>& rhs)
			// {
			// 	return (lhs.base() >= rhs.base());
			// };
		private:
			_Iter	__Current;
	};
	template <class it1, class it2>
	bool operator==(const reverse_iterator<it1>& cp1, const reverse_iterator<it2>& cp2)
	{
		return cp1.base() == cp2.base();
	}

	template <class it1, class it2>
	bool operator<  (const reverse_iterator<it1>& cp1, const reverse_iterator<it2>& cp2)
	{
		return (cp1.base() > cp2.base());
	}
	template <class it1, class it2>
	bool operator>  (const reverse_iterator<it1>& cp1, const reverse_iterator<it2>& cp2)
	{
		return (cp1.base() < cp2.base());
	}

	template <class it1, class it2>
	bool operator!=(const reverse_iterator<it1>& cp1, const reverse_iterator<it2>& cp2)
	{
		return cp1.base() != cp2.base();
	}

	template <class it1, class it2>
	bool operator<=(const reverse_iterator<it1>& cp1, const reverse_iterator<it2>& cp2)
	{
		return cp1.base() >= cp2.base();
	}

	template <class it1, class it2>
	bool operator>=(const reverse_iterator<it1>& cp1, const reverse_iterator<it2>& cp2)
	{
		return cp1.base() <= cp2.base();
	}

	//operator- (reverse_iterator)
	template <class it1, class it2>
	typename reverse_iterator<it1>::difference_type operator-(const reverse_iterator<it1>& __x, const reverse_iterator<it2>& __y)
	{
		return (__y.base()) - (__x.base());
	}

	template <class it1>
	reverse_iterator<it1> operator+(typename reverse_iterator<it1>::difference_type __n, const reverse_iterator<it1>& __x)
	{
		return reverse_iterator<it1>((__x.base()) - __n);
	}
}

// typename a;