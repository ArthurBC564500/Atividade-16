#include <iostream>
#include <cmath>
#include <string>
using namespace std;

class Ponto {
private:
    double x;
    double y;

public:
    Ponto() {
        x = 0;
        y = 0;
    }

    Ponto(double x, double y) {
        this->x = x;
        this->y = y;
    }

    void setPosicao(double x, double y) {
        this->x = x;
        this->y = y;
    }

    double getX() {
        return x;
    }

    double getY() {
        return y;
    }

    double distanciaPara(double x2, double y2) {
        return sqrt(pow(x - x2, 2) + pow(y - y2, 2));
    }

    double distanciaPara(Ponto outro) {
        return distanciaPara(outro.getX(), outro.getY());
    }
};

class Circulo : public Ponto {
protected:
    double raio;

public:
    Circulo() : Ponto() {
        raio = 1.0;
    }

    Circulo(double x, double y, double r) : Ponto(x, y) {
        raio = r;
    }

    void setRaio(double r) {
        raio = r;
    }

    double getRaio() {
        return raio;
    }

    double calcularArea() {
        return 3.141592653589793 * raio * raio;
    }

    double calcularCircunferencia() {
        return 2 * 3.141592653589793 * raio;
    }
};

class Roda : public Circulo {
private:
    string material;
    int aro;
    string fabricante;

public:
    Roda(double x, double y, double r, string mat, int a, string fab)
        : Circulo(x, y, r) {
        material = mat;
        aro = a;
        fabricante = fab;
    }

    void exibirDados() {
        cout << "Material: " << material << endl;
        cout << "Aro: " << aro << endl;
        cout << "Fabricante: " << fabricante << endl;
        cout << "Raio: " << raio << endl;
        cout << "Centro: (" << getX() << ", " << getY() << ")" << endl;
    }
};

class Esfera : public Circulo {
public:
    Esfera(double x, double y, double r) : Circulo(x, y, r) {}

    double calcularVolume() {
        return (4.0 / 3.0) * 3.141592653589793 * pow(raio, 3);
    }
};

int main() {
    Ponto p1(2.0, 3.0);
    cout << "Ponto p1: (" << p1.getX() << ", " << p1.getY() << ")" << endl;

    Circulo c1(1.0, 1.0, 5.0);
    cout << "Area do circulo: " << c1.calcularArea() << endl;
    cout << "Circunferencia do circulo: " << c1.calcularCircunferencia() << endl;

    Roda r1(0.0, 0.0, 7.0, "borracha", 17, "Firestone");
    cout << "\nDados da roda:" << endl;
    r1.exibirDados();

    Esfera e1(0.0, 0.0, 4.0);
    cout << "\nVolume da esfera: " << e1.calcularVolume() << endl;

    return 0;
}
