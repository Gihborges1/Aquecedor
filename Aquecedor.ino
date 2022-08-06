#include "max6675.h"

String TD, VT;
const int pinoRele = 2;
int ktcSO = 8; //PINO DIGITAL (SO)
int ktcCS = 9; //PINO DIGITAL (CS)
int ktcCLK = 10; //PINO DIGITAL (CLK / SCK)
 
MAX6675 ktc(ktcCLK, ktcCS, ktcSO); //CRIA UMA INSTÂNCIA UTILIZANDO OS PINOS (CLK, CS, SO)
  
void setup(){
  pinMode(pinoRele, OUTPUT);
  digitalWrite(pinoRele, HIGH);
  Serial.begin(9600); //INICIALIZA A SERIAL
}
 
void loop(){
   Serial.print("Temperatura: "); //IMPRIME O TEXTO NO MONITOR SERIAL
   Serial.print(ktc.readCelsius()); //IMPRIME NO MONITOR SERIAL A TEMPERATURA MEDIDA
   Serial.println("*C"); //IMPRIME O TEXTO NO MONITOR SERIAL
   delay(500); //INTERVALO DE 500 MILISSEGUNDOS

   Serial.println("INFORME QUAL TEMPERATURA DESEJADA:"); 
   while(Serial.available()==0);
   TD = Serial.readString();
   VT = ktc.readCelsius();
   
   if (VT < TD){
    digitalWrite(pinoRele, LOW); //LIGA
     
   }else{
    digitalWrite(pinoRele, HIGH);//DESLIGA
   }
   
}
