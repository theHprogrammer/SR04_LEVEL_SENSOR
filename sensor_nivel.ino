#include <NewPing.h>  // Biblioteca para o sensor ultrassônico

#define TRIGGER_PIN 12  // Pino de disparo (Trigger) conectado ao pino D1
#define ECHO_PIN 14    // Pino de eco (Echo) conectado ao pino D2
#define MAX_DISTANCE 500 // Distância máxima a ser medida em centímetros

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

const int nivelAlerta = 300;  // Nível de água em centímetros que aciona o alerta

void setup() {
  Serial.begin(9600);
}

void loop() {
  delay(500);  // Delay para obter leituras mais estáveis

  int distancia = sonar.ping_cm();  // Realiza a medição da distância em centímetros

  if (distancia >= 25) {
    // Calcula o nível da água subtraindo a distância medida da altura da ponte (5 metros)
    int nivelAgua = MAX_DISTANCE - distancia;

    Serial.print("Nível de água: ");
    Serial.print(nivelAgua);
    Serial.println(" cm");

    // Verifica se o nível de água ultrapassou o nível de alerta
    if (nivelAgua >= nivelAlerta) {
      // Aciona o alerta aqui
      Serial.println("ALERTA: Nível de água elevado!");
    }
  }
}
