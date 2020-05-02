/*
Un empresa que se dedica a la venta de seguros de vehiculos, calcula el importe
según el modelo y color del automovil, asi como la edad del conductor.

Modelo       Color             Precio
A              Blanco           240.50
                Metalizado    330.00
                Otros             270.50
B               Blanco          300.00
                 Metalizado     360.50
                 Otros             330.00

Incremento de precio
Edad            % Incremento
<31                    25%
Entre 31 y 65    0%
>65                   30%

Determine el importe a pagar mostrandolo en pantalla según los datos del vehículo (modelo y color)
y la edad del conductor.
*/

#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

int main(){
	char modelo;  // Modelo A o B
	int edad;     // numero entero
	char color;   // solo una letra
	float precio; // numeros con decimales
	//variables de apoyo para leer # que contiene el archivo
	string s;
	int lineas;
	char lmodelo;
	int ledad;     // numero entero
	char lcolor;   // solo una letra
	float lprecio; // numeros con decimales
	//Ingreso de datos
	cout<<"Ingrese Datos para poliza de vehiculos:  \n"<<endl;
	cout<<"Ingrese Modelo de Vehiculo:  "<<endl;
	cin>>modelo;
	cout<<"Ingrese Color de Vehiculo:  "<<endl;
	cin>>color;
	cout<<"Ingrese Edad del Conductor:  "<<endl;
	cin>>edad;
	//validaciones
	modelo=toupper(modelo);
	color =toupper(color);
	if (modelo=='A'){
		if (color=='B')
			precio= 240.50;
		else if (color=='M')
			precio=330.00;
		else if (color=='O')
			precio=270.50;
	}
	else if (modelo=='B'){
		if (color=='B')
			precio= 300.00;
		else if (color=='M')
			precio=360.50;
		else if (color=='O')
			precio=330;
	}
	else
		cout<<"Modelo Incorrecto";

	if (edad>=18 && edad < 31)
		precio= precio + (precio*0.25);
	else if (edad>65 && edad <= 80)
		precio= precio + (precio*0.30);
	//output a la pantalla
	cout.precision(5);
	cout<<"Modelo: "<<modelo<<endl;
	cout<<"Color:  "<<color<<endl;
	cout<<"Edad:   "<<edad<<endl;
	cout<<"\n\nPrecio de la poliza a pagar:  "<<precio;
	//Grabar al archivo
	ofstream miarchivo;
	system("PAUSE");
	try {
		miarchivo.open("seguro.txt",ios::out);
		miarchivo<<modelo<<"\t"<<color<<"\t"<<edad<<"\t"<<precio<<endl;
		miarchivo.close();
		cout<<"Datos grabados en el archivo";
	}
	catch(exception X){
		cout<<"Error al grabar en el archivo";
		system("PAUSE");
	} //fin try/catch
	system("CLS"); //limpiar pantalla
	ifstream leerarchivo; //declaracion de objeto tipo archivo que hereda funciones ifstream
	leerarchivo.open("seguro.txt",ios::in);
	leerarchivo>>lmodelo>>lcolor>>ledad>>lprecio;
	leerarchivo.close();

	cout<<lmodelo<<lcolor<<ledad<<lprecio;





}//fin main
