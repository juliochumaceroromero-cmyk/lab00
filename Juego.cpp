#pragma once
#include "Personaje.h"

// ============================================================
//  Enemigo.h — DECLARACIÓN de la clase Enemigo
//  También hereda de Personaje.
//  Agrega el tipo de enemigo y la IA simple.
// ============================================================
class Enemigo : public Personaje {
private:
    string tipo;   // "Goblin", "Orco", "Dragón", etc.

public:
    Enemigo(string nombre, string tipo, int vida, int ataque, int defensa);

    string getTipo() const;

    // IA: decide qué acción tomar (1=atacar, 2=defender)
    int elegirAccion() const;

    // override: versión específica para el Enemigo
    void mostrarEstado() const override;
};
