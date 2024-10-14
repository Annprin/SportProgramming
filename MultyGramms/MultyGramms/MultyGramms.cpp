#include <iostream>
#include <vector>

using namespace std;

struct count_ab {
    int a;
    int b;
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    char c;
    vector<count_ab> str;
    int count_a = 0, count_b = 0;

    while (cin >> c) {
        if (c == 'a') {
            count_a += 1;
        }
        else {
            count_b += 1;
        }
        str.push_back({ count_a, count_b });
    }
    int l = str.size();
    for (int end = 1; end <= l / 2; end++) {
        if (l % end != 0) {
            continue;
        }

        bool is_repeating = true;
        int a = str[end - 1].a;
        int b = str[end - 1].b;
        for (int i = 2 * end - 1; i < l; i += end) {
            if (str[i].a - str[i - end].a != a || str[i].b - str[i - end].b != b) {
                is_repeating = false;
                break;
            }
        }

        if (is_repeating) {
            cout << end;
            return 0;
        }
    }
    cout << "-1";
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
