#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct up {
    int id;
    int a;
    int plus;
};

int main()
{
    vector<up> positive, negative;
    int n;
    int s;
    cin >> n >> s;
    int now = s;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        s = b - a;
        if (s > 0) {
            positive.push_back({ i + 1, a, s });
        }
        else {
            negative.push_back({ i + 1, a, s });
        }
    }

    vector<int> result;
    int len = positive.size();
    for (int i = 0; i < len; ++i) {
        int drop = 0;
        for (int j = 0; j < len; ++j) {
            if (now > positive[j].a) {
                ++drop;
                result.push_back(positive[j].id);
                now += positive[j].plus;
                positive.erase(positive.begin() + j);
            }
        }
        if (drop == 0) {
            cout << "-1";
            return 0;
        }
        else if (drop == len) {
            break;
        }
        len -= drop;
    }

    int len = negative.size();
    sort(negative.begin(), negative.end(),
        [](const up& a, const up& b) {
            bool res = false;
            if (a.plus > 0 && b.plus > 0)
                res = (a.a < b.a) || (a.a == b.a && a.plus > b.plus);
            else
                res = (a.plus > b.plus) || (a.plus == b.plus && a.a > b.a);
            return res;

            if (a.plus > 0 && b.plus > 0)
                res = (a.a < b.a) || (a.a == b.a && a.plus > b.plus);
            else if (a.plus < 0 && b.plus < 0)
                res = (a.a + a.plus > b.a + b.plus);
            else if (a.plus * b.plus <= 0)
                res = a.plus > b.plus;
            return res;
        });

    for (int i = 0; i < len; ++i) {
        int drop = 0;
        for (int j = 0; j < len; ++j) {
            if (now > positive[j].a) {
                ++drop;
                result.push_back(positive[j].id);
                now += positive[j].plus;
                positive.erase(positive.begin() + j);
            }
        }
        if (drop == 0) {
            cout << "-1";
            return 0;
        }
        else if (drop == len) {
            break;
        }
        len -= drop;
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
