#include "stdafx.h"
#include <cmath>
#include <memory.h>
#include <iostream>
#include "Multymatrix.h"   // умножение матриц 

#define N 6

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	int Mc[N + 1] = { 10,52,100,33,50,40,21 }, Ms[N][N], r = 0, rd = 0;

	memset(Ms, 0, sizeof(int) * N * N);
	r = OptimalM(1, N, N, Mc, OPTIMALM_PARM(Ms));

	cout << endl << "-- расстановка скобок (рекурсивное решение) "<< endl;
	cout << endl << "размерности матриц: ";

	for (int i = 1; i <= N; i++) 
		cout << "(" << Mc[i - 1] << "," << Mc[i] << ") ";

	cout << endl << "минимальное количество операций умножения: " << r;
	cout << endl << endl << "матрица S" << endl;

	for (int i = 0; i < N; i++)
	{
		cout << std::endl;

		for (int j = 0; j < N; j++)  
			cout << Ms[i][j] << "  ";
	}
	cout << endl;

	memset(Ms, 0, sizeof(int) * N * N);
	rd = OptimalMD(N, Mc, OPTIMALM_PARM(Ms));

	cout << endl << "-- расстановка скобок (динамичеое программирование) " << endl;
	cout << endl << "размерности матриц: ";

	for (int i = 1; i <= N; i++)
		cout << "(" << Mc[i - 1] << "," << Mc[i] << ") ";

	cout << endl << "минимальное количество операций умножения: " << rd;
	cout << endl << endl << "матрица S" << endl;

	for (int i = 0; i < N; i++)
	{
		cout << endl;

		for (int j = 0; j < N; j++)  
			cout << Ms[i][j] << "  ";
	}

	cout << endl << endl;
	system("pause");

	return 0;
}