#include <iostream>
#include <string>
#include <stdexcept>
 
using namespace std;
 
// Classe que representa um sensor de nível de forma simples
class SensorNivel {
private:
    string nome;
    double minimo;
    double maximo;
    double valorAtual;
 
public:
    // Construtor básico: cria um sensor com valores padrão
    SensorNivel(const string& nome)
        : nome(nome), minimo(0.0), maximo(100.0), valorAtual(0.0) {}
 
    // Construtor completo: permite definir tudo manualmente
    SensorNivel(const string& nome, double minimo, double maximo, double valorAtual) {
        if (minimo >= maximo)
            throw invalid_argument("Erro: valor mínimo deve ser menor que o máximo.");
        if (valorAtual < minimo || valorAtual > maximo)
            throw invalid_argument("Erro: valor atual fora do intervalo permitido.");
 
        this->nome = nome;
        this->minimo = minimo;
        this->maximo = maximo;
        this->valorAtual = valorAtual;
    }
 
    // Mostra as informações do sensor
    void exibirResumo() const {
        cout << "Sensor: " << nome
             << " | faixa: " << minimo << " a " << maximo
             << " | valor atual: " << valorAtual << "\n";
    }
};
 
 
// Classe que representa uma bomba simples
class Bomba {
private:
    string nome;
    double velocidade; // de 0 a 100
 
public:
    // Construtor básico: começa desligada
    Bomba(const string& nome)
        : nome(nome), velocidade(0.0) {}
 
    // Construtor completo: já define a velocidade inicial
    Bomba(const string& nome, double velocidade) {
        if (velocidade < 0.0 || velocidade > 100.0)
            throw invalid_argument("Erro: velocidade deve ser entre 0 e 100.");
 
        this->nome = nome;
        this->velocidade = velocidade;
    }
 
    // Mostra as informações da bomba
    void exibirResumo() const {
        cout << "Bomba: " << nome
             << " | velocidade: " << velocidade << " %\n";
    }
};
 
 
// Classe que representa um controlador simples de tanque
class ControladorTanque {
private:
    string nome;
    double setpoint; // valor desejado
    double kp;       // ajuste do controle
 
public:
    // Construtor básico com valores padrão
    ControladorTanque(const string& nome)
        : nome(nome), setpoint(50.0), kp(1.0) {}
 
    // Construtor completo
    ControladorTanque(const string& nome, double setpoint, double kp) {
        if (kp <= 0.0)
            throw invalid_argument("Erro: o valor de kp deve ser positivo.");
 
        this->nome = nome;
        this->setpoint = setpoint;
        this->kp = kp;
    }
 
    // Mostra as informações do controlador
    void exibirResumo() const {
        cout << "Controlador: " << nome
             << " | alvo: " << setpoint << " %"
             << " | kp: " << kp << "\n";
    }
};
 
 
int main() {
    cout << "=== Sistema Simples ===\n\n";
 
    // Sensor criado com padrão
    SensorNivel sn1("Sensor1");
 
    // Sensor com valores definidos
    SensorNivel sn2("Sensor2", 0.0, 5000.0, 2780.0);
 
    sn1.exibirResumo();
    sn2.exibirResumo();
    cout << "\n";
 
    // Bomba desligada
    Bomba b1("Bomba1");
 
    // Bomba já funcionando
    Bomba b2("Bomba2", 72.5);
 
    b1.exibirResumo();
    b2.exibirResumo();
    cout << "\n";
 
    // Controlador padrão
    ControladorTanque c1("Controlador1");
 
    // Controlador ajustado
    ControladorTanque c2("Controlador2", 80.0, 2.4);
 
    c1.exibirResumo();
    c2.exibirResumo();
    cout << "\n";

 
    return 0;
}