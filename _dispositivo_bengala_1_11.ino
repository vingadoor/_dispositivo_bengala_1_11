
#include <Adafruit_LiquidCrystal.h>
          
  //projeto realizado pela turma de Desenvolvimento de sistema
// THALITA MARIA
// NICOLAS FRANCISCO
// FRANCISMAR PEREIRA
#define trigger 9   // sensor de obstaculo 8,9                    
#define echo 8                          
#define trigger1 5     
#define echo1 4 

int motor= 12; // motor de  vibração
int Buzzer= 13; //piezo(sinal sonoro)

int motor2= 7;  // motor de  vibração
float distancia = 0;                    
float tempo = 0;
float distancia1=0;
float tempo1=0;



void leitura(); // leitura do sensor de obstaculo
void leitura1(); // leitura do sensor de desnivel



  
void setup() {
  
  Serial.begin(9600);		//comunicação serial
  pinMode(trigger1, OUTPUT); 
  pinMode(echo1, LOW);       
  pinMode(trigger, OUTPUT); 
  pinMode(echo, LOW);
  pinMode(Buzzer,OUTPUT);
  pinMode(motor,OUTPUT);
  pinMode(motor2,OUTPUT);
  
  //delay(2000);
  
  
}

void loop() {
  leitura();
  distancia= tempo/59;  // formula para caculo de distancia
  Serial.print("CM:"); // unidade de medida
  Serial.println(distancia);// mostrar na tela do monitor
  delay (1000);
  
  
  leitura1();
  distancia1= tempo1/59;
  Serial.print("CM:");
  Serial.println(distancia1);
  delay (1000);
  
 
  
 
 // primeiro sensor echo, trigger(8 e 9)
  // este sensor tem como objetivo identificar obstaculo
 
  
  
  // Primeira identificação do obstaculo
  
  if (distancia>=160 && distancia<=200){
  	digitalWrite(motor,HIGH);
  	tone(Buzzer, 656, 300); 
     delayMicroseconds(500);
    
    
  } // obstaculo longe    	
  
  else  {
  digitalWrite(motor, LOW);
  }
  
  
  //segundo sinal que obstaculo persiste
  
  if (distancia<159){
  	digitalWrite(motor,HIGH);
  	tone(Buzzer,2000, 500); 
     delayMicroseconds(500);
   
    
  }     	
  else  {
  //digitalWrite(motor, LOW);
  }
  
  
  // segundo sensor echo1, trigger1(4 e 5)
  // este sensor tem como objetivo identificar desnivel
  // este sensor trabalha numa margem segura de de 134cm
  // caso aja um desnivel de até 14cm
  // passado de 15cm o sensor vai que aja 
  //um desnivelamento grande ou buraco
  
  if (distancia1>=135 && distancia1<=149){
  	digitalWrite(motor2,HIGH);
  	tone(Buzzer, 856, 300);
      
     delayMicroseconds(500); 
   
    } // desnivel de 10cm
  else  {
  digitalWrite(motor2, LOW);
  }
  
  //identifcando desnivelamento grande ou buraco
  if (distancia1>150){
  	digitalWrite(motor2,HIGH);
  	tone(Buzzer, 456, 300);
     
     delayMicroseconds(500); 
    
    }
   else  {
//  digitalWrite(motor2, LOW);
  }
  
}
  void leitura()
  {
  pinMode(trigger, OUTPUT);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
    digitalWrite(trigger, LOW);
    pinMode(echo, INPUT);
    tempo=pulseIn(echo,HIGH);
  }



void leitura1(){
    
    pinMode(trigger1, OUTPUT);
  digitalWrite(trigger1, HIGH);
  delayMicroseconds(10);
    digitalWrite(trigger1, LOW);
    pinMode(echo1, INPUT);
    tempo1=pulseIn(echo1,HIGH);
    
    
  }

  
  

 

 