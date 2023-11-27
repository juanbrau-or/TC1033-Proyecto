#ifndef MENUS_H_
#define MENUS_H_

#include <iostream>
#include <string>
#include <vector>
#include <set>

bool isNumber(std::string &s) {
    for (char &ch : s) {
        if (std::isdigit(ch) == 0)
            return false;
    }
    return true;
}

void crear_jugador(std::vector<Atleta> &jugadores) {
    std::cout << "Seleccione la opcion segun los datos disponibles del jugador" << std::endl;
    std::cout << "1. Ningun dato disponible" << std::endl;
    std::cout << "2. Estatura y peso" << std::endl;
    std::cout << "3. Nombre, estatura y peso" << std::endl;
    std::cout << "4. Nombre, estatura, peso, equipo, campeonatos y salario" << std::endl;
    std::cout << "0. Cancelar" << std::endl << std::endl;
    std::string aux;
    bool continua = true;
    while( continua ) {
        continua = false;
        std::cout << "Ingrese el numero de operacion a realizar: ";
        fflush(stdin);
        getline(std::cin, aux);
        if( aux == "0" )
            return;
        else if( aux == "1" ) {
            jugadores.push_back(Atleta());
        }
        else if( aux == "2" ) {
            float estatura, peso;
            std::cout << "Ingrese la estatura del jugador: ";
            std::cin >> estatura;
            std::cout << "Ingrese el peso del jugador: ";
            std::cin >> peso;
            jugadores.push_back(Atleta(estatura, peso));
        }
        else if( aux == "3" ) {
            std::string nombre;
            float estatura, peso;
            std::cout << "Ingrese el nombre del jugador: ";
            fflush(stdin);
            getline(std::cin, nombre);
            std::cout << "Ingrese la estatura del jugador: ";
            std::cin >> estatura;
            std::cout << "Ingrese el peso del jugador: ";
            std::cin >> peso;
            jugadores.push_back(Atleta(nombre, estatura, peso));
        }
        else if( aux == "4" ) {
            // Atleta(float height,float weight,std::string name,std::string team,int champs,float sal);
            std::string nombre;
            std::string team;
            int campeonatos;
            float estatura, peso, salario;
            std::cout << "Ingrese el nombre del jugador: ";
            fflush(stdin);
            getline(std::cin, nombre);
            std::cout << "Ingrese la estatura del jugador: ";
            std::cin >> estatura;
            std::cout << "Ingrese el peso del jugador: ";
            std::cin >> peso;
            std::cout << "Ingrese el equipo del jugador: ";
            fflush(stdin);
            getline(std::cin, team);
            std::cout << "Ingrese la cantidad de campeonatos del jugador: ";
            std::cin >> campeonatos;
            std::cout << "Ingrese el salario del jugador: ";
            std::cin >> salario;
            jugadores.push_back(Atleta(estatura, peso, nombre, team, campeonatos, salario));
        }
        else {
            std::cout << "Comando invalido, intente de nuevo" << std::endl;
            continua = true;
        }
    }
    return;
}

void crear_entrenador(std::vector<Entrenador> &entrenadores) {
    std::cout << "Seleccione la opcion segun los datos disponibles del jugador" << std::endl;
    std::cout << "1. Ningun dato disponible" << std::endl;
    std::cout << "2. Nombre" << std::endl;
    std::cout << "3. Nombre, equipo, numero de campeonatos y salario" << std::endl;
    std::cout << "0. Cancelar" << std::endl << std::endl;
    std::string aux;
    bool continua = true;
    while( continua ) {
        continua = false;
        std::cout << "Ingrese el numero de operacion a realizar: ";
        fflush(stdin);
        getline(std::cin, aux);
        if( aux == "0" )
            return;
        else if( aux == "1" ) {
            entrenadores.push_back(Entrenador());
        }
        else if( aux == "2" ) {
            std::string nombre;
            std::cout << "Ingrese el nombre del entrenador: ";
            fflush(stdin);
            getline(std::cin, nombre);
            entrenadores.push_back(Entrenador(nombre));
        }
        else if( aux == "3" ) {
            //Entrenador(float inVic,std::string name,std::string team,int champs,float sal);
            float indiceVictorias, salario;
            std::string nombre, team;
            int campeonatos;
            std::cout << "Ingrese el nombre del entrenador: ";
            fflush(stdin);
            getline(std::cin, nombre);
            std::cout << "Ingrese el equipo del entrenador: ";
            fflush(stdin);
            getline(std::cin, team);
            std::cout << "Ingrese el indice de victorias del entrenador: ";
            std::cin >> indiceVictorias;
            std::cout << "Ingrese la cantidad de campeonatos del entrenador: ";
            std::cin >> campeonatos;
            std::cout << "Ingrese el salario del entrenador: ";
            std::cin >> salario;
            entrenadores.push_back(Entrenador(indiceVictorias, nombre, team, campeonatos, salario));
        }
        else {
            std::cout << "Comando invalido, intente de nuevo" << std::endl;
            continua = true;
        }
    }
    return;
}

