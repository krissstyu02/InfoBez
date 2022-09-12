#include <iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
    string s;
    int k ;
    ifstream f("input.txt");
    char a[100];
    ofstream f1("output.txt");
    while(!(f.eof()))
    {
        k = 0;
        getline(f, s);
        for (int i = 0; i < s.size(); i++)
        {
            a[i] = s[i];
            k++;
        }
        for (int i = k - 1; i >= 0; i--)
        {
            f1 << a[i];
        }
        f1 << endl;

    }
    f.close();
    f1.close();
}