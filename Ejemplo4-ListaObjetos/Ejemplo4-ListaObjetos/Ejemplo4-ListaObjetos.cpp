#include <iostream>
#include <list>
#include <string>
#include <cstdlib>
#include <conio.h> 

class Estudiante {
public:
    int id;
	std::string nombre;
	char genero;
	int edad;

	Estudiante(int id, std::string nombre, char genero, int edad) :
		id(id), nombre(nombre), genero(genero), edad(edad) {}

	//Método para mostrar información de un estudiante
	void mostrar() const {
		std::cout <<"\n" << id << "." << nombre << std::endl;
		std::cout << "\tEdad: " << edad << std::endl;
		if(genero == 'f') std::cout << "\tGenero: Femenino" << std::endl;
		else std::cout << "\tGenero: Masculino" << std::endl;
		std::cout << "-----------------------------------------------" << std::endl;
	}
};

static char menu()
{
	std::cout << "\n\t\tGestion de Estudiantes\n";
	std::cout << "a.- Agregar Estudiante\n";
	std::cout << "b.- Eliminar Estudiante\n";
	std::cout << "c.- Mostrar Estudiantes\n";
	std::cout << "e.- Salir\n";
	std::cout << "> Ingresa tu opcion: ";
	char valor;
	std::cin >> valor;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return valor;
}

int main() {
	std::list<Estudiante> Estudiantes;
	char opcion;
	bool continuar = true;

    do
    {
        system("cls");
        opcion = menu();
        int id;
        std::string nombre;
        char genero;
        int edad;
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
            id = Estudiantes.size() + 1;

            Estudiantes.push_back(Estudiante(id, nombre, genero, edad));
            std::cout << "\nEstudiante Registrado\n";
            std::cout << "Presiona cualquier tecla para continuar..." << std::endl;
            _getch();
            break;
        case 'b':
            if (Estudiantes.empty()) std::cout << "\nNo hay estudiantes registrados ";
            else {
                totalE = Estudiantes.size();
                std::cout << "Ingresa el id del estudiante a eliminar: ";
                std::cin >> id;
                Estudiantes.remove_if(
                    [&id](const Estudiante& estudiante) {
                        return estudiante.id == id;
                    }
                );
                nTotalE = Estudiantes.size();
                if (totalE == nTotalE) std::cout << "No se encontro estudiante" << std::endl;
                else std::cout << "\n\nEstudiante eliminado" << std::endl;
            }
                    
            std::cout << "\nPresiona cualquier tecla para continuar..." << std::endl;
            _getch();
            break;
        case 'c':
            std::cout << "\nListado de estudiantes: ";
            if(Estudiantes.empty()) std::cout << "\nNo hay estudiantes registrados ";
            else {
                for (const auto& estudiante : Estudiantes) {
                    estudiante.mostrar();
                }
            }
            std::cout << "\n\nTotal Estudiantes: " << Estudiantes.size() << std::endl;
            std::cout << "Presiona cualquier tecla para continuar..." << std::endl;
            _getch();
            break;
        case 'e':
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