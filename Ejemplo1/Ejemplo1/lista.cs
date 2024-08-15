using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ejemplo1
{
    class lista
    {
        public nodo inicio; //cabeza de la lista
        public lista() //constructor por defecto
        {
            inicio = null;
        }
        public void InsertarF(int item) //método para insertar al final de la lista
        {
            nodo auxiliar = new nodo();
            auxiliar.dato = item;
            auxiliar.siguiente = null;

            if (inicio == null) //verificar si la lista está vacía
            {
                inicio = auxiliar;
            }
            else
            {
                nodo puntero; //utilizado para recorrer la lista
                puntero = inicio;
                while (puntero.siguiente != null)
                {
                    puntero = puntero.siguiente;
                }
                puntero.siguiente = auxiliar;
            }
        }
        public void InsertarI(int item) //método para insertar al inicio de la lista
        {
            nodo auxiliar = new nodo();
            auxiliar.dato = item;
            auxiliar.siguiente = null;

            if (inicio == null) //verificar si la lista está vacía
            {
                inicio = auxiliar;
            }
            else
            {
                nodo puntero; //utilizado para almacenar la cabeza de la lista
                puntero = inicio;
                inicio = auxiliar;
                auxiliar.siguiente = puntero;
            }
        }
        public string EliminarI() //método para eliminar en la cabeza de la lista
        {
            string cadena;
            if (inicio == null) //verificar si la lista está vacía
            {
                cadena = "Lista vacía, no se puede eliminar elemento";
            }
            else
            {
                inicio = inicio.siguiente;
                cadena = "Dato eliminado";
            }
            return cadena;
        }
        public string EliminarF() //método para eliminar en al final de la lista
        {
            string cadena;
            if (inicio == null) //verificar si la lista está vacía
            {
                cadena = "Lista vacía, no se puede eliminar elemento";
            }
            else
            {
                nodo punteroant = inicio, punteropost = inicio;

                while (punteropost.siguiente != null) //recorre la lista
                {
                    punteroant = punteropost;
                    punteropost = punteropost.siguiente;
                }
                punteroant.siguiente = null;
                cadena = "Dato eliminado";
            }
            return cadena;
        }
        public void InsertarP(int item, int pos) //método para insertar en una posición específica
        {
            nodo auxiliar = new nodo();
            auxiliar.dato = item;
            auxiliar.siguiente = null;

            if (inicio == null) //verificar si la lista está vacía
            {
                Console.WriteLine("La lista está vacía, por lo tanto se va a insertar en la primera posición");
                inicio = auxiliar;
            }
            else
            {
                nodo puntero;
                puntero = inicio;
                if (pos == 1) //si la posición está en la cabeza
                {
                    inicio = auxiliar;
                    auxiliar.siguiente = puntero;
                }
                else
                {
                    for (int i = 1; i < pos - 1; i++) //recorrer la lista hasta la posición dada
                    {
                        puntero = puntero.siguiente;
                        if (puntero.siguiente == null) //si la posición es mayor que la longitud de la lista
                        {
                            Console.WriteLine("\n==================================================");
                            Console.WriteLine(" > La posición no existe, el dato se insertará al final de la cadena");
                            Console.WriteLine("==================================================");
                            break;
                        }
                    }

                    nodo punteronext;
                    punteronext = puntero.siguiente;
                    puntero.siguiente = auxiliar;
                    auxiliar.siguiente = punteronext;
                }
            }
        }
        
        public void mostrar() //método para imprimir la lista
        {
            Console.Write("\n");
            if (inicio == null)
            {
                Console.WriteLine("La lista está vacía");
            }
            else
            {
                nodo puntero;
                puntero = inicio;
                Console.WriteLine("\n");
                Console.Write("|\t{0}\t", puntero.dato);
                while (puntero.siguiente != null)
                {
                    puntero = puntero.siguiente;
                    Console.Write("|\t{0}\t", puntero.dato);
                }
            }
            Console.Write("|");
            Console.WriteLine();
        }
    }
}