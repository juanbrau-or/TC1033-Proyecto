/*
 * Proyecto Deportes
 * Juan Braulio Olivares Rodriguez
 * A01706880
 * 26/11/2023
*/

/*
 * Este proyecto permite administrar distintos equipos,
 * jugadores y entrenadores, permitiendo hacer transferencias,
 * despedir y contratar empleados
 */

// Importar las librerias a utilizar
#include <iostream>
#include <string>
#include <vector>
#include "equipo.h"
#include "empleado.h"
#include "menus.h"

/*
 * Esta funcion solo imprime las posibles operaciones que el usuario puede realizar
 * @param
 * @return
*/
void menu() {
    std::cout << std::endl;
    std::cout << "-----------------------" << std::endl;
    std::cout << "Funciones disponibles:" << std::endl << std::endl;
    std::cout << "1. Crear jugador" << std::endl;
    std::cout << "2. Crear entrenador" << std::endl;
    std::cout << "3. Crear equipo" << std::endl;
    std::cout << "4. Consultar jugador" << std::endl;
    std::cout << "5. Consultar entrenador" << std::endl;
    std::cout << "6. Consultar equipo" << std::endl;
    std::cout << "7. Modificar jugador" << std::endl;
    std::cout << "8. Modificar entrenador" << std::endl;
    std::cout << "9. Modificar equipo" << std::endl;
    std::cout << "0. Salir" << std::endl;
    std::cout << "-----------------------" << std::endl << std::endl;
}

/*
 * Lee la opcion ingresada por el usuario y llama a la funcion correspondiente
 * Regresa false si el programa debe parar
 * @param vector<Atleta>, vector<Entrenador>, vector<Equipo>
 * @return bool: si el programa
*/
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
    // Se crean vectores para almacenar los objetos creados por el usuario
    std::vector<Atleta> jugadores;
    std::vector<Entrenador> entrenadores;
    std::vector<Equipo> equipos;
    do {
        menu();
    } while( opcion(jugadores, entrenadores, equipos) );
    // Mientras el usuario no desee terminar el programa se sigue el ciclo
    return 0;
}