void crear_equipo(std::vector<Equipo> &equipos) {
    std::cout << "Seleccione la opcion segun los datos disponibles del jugador" << std::endl;
    std::cout << "1. Ningun dato disponible" << std::endl;
    std::cout << "2. Nombre y cantidad de campeonatos" << std::endl;
    std::cout << "0. Cancelar" << std::endl << std::endl;
    std::string aux;
    bool continua = true;
    while( continua ) {
        continua = false;
        std::cout << "Ingrese el numero de operacion a realizar: ";
        fflush(stdin);
        getline(std::cin, aux);
        if( aux == "0" )
            return;
        else if( aux == "1" ) {
            equipos.push_back(Equipo());
        }
        else if( aux == "2" ) {
            std::string nombre;
            int campeonatos;
            std::cout << "Ingrese el nombre del equipo: ";
            fflush(stdin);
            getline(std::cin, nombre);
            std::cout << "Ingrese el numero de campeonatos del equipo: ";
            std::cin >> campeonatos;
            equipos.push_back(Equipo(nombre, campeonatos));
        }
        else {
            std::cout << "Comando invalido, intente de nuevo" << std::endl;
            continua = true;
        }
    }
    return;
}

void consultar_jugador(std::vector<Atleta> &jugadores) {
    std::cout << "Lista de jugadores: " << std::endl;
    int cnt = 1;
    for( Atleta jug:jugadores ) {
        std::cout << cnt << ". " << jug.getNombre() << std::endl;
        cnt++;
    }
    std::cout << "0. Cancelar" << std::endl << std::endl;
    bool continua = true;
    std::string aux;
    int num;
    while( continua ) {
        continua = false;
        std::cout << "Ingrese el numero de jugador a consultar: ";
        fflush(stdin);
        getline(std::cin, aux);
        if( !isNumber(aux) ) {
            continua = true;
            std::cout << "Comando invalido, intente de nuevo" << std::endl;
            continue;
        }
        num = stoi(aux);
        if( num == 0 )
            return;
        if( num < 0 || num > jugadores.size() ) {
            continua = true;
            std::cout << "Comando invalido, intente de nuevo" << std::endl;
        }
        num--;
    }
    std::cout << std::endl;
    std::cout << "Los posibles atributos a consultar son:" << std::endl;
    std::cout << "1. Nombre" << std::endl;
    std::cout << "2. Estatura" << std::endl;
    std::cout << "3. Peso" << std::endl;
    std::cout << "4. Equipo" << std::endl;
    std::cout << "5. Campeonatos" << std::endl;
    std::cout << "6. Salario" << std::endl;
    std::cout << "7. Perfil completo" << std::endl;
    std::cout << "0. Cancelar" << std::endl;
    std::cout << std::endl;
    continua = true;
    while( continua ) {
        continua = false;
        std::cout << "Ingrese el numero de atributo a consultar: ";
        fflush(stdin);
        getline(std::cin, aux);
        if( aux == "0" )
            return;
        else if( aux == "1" )
            std::cout << "Nombre: " << jugadores[num].getNombre() << std::endl;
        else if( aux == "2" )
            std::cout << "Estatura: " << jugadores[num].getEstatura() << std::endl;
        else if( aux == "3" )
            std::cout << "Peso: " << jugadores[num].getPeso() << std::endl;
        else if( aux == "4" )
            std::cout << "Equipo: " << jugadores[num].getEquipo() << std::endl;
        else if( aux == "5" )
            std::cout << "Campeonatos: " << jugadores[num].getCampeonatos() << std::endl;
        else if( aux == "6" )
            std::cout << "Salario: " << jugadores[num].getSalario() << std::endl;
        else if( aux == "7" )
            std::cout << jugadores[num].toString() << std::endl;
        else {
            std::cout << "Comando invalido, intente de nuevo" << std::endl;
            continua = true;
        }
    }
    return;
}

