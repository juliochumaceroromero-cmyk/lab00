#pragma once
#include <string>
using namespace std;

// ============================================================
//  Personaje.h — DECLARACIÓN de la clase base Personaje
//  El archivo .h solo declara QUÉ tiene la clase
//  (sus propiedades y la firma de sus métodos).
// ============================================================
class Personaje {
private:
    string nombre;
    int    vida;
    int    vidaMax;
    int    ataque;
    int    defensa;

public:
    Personaje(string _nombre, int _vida, int _ataque, int _defensa);
    virtual ~Personaje();

    // Getters
    string getNombre()  const;
    int    getVida()    const;
    int    getVidaMax() const;
    int    getAtaque()  const;
    int    getDefensa() const;

    bool estaVivo()         const;
    void recibirDanio(int danio);
    void curar(int cantidad);
    int  calcularDanio()    const;

    // virtual: las subclases pueden redefinirlo (polimorfismo)
    virtual void mostrarEstado() const;
};
