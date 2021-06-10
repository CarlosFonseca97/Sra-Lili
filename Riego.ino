void Reloj()
{
 // Serial.println("estoy en el Reloj");
   RtcDateTime now = Rtc.GetDateTime();
    //Serial.print(__DATE__);
    //Serial.println(__TIME__);
printDateTime(now);
}
#define countof(a) (sizeof(a) / sizeof(a[0]))

void lcdShowTime(const RtcDateTime& dt)
{
  char timestring[20];
  snprintf_P(timestring,
             countof(timestring),
             PSTR("%02u:%02u:%02u"),
             dt.Hour(),
             dt.Minute(),
             dt.Second() );             

  lcd.setCursor(2,1);
  lcd.print(timestring);
}
void Riego1(){
// b++ sirve para entrar al loop
 RtcDateTime now = Rtc.GetDateTime();
   if ((now.Hour()==h1_c1) && (now.Minute()==m1_c1) && (now.Second()>=0 && now.Second()<=5))   activar_bomba1(); 
   if ((now.Hour()==h2_c1) && (now.Minute()==m2_c1) && (now.Second()>=0 && now.Second()<=5))   activar_bomba1();
   if ((now.Hour()==h3_c1) && (now.Minute()==m3_c1) && (now.Second()>=0 && now.Second()<=5))   activar_bomba1();
   if ((now.Hour()==h4_c1) && (now.Minute()==m4_c1) && (now.Second()>=0 && now.Second()<=5))   activar_bomba1();    
   if ((now.Hour()==h5_c1) && (now.Minute()==m5_c1) && (now.Second()>=0 && now.Second()<=5))   activar_bomba1();
   if ((now.Hour()==h6_c1) && (now.Minute()==m6_c1) && (now.Second()>=0 && now.Second()<=5))   activar_bomba1();
   if ((now.Hour()==h7_c1) && (now.Minute()==m7_c1) && (now.Second()>=0 && now.Second()<=5))   activar_bomba1();
   if ((now.Hour()==h8_c1) && (now.Minute()==m8_c1) && (now.Second()>=0 && now.Second()<=5))   activar_bomba1();
   if ((now.Hour()==h9_c1) && (now.Minute()==m9_c1) && (now.Second()>=0 && now.Second()<=5))   activar_bomba1();
   if ((now.Hour()==h10_c1) && (now.Minute()==m10_c1) && (now.Second()>=0 && now.Second()<=5)) activar_bomba1();
   if ((now.Hour()==h11_c1) && (now.Minute()==m11_c1) && (now.Second()>=0 && now.Second()<=5)) activar_bomba1();
   ///////////////////////////////Apagar Bomba1///////////////////////
   if ((now.Hour()==h1_c2)  && (now.Minute()==m1_c2)  && (now.Second()>=0 && now.Second()<=5))   apagarBomba1();
   if ((now.Hour()==h2_c2)  && (now.Minute()==m2_c2)  && (now.Second()>=0 && now.Second()<=5))   apagarBomba1();
   if ((now.Hour()==h3_c2)  && (now.Minute()==m3_c2)  && (now.Second()>=0 && now.Second()<=5))   apagarBomba1();
   if ((now.Hour()==h4_c2)  && (now.Minute()==m4_c2)  && (now.Second()>=0 && now.Second()<=5))   apagarBomba1();
   if ((now.Hour()==h5_c2)  && (now.Minute()==m5_c2)  && (now.Second()>=0 && now.Second()<=5))   apagarBomba1(); 
   if ((now.Hour()==h6_c2)  && (now.Minute()==m6_c2)  && (now.Second()>=0 && now.Second()<=5))   apagarBomba1(); 
   if ((now.Hour()==h7_c2)  && (now.Minute()==m7_c2)  && (now.Second()>=0 && now.Second()<=5))   apagarBomba1();
   if ((now.Hour()==h8_c2)  && (now.Minute()==m8_c2)  && (now.Second()>=0 && now.Second()<=5))   apagarBomba1();
   if ((now.Hour()==h9_c2)  && (now.Minute()==m9_c2)  && (now.Second()>=0 && now.Second()<=5))   apagarBomba1();
   if ((now.Hour()==h10_c2) && (now.Minute()==m10_c2) && (now.Second()>=0 && now.Second()<=5))   apagarBomba1();
   if ((now.Hour()==h11_c2) && (now.Minute()==m11_c2) && (now.Second()>=0 && now.Second()<=5))   apagarBomba1();
   // El siguiente y ultimo horario pone las bombas apagadas, resetea los contadores ademas reescribe d para al otro dia volver a empezar */
   //Condicionales apagar bomba en horario de noche
  
}

