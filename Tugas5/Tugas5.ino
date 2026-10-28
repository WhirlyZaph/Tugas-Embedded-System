#include <avr/io.h>
#include <util/delay.h>

/*
  PB5------BTN
  PB4------BTN
  PB0------Transmitter
  Tx-------Rx Slave
*/

int main() {
  DDRB = 0x01;
  PORTB = 0b00110000;

  loop:
    if (PINB & 0x20) {
      PORTB = 0x21;
      _delay_ms(100);
    } else if (PINB & 0x10) {
      PORTB = 0x21;
      _delay_us(13);
      PORTB = 0x20;
      _delay_us(13);
      PORTB = 0x21;
      _delay_us(13);
      PORTB = 0x20;
      _delay_us(13);
    }

    PORTB = 0x20;
  goto loop;
}
