#include <string.h>
#include <stdlib.h>
#include <iostream>
#define max 20

using namespace std;

bool palabraReservada (char pr[]);

char *pr [max] = {
    "inicio()","if","else","elif","while","do","while", "for", "switch", "case", "default",
    "break", "return", "Escribir", "Leer", "True", "False","int","float", "String", "boolean",
    "{","}","[","]","(",")", "=","==","!=","<",">","<=",">=","++","--","=+","=-",":",".",";",",",
    "'","+","-","*","/","","<<",">>"
};

int main (){
    
    return 0;
}

bool palabraReservada(char palReservada[]){ //Metodo para verificar si la palabra pertenece a una palabra reservada
    bool reservada = false; //POr defecto, la palabra no es reservada
    string str(palReservada);
    int comparacion;
    for(int i=0; i<max; i++){
        comparacion = strcmp(pr[i],palReservada);
        if(comparacion==0){
            reservada = true;
            break;
        }
    }
}
void imprimirIdentificadoresNoValidos(){
	puts(" ");
	printf("********************************* MENSAJES *********************************\n");
   if(auxTNV == 0){
   	printf("\t\t 0 Errores, programa fuente exitoso...");
   }else{
   	for(int i=0;i<auxTNV;i++)
	   {
   		printf("\t\tERROR: No es Valido el Token: %s \n",tokensNoValidos[i]);
   	}
   }
}


bool verificarNumero(char palabra[]){
	string auxPalabra = palabra;
   esNumero = false;
	short estado = 0,cont=0;
   char *p = palabra;
	while(*p!='\0')
   {
   	switch(estado)
      {
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
