#include<iostream> 
#include<cstring> 
#include<cstdlib> 
#include<time.h>
using namespace std; 
void lcs( char *X, char *Y, int m, int n ) 
{ 
   int L[m+1][n+1]; 
   for (int i=0; i<=m; i++) 
   { 
     for (int j=0; j<=n; j++) 
     { 
       if (i == 0 || j == 0) 
         L[i][j] = 0; 
       else if (X[i-1] == Y[j-1]) 
         L[i][j] = L[i-1][j-1] + 1; 
       else
         L[i][j] = max(L[i-1][j], L[i][j-1]); 
     } 
   } 
    int index = L[m][n]; 
	char lcs[index+1]; 
   lcs[index] = '\0';
    int i = m, j = n; 
   while (i > 0 && j > 0) 
   { 
	   if (X[i-1] == Y[j-1]) 
      { 
          lcs[index-1] = X[i-1];
		  i--; j--; index--; 
	  }
	  else if (L[i-1][j] > L[i][j-1]) 
         i--; 
      else
         j--; 
   } 
   cout << "LCS of " << X << " and " << Y << " is " << lcs<<endl; 
} 
int main() 
{ 
	int m,n,i;
	char X[100];
	char Y[100];
	clock_t start,end;
	double t;
	start=clock();
	cout<<"Enter the size of the first string"<<endl;
	cin>>m;
	cout<<"Enter the first string:"<<endl;
	for(i=0;i<m;i++)
	{
	cin>>X[i];
	}
	cout<<"Enter the size of the second string:"<<endl;
	cin>>n;
	cout<<"Enter the second string:"<<endl;
	for(i=0;i<n;i++)
	{
		cin>>Y[i];
	}

  
  lcs(X, Y, m, n); 
  end=clock();
	t+=(double)(end-start)/CLOCKS_PER_SEC;
	cout<<"Time complexity:"<<t;
  return 0; 
} 


//output:

Enter the size of the first string
5
Enter the first string:
hello
Enter the size of the second string:
5
Enter the second string:
heyol
LCS of hello and heyol is heo
Time complexity:0.000303Press ENTER to continue...//

