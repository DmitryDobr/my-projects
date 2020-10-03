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
	int n = atoi(in.c_str());
	cout << "n=" << n << endl;
	
	int N = n, M; 
	
	//cout << N << " " << M << endl;
	
	int arr[n][n], i1 = 0;
	
	for (int i = 0 ; i < n ; i++)
	{
		getline(fin, in);
		int l = in.length();
		i1 = 0;
		for (int j = 0 ; j < l ; j++)
		{
			if (in[j] != ' ')
			{	
				arr[i][i1] =  in[j] - 48;
				if (in[j] - 48 == 1)
				{
					M++;
				}
				i1++;
			}
		}
		cout << endl;
	}
	
	
	ofstream tin("outcode.txt");
	
	cout << N << " " << M << endl;
	tin << N << " " << M << endl;	
	
	
	for (int i = 0 ; i < n ; i++)
	{
		for (int j = 0 ; j < n ; j++)
		{
			if (arr[i][j] == 1)
			{
				cout << i + 1 << " " << j + 1 << endl;
				tin << i + 1 << " " << j + 1 << endl;
			}
		}
	}
	
}
