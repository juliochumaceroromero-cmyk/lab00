#pragma once
#include "Personaje.h"

// ============================================================
//  Jugador.h — DECLARACIÓN de la clase Jugador
//  Hereda de Personaje con:  class Jugador : public Personaje
//  Agrega pociones y la acción de defender.
// ============================================================
class Jugador : public Personaje {
private:
    int  pociones;
    bool defendiendo;

public:
    Jugador(string nombre, int vida, int ataque, int defensa, int pociones);

    int  getPociones()              const;
    bool estaDefendiendo()          const;
    void setDefendiendo(bool valor);

    bool usarPocion();

    // override: redefine el método virtual de Personaje
    void mostrarEstado() const override;
};
