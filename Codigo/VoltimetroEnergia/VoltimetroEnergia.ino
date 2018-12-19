/**
 * Autor: Misael Saenz Flores
 * Esta obra está bajo una Licencia Creative Commons 
 * Atribución-NoComercial-SinDerivadas 4.0 Internacional.
 */

#include "SevSeg.h"

SevSeg Display;

#define Vout A0

float Vout_1;
float R1 = 10;
float R2 = 1;
float Vin;
float lista[8];
float voltArreglo;

void setup(){
  Display.Begin(1,3,4,5,6,7,8,9,10,11,12,13,14);
}

void loop(){
  for(int i = 0; i <= 7 ; i++){
    lista[i] = analogRead(Vout);
    voltArreglo = voltArreglo + lista[i];
  }

  float Volt = (((voltArreglo/8.0)/1023) * 3.3);
  Vin = ((Volt/(R2/(R1+R2)))) * 10;
  Display.NewNum(Vin,1);
  Display.PrintOutput();  
  voltArreglo = 0;
}

