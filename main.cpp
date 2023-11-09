#include <iostream>
#include "atleta.h"
#include "equipo.h"
#include "deporte.h"

int main() {
    Atleta giannelli;

    giannelli.set_nombre("Simone Giannelli");
    giannelli.set_peso(89);
    giannelli.set_estatura(2);

    std::cout << "Nombre jugador: " << giannelli.get_nombre() << std::endl;
    std::cout << "Peso: " << giannelli.get_peso() << std::endl;
    std::cout << "Estatura: " << giannelli.get_estatura() << std::endl;

    std::cout << std::endl;

    Equipo modena;
    modena.set_nombre("Modena Volley");
    modena.set_numJugadores(12);

    std::cout << "Nombre equipo: " << modena.get_nombre() << std::endl;
    std::cout << "No. de jugadores: " << modena.get_numJugadores() << std::endl;
    std::cout << std::endl;

    Deporte voleibol;
    voleibol.set_nombre("Voleibol");
    voleibol.set_espectadores(91989876888);
    voleibol.set_equipos(16);

    std::cout << "Nombre deporte: " << voleibol.get_nombre() << std::endl;
    std::cout << "No. de equipos: " << voleibol.get_numEquipos() << std::endl;
    std::cout << "No. de espectadores: " << voleibol.get_numEspectadores() << std::endl;

    return 0;
}
