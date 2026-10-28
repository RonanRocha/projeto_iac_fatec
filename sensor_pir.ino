int relayPin = 8;  // Pino do LED
int sensorPin = 2; // Pino do sensor de presença
bool estadoSensor = false;
bool movimentoDetectado = false;

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
  estadoSensor = digitalRead(sensorPin);

  if (estadoSensor)
  {

    if (!movimentoDetectado)
    {
      digitalWrite(relayPin, HIGH);
      Serial.println("MOVIMENTO DETECTADO");
      movimentoDetectado = true;
      delay(60000);
    }
  }
  else
  {

    if (movimentoDetectado)
    {
      digitalWrite(relayPin, LOW);
      Serial.println("SEM MOVIMENTO");
      movimentoDetectado = false;
    }
  }

  delay(100);
}