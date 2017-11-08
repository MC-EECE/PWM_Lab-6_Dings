const int led_pin=13;
const int input = A0;
const int MAX_8_INT = 255;
int brightness = 0;
int fade_amount = 1;

void setup() {
  // put your setup code here, to run once:
  analogReadResolution(12);
  analogWriteResolution(8);
  
}

void loop() {
  // put your main code here, to run repeatedly:

int PWM_input = analogRead(input)>>4;
analogWrite(led_pin, PWM_input);

//brightness = brightness + fade_amount;
//if (brightness == 0 or brightness == MAX_8_INT)
//{
//  fade_amount = -fade_amount;
//}
//delay(100);

}
