#include <iostream>
#include <fstream>
#include <math.h>
#include <string>
#include <stdlib.h>
#include <stack>

using namespace std;

int main()
{
	ifstream fin("incode.txt");
	string in;	
	getline(fin, in);
	
	int n = atoi(in.c_str());
	cout << "n=" << n << endl;
	int N = n, M; 
	
	int arr[n][n], i1 = 0;
	for (int i = 0 ; i < n ; i++)
	{getline(fin, in);int l = in.length();i1 = 0;for (int j = 0 ; j < l ; j++){if (in[j] != ' '){arr[i][i1] =  in[j] - 48;if (in[j] - 48 == 1){M++;}i1++;}}}
	
	int mas[n];
	stack <int> S;
	
	for (int i = 0 ; i < n ; i++){mas[i] = -1;for (int j = 0 ; j < n ; j++){cout << arr[i][j] << " "; }cout << endl;}
	
	S.push(0);
	mas[0] = 0;
	
	while (!S.empty())
	{
		int i = S.top();
		bool buf = false;
		
		for (int j = 0; j < n ; j++)
		{	
			if (arr[i][j] == 1 && mas[j] != -1 && buf == false)
			{
				if (mas[j] > S.top())
				{
					cout << "cikl" << endl;
					exit(0);	
				}	
			}
			
			if (arr[i][j] == 1 && mas[j] == -1 && buf == false)
			{
				//cout << S.top() << " -> " << j << endl;
				buf = true;
				mas[j] = S.top();
				S.push(j);
			}
		}
		
		if (buf == false)
		{
			S.pop();
		}
		
	}
	
}
