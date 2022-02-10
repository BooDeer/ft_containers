#pragma once

#include <iostream>
#include <deque>

namespace ft
{
	template <class T, class Container = std::deque<T> >class	stack;
	template < class T, class Alloc = allocator<T> > class vector; // generic template
}