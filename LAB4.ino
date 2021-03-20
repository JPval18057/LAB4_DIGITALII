/*
  Blink
  The basic Energia example.
  Turns on an LED on for one second, then off for one second, repeatedly.
  Change the LED define to blink other LEDs.
  
  Hardware Required:
  * LaunchPad with an LED
  
  This example code is in the public domain.
*/

// most launchpads have a red LED
#define LED BLUE_LED

//see pins_energia.h for more LED definitions
#define LED1 GREEN_LED
#define LED2 RED_LED
#define LED3 BLUE_LED
#define boton_inicio PA_2

//VARIABLES
int count=0;
int count2=0; 

//GANADOR
int win1=0;
int win2=0;

//JUEGO ACTIVO
int game=0;
int lights = 0; //indica si se debe ejecutar la secuencia de inicio
int start = 0; //sencuencia de inicio de luces

//definición de botones
const byte boton1 = PUSH1;
const byte boton2 = PUSH2; 

//PROTOTIPO FUNCIONES
void luces(void);
void apagar(void);
void semaforo_off(void);

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(LED, OUTPUT);     
  pinMode(LED1, OUTPUT);     
  pinMode(LED2, OUTPUT);    //Luces del semáforo
  //LUCES JUGADOR 1
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
  pinMode(A4, OUTPUT);
  pinMode(A5, OUTPUT);
  pinMode(A6, OUTPUT);
  pinMode(A7, OUTPUT);
  //LUCES JUGADOR 2
  pinMode(PA_7, OUTPUT);
  pinMode(PA_6, OUTPUT);
  pinMode(PB_5, OUTPUT);
  pinMode(PB_4, OUTPUT);
  pinMode(PE_5, OUTPUT);
  pinMode(PE_4, OUTPUT);
  pinMode(PB_1, OUTPUT);
  pinMode(PB_0, OUTPUT);
  
  //BOTONES
  pinMode(boton1, INPUT_PULLUP);
  pinMode(boton2, INPUT_PULLUP);
  pinMode(boton_inicio, INPUT);
  Serial.begin(115200);
}

