#include <Wifi.h>
#include <WebServer.h>
#include "LandingPage.h" //Faz como um axios point, ela é um wifi local

#define WIFI_NAME "Esp32WebServer" //Alterar para não ter problema na proxima aula
#define WIFI_PASS "senaimange" //Alterar para não ter problema na proxima aula

WebServer server(80) 

void setup(){
    Wifi.mode(WIFI_OFF);
    delay(1000);
    Wifi.mode(WIFI_AP);
    delay(1000);

    
}