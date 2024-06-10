#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Autos {
public:
    string nombre;
    int ano;

    // Constructor
    Autos(string _nombre, int _ano)
        : nombre(_nombre), ano(_ano) {}
};

int main() {
    // Crear un vector de objetos Autos
    vector<Autos> autosList = {
        Autos("Ford", 2024),
        Autos("Fiat", 2015),
        Autos("Toyota", 2020),
        Autos("Chevrolet", 2018)
    };

    // Ordenar el vector de menor a mayor según el año
    sort(autosList.begin(), autosList.end(), [](const Autos& a, const Autos& b) {
        return a.ano < b.ano;
    });

    // Imprimir los autos ordenados
    for (const auto& autoObj : autosList) {
        cout << "Nombre: " << autoObj.nombre << ", Año: " << autoObj.ano << endl;
    }

    return 0;
}
