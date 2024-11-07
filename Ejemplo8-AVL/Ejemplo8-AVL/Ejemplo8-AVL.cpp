#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <conio.h> 
using namespace std;

// Definición del nodo del árbol AVL
struct Nodo {
    int valor;
    int altura;
    Nodo* izquierda;
    Nodo* derecha;

    Nodo(int v) : valor(v), altura(1), izquierda(nullptr), derecha(nullptr) {}
};

// Clase para el Árbol AVL
class ArbolAVL {
public:
    Nodo* raiz;

    ArbolAVL() : raiz(nullptr) {}

    // Función para insertar un nuevo valor en el árbol
    void insertar(int valor) {
        raiz = insertarRecursivo(raiz, valor);
    }

    // Función para eliminar un valor del árbol
    void eliminar(int valor) {
        raiz = eliminarRecursivo(raiz, valor);
    }

    // Función para imprimir el árbol
    void imprimirArbol() {
        imprimirArbolEstructurado(raiz, 0);
    }

    // Función para buscar un valor en el árbol AVL
    bool buscar(int valor) {
        return buscarRecursivo(raiz, valor);
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
    // Obtener la altura de un nodo
    int altura(Nodo* nodo) {
        return nodo ? nodo->altura : 0;
    }

    // Obtener el factor de balance de un nodo
    int obtenerBalance(Nodo* nodo) {
        return nodo ? altura(nodo->izquierda) - altura(nodo->derecha) : 0;
    }

    // Rotación simple a la derecha
    Nodo* rotacionDerecha(Nodo* y) {
        cout << "Realizando rotacion derecha en el nodo con valor " << y->valor << endl;

        Nodo* x = y->izquierda;
        Nodo* T2 = x->derecha;

        // Realizar rotación
        x->derecha = y;
        y->izquierda = T2;

        // Actualizar alturas
        y->altura = 1 + max(altura(y->izquierda), altura(y->derecha));
        x->altura = 1 + max(altura(x->izquierda), altura(x->derecha));

        return x;
    }

    // Rotación simple a la izquierda
    Nodo* rotacionIzquierda(Nodo* x) {
        cout << "Realizando rotacion izquierda en el nodo con valor " << x->valor << endl;

        Nodo* y = x->derecha;
        Nodo* T2 = y->izquierda;

        // Realizar rotación
        y->izquierda = x;
        x->derecha = T2;

        // Actualizar alturas
        x->altura = 1 + max(altura(x->izquierda), altura(x->derecha));
        y->altura = 1 + max(altura(y->izquierda), altura(y->derecha));

        return y;
    }

    // Rotación doble izquierda-derecha
    Nodo* rotacionIzquierdaDerecha(Nodo* nodo) {
        cout << "Realizando rotacion izquierda-derecha en el nodo con valor " << nodo->valor << endl;
        nodo->izquierda = rotacionIzquierda(nodo->izquierda);
        return rotacionDerecha(nodo);
    }

    // Rotación doble derecha-izquierda
    Nodo* rotacionDerechaIzquierda(Nodo* nodo) {
        cout << "Realizando rotacion derecha-izquierda en el nodo con valor " << nodo->valor << endl;
        nodo->derecha = rotacionDerecha(nodo->derecha);
        return rotacionIzquierda(nodo);
    }

    // Función recursiva para insertar un nodo en el árbol
    Nodo* insertarRecursivo(Nodo* nodo, int valor) {
        // Inserción estándar de un árbol binario de búsqueda
        if (!nodo) return new Nodo(valor);

        if (valor < nodo->valor) {
            nodo->izquierda = insertarRecursivo(nodo->izquierda, valor);
        }
        else if (valor > nodo->valor) {
            nodo->derecha = insertarRecursivo(nodo->derecha, valor);
        }
        else {
            // No se permiten valores duplicados en el árbol AVL
            cout << "El valor " << valor << " ya existe en el arbol" << endl;
            return nodo;
        }

        // Actualizar la altura del nodo actual
        nodo->altura = 1 + max(altura(nodo->izquierda), altura(nodo->derecha));

        // Balancear el árbol AVL
        return balancear(nodo, valor);
    }

    // Función para balancear un nodo
    Nodo* balancear(Nodo* nodo, int valor) {
        int balance = obtenerBalance(nodo);

        // Caso izquierda-izquierda
        if (balance > 1 && valor < nodo->izquierda->valor) {
            return rotacionDerecha(nodo);
        }

        // Caso derecha-derecha
        if (balance < -1 && valor > nodo->derecha->valor) {
            return rotacionIzquierda(nodo);
        }

        // Caso izquierda-derecha
        if (balance > 1 && valor > nodo->izquierda->valor) {
            return rotacionIzquierdaDerecha(nodo);
        }

        // Caso derecha-izquierda
        if (balance < -1 && valor < nodo->derecha->valor) {
            return rotacionDerechaIzquierda(nodo);
        }

        return nodo;
    }

    // Función recursiva para eliminar un nodo del árbol
    Nodo* eliminarRecursivo(Nodo* nodo, int valor) {
        if (!nodo) return nodo;

        if (valor < nodo->valor) {
            nodo->izquierda = eliminarRecursivo(nodo->izquierda, valor);
        }
        else if (valor > nodo->valor) {
            nodo->derecha = eliminarRecursivo(nodo->derecha, valor);
        }
        else {
            // Nodo encontrado para eliminación
            if (!nodo->izquierda || !nodo->derecha) {
                Nodo* temp = nodo->izquierda ? nodo->izquierda : nodo->derecha;
                delete nodo;
                nodo = temp;
            }
            else {
                Nodo* temp = encontrarMin(nodo->derecha);
                nodo->valor = temp->valor;
                nodo->derecha = eliminarRecursivo(nodo->derecha, temp->valor);
            }
        }

        if (!nodo) return nodo;

        // Actualizar la altura del nodo actual
        nodo->altura = 1 + max(altura(nodo->izquierda), altura(nodo->derecha));

        // Balancear el árbol AVL
        return balancear(nodo, valor);
    }

    // Función para encontrar el valor mínimo en un subárbol
    Nodo* encontrarMin(Nodo* nodo) {
        while (nodo->izquierda) nodo = nodo->izquierda;
        return nodo;
    }

    // Función recursiva para buscar un valor en el árbol
    bool buscarRecursivo(Nodo* nodo, int valor) {
        if (nodo == nullptr) {
            return false; // Valor no encontrado
        }

        if (nodo->valor == valor) {
            return true; // Valor encontrado
        }

        // Recorrer el subárbol izquierdo o derecho según el valor
        if (valor < nodo->valor) {
            return buscarRecursivo(nodo->izquierda, valor);
        }
        else {
            return buscarRecursivo(nodo->derecha, valor);
        }
    }

    // Función recursiva para imprimir el árbol en una estructura jerárquica
    void imprimirArbolEstructurado(Nodo* nodo, int espacio) {
        if (!nodo) return;

        espacio += 10;
        imprimirArbolEstructurado(nodo->derecha, espacio);
        cout << endl << setw(espacio) << nodo->valor << endl;
        imprimirArbolEstructurado(nodo->izquierda, espacio);
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
    std::cout << "\n\t\tArbol AVL\n";
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
    ArbolAVL arbol;

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