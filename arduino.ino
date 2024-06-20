const int sensorPin = A0; // Pin analógico donde está conectado el sensor de humedad
const int relayPin = 52; // Pin digital donde está conectado el módulo de relé

const int threshold = 500; // Umbral de humedad para activar la bomba
const int bombTime = 3000; // Tiempo de riego de la bomba (ms)

void setup() {
  
  pinMode(relayPin, OUTPUT); // Inicializar el pin del relé como salida
  pinMode(sensorPin, INPUT); // Inicializar el pin del sensor de humedad como entrada

  Serial.begin(9600); // Inicializar la comunicación serie
}

void loop() {
  
  int sensorValue = analogRead(sensorPin); // Leer el valor del sensor de humedad

  // Imprimir el valor del sensor
  Serial.print("Humedad del suelo: ");
  Serial.println(sensorValue);

  // Si el valor del sensor es menor que el umbral, encender la bomba por el tiempo definido
  if (sensorValue >= threshold) {
    
    digitalWrite(relayPin, HIGH); 
    Serial.println("Bomba encendida");

    delay(bombTime);

    digitalWrite(relayPin, LOW);
    Serial.println("Bomba apagada");
  }

  delay(100); // Esperar 100 milisegundos antes de la siguiente lectura
}