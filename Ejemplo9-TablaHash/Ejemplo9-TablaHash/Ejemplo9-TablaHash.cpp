#include <iostream>
#include <list>
#include <vector>
#include <iterator>
#include <string>
#include <cstdlib>
#include <conio.h> 
using namespace std;

// Definición tabla hash
class HashTable {
private:
    // Definición de tamaño de tabla
    int tableSize;

    // Listas enlazadas para resolver colisiones (encadenamiento)
    // Vector de listas
    //Cada ítem de la lista es un par de clave-valor de tipo int (clave) y string (valor)
    vector<list<pair<int, string>>> table;

    // Función hash simple que toma una clave y la mapea a un índice
    int hashFunction(int key) {
        return key % tableSize;
    }

public:
    // Constructor que inicializa la tabla con el tamaño dado
    HashTable(int size) {
        tableSize = size;
        table.resize(tableSize);
    }

    // Insertar un par clave-valor en la tabla
    void insert(int key, string value) {
        int index = hashFunction(key);
        table[index].push_back(make_pair(key, value)); // Insertar al final de la lista
    }

    // Buscar un valor por su clave
    string search(int key) {
        int index = hashFunction(key);
        // Buscar en la lista correspondiente
        for (auto& pair : table[index]) {
            if (pair.first == key) {
                return pair.second; // Si la clave coincide, devolver el valor
            }
        }
        return "No encontrado"; // Si no se encuentra la clave
    }

    // Eliminar una entrada por su clave
    void remove(int key) {
        int index = hashFunction(key);
        auto& list = table[index];
        for (auto it = list.begin(); it != list.end(); ++it) {
            if (it->first == key) {
                list.erase(it); // Eliminar el elemento
                return;
            }
        }
    }

    // Mostrar el contenido de la tabla hash
    void display() {
        for (int i = 0; i < tableSize; ++i) {
            if (!table[i].empty()) {
                cout << "Indice " << i << ": ";
                for (auto& pair : table[i]) {
                    cout << "[" << pair.first << ", " << pair.second << "] ";
                }
                cout << endl;
            }
        }
    }
};

// MENÚ
static char menu()
{
    std::cout << "\n\t\tTabla Hash\n";
    std::cout << "a.- Insertar\n";
    std::cout << "b.- Eliminar\n";
    std::cout << "c.- Buscar\n";
    std::cout << "d.- Mostrar Tabla\n";
    std::cout << "e.- Salir\n";
    std::cout << "> Ingresa tu opcion: ";
    char valor;
    std::cin >> valor;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return valor;
}

// Ejemplo de uso
int main() {
    HashTable ht(10); // Crear una tabla hash de tamaño 10

    char opcion;
    bool continuar = true;
    string nombre;
    int key;

    do
    {
        system("cls");
        opcion = menu();
        switch (opcion)
        {
        case 'a':
            std::cout << "Ingresa la llave: ";
            std::cin >> key;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "\nIngresa el nombre: ";
            std::getline(std::cin, nombre);
            ht.insert(key, nombre);
            std::cout << "Elemento insertado" << std::endl;
            std::cout << "Presiona cualquier tecla para continuar..." << std::endl;
            _getch();
            break;
        case 'b':
            std::cout << "Ingresa la llave: ";
            std::cin >> key;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            ht.remove(key);
            std::cout << "Elemento eliminado" << std::endl;
            std::cout << "Presiona cualquier tecla para continuar..." << std::endl;
            _getch();
            break;
        case 'c':
            std::cout << "Ingresa la llave: ";
            std::cin >> key;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Buscar clave " << key << ": " << ht.search(key) << endl;
            std::cout << "Presiona cualquier tecla para continuar..." << std::endl;
            _getch();
            break;
        case 'd':
            ht.display();
            std::cout << "\nPresiona cualquier tecla para continuar..." << std::endl;
            _getch();
            break;
        case 'e':
            continuar = false;
            break;
        default:
            std::cout << "Error, opcion no valida";
            std::cout << "Presiona cualquier tecla para continuar..." << std::endl;
            _getch();
            break;
        }
    } while (continuar == true);
    std::cout << "El programa ha finalizado.";
    return 0;
}