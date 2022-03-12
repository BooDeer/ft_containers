/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudhir <hboudhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 14:54:59 by hboudhir          #+#    #+#             */
/*   Updated: 2022/03/12 14:16:09 by hboudhir         ###   ########.fr       */
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
#include <unistd.h>
#include <sys/time.h>
#define TIME_FAC 20 // the ft::map methods can be slower up to std::map methods * TIME_FAC (MAX 20)
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
time_t get_time(void)
{
    struct timeval time_now;

    gettimeofday(&time_now, NULL);
    time_t msecs_time = (time_now.tv_sec * 1e3) + (time_now.tv_usec / 1e3);
    return (msecs_time);
}

int main( void )
{
	{
            // time_t start, end, diff;

            std::map<int, std::string> m;
            ft::map<int, int> my_m;
            ft::map<int, int>::iterator itB;
            ft::map<int, int>::iterator itE;

			for(int i = 0; i < 5; i++)
				my_m.insert(ft::make_pair(i * 10, i * 10));
			// std::cout << "----> end node: " << my_m.__TreeRoot.end_node << std::endl;
			itB = my_m.begin();
			// std::cout << "----> begin node: " << my_m.begin().__Node << std::endl;
			itE = my_m.end();
			// std::cout << "----> end node: " <<  my_m.end().__Node << std::endl;
			// std::cout << "----> end node: " <<  itE.__Node << std::endl;
			int i = 0;
			my_m.__TreeRoot.printBT();
			for(; itB != itE; itB++)
				// std::cout << "----> end node: " <<  itB.__Node << std::endl;
				LOG((*itB).first);
				std::cout << "----> end node: " <<  itB.__Node << std::endl;
			
            // ft::map<int, std::string>::reverse_iterator it;
            // ft::map<int, std::string>::const_reverse_iterator it;
            // ft::map<int, char>::iterator it = my_m.begin();
			// ++it;
			// ft::map<int, char>::iterator my_rit2(my_m.end());
			// ft::map<int, char>::const_iterator c_it, c_ob(my_m.end());
			// c_it = my_rit2;
			// c_it++;
			// my_rit2->first;
			// // ft_m.insert(ft::make_pair(1, "value"));
            // for (size_t i = 0; i < 1e6; ++i)
            // {
            //     // m.insert(std::make_pair(i, "value"));
            //     ft_m.insert(ft::make_pair(i, "value"));
            //     // LOG((*(ft_m.insert(ft::make_pair(i, "value")).first)).first);
			// 	 std::cout << "-->" << i << std::endl;
            // }
            // start = get_time();
            // for (std::map<int, std::string>::iterator it = m.begin(); it != m.end(); ++it)
            //     ;
            // end = get_time();
            // diff = end - start;
            // diff = (diff) ? (diff * TIME_FAC) : TIME_FAC;

            // ualarm(diff * 1e3, 0);
            // for (ft::map<int, std::string>::iterator it = ft_m.begin(); it != ft_m.end(); ++it)
            //     ;
            // ualarm(0, 0);
        }
	// LOG("\n\n=============================== STD::MAP  ================================\n\n");
	// {
	// 	// mapIterator<ft::pair<int, int> >	test;
	// 	ft::map<int, int>		mapT;
	// 	// LOG("The end_node address: " << mapT.__TreeRoot.end_node);
	// 	for(int i = 1; i <= 5; i++)
	// 		mapT.insert(ft::pair<int,int>(i * 10, i * 10));
	// 	mapT.insert(ft::pair<int,int>(10, 10));
	// 	mapT.__TreeRoot.printBT();
	// 	// LOG("The end_node address: " << mapT.__TreeRoot.end_node);
	// 	// mapT.__TreeRoot.printBT();
	// 	// ft::map<int, int>::iterator	it1;
	// 	// ft::map<int, int>::iterator	it2;
	// 	// LOG("The end_node address: " << mapT.__TreeRoot.end_node);
		
	// 	// it1 = mapT.begin();
	// 	// LOG("First tree" << it1.__Tree.mv_ch);
	// 	// it2 = mapT.end();
	// 	// it2--;
	// 	// it2--;
	// 	// LOG((*it2).first);
	// 	// int i = 0;
	// 	// // while (it1 != it2)
	// 	// // while (it1 != it2)
	// 	// // {
	// 	// // 	std::cout << (*it1).first << " ";
	// 	// // 	it1++;
	// 	// // }
	// 	// LOG("");
	// 	// for(int i = 0; i < 100; i++)
	// 	// 	test.insert(ft::make_pair<int, int>(i * 10, i * 10));
	// 	// test.debug();
	// 	// test.deleteNode(ft::make_pair<int, int>(630, 100));
	// 	// test.debug();
	// 	// AvlBST<ft::pair<int, std::string> >	test;
		
	// 	// for(int i = 1; i <= 10; i++)
	// 	// 	test.__root = test.insertNode(test.__root, ft::make_pair<int, std::string>(i * 10, std::string("This is a test")));
	// 	// test.printBT(test.__root);
	// 	// for(int i = 1; i < 10; i++)
	// 	// 	__root = insertNode(__root, i * 10);
	// 	// printBT(__root);
	// 	// __root = deleteNode(__root, 60);
	// 	// __root = deleteNode(__root, 70);
	// 	// printBT(__root);
	// }
	LOG("============================== STD::VECTOR  ==============================\n\n");
	{















		
		// int arr[] = {0, 1, 2,3,4};
		// std::set<int>	test2(arr, arr + 4);
		// ft::vector<int> test(test2.begin(), test2.end());
		
		// std::<int, int>::iterator	test;



		std::vector<int> test;









	}











	return (0);
}













