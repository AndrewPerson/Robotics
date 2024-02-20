const int button_pin = 5;
const int debounce_delay = 50;

int lastSteadyState = LOW;       
int lastFlickerableState = LOW;  
int currentState; 

unsigned long lastDebounceTime = 0;

void setup() {
    Serial.begin(9600);
    pinMode(button_pin, INPUT_PULLUP);

}

void loop() {
    currentState = digitalRead(button_pin);

    if (currentState != lastFlickerableState) {
        lastDebounceTime = millis();
        lastFlickerableState = currentState;

    }

    if ((millis() - lastDebounceTime) > debounce_delay) {
    
        if (lastSteadyState == HIGH && currentState == LOW)
        Serial.println("The button is pressed");
        else if (lastSteadyState == LOW && currentState == HIGH)
        Serial.println("The button is released");

        lastSteadyState = currentState;
  }

}