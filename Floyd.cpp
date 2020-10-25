// АЛГОРИТМ ФЛОЙДА
// Кратчайший путь между каждой парой точек. Работает с "-" весами

#include <iostream>
#include <fstream>
#include <stack>
#include <vector>
#include <math.h>
#include <string>
#include <stdlib.h>

using namespace std;
 
int arr[1000][1000];

int main() {
	ifstream fin ("input.txt");
	int n;
	fin >> n;
	
    cout << "n=" << n << endl;
    
    for (int i = 0 ; i < n ; i++)
	{
		for (int j = 0 ; j < n ; j++)
		{
			fin >> arr[i][j];
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}

    for (int k = 0; k < n; k++) {        //текущая вершина, используемая для улучшения
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
            }
        }
    }
    
    cout << "final" << endl;
    ofstream tin("output.txt");
    
    for (int i = 0; i < n ; i++)
    {
    	for (int j = 0; j < n ; j++)
    	{
    		if (arr[i][j] == 100)
    		{
    			cout << "x" << " ";
				tin << "x" << " ";
			}
			
			if (arr[i][j] != 100)
    		{
    			cout << arr[i][j] << " ";
    			tin << arr[i][j] << " ";
    		}
		}
		cout << endl;
	}

    //По идее, массив arr содержит длины кратчайших путей между всеми парами вершин
}