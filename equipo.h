/*
 * Proyecto Deportes
 * Juan Braulio Olivares Rodriguez
 * A01706880
 * 26/11/2023
*/

/*
 * Clase Equipo contiene métodos que pueden modificar
 * a las clases entrenador y jugador, no tiene clases hijas
 * permite almacenar los datos de varios jugadores y de un entrenador
 */

#ifndef EQUIPO_H_
#define Equipo_H_

// Importar librerias
#include <iostream>
#include <set>
#include <string>
#include "empleado.h"

class Equipo {
private:
    // Declaracion de variables privadas
    std::string nombre;
    int campeonatos;
    std::set<Atleta> jugadores;
    Entrenador entrenador;
    Entrenador* pEntrenador;
public:
    // Declaracion de los metodos
    Equipo():nombre(""),campeonatos(0),entrenador(Entrenador()),pEntrenador(NULL){};
    Equipo(std::string name, int champs):nombre(name),campeonatos(champs),entrenador(Entrenador()),pEntrenador(NULL){};
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
    void despideEntrenador();
    std::string toString();
};

/*
 * Constructor que recibe nombre, campeonatos y entrenador
 *
 * @param string name: nombre del equipo, int champs: numero de campeonatos
 * Entrenador trainer: entrenador del equipo
 * @return Objeto Equipo
*/
Equipo::Equipo(std::string name, int champs, Entrenador& trainer) {
    nombre = name;
    campeonatos = champs;
    entrenador = trainer;
    trainer.cambiaEquipo(getNombre());
    pEntrenador = &trainer;
}


/*
 * getter nombre
 * @param
 * @return string nombre del equipo
*/
std::string Equipo::getNombre() {
    return nombre;
}

/*
 * getter campeonatos
 * @param
 * @return int numero de campeonatos
*/
int Equipo::getCampeonatos() {
    return campeonatos;
}

/*
 * getter jugadores
 * @param
 * @return set de Atleta con los jugadores del equipo
*/
std::set<Atleta> Equipo::getJugadores() {
    return jugadores;
}

/*
 * getter entrenador
 * @param
 * @return Objeto Entrenador del equipo
*/
Entrenador Equipo::getEntrenador() {
    return entrenador;
}

/*
 * Metodo que imprime la lista de jugadores
 *
 * @param
 * @return
*/
void Equipo::imprimeJugadores() {
    std::cout << "Lista de jugadores: " << std::endl;
    int cnt = 1;
    for( Atleta jug:jugadores ) {
        std::cout << cnt << ". " << jug.getNombre() << std::endl;
        cnt++;
    }
    std::cout << std::endl;
}

/*
 * setter nombre
 * @param string nombre
 * @return
*/
void Equipo::setNombre(std::string name) {
    nombre = name;
}

/*
 * aumenta en uno el numero de campeonatos del equipo
 * @param
 * @return
*/
void Equipo::aumentaCampeonatos() {
    campeonatos++;
}

/*
 * setter campeonatos
 * @param int campeonatos
 * @return
*/
void Equipo::setCampeonatos(int champs) {
    campeonatos = champs;
}

/*
 * contrata a un atleta y cambia su atributo de equipo
 * @param Atleta jugador
 * @return
*/
void Equipo::contrataAtleta(Atleta& jugador) {
    jugadores.insert(jugador);
    jugador.cambiaEquipo(getNombre());
}

/*
 * vende a un atleta y cambia su atributo de equipo
 * @param Atleta jugador
 * @return
*/
void Equipo::vendeAtleta(Atleta& jugador) {
    jugadores.erase(jugador);
    jugador.cambiaEquipo("Sin equipo");
}

/*
 * contrata a un entrenador, cambia su atributo de equipo
 * guarda un puntero a la memoria del entrenador
 * @param Entrenador
 * @return
*/
void Equipo::contrataEntrenador(Entrenador& trainer) {
    if( pEntrenador != NULL )
        despideEntrenador();
    entrenador = trainer;
    trainer.cambiaEquipo(getNombre());
    pEntrenador = &trainer;
}

/*
 * despide entrenador, utiliza el puntero del entrenador para
 * modificar el atributo del entrenador original
 * @param
 * @return
*/
void Equipo::despideEntrenador() {
    Entrenador trainer = *pEntrenador;
    (*pEntrenador).cambiaEquipo("Sin equipo");
    entrenador = Entrenador();
    pEntrenador = NULL;
}

/*
 * regresa una string con todos los atributos pertenecientes al objeto
 * @param
 * @return string aux
*/
std::string Equipo::toString() {
    std::stringstream aux;
    aux << nombre << std::endl;
    aux << "Numero de campeonatos: " << campeonatos << std::endl;
    aux << entrenador.toString();
    aux << "Lista de jugadores: " << std::endl;
    for( Atleta jug:jugadores ) {
        aux << jug.toString();
    }
    aux << std::endl;
    return aux.str();
}

#endif // EQUIPO_H_
