#ifndef COMPLEX2D_H
#define COMPLEX2D_H

class Complex2D
{
private:
    double reel;
    double imaginaire;

public:
    // Constructeur avec réel et imaginaire
    Complex2D(double reel, double imaginaire);

    // Constructeur avec une seule valeur pour réel et imaginaire
    Complex2D(double valeur);

    // Constructeur par copie
    Complex2D(const Complex2D& autre);

     // Getters
    double getReel();
    double getImaginaire();

    // Setters
    void setReel(double reel);
    void setImaginaire(double imaginaire);

    // Opérateur +
    Complex2D operator+(const Complex2D& autre);
    Complex2D operator-(const Complex2D& autre);
    Complex2D operator*(const Complex2D& autre);
    Complex2D operator/(const Complex2D& autre);
    bool operator<(const Complex2D& autre);
    bool operator>(const Complex2D& autre); 

};

#endif