void consultar_entrenador(std::vector<Entrenador> &entrenadores) {
    std::cout << "Lista de entrenadores: " << std::endl;
    int cnt = 1;
    for( Entrenador train:entrenadores ) {
        std::cout << cnt << ". " << train.getNombre() << std::endl;
        cnt++;
    }
    std::cout << "0. Cancelar" << std::endl << std::endl;
    bool continua = true;
    std::string aux;
    int num;
    while( continua ) {
        continua = false;
        std::cout << "Ingrese el numero de entrenador a consultar: ";
        fflush(stdin);
        getline(std::cin, aux);
        if( !isNumber(aux) ) {
            continua = true;
            std::cout << "Comando invalido, intente de nuevo" << std::endl;
            continue;
        }
        num = stoi(aux);
        if( num == 0 )
            return;
        if( num < 0 || num > entrenadores.size() ) {
            continua = true;
            std::cout << "Comando invalido, intente de nuevo" << std::endl;
        }
        num--;
    }
    std::cout << std::endl;
    std::cout << "Los posibles atributos a consultar son:" << std::endl;
    std::cout << "1. Nombre" << std::endl;
    std::cout << "2. Indice de victorias" << std::endl;
    std::cout << "3. Equipo" << std::endl;
    std::cout << "4. Campeonatos" << std::endl;
    std::cout << "5. Salario" << std::endl;
    std::cout << "6. Perfil completo" << std::endl;
    std::cout << "0. Cancelar" << std::endl;
    std::cout << std::endl;
    continua = true;
    while( continua ) {
        continua = false;
        std::cout << "Ingrese el numero de atributo a consultar: ";
        fflush(stdin);
        getline(std::cin, aux);
        if( aux == "0" )
            return;
        else if( aux == "1" )
            std::cout << "Nombre: " << entrenadores[num].getNombre() << std::endl;
        else if( aux == "2" )
            std::cout << "Indice de victorias: " << entrenadores[num].getIndiceVictorias() << std::endl;
        else if( aux == "3" )
            std::cout << "Equipo: " << entrenadores[num].getEquipo() << std::endl;
        else if( aux == "4" )
            std::cout << "Campeonatos: " << entrenadores[num].getCampeonatos() << std::endl;
        else if( aux == "5" )
            std::cout << "Salario: " << entrenadores[num].getSalario() << std::endl;
        else if( aux == "6" )
            std::cout << entrenadores[num].toString() << std::endl;
        else {
            std::cout << "Comando invalido, intente de nuevo" << std::endl;
            continua = true;
        }
    }
    return;
}

