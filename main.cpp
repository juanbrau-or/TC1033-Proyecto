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

    borregos.imprimeJugadores();

    braulio.imprimeDatos();
    victor.imprimeDatos();

    alejandro.imprimeDatos();
    borregos.despideEntrenador(alejandro);
    alejandro.imprimeDatos();

    borregos.vendeAtleta(braulio);
    braulio.imprimeDatos();
    borregos.imprimeJugadores();
    return 0;
}
