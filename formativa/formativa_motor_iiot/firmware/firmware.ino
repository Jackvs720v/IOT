#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

const char* ssid = "Wokwi-GUEST";
const char* password = "";

const char* contentfulURL = "https://api.contentful.com/spaces/5g095b2j4szw/environments/master/entries"; 
const char* accessToken = "Bearer olx7dMDJiwF7lBZjnjetc-FDW7C7gSo9A3nLMLU_MdI";   

unsigned long timerScan = 0;
#define SCAN_DELAY 10000  // Envia dados a cada 10s

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.println("Conectando ao Wi-Fi...");
  while (WiFi.status() != WL_CONNECTED) {
    delay(100);
    Serial.print(".");
  }
  Serial.println("\nWi-Fi conectado com sucesso!");
}

void loop() {
  if ((millis() - timerScan) >= SCAN_DELAY) {
    Serial.println("\nEnviando dados para o Contentful...");
    sendSensorData();
    timerScan = millis();
  }
}

void sendSensorData() {
  // Simula os valores dos sensores
  float tempMotor = random(300, 600) / 10.0;        
  float tempBombaA = random(250, 500) / 10.0;        
  float tempBombaB = random(250, 500) / 10.0;
  float monometro = random(1000, 5000) / 10.0;  

  Serial.printf("tempMotor: %.1f\n", tempMotor);
  Serial.printf("tempBombaA: %.1f\n", tempBombaA);
  Serial.printf("tempBombaB: %.1f\n", tempBombaB);
  Serial.printf("monometro: %.1f\n", monometro);

  HTTPClient http;
  http.begin(contentfulURL);
  http.addHeader("Authorization", accessToken);
  http.addHeader("Content-Type", "application/vnd.contentful.management.v1+json");
  http.addHeader("X-Contentful-Content-Type", "motorIiot"); // substitua se o content type for diferente

  DynamicJsonDocument doc(1024);

  JsonObject fields = doc.createNestedObject("fields");

  fields["tempMotor"]["pt"] = tempMotor;
  fields["tempBombaA"]["pt"] = tempBombaA;
  fields["tempBombaB"]["pt"] = tempBombaB;
  fields["monometro"]["pt"] = monometro;

  String requestBody;
  serializeJson(doc, requestBody);

  int httpResponseStatus = http.POST(requestBody);

  if (httpResponseStatus > 0) {
    String response = http.getString();
    Serial.println("Resposta da API:");
    Serial.println(response);
  } else {
    Serial.printf("Erro ao enviar: %d\n", httpResponseStatus);
  }

  http.end();
}