void Riego1N(){
   RtcDateTime now = Rtc.GetDateTime();
   if ((now.Hour()==h12_c1) && (now.Minute()==m12_c1) && (now.Second()>=0 && now.Second()<=5))          activar_bomba1();
   if ((now.Hour()==h13_c1) && (now.Minute()==m13_c1) && (now.Second()>=0 && now.Second()<=5))          activar_bomba1();
   if ((now.Hour()==h14_c1) && (now.Minute()==m14_c1) && (now.Second()>=0 && now.Second()<=5))          activar_bomba1();
   if ((now.Hour()==h15_c1) && (now.Minute()==m15_c1) && (now.Second()>=0 && now.Second()<=5))          activar_bomba1();
   //if ((now.Hour()==h16_c1) && (now.Minute()==m16_c1) && (now.Second()>=0 && now.Second()>=2))          activar_bomba1();

   if ((now.Hour()==h12_c2) && (now.Minute()==m12_c2) && (now.Second()>=0 && now.Second()<=5))          apagarBomba1();
   if ((now.Hour()==h13_c2) && (now.Minute()==m13_c2) && (now.Second()>=0 && now.Second()<=5))          apagarBomba1();
   if ((now.Hour()==h14_c2) && (now.Minute()==m14_c2) && (now.Second()>=0 && now.Second()<=5))          apagarBomba1();
   if ((now.Hour()==h15_c2) && (now.Minute()==m15_c2) && (now.Second()>=0 && now.Second()<=5))          apagarBomba1();
   //if ((now.Hour()==h16_c2) && (now.Minute()==m16_c2) && (now.Second()>=0 && now.Second()>=2))          apagarBomba1();
}

void Riego1A(){
   RtcDateTime now = Rtc.GetDateTime();
// b++ sirve para entrar al loop
   if ((now.Hour()==h1_t1) && (now.Minute()==m1_t1) && (now.Second()>=0 && now.Second()>=2))   activar_bomba1(); 
   if ((now.Hour()==h2_t1) && (now.Minute()==m2_t1) && (now.Second()>=0 && now.Second()>=2))   activar_bomba1();
   if ((now.Hour()==h3_t1) && (now.Minute()==m3_t1) && (now.Second()>=0 && now.Second()>=2))   activar_bomba1();
   if ((now.Hour()==h4_t1) && (now.Minute()==m4_t1) && (now.Second()>=0 && now.Second()>=2))   activar_bomba1();    
   if ((now.Hour()==h5_t1) && (now.Minute()==m5_t1) && (now.Second()>=0 && now.Second()>=2))   activar_bomba1();
   if ((now.Hour()==h6_t1) && (now.Minute()==m6_t1) && (now.Second()>=0 && now.Second()>=2))   activar_bomba1();
   if ((now.Hour()==h7_t1) && (now.Minute()==m7_t1) && (now.Second()>=0 && now.Second()>=2))   activar_bomba1();
   if ((now.Hour()==h8_t1) && (now.Minute()==m8_t1) && (now.Second()>=0 && now.Second()>=2))   activar_bomba1();
   if ((now.Hour()==h9_t1) && (now.Minute()==m9_t1) && (now.Second()>=0 && now.Second()>=2))   activar_bomba1();
   if ((now.Hour()==h10_t1) && (now.Minute()==m10_t1) && (now.Second()>=0 && now.Second()>=2)) activar_bomba1();
   if ((now.Hour()==h11_t1) && (now.Minute()==m11_t1) && (now.Second()>=0 && now.Second()>=2)) activar_bomba1();
   ///////////////////////////////Apagar Bomba1///////////////////////
   if ((now.Hour()==h1_t2)  && (now.Minute()==m1_t2)  && (now.Second()>=0 && now.Second()>=2))   apagarBomba1();
   if ((now.Hour()==h2_t2)  && (now.Minute()==m2_t2)  && (now.Second()>=0 && now.Second()>=2))   apagarBomba1();
   if ((now.Hour()==h3_t2)  && (now.Minute()==m3_t2)  && (now.Second()>=0 && now.Second()>=2))   apagarBomba1();
   if ((now.Hour()==h4_t2)  && (now.Minute()==m4_t2)  && (now.Second()>=0 && now.Second()>=2))   apagarBomba1();
   if ((now.Hour()==h5_t2)  && (now.Minute()==m5_t2)  && (now.Second()>=0 && now.Second()>=2))   apagarBomba1(); 
   if ((now.Hour()==h6_t2)  && (now.Minute()==m6_t2)  && (now.Second()>=0 && now.Second()>=2))   apagarBomba1(); 
   if ((now.Hour()==h7_t2)  && (now.Minute()==m7_t2)  && (now.Second()>=0 && now.Second()>=2))   apagarBomba1();
   if ((now.Hour()==h8_t2)  && (now.Minute()==m8_t2)  && (now.Second()>=0 && now.Second()>=2))   apagarBomba1();
   if ((now.Hour()==h9_t2)  && (now.Minute()==m9_t2)  && (now.Second()>=0 && now.Second()>=2))   apagarBomba1();
   if ((now.Hour()==h10_t2) && (now.Minute()==m10_t2) && (now.Second()>=0 && now.Second()>=5))   apagarBomba1();
   if ((now.Hour()==h11_t2) && (now.Minute()==m11_t2) && (now.Second()>=0 && now.Second()>=5))   apagarBomba1();
}

