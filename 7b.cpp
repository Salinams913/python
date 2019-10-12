#include<iostream>
#include<time.h>
using namespace std;

int max(int a,int b)
{
	return (a>b)?a:b;
}

int knapSack(int W,int w[],int v[],int n)
{
	int i,wt,k[n+1][W+1];
	for(i=0;i<=n;i++)
	{
		for(wt=0;wt<=W;wt++)
		{
			if(i==0 || wt==0)
				k[i][wt]=0;
			else if (w[i-1]<=wt)
				k[i][wt]=max(v[i-1]+k[i-1][wt-w[i-1]],  k[i-1][wt]);
			else
				k[i][wt]=k[i-1][wt];
		}
	}
	return k[n][W];
}

int main()
{
	int W,n,max;
	clock_t start,end;
	double t;
	start=clock();
	cout<<"Enter the no. of items :";
	cin>>n;
	int w[n],v[n];
	cout<<"Enter the weights and values of the items : "<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<"Item "<<i<<": ";
		cin>>w[i];
		cin>>v[i];
	}
	cout<<"Enter the capacity :";
	cin>>W;
	max=knapSack(W,w,v,n);
	cout<<"Solution :"<<max<<endl;
	end=clock();
	t+=(double)(end-start)/CLOCKS_PER_SEC;
	cout<<"Time complexity:"<<t;
	return 0;
}


//output:
Enter the no. of items :5
Enter the weights and values of the items : 
Item 0: 111 11
Item 1: 121 22
Item 2: 131 33
Item 3: 141 44
Item 4: 151 55
Enter the capacity :300
Solution :99
Time complexity:0.000604Press ENTER to continue...//

