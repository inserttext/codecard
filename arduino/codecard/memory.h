/*
  memory.h
  
*/

int getKeyIndex(String val){
  int ret = -1;
  for (int i=0; i < keysLen; i++){
    if (String(keys[i]) == val) {
      ret = i;
      break;
    }
  }
  return ret;
}

String getFromMemory(int addr) {
  char arrayToStore[100];
  if (EEPROM.read(addr*maxValue) == 255){
    return "";
  }
  EEPROM.get(addr*maxValue, arrayToStore);
  String ret(arrayToStore);
  return ret;
}

String getFromMemory(String key) {
  String ret = "";
  for (int i=0; i < keysLen; i++) {
    if (String(keys[i]) == key) {
      String key = keys[i];
      ret = getFromMemory(i);
      if (key.indexOf("method") > -1 && ret == "") {
         ret = "GET";
      }
      if (key.indexOf("initalsetup") > -1 && ret == "") {
         ret = "true";
      }
      break;
    }
  }
  return ret;
}

void saveToMemory(int addr, String val) {
  char arrayToStore[100];
  val.toCharArray(arrayToStore, 100) ;
  EEPROM.put(addr*maxValue, arrayToStore);
  EEPROM.commit();
}
