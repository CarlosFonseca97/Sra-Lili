 #include <RtcDS3231.h>             // Libreria para el reloj en tiempo real
#include "LiquidCrystal_I2C.h"// Libreria pantalla LCD
#include "Wire.h" 
#include "FirebaseESP8266.h"
#include <ESP8266WiFi.h>

#include <StaticThreadController.h>
#include <Thread.h>            // Libreria Acondicionada para realizar la programacion MultiHilo
#include <ThreadController.h>

#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>         //https://github.com/tzapu/


//unsigned long myChannelNumber = SECRET_CH_ID;
//const char * myWriteAPIKey = SECRET_WRITE_APIKEY;

#define FIREBASE_HOST "sralili-b4ef5-default-rtdb.firebaseio.com" //Without http:// or https:// schemes
#define FIREBASE_AUTH "lETgXQdNcOQUgoE7vVOkfrmJw2DeQZSg7j0Qyt4o"
FirebaseData firebaseData;
FirebaseJson json;
void printResult(FirebaseData &data);
ThreadController controlFirebase = ThreadController();   //control independiente
ThreadController controlFirebase2 = ThreadController();   //control independiente
ThreadController control1 = ThreadController();
ThreadController control2 = ThreadController();
ThreadController control3 = ThreadController();

Thread* ThreadRiego1 = new Thread();

Thread* ThreadRiego2 = new Thread();

Thread* ThreadPantalla = new Thread();

Thread* ThreadSendFirebase = new Thread(); //Thread principal independiente firebase
Thread  ThreadSendFirebaseSp = Thread();
Thread* ThreadReciveFirebase = new Thread(); //Thread principal independiente firebase
 RtcDS3231<TwoWire> Rtc(Wire);
 RtcDateTime now = Rtc.GetDateTime();
 int r_diaSemana; 
 int segundo;
 int minuto;
 int hora;
 int tiempo_riego;
 int b;
 int c;
 bool internet;
 bool automatico;
 String TipoRiego;
String Interruptor;
String Interruptor2;
bool RiegoB1; // true = automatico false = Manual
bool RiegoB2;
bool RiegoM; // true = pulsar desde app On false = pulsar desde la app Off
bool RiegoM2;
//DateTime dt(2019, 11, 23, 11, 13, 0, 3);
 //rtc.setDOW(WEDNESDAY);     // Set Day-of-Week to SUNDAY
  //rtc.setTime(12, 0, 0);     // Set the time to 12:00:00 (24hr format)
  //rtc.setDate(1, 1, 2014);
 /* El siguiente bloque debe habilitarse para reajustar el reloj RTC cargar el arreglo Eliminar la linea y volver a cargar si esta
  La linea fija la fecha, hora y dia de la semana, se debe suprimir la linea en la segunda carga
  Ejemplo 2018 noviembre 11, 08:00:00  dia 6-Sabado (0=Dom, 1=Lun, 2=Mar, 3=Mie, 4=Jue, 5=Vie, 6=Sab)
   DateTime dt(2018, 11, 14, 22, 12, 0, 3);
*/
//DateTime dt(2020, 4, 5, 18, 9, 0, 1);
  //DateTime dt(2018, 11, 14, 22, 12, 0, 3);


