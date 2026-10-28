#include <avr/io.h>
#include <util/delay.h>

/*
  PB5------BTN
  PB4------BTN
  Tx-------Rx Slave
  
  Jangan lupa GND disamakan!
*/

void Write(const char* str) {  // Pointer berjalan tiap char
  while (*str) {
    while (!(UCSR0A & (1 << UDRE0))); // Wait until the transmit buffer is ready
    UDR0 = *str;                      // Write the character to the buffer
    str++;                            // Move to the next character
  }
}
/*
uint8_t Read() {
  while (!(UCSR0A & 0x80)); // Bit ke-7 UCSR0A adalah RXC0, dimana
                            // 1 adalah complete byte received, dan
                            // 0 adalah no new data received
                            // Wait until buffer is not empty
  return UDR0;
}
*/
int main() {
  // Menggunakan USART (Universal Synchronous and Asynchronous
  // serial Receiver and Transmitter)
  DDRB = 0x00;
  PORTB = 0b00110000;
  UBRR0H = 0x00;  // 16-bit dipisah menjadi 8-bit high dan 8-bit low
  UBRR0L = 0b01100111;  // 103 untuk baud rate 9600, lanjutan dari atas
  UCSR0B = 0x18;  // 0b00011000, untuk 9-bit jadikan 0b00011100
                  // untuk enable TX dan RX
  UCSR0C = 0b00000110;  // 8-bit, untuk 9-bit lihat diatas
                        // untuk set frame bit komunikasi

  loop:
    // Send
    if (PINB & 0x20) {
      Write("1");
      _delay_ms(50);
    } else if (PINB & 0x10) {
      Write("2");
      _delay_ms(50);
    } else {
      PORTB = 0x20;
    }
/*
    // Read
    if (UCSR0A & 0x80) {
      char receivedChar = Read();
      if (receivedChar == '1') {
        DDRB = 0x01;
      }
    }
*/
  goto loop;
}