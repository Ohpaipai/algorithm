#include<iostream>
#include<cstdlib>
#include<vector>
#include<algorithm>
#include<set>
#pragma warning( disable : 4996 )
typedef struct MyStruct
{
	char color;
	int startime;
	int finishtime;
	
}Vertices;
Vertices vertices[9999];
int Gstep[9999][9999];
char Gedge[9999][9999];
//std::vector<std::set<double>> Tree;
std::set<double>TemTree;
int Treetime;
bool IssinglyConnectedGraph = true;
int componentBackedgenum = 0; int notsamecomponentCrossgenum = 0;
void DFS(int start, const int V)
{

	for (int i = 0; i < V; i++)
	{
		if (Gstep[start][i] == 1 && Gedge[start][i] == 'E')  //����I���s���B��S�ιL
		{

			if (vertices[i].color == 'W') //�I���զ�
			{
				TemTree.insert(start);
				TemTree.insert(i);
				Gedge[start][i] = 'T';//treeedge
				vertices[i].startime = Treetime;
				vertices[i].color = 'G';
				Treetime++;
				DFS(i, V);
				vertices[i].finishtime = Treetime;
				Treetime++;
				vertices[i].color = 'B';
			}
			else if (vertices[i].color == 'G')//�I���Ǧ�
			{
				Gedge[start][i] = 'B';//Backedge
				componentBackedgenum++;
				/*if (componentBackedgenum > 1)
					IssinglyConnectedGraph = false;*/
			}
			else if (vertices[i].color == 'B')//�I���¦�
			{
				int exist = TemTree.count(i);
				
				if (exist == 1)
				{
					if (vertices[start].startime < vertices[i].startime) //��L���o�{
					{
						Gedge[start][i] = 'F'; //FowardEdge
						IssinglyConnectedGraph = false;
					}
					else {
						Gedge[start][i] = 'C';
						IssinglyConnectedGraph = false;
					}
				}
				else {
					Gedge[start][i] = 'C'; //CrossEdge
					notsamecomponentCrossgenum++;
					if(notsamecomponentCrossgenum>1)
						IssinglyConnectedGraph = false;
					
				}
				
			}

		}
	}
	
	
}
int main() {

	int N; //�X������
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		
	
		int V=0;  //�X���I
		scanf("%d", &V);
		
		
		
	
		//���m �k0
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
	
		int E=0; //�X����
		scanf("%d", &E);
		int start, finish;
		for (int j = 0; j <E; j++)
		{
			
			scanf("%d %d",&start,&finish);
			Gstep[start][finish] =1;
			
		}
		
		
		for (int j = 0; j < E; j++)
		{

			TemTree.clear();
			componentBackedgenum = 0;
			notsamecomponentCrossgenum = 0;
			if (vertices[j].color == 'W')
			{
				vertices[j].color = 'G';
				vertices[j].startime = Treetime;
				Treetime++;
				DFS(j, V);
				vertices[j].finishtime = Treetime;
				Treetime++;
				vertices[j].color = 'B';
			}
			else {
				DFS(j, V);
			}

		}



		//for (int j = 0; j < V; j++)
		//{

		//	std::cout << j<<":  " << vertices[j].startime << "&" << vertices[j].finishtime << "\n";

		//}
		//for (int j = 0; j < V; j++)
		//{

		//	for (int k = 0; k < V; k++)
		//	{
		//		std::cout << Gedge[j][k];
		//	}
		//	std::cout << "\n";
		//}
		//std::cout << "\n";

		if (IssinglyConnectedGraph)
			printf("%d YES\n", i + 1);
		else
			printf("%d NO\n", i + 1);
		
	}
	system("pause");
	return 0;
}