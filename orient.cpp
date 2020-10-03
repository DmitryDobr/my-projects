#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream in ("input.txt");
    int n, m = 0;
    in >> n ;
    int a[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n ; j++)
        {
		   in >> a[i][j];
		}
	}
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n ; j++)
        {
		    if ((a[i][i] != 0) || (a[i][j] == a[j][i]) && (a[i][j] == 1))
			{
				m++;
			}
    	}		    
	}
		
    if (m > 0)
	{
		cout<<"NO";
	}
    else 
	{
		cout<<"YES";
	}
    return 0;
}
