#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	ifstream fin("input.txt");
	
	string in;
	getline(fin, in);
	int l = in.length();
	int otv = 0;
	int otv_m = 0;
	
	for (int i = 1 ; i < l ; i++)
	{
		if (in[i-1] != in[i])
		{
			otv++;
			
			if (otv > otv_m)
			{
				otv_m = otv;
			}
		}
	}
	
	cout << otv_m + 1;
	
}
