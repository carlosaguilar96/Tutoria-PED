#include <iostream>
#include <cstdlib>
#include <conio.h> 

class ListaDoble {
private:
    // Clase para representar un nodo en la lista
    struct Nodo {
        int num;
        Nodo* next;
        Nodo* prev;

        Nodo(int num) : num(num), next(nullptr), prev(nullptr) {}
    };

    Nodo* primero;
    Nodo* ultimo;

public:
    ListaDoble() : primero(nullptr), ultimo(nullptr) {}

    ~ListaDoble() {
        Nodo* actual = primero;
        while (actual != nullptr) {
            Nodo* siguiente = actual->next;
            delete actual;
            actual = siguiente;
        }
    }

    // Método para agregar un nuevo nodo al final de la lista
    void addLast(int dato) {
        Nodo* newNodo = new Nodo(dato);
        if (primero == nullptr) {
            primero = ultimo = newNodo;
        }
        else {
            ultimo->next = newNodo;
            newNodo->prev = ultimo;
            ultimo = newNodo;
        }
    }

    // Método para agregar un nuevo nodo al inicio de la lista
    void addFirst(int dato) {
        Nodo* newNodo = new Nodo(dato);
        if (primero == nullptr) {
            primero = ultimo = newNodo;
        }
        else {
            newNodo->next = primero;
            primero->prev = newNodo;
            primero = newNodo;
        }
    }

    // Método para eliminar el primer nodo con un valor específico
    bool remove(int dato) {
        Nodo* actual = primero;

        while (actual != nullptr) {
            if (actual->num == dato) {
                if (actual->prev != nullptr) {
                    actual->prev->next = actual->next;
                }
                else {
                    primero = actual->next;
                }

                if (actual->next != nullptr) {
                    actual->next->prev = actual->prev;
                }
                else {
                    ultimo = actual->prev;
                }

                delete actual;
                return true;
            }

            actual = actual->next;
        }

        return false;
    }

    // Método para imprimir los elementos de la lista desde el principio hasta el final
    void printForward() const {
        Nodo* actual = primero;
        while (actual != nullptr) {
            std::cout << "\t" << actual->num << "\t| ";
            actual = actual->next;
        }
        std::cout << std::endl;
    }

    // Método para imprimir los elementos de la lista desde el final hasta el principio
    void printBackward() const {
        Nodo* actual = ultimo;
        while (actual != nullptr) {
            std::cout << "\t" << actual->num << "\t| ";
            actual = actual->prev;
        }
        std::cout << std::endl;
    }

    //Método para encontrar longitud de la lista
    int size() {
        int longitud=0;
        if (primero == nullptr) {
            longitud = 0;
        }
        else {
            Nodo* actual = primero;
            while (actual != nullptr) {
                longitud++;
                actual = actual->next;
            }
        }
        return longitud;
    }

    //Método para agregar un nodo en medio
    void agregarEnMedio(int dato) {
        Nodo* newNodo = new Nodo(dato);
        int posicionMedio;
        if (primero == nullptr) {
            primero = ultimo = newNodo;
        }
        else {
            posicionMedio = this->size() / 2;
            if (this->size() % 2 != 0) {
                int valor;
                std::cout << "\n>Digitar 1 si antes del medio o 2 si despues del medio: ";
                std::cin >> valor;
                if (valor == 2) {
                    posicionMedio += 1;
                }
            }
            Nodo* actual = primero;
            for (int i = 1; i <= posicionMedio; i++) {
                if (i == posicionMedio) {
                    newNodo->next = actual->next;
                    actual->next->prev = newNodo;
                    actual->next = newNodo;
                    newNodo->prev = actual;
                }
                else actual = actual->next;
            }
        }
    }
};
static char menu()
{
    std::cout << "\n\t\tLista Menu\n";
    std::cout << "a.- Insertar al frente\n";
    std::cout << "b.- Insertar al final\n";
    std::cout << "c.- Eliminar un elemento\n";
    std::cout << "d.- Mostrar lista de primero a ultimo\n";
    std::cout << "e.- Mostrar lista de ultimo a primero\n";
    std::cout << "f.- Insertar al medio\n";
    std::cout << "g.- Salir\n";
    std::cout << "> Ingresa tu opcion: ";
    char valor;
    std::cin >> valor;
    return valor;
}

static int leern()
{
    int valor;
    std::cout << "\n>Digite valor a ingresar: ";
    std::cin >> valor;
    return valor;
}


int main() {
    ListaDoble milista;

    char opcion;
    bool continuar = true;

    do
    {
        system("cls");
        opcion = menu();
        switch (opcion)
        {
        case 'a':
            milista.addFirst(leern());
            std::cout << "Dato ingresado\n";
            std::cout << "Presiona cualquier tecla para continuar..." << std::endl;
            _getch();
            break;
        case 'b':
            milista.addLast(leern());
            std::cout << "Dato ingresado\n";
            std::cout << "Presiona cualquier tecla para continuar..." << std::endl;
            _getch();
            break;
        case 'c':
            if (milista.remove(leern())) {
                std::cout << "Dato eliminado\n";
                std::cout << "Presiona cualquier tecla para continuar..." << std::endl;
                _getch();
            }
            break;
        case 'd':
            milista.printForward();
            std::cout << "Presiona cualquier tecla para continuar..." << std::endl;
            _getch();
            break;
        case 'e':
            milista.printBackward();
            std::cout << "Presiona cualquier tecla para continuar..." << std::endl;
            _getch();
            break;
        case 'g':
            continuar = false;
            break;
        case 'f':
            milista.agregarEnMedio(leern());
            std::cout << "Dato ingresado\n";
            std::cout << "Presiona cualquier tecla para continuar..." << std::endl;
            _getch();
            break;
        default:
            std::cout<< "Error, opción no válida";
            std::cout << "Presiona cualquier tecla para continuar..." << std::endl;
            _getch();
            break;
        }
    } while (continuar == true);
    std::cout<< "El programa ha finalizado.";
    return 0;
}
