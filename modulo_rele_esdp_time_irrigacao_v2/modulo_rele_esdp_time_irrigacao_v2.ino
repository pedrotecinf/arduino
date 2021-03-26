#include <Time_irrigacao.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#define pin_rele 0

//Time_irrigacao rele_bomba1M(botaoDesliga,pin_rele);
Time_irrigacao rele_bomba5M(botaoDesliga,pin_rele);
//Time_irrigacao rele_bomba15M(botaoDesliga,pin_rele);
// Time_irrigacao rele_bomba30M(botaoDesliga,pin_rele);


 
// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "0f347e7b56e5441a9ea9a2e7e5bf52ac";
 


// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "";
char pass[] = "";

 BLYNK_WRITE(V0)
{
  int pinValue = param.asInt();
  
  if(pinValue == 1)rele_bomba30M.start();botaoDesliga=pinValue;// ligado
  if(pinValue == 0){botaoDesliga=!pinValue; rele_bomba30M.stop(); }
}
 BLYNK_WRITE(V1)
{
   int pinValue = param.asInt();
  if(pinValue == 1)rele_bomba1M.start();botaoDesliga=pinValue; // ligado
  if(pinValue == 0){botaoDesliga=!pinValue; rele_bomba1M.stop(); }
  
  
}
 BLYNK_WRITE(V2)
{
   int pinValue = param.asInt();
  if(pinValue == 1)rele_bomba5M.start(); botaoDesliga=pinValue;// ligado
  if(pinValue == 0){botaoDesliga=!pinValue; rele_bomba5M.stop(); }
}
 BLYNK_WRITE(V3 )
{
   int pinValue = param.asInt();
  if(pinValue == 1)rele_bomba15M.start();botaoDesliga=pinValue; // ligado
  if(pinValue == 0){botaoDesliga=!pinValue; rele_bomba15M.stop(); }
}

 
void setup()
{ 
  Blynk.begin(auth, ssid, pass);

  
}
 
 
void loop()
{
  Blynk.run();
  rele_bomba1M.loop();
   rele_bomba5M.loop();
    rele_bomba15M.loop();
    rele_bomba30M.loop();
}

 
