/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boodeer <boodeer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 14:54:59 by hboudhir          #+#    #+#             */
/*   Updated: 2022/02/24 21:16:56 by boodeer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "macro.hpp"
// #include "stack.hpp"
// #include <stack>
#include <vector>
// #include <map>
#include "vector.hpp"
#include "avlBST.hpp"

/*
	// template <class iter>
	// size_t do_distance(iter it,iter end, std::random_access_iterator_tag)
	// {
	// 	return end - it;
	// }

	// template <class iter>
	// size_t do_distance(iter it,iter end, std::input_iterator_tag)
	// {
	// 	size_t k = 0;
	// 	while(it != end)
	// 		k++, it++;
	// 	return k;
	// }

	// template <class iter>
	// size_t ft_distance(iter it, iter end)
	// {
	// 	do_distance(it,end, iterator_triats<iter>::iterator_category())
	// }

	// template <class T>
	// void	print(void)
	// {
	// 	T* c;
	// 	std::cout << "test" << std::endl;
	// }

	// template<>
	// void	print<int>( void )
	// {
	// 	std::cout << "test22" << std::endl;
	// }
*/	

int main( void )
{
	
	LOG("\n\n=============================== STD::MAP  ================================\n\n");
	{
		// AvlBST<std::string>	test;
		Node*	__root = NULL;
		__root = insertNode(__root, 10);
		__root = insertNode(__root, 13);
		__root = insertNode(__root, 14);
		__root = insertNode(__root, 9);

		LOG(findNode(__root, 8));



	}
	LOG("============================== STD::VECTOR  ==============================\n\n");
	{















	}











	return (0);
}