#include "stdafx.h"
#include <iostream>
#include <iomanip> 
#include "Salesman.h"

#define N 5

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	int d[N][N] = {//1    2     3     4     5        
				  { INF,  32,   37,   INF,  16	},	//  1
				  { 16,   INF,  31,   52,   68  },	//  2
				  { 18,   48,   INF,  86,   65  },	//  3 
				  { 33,   42,   64,   INF,  48  },	//  4
				  { 77,   82,   52,   29,   INF }};	//  5

	int result[N];	// результат 
	int s = salesman(
		N,          // [in]  кол-во городов 
		(int*)d,    // [in]  массив [n*n] расстояний 
		result      // [out] массив [n] маршрут 0 x x x x  
	);

	cout << "\n-- Задача коммивояжера -- ";
	cout << "\n-- количество  городов: " << N;
	cout << "\n-- матрица расстояний : ";

	for (int i = 0; i < N; i++)
	{
		cout << "\n";
		for (int j = 0; j < N; j++)
			if (d[i][j] != INF) 
				cout << setw(3) << d[i][j] << " ";
			else 
				cout << setw(3) << "INF" << " ";
	}

	cout << "\n-- оптимальный маршрут: ";
	for (int i = 0; i < N; i++)
		cout << result[i] + 1 << "-->";

	cout << 1;
	cout << "\n-- длина маршрута     : " << s << "\n";
	system("pause");
	return 0;
}