#include <iostream>
#include <vector>
#include <list>
#include <utility>          
#include <iomanip>      
using namespace std;
std::vector<std::list<std::pair<int, int>>> AdjList;
std::vector<int> predecessor; 
std::vector<int>distances;
bool negativecycle = false;
int main() {

	int npoints,nedges;
	cin >> npoints >> nedges;
	AdjList.resize(npoints);
	predecessor.resize(npoints);
	distances.resize(npoints);
	for (int i = 0; i < nedges; i++)
	{
		int a, b, c;
		cin >>a>>b>>c;
		AdjList[a].push_back(std::make_pair(b,c));
	}

	int start;
	cin >> start;
	for (int i = 0; i < npoints; i++)
	{
		distances[i] = 9999;
		predecessor[i] = -1;
	}
	distances[start] = 0;
//演算法
	for (int i = 0; i < npoints-1; i++) // |V-1|次的iteration
	{
		for (int j = 0; j < npoints; j++)// 把AdjList最外層的vector走一遍
		{
			for (std::list<std::pair<int, int> >::iterator itr = AdjList[j].begin();
				itr != AdjList[j].end(); itr++)// 各個vector中, 所有edge走一遍
			{
				if (distances[(*itr).first] > distances[j] +(*itr).second)
				{
					distances[(*itr).first] = distances[j] + (*itr).second;
					predecessor[(*itr).first] = j;
				}
			}
		}
	}
	//看有沒有negative
	for (int i = 0; i < npoints; i++)
	{
		for (std::list<std::pair<int, int> >::iterator itr = AdjList[i].begin();
			itr != AdjList[i].end(); itr++)// 各個vector中, 所有edge走一遍
		{
			if (distances[(*itr).first] >  distances[i]+(*itr).second)
			{
				negativecycle = true;
			}
		}
	}
	if (negativecycle)
		cout << "有複還" << endl;
	else
	{
		std::cout << "predecessor[]:\n";
		for (int i = 0; i < npoints; i++)
		{
			
			std::cout << std::setw(4) << i;
		}
		cout << endl;
		for (int i = 0; i < npoints; i++)
		{

			std::cout << std::setw(4) << predecessor[i];
		}
		std::cout << "\ndistances[]:\n";
		for (int i = 0; i < npoints; i++)
		{

			std::cout << std::setw(4) << i;
		}
		cout << endl;
		for (int i = 0; i < npoints; i++)
		{

			std::cout << std::setw(4) << distances[i];
		}
	}
	system("pause");
	return 0;
}
//6
//10
//0 1 5
//1 2 6
//5 1 7
//5 0 3
//1 4 - 4
//2 5 - 2
//4 5 6
//2 4 - 3
//4 3 1
//3 2 4