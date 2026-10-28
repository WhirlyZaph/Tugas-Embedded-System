#include <avr/io.h>
#include <util/delay.h>

/*
  PD7 ke button
  PB0 sampai PB5 ke LED
*/

int main(void) {
  DDRB = 0b00111111;
  DDRD = 0x80;
  PORTD = 0x80;
  int button = 0;
  int previous = 1;  // Set selain angka-angka yang dapat dihasilkan oleh variable "current"

  loop:
    int current = PIND & 0x80;  // Return 0 (0x00) atau 128 (0x80)

    if (previous && !current) {
      button++;
    }

    if (button == 0 || button > 8) {
      button = 0;
      PORTB = 0x00;
    } else if (button == 1) {
      PORTB = 0b00011011;
    } else if (button == 2) {
      PORTB = 0b00110110;
    } else if (button == 3) {
      PORTB = 0b00100001;
    } else if (button == 4) {
      PORTB = 0b00001100;
    } else if (button == 5) {
      PORTB = 0b00011100;
    } else if (button == 6) {
      PORTB = 0b00001110;
    } else if (button == 7) {
      PORTB = 0b00111001;
    } else if (button == 8) {
      PORTB = 0b00100111;
    }
    
    _delay_ms(100);
    previous = current;
  goto loop;
}