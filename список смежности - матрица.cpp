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
	
	// список смежности --> матрица
	
	getline(fin, in);
	int n = atoi(in.c_str());
	cout << "n=" << n << endl;
	int arr[n][n];
	
	for (int i = 0 ; i < n ; i++)
	{
		for (int j = 0 ; j < n ; j++)
		{
			arr[i][j] = 0;
		}
	}
	
	for (int i = 0 ; i < n ; i++)
	{
		getline(fin, in);
		int l = in.length();
		int a1 = in[0] - 48;
		//cout << "a1=" << a1 << endl;
		for (int j = 2 ; j < l ; j++)
		{
			if (in[j] != ' ' && in[j] - 48 != 0)
			{
				char conv = in[j];
				int a2 = conv - 48; 
				//cout << a2 << " " ;		
				arr[a1-1][a2-1] = 1;
			}
		}	
		cout << endl;
	}
	
	ofstream tin("outcode.txt");
	
	for (int i = 0 ; i < n ; i++)
	{
		for (int j = 0 ; j < n ; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	
	for (int i = 0 ; i < n ; i++)
	{
		for (int j = 0 ; j < n ; j++)
		{
			tin << arr[i][j] << " ";
		}
		tin << endl;
	}
	
}

