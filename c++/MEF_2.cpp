#define DEBOUNCE_DELAY 40
#define LEDPIN 13
#define BUTTONPIN 8
#define SYSTEM_DELAY 10
#define NUMS_LIM 15

// link to tinkercad proyect https://www.tinkercad.com/things/fYhpRySFNUv-mef22

typedef enum {
  BUTTON_UP,
  BUTTON_FALLING,
  BUTTON_DOWN,
  BUTTON_RISING
} debounceState_t;

const char OUTPUTS[] = {
  B11111100,
  B01100000,
  B11011010,
  B11110010,
  B01100110,
  B10110110,
  B10111110,
  B11100000,
  B11111110,
  B11100110,
  B11111010,
  B00111110,
  B10011100,
  B01111010,
  B10011110,
  B10001110
};


debounceState_t currentState;

void debounceFSM_init(void);
void debounceFSM_update(void);

void buttonPressed(void);
void buttonReleased(void);

void setdisplay(int);

int counter = 0;

void setup() {
  pinMode(LEDPIN, OUTPUT);
  pinMode(BUTTONPIN, INPUT);
  
  DDRD = B11111110;
  PORTD = B0;
  
  debounceFSM_init();
}

void loop() {
  debounceFSM_update();
  setdisplay(counter);
  delay(SYSTEM_DELAY);
}

void debounceFSM_init(void) {
  currentState = BUTTON_UP;
}

void debounceFSM_update(void) {
  static unsigned long lastTime = millis();
  
  switch (currentState) {
    case BUTTON_UP:
      if (!digitalRead(BUTTONPIN)){
        currentState = BUTTON_FALLING;
        lastTime = millis();
      }
      break;

    case BUTTON_FALLING:
      if (millis() - lastTime >= DEBOUNCE_DELAY) {
        if (!digitalRead(BUTTONPIN)){
          buttonPressed();
          currentState = BUTTON_DOWN;
        }else currentState = BUTTON_UP;
      }
      break;

    case BUTTON_DOWN:
      if (digitalRead(BUTTONPIN)) {
        currentState = BUTTON_RISING;
        lastTime = millis();
      }
      break;

    case BUTTON_RISING:
      if (millis() - lastTime >= DEBOUNCE_DELAY) {
        if (digitalRead(BUTTONPIN)) {
          buttonReleased();
          currentState = BUTTON_UP;
        } else currentState = BUTTON_DOWN;
      }
      break;

    default:
      buttonReleased();
      break;
  }
}

void buttonPressed(void) {
  digitalWrite(LEDPIN, HIGH);
  if (counter < NUMS_LIM) counter++;
  else counter = 0;
}

void buttonReleased(void) {
  digitalWrite(LEDPIN, LOW);
}

void setdisplay(int num){
  PORTD = OUTPUTS[num];
}
