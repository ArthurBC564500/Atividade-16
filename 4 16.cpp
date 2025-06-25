#include <iostream>

class Forma {
public:
    virtual double calcularArea() = 0;
    virtual ~Forma() {}
};

class Retangulo : public Forma {
private:
    double base, altura;
public:
    Retangulo(double b, double a) : base(b), altura(a) {}
    double calcularArea() override {
        return base * altura;
    }
};

class Triangulo : public Forma {
private:
    double base, altura;
public:
    Triangulo(double b, double a) : base(b), altura(a) {}
    double calcularArea() override {
        return (base * altura) / 2;
    }
};

int main() {
    Forma* formas[2];
    
    formas[0] = new Retangulo(5, 3);
    formas[1] = new Triangulo(4, 6);
    
    for(int i = 0; i < 2; i++) {
        std::cout << "Area: " << formas[i]->calcularArea() << std::endl;
    }
    
    delete formas[0];
    delete formas[1];
    
    return 0;
}