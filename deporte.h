#include <string>

class Deporte {
    private:
        std::string nombre;
        long long num_espectadores;
        int num_equipos;
    public:
        Deporte();
        Deporte(std::string nombre_ini, long long num_espectadores_ini, int num_equipos_ini);
        std::string get_nombre();
        long long get_numEspectadores();
        int get_numEquipos();
        void set_nombre(std::string new_nombre);
        void set_espectadores(long long new_espectadores);
        void set_equipos(int new_numEquipos);
};

Deporte::Deporte() {
    nombre = "";
    num_espectadores = num_equipos = 0;
}

Deporte::Deporte(std::string nombre_ini, long long num_espectadores_ini, int num_equipos_ini) {
    nombre = nombre_ini;
    num_espectadores = num_espectadores_ini;
    num_equipos = num_equipos_ini;
}

std::string Deporte::get_nombre() {
    return nombre;
}

long long Deporte::get_numEspectadores() {
    return num_espectadores;
}

int Deporte::get_numEquipos() {
    return num_equipos;
}

void Deporte::set_nombre(std::string new_nombre) {
    nombre = new_nombre;
}

void Deporte::set_espectadores(long long new_espectadores) {
    num_espectadores = new_espectadores;
}

void Deporte::set_equipos(int new_numEquipos) {
    num_equipos = new_numEquipos;
}
