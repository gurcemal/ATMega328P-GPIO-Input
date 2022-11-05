/* Arduino Nano GPIO Exaple
   PD3 --> D3 --> Button 1    //Pull-up activated
   PB0 --> D8 --> Button 2    //Pull-up not activated
*/

#define button_1 PD3
#define button_2 PB0

bool button1_value, button2_value;

void setup() {
  Serial.begin(9600);
  DDRD &= (~(1 << button_1));       // 3. bit of portD is false and input for Button_1
  DDRB &= (~(1 << button_2));       // 0. bit of portD is false and input for Button_2

  PORTD |= (1 << button_1);         // Pull-up res is activated for 3. bit of portD
  PORTD &= (~(1 << button_2));      // Pull-up res is not activated for 0. bit of portB
}

void loop() {
  button1_value = (PIND & (1 << button_1));     // read the 3. bit of PIND port
  button2_value = (PINB & (1 << button_2));     // read the 0. bit of PINB port
  if ( button1_value == 0 ) {
    Serial.println("Button 1 is pressed");
    while ( button1_value == 0 ) {
      button1_value = (PIND & (1 << button_1));     // read the 3. bit of PIND port
    }
  }
  if ( button2_value == 1 ) {
    Serial.println("Button 2 is pressed");
    while ( button2_value == 1 ) {
      button2_value = (PINB & (1 << button_2));     // read the 0. bit of PINB port
    }
  }
}
