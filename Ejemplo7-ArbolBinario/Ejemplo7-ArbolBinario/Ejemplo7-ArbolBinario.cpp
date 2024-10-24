#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <conio.h> 

using namespace std;

// Definición del nodo del árbol binario
struct Nodo {
    int valor;
    Nodo* izquierda;
    Nodo* derecha;

    Nodo(int v) : valor(v), izquierda(nullptr), derecha(nullptr) {}
};

// Clase para el Árbol Binario de Búsqueda
class ArbolBinarioBusqueda {
public:
    Nodo* raiz;

    ArbolBinarioBusqueda() : raiz(nullptr) {}

    // Función para insertar un nuevo valor en el árbol
    void insertar(int valor) {
        raiz = insertarRecursivo(raiz, valor);
    }

    // Función para imprimir el árbol
    void imprimirArbol() {
        imprimirArbolEstructurado(raiz, 0);
    }

    // Función para buscar un valor en el árbol
    bool buscar(int valor) {
        return buscarRecursivo(raiz, valor);
    }

    // Función para eliminar un valor del árbol
    void eliminar(int valor) {
        raiz = eliminarRecursivo(raiz, valor);
    }

    // Función para realizar el recorrido en orden
    void recorridoEnOrden() {
        recorridoEnOrdenRecursivo(raiz);
    }

    // Función para realizar el recorrido pre orden
    void recorridoPreOrden() {
        recorridoPreOrdenRecursivo(raiz);
    }

    // Función para realizar el recorrido post orden
    void recorridoPostOrden() {
        recorridoPostOrdenRecursivo(raiz);
    }

private:
    // Función recursiva para insertar un nodo en el árbol
    Nodo* insertarRecursivo(Nodo* nodo, int valor) {
        if (nodo == nullptr) {
            std::cout << "Dato ingresado\n";
            return new Nodo(valor); // Crear un nuevo nodo si llegamos a un lugar vacío
        }

        // Insertar el valor a la izquierda o derecha según sea menor o mayor
        if (valor < nodo->valor) {
            nodo->izquierda = insertarRecursivo(nodo->izquierda, valor);
        }
        else if (valor > nodo->valor) {
            nodo->derecha = insertarRecursivo(nodo->derecha, valor);
        } else {
            // Si el valor ya existe en el árbol
            cout << "El valor " << valor << " ya existe en el arbol" << endl;
            return nodo;
        }

        return nodo;
    }

    // Función recursiva para imprimir el árbol en una estructura jerárquica
    void imprimirArbolEstructurado(Nodo* nodo, int espacio) {
        if (nodo == nullptr) return;

        // Incrementar la cantidad de espacio entre niveles
        espacio += 10;

        // Primero procesar el subárbol derecho
        imprimirArbolEstructurado(nodo->derecha, espacio);

        // Imprimir el nodo actual después del espacio adecuado
        cout << endl;
        cout << setw(espacio) << nodo->valor << endl;

        // Luego procesar el subárbol izquierdo
        imprimirArbolEstructurado(nodo->izquierda, espacio);
    }

    // Función recursiva para buscar un valor en el árbol
    bool buscarRecursivo(Nodo* nodo, int valor) {
        if (nodo == nullptr) {
            return false; // No se encontró el valor
        }

        if (nodo->valor == valor) {
            return true; // Valor encontrado
        }

        // Buscar en el subárbol izquierdo o derecho
        if (valor < nodo->valor) {
            return buscarRecursivo(nodo->izquierda, valor);
        }
        else {
            return buscarRecursivo(nodo->derecha, valor);
        }
    }

    // Función recursiva para eliminar un nodo del árbol
    Nodo* eliminarRecursivo(Nodo* nodo, int valor) {
        if (nodo == nullptr) {
            cout << "El valor " << valor << " no existe en el arbol" << endl;
            return nodo;
        }

        // Encontrar el nodo a eliminar
        if (valor < nodo->valor) {
            nodo->izquierda = eliminarRecursivo(nodo->izquierda, valor);
        }
        else if (valor > nodo->valor) {
            nodo->derecha = eliminarRecursivo(nodo->derecha, valor);
        }
        else {
            // Nodo encontrado

            // Caso 1: Nodo sin hijos (hoja)
            if (nodo->izquierda == nullptr && nodo->derecha == nullptr) {
                delete nodo;
                std::cout << "Dato eliminado\n";
                return nullptr;
            }

            // Caso 2: Nodo con un hijo (derecho o izquierdo)
            if (nodo->izquierda == nullptr) {
                Nodo* temp = nodo->derecha;
                delete nodo;
                std::cout << "Dato eliminado\n";
                return temp;
            }
            else if (nodo->derecha == nullptr) {
                Nodo* temp = nodo->izquierda;
                delete nodo;
                std::cout << "Dato eliminado\n";
                return temp;
            }

            // Caso 3: Nodo con dos hijos
            Nodo* sucesor = encontrarMin(nodo->derecha);
            nodo->valor = sucesor->valor; // Reemplazar el valor del nodo por el del sucesor
            nodo->derecha = eliminarRecursivo(nodo->derecha, sucesor->valor); // Eliminar el sucesor
        }

        return nodo;
    }

