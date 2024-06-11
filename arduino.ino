// Definir los pines
const int sensorPin = A0; // Pin analógico donde está conectado el sensor de humedad
const int relayPin = 52; // Pin digital donde está conectado el módulo de relé

// Umbral de humedad para activar/desactivar la bomba
const int threshold = 500;

void setup() {
  // Inicializar el pin del relé como salida
  pinMode(relayPin, OUTPUT);
  // Inicializar el pin del sensor de humedad como entrada (opcional)
  pinMode(sensorPin, INPUT);

  // Inicializar la comunicación serie para la depuración
  Serial.begin(9600);
}

void loop() {
  // Leer el valor del sensor de humedad
  int sensorValue = analogRead(sensorPin);

  // Imprimir el valor del sensor para la depuración
  Serial.print("Humedad del suelo: ");
  Serial.println(sensorValue);

  // Si el valor del sensor es menor que el umbral, encender la bomba
  if (sensorValue>=threshold) {
    digitalWrite(relayPin, HIGH); 
    Serial.println("Bomba encendida");
  } else {
    digitalWrite(relayPin, LOW);
    Serial.println("Bomba apagada");
  }

  // Esperar un segundo antes de la siguiente lectura
  delay(1000);
}