#include "Personaje.h"
#include <iostream>
#include <cstdlib>

// ============================================================
//  Personaje.cpp — IMPLEMENTACIÓN de la clase base Personaje
//  El archivo .cpp define CÓMO funciona cada método.
//  Cada método se prefija con  Personaje::  para indicar
//  que pertenece a esta clase.
// ============================================================

// Constructor: inicializa todas las propiedades
Personaje::Personaje(string _nombre, int _vida, int _ataque, int _defensa)
    : nombre(_nombre), vida(_vida), vidaMax(_vida),
      ataque(_ataque), defensa(_defensa) {
}

Personaje::~Personaje() {}

// --- Getters (métodos de consulta) --------------------------
string Personaje::getNombre()  const { return nombre; }
int    Personaje::getVida()    const { return vida; }
int    Personaje::getVidaMax() const { return vidaMax; }
int    Personaje::getAtaque()  const { return ataque; }
int    Personaje::getDefensa() const { return defensa; }

// --- estaVivo() ---------------------------------------------
bool Personaje::estaVivo() const {
    return vida > 0;
}

// --- recibirDanio() -----------------------------------------
// Aplica el daño descontando la defensa (mínimo 1).
void Personaje::recibirDanio(int danio) {
    int danioReal = danio - defensa;
    if (danioReal < 1) danioReal = 1;
    vida -= danioReal;
    if (vida < 0) vida = 0;
}

// --- curar() ------------------------------------------------
void Personaje::curar(int cantidad) {
    vida += cantidad;
    if (vida > vidaMax) vida = vidaMax;
}

// --- calcularDanio() ----------------------------------------
// Daño base con variación aleatoria del ±20%.
int Personaje::calcularDanio() const {
    int variacion = ataque / 5;
    return ataque + (rand() % (variacion * 2 + 1)) - variacion;
}

// --- mostrarEstado() ----------------------------------------
void Personaje::mostrarEstado() const {
    cout << "[" << nombre << "]  Vida: " << vida << "/" << vidaMax << "\n";
}
