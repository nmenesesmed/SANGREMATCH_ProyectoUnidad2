#include <iostream>     // Incluye la entrada y salida estándar
#include <string>       // Incluye el manejo de cadenas de texto
#include <iomanip>      // Incluye el manejo de formatos de entrada/salida

using namespace std;    // Evitar el uso de std:: continuamente

// Estructura para almacenar la información de una persona
struct Persona {
    string nombre;       // Nombre de la persona
    string tipo_sangre;  // Tipo de sangre de la persona
};

// Función para determinar si un donante es compatible con un receptor
bool es_compatible(const string& receptor, const string& donante) {
    // Verifica la compatibilidad basada en el tipo de sangre del receptor
    if (receptor == "A+") {
        return (donante == "O-" || donante == "O+" || donante == "A-" || donante == "A+");
    } else if (receptor == "A-") {
        return (donante == "O-" || donante == "A-");
    } else if (receptor == "O+") {
        return (donante == "O-" || donante == "O+");
    } else if (receptor == "O-") {
        return (donante == "O-");
    } else if (receptor == "B+") {
        return (donante == "O-" || donante == "O+" || donante == "B-" || donante == "B+");
    } else if (receptor == "B-") {
        return (donante == "O-" || donante == "B-");
    } else if (receptor == "AB+") {
        return (donante == "O-" || donante == "O+" || donante == "A-" || donante == "A+" || donante == "B-" || donante == "B+" || donante == "AB-" || donante == "AB+");
    } else if (receptor == "AB-") {
        return (donante == "O-" || donante == "A-" || donante == "B-" || donante == "AB-");
    }
    return false; // Si el tipo de sangre del receptor no coincide con ninguno de los casos, devuelve false
}