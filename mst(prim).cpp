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

bool WeightComp(edge e1, edge e2) {
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
	int* v = new int[n];
	int* key = new int[n];
	int* vistied = new int[n];
	for (int i = 0; i < n; i++)
	{
		v[i] = -1;//vertex沒有predecessor ->-1
		key[i] = 99999;//key設違無限大
		vistied[i] = 0;
	}
	//v0當作起點
	int start = 0;
	key[start] = 0;
	
	int u;
	for (int i = 0; i <n; i++)
	{
		int min = 99999;
		int minidx = 0;
		for (int j = 0; j < n; j++)
		{
			if (vistied[j] == 0 && key[j] < min)
			{
				min = key[j];
				minidx = j;
			}
		}
		vistied[minidx] = 1;
		for (int j = 0; j < n; j++)
		{
			if (vistied[j] == 0 && adjenctyMatrix[minidx][j] != 0 && adjenctyMatrix[minidx][j] < key[j]) {
				v[j] = minidx;
				key[j] = adjenctyMatrix[minidx][j];
			}
		}

	}
	int i = (start + 1) % n;   // 若從4開始, i依序為5,6,0,1,2,3
	while (i != start) {
 		std::cout << "   " << v[i] << " - " << "   " << i
			<< " : " << "    " << adjenctyMatrix[v[i]][i] << "\n";
		i = (++i) % n;       // 到了6之後, 6+1 = 7, error:bad_access, 透過mod把7喬回0
	}
	system("pause");
	return 0;
}
//7
//11
//0 5 3
//0 1 5
//1 4 1
//5 4
//6
//1 2 10
//1 6 4
//4 6 2
//4 3 7
//6 3 9
//6 2 8
//2 3 5