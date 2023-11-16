#ifndef EQUIPO_H_
#define Equipo_H_

#include <iostream>
#include <set>
#include <string>
#include "empleado.h"

class Equipo {
private:
    std::string nombre;
    int campeonatos;
    std::set<Atleta> jugadores;
    Entrenador entrenador;
public:
    Equipo():nombre(""),campeonatos(0),entrenador(Entrenador()){};
    Equipo(std::string name, int champs):nombre(name),campeonatos(champs),entrenador(Entrenador()){};
    Equipo(std::string name, int champs, Entrenador& trainer);
    std::string getNombre();
    int getCampeonatos();
    std::set<Atleta> getJugadores();
    Entrenador getEntrenador();
    void imprimeJugadores();
    void setNombre(std::string);
    void aumentaCampeonatos();
    void setCampeonatos(int);
    void contrataAtleta(Atleta&);
    void vendeAtleta(Atleta&);
    void contrataEntrenador(Entrenador&);
    void despideEntrenador(Entrenador&);
};

Equipo::Equipo(std::string name, int champs, Entrenador& trainer) {
    nombre = name;
    campeonatos = champs;
    entrenador = trainer;
    trainer.cambiaEquipo(getNombre());
}

std::string Equipo::getNombre() {
    return nombre;
}

int Equipo::getCampeonatos() {
    return campeonatos;
}

std::set<Atleta> Equipo::getJugadores() {
    return jugadores;
}

Entrenador Equipo::getEntrenador() {
    return entrenador;
}

void Equipo::imprimeJugadores() {
    std::cout << "Lista de jugadores: " << std::endl;
    for( Atleta jug:jugadores ) {
        std::cout << jug.getNombre() << std::endl;
    }
    std::cout << std::endl;
}

void Equipo::setNombre(std::string name) {
    nombre = name;
}

void Equipo::aumentaCampeonatos() {
    campeonatos++;
}

void Equipo::setCampeonatos(int champs) {
    campeonatos = champs;
}

void Equipo::contrataAtleta(Atleta& jugador) {
    jugadores.insert(jugador);
    jugador.cambiaEquipo(getNombre());
}

void Equipo::vendeAtleta(Atleta& jugador) {
    jugadores.erase(jugador);
    jugador.cambiaEquipo("Sin equipo");
}

void Equipo::contrataEntrenador(Entrenador& trainer) {
    entrenador = trainer;
    trainer.cambiaEquipo(getNombre());
}

void Equipo::despideEntrenador(Entrenador& trainer) {
    trainer.cambiaEquipo("Sin equipo");
    entrenador = Entrenador();
}

#endif // EQUIPO_H_