    // Función para encontrar el valor mínimo en un subárbol (sucesor inorden)
    Nodo* encontrarMin(Nodo* nodo) {
        while (nodo->izquierda != nullptr) {
            nodo = nodo->izquierda;
        }
        return nodo;
    }

    // Función recursiva para el recorrido en orden
    void recorridoEnOrdenRecursivo(Nodo* nodo) {
        if (nodo == nullptr) return;

        // Recorrer el subárbol izquierdo, luego el nodo, y después el subárbol derecho
        recorridoEnOrdenRecursivo(nodo->izquierda);
        cout << nodo->valor << " ";
        recorridoEnOrdenRecursivo(nodo->derecha);
    }

    // Función recursiva para el recorrido pre orden
    void recorridoPreOrdenRecursivo(Nodo* nodo) {
        if (nodo == nullptr) return;

        // Recorrer el nodo, luego el subárbol izquierdo, y después el subárbol derecho
        cout << nodo->valor << " "; 
        recorridoPreOrdenRecursivo(nodo->izquierda);
        recorridoPreOrdenRecursivo(nodo->derecha);
    }

    // Función recursiva para el recorrido post orden
    void recorridoPostOrdenRecursivo(Nodo* nodo) {
        if (nodo == nullptr) return;

        // Recorrer el subárbol izquierdo, luego el subárbol derecho, y después el nodo
        recorridoPostOrdenRecursivo(nodo->izquierda);
        recorridoPostOrdenRecursivo(nodo->derecha);
        cout << nodo->valor << " ";
    }
};

// MENÚ
static char menu()
{
    std::cout << "\n\t\tArbol Binario de Busqueda\n";
    std::cout << "a.- Insertar\n";
    std::cout << "b.- Eliminar\n";
    std::cout << "c.- Buscar\n";
    std::cout << "d.- Mostrar Arbol\n";
    std::cout << "e.- Recorrido Pre Orden\n";
    std::cout << "f.- Recorrido En Orden\n";
    std::cout << "g.- Recorrido Post Orden\n";
    std::cout << "h.- Salir\n";
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

// Leer número a buscar
static int leerb()
{
    int valor;
    std::cout << "\n>Digite valor a buscar: ";
    std::cin >> valor;
    return valor;
}

// Leer número a eliminar
static int leere()
{
    int valor;
    std::cout << "\n>Digite valor a eliminar: ";
    std::cin >> valor;
    return valor;
}

// Función principal
int main() {
    ArbolBinarioBusqueda arbol;

    char opcion;
    bool continuar = true;

    do
    {
        system("cls");
        opcion = menu();
        switch (opcion)
        {
        case 'a':
            arbol.insertar(leern());
            std::cout << "Presiona cualquier tecla para continuar..." << std::endl;
            _getch();
            break;
        case 'b':
            arbol.eliminar(leere());
            std::cout << "Presiona cualquier tecla para continuar..." << std::endl;
            _getch();
            break;
        case 'c':
            cout << (arbol.buscar(leerb()) ? "Encontrado" : "No encontrado") << endl;
            std::cout << "Presiona cualquier tecla para continuar..." << std::endl;
            _getch();
            break;
        case 'd':
            arbol.imprimirArbol();
            std::cout << "\nPresiona cualquier tecla para continuar..." << std::endl;
            _getch();
            break;
        case 'e':
            arbol.imprimirArbol();
            std::cout << "\nRecorrido Pre-Orden: ";
            arbol.recorridoPreOrden();
            std::cout << "\nPresiona cualquier tecla para continuar..." << std::endl;
            _getch();
            break;
        case 'f':
            arbol.imprimirArbol();
            std::cout << "\nRecorrido En Orden: ";
            arbol.recorridoEnOrden();
            std::cout << "\nPresiona cualquier tecla para continuar..." << std::endl;
            _getch();
            break;
        case 'g':
            arbol.imprimirArbol();
            std::cout << "\nRecorrido Post-Orden: ";
            arbol.recorridoPostOrden();
            std::cout << "\nPresiona cualquier tecla para continuar..." << std::endl;
            _getch();
            break;
        case 'h':
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