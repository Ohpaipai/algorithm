//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<math.h>
//#include<stdlib.h>
//int *Subarray;
//
//struct Data {
//	int low ;
//	int high;
//	int Sum;
//	bool operator>=(const Data& a) const
//	{
//		return (Sum >= a.Sum);
//	}
//} ;
//
//Data Left, Right, Crossing;
//Data FindMaxCrossingSubarray(int low, int mid, int high) {
//	int MaxLeft, MaxRight;
//	MaxLeft = 0;
//	MaxRight = 0;
//	Data A;
//	int Left_Sum ;
//	Left_Sum = -99999;
//	int sum ;
//	sum = 0;
//	for (int i = mid; i >= low; i--)
//	{
//		sum = sum + Subarray[i];
//		if (sum > Left_Sum)
//		{
//			Left_Sum = sum;
//			A.low = i;
//		}
//	}
//	int Right_Sum ;
//	Right_Sum = -99999;
//	sum = 0;
//	for (int i = mid + 1; i <= high; i++)
//	{
//		sum = sum + Subarray[i];
//		if (sum > Right_Sum)
//		{
//			Right_Sum = sum;
//			A.high = i;
//		}
//	}
//	A.Sum = Right_Sum + Left_Sum;
//	return A;
//}
//Data FindMaxMinSubarray(int low, int high) {
//	if (high == low)
//	{
//		Data A;
//		A.low = low;
//		A.high = high;
//		A.Sum = Subarray[low];
//		return A;
//	}
//	else {
//		int mid = floor((low + high) / 2);
//		Left = FindMaxMinSubarray(low, mid);
//		Right = FindMaxMinSubarray(mid + 1, high);
//		Crossing = FindMaxCrossingSubarray(low, mid, high);
//	}
//	if (Left >= Right && Left >= Crossing) return Left;
//	else if (Right >= Left && Right >= Crossing) return Right;
//	else return Crossing;
//}
//int main() {
//	int n;
//	while (scanf("%d", &n) == 1)
//	{
//		Subarray = (int *)malloc(n * sizeof(int));
//		for (int i = 0; i < n; i++)
//		{
//			scanf("%d", &Subarray[i]);
//		}
//		Data Ans = FindMaxMinSubarray(0, n - 1);
//		printf("%d %d %d\n", Ans.low, Ans.high, Ans.Sum);
//		free(Subarray);
//
//	}
//	//system("pause");
//}