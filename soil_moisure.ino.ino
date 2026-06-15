const int sensorUmidade = A1;
const int rele = 12;

const int limiteSeco = 600;
const int tempoIrrigacao = 1000; // 5 segundos

void setup() {
  pinMode(rele, OUTPUT);
  digitalWrite(rele, HIGH); // relé desligado (ativo em LOW)

  Serial.begin(9600);
}

void loop() {
  int leitura = analogRead(sensorUmidade);

  Serial.print("Umidade: ");
  Serial.println(leitura);

  if (leitura > limiteSeco) {
    Serial.println("SOLO SECO - IRRIGANDO");

    digitalWrite(rele, HIGH);   // liga relé
    delay(tempoIrrigacao);     // mantém ligado por 5 segundos
    digitalWrite(rele, LOW);  // desliga relé

    Serial.println("IRRIGACAO FINALIZADA");

    delay(5000); // espera 10 segundos antes de medir novamente
  } else {
    Serial.println("SOLO UMIDO");
    digitalWrite(rele, LOW); // garante desligado
    delay(5000);
  }
}