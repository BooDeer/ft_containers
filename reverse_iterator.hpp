#pragma once

#include <iostream>

template <typename _Iter>
class	random_reverse_iterator
{
	public:
		typedef _Iter														iterator_type; //* The received value, such as int.
		//TODO: requires iterator_traits class to be implemented
		// typedef std::random_access_iterator_tag								iterator_category; <== Doesn't exist in the reverse iterator. (TO be checked)
		typedef typename _Iter::value_type									value_type;
		typedef ptrdiff_t													difference_type;
		typedef typename _Iter::pointer										pointer;
		typedef typename _Iter::reference									reference;

	public:
		//! The canonical form.
		random_reverse_iterator( void ): __Current(nullptr) {};
		random_reverse_iterator(iterator_type it): __Current(it) {};
		template<typename Iter>
		random_reverse_iterator	(const random_reverse_iterator<Iter>& rev_it)
		{
			this->__Current = rev_it.base();
		};
		random_reverse_iterator& operator=(const random_reverse_iterator<_Iter>& rhs)
		{

		}
		
		~random_reverse_iterator( void ) {};
		
		iterator_type	base() const
		{
			return iterator_type(__Current);
		}
		//! The overloaded operators.
		reference	operator*()
		{
			iterator_type __tmp = __Current;
			return *--__tmp;
		}

		random_reverse_iterator operator+(difference_type n) const
		{
			return (random_reverse_iterator(__Current - n));
		}
		random_reverse_iterator operator++() {
			return (random_reverse_iterator(__Current--));
		} ;
		random_reverse_iterator operator++(int) {
			random_reverse_iterator tmp = *this;
			++(*this);
			return (random_reverse_iterator(tmp));
		};
		random_reverse_iterator operator--() {
			return (random_reverse_iterator(__Current++));
		} ;
		random_reverse_iterator operator--(int) {
			random_reverse_iterator tmp = *this;
			--(*this);
			return (random_reverse_iterator(tmp));
		};
		random_reverse_iterator& operator+=(difference_type n)
		{
			__Current -= n;
			return (*this);
		}
		
		random_reverse_iterator& operator-=(difference_type n)
		{
			__Current += n;
			return (*this);
		}
		random_reverse_iterator operator-(difference_type n) const
		{
			return (random_reverse_iterator(__Current + n));
		}

		pointer	operator->() const {
			return &(operator*());
		}

		reference	operator[](difference_type __n) const {
			return *(*this + __n);
		}		
		template <typename iter>
		friend random_reverse_iterator operator+(typename random_reverse_iterator<iter>::difference_type __n, const random_reverse_iterator<iter>& __x)
		{
			random_reverse_iterator<iter>(__x.base() - __n);
		}
		template <typename iter>
		friend random_reverse_iterator operator_(typename random_reverse_iterator<iter>::difference_type __n, const random_reverse_iterator<iter>& __x)
		{
			random_reverse_iterator<iter>(__x.base() + __n);
		}
		template <typename iter>
		friend bool	operator==(const random_reverse_iterator<iter>& lhs, const random_reverse_iterator<iter>& rhs)
		{
			return (*(lhs.__Current.base()) == *(rhs.__Current.base())) ? true : false;
		};

		template <typename iter>
		friend bool	operator!=(const random_reverse_iterator<iter>& lhs, const random_reverse_iterator<iter>& rhs)
		{
			return (lhs.__Current.base() == rhs.__Current.base()) ? false : true;
		};
		template <typename iter>
		friend bool operator< (const random_reverse_iterator<iter>& lhs, const random_reverse_iterator<iter>& rhs)
		{
			return (lhs.__Current.base() < rhs.__Current.base()) ? true : false;
		};
		template <typename iter>
		friend bool operator<= (const random_reverse_iterator<iter>& lhs, const random_reverse_iterator<iter>& rhs)
		{
			return (lhs.__Current.base() <= rhs.__Current.base()) ? true : false;
		};
		template <typename iter>
		friend bool operator> (const random_reverse_iterator<iter>& lhs, const random_reverse_iterator<iter>& rhs)
		{
			return (lhs.__Current.base() > rhs.__Current.base()) ? true : false;
		};
		template <typename iter>
		friend bool operator>= (const random_reverse_iterator<iter>& lhs, const random_reverse_iterator<iter>& rhs)
		{
			return (lhs.__Current.base() >= rhs.__Current.base()) ? true : false;
		};
	private:
		_Iter	__Current;
};