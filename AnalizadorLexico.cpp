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