//____________________________________ Horario 1 cada 15 min___________________
//Horario para ENCENDIDO de motomba 1 Riego 1
 int h1_c1=6;   int m1_c1=0;   int s1_c1=0;  // 6:00
 int h2_c1=7;   int m2_c1=15;   int s2_c1=0; // 7:15
 int h3_c1=8;   int m3_c1=30;   int s3_c1=0; // 8:30
 int h4_c1=9;  int m4_c1=45;    int s4_c1=0; // 9:45
 int h5_c1=11;  int m5_c1=0;    int s5_c1=0; // 11:00
 int h6_c1=12;  int m6_c1=15;   int s6_c1=0; // 12:15
 int h7_c1=13;  int m7_c1=30;   int s7_c1=0; // 13:30
 int h8_c1=14;  int m8_c1=45;   int s8_c1=0; // 14:45
 int h9_c1=16;  int m9_c1=0;    int s9_c1=0; // 16:00
 int h10_c1=17; int m10_c1=15;  int s10_c1=0;// 17:15
 int h11_c1=18; int m11_c1=30;  int s11_c1=0;// 18:30
 //Horario1 Noche encendido bomba 1
 int h12_c1=19; int m12_c1=0;   int s12_c1=0;
 int h13_c1=22; int m13_c1=10;   int s13_c1=0;
 int h14_c1=1; int m14_c1=20;   int s14_c1=0;
 int h15_c1=4; int m15_c1=30;   int s15_c1=0;
 int h16_c1=99; int m16_c1=0;   int s16_c1=0;

 //Horarios de APAGADO de Riego
 int h1_c2=6;   int m1_c2=15;   int s1_c2=0;   //6:00-6:15
 int h2_c2=7;   int m2_c2=30;   int s2_c2=0;   //7:15-7:30
 int h3_c2=8;   int m3_c2=45;    int s3_c2=0;  //8:30-8:45
 int h4_c2=10;  int m4_c2=0;   int s4_c2=0;    //9:45-10:00
 int h5_c2=11;  int m5_c2=15;   int s5_c2=0;   //11:00-11:15
 int h6_c2=12;  int m6_c2=30;   int s6_c2=0;   //12:15-12:30
 int h7_c2=13;  int m7_c2=45;    int s7_c2=0;  //13:30-13:45
 int h8_c2=15;  int m8_c2=0;   int s8_c2=0;    //14:45-15:00
 int h9_c2=16;  int m9_c2=15;   int s9_c2=0;   //16:00-16:15
 int h10_c2=17; int m10_c2=30;  int s10_c2=0;  //17:15-17:30
 int h11_c2=18; int m11_c2=45;  int s11_c2=0;  //18:30-18:45
 //Horario Noche Apagado Bomba 1
 int h12_c2=19; int m12_c2=10;   int s12_c2=0; //19:00-19:10
 int h13_c2=22; int m13_c2=20;   int s13_c2=0; 
 int h14_c2=1;  int m14_c2=30;   int s14_c2=0;
 int h15_c2=4; int m15_c2=40;    int s15_c2=0;
 int h16_c2=99; int m16_c2=0;    int s16_c2=0;

//Horario para ENCENDIDO Bomba 2 de riego 1
 int h1_c3=6;   int m1_c3=0;    int s1_c3=0; // 6:00
 int h2_c3=7;   int m2_c3=15;   int s2_c3=0; // 7.30
 int h3_c3=8;   int m3_c3=30;   int s3_c3=0; // 8.45
 int h4_c3=9;  int m4_c3=45;    int s4_c3=0; // 10
 int h5_c3=11;  int m5_c3=0;    int s5_c3=0; // 11.15
 int h6_c3=12;  int m6_c3=15;   int s6_c3=0; // 12.30
 int h7_c3=13;  int m7_c3=30;   int s7_c3=0; // 13.45
 int h8_c3=14;  int m8_c3=45;   int s8_c3=0; // 15
 int h9_c3=16;  int m9_c3=0;    int s9_c3=0;  // 16.15
 int h10_c3=17; int m10_c3=15;  int s10_c3=0;//17.30
 int h11_c3=18; int m11_c3=30;  int s11_c3=0;//18.45 
 //Horario encendido motoBomba 2 Noche
 int h12_c3=19; int m12_c3=0;   int s12_c3=0;
 int h13_c3=22; int m13_c3=10;   int s13_c3=0;
 int h14_c3=1; int m14_c3=20;   int s14_c3=0;
 int h15_c3=4; int m15_c3=30;   int s15_c3=0;
 int h16_c3=99; int m16_c3=0;   int s16_c3=0;

 //Horarios de APAGADO Bomba 2 de Riego 1
 int h1_c4=6;   int m1_c4=15;   int s1_c4=0;   //6.30
 int h2_c4=7;   int m2_c4=30;   int s2_c4=0;   //7.45
 int h3_c4=8;   int m3_c4=45;   int s3_c4=0;    //9
 int h4_c4=10;  int m4_c4=0;    int s4_c4=0;   // 10.15
 int h5_c4=11;  int m5_c4=15;   int s5_c4=0;   // 11.30
 int h6_c4=12;  int m6_c4=30;   int s6_c4=0;   //12.45
 int h7_c4=13;  int m7_c4=45;   int s7_c4=0;    //14
 int h8_c4=15;  int m8_c4=0;    int s8_c4=0;   //15.15
 int h9_c4=16;  int m9_c4=15;   int s9_c4=0;   //16.30
 int h10_c4=17; int m10_c4=30;  int s10_c4=0;  //17.45
 int h11_c4=18; int m11_c4=45;  int s11_c4=0;
 //Horario Noche Apagado Bomba 2
 int h12_c4=19; int m12_c4=10;   int s12_c4=0; //19:00-19:10
 int h13_c4=22; int m13_c4=20;   int s13_c4=0; 
 int h14_c4=1;  int m14_c4=30;   int s14_c4=0;
 int h15_c4=4; int m15_c4=40;    int s15_c4=0;
 int h16_c4=99; int m16_c4=0;    int s16_c4=0;

 //____________________________________________________Horario 2 con duracion de 10min de riego_____________________