void consultar_equipo(std::vector<Equipo> &equipos) {
    std::cout << "Lista de equipos: " << std::endl;
    int cnt = 1;
    for( Equipo team:equipos ) {
        std::cout << cnt << ". " << team.getNombre() << std::endl;
        cnt++;
    }
    std::cout << "0. Cancelar" << std::endl << std::endl;
    bool continua = true;
    std::string aux;
    int num;
    while( continua ) {
        continua = false;
        std::cout << "Ingrese el numero de equipo a consultar: ";
        fflush(stdin);
        getline(std::cin, aux);
        if( !isNumber(aux) ) {
            continua = true;
            std::cout << "Comando invalido, intente de nuevo" << std::endl;
            continue;
        }
        num = stoi(aux);
        if( num == 0 )
            return;
        if( num < 0 || num > equipos.size() ) {
            continua = true;
            std::cout << "Comando invalido, intente de nuevo" << std::endl;
        }
        num--;
    }
    std::cout << std::endl;
    std::cout << "Los posibles atributos a consultar son:" << std::endl;
    std::cout << "1. Nombre" << std::endl;
    std::cout << "2. Campeonatos" << std::endl;
    std::cout << "3. Jugadores" << std::endl;
    std::cout << "4. Entrenador" << std::endl;
    std::cout << "5. Perfil completo" << std::endl;
    std::cout << "0. Cancelar" << std::endl;
    std::cout << std::endl;
    continua = true;
    while( continua ) {
        continua = false;
        std::cout << "Ingrese el numero de atributo a consultar: ";
        fflush(stdin);
        getline(std::cin, aux);
        if( aux == "0" )
            return;
        else if( aux == "1" )
            std::cout << "Nombre: " << equipos[num].getNombre() << std::endl;
        else if( aux == "2" )
            std::cout << "Campeonatos: " << equipos[num].getCampeonatos() << std::endl;
        else if( aux == "3" )
            equipos[num].imprimeJugadores();
        else if( aux == "4" )
            std::cout << "Entrenador: " << equipos[num].getEntrenador().getNombre() << std::endl;
        else if( aux == "5" )
            std::cout << equipos[num].toString();
        else {
            std::cout << "Comando invalido, intente de nuevo" << std::endl;
            continua = true;
        }
    }
    return;
}

void modificar_jugador(std::vector<Atleta> &jugadores) {
    std::cout << "Lista de jugadores: " << std::endl;
    int cnt = 1;
    for( Atleta jug:jugadores ) {
        std::cout << cnt << ". " << jug.getNombre() << std::endl;
        cnt++;
    }
    std::cout << "0. Cancelar" << std::endl << std::endl;
    bool continua = true;
    std::string aux;
    int num;
    while( continua ) {
        continua = false;
        std::cout << "Ingrese el numero de jugador a modificar: ";
        fflush(stdin);
        getline(std::cin, aux);
        if( !isNumber(aux) ) {
            continua = true;
            std::cout << "Comando invalido, intente de nuevo" << std::endl;
            continue;
        }
        num = stoi(aux);
        if( num == 0 )
            return;
        if( num < 0 || num > jugadores.size() ) {
            continua = true;
            std::cout << "Comando invalido, intente de nuevo" << std::endl;
        }
        num--;
    }
    std::cout << std::endl;
    std::cout << "Los posibles atributos a modificar son:" << std::endl;
    std::cout << "1. Nombre" << std::endl;
    std::cout << "2. Estatura" << std::endl;
    std::cout << "3. Peso" << std::endl;
    std::cout << "4. Campeonatos" << std::endl;
    std::cout << "5. Salario" << std::endl;
    std::cout << "0. Cancelar" << std::endl;
    std::cout << std::endl;
    continua = true;
    while( continua ) {
        continua = false;
        std::cout << "Ingrese el numero de atributo a consultar: ";
        fflush(stdin);
        getline(std::cin, aux);
        if( aux == "0" )
            return;
        else if( aux == "1" ) {
            std::string nombre;
            std::cout << "Ingrese el nuevo nombre: ";
            fflush(stdin);
            getline(std::cin, nombre);
            jugadores[num].setNombre(nombre);
        }
        else if( aux == "2" ) {
            float estatura;
            std::cout << "Ingrese la nueva estatura: ";
            std::cin >> estatura;
            jugadores[num].setEstatura(estatura);
        }
        else if( aux == "3" ) {
            float peso;
            std::cout << "Ingrese el nuevo peso: ";
            std::cin >> peso;
            jugadores[num].setPeso(peso);
        }
        else if( aux == "4" ) {
            int campeonatos;
            std::cout << "Ingrese la nueva cantidad de campeonatos: ";
            std::cin >> campeonatos;
            jugadores[num].setCampeonatos(campeonatos);
        }
        else if( aux == "5" ) {
            float salario;
            std::cout << "Ingrese el nuevo salario: ";
            std::cin >> salario;
            jugadores[num].setSalario(salario);
        }
        else {
            std::cout << "Comando invalido, intente de nuevo" << std::endl;
            continua = true;
        }
    }
    return;
}

