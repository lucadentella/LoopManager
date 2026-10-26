// FSM in short
// Idle state: S1 and LOOP polarity A, S2 polarity B
// Train enters S1: change S2 polarity to A
// Train enters S2: change S1 and LOOP polarity to B
// Train leaves the loop: return to IDLE state 

void FSM() {

  switch(fsmCurrentStatus) {

    case FSM_IDLE:

      if(s1Status == SENSOR_BUSY) {
        setLoopStatus(LOOP_STATUS_A);
        fsmCurrentStatus = FSM_ENTER_S1;
       DEBUG_PRINTLN("FSM_IDLE -> FSM_ENTER_S1, Loop status A");
      }
      if(s2Status == SENSOR_BUSY) {
        setLoopStatus(LOOP_STATUS_B);
        fsmCurrentStatus = FSM_ENTER_S2;
       DEBUG_PRINTLN("FSM_IDLE -> FSM_ENTER_S2, Loop status B");
      }
      break;

    case FSM_ENTER_S1:

      if(s1Status == SENSOR_FREE) {

        if(sLoopStatus == SENSOR_BUSY) {
        
          fsmCurrentStatus = FSM_IN_LOOP_FROM_S1;
         DEBUG_PRINTLN("FSM_ENTER_S1 -> FSM_IN_LOOP_FROM_S1");
        }  
        else {

          setLoopStatus(LOOP_STATUS_IDLE);
          fsmCurrentStatus = FSM_IDLE;
         DEBUG_PRINTLN("FSM_ENTER_S1 -> Train lost, back to IDLE");         
        }
      }
      break;

    case FSM_ENTER_S2:

      if(s2Status == SENSOR_FREE) {
      
        if(sLoopStatus == SENSOR_BUSY) {
        
          fsmCurrentStatus = FSM_IN_LOOP_FROM_S2;
         DEBUG_PRINTLN("FSM_ENTER_S2 -> FSM_IN_LOOP_FROM_S2");
        }
        else {

          setLoopStatus(LOOP_STATUS_IDLE);
          fsmCurrentStatus = FSM_IDLE;
         DEBUG_PRINTLN("FSM_ENTER_S2 -> Train lost, back to IDLE");         
        }
      }
      break;

    case FSM_IN_LOOP_FROM_S1:

      if(s2Status == SENSOR_BUSY) {
        setLoopStatus(LOOP_STATUS_B);
        fsmCurrentStatus = FSM_EXIT_S2;
       DEBUG_PRINTLN("FSM_IN_LOOP_FROM_S1 -> FSM_EXIT_S2, Loop status B");
      }
      break;

    case FSM_IN_LOOP_FROM_S2:

      if(s1Status == SENSOR_BUSY) {
        setLoopStatus(LOOP_STATUS_A);
        fsmCurrentStatus = FSM_EXIT_S1;
       DEBUG_PRINTLN("FSM_IN_LOOP_FROM_S2 -> FSM_EXIT_S1, Loop status A");
      }
      break;

    case FSM_EXIT_S1:

      if(s1Status == SENSOR_FREE) {
        setLoopStatus(LOOP_STATUS_IDLE);
        fsmCurrentStatus = FSM_IDLE;
       DEBUG_PRINTLN("FSM_EXIT_S1 -> FSM_IDLE, Loop status IDLE");
      }
      break;

    case FSM_EXIT_S2:

      if(s2Status == SENSOR_FREE) {
        setLoopStatus(LOOP_STATUS_IDLE);
        fsmCurrentStatus = FSM_IDLE;
       DEBUG_PRINTLN("FSM_EXIT_S2 -> FSM_IDLE, Loop status IDLE");
      }
      break;      
  }
}

void setLoopStatus(int status) {

  switch(status) {

    case LOOP_STATUS_IDLE:
      digitalWrite(PIN_CTRL_1, LOW);
      digitalWrite(PIN_CTRL_2, LOW);
      digitalWrite(PIN_CTRL_LOOP, LOW);    
      digitalWrite(PIN_LED_STATUS_A, LOW);
      digitalWrite(PIN_LED_STATUS_B, LOW);
      break;

    case LOOP_STATUS_A:
      digitalWrite(PIN_CTRL_1, LOW);
      digitalWrite(PIN_CTRL_2, HIGH);
      digitalWrite(PIN_CTRL_LOOP, LOW);    
      digitalWrite(PIN_LED_STATUS_A, HIGH);
      digitalWrite(PIN_LED_STATUS_B, LOW);
      break;

    case LOOP_STATUS_B:
      digitalWrite(PIN_CTRL_1, HIGH);
      digitalWrite(PIN_CTRL_2, LOW);
      digitalWrite(PIN_CTRL_LOOP, HIGH);
      digitalWrite(PIN_LED_STATUS_A, LOW);
      digitalWrite(PIN_LED_STATUS_B, HIGH);
      break;
  }
}