//Horario para ENCENDIDO de Electrobomba 1 Riego Tipo 2 
 int h1_t1=6;  int m1_t1=0;  int s1_t1=0;    // 6:00
 int h2_t1=7;   int m2_t1=10;   int s2_t1=0; // 7:10
 int h3_t1=8;   int m3_t1=20;   int s3_t1=0; // 8:20
 int h4_t1=9;  int m4_t1=30;    int s4_t1=0; // 9:30
 int h5_t1=10;  int m5_t1=40;   int s5_t1=0; // 10:40
 int h6_t1=11;  int m6_t1=50;   int s6_t1=0; // 11:50
 int h7_t1=13;  int m7_t1=0;   int s7_t1=0;  // 13:00
 int h8_t1=14;  int m8_t1=10;    int s8_t1=0; //14:10
 int h9_t1=15;  int m9_t1=20;   int s9_t1=0; // 15:20
 int h10_t1=16; int m10_t1=30;  int s10_t1=0;// 16:30
 int h11_t1=17; int m11_t1=40;   int s11_t1=0; 
     //Horario encendido noche bomba 1 tipo 2 cada 15min
 int h12_t1=19; int m12_t1=0;   int s12_t1=0;
 int h13_t1=22; int m13_t1=15;   int s13_t1=0;
 int h14_t1=1; int m14_t1=30;   int s14_t1=0;
 int h15_t1=4; int m15_t1=45;   int s15_t1=0;
 int h16_t1=99; int m16_t1=0;   int s16_t1=0;

 //Horarios de APAGADO de Electrobomba 1 de Riego 2
 int h1_t2=6;   int m1_t2=10;   int s1_t2=0;   //6:10
 int h2_t2=7;   int m2_t2=20;   int s2_t2=0;   //7.45
 int h3_t2=8;   int m3_t2=30;   int s3_t2=0;   //9
 int h4_t2=9;   int m4_t2=40;   int s4_t2=0;   // 10.15
 int h5_t2=10;  int m5_t2=50;   int s5_t2=0;   // 11.30
 int h6_t2=12;  int m6_t2=0;    int s6_t2=0;   //12.45
 int h7_t2=13;  int m7_t2=10;   int s7_t2=0;    //14
 int h8_t2=14;  int m8_t2=20;   int s8_t2=0;   //15.15
 int h9_t2=15;  int m9_t2=30;   int s9_t2=0;   //16.30
 int h10_t2=16; int m10_t2=40;  int s10_t2=0;  //17.45
 int h11_t2=17; int m11_t2=50;  int s11_t2=0;
       //Horario Apagado noche bomba 1 tipo 2
 int h12_t2=19; int m12_t2=15;   int s12_t2=0;
 int h13_t2=22; int m13_t2=30;   int s13_t2=0;
 int h14_t2=1; int m14_t2=45;   int s14_t2=0;
 int h15_t2=5; int m15_t2=0;   int s15_t2=0;
 int h16_t2=99; int m16_t2=0;   int s16_t2=0;

