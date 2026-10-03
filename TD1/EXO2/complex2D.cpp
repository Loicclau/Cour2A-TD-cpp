#include "Complex2D.h"

// Constructeur avec réel et imaginaire
Complex2D::Complex2D(double reel, double imaginaire)
{
    this->reel = reel;
    this->imaginaire = imaginaire;
}

// Constructeur avec une seule valeur
Complex2D::Complex2D(double valeur)
{
    reel = valeur;
    imaginaire = valeur;
}

// Constructeur par copie
Complex2D::Complex2D(const Complex2D& autre)
{
    reel = autre.reel;
    imaginaire = autre.imaginaire;
}


// Getters
double Complex2D::getReel()
{
    return reel;
}
double Complex2D::getImaginaire()
{
    return imaginaire;
}

// Setters
void Complex2D::setReel(double reel)
{
    this->reel = reel;
}

void Complex2D::setImaginaire(double imaginaire)
{
    this->imaginaire = imaginaire;
}


// Opérateur +
Complex2D Complex2D::operator+(const Complex2D& autre)
{
    return Complex2D(
        reel + autre.reel,
        imaginaire + autre.imaginaire
    );
}

// Soustraction
Complex2D Complex2D::operator-(const Complex2D& autre)
{
    return Complex2D(
        reel - autre.reel,
        imaginaire - autre.imaginaire
    );
}

// Multiplication
Complex2D Complex2D::operator*(const Complex2D& autre)
{
    return Complex2D(
        reel * autre.reel - imaginaire * autre.imaginaire,  //partie réelle
        reel * autre.imaginaire + imaginaire * autre.reel //imag
    );
}


// Division
Complex2D Complex2D::operator/(const Complex2D& autre)
{
    //calcule le dénominateur
    double denominateur = autre.reel * autre.reel + autre.imaginaire * autre.imaginaire;

    return Complex2D(
        (reel * autre.reel + imaginaire * autre.imaginaire) / denominateur,
        (imaginaire * autre.reel - reel * autre.imaginaire) / denominateur
    );
}

// Comparaison <

// ON Comparer les modules
bool Complex2D::operator<(const Complex2D& autre)
{
    double module1 = reel * reel + imaginaire * imaginaire;
    double module2 = autre.reel * autre.reel + autre.imaginaire * autre.imaginaire;

    return module1 < module2;
}

// Comparaison >
bool Complex2D::operator>(const Complex2D& autre)
{
    double module1 = reel * reel + imaginaire * imaginaire;
    double module2 = autre.reel * autre.reel + autre.imaginaire * autre.imaginaire;

    return module1 > module2;
}