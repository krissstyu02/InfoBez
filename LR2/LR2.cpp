// LR2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

long gcd_ext(long a, long b, long& x, long& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long d = gcd_ext(b, a % b, x, y);
    x -= (a / b) * y;
    swap(x, y);
    return d;
}

int main()
{
    ifstream input("input.txt");
    long n, m, d, c, x, y;
    input >> n >> m >> d >> c;
    vector<long> v;
    for (int i = 0; i < m; i++) {
        int el; input >> el;
        v.push_back(el);
    }
    vector<long> result;
    ofstream output("output.txt");
    for (int i = 0; i < m; i++) {
        long e = gcd_ext(d, -n, x, y);
        if ((v[i] - c) % e != 0) {
            output << "NO";
            return 0;
        }
        long p = x * (v[i] - c) / e;
        long q = (-n) / e;
        long ans = (p % q + q) % q;
        if (ans < 0) {
            ans += n;
        }
        result.push_back(ans);

    }

    output << "Yes" << endl;
    for (int i = 0; i < m; i++) {
        output << result[i] << ' ';
    }
    //y - целое
    //x*d - n*y = j-c

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
