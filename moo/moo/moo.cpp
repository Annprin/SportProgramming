#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> matrix(n, vector<char>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    map<string, int> moo;
    long long int max = 0;
    string key;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            //matrix[i][j] == 'M'
            if (matrix[i][j] != 'M') {
                // 2 вперед
                if (j + 2 < m && matrix[i][j] != matrix[i][j + 1] && matrix[i][j + 1]!='O' && matrix[i][j + 1] == matrix[i][j + 2]) {
                    key = matrix[i][j];
                    key += matrix[i][j + 1];
                    moo[key] += 1;
                    //cout << key << " " << moo[key] << endl;
                    if (moo[key] > max) {
                        max = moo[key];
                    }
                }

                // 2 вниз
                if (i + 2 < n && matrix[i][j] != matrix[i + 1][j] && matrix[i + 1][j] != 'O' && matrix[i + 1][j] == matrix[i + 2][j]) {
                    key = matrix[i][j];
                    key += matrix[i + 1][j];
                    moo[key] += 1;
                    //cout << key << " " << moo[key] << endl;
                    if (moo[key] > max) {
                        max = moo[key];
                    }
                }

                // вправо вниз по диагонали
                if (j + 2 < m && i + 2 < n && matrix[i][j] != matrix[i + 1][j + 1] && matrix[i + 1][j + 1] != 'O' && matrix[i + 1][j + 1] == matrix[i + 2][j + 2]) {
                    key = matrix[i][j];
                    key += matrix[i + 1][j + 1];
                    moo[key] += 1;
                    //cout << key << " " << moo[key] << endl;
                    if (moo[key] > max) {
                        max = moo[key];
                    }
                }

                // влево вниз по диагонали
                if (j - 2 >= 0 && i + 2 < n && matrix[i][j] != matrix[i + 1][j - 1] && matrix[i + 1][j - 1] != 'O' && matrix[i + 1][j - 1] == matrix[i + 2][j - 2]) {
                    key = matrix[i][j];
                    key += matrix[i + 1][j - 1];
                    moo[key] += 1;
                    //cout << key << " " << moo[key] << endl;
                    if (moo[key] > max) {
                        max = moo[key];
                    }
                }
            }
            //matrix[i][j] == 'O'
            if (matrix[i][j] != 'O') {
                // 2 вперед
                if (j + 2 < m && matrix[i][j] != matrix[i][j + 2] && matrix[i][j + 2] != 'M' && matrix[i][j] == matrix[i][j + 1]) {
                    key = matrix[i][j + 2];
                    key += matrix[i][j];
                    moo[key] += 1;
                    //cout << key << " " << moo[key] << endl;
                    if (moo[key] > max) {
                        max = moo[key];
                    }
                }

                // 2 вниз
                if (i + 2 < n && matrix[i][j] != matrix[i + 2][j] && matrix[i + 2][j] != 'M' && matrix[i][j] == matrix[i + 1][j]) {
                    key = matrix[i + 2][j];
                    key += matrix[i][j];
                    moo[key] += 1;
                    //cout << key << " " << moo[key] << endl;
                    if (moo[key] > max) {
                        max = moo[key];
                    }
                }

                // вправо вниз по диагонали
                if (j + 2 < m && i + 2 < n && matrix[i][j] != matrix[i + 2][j + 2] && matrix[i + 2][j + 2] != 'M' && matrix[i][j] == matrix[i + 1][j + 1]) {
                    key = matrix[i + 2][j + 2];
                    key += matrix[i][j];
                    moo[key] += 1;
                    //cout << key << " " << moo[key] << endl;
                    if (moo[key] > max) {
                        max = moo[key];
                    }
                }

                // влево вниз по диагонали
                if (j - 2 >= 0 && i + 2 < n && matrix[i][j] != matrix[i + 2][j - 2] && matrix[i + 2][j - 2] != 'M' && matrix[i][j] == matrix[i + 1][j - 1]) {
                    key = matrix[i + 2][j - 2];
                    key += matrix[i][j];
                    moo[key] += 1;
                    //cout << key << " " << moo[key] << endl;
                    if (moo[key] > max) {
                        max = moo[key];
                    }
                }
            }
        }
    }
    cout << max;
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
