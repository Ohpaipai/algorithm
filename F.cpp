#define _CRT_SECURE_NO_WARNINGS
#define  mostsmall -214783648
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
struct Data {
	int low;
	int high;
	int Sum;
	bool operator>=(const Data& a) const
	{
		return (Sum >= a.Sum);
	}
};
int main() {
	int *Subarray, n, low, high, mid;

	while (scanf("%d", &n) == 1)
	{
		Subarray = (int *)malloc(n * sizeof(int));
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &Subarray[i]);
		}
		Data Ans;
		Ans.high = n - 1;
		Ans.low = 0;
		Ans.Sum = mostsmall;
		low = 0;
		high = n;

 		while (low<=high)
		{
			mid = floor((low + high) / 2);
			int first;
			int last;
			first = 0;
			last = n;
			int Lmax;
			Lmax = mostsmall;
			int Rmax;
			Rmax = mostsmall;
			int Sum ;
			Sum = 0;
			for (int i = mid-1; i >=low ; i--)
			{
				Sum += Subarray[i];
				if (Sum >Lmax)
				{
					Lmax = Sum;
					first = i;
				}
			} 
			Sum =0;
			for (int i = mid+1; i<=high; i++)
			{
				Sum += Subarray[i];
				if (Sum >Rmax)
				{
					Rmax = Sum;
					last = i;
					
			 	}
			}

			 if (Lmax >Ans.Sum)
			 {
				Ans.Sum = Lmax;
				Ans.low = first;
				Ans.high = mid - 1;
			 }
			 if(Rmax>Ans.Sum)
			 {
				Ans.Sum = Rmax;
				Ans.low = mid + 1;
				if (last == n) Ans.high = last - 1;
				else
				{
					Ans.high = last;
				}
			 }
			 if (Subarray[mid] + Lmax > Ans.Sum)
			 {
				Ans.Sum = Subarray[mid] + Lmax;
				Ans.low = first;
				Ans.high = mid;

			 }
			 if (Subarray[mid] + Rmax > Ans.Sum)
			 {
				Ans.Sum = Subarray[mid] + Rmax;
				Ans.low = mid;
				if (last == n) Ans.high = last - 1;
				else
				{
					Ans.high = last;
				}
			 }
			 if (Subarray[mid] + Lmax + Rmax >Ans.Sum)
			 {
				Ans.Sum = Subarray[mid] + Lmax + Rmax;
				Ans.low = first;
				if(last==n) Ans.high = last-1;
				else
				{
					Ans.high = last;
				}

			 }
			
			

			
			if (Lmax > Rmax)
			{
				high = mid - 1;
			}
			else
				low = mid + 1;
			
			
		}


		printf("%d %d %d\n", Ans.low, Ans.high, Ans.Sum);
		free(Subarray);

	}
	//system("pause");
}
