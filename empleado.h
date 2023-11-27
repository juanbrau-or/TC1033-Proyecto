/*
 * Proyecto Deportes
 * Juan Braulio Olivares Rodriguez
 * A01706880
 * 26/11/2023
*/

/*
 * Clase Empleado contiene métodos genéricos para un empleado de un club deportivo
 * tiene dos clases hijas que son distintos tipos de empleados:
 * Atleta (jugadores) y Entrenador, cada uno tiene distintos atributos que
 * son importantes para sus estadisticas
 */

#ifndef EMPLEADO_H_
#define EMPLEADO_H_

// Importar las librerias a utilizar
#include <iostream>
#include <string>
#include <sstream>

class Empleado {
protected:
    // Variables comunes entre entrenadores y atletas
    std::string nombre, equipo;
    float salario;
    int campeonatos;
public:
    Empleado():nombre(""),equipo("Sin equipo"),salario(0),campeonatos(0){};
    Empleado(std::string name,int champs,float sal);
    std::string getNombre();
    float getSalario();
    std::string getEquipo();
    int getCampeonatos();
    void setNombre(std::string);
    void setSalario(float);
    void cambiaEquipo(std::string);
    void setCampeonatos(int);
    void aumentaCampeonatos();
    bool operator <(const Empleado& st) const{ //sort using nombre
      return (this->nombre < st.nombre);
   }
};

/*
 * Constructor que recibe nombre, campeonatos y salario inicial
 * @param string name: nombre del empleado, int champs: campeonatos ganados, float sal: salario
 * @return
*/
Empleado::Empleado(std::string name, int champs, float sal) {
    nombre = name;
    equipo = "Sin equipo";
    campeonatos = champs;
    salario = sal;
}

/*
 * getter nombre
 * @param
 * @return string: nombre del empleado
*/
std::string Empleado::getNombre() {
    return nombre;
}

/*
 * getter salario
 * @param
 * @return float: salario del empleado
*/
float Empleado::getSalario() {
    return salario;
}

/*
 * getter equipo
 * @param
 * @return string: equipo en el que trabaja
*/
std::string Empleado::getEquipo() {
    return equipo;
}

/*
 * getter campeonatos
 * @param
 * @return int: campeonatos ganados
*/
int Empleado::getCampeonatos() {
    return campeonatos;
}

/*
 * setter nombre
 * @param string: nombre del atleta o entrenador
 * @return
*/
void Empleado::setNombre(std::string name) {
    nombre = name;
}

/*
 * setter salario
 * @param float: salario del empleado
 * @return
*/
void Empleado::setSalario(float sal) {
    salario = sal;
}

/*
 * setter equipo
 * a esta funcion solo se tiene acceso desde un objeto Equipo
 * @param string: nuevo equipo en el que trabajara
 * @return
*/
void Empleado::cambiaEquipo(std::string team) {
    equipo = team;
}

/*
 * set campeonatos
 * @param int: nueva cantidad de campeonatos ganados
 * @return
*/
void Empleado::setCampeonatos(int champs) {
    campeonatos = champs;
}

/*
 * aumenta campeonatos
 * aumenta el numero de campeonatos ganados en uno
 * @param
 * @return
*/
void Empleado::aumentaCampeonatos() {
    campeonatos++;
}

/*
 * Clase atleta, hereda de empleado
 * Tiene como atributos adicionales su estatura y peso
*/
class Atleta: public Empleado {
private:
    float estatura, peso;
public:
    Atleta():Empleado(),estatura(0),peso(0){};
    Atleta(std::string name, float height, float weight);
    Atleta(float height, float weight):Empleado(),estatura(height),peso(weight){};
    Atleta(float height,float weight,std::string name,int champs,float sal);
    float getEstatura();
    float getPeso();
    void setEstatura(float);
    void setPeso(float);
    void imprimeDatos();
    std::string toString();
};

/*
 * Constructor que recibe nombre, estatura y peso
 * @param
 * @return Objeto Atleta
*/
Atleta::Atleta(std::string name, float height, float weight) {
    nombre = name;
    estatura = height;
    peso = weight;
}

/*
 * Constructor que recibe estatura, peso, nombre, campeonatos y salario
 * @param
 * @return Objeto Atleta
*/
Atleta::Atleta(float height, float weight, std::string name, int champs, float sal) {
    nombre = name;
    equipo = "Sin equipo";
    campeonatos = champs;
    salario = sal;
    estatura = height;
    peso = weight;
}

