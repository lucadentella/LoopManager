#include "config.h"

//#define DEBUG_ENABLE

#ifdef DEBUG_ENABLE
  #define DEBUG_PRINT(x)     Serial.print(x)
  #define DEBUG_PRINTLN(x)  Serial.println(x)
#else
  #define DEBUG_PRINT(x)
  #define DEBUG_PRINTLN(x)
#endif

int fsmCurrentStatus;
int s1Status, s2Status, sLoopStatus;
long s1LastChanged, s2LastChanged, sLoopLastChanged;

void setup() {

  #ifdef DEBUG_ENABLE
  Serial.begin(115200);
  while(!Serial);
  #endif

  DEBUG_PRINTLN("----- LoopManager setup -----");

  // PIN configuration
  pinMode(PIN_STATUS_1, INPUT);
  pinMode(PIN_STATUS_2, INPUT);
  pinMode(PIN_STATUS_LOOP, INPUT);
  pinMode(PIN_CTRL_1, OUTPUT);
  pinMode(PIN_CTRL_2, OUTPUT);
  pinMode(PIN_CTRL_LOOP, OUTPUT);
  pinMode(PIN_LED_1, OUTPUT);
  pinMode(PIN_LED_2, OUTPUT);
  pinMode(PIN_LED_LOOP, OUTPUT);
  pinMode(PIN_LED_STATUS_A, OUTPUT);
  pinMode(PIN_LED_STATUS_B, OUTPUT);
  DEBUG_PRINTLN(". PINs configured");

  // Default sensors status, unknown
  s1Status = SENSOR_UNKNOWN;
  s2Status = SENSOR_UNKNOWN;
  sLoopStatus = SENSOR_UNKNOWN;
  DEBUG_PRINTLN(". Sensors in UNKNOWN status");

  // Default relays position
  digitalWrite(PIN_CTRL_1, LOW);
  digitalWrite(PIN_CTRL_2, LOW);
  digitalWrite(PIN_CTRL_LOOP, LOW);
  DEBUG_PRINTLN(". Relays in default position");

  // Start in IDLE
  fsmCurrentStatus = FSM_IDLE;
  setLoopStatus(LOOP_STATUS_IDLE);
  DEBUG_PRINTLN(". FSM in IDLE");

  DEBUG_PRINTLN();
  DEBUG_PRINTLN("----- LoopManager loop -----");
}

void loop() {

  // Update sensors
  updateSensors();

  // FSM
  FSM();
}
