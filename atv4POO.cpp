#include <iostream>
#include <string>

using namespace std;

// Classe base: representa um ativo genérico de campo
class AtivoCampo {
private:
    string tag;      
    bool bloqueado;  

protected:
    string area;    
    // protected: permite que classes derivadas acessem/modifiquem a área
    void redefinirArea(string novaArea) {
        area = novaArea;
    }

public:
    AtivoCampo(string novaTag, string novaArea)
        : tag(novaTag), bloqueado(false), area(novaArea) {}

    string getTag() const {
        return tag;
    }

    bool estaBloqueado() const {
        return bloqueado;
    }

    void bloquear() {
        bloqueado = true;
    }

    void liberar() {
        bloqueado = false;
    }
};

// Classe derivada: Sensor de nível
class SensorNivel : public AtivoCampo {
private:
    double nivelAtual; // é um valor sensível, só pode ser alterado com validação
    double limiteAlto; // é parâmetro interno do sensor

public:
    // Construtor reutilizando a classe base
    SensorNivel(string tag, string area, double limite)
        : AtivoCampo(tag, area), nivelAtual(0), limiteAlto(limite) {}

    // Atualiza nível com regras
    void atualizarNivel(double novoNivel) {
        if (estaBloqueado()) return; // regra 1

        if (novoNivel < 0) return;   // regra 2

        nivelAtual = novoNivel;
    }

    // Exibe resumo do sensor
    void exibirResumo() {
        cout << "SensorNivel - Tag: " << getTag()
             << ", Area: " << area
             << ", Nivel: " << nivelAtual
             << ", Limite Alto: " << limiteAlto << endl;
    }

    // Friend: acesso direto em inspeções técnicas
    friend void inspecaoTecnica(const SensorNivel& s);
};

// Definição da friend function
void inspecaoTecnica(const SensorNivel& s) {
    cout << "[Inspecao Tecnica] Nivel Atual: " << s.nivelAtual
         << ", Limite Alto: " << s.limiteAlto << endl;
}

// Classe derivada: Bomba Dosadora
class BombaDosadora : public AtivoCampo {
private:
    double vazaoPercentual;  //deve ser controlado por regras (1 e 2)

public:
    // Construtor usando base
    BombaDosadora(string tag, string area)
        : AtivoCampo(tag, area), vazaoPercentual(0) {}

    // Ajusta vazão com validação
    void ajustarVazao(double valor) {
        if (estaBloqueado()) return; // regra 1

        if (valor < 0 || valor > 100) return; // regra 2

        vazaoPercentual = valor;
    }

    // Move a bomba para outra área
    void moverParaArea(string novaArea) {
        redefinirArea(novaArea);
    }
    // usa protected da base

    // Exibe resumo
    void exibirResumo() {
        cout << "BombaDosadora - Tag: " << getTag()
             << ", Area: " << area
             << ", Vazao: " << vazaoPercentual << "%" << endl;
    }
};

int main() {
    // Criação dos objetos
    SensorNivel sensor("Sensor1", "Tanque A", 100);
    BombaDosadora bomba("Bomba1", "Linha 1");

    // Atualizando estados
    sensor.atualizarNivel(80);
    bomba.ajustarVazao(20);

    // Teste de bloqueio
    sensor.bloquear();
    sensor.atualizarNivel(80); // não deve alterar

    // Exibindo resumo
    sensor.exibirResumo();
    bomba.exibirResumo();

    // Inspeção técnica
    inspecaoTecnica(sensor);

    return 0;
}