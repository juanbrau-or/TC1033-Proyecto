#ifndef EMPLEADO_H_
#define EMPLEADO_H_

#include <iostream>
#include <string>

class Empleado {
protected:
    std::string nombre, equipo;
    float salario;
    int campeonatos;
public:
    Empleado():nombre(""),equipo("Sin equipo"),salario(0),campeonatos(0){};
    Empleado(std::string name,std::string team,int champs,float sal);
    std::string getNombre();
    float getSalario();
    std::string getEquipo();
    int getCampeonatos();
    void setNombre(std::string);
    void setSalario(float);
    void cambiaEquipo(std::string);
    void setCampeonatos(int);
    void aumentaCampeonatos();
    bool operator <(const Empleado& st) const{ //sort using nombre,
      return (this->nombre < st.nombre);
   }
};

Empleado::Empleado(std::string name, std::string team, int champs, float sal) {
    nombre = name;
    equipo = team;
    campeonatos = champs;
    salario = sal;
}

std::string Empleado::getNombre() {
    return nombre;
}

float Empleado::getSalario() {
    return salario;
}

std::string Empleado::getEquipo() {
    return equipo;
}

int Empleado::getCampeonatos() {
    return campeonatos;
}

void Empleado::setNombre(std::string name) {
    nombre = name;
}

void Empleado::setSalario(float sal) {
    salario = sal;
}

void Empleado::cambiaEquipo(std::string team) {
    equipo = team;
}

void Empleado::setCampeonatos(int champs) {
    campeonatos = champs;
}

void Empleado::aumentaCampeonatos() {
    campeonatos++;
}

class Atleta: public Empleado {
private:
    float estatura, peso;
public:
    Atleta():Empleado(),estatura(0),peso(0){};
    Atleta(std::string name, float height, float weight);
    Atleta(float height, float weight):Empleado(),estatura(height),peso(weight){};
    Atleta(float height,float weight,std::string name,std::string team,int champs,float sal);
    float getEstatura();
    float getPeso();
    void setEstatura(float);
    void setPeso(float);
    void imprimeDatos();
};

Atleta::Atleta(std::string name, float height, float weight) {
    nombre = name;
    estatura = height;
    peso = weight;
}

Atleta::Atleta(float height, float weight, std::string name, std::string team, int champs, float sal) {
    nombre = name;
    equipo = team;
    campeonatos = champs;
    salario = sal;
    estatura = height;
    peso = weight;
}

float Atleta::getEstatura() {
    return estatura;
}

float Atleta::getPeso() {
    return peso;
}

void Atleta::setEstatura(float height) {
    estatura = height;
}

void Atleta::setPeso(float weight) {
    peso = weight;
}

void Atleta::imprimeDatos() {
    std::cout << "Datos atleta" << std::endl;
    std::cout << "Nombre: " << getNombre() << std::endl;
    std::cout << "Estatura: " << getEstatura() << std::endl;
    std::cout << "Peso: " << getPeso() << std::endl;
    std::cout << "Equipo: " << getEquipo() << std::endl;
    std::cout << "Campeonatos: " << getCampeonatos() << std::endl;
    std::cout << "Salario: " << getSalario() << std::endl;
    std::cout << std::endl;
}

class Entrenador: public Empleado {
private:
    float indiceVictorias;
public:
    Entrenador():Empleado(),indiceVictorias(0){};
    Entrenador(float inVic):Empleado(),indiceVictorias(inVic){};
    Entrenador(float inVic,std::string name,std::string team,int champs,float sal);
    float getIndiceVictorias();
    void setIndiceVictorias(float);
    void imprimeDatos();
};

Entrenador::Entrenador(float inVic, std::string name, std::string team, int champs, float sal) {
    indiceVictorias = inVic;
    nombre = name;
    equipo = team;
    campeonatos = champs;
    salario = sal;
}

float Entrenador::getIndiceVictorias() {
    return indiceVictorias;
}

void Entrenador::setIndiceVictorias(float inVic) {
    indiceVictorias = inVic;
}

void Entrenador::imprimeDatos() {
    std::cout << "Datos entrenador" << std::endl;
    std::cout << "Nombre: " << getNombre() << std::endl;
    std::cout << "Indice de victorias: " << getIndiceVictorias() << std::endl;
    std::cout << "Equipo: " << getEquipo() << std::endl;
    std::cout << "Campeonatos: " << getCampeonatos() << std::endl;
    std::cout << "Salario: " << getSalario() << std::endl;
    std::cout << std::endl;
}

#endif // EMPLEADO_H_
