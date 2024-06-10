#include <iostream>
#include <string>

// Clase Persona
class Persona {
public:
    Persona(const std::string& nombre) : nombre_(nombre) {}
    std::string getDescription() const {
        return "Persona con nombre " + nombre_;
    }
private:
    std::string nombre_;
};

// Clase Poste
class Poste {
public:
    Poste(float altura, float diametro) : altura_(altura), diametro_(diametro) {}
    std::string getDescription() const {
        return "Poste con altura de " + std::to_string(altura_) + " metros y " + std::to_string(diametro_) + " cm de diámetro";
    }
private:
    float altura_;
    float diametro_;
};

// Función genérica para imprimir descripciones
template<typename T>
void printDescription(const T& obj) {
    std::cout << obj.getDescription() << std::endl;
}

int main() {
    // Crear objetos de la clase Persona
    Persona persona1("Ayelen");
    Persona persona2("Fabricio");

    // Crear objetos de la clase Poste
    Poste poste1(8, 15);
    Poste poste2(10, 20);

    // Imprimir descripciones
    printDescription(persona1);
    printDescription(persona2);
    printDescription(poste1);
    printDescription(poste2);

    return 0;
}
