using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LRUG
{
    class Program
    {
        static void Main(string[] args)
        {

            int[,] array = new int[8, 8];
for (int i = 0; i < 8; i++)
{
    for (int j = 0; j < 8; j++)
    {
        array[i, j] = 0;
    }
}
 Console.WriteLine("Escriba 8 digitos binarios");

  string ingrese = Console.ReadLine();

  int tam = ingrese.Length;

  int[] estado = new int[tam];

  for (int a = 0; a < ingrese.Length; a++)

    {

  if (ingrese[a] == '1')

   estado[a] = 1;

  else if (ingrese[a] == '0')

   estado[a] = 0;

    }

 Console.Write(Environment.NewLine);

  for (int x = 0; x < 8; x++)

    {

  for (int z = 6; z > 0; z--)

    array[x, z] = array[x, z - 1];


    array[x, 0] = estado[x];

  for (int wu = 0; wu < 8; wu++)

 Console.Write("{0}", array[x, wu]);

 Console.Write(Environment.NewLine);
 
          }

  Console.WriteLine("Oprima ENTER para salir");
 Console.ReadLine();
        }

       }

      }
// En cada uno de los programas creados tuve apoyo de mis compañeros, resalto este hecho para que no haya confuciones, esto con la finalidad de no perjudicar a nadie//