void EnvioFirebase(){
  Serial.println("Estoy en la funcion envio a firebase");
  String path = "/Variables de Cultivo Hidroponico";
   
    String path2 = "/Tipo de Alarma";
     String path3 ="/Estado de Alarma";
     String path4 ="/Tipo de Riego";

     
      if (Firebase.setString(firebaseData,path2+"/Tipo de Alarma","Ninguna"))
    {
      Serial.print("Tipo de alarma Enviada");
    }
      
    if (Firebase.setFloat(firebaseData,path3+"/Alarma",20))
    {
      Serial.print("Estado de alarma Enviada");
    }   
    if (Firebase.setFloat(firebaseData,path+"/Temperatura Ambiente",20))
    {
      Serial.print("Temperatura Enviada");
    }
    if (Firebase.setFloat(firebaseData,path+"/Humedad Ambiente",70))
    {
      Serial.print("Humedad Enviada");
    }
    if (Firebase.setFloat(firebaseData,path+"/Ph",50))
    {
      Serial.println("Ph Enviada");
    }
}

void LecturaFirebase(){
  String path1 = "/Activar - Desactivar Actuadores";
  String path0 = "/ADMINISTRADOR";
  String path10 = "/OPERARIO";
  String path11 = "HORARIO";
    if (Firebase.setString(firebaseData,path1+"/ESTADO BOMBA 1","1"))
    {
      Serial.print("Tipo de alarma Enviada");
    }
    if (Firebase.setString(firebaseData,path1+"/Activar Desactivar Bomba 1",""))
    {
      Serial.print("Tipo de alarma Enviada");
    }
    if (Firebase.setString(firebaseData,path1+"/ESTADO BOMBA 2",""))
    {
      Serial.print("Tipo de alarma Enviada");
    }
      if (Firebase.setString(firebaseData,path1+"/Activar Desactivar Bomba 2",""))
    {
      Serial.print("Tipo de alarma Enviada");
    }
   
  Serial.println("Estoy en la funcion Lectura de firebase");
    if (Firebase.getString(firebaseData,path1+"/ESTADO BOMBA 1")) //Preguntar si esta en estado automatico o manual
    {
        TipoRiego=firebaseData.stringData();
        Serial.println(TipoRiego);
        if ((TipoRiego.toInt()== 0)){ // 0 == Manual
        RiegoB1=false; 
        Serial.println("Bomba #1 en modo Manual");
      }
        if ((TipoRiego.toInt()== 1)){ // 1 == Automatico
        RiegoB1=true; //Es true para riego automatico y false para riego manual
        posB=1;
        Serial.println("Bomba #1 en modo Automatico");
      }
        
    }
    delay(10);
    if (Firebase.getString(firebaseData,path1+"/Activar Desactivar Bomba 1")) //Preguntar si esta en estado automatico o manual
    {
       Interruptor = firebaseData.stringData();
        Serial.println(Interruptor);
        if ((Interruptor.toInt()==1)){ // 1 es Bomba encender
        RiegoM=true; //Es true Enciendo la Bomba   
      }
      if ((Interruptor.toInt()==0)){ // 0 es bomba apagar
             RiegoM=false; //Es false apago la Bomba 
            }
           
    }

    // Analisar estado de la bomba 2
 delay(100);

  if (Firebase.getString(firebaseData,path1+"/ESTADO BOMBA 2")) //Preguntar si esta en estado automatico o manual
    {
        TipoRiego=firebaseData.stringData();
        Serial.println(TipoRiego);
        if ((TipoRiego.toInt()== 0)){ // 0 == Manual
        RiegoB2=false; 
        Serial.println("Bomba #2 en modo Manual");
      }
        if ((TipoRiego.toInt()== 1)){ // 1 == Automatico
        RiegoB2=true; //Es true para riego automatico y false para riego manual
        posB=2;
        Serial.println("Bomba #2 en modo Automatico");
      }
        
    }
    delay(10);
    if (Firebase.getString(firebaseData,path1+"/Activar Desactivar Bomba 2")) //Preguntar si esta en estado automatico o manual
    {
       Interruptor2 = firebaseData.stringData();
        Serial.println(Interruptor);
        if ((Interruptor2.toInt()==1)){ // 1 es Bomba encender
        RiegoM2=true; //Es true Enciendo la Bomba No 2
      }
      if ((Interruptor2.toInt()==0)){ // 0 es bomba apagar
             RiegoM2=false; //Es false apago la Bomba No 2
            }
           
    }

      if (Firebase.getString(firebaseData,path1+"/ESTADO BOMBA 1-2")) //Preguntar si esta en estado automatico o manual
    {
       String TipoRiego=firebaseData.stringData();
        Serial.println(TipoRiego);
        if ((TipoRiego.toInt()== 0)){ // 0 == Manual
        RiegoB2=false; 
        RiegoB1=false;
        Serial.println("Bomba #1-2 en modo Manual");
      }
        if ((TipoRiego.toInt()== 1)){ // 1 == Automatico
        RiegoB2=true; //Es true para riego automatico y false para riego manual
        RiegoB1=true;
        posB=3;
        Serial.println("Bomba #1-2 en modo Automatico");
      }
        
    }
    delay(10);
    if (Firebase.getString(firebaseData,path1+"/Activar Desactivar Bomba 1-2")) //Preguntar si esta en estado automatico o manual
    {
       Interruptor2 = firebaseData.stringData();
        Serial.println(Interruptor);
        if ((Interruptor2.toInt()==1)){ // 1 es Bomba encender
        RiegoM2=true; //Es true Enciendo la Bomba No 2
      }
      if ((Interruptor2.toInt()==0)){ // 0 es bomba apagar
             RiegoM2=false; //Es false apago la Bomba No 2
            } 
    }
// Preguntar tipo de Riego 
    delay(10);
    if (Firebase.getString(firebaseData,path11+"/Tipo Riego")) //Preguntar si esta en estado automatico o manual
    {
        contacto1 = firebaseData.stringData();
        Serial.print("Horario Diurno No ");Serial.println(contacto1);
        if ((contacto1.toInt()==1)){ // 1 es horario diurno 1
           posD = 1; 
           }
        if ((contacto1.toInt()==2)){ // 2 es horario diurno 2
              posD = 2; //2 es horario diurno 2
            }
          if ((contacto1.toInt()==3)){ // 2 es horario diurno 2
              posD = 3; //3 es horario dirno 3
            }     
    }

      delay(10);
    if (Firebase.getString(firebaseData,path11+"/Tipo Riego Nocturno")) //Preguntar si esta en estado automatico o manual
    {
        contacto1N = firebaseData.stringData();
        Serial.print("Horario nocturno No ");Serial.println(contacto1N);
        if ((contacto1N.toInt()==1)){ // 1 es horario nocturno 1
           posN = 1; 
           }
        if ((contacto1N.toInt()==2)){ // 2 es horario diurno 2
              posN = 2; //2 es horario nocturno 2
            }
          if ((contacto1N.toInt()==3)){ // 2 es horario diurno 2
              posN = 3; //3 es horario nocturno 3
            }     
    }
    
}


