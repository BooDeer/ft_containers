/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudhir <hboudhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 14:54:59 by hboudhir          #+#    #+#             */
/*   Updated: 2022/03/06 16:22:07 by hboudhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <set>
#include <iostream>
#include "macro.hpp"
#include "stack.hpp"
#include <stack>
#include <vector>
#include <map>
#include "vector.hpp"
#include "avlBST.hpp"
#include "utility.hpp"
#include "mapIterator.hpp"
#include "map.hpp"
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
		// mapIterator<ft::pair<int, int> >	test;
		ft::map<int, int>		mapT;

		for(int i = 1; i <= 3; i++)
			mapT.insert(ft::pair<int,int>(i * 10, i * 10));
		mapT.__TreeRoot.printBT();
		ft::map<int, int>::iterator	it1;
		ft::map<int, int>::iterator	it2;

		it1 = mapT.begin();
		it2 = mapT.end();
		

		int i = 0;
		while (it1 != it2 && i < 5)
		// while (it1 != it2)
		{
			LOG((*it1).first);
			it1++;
			i++;
		}
		// for(int i = 0; i < 100; i++)
		// 	test.insert(ft::make_pair<int, int>(i * 10, i * 10));
		// test.debug();
		// test.deleteNode(ft::make_pair<int, int>(630, 100));
		// test.debug();
		// AvlBST<ft::pair<int, std::string> >	test;
		
		// for(int i = 1; i <= 10; i++)
		// 	test.__root = test.insertNode(test.__root, ft::make_pair<int, std::string>(i * 10, std::string("This is a test")));
		// test.printBT(test.__root);
		// for(int i = 1; i < 10; i++)
		// 	__root = insertNode(__root, i * 10);
		// printBT(__root);
		// __root = deleteNode(__root, 60);
		// __root = deleteNode(__root, 70);
		// printBT(__root);
	}
	LOG("============================== STD::VECTOR  ==============================\n\n");
	{















		
		// int arr[] = {0, 1, 2,3,4};
		// std::set<int>	test2(arr, arr + 4);
		// ft::vector<int> test(test2.begin(), test2.end());
		
		// std::<int, int>::iterator	test;













	}











	return (0);
}