// Horario Motobomba 2
//Horario para ENCENDIDO Electrobomba 2 de riego 2
 int h1_t3=6;  int m1_t3=0;  int s1_t3=0; // 6:15
 int h2_t3=7;   int m2_t3=10;   int s2_t3=0; // 7.30
 int h3_t3=8;   int m3_t3=20;   int s3_t3=0; // 8.45
 int h4_t3=9;  int m4_t3=30;    int s4_t3=0; // 10
 int h5_t3=10;  int m5_t3=40;   int s5_t3=0; // 11.15
 int h6_t3=11;  int m6_t3=50;   int s6_t3=0; // 12.30
 int h7_t3=13;  int m7_t3=0;   int s7_t3=0; // 13.45
 int h8_t3=14;  int m8_t3=10;    int s8_t3=0; // 15
 int h9_t3=15;  int m9_t3=20;   int s9_t3=0; // 16.15
 int h10_t3=16; int m10_t3=30;  int s10_t3=0;//17.30
 int h11_t3=17; int m11_t3=40;   int s11_t3=0; 
 //Horario encendido noche bomba 2 tipo 2 cada 10min
 int h12_t3=19; int m12_t3=0;   int s12_t3=0;
 int h13_t3=22; int m13_t3=15;   int s13_t3=0;
 int h14_t3=1; int m14_t3=30;   int s14_t3=0;
 int h15_t3=4; int m15_t3=45;   int s15_t3=0;
 int h16_t3=99; int m16_t3=0;   int s16_t3=0;

 //Horarios de APAGADO Motobomba 2 tipo de Riego 2
 int h1_t4=6;   int m1_t4=10;   int s1_t4=0;   //6:10
 int h2_t4=7;   int m2_t4=20;   int s2_t4=0;   //7.45
 int h3_t4=8;   int m3_t4=30;   int s3_t4=0;   //9
 int h4_t4=9;   int m4_t4=40;   int s4_t4=0;   // 10.15
 int h5_t4=10;  int m5_t4=50;   int s5_t4=0;   // 11.30
 int h6_t4=12;  int m6_t4=0;    int s6_t4=0;   //12.45
 int h7_t4=13;  int m7_t4=10;   int s7_t4=0;    //14
 int h8_t4=14;  int m8_t4=20;   int s8_t4=0;   //15.15
 int h9_t4=15;  int m9_t4=30;   int s9_t4=0;   //16.30
 int h10_t4=16; int m10_t4=40;  int s10_t4=0;  //17.45
 int h11_t4=17; int m11_t4=50;  int s11_t4=0;
  //Horario Apagado noche bomba 2 tipo 2
 int h12_t4=19; int m12_t4=15;   int s12_t4=0;
 int h13_t4=22; int m13_t4=30;   int s13_t4=0;
 int h14_t4=1; int m14_t4=45;   int s14_t4=0;
 int h15_t4=5; int m15_t4=0;   int s15_t4=0;
 int h16_t4=99; int m16_t4=0;   int s16_t4=0;

