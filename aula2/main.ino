#include <Wifi.h>
#include <WebServer.h>
#include "LandingPage.h" //Faz como um axios point, ela é um wifi local

#define WIFI_NAME "Esp32WebServer" //Alterar para não ter problema na proxima aula
#define WIFI_PASS "senaimange" //Alterar para não ter problema na proxima aula

WebServer server(80) 

void setup(){
    Serial.begin(9600);

    Wifi.mode(WIFI_OFF);
    delay(1000);
    Wifi.mode(WIFI_AP);
    delay(1000);

    IPAddress staticIP(192,168,10,17);
    IPAddress gateway(192,168,10,1);
    IPAddress subnet(255,255,255,0);

    Wifi.softAPConfig(staticIP, gateway, subnet);
    Wifi.softAP(WIFI_NAME,WIFI_PASS);

    Serial.print("IP Configurado: ");
    Serial.println(Wifi.softAPIP());

    /*WEB SERVER: */
    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) { //Quando acessar a raiz da url, 
        request -> send_P(200, "text/html", index_html);
    });

     server.onNotFound(notFound);
    });
    server.begin();


}

void notFound(AsyncWebServerRequest *request1){
    request -> send_P(404, "text/html", notFound_html)
}