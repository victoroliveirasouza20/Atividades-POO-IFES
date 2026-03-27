#include <iostream>
#include <string>
#include <vector>

using namespace std;

//CLASSE BASE
class AtuadorLinha {
private:
    string tag;
    string area;

protected:
    // A função deixa o percentual sempre entre 0% e 100%
    double limitarPercentual(double percentual) const {
        if (percentual < 0.0) return 0.0;
        if (percentual > 100.0) return 100.0;
        return percentual;
    }

public:
    // Construtor base
    AtuadorLinha(string novaTag, string novaArea)
        : tag(novaTag), area(novaArea) {}
    // Destutor virtual
    virtual ~AtuadorLinha() = default;
    //getters
    string getTag() const { return tag; }
    string getArea() const { return area; }

    // Virtual para permitir polimorfismo
    // cada atuador interpreta o percentual de forma diferente
    virtual void aplicarReferenciaPercentual(double percentual) = 0;
    //exibir informações
    virtual void exibirResumo() const = 0;
};

//CLASSE DERIVADA: MOTOR
class MotorEsteira : public AtuadorLinha {
private:
    double frequenciaHz; // Frequência do motor entre 0 e 60 Hz

public:
    //construtor
    MotorEsteira(string tag, string area)
        : AtuadorLinha(tag, area), frequenciaHz(0.0) {}
    //aqui o método virtual converte o percentual em frequência
    void aplicarReferenciaPercentual(double percentual) override {
        percentual = limitarPercentual(percentual);
        frequenciaHz = (percentual / 100.0) * 60.0;
    }
    //exibir
    void exibirResumo() const override {
        cout << "Motor Esteira | Tag: " << getTag()
             << " | Area: " << getArea()
             << " | Frequencia: " << frequenciaHz << " Hz" << endl;
    }
};

//ClASSE DERIVADA: VALVULA DE DOSAGEM
class ValvulaDosagem : public AtuadorLinha {
private:
    double aberturaPercentual; // Abertura em percentual (0 a 100%)

public:
    //construtor
    ValvulaDosagem(string tag, string area)
        : AtuadorLinha(tag, area), aberturaPercentual(0.0) {}
    // aqui o método virtual limita o valor de porcentagem de 0 a 100%
    void aplicarReferenciaPercentual(double percentual) override {
        aberturaPercentual = limitarPercentual(percentual);
    }
    //exibir
    void exibirResumo() const override {
        cout << "Valvula Dosagem | Tag: " << getTag()
             << " | Area: " << getArea()
             << " | Abertura: " << aberturaPercentual << " %" << endl;
    }
};

int main() {
    //objetos
    MotorEsteira motor("MTR-01", "Envase");
    ValvulaDosagem valvula("VAL-01", "Envase");
    //poliformismo
    vector<AtuadorLinha*> atuadores;

    atuadores.push_back(&motor);
    atuadores.push_back(&valvula);

    //referência percentual para todas os atuadores
    double referencia = 80.0;
    //aplica a mesma referência para todos os atuadores
    for (auto atuador : atuadores) {
        atuador->aplicarReferenciaPercentual(referencia);
    }
    //Exibe o resumo
    cout << "Resumo dos equipamentos:\n";

    for (auto atuador : atuadores) {
        atuador->exibirResumo();
    }

    return 0;
};