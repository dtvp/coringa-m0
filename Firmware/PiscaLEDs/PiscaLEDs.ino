const int LED_AZUL = 13; // Blue LED on pin 13
const int LED_RX = PIN_LED_RXL; // RX LED on pin 25
const int LED_TX = PIN_LED_TXL; // TX LED on pin 26

bool ledState = LOW;

void setup() 
{
  pinMode(LED_AZUL, OUTPUT);
  pinMode(LED_RX, OUTPUT);
  pinMode(LED_TX, OUTPUT);
  digitalWrite(LED_RX, HIGH);
  digitalWrite(LED_TX, HIGH);
}

void loop() 
{
  // Toggle RX and TX
  ledState = !ledState;
  digitalWrite(LED_RX, ledState);
  digitalWrite(LED_TX, !ledState);

  // Dimmer up:
  for (int i=0; i<256; i++)
  {
    analogWrite(LED_AZUL, i);
    delay(2);
  }

  delay(50);

  // Dimmer down
  for (int i=255; i>=0; i--)
  {
    analogWrite(LED_AZUL, i);
    delay(2);
  }
  delay(50);
}
