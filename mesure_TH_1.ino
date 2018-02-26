// Acefou
// V1.0 18/02/2018


//http://http://192.168.1.8/myesp.php?esp=IDESP&temp=22.19&humid=80


#include <WEMOS_DHT12.h>
#include <ESP8266HTTPClient.h>
#include <ESP8266WiFiMulti.h>

const char* version_croquis = "acefou v20180218 eth12 v1.0";
const char* ssid = "xxxxxx";
const char* password = "xxxxxx";
ESP8266WiFiMulti WiFiMulti;

DHT12 dht12;
float lth =0;
float lhu =0;

int i=0;
char ID_monESP[ 16 ];

String monurl1 = "http://www.acefou.fr/myesp.php";
String monurl2 = "?esp=";
String monurl3 = "&temp=";
String monurl4 = "&humid=";
String monurl ;

void setup() {

  Serial.begin(115200);
  delay(10);
  Serial.println();
  Serial.println(version_croquis);
  
  uint32_t n = ESP.getChipId();
  snprintf(ID_monESP, sizeof ID_monESP, "ETH%08X", (unsigned long)n); 
  // == Serial.printf("Chip ID = %08X\n", ESP.getChipId());
  Serial.println(ID_monESP);

  WiFiMulti.addAP(ssid, password);

  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);   // Turn the LED off
//signature de la fin du setup avec la led built-in : 3 flash de 0.1 secondes
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);   
  digitalWrite(LED_BUILTIN, HIGH);
  delay(200);
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);   
  digitalWrite(LED_BUILTIN, HIGH);
  delay(200);
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);   
  digitalWrite(LED_BUILTIN, HIGH); // Turn the LED off


  Serial.println("READY : GO to Loop");
}

void loop() {

//1 Mesure
  if(dht12.get()==0){
    Serial.print("Temperature en °Celsius : ");
    lth = dht12.cTemp;
    Serial.println(lth);
    Serial.print("Humiditée  %            : ");
    lhu = dht12.humidity;
    Serial.println(lhu);
    Serial.println();
  }else
  {
   Serial.print(dht12.get()); }


//2 Envoi mesures
    // wait for WiFi connection
    if((WiFiMulti.run() == WL_CONNECTED)) {
        HTTPClient http;
        monurl  = monurl1 + monurl2 + ID_monESP + monurl3 + (String)lth + monurl4 + (String)lhu;
        Serial.println(monurl);
        http.begin(monurl);
        int httpCode = http.GET();
               // httpCode will be negative on error
        if(httpCode > 0) {
            // HTTP header has been send and Server response header has been handled
            Serial.printf("[HTTP] GET... code: %d\n", httpCode);

            // file found at server
            if(httpCode == HTTP_CODE_OK) {
                String payload = http.getString();
                Serial.println(payload);
            }
        } else {
            Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
        }

        http.end();
    }

    
    delay(5000);

}
