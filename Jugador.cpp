#pragma once
#include "Jugador.h"
#include "Enemigo.h"

// ============================================================
//  Juego.h — DECLARACIÓN de la clase Juego
//  Orquesta toda la lógica: turnos, menú y resultado.
//  Contiene PUNTEROS a objetos Jugador y Enemigo.
// ============================================================
class Juego {
private:
    Jugador* jugador;   // puntero a objeto Jugador
    Enemigo* enemigo;   // puntero a objeto Enemigo
    int      turno;

    // Métodos privados (solo usados internamente)
    void separador()           const;
    void mostrarEncabezado()   const;
    int  pedirOpcion()         const;
    void turnoJugador(int op);
    void turnoEnemigo();

public:
    Juego();
    ~Juego();   // destructor: libera la memoria con delete

    void inicializar();
    void ejecutar();
    void mostrarResultado() const;
};
