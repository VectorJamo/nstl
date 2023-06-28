#include <iostream>
#include "nvector.h"

int main()
{
	using namespace nstl;

	vector<int> datas;
	datas.reserve(5);

	datas.push_back(1);
	datas.push_back(2);
	datas.push_back(3);
	datas.push_back(4);
	datas.push_back(5);
	datas.push_back(6);
	datas.push_back(7);

	vector<int> datas2 = datas;

	
	std::cout << datas2[6] << std::endl;

	system("PAUSE");
	return 0;
}