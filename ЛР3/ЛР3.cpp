// ЛР3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;


bool Perest(string s) { 
	vector<int> v;
	for (int i = 0; i < s.size(); i++) {
		v.push_back(s[i]);
	}
	sort(begin(v), end(v));
	if (v[0] == 65) { //ascii(A)
		for (int i = 1; i < s.size(); i++) {
			if (v[i - 1] + 1 != v[i]) {
				return false;
			}
		}
	}
	else {
		return false;
	}
	return true;
}

bool SemiPerest(string s) { //проверка на почти перестановочную
	bool f = false;
	for (int i = 0; i < s.size(); i++) {
		string tmp = s;
		tmp.erase(i, 1);
		f = Perest(tmp);
		if (f) {
			return true;
		}
	}
	return false;
}

bool getNextString(string& s, int nowSize) {
	bool f = true;
	for (int i = 0; i < s.size(); i++) {
		f = s[i] == 64 + nowSize && f;
	}
	if (f) {
		return false;
	}

	int i = 0;
	string newString = "";
	while (true) {
		if (s[i] == 64 + nowSize) {
			newString += "A";
			i++;
		}
		else {
			newString += char(s[i] + 1) + s.substr(i + 1);
			break;
		}
	}
	s = newString;
	return true;
}

bool isContains(string s, string s1) {
	bool f = false;
	for (int i = 0; i < s.size() - s1.size() + 1; i++) {
		f = s.substr(i, s1.size()) == s1;  //проверка на подстроку
		if (f) {
			return true;
		}
	}
	return false;
}

bool HyperSemiPerest(string s, int n) { //гипер почти перестановочная
	n = n + 1;
	bool f = true;
	for (int i = 0; i < s.size() + 1 - n; i++) {
		f = SemiPerest(s.substr(i, n));
		if (!f) {
			return false;
		}
	}
	return true;
}

int main()
{
	setlocale(LC_ALL,"Russian");
	int n; string t;
	ifstream input("input.txt");
	ofstream output("output.txt");
	getline(input, t);
	n = stoi(t);//преобразует строку в int
	string s1, s2;
	getline(input, s1);
	getline(input, s2);
	int minSize = min(s1.size(), s2.size());

	int nowSize = minSize - 1;
	while (true) {
		nowSize++;
		string s = "";
		for (int i = 0; i < nowSize; i++) {
			s += "A";
		}
		do {
			if (isContains(s, s1) && isContains(s, s2)) {
				if (s == "ABCACB") {
					cout << ("Решение в файле 'output'");
				}
				if (HyperSemiPerest(s, n)) {
					output << s;
					return 0;
				}
			}

		} while (getNextString(s, nowSize));
	}
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