// the loop routine runs over and over again forever:
void loop() {
  if (digitalRead(boton_inicio)==0 & game==0){ //boton en PA_2 por default
    game=1;
    win1=0;
    win2=0;
    semaforo_off();
    apagar();
    luces();
    semaforo_off();
    count=0;
    count2=0;//por si acaso
  }
  if (game==1){
    //boton de inicio del juego, solo funciona si el juego está parado (alguien ganó)
    if(digitalRead(boton1)==0){
      while (digitalRead(boton1)==0); //avanza el contador hasta que suelto el botón
      delay(50);//debouncing
      count++;
      //Serial.println(count); //Enviamos el dato para corroborar
      //mecanismo de ganador1
      if (count==8){
        digitalWrite(A0, LOW);
        digitalWrite(A1, LOW);
        digitalWrite(A2, LOW);
        digitalWrite(A3, LOW);
        digitalWrite(A4, LOW);
        digitalWrite(A5, LOW);
        digitalWrite(A6, LOW);
        digitalWrite(A7, HIGH);
        delay(300);
        count=0;
        win1=1;
        game=0; //se para el juego
      } 
    }
    if (digitalRead(boton2)==0){
      while (digitalRead(boton2)==0); //cuenta hasta que suelto el botón
      delay(50); //debouncing
      count2++;
      //Serial.println(count2);
      
      //mecanismo de ganador2
      if (count2==8){
        digitalWrite(PA_7, LOW);
        digitalWrite(PA_6, LOW);
        digitalWrite(PB_5, LOW);
        digitalWrite(PB_4, LOW);
        digitalWrite(PE_5, LOW);
        digitalWrite(PE_4, LOW);
        digitalWrite(PB_1, LOW);
        digitalWrite(PB_0, HIGH);
        delay(300);
        count2=0;
        win2=1;
        game=0; //se para el juego
      } 
    }
    //switch case
    //para jugador 1
      switch (count){
      case 1:
        digitalWrite(A0, HIGH);
        digitalWrite(A1, LOW);
        digitalWrite(A2, LOW);
        digitalWrite(A3, LOW);
        digitalWrite(A4, LOW);
        digitalWrite(A5, LOW);
        digitalWrite(A6, LOW);
        digitalWrite(A7, LOW);
        break;
      case 2:
        digitalWrite(A0, LOW);
        digitalWrite(A1, HIGH);
        digitalWrite(A2, LOW);
        digitalWrite(A3, LOW);
        digitalWrite(A4, LOW);
        digitalWrite(A5, LOW);
        digitalWrite(A6, LOW);
        digitalWrite(A7, LOW);    
        break;
      case 3:
        digitalWrite(A0, LOW);
        digitalWrite(A1, LOW);
        digitalWrite(A2, HIGH);
        digitalWrite(A3, LOW);
        digitalWrite(A4, LOW);
        digitalWrite(A5, LOW);
        digitalWrite(A6, LOW);
        digitalWrite(A7, LOW);
        break;
      case 4:
        digitalWrite(A0, LOW);
        digitalWrite(A1, LOW);
        digitalWrite(A2, LOW);
        digitalWrite(A3, HIGH);
        digitalWrite(A4, LOW);
        digitalWrite(A5, LOW);
        digitalWrite(A6, LOW);
        digitalWrite(A7, LOW);
        break;
      case 5:
        digitalWrite(A0, LOW);
        digitalWrite(A1, LOW);
        digitalWrite(A2, LOW);
        digitalWrite(A3, LOW);
        digitalWrite(A4, HIGH);
        digitalWrite(A5, LOW);
        digitalWrite(A6, LOW);
        digitalWrite(A7, LOW);
        break;
      case 6:
        digitalWrite(A0, LOW);
        digitalWrite(A1, LOW);
        digitalWrite(A2, LOW);
        digitalWrite(A3, LOW);
        digitalWrite(A4, LOW);
        digitalWrite(A5, HIGH);
        digitalWrite(A6, LOW);
        digitalWrite(A7, LOW);
        break;
      case 7:
        digitalWrite(A0, LOW);
        digitalWrite(A1, LOW);
        digitalWrite(A2, LOW);
        digitalWrite(A3, LOW);
        digitalWrite(A4, LOW);
        digitalWrite(A5, LOW);
        digitalWrite(A6, HIGH);
        digitalWrite(A7, LOW);
        break;
      default:
      //si no se cumple ninguna condición
      //apagar todo
        digitalWrite(A0, LOW);
        digitalWrite(A1, LOW);
        digitalWrite(A2, LOW);
        digitalWrite(A3, LOW);
        digitalWrite(A4, LOW);
        digitalWrite(A5, LOW);
        digitalWrite(A6, LOW);
        digitalWrite(A7, LOW);
        break;
    }

    switch (count2){
        case 1:
          digitalWrite(PA_7, HIGH);
          digitalWrite(PA_6, LOW);
          digitalWrite(PB_5, LOW);
          digitalWrite(PB_4, LOW);
          digitalWrite(PE_5, LOW);
          digitalWrite(PE_4, LOW);
          digitalWrite(PB_1, LOW);
          digitalWrite(PB_0, LOW);
          break;
        case 2:
          digitalWrite(PA_7, LOW);
          digitalWrite(PA_6, HIGH);
          digitalWrite(PB_5, LOW);
          digitalWrite(PB_4, LOW);
          digitalWrite(PE_5, LOW);
          digitalWrite(PE_4, LOW);
          digitalWrite(PB_1, LOW);
          digitalWrite(PB_0, LOW);
          break;
        case 3:
          digitalWrite(PA_7, LOW);
          digitalWrite(PA_6, LOW);
          digitalWrite(PB_5, HIGH);
          digitalWrite(PB_4, LOW);
          digitalWrite(PE_5, LOW);
          digitalWrite(PE_4, LOW);
          digitalWrite(PB_1, LOW);
          digitalWrite(PB_0, LOW);
          break;
        case 4:
          digitalWrite(PA_7, LOW);
          digitalWrite(PA_6, LOW);
          digitalWrite(PB_5, LOW);
          digitalWrite(PB_4, HIGH);
          digitalWrite(PE_5, LOW);
          digitalWrite(PE_4, LOW);
          digitalWrite(PB_1, LOW);
          digitalWrite(PB_0, LOW);
          break;
        case 5:
          digitalWrite(PA_7, LOW);
          digitalWrite(PA_6, LOW);
          digitalWrite(PB_5, LOW);
          digitalWrite(PB_4, LOW);
          digitalWrite(PE_5, HIGH);
          digitalWrite(PE_4, LOW);
          digitalWrite(PB_1, LOW);
          digitalWrite(PB_0, LOW);
          break;
        case 6:
          digitalWrite(PA_7, LOW);
          digitalWrite(PA_6, LOW);
          digitalWrite(PB_5, LOW);
          digitalWrite(PB_4, LOW);
          digitalWrite(PE_5, LOW);
          digitalWrite(PE_4, HIGH);
          digitalWrite(PB_1, LOW);
          digitalWrite(PB_0, LOW);
          break;
        case 7:
          digitalWrite(PA_7, LOW);
          digitalWrite(PA_6, LOW);
          digitalWrite(PB_5, LOW);
          digitalWrite(PB_4, LOW);
          digitalWrite(PE_5, LOW);
          digitalWrite(PE_4, LOW);
          digitalWrite(PB_1, HIGH);
          digitalWrite(PB_0, LOW);
          break;
        default:
        //si no se cumple ninguna condición
        //apagar todo
          digitalWrite(PA_7, LOW);
          digitalWrite(PA_6, LOW);
          digitalWrite(PB_5, LOW);
          digitalWrite(PB_4, LOW);
          digitalWrite(PE_5, LOW);
          digitalWrite(PE_4, LOW);
          digitalWrite(PB_1, LOW);
          digitalWrite(PB_0, LOW);
          break;
      }
    
  }
  if (win1==1){
    digitalWrite(LED, HIGH);  
  }
  if (win2==1){
    digitalWrite(LED1, HIGH);
  }
  
  
  
}

