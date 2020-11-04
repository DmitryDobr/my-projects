#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	ifstream fin("input.txt");
	
	int n, k;
	fin >> n;
	fin >> k;
	
	if (k < 2)
	{
		cout << "0";
		return(0);
	}
	else
	{
		int otv = k;
		
		for (int i = 0; i < n - 1; i++)
		{
			otv = otv * (k - 1);
		}
		
		cout << otv;
		return(0);
	}
	
}
