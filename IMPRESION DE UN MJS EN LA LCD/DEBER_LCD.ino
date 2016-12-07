#include <LiquidCrystal.h> // libreria para lcd
LiquidCrystal lcd(9,8,7,6,5,4); // declaro q puertos voi a utilizar de mi placa arduino
int i=0; // variable  
String dat; // variable tipo string
int tamano; // variable para utilizarla para saber el tamaño de la cadena ingresada
//String nodo;
int cont; //  variable para utilizarla en la impresion de los caracteres en la lcd
//int t; 
void setup() 
{
lcd.begin(16,2); // indico el tipo de lcd que voi a utilizar 
Serial.begin(9600); // inicializo la cx serial
lcd.clear(); // se realiza una limpieza de la pantalla 
}


void loop() 
{
 if(Serial.available()>0) // sentencia para verificar si se escribe algo en el virtual terminal o monitor serie del entorno de arduino 
 {
 dat=Serial.readString(); // lee la cadena ingresada
 tamano=dat.length(); // le asigno el valor del tamaño de la cadena a la variable tamano
 char vector[(dat.length()+1)]; // creo un vector de tamaño de la cadena + 1 espacio
 dat.toCharArray (vector,(dat.length()+1)); // convierto el vector a char el vector creado
for(;cont<tamano;cont++) // ciclo para imprimir los caracteres en la lcd 
{
lcd.setCursor(cont,0); // me ubico en una posicion especifica de la lcd para empezar a imprimir los caracteres
lcd.print(vector[cont]); // imprimo los caracteres posicion por posicion 
delay(300); // sentencia de espera para visualizar el caracter
lcd.setCursor(cont,0); // me ubico en la misma posicion inicial 
lcd.print(' '); // imprimo un espacio en blanco 
delay(300); // sentencia para visualizar el caracter
//Serial.print(vector[cont]);
}
lcd.setCursor(0,0); // me ubico en una posicion especifica para imprimir toda la cadena ingresada 
lcd.print(dat); // imprimo toda la cadena ingresada 
delay(1000); // tiempo para visualizar los datos 
lcd.clear(); // limpio la pantalla
cont=0; // encero la variable acumulada.
 }
}
