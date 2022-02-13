#include <memory>
#include <iostream>
#include "macro.hpp"
#include <vector>



int main( void )
{
	
	std::string						*arr;
	std::allocator<std::string> 	t;
	std::vector<int>				vecInt;
	std::allocator<int>				mINT;


	LOG(mINT.max_size());


	LOG(vecInt.max_size());





	return (0);
}