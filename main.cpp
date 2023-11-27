#include <iostream>
#include <string>
#include <vector>
#include "equipo.h"
#include "empleado.h"
#include "menus.h"

void menu() {
    std::cout << std::endl;
    std::cout << "Funciones disponibles:" << std::endl;
    std::cout << "1. Crear jugador" << std::endl;
    std::cout << "2. Crear entrenador" << std::endl;
    std::cout << "3. Crear equipo" << std::endl;
    std::cout << "4. Consultar jugador" << std::endl;
    std::cout << "5. Consultar entrenador" << std::endl;
    std::cout << "6. Consultar equipo" << std::endl;
    std::cout << "7. Modificar jugador" << std::endl;
    std::cout << "8. Modificar entrenador" << std::endl;
    std::cout << "9. Modificar equipo" << std::endl;
    std::cout << "0. Salir" << std::endl << std::endl;
}

bool opcion(std::vector<Atleta> &jugadores, std::vector<Entrenador> &entrenadores, std::vector<Equipo> &equipos) {
    std::string aux;
    bool continua = true;
    while( continua ) {
        std::cout << "Ingrese el no. de funcion a relizar: ";
        fflush(stdin);
        getline(std::cin, aux);
        continua = false;
        if( aux == "0" )
            return false;
        std::cout << std::endl;
        if( aux == "1" )
            crear_jugador(jugadores);
        else if( aux == "2" )
            crear_entrenador(entrenadores);
        else if( aux == "3" )
            crear_equipo(equipos);
        else if( aux == "4" )
            consultar_jugador(jugadores);
        else if( aux == "5" )
            consultar_entrenador(entrenadores);
        else if( aux == "6" )
            consultar_equipo(equipos);
        else if( aux == "7" )
            modificar_jugador(jugadores);
        else if( aux == "8" )
            modificar_entrenador(entrenadores);
        else if( aux == "9" )
            modificar_equipo(equipos, jugadores, entrenadores);
        else {
            std::cout << "Comando invalido, intente de nuevo" << std::endl << std::endl;
            continua = true;
        }
    }
    return true;
}

int main() {
    std::vector<Atleta> jugadores;
    std::vector<Entrenador> entrenadores;
    std::vector<Equipo> equipos;
    do {
        std::cout << "-------------" << std::endl;
        menu();
    } while( opcion(jugadores, entrenadores, equipos) );
    return 0;
}
