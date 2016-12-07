#include <LiquidCrystal.h>  // libreria para lcd de arduino 
LiquidCrystal lcd(9,8,7,6,5,4); // puertos digitales que voi a utlizar del arduino 
char vector2 []={'A','L','9','6'}; // creacion de un vector que va a representar mi contraseña 
String dat; // variable tipo string para almacenamiento de la informacion ingresda 
int tamano; // variable para el tamaño de la cadena ingresada 
int cont=0; // contador 
int i=0; // variable 
int j=0; // variable

void setup() {
lcd.begin(16,2); // especifico al arduino el tipo de lcd q se va a utilizar 
Serial.begin(9600); // inicializo la comuninicacion serial 
lcd.clear(); // limpio la pantalla 
lcd.setCursor(0,0); // me ubico en la primera posicion del la pantalla 
lcd.print("INGRESE CLAVE"); // imprimo un mjs en la lcd
lcd.setCursor(0,1); // me ubico en la segunda fila de la pantalla para imprimir un mjs 
lcd.print("CUATRO DIGITOS"); // inprimo un mjs  para dar informacion al usuario 
}


void loop() {
if(Serial.available()>0) // sentencia para saber si el usuario escribe algo en el virtual terminal 
 {
 lcd.clear(); // limpio la pantalla 
 dat=Serial.readString(); // leo y asigo la contraseña ingresada 
 tamano=dat.length(); // le asigno a tamano el tamaño de la cadena de la contraseña ingresada 
 char vector[5]; // creo un vector de tamaño cinco en donde se almacenara la contraseña ingresada por el usuario 
 dat.toCharArray (vector,5); // convierto  a char el vector
 while(i<4) // ciclo para comparar las posiciones del vector creado al principio con el vector almacenado con la contraeña ingresada
 {
  if(vector[i]==vector2[i]) // sentencia para comparar cada posicion 
  {
   lcd.setCursor(i,0); // me ubico en una posicion especifica de la lcd
   lcd.print(vector[i]); // imprimo la posicion del vector 
   delay(300); // tiempo para visualizar la informacion 
   lcd.setCursor(i,0); // ubico el cursor en la misma posicion anterior 
   lcd.print('*'); // imprimo un caracter 
   delay(300); // tiempo de espeera 
   i=i+1; // aumento la varible para imprimir la siguiente posicion del vector
   j=j+1; // variable para comparar si la contarseña ingresada es correcta o incorrecta 
  }
  if(vector[i]!=vector2[i])  // comparo cada posicion de los dos vectores si son deferentes
  {
   lcd.setCursor(i,0); // me ubico en una posicion de la lcd
   lcd.print(vector[i]); // imprimo la posicion del vector 
   delay(300); // tiempo de espera 
   lcd.setCursor(i,0); // me ubico en la misma posicion del vector anterior 
   lcd.print('*'); // imprimo un caaracter 
   delay(300); // tiempo de espera 
   i=i+1; // aumento de variable 
  }
 }
 if(j==4) // reviso el valor de esta variable para concluir que la contarseña es correcta   
 {
  lcd.clear(); // limpio la lcd
  lcd.setCursor(0,0); // me ubico en una posicion especifica 
  lcd.print("CONTRASENA"); // imprimo un mesaje 
  lcd.setCursor(0,1); // me ubico en la segunda fila de la lcd
  lcd.print("CORRECTA"); // imprimo un mjs 
  delay(2000); // tiempo para q se visualice el mjs 
 }
 if(j!=4) // reviso el valor de esta variable para concluir que  la contarseña es  incorrecta 
 {
  lcd.clear(); // limpio la lcd
  lcd.setCursor(0,0); // me ubico en una posicion especifica
  lcd.print("CONTRASENA"); // imprimo un mesaje 
  lcd.setCursor(0,1); // me ubico en la segunda fila de la lcd
  lcd.print("INCORRECTA");  // imprimo un mesaje 
  delay(2000); // tiempo para q se visualice el mjs 
 }
 }
 i=0; // vuelvo a cero esta variable
 j=0;// vuelvo a cero esta variable
 }
 

