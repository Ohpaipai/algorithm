#include<iostream>
using namespace std;
int main()
{
	int size = 8;
	int after[64];
	int before[64] = { 0,1,2,3,4,5,6,7 };
	for (int i = 0; i < 8; i++)
	{
		cout << before[i] << "\n";
	}
	for (int i = 1, j = 0; i < size; i++)
	{
		for (int k = size/2; !((j ^= k) & k); k /= 2)
		{
			if (i > j)
			{
				std::cout << i << "-->" << j << std::endl;
				double t = before[i];
				before[i] = before[j];
				before[j] = t;
			}
		}

	}
	cout << "////////////////////////////////////\n";
	for (int i = 0; i < 8; i++)
	{
		cout << before[i] << "\n";
	}
	system("pause");
	return 0;
}