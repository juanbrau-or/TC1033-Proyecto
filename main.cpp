#include <iostream>
#include "equipo.h"
#include "empleado.h"

int main() {
    Equipo borregos("Borregos", 5);
    Atleta braulio("Braulio",1.70, 63);
    Atleta victor(1.8,66,"Victor","Sin equipo",0,0);
    Entrenador alejandro(.65,"Alejandro","Sin equipo",2,5500);

    borregos.contrataAtleta(braulio);
    borregos.contrataAtleta(victor);
    borregos.contrataEntrenador(alejandro);

    std::cout << borregos.toString();

    std::cout << alejandro.toString();
    borregos.despideEntrenador();
    std::cout << alejandro.toString();

    borregos.vendeAtleta(braulio);
    std::cout << braulio.toString();
    std::cout << borregos.toString();
    return 0;
}