//_____________________________________Horario para ENCENDIDO de riego Tipo 3 duracion 20min_____________________________________________________ 
         // Horario Motobomba 1
 int h1_d1=6;   int m1_d1=0;    int s1_d1=0; // 6:00
 int h2_d1=7;   int m2_d1=20;   int s2_d1=0; // 7:20
 int h3_d1=8;   int m3_d1=40;   int s3_d1=0; // 8:40
 int h4_d1=10;  int m4_d1=0;    int s4_d1=0; // 10:00
 int h5_d1=11;  int m5_d1=20;   int s5_d1=0; // 11.15
 int h6_d1=12;  int m6_d1=40;   int s6_d1=0; // 12.30
 int h7_d1=14;  int m7_d1=0;    int s7_d1=0; // 13.45
 int h8_d1=15;  int m8_d1=20;   int s8_d1=0; // 15
 int h9_d1=16;  int m9_d1=40;   int s9_d1=0; // 16.15
 int h10_d1=18; int m10_d1=0;   int s10_d1=0;//17.30
 // horario Nocturno 3 Encendido Bomba 1 
 int h11_d1=19; int m11_d1=0;   int s11_d1=0; 
 int h12_d1=21; int m12_d1=10;   int s12_d1=0;
 int h13_d1=23; int m13_d1=20;   int s13_d1=0;
 int h14_d1=1; int m14_d1=40;   int s14_d1=0;
 int h15_d1=3; int m15_d1=50;   int s15_d1=0;
 int h16_d1=99; int m16_d1=0;   int s16_d1=0;

    //Horarios de APAGADO Motobomba 1
 int h1_d2=6;   int m1_d2=20;   int s1_d2=0;   //6.30
 int h2_d2=7;   int m2_d2=40;   int s2_d2=0;   //7.45
 int h3_d2=9;   int m3_d2=0;    int s3_d2=0;    //9
 int h4_d2=10;  int m4_d2=20;   int s4_d2=0;   // 10.15
 int h5_d2=11;  int m5_d2=40;   int s5_d2=0;   // 11.30
 int h6_d2=13;  int m6_d2=0;   int s6_d2=0;   //12.45
 int h7_d2=14;  int m7_d2=20;    int s7_d2=0;    //14
 int h8_d2=15;  int m8_d2=40;   int s8_d2=0;   //15.15
 int h9_d2=17;  int m9_d2=0;   int s9_d2=0;   //16.30
 int h10_d2=18; int m10_d2=20;  int s10_d2=0;  //17.45
 
        // Horario Nocturno APAGADO Motobomba 1
 int h11_d2=19; int m11_d2=10;  int s11_d2=0;
 int h12_d2=21; int m12_d2=20;   int s12_d2=0;
 int h13_d2=23; int m13_d2=40;   int s13_d2=0;
 int h14_d2=1;  int m14_d2=50;   int s14_d2=0;
 int h15_d2=4; int m15_d2=0;   int s15_d2=0;
 int h16_d2=99; int m16_d2=0;   int s16_d2=0;

