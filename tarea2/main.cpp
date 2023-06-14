#include <iostream>
#include "Str.cpp"

main ()
{
    char string[50];
    int nc;

    cout << "Ingrese una cadena de no mas de 50 caracteres: ";
    gets(string);

    String cad(string);

    nc = cad.size();
    cout << "\nEl tamanho de la cadena es de " << nc << " caracteres.";

    cout << "\nLa cadena que ingreso es la siguiente:  ";
    cad.print();

    cout << "\n\nPasar una cadena estatica como argumento al constructor sobrecargado\n\n";
    char letras[] = {'a', 'b', 'c', 'd', 'x', 'y', 'z'};
    String obj(letras);
    cout << "El tamanho de la cadena es: " << obj.size() << endl;
    cout << "Elementos de la cadena: ";
    obj.print();
    cout << endl << endl;

    cout << "Constructor copia: \n";
    cout << "Cadena original"<< obj; //Operador sobrecargado <<
    String copia = obj;
    cout << "\nCadena copia\n" << copia;

    //Operador =
    char alfNum[] = {'1', 'x', '2', 'y', '3', 'z', '4'};
    String chain(alfNum);
    String cpy;
    cpy = chain;
    cout << "\n\nOperador sobrecargado \n";
    cout << "\nCadena chain" << chain;
    cout << "\nCadena cpy\n" << cpy;

    if(cpy == chain) //Operador == sobrecargado
        cout << "\nLas cadenas son iguales." << endl << endl;
    if(cpy != chain) // Operador != sobrecargado
        cout << "\nLas cadenas son diferentes." << endl << endl;

    //Operador []
    cout << "\n\nOperador sobrecargado []:\n";
    cout << "\nElemento 3 de \"cpy\": " << cpy[3];
    cpy[3] = 'c';
    cout << "\nNuevo elemento 3 de \"cpy\" insertado: x" << endl;
    cout << "\nCadena \"chain\": " << chain;
    cout << "\nNueva cadena \"cpy\": " << cpy << endl;

    if(cpy == chain)
        cout << "\nLas cadenas son iguales.\n" << endl << endl;
    if(cpy != chain)
        cout << "\nLas cadenas son diferentes.\n" << endl << endl;

    //Comprobación de excepciones
    cout << "Mostrando el indice 8 de \"cpy\"." << endl;
    try
    {
        cout << cpy[8] << endl;
    }
    catch(const char* message)
    {
        cout << "\aError: " << message << endl;
    }

    cout << endl << endl;
    return 0;
}
