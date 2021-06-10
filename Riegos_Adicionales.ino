 void pantalla(){
 lcd.init();
 RtcDateTime now = Rtc.GetDateTime();
 RtcTemperature tempp = Rtc.GetTemperature();
 lcd.setCursor(0,0);
 lcd.print("Temp:");
 lcd.setCursor(5,0);
 lcd.print(tempp.AsFloatDegC());
 //Serial.print(rtc.getDateStr());
 lcd.setCursor(0,1);
 lcd.print("T:");
 lcd.setCursor(13,0);
 lcd.print("-");
 switch(posD){
  case 1:
        lcd.setCursor(11,0);
        lcd.print("D1");
  break;
  case 2:
        lcd.setCursor(11,0);
        lcd.print("D2");
        break;
        case 3:
        lcd.setCursor(11,0);
        lcd.print("D3");
        break;
 }
 switch(posN){
  case 1:
        lcd.setCursor(11,1);
        lcd.print("N1");
  break;
  case 2:
        lcd.setCursor(11,1);
        lcd.print("N2");
        break;
        case 3:
        lcd.setCursor(11,1);
        lcd.print("N3");
        break;
 }

switch(posB){
   case 1:
        lcd.setCursor(14,0);
        lcd.print("B1");
  break;
  case 2:
        lcd.setCursor(14,0);
        lcd.print("B2");
        break;
        case 3:
        lcd.setCursor(14,0);
        lcd.print("B3");
        break;
  
}

}
