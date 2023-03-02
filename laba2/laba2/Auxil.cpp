#include "Auxil.h" 
#include "stdafx.h"

namespace auxil
{
	void start()	// старт генератора случайных чисел 
	{
		srand((unsigned)time(NULL));
	};
	double dget(double rmin, double rmax)	// получить случайное число двойной точности
	{
		return ((double)rand() / (double)RAND_MAX) * (rmax - rmin) + rmin;
	};
	int iget(int rmin, int rmax)	// получить случайное целое число 
	{
		return (int)dget((double)rmin, (double)rmax);
	};
}