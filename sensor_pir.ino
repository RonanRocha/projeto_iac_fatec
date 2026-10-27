int relayPin = 8; //Pino do LED
int sensorPin = 2; //Pino do sensor de presença
int leitura = 0; //Variável para armazenar a leitura do sensor
bool estadoSensor = false; 

// C++ code
//
void setup()
{
  Serial.begin(9600);  
  pinMode(relayPin, OUTPUT);
  pinMode(sensorPin, INPUT);
  
}

void loop()
{
  leitura = digitalRead(sensorPin); 

  if (leitura == HIGH) { //Se leitura for igual a HIGH, o movimento foi detectado
      
    digitalWrite(relayPin, HIGH); //Aciona o rele

    if (estadoSensor == false) { //Compara o valor de estado do LED
      Serial.println("Movimento detectado"); //Imprime a mensagem no monitor serial
      estadoSensor = true; //Altera o valor de estadoSensor para HIGH   
    }
    
  } else { //Se leitura for igual a LOW, não houve movimento detectado
    
    digitalWrite(relayPin, LOW); //Desliga o rele

    if (estadoSensor == true) { //Compara o valor de estado do LED
        Serial.println("Sem movimento"); //Imprime a mensagem no monitor serial
        estadoSensor = false; //Altera o valor de estadoSensor para HIGH
    }

  }  
}