//_______________ Horario Motobomba 2
//Horario para ENCENDIDO Motobomba 2 de riego 3
 int h1_d3=6;   int m1_d3=0;   int s1_d3=0; // 6:15
 int h2_d3=7;   int m2_d3=20;   int s2_d3=0; // 7.30
 int h3_d3=8;   int m3_d3=45;   int s3_d3=0; // 8.45
 int h4_d3=10;  int m4_d3=0;    int s4_d3=0; // 10
 int h5_d3=11;  int m5_d3=20;   int s5_d3=0; // 11.15
 int h6_d3=12;  int m6_d3=40;   int s6_d3=0; // 12.30
 int h7_d3=14;  int m7_d3=0;   int s7_d3=0; // 13.45
 int h8_d3=15;  int m8_d3=20;    int s8_d3=0; // 15
 int h9_d3=16;  int m9_d3=40;   int s9_d3=0; // 16.15
 int h10_d3=18; int m10_d3=0;  int s10_d3=0;//17.30
 // horario Nocturno 3 Encendido Bomba 2 
 int h11_d3=19; int m11_d3=0;   int s11_d3=0; 
 int h12_d3=21; int m12_d3=10;   int s12_d3=0;
 int h13_d3=23; int m13_d3=20;   int s13_d3=0;
 int h14_d3=1; int m14_d3=40;   int s14_d3=0;
 int h15_d3=3; int m15_d3=50;   int s15_d3=0;
 int h16_d3=99; int m16_d3=0;   int s16_d3=0;

 //Horarios de APAGADO Motobomba 2 de Riego 3
 int h1_d4=6;   int m1_d4=20;   int s1_d4=0;   //6.30
 int h2_d4=7;   int m2_d4=40;   int s2_d4=0;   //7.45
 int h3_d4=9;   int m3_d4=0;    int s3_d4=0;   //9
 int h4_d4=10;  int m4_d4=20;   int s4_d4=0;   // 10.15
 int h5_d4=11;  int m5_d4=40;   int s5_d4=0;   // 11.30
 int h6_d4=13;  int m6_d4=0;   int s6_d4=0;   //12.45
 int h7_d4=14;  int m7_d4=20;    int s7_d4=0;   //14
 int h8_d4=15;  int m8_d4=40;   int s8_d4=0;   //15.15
 int h9_d4=17;  int m9_d4=0;   int s9_d4=0;   //16.30
 int h10_d4=18; int m10_d4=20;  int s10_d4=0;  //17.45
        // Horario Nocturno APAGADO Motobomba 2
 int h11_d4=19; int m11_d4=10;  int s11_d4=0;
 int h12_d4=21; int m12_d4=20;   int s12_d4=0;
 int h13_d4=23; int m13_d4=40;   int s13_d4=0;
 int h14_d4=1;  int m14_d4=50;   int s14_d4=0;
 int h15_d4=4; int m15_d4=0;   int s15_d4=0;
 int h16_d4=99; int m16_d4=0;   int s16_d4=0;
#define Bomba1  16  // 16 = D0 Bomba 1 es para encender motobomba 
#define Bomba1Off  0  //0 = D3 Bomba 1 es para APAGAR motobomba 
#define IndicadorBomba 15//D8

//Definir como variables virtuales los interreptures de seleccionar tipo de riego
String contacto1;
String contacto1N;


//_____________________________

 int estadoMotor1;
 int estadoMotor2;
 int estadoMotor12;

//_____________________________

int contconexion = 0;

int posD;
int posN;
int posB;
int estB;
LiquidCrystal_I2C lcd(0x27, 16, 2);   //20=columnas 4= filas  

byte paralelo[] = {
  B01010,
  B01010,
  B01010,
  B01010,
  B01010,
  B01010,
  B01010,
  B01010
};

byte esquinaiz1[] = {
  B11111,
  B10000,
  B10000,
  B10000,
  B10000,
  B10000,
  B10000,
  B10000
};
byte esquinaiz2[] = {
  B10000,
  B10000,
  B10000,
  B10000,
  B10000,
  B10000,
  B10000,
  B11111
};
byte superior[] = {
  B11111,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
};
byte inferior[] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B11111
};
byte derecha1[] = {
  B11111,
  B00001,
  B00001,
  B00001,
  B00001,
  B00001,
  B00001,
  B00001
};
byte derecha2[] = {
  B00001,
  B00001,
  B00001,
  B00001,
  B00001,
  B00001,
  B00001,
  B11111
};

byte grados[] = { B00010, B00101, B00101, B00010, B00000, B00000, B00000, B00000};

