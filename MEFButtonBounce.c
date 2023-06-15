#define RETARDO 40
#define LEDPIN 13
#define BUTTONPIN 2

typedef enum {
  BUTTON_UP,
  BUTTON_FALLING,
  BUTTON_DOWN,
  BUTTON_RAISING
} debounceState_t;

debounceState_t currentState;

void debounceFSM_init(void);
void debounceFSM_update(void);

void buttonPressed(void);
void buttonReleased(void);

void setup() {
  pinMode(LEDPIN, OUTPUT);
  pinMode(BUTTONPIN, INPUT);
  debounceFSM_init();
}

void loop() {
  debounceFSM_update();
  delay(10);
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
      if (millis() - lastTime >= RETARDO) {
        if (!digitalRead(BUTTONPIN)){
          buttonPressed();
          currentState = BUTTON_DOWN;
        }else currentState = BUTTON_UP;
      }
      break;

    case BUTTON_DOWN:
      if (digitalRead(BUTTONPIN)) {
        currentState = BUTTON_RAISING;
        lastTime = millis();
      }
      break;

    case BUTTON_RAISING:
      if (millis() - lastTime >= RETARDO) {
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
}

void buttonReleased(void) {
  digitalWrite(LEDPIN, LOW);
}
