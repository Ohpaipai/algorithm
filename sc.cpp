//#include<iostream>
//#pragma warning( disable : 4996 ) 
//#include<cstdlib> 
//bool IssinglyConnectedGraph = true;
//int Gstep[9999][9999];
//int Grecord[9999][9999];
//int G[9999][9999];
//bool v[9999];
//void dfs(int V, int x, int root)//x ����l
//{
//	if (IssinglyConnectedGraph == false)
//		return;
//
//	for (int i = 0; i < V; i++)
//	{
//		/*if (root != i)
//		{*/
//			if (Gstep[x][i] == 1 && v[i] == 0)
//			{
//
//				G[root][i]++;
//				if (G[root][i] > 1) {
//					IssinglyConnectedGraph = false;
//					return;
//				}
//
//
//				v[i] = 1;//�]�L���I�]���H�]�L 
//				//Gstep[x][i] = 0; //�o�Ӹ��|�R��
//				dfs(V, i, root);
//				//Gstep[x][i] = 1;//���|�^�k
//				v[i] = 0;
//
//			}
//		//}
//	
//	}
//}
//int main() {
//
//	int N; //�X������ 
//	scanf("%d", &N);
//	for (int i = 0; i < N; i++)
//	{
//
//
//		int V = 0;  //�X���I 
//		scanf("%d", &V);
//
//
//
//
//		//���m �k0 
//
//		IssinglyConnectedGraph = true;
//		for (int j = 0; j < V; j++)
//		{
//
//			v[j] = 0;
//			for (int k = 0; k < V; k++) {
//				Gstep[j][k] = 0;
//				G[j][k] = 0;
//				Grecord[j][k] = 0;
//			}
//		}
//
//		int E = 0; //�X���� 
//		scanf("%d", &E);
//		int start, finish;
//		for (int j = 0; j < E; j++)
//		{
//
//			scanf("%d %d", &start, &finish);
//			/*if (start != finish)
//			{*/
//				Gstep[start][finish] = 1;
//
//				Grecord[start][finish] = Gstep[start][finish];
//			//}
//		}
//
//
//		for (int j = 0; j < V; j++)
//		{
//			if (IssinglyConnectedGraph==true)
//			{
//				v[j] = 1;
//
//				dfs(V, j, j);
//				v[j] = 0;
//			}
//			else break;
//
//			for (int k = 0; k < V; k++)
//			{
//				v[k] = 0;
//			}
//		}
//
//		/*  for (int j = 0; j < V; j++)
//			{
//				 for (int k = 0; k < V; k++)
//				{
//					 std::cout << G[j][k];
//				  }
//				 std::cout << "\n";
//			  }
//	   
//*/
//
//		if (IssinglyConnectedGraph==true)
//			printf("%d YES\n", i + 1);
//		else
//			printf("%d NO\n", i + 1);
//
//
//
//
//		IssinglyConnectedGraph = true;
//		for (int j = 0; j < V; j++)
//		{
//
//			v[j] = 0;
//			for (int k = 0; k < V; k++) {
//				Gstep[j][k] = 0;
//				G[j][k] = 0;
//				Grecord[j][k] = 0;
//			}
//		}
//
//	}
//	system("pause");
//	return 0;
//}