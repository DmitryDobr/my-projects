#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	ifstream fin("input.txt");
	string in;	
	
	int n;
	fin >> n;
	//cout << n;
	
	fin >> in;
	getline(fin, in);
	int l = in.length();
	char arr[l];
	
	int ii = 0;
	
	for (int i = 0 ; i < l ; i++)
	{
		bool buf = false;
		
		for (int oi = 0 ; oi < ii ; oi++)
		{
			
			if (in[i] == arr[oi])
			{
				buf = true;	
			}
		}
		
		if (buf == false)
		{
			arr[ii] = in[i];
			ii++;
		}
	}
	
	int otv = ii;
	int u = 1;
	
	while (n > 0)
	{
		otv = otv * (ii - u);
		if (u + 1 < ii){
		u++;}
		n--;
	}
	
	cout << otv;
}
