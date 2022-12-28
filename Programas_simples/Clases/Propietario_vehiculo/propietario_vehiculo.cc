/**
 * Práctica personal programación en C++
 * @author Jaime Sendín
 * @date Dec 13 2022
 * @file propietario_vehiculo.cc
 * @brief Programa que interactúa con el usuario y los vehículos que éste posee.
 * @style Google c++ style guide. Nombre funciones = escritura de camello. Nombre atributos = escritura de serpiente
 * @add Experiencia e ITV en años
 * @see https://www.github.com/Jaimalex
 */


#include "propietario_vehiculo.h"


// Sobrecarga del operador de extracción, función amiga

std::istream& operator>>(std::istream& in, PropietarioVehiculo& propietario_vehiculo) {
    in >> propietario_vehiculo.nombre_ >> propietario_vehiculo.edad_ >> propietario_vehiculo.DNI_ >> propietario_vehiculo.experiencia_ >> propietario_vehiculo.marca_ >> propietario_vehiculo.modelo_ >> propietario_vehiculo.ITV_ >> propietario_vehiculo.kilometraje_;
    return in;
}

// Sobrecarga del operador de inserción, función normal

std::ostream& operator<<(std::ostream& out, PropietarioVehiculo& propietario_vehiculo) {

    out << std::endl << "Datos del usuario propietario del coche: " << std::endl;
    out << std::endl << "Nombre: " << propietario_vehiculo.GetNombre() << std::endl;
    out << std::endl << "Edad: " << propietario_vehiculo.GetEdad() << std::endl;
    out << std::endl << "DNI: " << propietario_vehiculo.GetDNI() << std::endl;
    out << std::endl << "Experiencia al volante: " << propietario_vehiculo.GetExperiencia() << " años " << std::endl;
    out << std::endl << "Marca del vehículo: " << propietario_vehiculo.GetMarca() << std::endl;
    out << std::endl << "Modelo del vehículo: " << propietario_vehiculo.GetModelo() << std::endl;
    out << std::endl << "Útima ITV del vehículo: Año " << propietario_vehiculo.GetITV() << std::endl;
    out << std::endl << "Kilometraje del vehículo: " << propietario_vehiculo.GetKilometraje() << " km" <<  std::endl;
    return out;
}

// Sobrecarga del operador de comparación (==) para comprobar si es el mismo propietario, función normal
// ¿Por qué no puede ser miembro? -> bool operator==(PropietarioVehiculo& propietario_1, PropietarioVehiculo& propietario_2) PONER EN LA DEFINICIÓN DE LA CLASE

bool operator==(PropietarioVehiculo& propietario_1, PropietarioVehiculo& propietario_2) {

    return{propietario_1.GetDNI() == propietario_2.GetDNI()};
}

// Función booleana para comprobar si la última fecha ITV del vehículo permite al propietario del coche seguir circulando, función normal

const bool ComprobarItv(const PropietarioVehiculo& propietario) {
    bool permiso_ITV{true};
    int fecha_actual{2022};
    int comprobar_itv{propietario.GetITV() + 4}; // Última ITV + 4 años
    fecha_actual > comprobar_itv ? permiso_ITV = false : permiso_ITV = true;
    return permiso_ITV;
}

// Función booleana para comprobar si el DNI del propietario es correcto, función normal

const bool ComprobarDni(const PropietarioVehiculo& propietario){ // DNI = XXXXXXXX0, 9 dígitos
    std::string Dni = propietario.GetDNI();
    bool comprobar_numero{true};
    bool comprobar_letra{true};
    for(int i = 0; i < 8; ++i) {
        if (!isdigit(Dni[i])) {
            comprobar_numero = false;
        }
    }
    if (!isalpha(Dni[8])) {
        comprobar_letra = false;
    }
    if(comprobar_numero == false || comprobar_letra == false) {
        return false;
    } else {
        return true;
    }
} 

// Función void para corregir el DNI en caso de que no haya sido introducido correctamente, función amiga

void CorregirDNI(PropietarioVehiculo& propietario) {
    std::cin >> propietario.DNI_;
}

// Función void para comprobar si el propietario es conductor novel, función miembro con puntero this. this es el puntero al objeto que llama a la función

void PropietarioVehiculo::ComprobarNovel() const {
    this->experiencia_ > 1 ? std::cout << "\nNo es conductor novel.\n" : std::cout << "\nEs conductor novel.\n";
}

// Sobrecarga del operador suma para que en caso de que un mismo propietario tenga más de un vehículo, podamos sumar sus vehículos entre sí,

// teniendo en cuenta: El nombre del propietario no debería cambiar, así como su edad, su DNI, y su experiencia al volante.
// La ITV se referirá por defecto a la ITV del primer vehículo del usuario
// El kilometraje se referirá a la suma de los distintos kilometrajes de sus vehículos (en km)

PropietarioVehiculo operator+(const PropietarioVehiculo& vehiculo_1, const PropietarioVehiculo& vehiculo_2) {
    return PropietarioVehiculo{ vehiculo_1.GetNombre(), vehiculo_1.GetEdad(), vehiculo_1.GetDNI(), vehiculo_1.GetExperiencia(), 
    "1." + vehiculo_1.GetMarca() + " 2." + vehiculo_2.GetMarca(), "1." + vehiculo_1.GetModelo() + " 2." + vehiculo_2.GetModelo(), vehiculo_1.GetITV(),
    vehiculo_1.GetKilometraje() + vehiculo_2.GetKilometraje()};
}

// Función tipo PropietarioVehiculo(clase) que devuelve los datos del propietario del vehículo y del vehículo, función normal

