#include <QCoreApplication>
#include <iostream>
#include <QString>
#include <QDebug>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    vector<string> expresiones;

    expresiones.push_back("ahogarse en un vaso de agua");
    expresiones.push_back("tomar el pelo");
    expresiones.push_back("lo agarre con las manos en la masa");
    expresiones.push_back("irse por las ramas");
    expresiones.push_back("ser la oveja negra");

    sort(expresiones.begin(), expresiones.end());

    cout << "Expresiones idiomaticas ordenadas alfabeticamente:"<<endl;
        for(const auto& expresion : expresiones) {
            cout << expresion << endl;
        }
    return 0 ;
}
