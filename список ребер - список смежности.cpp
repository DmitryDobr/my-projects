#include <iostream>
#include <fstream>
#include <math.h>
#include <string>
#include <stdlib.h>

using namespace std;

int main()
{
	ifstream fin("incode.txt");
	string in;	
	
	// матрица смежности --> список ребер
	
	getline(fin, in);
	int n = in[0] - 48;
	cout << "n=" << n << endl;
	int m = in[2] - 48;
	
	int ans[n+1][n+1];
	
	for (int i = 0 ; i < n+1 ; i++)
	{
		for (int j = 0; j < n+1 ; j++)
		{
			ans[i][j] = 0;
		}
	}
	
	int buff = 0, a1 = 1, a2 = 1;
	
	for (int i = 1 ; i < m+1 ; i++)
	{
		getline(fin, in);
		int a1 = in[0] - 48;
		//cout << "a1=" << a1 << " " ;
		
		if (a1 > buff)
		{
			a2 = 1;
		}
		
		ans[a1][a2] = in[2] - 48;
		//cout << ans[a1][a2] << " " << endl;
		
		a2++;
		
		buff = a1;
	
	}
	
	ofstream tin("outcode.txt");
	tin << n << endl;
	
	for (int i = 1 ; i < n + 1; i++ )
	{
		tin << i << " ";
		
		for (int j = 1 ; j < n + 1 ; j++)
		{
			if (ans[i][j] != 0)
			{
				cout << ans[i][j] << " ";
				tin << ans[i][j] << " ";
			}
		}
		cout << endl;
		tin << endl;
	}
	
}
