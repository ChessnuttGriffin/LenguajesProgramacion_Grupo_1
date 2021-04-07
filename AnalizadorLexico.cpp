#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <string>
#include <iostream>
#define MAX 650
#define MAX_RES 23

char *pr [MAX_RES] = {
    "inicio()","if","else","elif","while","do","while", "for", "switch", "case", "default",
    "break", "return", "Escribir", "Leer", "True", "False","int","float", "String", "boolean",
    "{","}","[","]","(",")", "=","==","!=","<",">","<=",">=","++","--","=+","=-",":",".",";",",",
    "'","+","-","*","/","","<<",">>"
};

using namespace std;
char tokenSimbolos[MAX];
char auxWord[MAX];	
string tokenNumeros[MAX];
string tokenIdentificadores[MAX];
string tokenReservadas[MAX];
string tokensNoValidos[MAX];

bool verificarNumero(char palabra[]);
bool verificarIdentificador(char palabra[]);
bool verificarReservada(char palabra[]);


int main(){

   for(int i=0;i<MAX;i++){
	tokenReservadas[i] = "";
   } // Fin del ciclo

   for(int i=0;i<MAX;i++){
	tokensNoValidos[i] = "";
   }

   for(int i=0;i<MAX;i++){
	palabra[i] = '\0';
   }

} 

// Metodo para verificar si el token formado corresponde a una palabra reservada
   bool verificarReservada(char palabra[]){
	int comp;
	bool esReservada=false;
	string str(palabra);
	for(int i=0; i<MAX_RES; i++){
		comp = strcmp(PalabrasReservadas[i],palabra);
		if(comp == 0){
		    esReservada = true;
		    break;
		}
	 }
	 return esReservada;
   }
