#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
 
// Set these to run example.
#define FIREBASE_HOST "node-mcu-firebase-b65a6.firebaseio.com"
#define FIREBASE_AUTH "dXP7zWrEEIwfl3v3BvfzhNJTZvcPBFX1yTklQBUe"
#define WIFI_SSID "Coimbra"
#define WIFI_PASSWORD "abcd80298421"

int salaLed1,salaLed2,salaLed3,salaLed4,salaTv,salaPorta;
int banheiroChuveiro,banheiroLed,banheiroTemperatura;
int suiteJanela, suiteLed;
int garagemPortao;

void setup() {
  //Define GPIO2 como saída
  pinMode (2, OUTPUT);
  //Inicia o monitor serial
  Serial.begin(9600);
 
  // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("conectando");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("conectado: ");
  Serial.println(WiFi.localIP());
  
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}
void loop() {
 //Receber a variavel led do firebase

 // Controles Sala {
    salaLed1 = Firebase.getInt("salaLed1");
    salaLed2 = Firebase.getInt("salaLed2");
    salaLed3 = Firebase.getInt("salaLed3");
    salaLed4 = Firebase.getInt("salaLed4");
    salaPorta = Firebase.getInt("salaPorta");
    salaTv = Firebase.getString("salaTv");

    salaLed1 == 1 ? digitalWrite(2 ,HIGH) : digitalWrite(2 ,LOW);
    salaLed2 == 1 ? digitalWrite(2 ,HIGH) : digitalWrite(2 ,LOW);
    salaLed3 == 1 ? digitalWrite(2 ,HIGH) : digitalWrite(2 ,LOW);
    salaLed4 == 1 ? digitalWrite(2 ,HIGH) : digitalWrite(2 ,LOW);
    salaPorta == 1 ? digitalWrite(2 ,HIGH) : digitalWrite(2 ,LOW);
//  controles sala }

// Controles Banheiro {
    banheiroChuveiro = Firebase.getInt("banheiroChuveiro");
    banheiroLed = Firebase.getInt("banheiroLed");
    banheiroTemperatura = Firebase.getString("banheiroTemperatura");

    banheiroChuveiro == 1 ? digitalWrite(2 ,HIGH) : digitalWrite(2 ,LOW);
    banheiroLed == 1 ? digitalWrite(2 ,HIGH) : digitalWrite(2 ,LOW);
// controles banheiro }

// Controles suite {
    suiteJanela = Firebase.getInt("suiteJanela");
    suiteLed = Firebase.getInt("suiteLed");

    suiteJanela == 1 ? digitalWrite(2 ,HIGH) : digitalWrite(2 ,LOW);
    suiteLed == 1 ? digitalWrite(2 ,HIGH) : digitalWrite(2 ,LOW);
// controles suite }

    garagemPortao = Firebase.getInt("garagemPortao");
    garagemPortao == 1 ? digitalWrite(2 ,HIGH) : digitalWrite(2 ,LOW);
}