PropietarioVehiculo CogerDatos(PropietarioVehiculo& propietario_vehiculo) {
    std::cout << std::endl << "Indique los datos del vehículo: " << std::endl;
    std::cout << "Nombre del propietario, edad del propietario, DNI del propietario, experiencia al volante del propietario," 
    << "marca del vehículo, modelo del vehículo, última ITV apta del vehículo, kilometraje del vehículo. " << std::endl;
    std::cin >> propietario_vehiculo;
    return propietario_vehiculo;
}

// Función tipo PropietarioVehiculo(clase) que devuelve los datos del segundo vehículo del propietario, función amiga

PropietarioVehiculo CogerDatosOtroVehiculo(PropietarioVehiculo& vehiculo) {
    std::cout << std::endl << "Indique los datos del segundo vehículo: " << std::endl;
    std::cout << "Marca del vehículo, modelo del vehículo, última ITV apta del vehículo, kilometraje del vehículo. " << std::endl;
    std::cin >> vehiculo.marca_ >> vehiculo.modelo_ >> vehiculo.ITV_ >> vehiculo.kilometraje_;
    return vehiculo;
}

// Función tipo void que imprime los datos del propietario del vehículo y del vehículo, función normal

void ImprimirDatos(PropietarioVehiculo& propietario_vehiculo) {
    std::cout << propietario_vehiculo;
}

// Función tipo void que imprime los datos del segundo vehículo del propietario, función amiga(podría ser normal, no es necesario que sea amiga)

void ImprimirDatosOtroVehiculo(PropietarioVehiculo& vehiculo) {
    std::cout << std::endl << "Datos del usuario propietario de los coches: " << std::endl;
    std::cout << std::endl << "Nombre: " << vehiculo.GetNombre() << std::endl;
    std::cout << std::endl << "Edad: " << vehiculo.GetEdad() << std::endl;
    std::cout << std::endl << "DNI: " << vehiculo.GetDNI() << std::endl;
    std::cout << std::endl << "Experiencia al volante: " << vehiculo.GetExperiencia() << " años " << std::endl;
    std::cout << std::endl << "Marca de los vehículos: " << vehiculo.GetMarca() << std::endl;
    std::cout << std::endl << "Modelo de los vehículos: " << vehiculo.GetModelo() << std::endl;
    std::cout << std::endl << "Útima ITV del vehículo(principal): Año " << vehiculo.GetITV() << std::endl;
    std::cout << std::endl << "Kilometraje de los dos vehículos en conjunto: " << vehiculo.GetKilometraje() << " km" <<  std::endl;
}

// Escribir

void MenuOpciones() {
    std::cout << std::endl << "MENÚ DE USUARIO " << std::endl;
    std::cout << std::endl << "Opción A - Imprimir datos del vehículo / de los vehículos " << std::endl;
    std::cout << std::endl << "Opción B - Comprobar ITV del vehículo(principal) " << std::endl;
    std::cout << std::endl << "Opción C - Comprobar experiencia al volante " << std::endl;
    std::cout << std::endl << std::endl << "Seleccione opción: (1. para salir) ";
}

// Escribir

void ElegirOpcion(PropietarioVehiculo& propietario_vehiculo_1, PropietarioVehiculo& propietario_vehiculo_2) {
    bool comprobar_DNI{true};
    while(ComprobarDni(propietario_vehiculo_1) == false) {
        std::cout << std::endl << "Su DNI no ha resultado válido. Inténtelo de nuevo. " << std::endl; 
        CorregirDNI(propietario_vehiculo_1);
    }
    char opcion{'0'};
    do {
        MenuOpciones();
        std::cin >> opcion;
        switch(opcion) {
            case 'A': 
            {
                if(propietario_vehiculo_2.GetMarca() != "Marca") {
                    PropietarioVehiculo propietario_vehiculo_3{propietario_vehiculo_1 + propietario_vehiculo_2};
                    ImprimirDatosOtroVehiculo(propietario_vehiculo_3);
                } else {
                    ImprimirDatos(propietario_vehiculo_1);
                }
                break;
            }
            case 'B':
            {
                bool comprobar_ITV{ComprobarItv(propietario_vehiculo_1)};
                if (comprobar_ITV == false) {
                    std::cout << std::endl << "No puede circular por carretera. Debe pasar la ITV de su vehículo(principal). " << std::endl;
                } else {
                    std::cout << std::endl << "Puede circular por carretera. Deberá pasar la ITV de su vehículo(principal) en " << propietario_vehiculo_1.GetITV() + 4 << "." << std::endl;
                }
                break;
            }
            case 'C':
            {
                std::cout << std::endl << "Experiencia al volante: " << propietario_vehiculo_1.GetExperiencia() << " años." << std::endl;
                propietario_vehiculo_1.ComprobarNovel();
                break;
            }
        }    
    } while(opcion != '1');
}

// Función void principal del programa
//Crea los objetos propietario_vehiculo_1 y propietario_vehiculo_2, pregunta si el usuario posee más de dos vehículos(coches)
// Coge los datos del propietario y de los vehículos que tenga
// Lleva al menú de opciones para elegir opción

void PropietarioYVehiculos() {

    PropietarioVehiculo propietario_vehiculo_1{};
    PropietarioVehiculo propietario_vehiculo_2{};
    propietario_vehiculo_1 = CogerDatos(propietario_vehiculo_1);
    std::cout << "\n¿Posee un segundo vehículo además del principal? S - SI, N - NO\n";
    char segundo_vehiculo{'0'};
    std::cin >> segundo_vehiculo;
    if (segundo_vehiculo == 'S') {
        propietario_vehiculo_2 = CogerDatosOtroVehiculo(propietario_vehiculo_2);
    }
    ElegirOpcion(propietario_vehiculo_1, propietario_vehiculo_2);
}