void modificar_entrenador(std::vector<Entrenador> &entrenadores) {
    std::cout << "Lista de entrenadores: " << std::endl;
    int cnt = 1;
    for( Entrenador train:entrenadores ) {
        std::cout << cnt << ". " << train.getNombre() << std::endl;
        cnt++;
    }
    std::cout << "0. Cancelar" << std::endl << std::endl;
    bool continua = true;
    std::string aux;
    int num;
    while( continua ) {
        continua = false;
        std::cout << "Ingrese el numero de entrenador a modificar: ";
        fflush(stdin);
        getline(std::cin, aux);
        if( !isNumber(aux) ) {
            continua = true;
            std::cout << "Comando invalido, intente de nuevo" << std::endl;
            continue;
        }
        num = stoi(aux);
        if( num == 0 )
            return;
        if( num < 0 || num > entrenadores.size() ) {
            continua = true;
            std::cout << "Comando invalido, intente de nuevo" << std::endl;
        }
        num--;
    }
    std::cout << std::endl;
    std::cout << "Los posibles atributos a modificar son:" << std::endl;
    std::cout << "1. Nombre" << std::endl;
    std::cout << "2. Indice de victorias" << std::endl;
    std::cout << "3. Campeonatos" << std::endl;
    std::cout << "4. Salario" << std::endl;
    std::cout << "0. Cancelar" << std::endl;
    std::cout << std::endl;
    continua = true;
    while( continua ) {
        continua = false;
        std::cout << "Ingrese el numero de atributo a modificar: ";
        fflush(stdin);
        getline(std::cin, aux);
        if( aux == "0" )
            return;
        else if( aux == "1" ) {
            std::string nombre;
            std::cout << "Ingrese el nuevo nombre: ";
            fflush(stdin);
            getline(std::cin, nombre);
            entrenadores[num].setNombre(nombre);
        }
        else if( aux == "2" ) {
            float indiceVictorias;
            std::cout << "Ingrese el nuevo indice de victorias: ";
            std::cin >> indiceVictorias;
            entrenadores[num].setIndiceVictorias(indiceVictorias);
        }
        else if( aux == "3" ) {
            int campeonatos;
            std::cout << "Ingrese el nuevo numero de campeonatos: ";
            std::cin >> campeonatos;
            entrenadores[num].setCampeonatos(campeonatos);
        }
        else if( aux == "4" ) {
            float salario;
            std::cout << "Ingrese el nuevo salario: ";
            std::cin >> salario;
            entrenadores[num].setSalario(salario);
        }
        else {
            std::cout << "Comando invalido, intente de nuevo" << std::endl;
            continua = true;
        }
    }
    return;
}

