#include <string>

class Atleta {
    private:
        std::string nombre;
        float estatura, peso;
    public:
        Atleta();
        Atleta(std::string nombre_ini, float estatura_ini, float peso_ini);
        std::string get_nombre();
        float get_estatura();
        float get_peso();
        void set_nombre(std::string new_nombre);
        void set_estatura(float new_estatura);
        void set_peso(float new_peso);
};

Atleta::Atleta() {
    nombre = "";
    estatura = 0;
    peso = 0;
}

Atleta::Atleta(std::string nombre_ini, float estatura_ini, float peso_ini) {
    nombre = nombre_ini;
    estatura = estatura_ini;
    peso = peso_ini;
}

std::string Atleta::get_nombre() {
    return nombre;
}

float Atleta::get_estatura() {
    return estatura;
}

float Atleta::get_peso() {
    return peso;
}

void Atleta::set_nombre(std::string new_nombre) {
    nombre = new_nombre;
}

void Atleta::set_estatura(float new_estatura) {
    estatura = new_estatura;
}

void Atleta::set_peso(float new_peso) {
    peso = new_peso;
}
