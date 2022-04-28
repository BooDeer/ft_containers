#pragma once

#include <iostream>

namespace ft
{

	template <class _Iter>
	class	random_access_iterator
	{
		private:
			typedef	random_access_iterator<const _Iter>							const_iterator;
		public:
			typedef _Iter														iterator_type;
			typedef std::random_access_iterator_tag								iterator_category;
			typedef _Iter														value_type;
			typedef ptrdiff_t													difference_type;
			typedef _Iter*														pointer;
			typedef _Iter&														reference;

		public:
			random_access_iterator( void ): __Ptr(nullptr) {};

			random_access_iterator( pointer ptr ): __Ptr(ptr) {};

			random_access_iterator(const random_access_iterator& src) {
				*this = src;
			};

			random_access_iterator& operator=(const random_access_iterator& rhs) {
				this->__Ptr = rhs.__Ptr;
				return *this;
			};

			~random_access_iterator( void ) {};

			operator const_iterator() const{
				return  const_iterator(this->__Ptr);
			}
			pointer	base()
			{
				return __Ptr;
			}

		
		public:

			template <typename iter1, typename iter2>
			friend bool	operator==(const iter1& lhs,const iter2& rhs)
			{
				return (lhs.__Ptr) == (rhs.__Ptr);
			};

			template <typename iter1, typename iter2>
			friend bool	operator!=(const iter1& lhs, const iter2& rhs)
			{
				return (lhs.__Ptr == rhs.__Ptr) ? false : true;
			};

			reference operator*() const
			{
				return *__Ptr;
			};

			pointer operator->() const
			{
				return __Ptr;
			};

			reference	operator*(iterator_type)
			{
				return __Ptr;
			}

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

				return (__f.base() - __s.base());
			}

			void	operator+=(const int& __n) { __Ptr = __Ptr + __n; }
			
			void	operator-=(const int& __n) { __Ptr = __Ptr - __n; }

			template <class iter1, class iter2>		
			friend bool	operator<(const iter1& lhs,const iter2& rhs)
			{
				return ((lhs.__Ptr < rhs.__Ptr));
			};

			template <class iter1, class iter2>		
			friend bool	operator<=(const iter1& lhs,const iter2& rhs)
			{
				return ((lhs.__Ptr <= rhs.__Ptr));
			};

			template <class iter1, class iter2>		
			friend bool	operator>(const iter1& lhs,const iter2& rhs)
			{
				return ((lhs.__Ptr > rhs.__Ptr));
			};

			template <class iter1, class iter2>		
			friend bool	operator>=(const iter1& lhs,const iter2& rhs)
			{
				return ((lhs.__Ptr >= rhs.__Ptr));
			};

			reference	operator[](int i) const
			{
				return (__Ptr[i]);
			};

		private:
			pointer			__Ptr;
	};
}
