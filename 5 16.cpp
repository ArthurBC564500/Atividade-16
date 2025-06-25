#include <iostream>
#include <string>

class Veiculo {
public:
    double peso, velocidadeMaxima, preco;
    
    Veiculo(double p, double v, double pr) : peso(p), velocidadeMaxima(v), preco(pr) {}
    
    void print() {
        std::cout << "Peso: " << peso << ", Velocidade: " << velocidadeMaxima << ", Preco: " << preco << std::endl;
    }
};

class Motor {
public:
    int numCilindros;
    double potencia;
    
    Motor(int nc, double pot) : numCilindros(nc), potencia(pot) {}
    
    void print() {
        std::cout << "Cilindros: " << numCilindros << ", Potencia: " << potencia << std::endl;
    }
};

class CarroPasseio : public Veiculo, public Motor {
public:
    std::string modelo, cor;
    
    CarroPasseio(double p, double v, double pr, int nc, double pot, std::string m, std::string c)
        : Veiculo(p, v, pr), Motor(nc, pot), modelo(m), cor(c) {}
    
    void print() {
        std::cout << "Modelo: " << modelo << ", Cor: " << cor << std::endl;
        Veiculo::print();
        Motor::print();
    }
};

class Caminhao : public Veiculo, public Motor {
public:
    double toneladas, alturaMaxima, comprimento;
    
    Caminhao(double p, double v, double pr, int nc, double pot, double t, double alt, double comp)
        : Veiculo(p, v, pr), Motor(nc, pot), toneladas(t), alturaMaxima(alt), comprimento(comp) {}
    
    void print() {
        std::cout << "Toneladas: " << toneladas << ", Altura: " << alturaMaxima << ", Comprimento: " << comprimento << std::endl;
        Veiculo::print();
        Motor::print();
    }
};

int main() {
    Veiculo v(1200, 180, 50000);
    Motor m(4, 150);
    CarroPasseio c(1400, 200, 80000, 4, 180, "Civic", "Preto");
    Caminhao cam(8000, 120, 250000, 6, 400, 15, 4.2, 12);
    
    v.print();
    m.print();
    c.print();
    cam.print();
    
    return 0;
}