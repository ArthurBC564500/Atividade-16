#include <iostream>
#include <string>
using namespace std;

struct Data {
    int dia;
    int mes;
    int ano;
};

struct Carro {
    string modelo;
    string marca;
    int anoFabricacao;
    float preco;
    Data dataVenda;
};

void carroMaisCaro(Carro carros[], int tamanho) {
    if (tamanho == 0) return;

    int indiceMaisCaro = 0;
    for (int i = 1; i < tamanho; i++) {
        if (carros[i].preco > carros[indiceMaisCaro].preco) {
            indiceMaisCaro = i;
        }
    }

    cout << "Carro mais caro:" << endl;
    cout << "Preco: R$ " << carros[indiceMaisCaro].preco << endl;
    cout << "Data de venda: "
         << carros[indiceMaisCaro].dataVenda.dia << "/"
         << carros[indiceMaisCaro].dataVenda.mes << "/"
         << carros[indiceMaisCaro].dataVenda.ano << endl;
}

int main() {
    Carro carros[3];

    carros[0] = {"Civic", "Honda", 2020, 95000.0, {10, 5, 2024}};
    carros[1] = {"Corolla", "Toyota", 2021, 98000.0, {22, 6, 2024}};
    carros[2] = {"Onix", "Chevrolet", 2022, 75000.0, {15, 4, 2024}};

    carroMaisCaro(carros, 3);

    return 0;
}
