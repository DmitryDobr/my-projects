#include <iostream>
#include <fstream>
#include <stack>
#include <vector>
#include <math.h>
#include <string>
#include <stdlib.h>

using namespace std;

int main()
{
    ifstream in ("input.txt");
    int n, d, c ,c1 ,y ;
    in >> n;
    stack <int> stack; // для алгоритма поиска в глубину
    vector < vector <int> > vec;
    vec.resize(n);
    int u[n];

    for (int i = 0; i < n; i++)
    {
		u[i] = 0;
	}
	
    for (int i = 0; i < n; i++)
	{
        in >> c;
        while (c > 0)
        {
            in >> c1;
            vec[i].push_back(c1);
            c--;
		}
    }

    c = 0, c1 = 0;
    u[0] = 1;
    d = 0;
    stack.push(d);

    for (int i = 0; i < n; i++)
    {
        for(int j = 0; j < vec[i].size(); j++)
        {
            cout << vec[i][j]<<" ";
        }
        cout << endl;
    }

    while (!stack.empty())
    {
        for (int l = 0; l < vec[d].size() ; l++)
        {

            if (!u[vec[d][l]-1])
            {
                stack.push(vec[d][l] - 1);
                u[vec[d][l] - 1] = 1;
            }
            else if (u[vec[d][l] - 1] && vec[d][l] - 1 > d)
            {
                c++;
            }
        }
        d = stack.top();
        stack.pop();
    }

    for (int i = 0; i < n; i++){if (u[i] != 1){c1++;}}
    
    if (c + c1 > 0){cout << "no";}else{cout << "yes";}
	
    in.close();
    
}
