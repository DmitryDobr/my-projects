#include <iostream>
#include <vector>
#include <conio.h>
#include <math.h>
#include <stdlib.h>

using namespace std;

float det_A(vector <vector<float> > matrix_A, int n1)
{
	float det = 0;
	//cout << "n1=" << n1 << endl;
	// нахождение определителя
	if (n1 == 1){ det = matrix_A[0][0];}
	if (n1 == 2){ det = matrix_A[0][0] * matrix_A[1][1] - matrix_A[0][1] * matrix_A[1][0];}	
	
	float kst;
	if (n1 > 2)
	{
		int p=0;
		for (int i=0; i<n1-1; i++)
		{
			int t=1;
			while(matrix_A[i][i] == 0)
			{
				for(int j = 0; j < n1; j++)
				{
					matrix_A[i][j]=kst;
					matrix_A[i][j]=matrix_A[i+t][j];
					matrix_A[i+t][j]=kst;
				}
				p++;
				t++;
			}
			for (int k=i+1; k<n1; k++)
			{
				kst=matrix_A[k][i]/matrix_A[i][i];
				for(int j = 0; j < n1; j++)
				matrix_A[k][j]-=matrix_A[i][j]*kst;
			}
		}
		kst=pow(-1,p);
		for(int i=0; i < n1; i++)
		kst*=matrix_A[i][i];
	}
	if (n1 > 2){det = kst;}
	if (det == -0)
	{
		det = 0;
	}
	return det;
} 

vector< vector<float> > alg_A(vector <vector<float> > matrix_A, int n1, int det)
{
	vector <vector<float> > matrix_alg_A;
	matrix_alg_A.resize(n1);
	int n2 = n1-1;
	
	//транспонирование матрицы
	
	vector < vector <float> > matrix_AT;
	matrix_AT.resize(n1);
	for (int i = 0; i < n1 ; i++)
	{
		vector <float> matrix_buf;
		matrix_buf.resize(n1);
		
		for (int j = 0 ; j < n1 ; j++)
		{
			matrix_buf[j] = matrix_A[j][i];
		}
		matrix_AT[i] = matrix_buf;
	}
	
	cout << endl <<"Транспонированная матрица А(T) = " << endl;
	
	for (int i = 0; i < n1 ; i++)
	{
		for (int j = 0 ; j < n1 ; j++)
		{
			cout << matrix_AT[i][j] << " ";
		}
		cout << endl;
	}
	cout << "---------------------------------" << endl;
	cout << "вычисление матирцы алгебраических дополнений" << endl;
	// вычисление матрицы алг.дополнений
	for (int i = 0 ; i < n1 ; i++)
	{
		vector<float> matrix_alg_A_buf;
		matrix_alg_A_buf.resize(n1);
		for (int j = 0 ; j < n1 ; j++)
		{
			cout << endl;
			cout << i << " " << j << ":" << endl;
			vector < vector<float> > buffer_1;
			buffer_1.resize(n1-1);
			int cj = 0; 
			for (int ii = 0 ; ii < n1 ; ii++)
			{
				if (ii != i)
				{
					vector <float> buffer;
					buffer.resize(n1-1);
					int ch = 0;
					for (int jj = 0 ; jj < n1 ; jj++)
					{
						if (jj != j)
						{
			    			buffer[ch] = matrix_AT[ii][jj];
			    			ch = ch + 1;
						}
					}	
					buffer_1[cj] = buffer;
					cj = cj + 1;
				}
			}			
			for (int o1 = 0 ; o1 < n1-1 ; o1++){for (int o = 0 ; o < n1-1 ; o++){cout << buffer_1[o1][o] << " ";}	cout << endl;}		
			matrix_alg_A_buf[j] = pow(-1,i+j) * det_A(buffer_1, n2) * 1/det;	
			cout <<"det["<<i<<"]["<<j<<"] = " << matrix_alg_A_buf[j] << endl;				
		}
		matrix_alg_A[i] = matrix_alg_A_buf;
	}
	return matrix_alg_A;
}

vector < vector <float> > AxB_1(vector <vector<float> > matrix_A , int n1, vector <vector<float> > matrix_B, int n2, int m2)
{
	// проверка на взможность
	if (n1 != n2)
	{
		cout << "Кол-во строк матрицы A не совпадает с кол-вом столбцов матрицы B --> решение невозможно"<< endl;
		exit(0);
	}
	vector < vector <float> > matrix_X;
	matrix_X.resize(n1);
	// умножение матриц
	for (int i = 0; i < n1; i++)
	{
		vector <float> buffer;
		buffer.resize(m2);
		for (int j = 0; j < m2 ; j++)
		{
			for(int k = 0; k < n1; k++)
			{
				buffer[j] += matrix_A[i][k] * matrix_B[k][j];
            	//matrix_C[i][j] += matrix_A[i][k] * matrix_B[k][j];
			}
		}
		matrix_X[i] = buffer;
	}
	return matrix_X;
}
 
