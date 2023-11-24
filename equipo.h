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
    Entrenador* pEntrenador;
public:
    Equipo():nombre(""),campeonatos(0),entrenador(Entrenador()),pEntrenador(NULL){};
    Equipo(std::string name, int champs):nombre(name),campeonatos(champs),entrenador(Entrenador()),pEntrenador(NULL){};
    Equipo(std::string name, int champs, Entrenador& trainer);
    std::string getNombre();
    int getCampeonatos();
    std::set<Atleta> getJugadores();
    Entrenador getEntrenador();
    int getSumaSalarios();
    void imprimeJugadores();
    void setNombre(std::string);
    void aumentaCampeonatos();
    void setCampeonatos(int);
    void contrataAtleta(Atleta&);
    void vendeAtleta(Atleta&);
    void contrataEntrenador(Entrenador&);
    void despideEntrenador();
    std::string toString();
};

Equipo::Equipo(std::string name, int champs, Entrenador& trainer) {
    nombre = name;
    campeonatos = champs;
    entrenador = trainer;
    trainer.cambiaEquipo(getNombre());
    pEntrenador = &trainer;
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

int Equipo::getSumaSalarios() {
    int suma = entrenador.getSalario();
    for ( Atleta jug:jugadores ) {
        suma+=jug.getSalario();
    }
    return suma;
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
    pEntrenador = &trainer;
}

void Equipo::despideEntrenador() {
    Entrenador trainer = *pEntrenador;
    (*pEntrenador).cambiaEquipo("Sin equipo");
    entrenador = Entrenador();
}

std::string Equipo::toString() {
    std::stringstream aux;
    aux << nombre << std::endl;
    aux << entrenador.toString();
    aux << "Lista de jugadores: " << std::endl;
    for( Atleta jug:jugadores ) {
        aux << jug.toString();
    }
    aux << "-------------" << std::endl;
    return aux.str();
}

#endif // EQUIPO_H_
