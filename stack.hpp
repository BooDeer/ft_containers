#pragma once

#include "ft_namespace.hpp"

template <class T, class Container = std::deque<T>
>class	ft::stack
{
	public:
		typedef Container									container_type;
		typedef typename container_type::value_type			value_type;
		typedef typename container_type::reference			reference;
		typedef typename container_type::const_reference	const_reference;
		typedef typename container_type::size_type			size_type;

		explicit stack( const container_type& ctnr = container_type() );

	private:
		container_type c; //* The underlying container.
	protected:

};