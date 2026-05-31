#include "Juego.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>


Juego::Juego() : jugador(nullptr), enemigo(nullptr), turno(1) {}

Juego::~Juego() {
    delete jugador;
    delete enemigo;
}

void Juego::separador() const {
    cout << "--------------------------------------------\n";
}

void Juego::mostrarEncabezado() const {
    cout << "\n============================================\n";
    cout << "  TURNO " << turno << "\n";
    cout << "============================================\n";
    jugador->mostrarEstado();   // llama al override de Jugador
    enemigo->mostrarEstado();   // llama al override de Enemigo
    separador();
}


int Juego::pedirOpcion() const {
    int opcion = 0;
    cout << "\n  ¿Que haras?\n";
    cout << "  1 Atacar\n";
    cout << "  2 Usar Pocion (" << jugador->getPociones() << " restantes)\n";
    cout << "  3 Defender  (reduce el dano recibido a la mitad)\n";
    cout << "  > ";
    while (!(cin >> opcion) || opcion < 1 || opcion > 3) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "  Opcion invalida. Elige 1, 2 o 3: ";
    }
    return opcion;
}

void Juego::turnoJugador(int opcion) {
    jugador->setDefendiendo(false);

    switch (opcion) {
    case 1: {
        int danio = jugador->calcularDanio();
        cout << "\n  " << jugador->getNombre() << " ataca a "
             << enemigo->getNombre() << " por " << danio << " de dano.\n";
        enemigo->recibirDanio(danio);
        break;
    }
    case 2:
        jugador->usarPocion();
        break;
    case 3:
        jugador->setDefendiendo(true);
        cout << "\n  " << jugador->getNombre()
             << " adopta postura defensiva.\n";
        break;
    }
}

// --- turnoEnemigo() -----------------------------------------
void Juego::turnoEnemigo() {
    if (!enemigo->estaVivo()) return;

    int accion = enemigo->elegirAccion();
    cout << "\n  --- Turno del " << enemigo->getNombre() << " ---\n";

    if (accion == 1) {
        int danio = enemigo->calcularDanio();
        if (jugador->estaDefendiendo()) {
            danio /= 2;
            cout << "  ¡Bloqueaste parte del ataque! Daño reducido a "
                 << danio << ".\n";
        } else {
            cout << "  " << enemigo->getNombre()
                 << " ataca por " << danio << " de daño.\n";
        }
        jugador->recibirDanio(danio);
    } else {
        cout << "  " << enemigo->getNombre()
             << " se prepara para el próximo ataque.\n";
    }
}

// --- inicializar() ------------------------------------------
// Crea los objetos con  new  (memoria dinámica).
void Juego::inicializar() {
    srand(static_cast<unsigned int>(time(nullptr)));

    cout << "============================================\n";
    cout << "   *** JUEGO RPG POR TURNOS - POO C++ ***  \n";
    cout << "============================================\n\n";
    cout << "Ingresa el nombre de tu heroe: ";

    string nombre;
    getline(cin, nombre);
    if (nombre.empty()) nombre = "Heroe";
    // Instanciación: se crean los OBJETOS a partir de las CLASES
    jugador = new Jugador(nombre, 100, 25, 5, 3);
    enemigo = new Enemigo("Orco Grim", "Orco", 80, 20, 3);

    cout << "\n¡Un " << enemigo->getTipo() << " salvaje aparecio!\n";
    separador();
}

// --- ejecutar() ---------------------------------------------
// Bucle principal: alterna turnos hasta que alguien muera.
void Juego::ejecutar() {
    while (jugador->estaVivo() && enemigo->estaVivo()) {
        mostrarEncabezado();
        int opcion = pedirOpcion();
        turnoJugador(opcion);
        turnoEnemigo();
        turno++;
    }
    mostrarResultado();
}

// --- mostrarResultado() -------------------------------------
void Juego::mostrarResultado() const {
    cout << "\n============================================\n";
    if (jugador->estaVivo()) {
        cout << "  *** ¡VICTORIA! ***\n";
        cout << "  " << jugador->getNombre()
             << " derroto al " << enemigo->getNombre() << "!\n";
        cout << "  Vida restante: " << jugador->getVida() << " HP\n";
    } else {
        cout << "  *** DERROTA ***\n";
        cout << "  " << jugador->getNombre()
             << " fue derrotado por " << enemigo->getNombre() << ".\n";
    }
    cout << "  Duración: " << turno - 1 << " turnos.\n";
    cout << "============================================\n";
}
