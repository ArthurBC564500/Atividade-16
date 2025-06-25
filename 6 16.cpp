#include <iostream>
#include <string>

class Funcionario {
protected:
    std::string nome;
    double salarioBase;
public:
    Funcionario(std::string n, double s) : nome(n), salarioBase(s) {}
    virtual double calcularSalario() { return salarioBase; }
    void exibirDados() {
        std::cout << "Nome: " << nome << ", Salario: " << calcularSalario() << std::endl;
    }
    virtual ~Funcionario() {}
};

class Gerente : public Funcionario {
public:
    Gerente(std::string n, double s) : Funcionario(n, s) {}
    double calcularSalario() override { return salarioBase + 2000; }
};

class Desenvolvedor : public Funcionario {
    int projetos;
public:
    Desenvolvedor(std::string n, double s, int p) : Funcionario(n, s), projetos(p) {}
    double calcularSalario() override { return salarioBase + (projetos * 500); }
};

class Estagiario : public Funcionario {
    float percentual;
public:
    Estagiario(std::string n, double s, float p) : Funcionario(n, s), percentual(p) {}
    double calcularSalario() override { return salarioBase * percentual; }
};

int main() {
    Funcionario* funcionarios[3];
    
    funcionarios[0] = new Gerente("Ana", 5000);
    funcionarios[1] = new Desenvolvedor("Carlos", 4000, 3);
    funcionarios[2] = new Estagiario("Pedro", 2000, 0.5);
    
    for(int i = 0; i < 3; i++) {
        funcionarios[i]->exibirDados();
    }
    
    delete funcionarios[0];
    delete funcionarios[1];
    delete funcionarios[2];
    
    return 0;
}