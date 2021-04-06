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

int auxTR=0;
int auxTI=0;
int auxTN=0;
int auxTNV=0;

bool verificarNumero(char palabra[]);
bool verificarIdentificador(char palabra[]);
void imprimirIdentificadoresNoValidos();
bool palabraReservada(char palReservada[]);




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

// Metodo para verificar si el token formado cumple para ser un identificador
bool verificarIdentificador(char palabra[]){
	string auxPalabra = palabra;
   esIdentificador = false;
   short estado = 0;
   char *p = palabra;
   while(*p != '\0')
   {
   	switch(estado)
      {
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

	int comprobacion=0;
int cont=0;
int alfabeto(char c) {// obtener la posicion de cada caracter 


	int d = listarecorrido.size();
	cout<<"Lista Recorrido>  "<<d<<endl;
	cout<<"Lo que recibe xpos>  "<<po<<endl;
	if(po!=-1){
		cont--;
		po=-1;
		x=-1;
		comprobacion++;

	}
	cout<<"Lista Recorrido>  "<<d<<endl;

	for(int j=cont ; j<= d ; j++){
		cout<<"Valor de J>  "<<j<<endl;
		cont++;
		cout<<"Valor de cont>  "<<cont<<endl;

		for (int i = 0; i <= 62; i++) {
			cout<<listarecorrido[j]<<endl;

			if (c == alfa[i]) {

				return i;

				break;
			}
		}



    }

    return 0;

}
	void metodoArchivo() {//Lee caracter por caracter del Archivo .txt
    //int linea = 0;
    ifstream fichero; //variable fichero para leer los datos
    fichero.open(("lenguaje.txt"));
    fichero.get(caracter);

    if (fichero.fail()) {// si fichero no falla coge un letra dle fichero
        cout << "Error al abrir el archivo lenguaje.txt" << endl;

    } else {

        while (!fichero.eof()) {//mientras fichero no llegue al final
        	listarecorrido.push_back(caracter);
/*        	listarecorrido.push_back(caracter);
        	int pos= alfabeto(caracter,xpos);
        	//cout<<"la posicion>  "<<pos<<endl;

        	if (pos == 59) {
                linea++;

            }
}
