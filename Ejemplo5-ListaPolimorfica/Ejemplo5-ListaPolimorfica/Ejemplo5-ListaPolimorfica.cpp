#include <iostream>
#include <list>
#include <memory> // Para usar std::shared_ptr
#include <string>
#include <cstdlib>
#include <conio.h> 

//Clase base de elemento de lista
class Elemento {
public:
	virtual void imprimir() const = 0; // Método para hacer polimorfismo
    virtual ~Elemento() {} // Destructor
};

// Clase derivada de tipo Estudiante
class Estudiante : public Elemento {
public:
	int id;
	std::string nombre;
	char genero;
	int edad;

	Estudiante(int id, std::string nombre, char genero, int edad) :
		id(id), nombre(nombre), genero(genero), edad(edad) {}

	//Método para mostrar información de un estudiante
	void imprimir() const override {
		std::cout << "\n" << id << "." << nombre << std::endl;
		std::cout << "\tEdad: " << edad << std::endl;
		if (genero == 'f') std::cout << "\tGenero: Femenino" << std::endl;
		else std::cout << "\tGenero: Masculino" << std::endl;
		std::cout << "-----------------------------------------------" << std::endl;
	}
};

// Clase derivada de tipo número entero
class NumeroEntero : public Elemento {
public:
	int valor;

	NumeroEntero(int valor) : valor(valor) {}

	//Método para mostrar número entero
    void imprimir() const override {
		std::cout << "\t" << valor << "\t| ";
    }
};

static char menu()
{
	std::cout << "\n\t\tLISTA POLIMORFICA\n";
	std::cout << "a.- Agregar Estudiante\n";
	std::cout << "b.- Agregar Numero Entero\n";
	std::cout << "c.- Mostrar Estudiantes\n";
	std::cout << "d.- Mostrar Numeros Enteros\n";
	std::cout << "e.- Mostrar Lista\n";
	std::cout << "f.- Salir\n";
	std::cout << "> Ingresa tu opcion: ";
	char valor;
	std::cin >> valor;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return valor;
}

int main() {
	// Lista polimórfica usando punteros
	std::list<std::shared_ptr<Elemento>> lista;
	char opcion;
	bool continuar = true;

    do
    {
        system("cls");
        opcion = menu();
        int id;
        std::string nombre;
        char genero;
        int edad, numero;
        int totalE, nTotalE;

        switch (opcion)
        {
        case 'a':
            std::cout << "\nIngresa el nombre del estudiante: ";
            std::getline(std::cin, nombre);
            std::cout << "Ingresa la edad del estudiante: ";
            std::cin >> edad;
            std::cout << "Ingresa \"f\" si el estudiante es femenino o \"m\" si es masculino: ";
            std::cin >> genero;
            id = lista.size() + 1;

            lista.push_back(std::make_shared<Estudiante>(id, nombre, genero, edad));
            std::cout << "\nEstudiante Registrado\n";
            std::cout << "Presiona cualquier tecla para continuar..." << std::endl;
            _getch();
            break;
        case 'b':
            std::cout << "Ingresa un numero entero: ";
            std::cin >> numero;
            
            lista.push_back(std::make_shared<NumeroEntero>(numero));
            std::cout << "\nNumero Registrado\n";
            std::cout << "\nPresiona cualquier tecla para continuar..." << std::endl;
            _getch();
            break;
        case 'c':
            std::cout << "\nListado de estudiantes: ";
            if (lista.empty()) std::cout << "\nNo hay registros ";
            else {
                for (const auto& estudiante : lista) {
                    // Usamos dynamic_cast para verificar si es un Estudiante
                    if (auto est = std::dynamic_pointer_cast<Estudiante>(estudiante)) {
                        est->imprimir();  // Llamada polimórfica si es un estudiante
                    }
                }
            }
            std::cout << "Presiona cualquier tecla para continuar..." << std::endl;
            _getch();
            break;
        case 'd':
            std::cout << "\nListado de numeros enteros: ";
            if (lista.empty()) std::cout << "\nNo hay registros ";
            else {
                for (const auto& numero : lista) {
                    // Usamos dynamic_cast para verificar si es un Estudiante
                    if (auto num = std::dynamic_pointer_cast<NumeroEntero>(numero)) {
                        num->imprimir();  // Llamada polimórfica si es un estudiante
                    }
                }
            }
            std::cout << "Presiona cualquier tecla para continuar..." << std::endl;
            _getch();
            break;
        case 'e':
            std::cout << "\nListado de elementos: ";
            if (lista.empty()) std::cout << "\nNo hay registros ";
            else {
                for (const auto& elemento : lista) {
                    elemento->imprimir(); // Llamada polimórfica
                }
            }
            std::cout << "Presiona cualquier tecla para continuar..." << std::endl;
            _getch();
            break;
        case 'f':
            continuar = false;
            break;
        default:
            std::cout << "Error, opcion no valida" << std::endl;
            std::cout << "Presiona cualquier tecla para continuar..." << std::endl;
            _getch();
            break;
        }
    } while (continuar == true);
    std::cout << "El programa ha finalizado.";

	return 0;
}