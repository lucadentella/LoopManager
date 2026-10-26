// PINs
#define PIN_STATUS_1       2
#define PIN_STATUS_2       3
#define PIN_STATUS_LOOP    4
#define PIN_CTRL_1         5
#define PIN_CTRL_2         6
#define PIN_CTRL_LOOP      9
#define PIN_LED_1          15
#define PIN_LED_2          18
#define PIN_LED_LOOP       14
#define PIN_LED_STATUS_A   16
#define PIN_LED_STATUS_B   10

// Sensors
#define NUM_SAMPLES        5
#define SAMPLE_INTERVAL    10
#define HYSTERESIS_MS      200
#define SENSOR_FREE        1
#define SENSOR_BUSY        0
#define SENSOR_UNKNOWN     -1

// FSM
#define FSM_IDLE             0
#define FSM_ENTER_S1         1
#define FSM_ENTER_S2         2
#define FSM_IN_LOOP_FROM_S1  3
#define FSM_IN_LOOP_FROM_S2  4
#define FSM_EXIT_S1          5
#define FSM_EXIT_S2          6

// Loop status
#define LOOP_STATUS_IDLE   0
#define LOOP_STATUS_A      1
#define LOOP_STATUS_B      2

