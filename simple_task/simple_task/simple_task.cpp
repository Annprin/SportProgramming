#include <iostream>

using namespace std;

int findMount(long long int one, long long int two, long long int k, long long int d) {
    long long int levelOne = one, levelTwo = two;
    long long int count = 0;
    while (levelOne != levelTwo) {
        long long int *levelMax = &levelTwo;
        if (levelOne > levelTwo){
            levelMax = &levelOne;
        }
        *levelMax = (*levelMax + d) / k;
        ++count;
    }
    return count;
}

int main()
{
    long long int n = 0, k = 0, q = 0;
    cin >> n >> k >> q;
    long long int d = k - 2;
    for (long long int i = 0; i < q; i++) {
        long long int one = 0, two = 0;
        cin >> one >> two;
        cout << findMount(one, two, k, d) << endl;
    }
    return 0;
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
