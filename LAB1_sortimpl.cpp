#include <iostream>
#include "LAB1_interfejs.h"

using namespace std;

void sort(int t[], int size)
{
	int c, a;
	for (int i = 1; i < size; i++)
	{
		c = t[i];
		a = i - 1;
		while (a >= 0 && t[a] > c)
		{
			t[a + 1] = t[a];
			--a;
		}
		t[a + 1] = c;
	}
}

void piszTab(int t[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << t[i] << "\t";
	}
	cout << "\n";
}