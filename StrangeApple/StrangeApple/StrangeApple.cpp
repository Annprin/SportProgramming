#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct bad_positive {
    int id;
    int a;
    int plus;
};

int main()
{
    vector<bad_positive> remember;
    int n;
    long long int s;
    cin >> n >> s;
    long long int positive = s;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        s += b - a;
        remember.push_back({ i + 1, a, b - a });
    }
    if (s <= 0) {
        cout << "-1";
        return 0;
    }
    
    sort(remember.begin(), remember.end(),
        [](const bad_positive& a, const bad_positive& b) {
            bool res = false;
            if (a.plus > 0 && b.plus > 0)
                res = (a.a < b.a) || (a.a == b.a && a.plus > b.plus);
            else if (a.plus < 0 && b.plus < 0)
                res = (a.a + a.plus > b.a + b.plus);
            else if (a.plus* b.plus <= 0)
                res = a.plus > b.plus;
            return res;
        });

    long long int len = remember.size();

    for (int i = 0; i < len; i++) {
        if (positive <= remember[i].a) {
            cout << "-1";
            return 0;
        }
        positive += remember[i].plus;
    }

    len = remember.size();
    for (int i = 0; i < len; i++) {
        cout << remember[i].id << " ";
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
