// Definir el pin analógico al que está conectado el sensor
const int analogPin = A0;

// Variable para almacenar el valor leído del pin analógico
int sensorValue = 0;

void setup() {
  // Iniciar la comunicación serie para imprimir los valores
  Serial.begin(9600);
}

void loop() {
  // Leer el valor del pin analógico (0 - 1023)
  sensorValue = analogRead(analogPin);

  // Convertir el valor leído a voltios (0 - 5V)
  float voltage = sensorValue * (5.0 / 1023.0);

  // Imprimir el valor en serie
  Serial.print("Valor analógico: ");
  Serial.print(sensorValue);
  Serial.print("\t Voltaje: ");
  Serial.println(voltage);

  // Pausa de 500ms antes de la siguiente lectura
  delay(500);
}
