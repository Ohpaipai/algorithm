#include<iostream>
#include<cstdlib>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>
#pragma warning( disable : 4996 )
typedef struct MyStruct
{
	char color;
	int startime;
	int finishtime;

}Vertices;
Vertices vertices[9999]; //點
int Gstep[9999][9999]; //邊
char Gedge[9999][9999]; //邊是屬於哪四種
std::set<double>TemTree;//樹的集合
int Treetime;//時間
bool IssinglyConnectedGraph = true;//是否為singly connected
int componentBackedgenum = 0; //一個component是否超過1個backedge
int notsamecomponentCrossgenum = 0; //一個component是否連到其他component超過1個
void DFS(int start, const int V)//起始位置 跟有幾個 vertices
{
	if (IssinglyConnectedGraph == false) return;
	for (int i = 0; i < V; i++)
	{
		if (Gstep[start][i] == 1 && Gedge[start][i] == 'E')  //兩個點有連接且邊沒用過
		{


			if (vertices[i].color == 'W') //點為白色
			{
				TemTree.insert(start);
				TemTree.insert(i);
				Gedge[start][i] = 'T';//treeedge
				vertices[i].startime = Treetime;
				vertices[i].color = 'G';//變成灰色
				Treetime++;
				DFS(i, V);
				vertices[i].finishtime = Treetime;
				Treetime++;
				vertices[i].color = 'B';//最後變黑色
			}
			else if (vertices[i].color == 'G')//點為灰色
			{
				Gedge[start][i] = 'B';//Backedge
				componentBackedgenum++;
				if (componentBackedgenum > 1)//看是否這個component有兩個以上backedge
					IssinglyConnectedGraph = false;
				/*int a = 0;
				for (int j = 0; j < V; j++)
				{
					if (Gedge[start][j] == 'B')
					{
						a++;
					}
				}
				if (a > 1)
					IssinglyConnectedGraph = false;*/
			}
			else if (vertices[i].color == 'B')//點為黑色
			{
				int exist = TemTree.count(i);
				if (exist == 1)//同一個component
				{
					//vertices[start].startime < vertices[i].startime
					if (Treetime > vertices[i].finishtime) //比他早發現
					{
						Gedge[start][i] = 'F'; //FowardEdge
						IssinglyConnectedGraph = false;
					}
					else {
						Gedge[start][i] = 'C'; //Crossedge
						IssinglyConnectedGraph = false;
					}
				}
				else if (exist == 0)
				{
					Gedge[start][i] = 'C'; //CrossEdge
					notsamecomponentCrossgenum++;
					if(notsamecomponentCrossgenum>1)//看是否這個component與其他component有兩個以上Crossedge
						IssinglyConnectedGraph = false;
					
				}

			}

		}
	}


}
int main() {

	int N; //幾筆測資
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{


		int V = 0;  //幾個點
		scanf("%d", &V);




		//重置 歸0
		Treetime = 0;
		componentBackedgenum = 0;
		notsamecomponentCrossgenum = 0;
		IssinglyConnectedGraph = true;

		for (int j = 0; j < V; j++)
		{

			vertices[j].color = 'W';
			vertices[j].finishtime = 0;
			vertices[j].startime = 0;
			for (int k = 0; k < V; k++) {
				Gstep[j][k] = 0;
				Gedge[j][k] = 'E';
			}
		}

		int E = 0; //幾條邊
		scanf("%d", &E);
		int start, finish;
		for (int j = 0; j < E; j++)
		{

			scanf("%d %d", &start, &finish);
			//if(start!=finish)
			if (Gstep[start][finish] == 1) IssinglyConnectedGraph = false;
			Gstep[start][finish] = 1;

		}



		for (int k = 0; k < V; k++)
		{
			if (IssinglyConnectedGraph == true)
			{
				TemTree.clear();//清空 樹的集合(這個component)
				componentBackedgenum = 0;
				notsamecomponentCrossgenum = 0;
				Treetime = 0;
				if (vertices[k].color == 'W')
				{
					vertices[k].color = 'G';
					vertices[k].startime = Treetime;
					Treetime++;
					DFS(k, V);
					vertices[k].finishtime = Treetime;
					Treetime++;
					vertices[k].color = 'B';
				}

				/*	for (int p = 0; p < V; p++)
					{
						for (int o = 0; o < V; o++)
						{
							if (Gedge[p][o] != 'E')
								std::cout << Gedge[p][o];
							else
								std::cout << ",";
						}
						std::cout << "\n";
					}
					std::cout << "\n";*/

				if (IssinglyConnectedGraph == false) break;
				else {
					Treetime = 0;
					TemTree.clear();
					for (int z = 0; z < V; z++)
					{

						vertices[z].color = 'W';
						vertices[z].finishtime = 0;
						vertices[z].startime = 0;
						for (int x = 0; x < V; x++) {
							Gedge[z][x] = 'E';
						}
					}
				}


			}
			else
				break;



		}
			

	




		//for (int j = 0; j < E; j++)
		//{

		//	if (IssinglyConnectedGraph)
		//	{
		//		TemTree.clear();//清空 樹的集合(這個component)
		//		componentBackedgenum = 0;
		//		notsamecomponentCrossgenum = 0;

		//		if (vertices[j].color == 'W')
		//		{
		//			vertices[j].color = 'G';
		//			vertices[j].startime = Treetime;
		//			Treetime++;
		//			DFS(j, V);
		//			vertices[j].finishtime = Treetime;
		//			Treetime++;
		//			vertices[j].color = 'B';
		//		}
		//	}
		//	else break;

		//}









		if (IssinglyConnectedGraph)
			printf("%d YES\n", i + 1);
		else
			printf("%d NO\n", i + 1);

	}
	system("pause");
	return 0;
}
