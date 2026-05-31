#include "Jugador.h"
#include <iostream>

// ============================================================
//  Jugador.cpp — IMPLEMENTACIÓN de la clase Jugador
// ============================================================

Jugador::Jugador(string nombre, int vida, int ataque, int defensa, int _pociones)
    : Personaje(nombre, vida, ataque, defensa),
      pociones(_pociones), defendiendo(false) {
}

int  Jugador::getPociones()              const { return pociones; }
bool Jugador::estaDefendiendo()          const { return defendiendo; }
void Jugador::setDefendiendo(bool valor)       { defendiendo = valor; }

// --- usarPocion() -------------------------------------------
// Restaura 40 HP si hay pociones disponibles.
bool Jugador::usarPocion() {
    if (pociones <= 0) {
        cout << "  ¡No tienes pociones!\n";
        return false;
    }
    int curacion = 40;
    curar(curacion);   // llama al metodo heredado de Personaje
    pociones--;
    cout << "  Usaste una pocion: +" << curacion
         << " vida.  Pociones restantes: " << pociones << "\n";
    return true;
}

// --- mostrarEstado() (override) -----------------------------
// Polimorfismo: versión específica para el Jugador.
void Jugador::mostrarEstado() const {
    cout << "[" << getNombre() << "]  Vida: "
         << getVida() << "/" << getVidaMax()
         << "  |  Pociones: " << pociones << "\n";
}
