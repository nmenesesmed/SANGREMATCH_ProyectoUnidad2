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

// Función para agregar una persona (receptor o donante) al arreglo de personas
void agregar_persona(Persona personas[], int& num_personas, const int max_personas, const string& tipo_persona) {
    if (num_personas < max_personas) { // Verifica si aún hay espacio en el arreglo
        cout << "Ingresa el nombre del " << tipo_persona << ": "; // Solicita el nombre
        getline(cin, personas[num_personas].nombre); // Lee el nombre completo de la persona
        cout << "Ingresa el tipo de sangre del " << tipo_persona << " (A+ , A-, O+, O-, B+, B-, AB+, AB-) : "; // Solicita el tipo de sangre
        getline(cin, personas[num_personas].tipo_sangre); // Lee el tipo de sangre
        num_personas++; // Incrementa el contador de personas
    } else {
        cout << "No se pueden agregar mas " << tipo_persona << "s, base de datos llena.\n"; // Mensaje si la base de datos está llena
    }
}