void Riego1AN(){
   RtcDateTime now = Rtc.GetDateTime();
   if ((now.Hour()==h12_t1) && (now.Minute()==m12_t1) && (now.Second()>=0 && now.Second()>=2))          activar_bomba1();
   if ((now.Hour()==h13_t1) && (now.Minute()==m13_t1) && (now.Second()>=0 && now.Second()>=2))          activar_bomba1();
   if ((now.Hour()==h14_t1) && (now.Minute()==m14_t1) && (now.Second()>=0 && now.Second()>=2))          activar_bomba1();
   if ((now.Hour()==h15_t1) && (now.Minute()==m15_t1) && (now.Second()>=0 && now.Second()>=2))          activar_bomba1();
   //if ((now.Hour()==h16_t1) && (now.Minute()==m16_t1) && (now.Second()>=0 && now.Second()>=2))          activar_bomba1();

   if ((now.Hour()==h12_t2) && (now.Minute()==m12_t2) && (now.Second()==s12_t2))          apagarBomba1();
   if ((now.Hour()==h13_t2) && (now.Minute()==m13_t2) && (now.Second()==s13_t2))          apagarBomba1();
   if ((now.Hour()==h14_t2) && (now.Minute()==m14_t2) && (now.Second()==s14_t2))          apagarBomba1();
   if ((now.Hour()==h15_t2) && (now.Minute()==m15_t2) && (now.Second()==s15_t2))          apagarBomba1();
  // if ((now.Hour()==h16_t2) && (now.Minute()==m16_t2) && (now.Second()==s16_t2))          apagarBomba1();
}

void Riego1B(){
   RtcDateTime now = Rtc.GetDateTime();
// b++ sirve para entrar al loop
   if ((now.Hour()==h1_d1) && (now.Minute()==m1_d1) && (now.Second()>=0 && now.Second()>=2))   activar_bomba1(); 
   if ((now.Hour()==h2_d1) && (now.Minute()==m2_d1) && (now.Second()>=0 && now.Second()>=2))   activar_bomba1();
   if ((now.Hour()==h3_d1) && (now.Minute()==m3_d1) && (now.Second()>=0 && now.Second()>=2))   activar_bomba1();
   if ((now.Hour()==h4_d1) && (now.Minute()==m4_d1) && (now.Second()>=0 && now.Second()>=2))   activar_bomba1();    
   if ((now.Hour()==h5_d1) && (now.Minute()==m5_d1) && (now.Second()>=0 && now.Second()>=2))   activar_bomba1();
   if ((now.Hour()==h6_d1) && (now.Minute()==m6_d1) && (now.Second()>=0 && now.Second()>=2))   activar_bomba1();
   if ((now.Hour()==h7_d1) && (now.Minute()==m7_d1) && (now.Second()>=0 && now.Second()>=2))   activar_bomba1();
   if ((now.Hour()==h8_d1) && (now.Minute()==m8_d1) && (now.Second()>=0 && now.Second()>=2))   activar_bomba1();
   if ((now.Hour()==h9_d1) && (now.Minute()==m9_d1) && (now.Second()>=0 && now.Second()>=2))   activar_bomba1();
   if ((now.Hour()==h10_d1) && (now.Minute()==m10_d1) && (now.Second()>=0 && now.Second()>=2)) activar_bomba1();
   
   ///////////////////////////////Apagar Bomba1///////////////////////
   if ((now.Hour()==h1_d2)  && (now.Minute()==m1_d2)  && (now.Second()>=0 && now.Second()>=2))   apagarBomba1();
   if ((now.Hour()==h2_d2)  && (now.Minute()==m2_d2)  && (now.Second()>=0 && now.Second()>=2))   apagarBomba1();
   if ((now.Hour()==h3_d2)  && (now.Minute()==m3_d2)  && (now.Second()>=0 && now.Second()>=2))   apagarBomba1();
   if ((now.Hour()==h4_d2)  && (now.Minute()==m4_d2)  && (now.Second()>=0 && now.Second()>=2))   apagarBomba1();
   if ((now.Hour()==h5_d2)  && (now.Minute()==m5_d2)  && (now.Second()>=0 && now.Second()>=2))   apagarBomba1(); 
   if ((now.Hour()==h6_d2)  && (now.Minute()==m6_d2)  && (now.Second()>=0 && now.Second()>=2))   apagarBomba1(); 
   if ((now.Hour()==h7_d2)  && (now.Minute()==m7_d2)  && (now.Second()>=0 && now.Second()>=2))   apagarBomba1();
   if ((now.Hour()==h8_d2)  && (now.Minute()==m8_d2)  && (now.Second()>=0 && now.Second()>=2))   apagarBomba1();
   if ((now.Hour()==h9_d2)  && (now.Minute()==m9_d2)  && (now.Second()>=0 && now.Second()>=2))   apagarBomba1();
   if ((now.Hour()==h10_d2) && (now.Minute()==m10_d2) && (now.Second()>=0 && now.Second()>=5))   apagarBomba1();

}
void Riego1BN(){
   RtcDateTime now = Rtc.GetDateTime();
   if ((now.Hour()==h11_d1) && (now.Minute()==m11_d1) && (now.Second()>=0 && now.Second()>=2))          activar_bomba1();
   if ((now.Hour()==h12_d1) && (now.Minute()==m12_d1) && (now.Second()>=0 && now.Second()>=2))          activar_bomba1();
   if ((now.Hour()==h13_d1) && (now.Minute()==m13_d1) && (now.Second()>=0 && now.Second()>=2))          activar_bomba1();
   if ((now.Hour()==h14_d1) && (now.Minute()==m14_d1) && (now.Second()>=0 && now.Second()>=2))          activar_bomba1();
   if ((now.Hour()==h15_d1) && (now.Minute()==m15_d1) && (now.Second()>=0 && now.Second()>=2))          activar_bomba1();
   //if ((now.Hour()==h16_d1) && (now.Minute()==m16_d1) && (now.Second()>=0 && now.Second()>=2))          activar_bomba1();

   if ((now.Hour()==h11_d2) && (now.Minute()==m11_d2) && (now.Second()>=0 && now.Second()>=2))          apagarBomba1();
   if ((now.Hour()==h12_d2) && (now.Minute()==m12_d2) && (now.Second()>=0 && now.Second()>=2))          apagarBomba1();
   if ((now.Hour()==h13_d2) && (now.Minute()==m13_d2) && (now.Second()>=0 && now.Second()>=2))          apagarBomba1();
   if ((now.Hour()==h14_d2) && (now.Minute()==m14_d2) && (now.Second()>=0 && now.Second()>=2))          apagarBomba1();
   if ((now.Hour()==h15_d2) && (now.Minute()==m15_d2) && (now.Second()>=0 && now.Second()>=2))          apagarBomba1();
   //if ((now.Hour()==h16_d2) && (now.Minute()==m16_d2) && (now.Second()>=0 && now.Second()>=2))          apagarBomba1();
}