vector < vector <float> > AxB_2(vector <vector<float> > matrix_B , int n2, int m2, vector <vector<float> > matrix_A , int n1)
{
	// проверка на взможность
	if (m2 != n1)
	{
		cout << "Кол-во строк матрицы B не совпадает с кол-вом столбцов матрицы A --> решение невозможно"<< endl;
		exit(0);
	}
	vector < vector <float> > matrix_X;
	matrix_X.resize(n2);
	// умножение матриц
	for (int i = 0; i < n2; i++)
	{
		vector <float> buffer;
		buffer.resize(n1);
		for (int j = 0; j < n1 ; j++)
		{
			buffer[j] = 0;
			for(int k = 0; k < m2; k++)
			{
				buffer[j] += matrix_B[i][k] * matrix_A[k][j];
            	//matrix_C[i][j] += matrix_A[i][k] * matrix_B[k][j];
			}
		}
		matrix_X[i] = buffer;
	}
	return matrix_X;
} 		
 
int main()
{
    int n1; // ограничение первого вектора
    cout << "n1=";cin >> n1;
    vector < vector <float> > matrix_A;
    matrix_A.resize(n1); 
    cout << "MATRIX A numbers" << endl;
    for (int i = 0 ; i < n1 ; i++)
	{
    	vector <float> buffer;
    	buffer.resize(n1); 
    	
    	for (int j = 0 ; j < n1 ; j++)
    	{
    		int buf;
    		cin >> buf;
    		buffer[j] = buf; 
		}
		matrix_A[i] = buffer;	
	}
    cout << endl;
    
    int n2, m2; // ограничение второго вектора
    cout << "n2=";cin >> n2;
	cout << "m2=";cin >> m2;
	
    vector < vector <float> > matrix_B;
    matrix_B.resize(n2); 
    cout << "MATRIX B numbers" << endl;
    for (int i = 0 ; i < n2 ; i++)
	{
    	vector <float> buffer;
    	buffer.resize(m2); 
    	
    	for (int j = 0 ; j < m2 ; j++)
    	{
    		int buf;
    		cin >> buf;
    		buffer[j] = buf; 
		}
		matrix_B[i] = buffer;	
	}
    system("cls");
    cout << "MATRIX A = " << endl;
    cout << endl;
	for (int i = 0 ; i < n1 ; i++)
	{
    	for (int j = 0 ; j < n1 ; j++)
    	{
    		cout << matrix_A[i][j] << " ";
		}
		cout << endl;
		cout << endl;	
	}
	cout << "MATRIX B = " << endl;
    cout << endl;
	for (int i = 0 ; i < n2 ; i++)
	{
    	for (int j = 0 ; j < m2 ; j++)
    	{
    		cout << matrix_B[i][j] << " ";
		}
		cout << endl;
		cout << endl;	
	}
	
	setlocale(LC_ALL , "rus");
	
	cout << endl;
	cout << "Выберите действие" << endl;
	cout << "1 - A*X = B " << endl;
	cout << "2 - X*A = B " << endl;
	int hod;
	while (hod != 1 && hod != 2)
	{
		cin >> hod;
	}
	
	float det = det_A(matrix_A , n1);
	cout << "det(A) = " << det;
		
	// проверка на возможность
	if (det == 0)
	{
		cout << endl << "Определитель матрицы А равен 0 --> решение невозможно"<< endl;
		exit(0);
	}
	 
	vector < vector <float> > matrix__A = alg_A(matrix_A, n1, det);
	cout << endl << "---------------------------------" << endl;
	cout << "Обратная матрица A(-1) " << endl;
	for (int i = 0 ; i < n1 ; i++)
	{
		for (int j = 0 ; j < n1 ; j++)
		{
			cout << matrix__A[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl << "---------------------------------" << endl;
	
	if (hod == 1)
	{	
		vector < vector <float> > matrix_X = AxB_1(matrix__A, n1, matrix_B, n2, m2); 
		cout << "X= " << endl;
		for (int i = 0 ; i < n1 ; i++){for (int j = 0 ; j < m2 ; j++){cout << matrix_X[i][j] << " ";}cout << endl;}
	}
	
	if (hod == 2)
	{	
		vector < vector <float> > matrix_X = AxB_2(matrix_B, n2, m2, matrix__A, n1); 
		cout << "X= " << endl;
		for (int i = 0 ; i < n2 ; i++){for (int j = 0 ; j < n1 ; j++){cout << matrix_X[i][j] << " ";}cout << endl;}
	}
	
}
