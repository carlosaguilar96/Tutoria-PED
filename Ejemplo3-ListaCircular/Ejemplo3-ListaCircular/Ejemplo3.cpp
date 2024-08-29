#include <iostream>
#include <cstdlib>
#include <conio.h> 

struct Nodo {
    int dato;
    Nodo* next;
};

class ListaCircular {
private:
    Nodo* last;

public:
    ListaCircular() : last(nullptr) {}

    // Función para comprobar si la lista está vacía
    bool isEmpty() {
        return last == nullptr;
    }

    // Función para insertar un nodo al final de la lista
    void insert(int dato) {
        Nodo* newNodo = new Nodo();
        newNodo->dato = dato;

        if (isEmpty()) {
            last = newNodo;
            last->next = last;
        }
        else {
            newNodo->next = last->next; //primer nodo
            last->next = newNodo; //último nodo deja de ser último nodo
            last = newNodo; //nuevo nodo es último nodo
        }
    }

    // Función para eliminar un nodo específico
    void deleteNodo(int dato) {
        if (isEmpty()) {
            std::cout << "La lista esta vacia.\n";
            return;
        }

        // Si la lista tiene un solo nodo
        if (last->next == last && last->dato == dato) {
            delete last;
            last = nullptr;
            std::cout << "Dato eliminado\n";
            return;
        }

        Nodo* actual = last->next; //apuntado al primer nodo
        Nodo* anterior = last;

        do {
            if (actual->dato == dato) {
                //Si el dato a eliminar se encuentra en el último nodo
                if (actual == last) {
                    last = anterior;
                }
                anterior->next = actual->next;
                delete actual;
                std::cout << "Dato eliminado\n";
                return;
            }
            anterior = actual;
            actual = actual->next;
        } while (actual != last->next);

        std::cout << "Dato no encontrado.\n";
    }

    // Función para mostrar la lista
    void print() {
        if (isEmpty()) {
            std::cout << "La lista esta vacia.\n";
            return;
        }

        Nodo* actual = last->next;
        std::cout << "\n";
        do {
            std::cout << "\t" << actual->dato << "\t| ";
            actual = actual->next;
        } while (actual != last->next);
        std::cout << "\n" << std::endl;
    }
};

static char menu()
{
    std::cout << "\n\t\tLista Menu\n";
    std::cout << "a.- Insertar\n";
    std::cout << "b.- Eliminar un elemento\n";
    std::cout << "c.- Mostrar lista\n";
    std::cout << "d.- Salir\n";
    std::cout << "> Ingresa tu opcion: ";
    char valor;
    std::cin >> valor;
    return valor;
}

static int leern()
{
    int valor;
    std::cout << "\n>Ingrese un valor: ";
    std::cin >> valor;
    return valor;
}

int main() {
    ListaCircular milista;
    char opcion;
    bool continuar = true;

    do
    {
        system("cls");
        opcion = menu();
        switch (opcion)
        {
        case 'a':
            milista.insert(leern());
            std::cout << "Dato ingresado\n";
            std::cout << "Presiona cualquier tecla para continuar..." << std::endl;
            _getch();
            break;
        case 'b':
            milista.deleteNodo(leern());
            std::cout << "Presiona cualquier tecla para continuar..." << std::endl;
            _getch();
            break;
        case 'c':
            milista.print();
            std::cout << "Presiona cualquier tecla para continuar..." << std::endl;
            _getch();
            break;
        case 'd':
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
