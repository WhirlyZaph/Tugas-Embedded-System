#include <avr/io.h>
#include <util/delay.h>

/*
  PB0 ke button
  PD0 sampai PD7 ke LED
*/

int main() {
  DDRB = 0x00;
  DDRD = 0b11111111;
  PORTB = 0x01;

  // Configure ADC Multiplexer Selection Register
  ADMUX = 0x40;    // Choose AVCC with external capacitor
  // ADC Control and Status Register A
  ADCSRA = 0b00000111;  // Choose prescaler with division factor 128 (from 111; slowest, most stable)

  uint8_t pressingButton = 0;  // Flag, function is as its name suggested
  uint16_t noise = 0;
  loop:
    if (PINB & 0x01) {
      ADCSRA = 0b11001111;  // Enable to generate noise (on A0 by default, leave unconnected)
      while (ADCSRA & 0x40);  // ADCSRA's 7th bit state becomes low when ADC process is complete

      noise = ADC % 36;
      if (pressingButton == 0) {
        if (noise == 0) {
          PORTD = 0b00010001;
        } else if (noise == 1) {
          PORTD = 0b00100001;
        } else if (noise == 2) {
          PORTD = 0b01010001;
        } else if (noise == 3) {
          PORTD = 0b01100001;
        } else if (noise == 4) {
          PORTD = 0b01110001;
        } else if (noise == 5) {
          PORTD = 0b11100001;
        } else if (noise == 6) {
          PORTD = 0b00010010;
        } else if (noise == 7) {
          PORTD = 0b00100010;
        } else if (noise == 8) {
          PORTD = 0b01010010;
        } else if (noise == 9) {
          PORTD = 0b01100010;
        } else if (noise == 10) {
          PORTD = 0b01110010;
        } else if (noise == 11) {
          PORTD = 0b11100010;
        } else if (noise == 12) {
          PORTD = 0b00010101;
        } else if (noise == 13) {
          PORTD = 0b00100101;
        } else if (noise == 14) {
          PORTD = 0b01010101;
        } else if (noise == 15) {
          PORTD = 0b01100101;
        } else if (noise == 16) {
          PORTD = 0b01110101;
        } else if (noise == 17) {
          PORTD = 0b11100101;
        } else if (noise == 18) {
          PORTD = 0b00010110;
        } else if (noise == 19) {
          PORTD = 0b00100110;
        } else if (noise == 20) {
          PORTD = 0b01010110;
        } else if (noise == 21) {
          PORTD = 0b01100110;
        } else if (noise == 22) {
          PORTD = 0b01110110;
        } else if (noise == 23) {
          PORTD = 0b11100110;
        } else if (noise == 24) {
          PORTD = 0b00010111;
        } else if (noise == 25) {
          PORTD = 0b00100111;
        } else if (noise == 26) {
          PORTD = 0b01010111;
        } else if (noise == 27) {
          PORTD = 0b01100111;
        } else if (noise == 28) {
          PORTD = 0b01110111;
        } else if (noise == 29) {
          PORTD = 0b11100111;
        } else if (noise == 30) {
          PORTD = 0b00011110;
        } else if (noise == 31) {
          PORTD = 0b00101110;
        } else if (noise == 32) {
          PORTD = 0b01011110;
        } else if (noise == 33) {
          PORTD = 0b01101110;
        } else if (noise == 34) {
          PORTD = 0b01111110;
        } else if (noise == 35) {
          PORTD = 0b11101110;
        }
      }

      pressingButton = 1;
    } else {
      ADCSRA = 0b00000111;  // Disable
      pressingButton = 0;
    }

    _delay_ms(100);  // Let noise accumulate and change
  goto loop;
}