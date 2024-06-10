#include <iostream>

// Función de ordenamiento por inserción
template <class T>
void insertionSort(T* v, int cantidad, bool mayor_a_menor) {
    for (int i = 1; i < cantidad; ++i) {
        T key = v[i];
        int j = i - 1;

        if (mayor_a_menor) {
            while (j >= 0 && v[j] < key) {
                v[j + 1] = v[j];
                --j;
            }
        } else {
            while (j >= 0 && v[j] > key) {
                v[j + 1] = v[j];
                --j;
            }
        }
        v[j + 1] = key;
    }
}

// Función genérica para imprimir el array ordenado
template <class T>
void imprimir(T* v, int cantidad, bool mayor_a_menor) {
    insertionSort(v, cantidad, mayor_a_menor);
    for (int i = 0; i < cantidad; ++i) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int arrInt[] = {4, 2, 5, 1, 3};
    float arrFloat[] = {4.2, 2.1, 5.3, 1.8, 3.7};

    std::cout << "Array int ordenado de menor a mayor: ";
    imprimir(arrInt, 5, false);

    std::cout << "Array int ordenado de mayor a menor: ";
    imprimir(arrInt, 5, true);

    std::cout << "Array float ordenado de menor a mayor: ";
    imprimir(arrFloat, 5, false);

    std::cout << "Array float ordenado de mayor a menor: ";
    imprimir(arrFloat, 5, true);

    return 0;
}
