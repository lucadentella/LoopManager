// check if a sensor has changed status
void updateSensors() {

  long currentTime = millis();

  int s1NewStatus = updateSensor(PIN_STATUS_1);
  if((s1Status != s1NewStatus) && (s1NewStatus != SENSOR_UNKNOWN) && (currentTime - s1LastChanged > HYSTERESIS_MS)) {
    s1Status = s1NewStatus;
    s1LastChanged = currentTime;
   DEBUG_PRINT("S1 new status -> ");
    if(s1Status == SENSOR_FREE) {
     DEBUG_PRINTLN("FREE");
      digitalWrite(PIN_LED_1, LOW);
    } else {
     DEBUG_PRINTLN("BUSY");
      digitalWrite(PIN_LED_1, HIGH);      
    }
  }

  int s2NewStatus = updateSensor(PIN_STATUS_2);
  if((s2Status != s2NewStatus) && (s2NewStatus != SENSOR_UNKNOWN) && (currentTime - s2LastChanged > HYSTERESIS_MS)) {
    s2Status = s2NewStatus;
    s2LastChanged = currentTime;
   DEBUG_PRINT("S2 new status -> ");
    if(s2Status == SENSOR_FREE) {
     DEBUG_PRINTLN("FREE");
      digitalWrite(PIN_LED_2, LOW);
    } else {
     DEBUG_PRINTLN("BUSY");
      digitalWrite(PIN_LED_2, HIGH);      
    }   
  }

  int sLoopNewStatus = updateSensor(PIN_STATUS_LOOP);
  if((sLoopStatus != sLoopNewStatus) && (sLoopNewStatus != SENSOR_UNKNOWN) && (currentTime - sLoopLastChanged > HYSTERESIS_MS)) {
    sLoopStatus = sLoopNewStatus;
    sLoopLastChanged = currentTime;
   DEBUG_PRINT("SLOOP new status -> ");
    if(sLoopStatus == SENSOR_FREE) {
     DEBUG_PRINTLN("FREE");
      digitalWrite(PIN_LED_LOOP, LOW);
    } else {
     DEBUG_PRINTLN("BUSY");
      digitalWrite(PIN_LED_LOOP, HIGH);      
    }   
  } 
}

int updateSensor(int sensorPin) {

  int lastStatus = digitalRead(sensorPin);
  
  // check if status is stable for NUM_SAMPLES * SAMPLE_INTERVAL ms
  for(int i = 0; i < NUM_SAMPLES; i++) {
    int currentSensorStatus = digitalRead(sensorPin);
    if(currentSensorStatus != lastStatus) return SENSOR_UNKNOWN;
    delay(SAMPLE_INTERVAL);
  }

  return lastStatus;
}
