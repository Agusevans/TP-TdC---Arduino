const int sensorPin = A0; // Pin analógico donde está conectado el sensor de humedad
const int relayPin = 52; // Pin digital donde está conectado el módulo de relé

const int umbral = 600; // Umbral de humedad para activar la bomba
const float kt = 5; // Cte de proporcionalidad de riego
float tiempoRiego = 1000; // [ms]

void setup() {
  
  pinMode(relayPin, OUTPUT); // Inicializar el pin del relé como salida
  pinMode(sensorPin, INPUT); // Inicializar el pin del sensor de humedad como entrada

  Serial.begin(9600); // Inicializar la comunicación serie
}

void loop() {
  
  int humedadSensada = analogRead(sensorPin); // Lee el valor del sensor de humedad

  Serial.print("Humedad del suelo: ");
  Serial.println(humedadSensada);

  // Si el valor del sensor es mayor que el umbral (menor humedad que la deseada), encender la bomba
  if (humedadSensada >= umbral) {
    
    tiempoRiego = (humedadSensada - umbral) * kt;
    if(tiempoRiego < 1000){ // tiempo minimo de riego de 1 segundo
      tiempoRiego = 1000;
    }

    digitalWrite(relayPin, HIGH); 
    Serial.println("Bomba encendida");

    Serial.print("Tiempo de riego [s]: ");
    Serial.println(tiempoRiego/1000);
    delay(tiempoRiego);

    digitalWrite(relayPin, LOW);
    Serial.println("Bomba apagada");

    delay(2000); // Espera 2 segundos a que se moje la tierra
  }

  delay(10); // Esperar 10 milisegundos antes de la siguiente lectura
}