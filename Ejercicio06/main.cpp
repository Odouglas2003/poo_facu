#include <iostream>
#include <string>

using namespace std;

class autos {
public:
    string Autos;
    int ano;

    // Constructor
    autos(string _autos, int _ano)
        : Autos(_autos), ano(_ano) {}
};

int main() {

    autos autos1("Ford", 2024);
    autos autos2("Fiat",  2015);

    cout<<"autos 1:"<<endl;
    cout << "autos: " << autos1.Autos << endl;
    cout << "Año: " << autos1.ano << endl;

    cout<<"-------------------------------"<<endl;

    cout<<"autos 2:"<<endl;
    cout << "autos: " << autos2.Autos << endl;
    cout << "ano : " << autos2.ano << endl;

    return 0;
}
