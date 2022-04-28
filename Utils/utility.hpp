#pragma once

#include <iostream>

namespace ft
{
	//* This class couples together a pair of values, which may be of different types (T1 and T2).
	//* The individual values can be accessed through its public members first and second.
	template <class __T1, class __T2>
	struct pair
	{
		typedef __T1 first_type;
		typedef __T2 second_type;

		//* The default constructor.
		pair( void ): first(), second() { };

		//* The copy constructor.
		template<class U, class V>
		pair(const pair<U,V>& pr): first(pr.first), second(pr.second) { };

		//* Initialization constructor.
		pair(const first_type&a, const second_type&b): first(a), second(b) { };

		//* The assignement operator.
		pair&	operator=( const pair& rhs )
		{
			first = rhs.first;
			second = rhs.second;
			return (*this);
		};

		//! Relational operators.
		

		//* Member attributes.
		__T1 first;
		__T2 second;
	};

	template <class T1,class T2>
	pair<T1,T2> make_pair (T1 x, T2 y)
	{
		return ( pair<T1,T2>(x,y) );
	}
	template <class __T1, class __T2>
	bool operator==(const pair<__T1, __T2>&lhs,const pair<__T1, __T2>& rhs)
	{
		return lhs.first==rhs.first && lhs.second==rhs.second;
	}
	template <class T1, class T2>
	bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return !(lhs==rhs); }

	template <class T1, class T2>
	bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second); }

	template <class T1, class T2>
	bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return !(rhs<lhs); }

	template <class T1, class T2>
	bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return rhs<lhs; }

	template <class T1, class T2>
	bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return !(lhs<rhs); }
};