/**
 * Práctica personal programación en C++
 * @author Jaime Sendín
 * @date Dec 13 2022
 * @file propietario_vehiculo.h
 * @brief Programa que interactúa con el usuario y los vehículos que éste posee.
 * @style Google c++ style guide. Nombre funciones = escritura de camello. Nombre atributos = escritura de serpiente
 * @add Experiencia e ITV en años
 * @see https://www.github.com/Jaimalex
 */

#ifndef PROPIETARIO_VEHICULO_H
#define PROPIETARIO_VEHICULO_H

#include <iostream>
// #include <string> 

class PropietarioVehiculo{

    public:

    // Constructor para valores inicializados por el usuario y para valores por defecto en caso de no ser introducidos

    PropietarioVehiculo(std::string nombre = "Nombre", int edad = 0, std::string DNI = "XXXXXXXX0", double experiencia = 0.0, 
    std::string marca = "Marca", std::string modelo = "Modelo", int ITV = 2017, int kilometraje = 0) : 
    nombre_(nombre), edad_(edad), DNI_(DNI), experiencia_(experiencia), marca_(marca), modelo_(modelo), ITV_(ITV), kilometraje_(kilometraje) {}

    // Destructor

    ~PropietarioVehiculo() {}

    // Getters, funciones miembro

    const std::string GetNombre() const { return nombre_;}
    const int GetEdad() const { return edad_; }
    const std::string GetDNI() const { return DNI_; }
    double GetExperiencia() const { return experiencia_; }
    const std::string GetMarca() const { return marca_; }
    const std::string GetModelo() const { return modelo_; }
    int GetITV() const { return ITV_; }
    int GetKilometraje() const { return kilometraje_; }

    // Setters, funciones miembro

    void SetExperiencia(const double& experiencia) { experiencia_ = experiencia; }
    void SetITV(const int& ITV) { ITV_ = ITV; }
    void SetKilometraje(const int& kilometraje) { kilometraje_ = kilometraje; }

    // Sobrecarga del operador de extracción, función amiga

    friend std::istream& operator>>(std::istream& in, PropietarioVehiculo& propietario_vehiculo);

    // Función tipo Coche(clase) que devuelve los datos del segundo vehículo del propietario, función amiga

    friend PropietarioVehiculo CogerDatosOtroVehiculo(PropietarioVehiculo& vehiculo);

    // Función tipo void que imprime los datos del segundo vehículo del propietario, función amiga

    friend void ImprimirDatosOtroVehiculo(PropietarioVehiculo& vehiculo);

    // Función void para corregir el DNI en caso de que no haya sido introducido correctamente, función amiga

    friend void CorregirDNI(PropietarioVehiculo& propietario);

    // Función void para comprobar si el propietario es conductor novel, función miembro con puntero this. this es el puntero al objeto que llama a la función

    void ComprobarNovel() const;

    private:
    // Datos del propietario
    std::string nombre_; // NO ADMITE ESPACIOS, std::cin
    int edad_;
    std::string DNI_;
    double experiencia_;
    // Datos del vehículo
    std::string marca_;
    std::string modelo_;
    int ITV_;
    int kilometraje_;

};

#endif