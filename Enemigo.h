#include "Enemigo.h"
#include <iostream>
#include <cstdlib>

// ============================================================
//  Enemigo.cpp — IMPLEMENTACIÓN de la clase Enemigo
// ============================================================

Enemigo::Enemigo(string nombre, string _tipo, int vida, int ataque, int defensa)
    : Personaje(nombre, vida, ataque, defensa), tipo(_tipo) {
}

string Enemigo::getTipo() const { return tipo; }

// --- elegirAccion() -----------------------------------------
// IA simple: 80% atacar, 20% defender.
int Enemigo::elegirAccion() const {
    return (rand() % 10 < 8) ? 1 : 2;
}

// --- mostrarEstado() (override) -----------------------------
// Polimorfismo: versión específica para el Enemigo.
void Enemigo::mostrarEstado() const {
    cout << "[" << getNombre() << " - " << tipo
         << "]  Vida: " << getVida() << "/" << getVidaMax() << "\n";
}
