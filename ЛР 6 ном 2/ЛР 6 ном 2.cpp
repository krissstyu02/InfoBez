// ЛР 6 ном 2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include  <iostream>
#include <vector>
using namespace std;


void CreateCS(vector<vector<bool>>& a, vector<int>& ls, vector<int>& lo)//передаю вектор матрицы и вектора массивов
{


	int i, j;
	for (i = 0; i < ls.size(); i++)
	{
		ls[i] = rand() % 10 + 1;
	}
	for (i = 0; i < lo.size(); i++)
	{
		lo[i] = rand() % 10 + 1;
	}
	for (i = 0; i < ls.size(); i++)
	{
		for (j = 0; j < lo.size(); j++)
		{
			if (ls[i] > lo[j])
			{
				a[i][j] = true;
			}
			else
			{
				a[i][j] = false;
			}
		}
	}
}


bool CheckCS(vector<vector<bool>> a, vector<int> ls, vector<int> lo) //Критерий безопасности Белла-Лападула
{
	int i, j;
	for (i = 0; i < ls.size(); i++)
	{
		for (j = 0; j < lo.size(); j++)
		{
			if (!((ls[i] > lo[j] && a[i][j]) || (ls[i] <= lo[j] && !(a[i][j]))))
			{
				return false;
			}
		}
	}
	return true;
}

bool GetVectors(const vector<vector<bool>>& a, vector<int>& ls, vector<int>& lo)
{
	int i, j;
	ls.clear();
	lo.clear();

	for (i = 0; i < a.size(); i++)
	{
		int cnt_s = 1;

		for (j = 0; j < a[i].size(); j++)
		{
			if (a[i][j])
			{
				cnt_s++;
			}
		}
		ls.push_back(cnt_s);
	}

	for (i = 0; i < a[0].size(); i++)
	{
		int min = 1;
		for (j = 0; j < a.size(); j++)
		{
			if (!a[j][i] && ls[j] > min)
			{
				min = ls[j];
			}
		}
		lo.push_back(min);
	}
	return CheckCS(a, ls, lo);
}


int main()
{
	setlocale(LC_ALL, "Rus");
	vector<vector<bool>> matrixA; //вектор для матрицы А
	int n, m, i, j;

	cout << "Введите число субъектов и объектов через строку:" << endl;
	cin >> n >> m;
	cout << "Генерация RW" << endl;
	matrixA.resize(n);
	for (i = 0; i < n; i++)
	{
		matrixA[i].resize(m);
	}

	//векторы для массивов LS и LO
	vector<int> ls;
	ls.resize(n);
	vector<int> lo;
	lo.resize(m);

	CreateCS(matrixA, ls, lo);//создаю компьютерную систему

	//вывод на экран матрицы и массивов
	cout << "Значения субъектов:" << endl;
	for (i = 0; i < ls.size(); i++)
	{
		cout << ls[i] << " ";
	}
	cout << endl;
	cout << "Значения объектов:" << endl;
	for (i = 0; i < lo.size(); i++)
	{
		cout << lo[i] << " ";
	}
	cout << endl;
	cout << "Значения матрицы:" << endl;
	for (i = 0; i < ls.size(); i++)
	{
		for (j = 0; j < lo.size(); j++)
		{
			if (matrixA[i][j])
			{
				cout << "W" << " ";
			}
			else
			{
				cout << "R" << " ";
			}
		}
		cout << endl;
	}

	if (CheckCS(matrixA, ls, lo))//проверка на соотвествие критерию безопасности
	{
		cout << "Система безопасна!" << endl;
	}
	else
	{
		cout << "Система небезопасно!" << endl;
	}

	if (GetVectors(matrixA, ls, lo))//формирование итоговых векторов объектов и субъектов
	{
		cout << "Итоговые вектора объектов и субъектов: " << endl;

		for (i = 0; i < ls.size(); i++)
		{
			cout << ls[i] << " ";
		}
		cout << endl;

		for (i = 0; i < lo.size(); i++)
		{
			cout << lo[i] << " ";
		}
	}
}

