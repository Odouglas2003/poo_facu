#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Jugador {
public:
    // Constructor 1
    Jugador() : velocidad(0), fuerza(0), nombre("sin nombre") {}

    // Constructor 2
    Jugador(int velocidad, int fuerza, const string& nombre)
        : velocidad(velocidad), fuerza(fuerza), nombre(nombre) {}

    // Destructor
    ~Jugador() {}

    int getVelocidad() const { return velocidad; }
    int getFuerza() const { return fuerza; }
    string getNombre() const { return nombre; }

private:
    int velocidad = 0;
    int fuerza = 0;
    string nombre = "sin nombre";
};

int main() {
    vector<Jugador> jugadores;


    for (int i = 1; i <= 10; ++i) {
        jugadores.emplace_back(i * 5, i * 10, "Jugador" + to_string(i)); // nuevos 10 jugadores
    }

    for (const auto& jugador : jugadores) {
        cout << "Nombre: " << jugador.getNombre() << ", Velocidad: " << jugador.getVelocidad()
                  << ", Fuerza: " << jugador.getFuerza() << endl;
    }

    return 0;
}
