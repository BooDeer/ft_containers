#pragma once

#include <iostream>


template <class _Iter>
class	_ft_random_iterator: public std::iterator<std::random_access_iterator_tag, _Iter>
{
	private:
		_Iter*	_ptr;
	public:
		typedef _Iter					iterator_type;
		//TODO: requires iterator_traits class to be implemented
		typedef typename iterator_traits<iterator_type>::iterator_category	iterator_category;
};