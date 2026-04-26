#include <iostream>
using namespace std;

class SensorNivel {
private:
    float nivel;

public:
    // construtor
    SensorNivel(float n) {
        nivel = n;
    }

    // getter
    float getNivel() const {
        return nivel;
    }

    // setter controlado
    void setNivel(float n) {
        nivel = n;
    }
};

int main() {
    SensorNivel sensor(50.0);

    cout << "Nivel atual: " << sensor.getNivel() << endl;

    sensor.setNivel(75.0);

    cout << "Nivel atualizado: " << sensor.getNivel() << endl;

    return 0;
}