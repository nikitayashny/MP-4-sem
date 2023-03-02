#include "pch.h"
#include "Auxil.h"								// вспомогательные функции 

#define  CYCLE  10000000						// количество циклов  
#define	 N		20

int fib(int number)
{
	if (number < 1) {
		return 0;
	}
	if (number == 1) {
		return 1;
	}
	return fib(number - 1) + fib(number - 2);
}

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "rus");

	double  av1 = 0, av2 = 0;
	clock_t  t1 = 0, t2 = 0, T1 = 0, T2 = 0;

	auxil::start();								// старт генерации 
	t1 = clock();								// фиксация времени 
	for (int i = 0; i < CYCLE; i++)
	{
		av1 += (double)auxil::iget(-100, 100);	// сумма случайных чисел 
		av2 += auxil::dget(-100, 100);			// сумма случайных чисел 
	}
	t2 = clock();								// фиксация времени 

	cout << endl << "количество циклов:         " << CYCLE;
	cout << endl << "среднее значение (int):    " << av1 / CYCLE;
	cout << endl << "среднее значение (double): " << av2 / CYCLE;
	cout << endl << "продолжительность (у.е):   " << (t2 - t1);
	cout << endl << "                  (сек):   " << ((double)(t2 - t1)) / ((double)CLOCKS_PER_SEC);
	cout << endl;

	T1 = clock();
	unsigned long long result = fib(N-1);
	T2 = clock();

	cout << "Расчетное время " << (T2 - T1) << endl;
	cout << "Расчетное время " << ((double)(T2 - T1)) / ((double)CLOCKS_PER_SEC) << " секунд" << endl;
}