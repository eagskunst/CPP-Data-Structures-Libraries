#include <iostream>
#include <windows.h>
#include <conio.h>
#include "fileManager.h"
#include "coords.h"
#include "cancion.h"
#include "colas.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

void imprimirInstrucciones()
{
	// IMPRESI�N DEL T�TULO
	gotoxy(10, 10);
	cout << "Reproductor de archivos .mp3";
	// IMPRESI�N DE T�TULO DE INSTRUCCIONES.
	gotoxy(7, 13);
	cout << "OPERACION";
	gotoxy(40, 13);
	cout << "TECLA";

	//IMPRESI�N DE OPERACIONES
	gotoxy(7, 15);
	cout << "REPRODUCIR";
	gotoxy(7, 16);
	cout << "DETENER";
	gotoxy(7, 17);
	cout << "PAUSAR";
	gotoxy(7, 18);
	cout << "SIGUIENTE";
	gotoxy(7, 19);
	cout << "CARGAR COLA DE REPRODUCCION";
	gotoxy(7, 20);
	cout << "SALIR";

	//IMPRESI�N DE TECLAS
	gotoxy(40, 15);
	cout << "R";
	gotoxy(40, 16);
	cout << "S";
	gotoxy(40, 17);
	cout << "P";
	gotoxy(40, 18);
	cout << "N";
	gotoxy(40, 19);
	cout << "C";
	gotoxy(40, 20);
	cout << "E";
}
//COORD coordenadas = getCoord();
//cout << coordenadas.X << " " << coordenadas.Y << endl;
//gotoxy(1,1);
//cout << coordenadas.X << " " << coordenadas.Y << endl;
//gotoxy(10,10);
//cout << coordenadas.X << " " << coordenadas.Y << "1" << endl;

int main(int argc, char **argv)
{

	imprimirInstrucciones();

	fileManager<Cancion> archivo("mp3.txt");
	archivo.cleanFile("mp3.txt");
	int cantidad = 7; //Cantidad dicha en el archivo de la actividad.
	Cancion canciones[cantidad];
	colaCircular<Cancion> cola(cantidad);
	archivo.open(OPENMODE_READING_TXT);
	for(int i = 0; i < cantidad; i ++){ 
		char buffer[300];
		archivo.read(buffer);
		canciones[i].cargarDatos(buffer);
	}
	archivo.close();


	// char letra;

	// do
	// {
	// 	if (kbhit)
	// 	{
	// 		letra = getch();
	// 		gotoxy(24, 23);
	// 		cout << "LETRA PRESIONADA: " << letra;
	// 		if (letra == 'e' || letra == 'E')
	// 			break;
	// 	}

	// } while (1);

	return 0;
}