void modificar_equipo(std::vector<Equipo> &equipos, std::vector<Atleta> &jugadores, std::vector<Entrenador> &entrenadores) {
    std::cout << "Lista de equipos: " << std::endl;
    int cnt = 1;
    for( Equipo team:equipos ) {
        std::cout << cnt << ". " << team.getNombre() << std::endl;
        cnt++;
    }
    std::cout << "0. Cancelar" << std::endl << std::endl;
    bool continua = true;
    std::string aux;
    int num;
    while( continua ) {
        continua = false;
        std::cout << "Ingrese el numero de equipo a modificar: ";
        fflush(stdin);
        getline(std::cin, aux);
        if( !isNumber(aux) ) {
            continua = true;
            std::cout << "Comando invalido, intente de nuevo" << std::endl;
            continue;
        }
        num = stoi(aux);
        if( num == 0 )
            return;
        if( num < 0 || num > equipos.size() ) {
            continua = true;
            std::cout << "Comando invalido, intente de nuevo" << std::endl;
        }
        num--;
    }
    std::cout << std::endl;
    std::cout << "Las posibles acciones son:" << std::endl;
    std::cout << "1. Cambiar nombre" << std::endl;
    std::cout << "2. Cambiar campeonatos" << std::endl;
    std::cout << "3. Contratar atleta" << std::endl;
    std::cout << "4. Contratar entrenador" << std::endl;
    std::cout << "5. Vender atleta" << std::endl;
    std::cout << "6. Despedir entrenador" << std::endl;
    std::cout << "0. Cancelar" << std::endl;
    std::cout << std::endl;
    continua = true;
    while( continua ) {
        continua = false;
        std::cout << "Ingrese el numero de accion a realizar: ";
        fflush(stdin);
        getline(std::cin, aux);
        if( aux == "0" )
            return;
        else if( aux == "1" ) {
            std::string nombre;
            std::cout << "Ingrese el nuevo nombre: ";
            fflush(stdin);
            getline(std::cin, nombre);
            equipos[num].setNombre(nombre);
        }
        else if( aux == "2" ) {
            int campeonatos;
            std::cout << "Ingrese el nuevo numero de campeonatos: ";
            std::cin >> campeonatos;
            equipos[num].setCampeonatos(campeonatos);
        }
        else if( aux == "3" ) {
            std::cout << "Lista de jugadores: " << std::endl;
            cnt = 1;
            for( Atleta jug:jugadores ) {
                std::cout << cnt << ". " << jug.getNombre() << std::endl;
                cnt++;
            }
            std::cout << "0. Cancelar" << std::endl << std::endl;
            continua = true;
            int num_jugador;
            while( continua ) {
                continua = false;
                std::cout << "Ingrese el numero de jugador a contratar: ";
                fflush(stdin);
                getline(std::cin, aux);
                if( !isNumber(aux) ) {
                    continua = true;
                    std::cout << "Comando invalido, intente de nuevo" << std::endl;
                    continue;
                }
                num_jugador = stoi(aux);
                if( num_jugador == 0 )
                    return;
                if( num_jugador < 0 || num_jugador > jugadores.size() ) {
                    continua = true;
                    std::cout << "Comando invalido, intente de nuevo" << std::endl;
                }
                num_jugador--;
            }
            equipos[num].contrataAtleta(jugadores[num_jugador]);
        }
        else if( aux == "4" ) {
            std::cout << "Lista de entrenadores: " << std::endl;
            cnt = 1;
            for( Entrenador train:entrenadores ) {
                std::cout << cnt << ". " << train.getNombre() << std::endl;
                cnt++;
            }
            std::cout << "0. Cancelar" << std::endl << std::endl;
            continua = true;
            int num_entrenador;
            while( continua ) {
                continua = false;
                std::cout << "Ingrese el numero de entrenador a contratar: ";
                fflush(stdin);
                getline(std::cin, aux);
                if( !isNumber(aux) ) {
                    continua = true;
                    std::cout << "Comando invalido, intente de nuevo" << std::endl;
                    continue;
                }
                num_entrenador = stoi(aux);
                if( num_entrenador == 0 )
                    return;
                if( num_entrenador < 0 || num_entrenador > entrenadores.size() ) {
                    continua = true;
                    std::cout << "Comando invalido, intente de nuevo" << std::endl;
                }
                num_entrenador--;
            }
            equipos[num].contrataEntrenador(entrenadores[num_entrenador]);
        }
        else if( aux == "5" ) {
            std::cout << "Lista de jugadores: " << std::endl;
            cnt = 1;
            for( Atleta jug:jugadores ) {
                std::cout << cnt << ". " << jug.getNombre() << std::endl;
                cnt++;
            }
            std::cout << "0. Cancelar" << std::endl << std::endl;
            continua = true;
            int num_jugador;
            while( continua ) {
                continua = false;
                std::cout << "Ingrese el numero de jugador a vender: ";
                fflush(stdin);
                getline(std::cin, aux);
                if( !isNumber(aux) ) {
                    continua = true;
                    std::cout << "Comando invalido, intente de nuevo" << std::endl;
                    continue;
                }
                num_jugador = stoi(aux);
                if( num_jugador == 0 )
                    return;
                if( num_jugador < 0 || num_jugador > jugadores.size() ) {
                    continua = true;
                    std::cout << "Comando invalido, intente de nuevo" << std::endl;
                }
                num_jugador--;
            }
            equipos[num].vendeAtleta(jugadores[num_jugador]);
        }
        else if( aux == "6" ) {
            equipos[num].despideEntrenador();
        }
        else {
            std::cout << "Comando invalido, intente de nuevo" << std::endl;
            continua = true;
        }
    }
    return;
}

#endif // MENUS_H_
