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

// Función para verificar la compatibilidad de donantes con receptores
void verificar_compatibilidad(const Persona receptores[], int num_receptores, const Persona donantes[], int num_donantes) {
    for (int i = 0; i < num_receptores; i++) { // Recorre todos los receptores
        cout << "----------------------------------------\n"; // Línea divisoria para claridad
        cout << "Receptor: " << receptores[i].nombre << " (" << receptores[i].tipo_sangre << ")\n"; // Muestra el receptor
        cout << "Donantes compatibles:\n"; // Inicia la lista de donantes compatibles
        bool found = false; // Variable para verificar si se encontró al menos un donante compatible
        for (int j = 0; j < num_donantes; j++) { // Recorre todos los donantes
            if (es_compatible(receptores[i].tipo_sangre, donantes[j].tipo_sangre)) { // Verifica la compatibilidad
                cout << "  - " << donantes[j].nombre << " (" << donantes[j].tipo_sangre << ")\n"; // Muestra el donante compatible
                found = true; // Marca que se encontró al menos un donante compatible
            }
        }
        if (!found) { // Si no se encontró ningún donante compatible
            cout << "  No hay donantes compatibles.\n"; // Mensaje indicando que no hay donantes compatibles
        }
    }
    cout << "----------------------------------------\n"; // Línea divisoria para claridad
}

// Función para mostrar el menú de opciones
void mostrar_menu() {
    cout << "\n----------------------------------------\n"; // Línea divisoria para claridad
    cout << "Menu:\n"; // Título del menú
    cout << "1. Agregar receptor\n"; // Opción para agregar un receptor
    cout << "2. Agregar donante\n"; // Opción para agregar un donante
    cout << "3. Verificar compatibilidad\n"; // Opción para verificar compatibilidad
    cout << "4. Salir\n"; // Opción para salir del programa
    cout << "----------------------------------------\n"; // Línea divisoria para claridad
    cout << "Elige una opcion: "; // Solicita al usuario que elija una opción
}