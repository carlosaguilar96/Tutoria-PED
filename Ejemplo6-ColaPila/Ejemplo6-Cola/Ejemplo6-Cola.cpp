#include <iostream>
#include <cstdlib>
#include <conio.h> 

struct Nodo {
    int dato;
    Nodo* siguiente;
};

class Cola {
private:
    Nodo* frente;  // Apunta al frente de la cola
    Nodo* final;   // Apunta al final de la cola

public:
    // Constructor
    Cola() {
        frente = nullptr;
        final = nullptr;
    }

    // Verificar si la cola está vacía
    bool estaVacia() {
        return (frente == nullptr);
    }

    // Insertar un elemento en la cola (enqueue)
    void insertar(int x) {
        Nodo* nuevoNodo = new Nodo();  // Crear un nuevo nodo
        nuevoNodo->dato = x;           // Asignar el dato
        nuevoNodo->siguiente = nullptr;

        if (estaVacia()) {
            frente = nuevoNodo;  // Si la cola está vacía, el frente y el final son el nuevo nodo
            final = nuevoNodo;
        }
        else {
            final->siguiente = nuevoNodo;  // Si no está vacía, agregamos el nuevo nodo al final
            final = nuevoNodo;
        }
    }

    // Eliminar un elemento de la cola (dequeue)
    void eliminar() {
        if (estaVacia()) {
            std::cout << "La cola está vacía" << std::endl;
            return;
        }

        Nodo* temp = frente;        // Guardamos el nodo a eliminar
        frente = frente->siguiente; // Movemos el frente al siguiente nodo

        if (frente == nullptr) {  // Si la cola se vació, actualizamos el final también
            final = nullptr;
        }

        delete temp;  // Liberamos la memoria del nodo eliminado
    }

    // Método para imprimir los elementos de la cola desde el principio hasta el final
    void mostrar() const {
        Nodo* actual = frente;
        while (actual != nullptr) {
            std::cout << "\t" << actual->dato << "\t| ";
            actual = actual->siguiente;
        }
        std::cout << std::endl;
    }

    // Destructor para liberar memoria al finalizar
    ~Cola() {
        while (!estaVacia()) {
            eliminar();  // Vaciamos la cola y liberamos la memoria de los nodos
        }
    }
};

class Pila {
private:
    Nodo* frente;  // Apunta al frente de la pila

public:
    // Constructor
    Pila() {
        frente = nullptr;
    }

    // Verificar si la pila está vacía
    bool estaVacia() {
        return (frente == nullptr);
    }

    // Insertar un elemento en la pila
    void insertar(int x) {
        Nodo* nuevoNodo = new Nodo();  // Crear un nuevo nodo
        nuevoNodo->dato = x;           // Asignar el dato
        nuevoNodo->siguiente = frente;
        frente = nuevoNodo;
    }

    // Eliminar un elemento de la pila
    void eliminar() {
        if (estaVacia()) {
            std::cout << "La pila está vacía" << std::endl;
            return;
        }

        Nodo* temp = frente;        // Guardamos el nodo a eliminar
        frente = frente->siguiente; // Movemos el frente al siguiente nodo
        delete temp;  // Liberamos la memoria del nodo eliminado
    }

    // Método para imprimir los elementos de la pila desde el principio hasta el final
    void mostrar() const {
        Nodo* actual = frente;
        while (actual != nullptr) {
            std::cout << "\t" << actual->dato << "\t| ";
            actual = actual->siguiente;
        }
        std::cout << std::endl;
    }

    // Destructor para liberar memoria al finalizar
    ~Pila() {
        while (!estaVacia()) {
            eliminar();  // Vaciamos la cola y liberamos la memoria de los nodos
        }
    }
};
// MENÚ
static char menu()
{
    std::cout << "\n\t\tCola Menu\n";
    std::cout << "a.- Insertar\n";
    std::cout << "b.- Eliminar\n";
    std::cout << "c.- Mostrar\n";
    std::cout << "\n\t\tPila Menu\n";
    std::cout << "d.- Insertar\n";
    std::cout << "e.- Eliminar\n";
    std::cout << "f.- Mostrar\n";
    std::cout << "g.- Salir\n";
    std::cout << "> Ingresa tu opcion: ";
    char valor;
    std::cin >> valor;
    return valor;
}

// Leer número a ingresar
static int leern()
{
    int valor;
    std::cout << "\n>Digite valor a ingresar: ";
    std::cin >> valor;
    return valor;
}

int main()
{
    Cola cola;
    Pila pila;

    char opcion;
    bool continuar = true;

    do
    {
        system("cls");
        opcion = menu();
        switch (opcion)
        {
        case 'a':
            cola.insertar(leern());
            std::cout << "Dato ingresado\n";
            std::cout << "Presiona cualquier tecla para continuar..." << std::endl;
            _getch();
            break;
        case 'b':
            cola.eliminar();
            std::cout << "Dato eliminado\n";
            std::cout << "Presiona cualquier tecla para continuar..." << std::endl;
            _getch();
            break;
        case 'c':
            cola.mostrar();
            std::cout << "Presiona cualquier tecla para continuar..." << std::endl;
            _getch();
            break;
        case 'd':
            pila.insertar(leern());
            std::cout << "Dato ingresado\n";
            std::cout << "Presiona cualquier tecla para continuar..." << std::endl;
            _getch();
            break;
        case 'e':
            pila.eliminar();
            std::cout << "Dato eliminado\n";
            std::cout << "Presiona cualquier tecla para continuar..." << std::endl;
            _getch();
            break;
        case 'f':
            pila.mostrar();
            std::cout << "Presiona cualquier tecla para continuar..." << std::endl;
            _getch();
            break;
        case 'g':
            continuar = false;
            break;
        default:
            std::cout << "Error, opción no válida";
            std::cout << "Presiona cualquier tecla para continuar..." << std::endl;
            _getch();
            break;
        }
    } while (continuar == true);
    std::cout << "El programa ha finalizado.";
    return 0;
}
