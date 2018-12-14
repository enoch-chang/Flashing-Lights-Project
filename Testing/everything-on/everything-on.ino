// This code is to ensure all the outputs and inputs are functional on the physical circuit

#define FLASH_RATE 2
#define BUTTON_IN 2
#define PWM_LED_OUT 11
#define BATT_CHECK_INPUT A0
#define BATT_CHECK_BUTTON 8
#define BATT_LED_1 5
#define BATT_LED_2 6
#define BATT_LED_3 7
#define DEBOUNCE_DELAY 100

// operating_mode: 0 - off, 1 - bright, 2 - mid, 3 - dim, 4 - flash
int operating_mode = 0;
int BUTTON_PUSHED = 0;
int previous_button_state = 0;
int PWM_OUT = 0;
int LED_STATE = LOW;
int PWM_MAX = 255;
int BATT_BUTTON_PUSHED = 0;
int voltage = 0;
int previousMillis = 0;
int currentMillis = 0;

int currentState;
int lastState;

void setup() {

  Serial.begin(9600);

  pinMode(BUTTON_IN, INPUT);
  pinMode(BATT_CHECK_BUTTON, INPUT);
  pinMode(PWM_LED_OUT, OUTPUT); 
  pinMode(BATT_LED_1, OUTPUT);  
  pinMode(BATT_LED_2, OUTPUT);  
  pinMode(BATT_LED_3, OUTPUT);  

  digitalWrite(BUTTON_IN, LOW); 
  digitalWrite(PWM_LED_OUT, LED_STATE);

  //attachInterrupt(digitalPinToInterrupt(BUTTON_IN), button_pushed, FALLING);
  //attachInterrupt(BATT_CHECK_BUTTON, batt_button_pushed, FALLING);
}

void loop() {
    Serial.print(digitalRead(BUTTON_IN));
    Serial.print(digitalRead(BATT_CHECK_BUTTON));
    digitalWrite(BATT_LED_1, HIGH);
    digitalWrite(BATT_LED_2, HIGH);
    digitalWrite(BATT_LED_3, HIGH); 
    digitalWrite(PWM_LED_OUT, HIGH);
  }
    