void activar_bomba1(){
  Serial.println("Bomba 1 encendida");
    lcd.setCursor(13,1);
    lcd.print("nB1");
  digitalWrite(Bomba1Off, LOW);
  //delay(1000);
  digitalWrite(Bomba1, HIGH); 
  delay(5000);
  digitalWrite(Bomba1, LOW);
  estB=1;
}

void apagarBomba1(){
b=0;
  Serial.println("Bomba 1 apagada");
  lcd.setCursor(13,1);
    lcd.print("oB1");
//  digitalWrite(Bomba1, LOW);
  digitalWrite(Bomba1Off, HIGH);
 // digitalWrite(Bomba1Off, LOW);
}

void Tipo_Horario(){

   if (posD == 1) {   // Si el contacto 1 esta activo (Horario 1)  
      if (posB == 1)
      {
        // Serial.print("Tipo de Horario"); Serial.print("Horario 1"); Serial.println("Bomba 1 Activa");
          Riego1();  
      } 
       if (posB == 2)
      {
         Serial.print("Tipo de Horario"); Serial.print("Horario 1"); Serial.println("Bomba 2 Activa");
         // Riego2();  
      } 
         if (posB == 3)
      {
          Riego1();           // llama a la funcion que activa el horario 1
         // Riego2();
          Serial.print("Tipo de Horario"); Serial.print("Horario 1"); Serial.println("Bomba 1 y 2 Activas");
      }
   }

    if (posD == 2) {   // Si el contacto 1 esta activo (Horario 1)  
      if (posB == 1)
      {
         Serial.print("Tipo de Horario"); Serial.print("Horario 2"); Serial.println("Bomba 1 Activa");
          Riego1A();
      } 
       if (posB == 2)
      {
         Serial.print("Tipo de Horario"); Serial.print("Horario 2"); Serial.println("Bomba 2 Activa");
         // Riego2A(); 
      } 
         if (posB == 3)
      {
          Riego1A();           // llama a la funcion que activa el horario 1
         // Riego2A();
          Serial.print("Tipo de Horario"); Serial.print("Horario 2"); Serial.println("Bomba 1 y 2 Activas");
      }
   }

       if (posD == 3) {   // Si el contacto 1 esta activo (Horario 1)  
        if (posB == 1)
      {
         Serial.print("Tipo de Horario"); Serial.print("Horario 3"); Serial.println("Bomba 1 Activa");
          Riego1B();
      } 
       if (posB == 2)
      {
         Serial.print("Tipo de Horario"); Serial.print("Horario 3"); Serial.println("Bomba 2 Activa");
         // Riego2B(); 
      } 
         if (posB == 3)
      {

          Riego1B();           // llama a la funcion que activa el horario 1
         // Riego2B();
          Serial.print("Tipo de Horario"); Serial.print("Horario 3"); Serial.println("Bomba 1 y 2 Activas");
      }
   }
}

