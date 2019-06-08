#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
using namespace std;
typedef struct Mystruct {
	int from;
	int to;
	int weight;
	
}edge;

edge edgeMat[10000];
int adjenctyMatrix[10000][10000];
bool WeightComp( edge e1,  edge e2) {
	return (e1.weight < e2.weight);
}
int FindSetCollapsing(int* subset, int i) {

	int root; 
	for (root = i; subset[root] >= 0; root = subset[root]);

	while (i != root) {
		int parent = subset[i];
		subset[i] = root;
		i = parent;
	}

	return root;
}
void UnionSet(int* subset, int x, int y) {

	int xroot = FindSetCollapsing(subset, x),
		yroot = FindSetCollapsing(subset, y);

	// 用rank比較, 負越多表示set越多element, 所以是值比較小的element比較多
	// xroot, yroot的subset[]一定都是負值
	if (subset[xroot] <= subset[yroot]) {        // x比較多element或是一樣多的時候, 以x作為root
		subset[xroot] += subset[yroot];
		subset[yroot] = xroot;
	}
	else {    //  if (subset[xroot] > subset[yroot]), 表示y比較多element
		subset[yroot] += subset[xroot];
		subset[xroot] = yroot;
	}
}

int main() {
	int n, e;
	cin >> n >> e;
	for (int i = 0; i < e; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		adjenctyMatrix[a][b] = c;
		adjenctyMatrix[b][a] = c;
	}
	int edgecount = 0;
	int* subset = new int[n];
	for (int i = 0; i < n; i++)
	{
		subset[i] = -1;
	}
	std::vector<edge>increaseweight;
	int edgesetcount = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (adjenctyMatrix[i][j] != 0) 
			{
				edge tem;
				tem.from = i;
				tem.to = j;
				tem.weight = adjenctyMatrix[i][j];
				increaseweight.push_back(tem);
			}
		}
	}
	std::sort(increaseweight.begin(), increaseweight.end(), WeightComp); //排序好edge
	for (int i = 0; i < increaseweight.size(); i++)
	{
		for (int i = 0; i < increaseweight.size(); i++) {
			if (FindSetCollapsing(subset, increaseweight[i].from) != FindSetCollapsing(subset, increaseweight[i].to)) {
				edgeMat[edgesetcount++] = increaseweight[i];
				UnionSet(subset, increaseweight[i].from, increaseweight[i].to);
			}
		}
	}
	for (int i = 0; i < n - 1; i++) {
		std::cout << "   " << edgeMat[i].from << " - " << "   " << edgeMat[i].to
			<< " : " << "    " << edgeMat[i].weight << "\n";
	}
	system("pause");
	return 0;
}