/*
 * getter estatura
 * @param
 * @return float: estatura del atleta
*/
float Atleta::getEstatura() {
    return estatura;
}

/*
 * getter peso
 * @param
 * @return float: peso del atleta
*/
float Atleta::getPeso() {
    return peso;
}

/*
 * setter estatura
 * @param float: nueva estatura del atleta
 * @return
*/
void Atleta::setEstatura(float height) {
    estatura = height;
}

/*
 * setter peso
 * @param float: nuevo peso del atleta
 * @return
*/
void Atleta::setPeso(float weight) {
    peso = weight;
}

/*
 * imprime todos los atributos del atleta
 * @param
 * @return
*/
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

/*
 * regresa una string con todos los atributos del atleta
 * @param
 * @return string
*/
std::string Atleta::toString() {
    std::stringstream aux;
    aux << "Datos atleta" << std::endl;
    aux << "Nombre: " << getNombre() << std::endl;
    aux << "Estatura: " << getEstatura() << std::endl;
    aux << "Peso: " << getPeso() << std::endl;
    aux << "Equipo: " << getEquipo() << std::endl;
    aux << "Campeonatos: " << getCampeonatos() << std::endl;
    aux << "Salario: " << getSalario() << std::endl;
    return aux.str();
}

/*
 * Clase Entrenador, hereda de Empleado
 * tiene como atributo extra el indice de victorias
*/
class Entrenador: public Empleado {
private:
    float indiceVictorias;
public:
    Entrenador():Empleado(),indiceVictorias(0){};
    Entrenador(std::string name);
    Entrenador(float inVic,std::string name,int champs,float sal);
    float getIndiceVictorias();
    void setIndiceVictorias(float);
    void imprimeDatos();
    std::string toString();
};

/*
 * Constructor que recibe el nombre del entrenador
 * @param string name: nombre del entrenador
 * @return Objeto Entrenador
*/
Entrenador::Entrenador(std::string name) {
    indiceVictorias = 0;
    nombre = name;
    equipo = "Sin equipo";
    campeonatos = 0;
    salario = 0;
}

/*
 * Constructor que recibe el indice de victorias, nombre, campeonatos y salario del entrenador
 * @param float inVic: indice de victorias, string name: nombre del entrenador
 * int champs: campeonatos ganados, float sal: salario
 * @return Objeto Entrenador
*/
Entrenador::Entrenador(float inVic, std::string name, int champs, float sal) {
    indiceVictorias = inVic;
    nombre = name;
    equipo = "Sin equipo";
    campeonatos = champs;
    salario = sal;
}

/*
 * getter indice de Victorias
 * @param
 * @return float: indice de victorias
*/
float Entrenador::getIndiceVictorias() {
    return indiceVictorias;
}

/*
 * setter indice de victorias
 * @param float inVic: nuevo indice de victorias
 * @return
*/
void Entrenador::setIndiceVictorias(float inVic) {
    indiceVictorias = inVic;
}

/*
 * Imprime los atributos del entrenador
 * @param
 * @return
*/
void Entrenador::imprimeDatos() {
    std::cout << "Datos entrenador" << std::endl;
    std::cout << "Nombre: " << getNombre() << std::endl;
    std::cout << "Indice de victorias: " << getIndiceVictorias() << std::endl;
    std::cout << "Equipo: " << getEquipo() << std::endl;
    std::cout << "Campeonatos: " << getCampeonatos() << std::endl;
    std::cout << "Salario: " << getSalario() << std::endl;
    std::cout << std::endl;
}

/*
 * Regresa una string con todos los atributos de la clase Entrenador
 * @param
 * @return string: atributos de la clase
*/
std::string Entrenador::toString() {
    std::stringstream aux;
    aux << "Datos entrenador" << std::endl;
    aux << "Nombre: " << getNombre() << std::endl;
    aux << "Indice de victorias: " << getIndiceVictorias() << std::endl;
    aux << "Equipo: " << getEquipo() << std::endl;
    aux << "Campeonatos: " << getCampeonatos() << std::endl;
    aux << "Salario: " << getSalario() << std::endl;
    return aux.str();
}

#endif // EMPLEADO_H_
