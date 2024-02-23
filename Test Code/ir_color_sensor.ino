const int line_data_pin = 2;

void setup() {
  pinMode(line_data_pin, INPUT);
  Serial.begin(9600);

}

void loop() {
  auto current_state = digitalRead(line_data_pin); // outputs a boolean, 1 if white, 0 if black.
  Serial.println(current_state);

}
