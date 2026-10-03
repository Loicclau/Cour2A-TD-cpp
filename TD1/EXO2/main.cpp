#include <iostream>
#include "Complex2D.h"

using namespace std;

int main()
{
    // On crée un nombre complexe
    Complex2D c1(3, 4);
    // Si on met une seul valeur on a 5 + 5i
    Complex2D c2(5);
    // test le constructeur par copie 
    Complex2D c3(c1);

    cout << c3.getReel() << endl;
    cout << c3.getImaginaire() << endl;

    // On modifie les valeurs de c3
    c3.setReel(10);
    c3.setImaginaire(20);

    cout << c3.getReel() << endl;
    cout << c3.getImaginaire() << endl;


    // Test des opérateurs
    // Addition de c1 et c2
    Complex2D addition = c1 + c2;
    cout << "Addition : "
         << addition.getReel() << " + "
         << addition.getImaginaire() << "i"
         << endl;


    // Soustraction de c1 et c2
    Complex2D soustraction = c1 - c2;
    cout << "Soustraction : "
         << soustraction.getReel() << " + "
         << soustraction.getImaginaire() << "i"
         << endl;


    // Multiplication
    Complex2D multiplication = c1 * c2;
    cout << "Multiplication : "
         << multiplication.getReel() << " + "
         << multiplication.getImaginaire() << "i"
         << endl;

    // Division
    Complex2D division = c1 / c2;
    cout << "Division : "
         << division.getReel() << " + "
         << division.getImaginaire() << "i"
         << endl;

    // On regarde si c1 est plus petit que c2
    if (c1 < c2){
        cout << "c1 est plus petit que c2" << endl;
    }
    else{
        cout << "c1 n'est pas plus petit que c2" << endl;
    }

    // On regarde si c1 est plus grand que c2
    if (c1 > c2){
        cout << "c1 est plus grand que c2" << endl;
    }
    else{
        cout << "c1 n'est pas plus grand que c2" << endl;
    }
    return 0;
}
