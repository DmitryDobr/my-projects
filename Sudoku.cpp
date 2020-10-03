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
	
	getline(fin, in);
	int n = atoi(in.c_str());
	cout << "n == " << n << endl;
	
	bool result = true;
	
	int arr[n*n][n*n], l, j1 = 0;
	
	for (int i = 0 ; i < n*n ; i++)
	{
		j1 = 0;
		getline(fin, in);
		l = in.length();
		
		for (int j = 0 ; j < l ; j++)
		{
			string conv;
			while (in[j] != ' ')
			{
				conv = conv + in[j];
				j++;
			}
			arr[i][j1] = atoi(conv.c_str());
			j1++;
		}
		cout << endl;
	}
	
	for (int i = 0 ; i < n*n ; i++)
	{
		for (int j = 0 ; j < n*n ; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	} 
	
	bool arr_cm[n*n];
	
	//проверка строк
	for (int i = 0 ; i < n*n ; i++)
	{
		for (int ii = 0 ; ii < n*n ; ii++)
		{
			arr_cm[ii] = true;
		}	
		for (int j = 0 ; j < n*n ; j++)
		{
			if (arr_cm[arr[i][j]-1] == false )
			{
				cout << "stroki - NO";
				exit(0);
			}
			if (arr_cm[arr[i][j]-1] == true )
			{
				arr_cm[arr[i][j]-1] = false;
			}
		}
	}

	cout << "stroki - yes" << endl;
	
	//проверка столбов
	for (int i = 0 ; i < n*n ; i++)
	{
		for (int ii = 0 ; ii < n*n ; ii++)
		{
			arr_cm[ii] = true;
		}	
		for (int j = 0 ; j < n*n ; j++)
		{
			if (arr_cm[arr[j][i]-1] == false )
			{
				cout << "stolbi - NO";
				exit(0);
			}
			if (arr_cm[arr[j][i]-1] == true )
			{
				arr_cm[arr[j][i]-1] = false;
			}
		}
	}
	
	cout << "stolbi - yes" << endl;
	
	cout << endl << "kvadrats" << endl;
	//проверка квадратиков
	int arr_dop[n*n][n*n], yo = 0;
	
	int i = 0, j = 0, ii = 0;
	
	for (int a2 = 0 ; a2 < n*n ; a2++)
	{
		for (int a1 = 0 ; a1 < n*n ; a1++)
		{
			j = 0;
			for (int b = a1 ; b < a1 + n ; b++)
			{	
				for (int c = a2 ; c < a2 + n ; c++)
				{
					arr_dop[i][j] = arr[b][c];
					j++;
				}
			}
			i++;
			a1 = a1 + n - 1;
		}
		a2 = a2 + n - 1;
	}
	
	for (int a = 0 ; a < n*n ; a++)
	{	
		for (int b = 0 ; b < n*n; b++)
		{
			cout << arr_dop[a][b] << " "; 
		}
		cout << endl;
	}
	
	cout << endl;
	
	//проверка квадратов
	for (int i = 0 ; i < n*n ; i++)
	{
		for (int ii = 0 ; ii < n*n ; ii++)
		{
			arr_cm[ii] = true;
		}	
		for (int j = 0 ; j < n*n ; j++)
		{
			if (arr_cm[arr_dop[j][i]-1] == false )
			{
				cout << "kvadrats - NO";
				exit(0);
			}
			if (arr_cm[arr_dop[j][i]-1] == true )
			{
				arr_cm[arr_dop[j][i]-1] = false;
			}
		}
	}
	
	cout << "kvadrats - YES";
	
	if (result == true)
	{
		cout << endl << "Yes";
	}
	
}
