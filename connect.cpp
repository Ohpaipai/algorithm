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
Vertices vertices[9999]; //�I
int Gstep[9999][9999]; //��
char Gedge[9999][9999]; //��O�ݩ���|��
std::set<double>TemTree;//�𪺶��X
int Treetime;//�ɶ�
bool IssinglyConnectedGraph = true;//�O�_��singly connected
int componentBackedgenum = 0; //�@��component�O�_�W�L1��backedge
int notsamecomponentCrossgenum = 0; //�@��component�O�_�s���Lcomponent�W�L1��
void DFS(int start, const int V)//�_�l��m �򦳴X�� vertices
{
	if (IssinglyConnectedGraph == false) return;
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
				vertices[i].color = 'G';//�ܦ��Ǧ�
				Treetime++;
				DFS(i, V);
				vertices[i].finishtime = Treetime;
				Treetime++;
				vertices[i].color = 'B';//�̫��ܶ¦�
			}
			else if (vertices[i].color == 'G')//�I���Ǧ�
			{
				Gedge[start][i] = 'B';//Backedge
				componentBackedgenum++; 
				//if (componentBackedgenum > 1)//�ݬO�_�o��component����ӥH�Wbackedge
				//	IssinglyConnectedGraph = false;
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
			else if (vertices[i].color == 'B')//�I���¦�
			{
				int exist = TemTree.count(i);
				if (exist == 1)//�P�@��component
				{
					//vertices[start].startime < vertices[i].startime
					if (Treetime> vertices[i].finishtime) //��L���o�{
					{
						Gedge[start][i] = 'F'; //FowardEdge
						IssinglyConnectedGraph = false;
					}
					else {
						Gedge[start][i] = 'C'; //Crossedge
						IssinglyConnectedGraph = false;
					}
				}
				else if(exist==0) 
				{
					Gedge[start][i] = 'C'; //CrossEdge
					//notsamecomponentCrossgenum++;
					//if(notsamecomponentCrossgenum>1)//�ݬO�_�o��component�P��Lcomponent����ӥH�WCrossedge
					//	IssinglyConnectedGraph = false;
					//
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
			//if(start!=finish)
				Gstep[start][finish] =1;
			
		}
	


		for (int k = 0; k < V; k++)
		{
			if (IssinglyConnectedGraph==true)
			{
				TemTree.clear();//�M�� �𪺶��X(�o��component)
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
			//		TemTree.clear();//�M�� �𪺶��X(�o��component)
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