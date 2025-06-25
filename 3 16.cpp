#include <iostream>
#include <string>
using namespace std;

class Empregado {
protected:
    string nome;
    double salarioBase;
    double imposto;

public:
    Empregado() {
        nome = "";
        salarioBase = 0;
        imposto = 0;
    }

    Empregado(string n, double s, double i) {
        nome = n;
        salarioBase = s;
        imposto = i;
    }

    void setNome(string n) {
        nome = n;
    }

    void setSalarioBase(double s) {
        salarioBase = s;
    }

    void setImposto(double i) {
        imposto = i;
    }

    string getNome() {
        return nome;
    }

    double getSalarioBase() {
        return salarioBase;
    }

    double getImposto() {
        return imposto;
    }
};

class Vendedor : public Empregado {
private:
    double valorVendas;
    double comissao;

public:
    Vendedor() : Empregado() {
        valorVendas = 0;
        comissao = 0;
    }

    Vendedor(string n, double s, double i, double v, double c) : Empregado(n, s, i) {
        valorVendas = v;
        comissao = c;
    }

    void setValorVendas(double v) {
        valorVendas = v;
    }

    void setComissao(double c) {
        comissao = c;
    }

    double calcularSalario() {
        double salarioBruto = salarioBase + (comissao * valorVendas);
        return salarioBruto * (1 - imposto);
    }
};

int main() {
    Vendedor v1("Carlos", 2000.0, 0.1, 15000.0, 0.05);
    Vendedor v2("Ana", 2500.0, 0.08, 20000.0, 0.04);

    cout << "Salario liquido de " << v1.getNome() << ": R$ " << v1.calcularSalario() << endl;
    cout << "Salario liquido de " << v2.getNome() << ": R$ " << v2.calcularSalario() << endl;

    return 0;
}