void InicioMenu(){
    //Wire.begin();
   lcd.createChar(1,esquinaiz1);
  lcd.createChar(2,esquinaiz2);
  lcd.createChar(3,superior);
  lcd.createChar(5,inferior);
  lcd.createChar(7,derecha1); //5
  lcd.createChar(0,derecha2); //6
  lcd.createChar(4,paralelo);
//  lcd.createChar(6,Check);
  
    // Imprime la informacion del proyecto:
    lcd.setCursor(0,0); lcd.write(1);
     lcd.setCursor(0,1); lcd.write(2);
     lcd.setCursor(15,0); lcd.write(7);
     lcd.setCursor(15,1); lcd.write(0);
     lcd.setCursor(1,0); lcd.write(3);lcd.setCursor(2,0); lcd.write(3);lcd.setCursor(13,0); lcd.write(3);lcd.setCursor(14,0); lcd.write(3);
     lcd.setCursor(1,1); lcd.write(5);lcd.setCursor(2,1); lcd.write(5);lcd.setCursor(3,1); lcd.write(5);lcd.setCursor(4,1); lcd.write(5);lcd.setCursor(11,1); lcd.write(5);lcd.setCursor(12,1); lcd.write(5);lcd.setCursor(13,1); lcd.write(5);lcd.setCursor(14,1); lcd.write(5);
     lcd.setCursor(4,0); lcd.print("Agro-IoT");
     lcd.setCursor(6,1); lcd.print("2020");
     delay(5000);
     lcd.clear();
     lcd.setCursor(0,0); lcd.write(1);
     lcd.setCursor(0,1); lcd.write(2);
     lcd.setCursor(15,0); lcd.write(7);
     lcd.setCursor(15,1); lcd.write(0);
     lcd.setCursor(1,0); lcd.write(3);lcd.setCursor(2,0); lcd.write(3);lcd.setCursor(11,0); lcd.write(3);lcd.setCursor(13,0); lcd.write(3);lcd.setCursor(14,0); lcd.write(3);
     lcd.setCursor(1,1); lcd.write(5);lcd.setCursor(2,1); lcd.write(5);lcd.setCursor(13,1); lcd.write(5);lcd.setCursor(14,1); lcd.write(5);
     //lcd.setCursor(15,1); lcd.write(0);
     lcd.setCursor(4,0); lcd.print("ElectIoT");
     lcd.setCursor(5,1); lcd.print("Cucuta");
     delay(5000);
     lcd.clear();
     lcd.setCursor(0,0); lcd.write(1);
     lcd.setCursor(0,1); lcd.write(2);
     lcd.setCursor(15,0); lcd.write(7);
     lcd.setCursor(15,1); lcd.write(0);
     //lcd.setCursor(1,0); lcd.write(3);lcd.setCursor(2,0); lcd.write(3);lcd.setCursor(13,0); lcd.write(3);lcd.setCursor(14,0); lcd.write(3);
     lcd.setCursor(2,0); lcd.print("AGRI-CULTOR");
     lcd.setCursor(2,1); lcd.print("LILIA ROSA");
     delay(5000);
     lcd.setCursor(0,0);
    for( int i=0 ; i<16 ; i++ )
    {
        lcd.print(".");
        delay(150);
    }
       lcd.setCursor(0,1);
    for( int i=0 ; i<16 ; i++ )
    {
        lcd.print(".");
        delay(150);
    }
    lcd.clear();
    lcd.createChar(8,grados);
}