void Tipo_HorarioNocturno(){ //Empezar este control despues de las 6:00 pm
  
       if (posN == 1) {   // Si el contacto 1 esta activo (Horario 1)  
        if (posB == 1)
      {
        // Serial.print("Tipo de Horario"); Serial.print("Horario N 1"); Serial.println("Bomba 1 Activa");
          Riego1N();
      } 
       if (posB == 2)
      {
         Serial.print("Tipo de Horario"); Serial.print("Horario N 1"); Serial.println("Bomba 2 Activa");
         // Riego2N(); 
      } 
         if (posB == 3)
      {
          Riego1N();           // llama a la funcion que activa el horario 1
         // Riego2N();
          Serial.print("Tipo de Horario"); Serial.print("Horario N 1"); Serial.println("Bomba 1 y 2 Activas");
      }
   }

       if (posN == 2) {   // Si el contacto 1 esta activo (Horario 1)  
        if (posB == 1)
      {
         Serial.print("Tipo de Horario"); Serial.print("Horario N 2"); Serial.println("Bomba 1 Activa");
          Riego1AN();
      } 
       if (posB == 2)
      {
         Serial.print("Tipo de Horario"); Serial.print("Horario N 2"); Serial.println("Bomba 2 Activa");
        //  Riego2AN(); 
      } 
         if (posB == 3)
      {
          Riego1AN();           // llama a la funcion que activa el horario 1
         // Riego2AN();
          Serial.print("Tipo de Horario"); Serial.print("Horario N 2"); Serial.println("Bomba 1 y 2 Activas");
      }
   }

  if (posN == 3) {   // Si el contacto 1 esta activo (Horario 1)  
        if (posB == 1)
      {
         Serial.print("Tipo de Horario"); Serial.print("Horario N 3"); Serial.println("Bomba 1 Activa");
          Riego1BN();
      } 
       if (posB == 2)
      {
         Serial.print("Tipo de Horario"); Serial.print("Horario N 3"); Serial.println("Bomba 2 Activa");
        //  Riego2BN(); 
      } 
         if (posB == 3)
      {
          Riego1BN();           // llama a la funcion que activa el horario 1
         // Riego2BN();
          Serial.print("Tipo de Horario"); Serial.print("Horario N 3"); Serial.println("Bomba 1 y 2 Activas");
      }
   }
}
void printDateTime(const RtcDateTime& dt)
{
    char datestring[20];

    snprintf_P(datestring, 
            countof(datestring),
            PSTR("%02u/%02u/%04u %02u:%02u:%02u"),
            dt.Month(),
            dt.Day(),
            dt.Year(),
            dt.Hour(),
            dt.Minute(),
            dt.Second() );
    Serial.print(datestring);
}
//------------------------------------ Riego 2 (Segunda Bomba) ----------------------------------------------------
/*
void Riego2(){
   RtcDateTime now = Rtc.GetDateTime();
// b++ sirve para entrar al loop
   if ((now.Hour()==h1_c3) && (now.Minute()==m1_c3) && (now.Second()>=0 && now.Second()>=2))   activar_bomba2(); 
   if ((now.Hour()==h2_c3) && (now.Minute()==m2_c3) && (now.Second()>=0 && now.Second()>=2))   activar_bomba2();
   if ((now.Hour()==h3_c3) && (now.Minute()==m3_c3) && (now.Second()>=0 && now.Second()>=2))   activar_bomba2();
   if ((now.Hour()==h4_c3) && (now.Minute()==m4_c3) && (now.Second()>=0 && now.Second()>=2))   activar_bomba2();    
   if ((now.Hour()==h5_c3) && (now.Minute()==m5_c3) && (now.Second()>=0 && now.Second()>=2))   activar_bomba2();
   if ((now.Hour()==h6_c3) && (now.Minute()==m6_c3) && (now.Second()>=0 && now.Second()>=2))   activar_bomba2();
   if ((now.Hour()==h7_c3) && (now.Minute()==m7_c3) && (now.Second()>=0 && now.Second()>=2))   activar_bomba2();
   if ((now.Hour()==h8_c3) && (now.Minute()==m8_c3) && (now.Second()>=0 && now.Second()>=2))   activar_bomba2();
   if ((now.Hour()==h9_c3) && (now.Minute()==m9_c3) && (now.Second()>=0 && now.Second()>=2))   activar_bomba2();
   if ((now.Hour()==h10_c3) && (now.Minute()==m10_c3) && (now.Second()>=0 && now.Second()>=2)) activar_bomba2();
   if ((now.Hour()==h11_c3) && (now.Minute()==m11_c3) && (now.Second()>=0 && now.Second()>=2)) activar_bomba2();
   ///////////////////////////////Apagar Bomba1///////////////////////
   if ((now.Hour()==h1_c4)  && (now.Minute()==m1_c4)  && (now.Second()>=0 && now.Second()>=2))   apagarBomba2();
   if ((now.Hour()==h2_c4)  && (now.Minute()==m2_c4)  && (now.Second()>=0 && now.Second()>=2))   apagarBomba2();
   if ((now.Hour()==h3_c4)  && (now.Minute()==m3_c4)  && (now.Second()>=0 && now.Second()>=2))   apagarBomba2();
   if ((now.Hour()==h4_c4)  && (now.Minute()==m4_c4)  && (now.Second()>=0 && now.Second()>=2))   apagarBomba2();
   if ((now.Hour()==h5_c4)  && (now.Minute()==m5_c4)  && (now.Second()>=0 && now.Second()>=2))   apagarBomba2(); 
   if ((now.Hour()==h6_c4)  && (now.Minute()==m6_c4)  && (now.Second()>=0 && now.Second()>=2))   apagarBomba2(); 
   if ((now.Hour()==h7_c4)  && (now.Minute()==m7_c4)  && (now.Second()>=0 && now.Second()>=2))   apagarBomba2();
   if ((now.Hour()==h8_c4)  && (now.Minute()==m8_c4)  && (now.Second()>=0 && now.Second()>=2))   apagarBomba2();
   if ((now.Hour()==h9_c4)  && (now.Minute()==m9_c4)  && (now.Second()>=0 && now.Second()>=2))   apagarBomba2();
   if ((now.Hour()==h10_c4) && (now.Minute()==m10_c4) && (now.Second()>=0 && now.Second()>=5))   apagarBomba2();
   if ((now.Hour()==h11_c4) && (now.Minute()==m11_c4) && (now.Second()>=0 && now.Second()>=5))   apagarBomba2();
}

void Riego2N(){
   RtcDateTime now = Rtc.GetDateTime();
   if ((now.Hour()==h12_c3) && (now.Minute()==m12_c3) && (now.Second()>=0 && now.Second()>=2))          activar_bomba1();
   if ((now.Hour()==h13_c3) && (now.Minute()==m13_c3) && (now.Second()>=0 && now.Second()>=2))          activar_bomba1();
   if ((now.Hour()==h14_c3) && (now.Minute()==m14_c3) && (now.Second()>=0 && now.Second()>=2))          activar_bomba1();
   if ((now.Hour()==h15_c3) && (now.Minute()==m15_c3) && (now.Second()>=0 && now.Second()>=2))          activar_bomba1();
  // if ((now.Hour()==h16_c3) && (now.Minute()==m16_c3) && (now.Second()>=0 && now.Second()>=2))          activar_bomba1();

   if ((now.Hour()==h12_c4) && (now.Minute()==m12_c4) && (now.Second()==s12_c4))          apagarBomba2();
   if ((now.Hour()==h13_c4) && (now.Minute()==m13_c4) && (now.Second()==s13_c4))          apagarBomba2();
   if ((now.Hour()==h14_c4) && (now.Minute()==m14_c4) && (now.Second()==s14_c4))          apagarBomba2();
   if ((now.Hour()==h15_c4) && (now.Minute()==m15_c4) && (now.Second()==s15_c4))          apagarBomba2();
 //  if ((now.Hour()==h16_c4) && (now.Minute()==m16_c4) && (now.Second()==s16_c4))          apagarBomba2();
}

void Riego2A(){
   RtcDateTime now = Rtc.GetDateTime();
// b++ sirve para entrar al loop
   if ((now.Hour()==h1_t3) && (now.Minute()==m1_t3) && (now.Second()>=0 && now.Second()>=2))   activar_bomba2(); 
   if ((now.Hour()==h2_t3) && (now.Minute()==m2_t3) && (now.Second()>=0 && now.Second()>=2))   activar_bomba2();
   if ((now.Hour()==h3_t3) && (now.Minute()==m3_t3) && (now.Second()>=0 && now.Second()>=2))   activar_bomba2();
   if ((now.Hour()==h4_t3) && (now.Minute()==m4_t3) && (now.Second()>=0 && now.Second()>=2))   activar_bomba2();    
   if ((now.Hour()==h5_t3) && (now.Minute()==m5_t3) && (now.Second()>=0 && now.Second()>=2))   activar_bomba2();
   if ((now.Hour()==h6_t3) && (now.Minute()==m6_t3) && (now.Second()>=0 && now.Second()>=2))   activar_bomba2();
   if ((now.Hour()==h7_t3) && (now.Minute()==m7_t3) && (now.Second()>=0 && now.Second()>=2))   activar_bomba2();
   if ((now.Hour()==h8_t3) && (now.Minute()==m8_t3) && (now.Second()>=0 && now.Second()>=2))   activar_bomba2();
   if ((now.Hour()==h9_t3) && (now.Minute()==m9_t3) && (now.Second()>=0 && now.Second()>=2))   activar_bomba2();
   if ((now.Hour()==h10_t3) && (now.Minute()==m10_t3) && (now.Second()>=0 && now.Second()>=2)) activar_bomba2();
   ///////////////////////////////Apagar Bomba1///////////////////////
   if ((now.Hour()==h1_t4)  && (now.Minute()==m1_t4)  && (now.Second()>=0 && now.Second()>=2))   apagarBomba2();
   if ((now.Hour()==h2_t4)  && (now.Minute()==m2_t4)  && (now.Second()>=0 && now.Second()>=2))   apagarBomba2();
   if ((now.Hour()==h3_t4)  && (now.Minute()==m3_t4)  && (now.Second()>=0 && now.Second()>=2))   apagarBomba2();
   if ((now.Hour()==h4_t4)  && (now.Minute()==m4_t4)  && (now.Second()>=0 && now.Second()>=2))   apagarBomba2();
   if ((now.Hour()==h5_t4)  && (now.Minute()==m5_t4)  && (now.Second()>=0 && now.Second()>=2))   apagarBomba2(); 
   if ((now.Hour()==h6_t4)  && (now.Minute()==m6_t4)  && (now.Second()>=0 && now.Second()>=2))   apagarBomba2(); 
   if ((now.Hour()==h7_t4)  && (now.Minute()==m7_t4)  && (now.Second()>=0 && now.Second()>=2))   apagarBomba2();
   if ((now.Hour()==h8_t4)  && (now.Minute()==m8_t4)  && (now.Second()>=0 && now.Second()>=2))   apagarBomba2();
   if ((now.Hour()==h9_t4)  && (now.Minute()==m9_t4)  && (now.Second()>=0 && now.Second()>=2))   apagarBomba2();
   if ((now.Hour()==h10_t4) && (now.Minute()==m10_t4) && (now.Second()>=0 && now.Second()>=5))   apagarBomba2();
   if ((now.Hour()==h11_t4) && (now.Minute()==m11_t4) && (now.Second()>=0 && now.Second()>=5))   apagarBomba2();
}

void Riego2AN(){
   RtcDateTime now = Rtc.GetDateTime();
   if ((now.Hour()==h12_t3) && (now.Minute()==m12_t3) && (now.Second()>=0 && now.Second()>=2))          activar_bomba1();
   if ((now.Hour()==h13_t3) && (now.Minute()==m13_t3) && (now.Second()>=0 && now.Second()>=2))          activar_bomba1();
   if ((now.Hour()==h14_t3) && (now.Minute()==m14_t3) && (now.Second()>=0 && now.Second()>=2))          activar_bomba1();
   if ((now.Hour()==h15_t3) && (now.Minute()==m15_t3) && (now.Second()>=0 && now.Second()>=2))          activar_bomba1();
   //if ((now.Hour()==h16_t3) && (now.Minute()==m16_t3) && (now.Second()>=0 && now.Second()>=2))          activar_bomba1();

   if ((now.Hour()==h12_t4) && (now.Minute()==m12_t4) && (now.Second()>=0 && now.Second()>=2))          apagarBomba1();
   if ((now.Hour()==h13_t4) && (now.Minute()==m13_t4) && (now.Second()>=0 && now.Second()>=2))          apagarBomba1();
   if ((now.Hour()==h14_t4) && (now.Minute()==m14_t4) && (now.Second()>=0 && now.Second()>=2))          apagarBomba1();
   if ((now.Hour()==h15_t4) && (now.Minute()==m15_t4) && (now.Second()>=0 && now.Second()>=2))          apagarBomba1();
  // if ((now.Hour()==h16_t4) && (now.Minute()==m16_t4) && (now.Second()>=0 && now.Second()>=2))          apagarBomba1();
}

void Riego2B(){
   RtcDateTime now = Rtc.GetDateTime();
// b++ sirve para entrar al loop
   if ((now.Hour()==h1_d3) && (now.Minute()==m1_d3) && (now.Second()>=0 && now.Second()>=2))   activar_bomba2(); 
   if ((now.Hour()==h2_d3) && (now.Minute()==m2_d3) && (now.Second()>=0 && now.Second()>=2))   activar_bomba2();
   if ((now.Hour()==h3_d3) && (now.Minute()==m3_d3) && (now.Second()>=0 && now.Second()>=2))   activar_bomba2();
   if ((now.Hour()==h4_d3) && (now.Minute()==m4_d3) && (now.Second()>=0 && now.Second()>=2))   activar_bomba2();    
   if ((now.Hour()==h5_d3) && (now.Minute()==m5_d3) && (now.Second()>=0 && now.Second()>=2))   activar_bomba2();
   if ((now.Hour()==h6_d3) && (now.Minute()==m6_d3) && (now.Second()>=0 && now.Second()>=2))   activar_bomba2();
   if ((now.Hour()==h7_d3) && (now.Minute()==m7_d3) && (now.Second()>=0 && now.Second()>=2))   activar_bomba2();
   if ((now.Hour()==h8_d3) && (now.Minute()==m8_d3) && (now.Second()>=0 && now.Second()>=2))   activar_bomba2();
   if ((now.Hour()==h9_d3) && (now.Minute()==m9_d3) && (now.Second()>=0 && now.Second()>=2))   activar_bomba2();
   if ((now.Hour()==h10_d3) && (now.Minute()==m10_d3) && (now.Second()>=0 && now.Second()>=2)) activar_bomba2();
   ///////////////////////////////Apagar Bomba1///////////////////////
   if ((now.Hour()==h1_d4)  && (now.Minute()==m1_d4)  && (now.Second()>=0 && now.Second()>=2))   apagarBomba2();
   if ((now.Hour()==h2_d4)  && (now.Minute()==m2_d4)  && (now.Second()>=0 && now.Second()>=2))   apagarBomba2();
   if ((now.Hour()==h3_d4)  && (now.Minute()==m3_d4)  && (now.Second()>=0 && now.Second()>=2))   apagarBomba2();
   if ((now.Hour()==h4_d4)  && (now.Minute()==m4_d4)  && (now.Second()>=0 && now.Second()>=2))   apagarBomba2();
   if ((now.Hour()==h5_d4)  && (now.Minute()==m5_d4)  && (now.Second()>=0 && now.Second()>=2))   apagarBomba2(); 
   if ((now.Hour()==h6_d4)  && (now.Minute()==m6_d4)  && (now.Second()>=0 && now.Second()>=2))   apagarBomba2(); 
   if ((now.Hour()==h7_d4)  && (now.Minute()==m7_d4)  && (now.Second()>=0 && now.Second()>=2))   apagarBomba2();
   if ((now.Hour()==h8_d4)  && (now.Minute()==m8_d4)  && (now.Second()>=0 && now.Second()>=2))   apagarBomba2();
   if ((now.Hour()==h9_d4)  && (now.Minute()==m9_d4)  && (now.Second()>=0 && now.Second()>=2))   apagarBomba2();
   if ((now.Hour()==h10_d4) && (now.Minute()==m10_d4) && (now.Second()>=0 && now.Second()>=5))   apagarBomba2();
}
void Riego2BN(){
   RtcDateTime now = Rtc.GetDateTime();
   if ((now.Hour()==h11_d3) && (now.Minute()==m11_d3) && (now.Second()>=0 && now.Second()>=2))          activar_bomba1();
   if ((now.Hour()==h12_d3) && (now.Minute()==m12_d3) && (now.Second()>=0 && now.Second()>=2))          activar_bomba1();
   if ((now.Hour()==h13_d3) && (now.Minute()==m13_d3) && (now.Second()>=0 && now.Second()>=2))          activar_bomba1();
   if ((now.Hour()==h14_d3) && (now.Minute()==m14_d3) && (now.Second()>=0 && now.Second()>=2))          activar_bomba1();
   if ((now.Hour()==h15_d3) && (now.Minute()==m15_d3) && (now.Second()>=0 && now.Second()>=2))          activar_bomba1();
   //if ((now.Hour()==h16_d1) && (now.Minute()==m16_d1) && (now.Second()>=0 && now.Second()>=2))          activar_bomba1();

   if ((now.Hour()==h11_d4) && (now.Minute()==m11_d4) && (now.Second()>=0 && now.Second()>=2))          apagarBomba1();
   if ((now.Hour()==h12_d4) && (now.Minute()==m12_d4) && (now.Second()>=0 && now.Second()>=2))          apagarBomba1();
   if ((now.Hour()==h13_d4) && (now.Minute()==m13_d4) && (now.Second()>=0 && now.Second()>=2))          apagarBomba1();
   if ((now.Hour()==h14_d4) && (now.Minute()==m14_d4) && (now.Second()>=0 && now.Second()>=2))          apagarBomba1();
   if ((now.Hour()==h15_d4) && (now.Minute()==m15_d4) && (now.Second()>=0 && now.Second()>=2))          apagarBomba1();
   //if ((now.Hour()==h16_d4) && (now.Minute()==m16_d4) && (now.Second()>=0 && now.Second()>=2))          apagarBomba1();
}

void activar_bomba2(){
  Serial.println("Bomba 2 encendida");
  digitalWrite(Bomba2Off, HIGH);
  delay(1000);
  digitalWrite(Bomba2, HIGH); 
  delay(5000);
  digitalWrite(Bomba2, LOW);
  estB=2;
}

void apagarBomba2(){
c=0;
  Serial.println("Bomba 2 apagada");
      digitalWrite(Bomba2Off, LOW);
      //delay(2000);
     // digitalWrite(Bomba2Off, LOW);
}
*/
