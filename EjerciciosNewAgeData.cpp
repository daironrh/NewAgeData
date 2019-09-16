// EjerciciosNewAgeData.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <stack>#include <stdio.h>
using namespace std;

int SumaSinOperador() 
{
	int x, y = 0;
	int d, suma;
	
	cout << "Suma sin operador +\n";
	cout << "Ingrese el primer #\n";
	cin >> x;
	cout << "Ingrese el segundo #\n";
	cin >> y;
	
	do
	{
		d = x & y; //ver si hay acarreo
		suma = x ^ y; //xor para sumar bit a bit
		x = d << 1; // corremos el acarreo un bit hacia la izquierda y lo guardamos en "x" para sumarlo nuevamente
		y = suma; // guardamos en "y" el resultado de la suma para continuar sumando si tenemos acarreo

	} while (d); // si tenemos acarreo continuamos la suma

	cout << "El resultado de la suma es: ";
	cout << suma << endl;  // retornamos la suma

	return 0; 
}


int DividirEntre4SinOperador() 
{
	int dividendo, cociente = 0;
	
	cout << "Suma sin operador +\n";
	cout << "Ingrese el #\n";
	cin >> dividendo;

	while (dividendo >= 4)
	{
		cociente++;
		dividendo = dividendo - 4;
	}	
	cout << "El Cociente es: " << cociente << endl;
	cout << "El resto es: " << (dividendo) << endl;

	return 0;
}

int InvertirCadena()
{
	string invertida = "";
	string cadena;

	cout << "Invertir cadena" << endl;
	cout << "Ingrese la cadena a invertir" << endl;
	cin.ignore();
	getline(cin, cadena);
	
	int pos = 0;
	for (int i = 0; i < cadena.size(); i++)
	{
		if (cadena[i] == ' ')
		{
			string subcad = cadena.substr(pos, i - pos) + ' ';
			invertida = subcad + invertida;
			pos = i + 1;
		}
		if (i == cadena.size() - 1)
		{
			invertida = cadena.substr(pos, i - pos + 1) + " " + invertida;
		}
	}
	cout << "Cadena invertida: ";
	cout << invertida + "\n";
	return 0;
	
}

int CadenaValidaParentesis()
{
	string cadena = "";
	cout << "Cadena válida de paréntesis\n";
	cout << "Longitud de la cadena válida de paréntesis más larga\n";
	cin >> cadena;

	int longitud = cadena.size();
	int maxima = 0;
	int ultimoIndice = -1;

	if (longitud == 0 || longitud == 1)
		return 0;

	stack<int> pila;

	for (int i = 0; i < longitud; i++)
	{
		if (cadena[i]=='(')
			pila.push(i);
		else
		{
			if (pila.empty())
				ultimoIndice = i;
			else
			{
				pila.pop();
				if (pila.empty())
				{
					if (maxima < i - ultimoIndice)
					{
						maxima = i - ultimoIndice;
					}
				}
				else
				{
					if (maxima < i - pila.top())
					{
						maxima = i - pila.top();
					}
				}
			}
		}

	}
	cout << "La longitud de la subcadena máxima de paréntesis es: ";
	cout << maxima << endl;
	return 0;

}



int main()
{
	int a, b, opcion = 0;

	cout << "Menu de opciones" << endl;
	cout << "Presione 1-Sumar" << endl;
	cout << "Presione 2-Dividir entre 4" << endl;
	cout << "Presione 3-Invertir cadena" << endl;
	cout << "Presione 4-Cadena válida paréntesis" << endl;
	cin >> opcion;

	switch (opcion)
	{
		case 1:
			return SumaSinOperador();
		case 2:
			return DividirEntre4SinOperador();
		case 3:
			return InvertirCadena();
		case 4:
			return CadenaValidaParentesis();
	}
	
	return 0;

}