void setup() {
  Serial.begin(9600);
  Wire.begin();
  lcd.init();                   
  lcd.backlight();
  Rtc.Begin();
  //RtcDateTime(__DATE__, __TIME__);

RtcDateTime compiled = RtcDateTime("May 16 2021","12:34:01");
//Rtc.SetDateTime(compiled);
//RtcDateTime now = Rtc.GetDateTime();

  // January 21, 2014 at 3am you would call:
//  Rtc.adjust(DateTime(2020, 25, 10, 9, 29, 20));
  // January 21, 2014 at 3am you would call:
//    rtc.adjust(DateTime(2020, 8, 8, 10, 43, 20));
InicioMenu(); 
 WiFiManager wifiManager;
       //wifiManager.resetSettings();
       wifiManager.setTimeout(10);
        lcd.setCursor(0,0);
        lcd.print("Conectando Wifi");
        delay(3000);
        if(wifiManager.autoConnect("AutoConnectAP")) {
         delay(3000);
         //reset and try again, or maybe put it to deep sleep
         // ESP.reset();
           delay(5000);
        }
 Serial.println("failed to connect and hit timeout");
   
          if (WiFi.status() != WL_CONNECTED){
             lcd.clear();
             lcd.setCursor(0,0 );
             lcd.print("Wiffi NO conectado");
             internet=false;
          }
          else{
          lcd.clear();
          lcd.setCursor(0,0 );
          lcd.print("Wiffi conectado");
          internet=true;
          }
          delay(1000);
          lcd.clear();


  //ThingSpeak.begin(client);  // Initialize ThingSpeak
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);

    ThreadSendFirebase->onRun(EnvioFirebase);
     ThreadSendFirebase->setInterval(3000);
  
    ThreadReciveFirebase->onRun(LecturaFirebase);
     ThreadReciveFirebase->setInterval(1200);


 ThreadRiego1->onRun(Tipo_Horario);                 // Sensor_Ph: funcion Lectura sensor de ph
   ThreadRiego1->setInterval(1000);
   
control1.add(ThreadRiego1);

 ThreadRiego2->onRun(Tipo_HorarioNocturno);                 // Sensor_Ph: funcion Lectura sensor de ph
   ThreadRiego2->setInterval(1000);
   control2.add(ThreadRiego2);

 ThreadPantalla->onRun(pantalla);
   ThreadPantalla->setInterval(700);
   control3.add(ThreadPantalla);
   
 //rtc.setDOW(SABADO);  // Configuracion de dia de la semana   
  //rtc.setTime(10, 44, 20);  // Configuracion de la hora
 // rtc.setDate(8, 8, 2020); // Configuracion de la fecha 
 pinMode(Bomba1,OUTPUT);
 pinMode(Bomba1Off,OUTPUT);
  pinMode(IndicadorBomba,OUTPUT);
  digitalWrite(IndicadorBomba, LOW);
 digitalWrite(Bomba1, LOW);
 digitalWrite(Bomba1Off, LOW);

}

void loop() {

Reloj();
RtcDateTime now = Rtc.GetDateTime();
lcdShowTime(now);
delay(100);
controlFirebase.run();
controlFirebase2.run();

control3.run();

if (internet==false){
RiegoB1=true;
posD = 1;
     posB = 1;
     posN = 1;
//posD = 1;
}
else{
    controlFirebase.run();
    controlFirebase2.run();
}
  if (RiegoB1==false)
  {
    lcd.setCursor(13,0); lcd.print("MAN");
             if (RiegoM==true)
              {
                                digitalWrite(Bomba1, HIGH);
                                digitalWrite(IndicadorBomba, HIGH);
                                
                Serial.println("Bomba encendida por firebase de forma manual");
              }
               if (RiegoM==false)
                {
                                digitalWrite(Bomba1, LOW);
                                digitalWrite(IndicadorBomba, LOW);
                Serial.println("Bomba Apagada por firebase de forma manual");
                }
  }
    else{
     lcd.setCursor(13,0); lcd.print("AUT");
    // Serial.println("Estoy en modo Automatico");
     posD = 1;
     posB = 1;
     posN = 1;
     control1.run();
      control2.run();
     //Serial.print("PosD =");Serial.print(posD);Serial.print(" PosB =");Serial.print(posB);Serial.print(" PosN =");Serial.println(posN);
    //Riego=true;
    }
// if ((T.hour>=h1_c1) &&(T.hour<=19))   { Paa verificar que me encuentro en la mañana realice el riego de mañana

//Serial.println(rtc.getTimeStr());
//else { HorarioNoche();
//}
}
 /*
if ( b>=1){                    
  activar_bomba1();
}
   else {
     apagarBomba1();
   }
if ( c>=1){
  activar_bomba2();
}
  else{
  apagarBomba2();
}
*/
