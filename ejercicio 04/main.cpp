#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <unordered_map>

using namespace std;
int main() {
    srand(time(nullptr));

    vector<int> numeros;

    for (int i = 0; i < 30; ++i) {
        int num = rand() % 15 + 1;
        numeros.push_back(num);
    }

    unordered_map<int, int> frecuencia;
    for (int num : numeros) {
        frecuencia[num]++;
    }

    int moda =max_element(frecuencia.begin(), frecuencia.end(),
                                [](const auto &a, const auto &b) {
                                    return a.second < b.second;
                                })->first;

    cout << "La moda es: " << moda << endl;

    return 0;
}
