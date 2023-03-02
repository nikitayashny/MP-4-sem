#include "Combi.h"
#include "Boat.h"
#include "Auxil.h"
#include "stdafx.h"

#define N 10
#define INF 0x7fffffff 
#define H (sizeof(AA)/2)
#define M 3
#define NN (sizeof(v)/sizeof(int))
#define MM 6
#define COUNT 35

int main()
{
	setlocale(LC_ALL, "rus");
	char AA[][2] = { "A", "B", "C", "D" };
	cout << " ---- Генератор множества всех подмножеств ---- \nИсходное множество: \n{";
	for (int i = 0; i < sizeof(AA) / 2; i++)
	{
		cout << AA[i] << ((i < sizeof(AA) / 2 - 1) ? "," : " ");
	}
	cout << "}\n";
	cout << "Генерация всех подмножеств \n";
	combi::subset* s1 = new combi::subset(sizeof(AA) / 2);
	int n = s1->getfirst();
	while (n >= 0)
	{
		cout << "{ ";
		for (int i = 0; i < n; i++)
		{
			cout << AA[s1->ntx(i)] << ((i < n - 1) ? ", " : " ");
		}
		cout << "}\n";
		n = s1->getnext();
	}
	cout << "Всего : " << s1->count() << endl;

	//------------------------------------------------------------------------

	cout << endl << " --- Генератор сочетаний --- ";
	cout << endl << "Исходное множество: ";
	cout << "{ ";
	for (int i = 0; i < sizeof(AA) / 2; i++)
	{
		cout << AA[i] << ((i < sizeof(AA) / 2 - 1) ? ", " : " ");
	}
	cout << "}";
	cout << endl << "Генерация сочетаний ";
	combi::xcombination xc(sizeof(AA) / 2, 3);
	cout << "из " << xc.n << " по " << xc.m;
	int  n2 = xc.getfirst();
	while (n2 >= 0)
	{
		cout << endl << xc.nc << ": { ";
		for (int i = 0; i < n2; i++)
		{
			cout << AA[xc.ntx(i)] << ((i < n2 - 1) ? ", " : " ");
		}
		cout << "}";
		n2 = xc.getnext();
	};
	cout << endl << "всего: " << xc.count() << endl;

	//-----------------------------------------------------------------------

	cout << endl << " --- Генератор перестановок --- ";
	cout << endl << "Исходное множество: ";
	cout << "{ ";
	for (int i = 0; i < sizeof(AA) / 2; i++)
	{
		cout << AA[i] << ((i < sizeof(AA) / 2 - 1) ? ", " : " ");
	}
	cout << "}";
	cout << endl << "Генерация перестановок ";
	combi::permutation p(sizeof(AA) / 2);
	__int64  n3 = p.getfirst();
	while (n3 >= 0)
	{
		cout << endl << setw(4) << p.np << ": { ";
		for (int i = 0; i < p.n; i++)
		{
			cout << AA[p.ntx(i)] << ((i < p.n - 1) ? ", " : " ");
		}
		cout << "}";
		n3 = p.getnext();
	};
	cout << endl << "всего: " << p.count() << endl;

	//-----------------------------------------------------------------------

	cout << endl << " --- Генератор размещений --- ";
	cout << endl << "Исходное множество: ";
	cout << "{ ";
	for (int i = 0; i < H; i++)
	{
		cout << AA[i] << ((i < H - 1) ? ", " : " ");
	}
	cout << "}";
	cout << endl << "Генерация размещений  из  " << H << " по " << M;
	combi::accomodation s(H, M);
	int  n4 = s.getfirst();
	while (n4 >= 0)
	{
		cout << endl << setw(2) << s.na << ": { ";
		for (int i = 0; i < 3; i++)
		{
			cout << AA[s.ntx(i)] << ((i < n4 - 1) ? ", " : " ");
		}
		cout << "}";
		n4 = s.getnext();
	};
	cout << endl << "всего: " << s.count() << endl;

	//-------------------------------------------------------------------------------

	int v[COUNT]; //Вес контейнеров
	int c[COUNT]; //Доход от перевзки каждого
	auxil::start();
	for (int i = 0; i < COUNT; i++)
	{
		v[i] = auxil::iget(100, 900);
		c[i] = auxil::iget(10, 150);
	}
	int V = 1500;
	short  r[MM];

	clock_t t1 = clock();
	int cc = boat(
		V,   // [in]  максимальный вес груза
		MM,  // [in]  количество мест для контейнеров     
		NN,  // [in]  всего контейнеров  
		v,   // [in]  вес каждого контейнера  
		c,   // [in]  доход от перевозки каждого контейнера     
		r    // [out] результат: индексы выбранных контейнеров  
	);
	clock_t t2 = clock();

	cout << endl << "Задача о размещении контейнеров на судне \n --------------------------------";
	cout << endl << "Общее количество контейнеров : " << NN;
	cout << endl << "количество мест для контейнеров : " << MM;
	cout << endl << "ограничение по суммарному весу  : " << V;
	cout << endl << "вес контейнеров : ";
	for (int i = 0; i < NN; i++)
	{
		cout << setw(3) << v[i] << " ";
	}
	cout << endl << "доход от перевозки : ";
	for (int i = 0; i < NN; i++)
	{
		cout << setw(3) << c[i] << " ";
	}
	cout << endl << "выбраны контейнеры (0,1,...,m-1): ";
	for (int i = 0; i < MM; i++)
	{
		cout << r[i] << " ";
	}
	cout << endl << "доход от перевозки : " << cc;
	cout << endl << "общий вес выбранных контейнеров : ";
	int k = 0; 
	for (int i = 0; i < MM; i++)
	{
		k += v[r[i]];
	} 
	cout << k;
	cout << endl << endl;
	cout << "Время: " << ((double)(t2 - t1)) / ((double)CLOCKS_PER_SEC) << endl;
	system("pause");

	cout << endl << "Задача об оптимальной загрузке судна \n ----------------------------------- ";
	cout << endl << "ограничение по весу : " << V;
	cout << endl << "количество мест : " << MM;
	cout << endl << "количество контейнеров / продолжительность вычисления";
	for (int i = 25; i <= NN; i++)
	{
		t1 = clock();
		int maxcc = boat(V, MM, i, v, c, r);
		t2 = clock();
		cout << endl << "          " << setw(2) << i << "                     " << setw(5) << (t2 - t1);
	}
	cout << endl << endl;
	system("pause");
}