//secuencia de luces del semáforo
void luces(void){
    digitalWrite(LED1, HIGH);
    delay(1000);
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, HIGH);
    delay(1000);
    digitalWrite(LED2, LOW);
    digitalWrite(LED, HIGH);
    delay(1000);
    digitalWrite(LED, LOW);
}

//secuencia para apagar todas las luces
void apagar(void){
  //apagamos todas las luces del jugador 2
  digitalWrite(PA_7, LOW);
  digitalWrite(PA_6, LOW);
  digitalWrite(PB_5, LOW);
  digitalWrite(PB_4, LOW);
  digitalWrite(PE_5, LOW);
  digitalWrite(PE_4, LOW);
  digitalWrite(PB_1, LOW);
  digitalWrite(PB_0, LOW);
  //apagamos todas las luces del jugador 1
  digitalWrite(A0, LOW);
  digitalWrite(A1, LOW);
  digitalWrite(A2, LOW);
  digitalWrite(A3, LOW);
  digitalWrite(A4, LOW);
  digitalWrite(A5, LOW);
  digitalWrite(A6, LOW);
  digitalWrite(A7, LOW);
}
void semaforo_off(void){
  digitalWrite(LED, LOW);
  delay(1);
  digitalWrite(LED1, LOW);
  delay(1);
  digitalWrite(LED2, LOW);
  delay(1);
}
