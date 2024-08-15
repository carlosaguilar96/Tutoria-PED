using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ejemplo1
{
    class Program
    {
        static void Main(string[] args)
        {
            lista milista = new lista();
            char opcion;
            Boolean continuar = true;

            do
            {
                Console.Clear();
                opcion = menu();
                switch (opcion)
                {
                    case 'a':
                        milista.InsertarI(leern());
                        mensaje("Dato ingresado");
                        break;
                    case 'b':
                        milista.InsertarF(leern());
                        mensaje("Dato ingresado");
                        break;
                    case 'c':
                        milista.InsertarP(leern(), leerp());
                        mensaje("Dato ingresado");
                        break;
                    case 'd':
                        mensaje(milista.EliminarI());
                        break;
                    case 'e':
                        mensaje(milista.EliminarF());
                        break;
                    case 'f':
                        milista.mostrar();
                        Console.ReadKey();
                        break;
                    case 'g':
                        continuar = false;
                        break;
                    default:
                        mensaje("Error, opción no válida");
                        break;
                }
            } while (continuar == true);
            mensaje("El programa ha finalizado.");
        }
        static char menu()
        {
            Console.WriteLine("\n\t\tLista Menú\n");
            Console.WriteLine("a.- Insertar al frente");
            Console.WriteLine("b.- Insertar al final");
            Console.WriteLine("c.- Insertar en una posición específica");
            Console.WriteLine("d.- Eliminar al frente");
            Console.WriteLine("e.- Eliminar al final");
            Console.WriteLine("f.- Mostrar lista");
            Console.WriteLine("g.- Salir");
            Console.Write("> Ingresa tu opción: ");
            try
            {
                char valor = Convert.ToChar(Console.ReadLine());
                return valor;
            }
            catch
            {
                return 'h';
            }
        }
        static int leern()
        {
            int valor;
            Console.Write("\n>Ingrese valor a ingresar: ");
            int num = Convert.ToInt32(Console.ReadLine());
            while (num > 99 || num <= 0)
            {
                mensaje("Solo números del 1 al 99");
                Console.Write("\n>Ingrese valor: ");
                num = Convert.ToInt32(Console.ReadLine());
            }
            valor = num;
            return valor;
        }
        static int leerp()
        {
            int valor;
            Console.Write("\n>Ingrese valor de la posición: ");
            valor = Convert.ToInt32(Console.ReadLine());
            return valor;
        }
        static void mensaje(String texto)
        {
            if (texto.Length > 0)
            {
                Console.WriteLine("\n==================================================");
                Console.WriteLine(" > {0}", texto);
                Console.WriteLine("==================================================");
                Console.WriteLine("\n >Presione cualquier tecla para continuar...");
                Console.ReadKey();
            }
        }
    }
}