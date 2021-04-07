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
//Este bucle es el que recorre cada caracter de la entrada(programa fuente) que ingreso el usuario, el procedimiento dentro del bucle es para formar los tokens necesarios.
   while(*p!='\0'){
		if((*p != ' ') && (*p !=',')){ 	//Primero revisa que sea distinto de un espacio ' ' y una coma ','
			if((p== ';') || (*p=='"') || (*p=='(') || (*p==')') || (*p=='+') || (*p=='-') || (*p=='') || (*p=='/') || (*p=='#') || (*p=='<') || (*p=='>') || (*p=='=')){
			   tokenSimbolos[indexSimbolos] = *p;
				indexSimbolos++;
			}else{
				palabra[indexPalabra] = *p;
				auxWord[indexPalabra] = *p;	//La razon de usar este arreglo es para mandar como parametro al metodo verificarNumero()... debido a un problema de programacion.
				indexPalabra++;
			}
      }
      else if((*p ==' ') || (*p ==',')){
      	// Guarda la palabra en los respectivos tokens segun las funciones hayan examinado la palabra.
         if(verificarReservada(palabra) == true){
			tokenReservadas[auxTR] = palabra;
          	auxTR++;
         }else if(verificarIdentificador(palabra) == true){
         	tokenIdentificadores[auxTI] = palabra;
		    auxTI++;
         }else if(verificarNumero(auxWord)==true){
         	tokenNumeros[auxTN] = auxWord;
		    auxTN++;
         }
         for(int i=0;i<MAX;i++){
			 palabra[i]='\0';
		 }	//Para vaciar el arreglo de la palabra
         for(int i=0;i<MAX;i++){
			 auxWord[i]='\0';
	     }	//Para vaciar el arreglo del arreglo auxiliar
         indexPalabra=0;
      }
      p++;
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


bool verificarIdentificador(char palabra[]){
	 string auxPalabra = palabra;
     esIdentificador = false;
     short estado = 0;
     char *p = palabra;
     while(*p != '\0'){
		switch(estado){
			case 0:
				if((isalpha(*p)) || (*p=='_')){
					estado = 1;
				   esIdentificador = true;
				}
				else{
					estado = 2;
				   esIdentificador = false;
				}
				p++;
			 break;
			 case 1:
				if((isalpha(*p)) || (isdigit(*p)) || (*p=='_')){
					estado = 1;
				   esIdentificador = true;
				}
				else{
					estado = 2;
				   esIdentificador = false;
				}
				p++;
			 break;
			 case 2:
					//No es un identificador
				esIdentificador = false;
				*p = '\0';
			 break;
		}
   }
   return esIdentificador;
}

bool verificarNumero(char palabra[]){
	string auxPalabra = palabra;
	esNumero = false;
	short estado = 0,cont=0;
	char *p = palabra;
	while(*p!='\0'){
		switch(estado){
			case 0:
				if(isdigit(*p)){
						estado = 0;
				   esNumero = true;
				   cont++;
				}
				else if( ((*p == '.') && (cont==0)) || (isalpha(*p))){
						estado = 2;
				   esNumero=false;
				}else if(*p=='.'){
						estado = 1;
					esNumero = false;
				}
				p++;
				break;
			 case 1:
				if(isdigit(*p)){
					estado = 1;
				   esNumero = true;
				}else
				{
					estado = 2;
				   esNumero = false;
				}
				p++;
				break;
			 case 2:
					esNumero = false;
				    *p = '\0';
					break;
		  }
	   }
	   
	   if(esNumero == false){
		  if(auxPalabra != ""){
		   tokensNoValidos[auxTNV] = auxPalabra;
			  auxTNV++;
		  }
		}
 	return esNumero;
}
