#include <string>

const int MAX = 100;

class Equipo {
    private:
        std::string nombre;
        int total_jugadores;
    public:
        Equipo();
        Equipo(std::string nombre_ini, int jugadores_iniciales);
        std::string get_nombre();
        int get_numJugadores();
        void set_nombre(std::string new_nombre);
        void set_numJugadores(int new_jugadores);
};

Equipo::Equipo() {
    nombre = "";
    total_jugadores = 0;
}

Equipo::Equipo(std::string nombre_ini, int jugadores_iniciales) {
    nombre = nombre_ini;
    total_jugadores = jugadores_iniciales;
}

std::string Equipo::get_nombre() {
    return nombre;
}

int Equipo::get_numJugadores() {
    return total_jugadores;
}

void Equipo::set_nombre(std::string new_nombre) {
    nombre = new_nombre;
}

void Equipo::set_numJugadores(int new_jugadores) {
    total_jugadores = new_jugadores;
}
