#include <iostream>
#include <string>
using namespace std;

class Carro {
  private:
    int VelInst; // Velocidade instantânea (int variable)
          
  public:
    Carro() { //Construtor
        VelInst = 0;
    }

    void acelerar(int valor) { //método para acelar o carro com o parâmetro
        VelInst += valor;
    }

    void printVelocidade() {
        cout << "Velocidade Instantânea: " << VelInst << " km/h\n";
    }

    // Atributos String do Carro
    string Time;         // time (string variable)
    string Piloto;       // piloto (string variable)
    string TP;           // tipo de pneu (string variable)
    string SP;           // saúde do pneu (string variable)
    string Cor;          // emplacamento (string variable)
};

int main() {
  Carro F1;

  F1.acelerar(10);
  F1.printVelocidade();

  F1.acelerar(20);
  F1.printVelocidade();

  F1.acelerar(40);
  F1.printVelocidade();

  F1.acelerar(80);
  F1.printVelocidade();

  // Informações String do Carro
  F1.Time = "Red Bull Racing"; // time
  F1.Piloto = "Max Verstappen"; //piloto
  F1.TP = "Macios"; // tipo de pneu
  F1.SP= "Boa"; // Saúde do pneu
  F1.Cor = "Azul"; //Cor do carro";

  // Print values
  cout << "Equipe: " << F1.Time << " F1\n";
  cout << "Piloto: " << F1.Piloto << "\n";
  cout << "Pneus: " << F1.TP << "\n";
  cout << "Saúde dos Pneus: " <<F1.SP << "\n";
  cout << "Cor: "<< F1.Cor << "\n";
  return 0;
};