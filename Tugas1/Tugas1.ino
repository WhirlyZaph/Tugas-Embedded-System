#include <avr/io.h>
#include <util/delay.h>


// 2088BS; tulisan berhadap ke bawah/selatan
// 1-8 adalah set pin terdekat dengan tulisan (kiri ke kanan)
// a-h adalah set pin jauh dari tulisan (kiri ke kanan)

// Relasi pin yang digunakan:
//   PB5 -> 3
//   PB4 -> 4
//   PB3 -> g
//   PB2 -> 6
//   PB1 -> f
//   PB0 -> b
// ------------
//   PD7 -> c
//   PD6 -> 8
//   PD5 -> e
//   PD4 -> 1
//   PD3 -> 7
//   PD2 -> 2
// ------------
//   PC5 -> input button             | Stop
//   PC4 -> input switch 2-state     | Hazard
//   PC3 -> input switch 3-state I   | Kiri
//   PC2 -> input switch 3-state II  | Kanan

// Workaround untuk keterbatasan penggunaan variable dynamic pada _delay_us()
void usdelay(uint16_t delaytime) {
  while (delaytime--) {
    _delay_us(1);
  }
}


int main(void) {
  DDRB = 0b00111111;  // Set digital port 8-13 sebagai output (sebagai LOW)
  DDRD = 0b11111100;  // Set digital port 2-7 sebagai output (sebagai HIGH)
  DDRC = 0b00000001;  // Set digital port A0-A5 yang diperlukan sebagai input button dan switch
  int i = 0;  // Flag mode lampu ke berapa
  int j = 0;  // Counter looping animasi

  // Kecepatan animasi lampu hazard
  int waktuTiapInterval = 100;  // dari atas ke bawah

  // Kecepatan animasi lainnya
  int waktuTiapFrame = 8;  // tergantung kecepatan process
  int delayPerBaris = 2000;  // dalam micro-second

  loop:
    j = waktuTiapFrame * -1;



    if (PINC & 0b00010000) {  // HAZARD
      j = waktuTiapInterval * -1;
      while (j < waktuTiapInterval * 0 && PINC & 0b00010000) {
        PORTD = 0x80;  // c
        PORTB = 0b00111111;
        _delay_us(100);
        PORTD = 0x40;  // 8
        PORTB = 0b00111111;
        _delay_us(100);
        PORTD = 0x20;  // e
        PORTB = 0b00111111;
        _delay_us(100);
        PORTD = 0x10;  // 1
        PORTB = 0b00111111;
        _delay_us(100);
        PORTD = 0x08;  // 7
        PORTB = 0b00111111;
        _delay_us(100);
        PORTD = 0x04;  // 2
        PORTB = 0b00111111;
        _delay_us(100);

        j++;
      }

      while (j < waktuTiapInterval * 1 && PINC & 0b00010000) {
        PORTD = 0x80;  // c
        PORTB = 0b00110011;
        _delay_us(1);
        PORTB = 0b00111111;
        _delay_us(99);
        PORTD = 0x40;  // 8
        PORTB = 0b00111111;
        _delay_us(100);
        PORTD = 0x20;  // e
        PORTB = 0b00111111;
        _delay_us(100);
        PORTD = 0x10;  // 1
        PORTB = 0b00111111;
        _delay_us(100);
        PORTD = 0x08;  // 7
        PORTB = 0b00111111;
        _delay_us(100);
        PORTD = 0x04;  // 2
        PORTB = 0b00111111;
        _delay_us(100);

        j++;
      }

      while (j < waktuTiapInterval * 2 && PINC & 0b00010000) {
        PORTD = 0x80;  // c
        PORTB = 0b00110011;
        _delay_us(2);
        PORTB = 0b00111111;
        _delay_us(98);
        PORTD = 0x40;  // 8
        PORTB = 0b00100001;
        _delay_us(1);
        PORTB = 0b00111111;
        _delay_us(99);
        PORTD = 0x20;  // e
        PORTB = 0b00111111;
        _delay_us(100);
        PORTD = 0x10;  // 1
        PORTB = 0b00111111;
        _delay_us(100);
        PORTD = 0x08;  // 7
        PORTB = 0b00111111;
        _delay_us(100);
        PORTD = 0x04;  // 2
        PORTB = 0b00111111;
        _delay_us(100);

        j++;
      }

      while (j < waktuTiapInterval * 3 && PINC & 0b00010000) {
        PORTD = 0x80;  // c
        PORTB = 0b00110011;
        _delay_us(5);
        PORTB = 0b00111111;
        _delay_us(95);
        PORTD = 0x40;  // 8
        PORTB = 0b00100001;
        _delay_us(2);
        PORTB = 0b00111111;
        _delay_us(98);
        PORTD = 0x20;  // e
        PORTB = 0b00001100;
        _delay_us(1);
        PORTB = 0b00111111;
        _delay_us(99);
        PORTD = 0x10;  // 1
        PORTB = 0b00111111;
        _delay_us(100);
        PORTD = 0x08;  // 7
        PORTB = 0b00111111;
        _delay_us(100);
        PORTD = 0x04;  // 2
        PORTB = 0b00111111;
        _delay_us(100);

        j++;
      }

      while (j < waktuTiapInterval * 4 && PINC & 0b00010000) {
        PORTD = 0x80;  // c
        PORTB = 0b00110011;
        _delay_us(10);
        PORTB = 0b00111111;
        _delay_us(90);
        PORTD = 0x40;  // 8
        PORTB = 0b00100001;
        _delay_us(5);
        PORTB = 0b00111111;
        _delay_us(95);
        PORTD = 0x20;  // e
        PORTB = 0b00001100;
        _delay_us(2);
        PORTB = 0b00111111;
        _delay_us(98);
        PORTD = 0x10;  // 1
        PORTB = 0b00001100;
        _delay_us(1);
        PORTB = 0b00111111;
        _delay_us(99);
        PORTD = 0x08;  // 7
        PORTB = 0b00111111;
        _delay_us(100);
        PORTD = 0x04;  // 2
        PORTB = 0b00111111;
        _delay_us(100);

        j++;
      }

      while (j < waktuTiapInterval * 5 && PINC & 0b00010000) {
        PORTD = 0x80;  // c
        PORTB = 0b00110011;
        _delay_us(30);
        PORTB = 0b00111111;
        _delay_us(70);
        PORTD = 0x40;  // 8
        PORTB = 0b00100001;
        _delay_us(10);
        PORTB = 0b00111111;
        _delay_us(90);
        PORTD = 0x20;  // e
        PORTB = 0b00001100;
        _delay_us(5);
        PORTB = 0b00111111;
        _delay_us(95);
        PORTD = 0x10;  // 1
        PORTB = 0b00001100;
        _delay_us(2);
        PORTB = 0b00111111;
        _delay_us(98);
        PORTD = 0x08;  // 7
        PORTB = 0b00100001;
        _delay_us(1);
        PORTB = 0b00111111;
        _delay_us(99);
        PORTD = 0x04;  // 2
        PORTB = 0b00111111;
        _delay_us(100);

        j++;
      }

      while (j < waktuTiapInterval * 6 && PINC & 0b00010000) {
        PORTD = 0x80;  // c
        PORTB = 0b00110011;
        _delay_us(30);
        PORTB = 0b00111111;
        _delay_us(70);
        PORTD = 0x40;  // 8
        PORTB = 0b00100001;
        _delay_us(30);
        PORTB = 0b00111111;
        _delay_us(70);
        PORTD = 0x20;  // e
        PORTB = 0b00001100;
        _delay_us(10);
        PORTB = 0b00111111;
        _delay_us(99);
        PORTD = 0x10;  // 1
        PORTB = 0b00001100;
        _delay_us(5);
        PORTB = 0b00111111;
        _delay_us(95);
        PORTD = 0x08;  // 7
        PORTB = 0b00100001;
        _delay_us(2);
        PORTB = 0b00111111;
        _delay_us(98);
        PORTD = 0x04;  // 2
        PORTB = 0b00110011;
        _delay_us(1);
        PORTB = 0b00111111;
        _delay_us(99);

        j++;
      }

      while (j < waktuTiapInterval * 7 && PINC & 0b00010000) {
        PORTD = 0x80;  // c
        PORTB = 0b00110011;
        _delay_us(30);
        PORTB = 0b00111111;
        _delay_us(70);
        PORTD = 0x40;  // 8
        PORTB = 0b00100001;
        _delay_us(30);
        PORTB = 0b00111111;
        _delay_us(70);
        PORTD = 0x20;  // e
        PORTB = 0b00001100;
        _delay_us(30);
        PORTB = 0b00111111;
        _delay_us(70);
        PORTD = 0x10;  // 1
        PORTB = 0b00001100;
        _delay_us(10);
        PORTB = 0b00111111;
        _delay_us(90);
        PORTD = 0x08;  // 7
        PORTB = 0b00100001;
        _delay_us(5);
        PORTB = 0b00111111;
        _delay_us(95);
        PORTD = 0x04;  // 2
        PORTB = 0b00110011;
        _delay_us(2);
        PORTB = 0b00111111;
        _delay_us(92);

        j++;
      }

      while (j < waktuTiapInterval * 8 && PINC & 0b00010000) {
        PORTD = 0x80;  // c
        PORTB = 0b00110011;
        _delay_us(30);
        PORTB = 0b00111111;
        _delay_us(70);
        PORTD = 0x40;  // 8
        PORTB = 0b00100001;
        _delay_us(30);
        PORTB = 0b00111111;
        _delay_us(70);
        PORTD = 0x20;  // e
        PORTB = 0b00001100;
        _delay_us(30);
        PORTB = 0b00111111;
        _delay_us(70);
        PORTD = 0x10;  // 1
        PORTB = 0b00001100;
        _delay_us(30);
        PORTB = 0b00111111;
        _delay_us(70);
        PORTD = 0x08;  // 7
        PORTB = 0b00100001;
        _delay_us(10);
        PORTB = 0b00111111;
        _delay_us(90);
        PORTD = 0x04;  // 2
        PORTB = 0b00110011;
        _delay_us(5);
        PORTB = 0b00111111;
        _delay_us(95);

        j++;
      }

      while (j < waktuTiapInterval * 9 && PINC & 0b00010000) {
        PORTD = 0x80;  // c
        PORTB = 0b00110011;
        _delay_us(30);
        PORTB = 0b00111111;
        _delay_us(70);
        PORTD = 0x40;  // 8
        PORTB = 0b00100001;
        _delay_us(30);
        PORTB = 0b00111111;
        _delay_us(70);
        PORTD = 0x20;  // e
        PORTB = 0b00001100;
        _delay_us(30);
        PORTB = 0b00111111;
        _delay_us(70);
        PORTD = 0x10;  // 1
        PORTB = 0b00001100;
        _delay_us(30);
        PORTB = 0b00111111;
        _delay_us(70);
        PORTD = 0x08;  // 7
        PORTB = 0b00100001;
        _delay_us(30);
        PORTB = 0b00111111;
        _delay_us(70);
        PORTD = 0x04;  // 2
        PORTB = 0b00110011;
        _delay_us(10);
        PORTB = 0b00111111;
        _delay_us(90);

        j++;
      }

      while (j < waktuTiapInterval * 12 && PINC & 0b00010000) {
        PORTD = 0x80;  // c
        PORTB = 0b00110011;
        _delay_us(30);
        PORTB = 0b00111111;
        _delay_us(70);
        PORTD = 0x40;  // 8
        PORTB = 0b00100001;
        _delay_us(30);
        PORTB = 0b00111111;
        _delay_us(70);
        PORTD = 0x20;  // e
        PORTB = 0b00001100;
        _delay_us(30);
        PORTB = 0b00111111;
        _delay_us(70);
        PORTD = 0x10;  // 1
        PORTB = 0b00001100;
        _delay_us(30);
        PORTB = 0b00111111;
        _delay_us(70);
        PORTD = 0x08;  // 7
        PORTB = 0b00100001;
        _delay_us(30);
        PORTB = 0b00111111;
        _delay_us(70);
        PORTD = 0x04;  // 2
        PORTB = 0b00110011;
        _delay_us(30);
        PORTB = 0b00111111;
        _delay_us(70);

        j++;
      }

      while (j < waktuTiapInterval * 13 && PINC & 0b00010000) {
        PORTD = 0x80;  // c
        PORTB = 0b00110011;
        _delay_us(10);
        PORTB = 0b00111111;
        _delay_us(90);
        PORTD = 0x40;  // 8
        PORTB = 0b00100001;
        _delay_us(30);
        PORTB = 0b00111111;
        _delay_us(70);
        PORTD = 0x20;  // e
        PORTB = 0b00001100;
        _delay_us(30);
        PORTB = 0b00111111;
        _delay_us(70);
        PORTD = 0x10;  // 1
        PORTB = 0b00001100;
        _delay_us(30);
        PORTB = 0b00111111;
        _delay_us(70);
        PORTD = 0x08;  // 7
        PORTB = 0b00100001;
        _delay_us(30);
        PORTB = 0b00111111;
        _delay_us(70);
        PORTD = 0x04;  // 2
        PORTB = 0b00110011;
        _delay_us(30);
        PORTB = 0b00111111;
        _delay_us(70);

        j++;
      }

      while (j < waktuTiapInterval * 14 && PINC & 0b00010000) {
        PORTD = 0x80;  // c
        PORTB = 0b00110011;
        _delay_us(5);
        PORTB = 0b00111111;
        _delay_us(95);
        PORTD = 0x40;  // 8
        PORTB = 0b00100001;
        _delay_us(10);
        PORTB = 0b00111111;
        _delay_us(90);
        PORTD = 0x20;  // e
        PORTB = 0b00001100;
        _delay_us(30);
        PORTB = 0b00111111;
        _delay_us(70);
        PORTD = 0x10;  // 1
        PORTB = 0b00001100;
        _delay_us(30);
        PORTB = 0b00111111;
        _delay_us(70);
        PORTD = 0x08;  // 7
        PORTB = 0b00100001;
        _delay_us(30);
        PORTB = 0b00111111;
        _delay_us(70);
        PORTD = 0x04;  // 2
        PORTB = 0b00110011;
        _delay_us(30);
        PORTB = 0b00111111;
        _delay_us(70);

        j++;
      }

      while (j < waktuTiapInterval * 15 && PINC & 0b00010000) {
        PORTD = 0x80;  // c
        PORTB = 0b00110011;
        _delay_us(2);
        PORTB = 0b00111111;
        _delay_us(98);
        PORTD = 0x40;  // 8
        PORTB = 0b00100001;
        _delay_us(5);
        PORTB = 0b00111111;
        _delay_us(95);
        PORTD = 0x20;  // e
        PORTB = 0b00001100;
        _delay_us(10);
        PORTB = 0b00111111;
        _delay_us(90);
        PORTD = 0x10;  // 1
        PORTB = 0b00001100;
        _delay_us(30);
        PORTB = 0b00111111;
        _delay_us(70);
        PORTD = 0x08;  // 7
        PORTB = 0b00100001;
        _delay_us(30);
        PORTB = 0b00111111;
        _delay_us(70);
        PORTD = 0x04;  // 2
        PORTB = 0b00110011;
        _delay_us(30);
        PORTB = 0b00111111;
        _delay_us(70);

        j++;
      }

      while (j < waktuTiapInterval * 16 && PINC & 0b00010000) {
        PORTD = 0x80;  // c
        PORTB = 0b00110011;
        _delay_us(1);
        PORTB = 0b00111111;
        _delay_us(99);
        PORTD = 0x40;  // 8
        PORTB = 0b00100001;
        _delay_us(2);
        PORTB = 0b00111111;
        _delay_us(98);
        PORTD = 0x20;  // e
        PORTB = 0b00001100;
        _delay_us(5);
        PORTB = 0b00111111;
        _delay_us(95);
        PORTD = 0x10;  // 1
        PORTB = 0b00001100;
        _delay_us(10);
        PORTB = 0b00111111;
        _delay_us(90);
        PORTD = 0x08;  // 7
        PORTB = 0b00100001;
        _delay_us(30);
        PORTB = 0b00111111;
        _delay_us(70);
        PORTD = 0x04;  // 2
        PORTB = 0b00110011;
        _delay_us(30);
        PORTB = 0b00111111;
        _delay_us(70);

        j++;
      }

      while (j < waktuTiapInterval * 17 && PINC & 0b00010000) {
        PORTD = 0x80;  // c
        PORTB = 0b00111111;
        _delay_us(100);
        PORTD = 0x40;  // 8
        PORTB = 0b00100001;
        _delay_us(1);
        PORTB = 0b00111111;
        _delay_us(99);
        PORTD = 0x20;  // e
        PORTB = 0b00001100;
        _delay_us(2);
        PORTB = 0b00111111;
        _delay_us(98);
        PORTD = 0x10;  // 1
        PORTB = 0b00001100;
        _delay_us(5);
        PORTB = 0b00111111;
        _delay_us(95);
        PORTD = 0x08;  // 7
        PORTB = 0b00100001;
        _delay_us(10);
        PORTB = 0b00111111;
        _delay_us(90);
        PORTD = 0x04;  // 2
        PORTB = 0b00110011;
        _delay_us(30);
        PORTB = 0b00111111;
        _delay_us(70);

        j++;
      }

      while (j < waktuTiapInterval * 18 && PINC & 0b00010000) {
        PORTD = 0x80;  // c
        PORTB = 0b00111111;
        _delay_us(100);
        PORTD = 0x40;  // 8
        PORTB = 0b00111111;
        _delay_us(100);
        PORTD = 0x20;  // e
        PORTB = 0b00001100;
        _delay_us(1);
        PORTB = 0b00111111;
        _delay_us(99);
        PORTD = 0x10;  // 1
        PORTB = 0b00001100;
        _delay_us(2);
        PORTB = 0b00111111;
        _delay_us(98);
        PORTD = 0x08;  // 7
        PORTB = 0b00100001;
        _delay_us(5);
        PORTB = 0b00111111;
        _delay_us(95);
        PORTD = 0x04;  // 2
        PORTB = 0b00110011;
        _delay_us(10);
        PORTB = 0b00111111;
        _delay_us(90);

        j++;
      }

      while (j < waktuTiapInterval * 19 && PINC & 0b00010000) {
        PORTD = 0x80;  // c
        PORTB = 0b00111111;
        _delay_us(100);
        PORTD = 0x40;  // 8
        PORTB = 0b00111111;
        _delay_us(100);
        PORTD = 0x20;  // e
        PORTB = 0b00111111;
        _delay_us(100);
        PORTD = 0x10;  // 1
        PORTB = 0b00001100;
        _delay_us(1);
        PORTB = 0b00111111;
        _delay_us(99);
        PORTD = 0x08;  // 7
        PORTB = 0b00100001;
        _delay_us(2);
        PORTB = 0b00111111;
        _delay_us(98);
        PORTD = 0x04;  // 2
        PORTB = 0b00110011;
        _delay_us(5);
        PORTB = 0b00111111;
        _delay_us(95);

        j++;
      }

      while (j < waktuTiapInterval * 20 && PINC & 0b00010000) {
        PORTD = 0x80;  // c
        PORTB = 0b00111111;
        _delay_us(100);
        PORTD = 0x40;  // 8
        PORTB = 0b00111111;
        _delay_us(100);
        PORTD = 0x20;  // e
        PORTB = 0b00111111;
        _delay_us(100);
        PORTD = 0x10;  // 1
        PORTB = 0b00111111;
        _delay_us(100);
        PORTD = 0x08;  // 7
        PORTB = 0b00100001;
        _delay_us(1);
        PORTB = 0b00111111;
        _delay_us(99);
        PORTD = 0x04;  // 2
        PORTB = 0b00110011;
        _delay_us(2);
        PORTB = 0b00111111;
        _delay_us(98);

        j++;
      }

      while (j < waktuTiapInterval * 21 && PINC & 0b00010000) {
        PORTD = 0x80;  // c
        PORTB = 0b00111111;
        _delay_us(100);
        PORTD = 0x40;  // 8
        PORTB = 0b00111111;
        _delay_us(100);
        PORTD = 0x20;  // e
        PORTB = 0b00111111;
        _delay_us(100);
        PORTD = 0x10;  // 1
        PORTB = 0b00111111;
        _delay_us(100);
        PORTD = 0x08;  // 7
        PORTB = 0b00111111;
        _delay_us(100);
        PORTD = 0x04;  // 2
        PORTB = 0b00110011;
        _delay_us(1);
        PORTB = 0b00111111;
        _delay_us(99);

        j++;
      }
      goto loop;
    }



    else if (PINC & 0b00100000) {  // STOP
      while (j < waktuTiapFrame && PINC & 0b00100000 && !(PINC & 0b00010000)) {
        PORTD = 0x80;  // c
        PORTB = 0b00011110;
        _delay_us(delayPerBaris);
        PORTD = 0x40;  // 8
        PORTB = 0b00100001;
        _delay_us(delayPerBaris);
        PORTD = 0x20;  // e
        PORTB = 0b00100001;
        _delay_us(delayPerBaris);
        PORTD = 0x10;  // 1
        PORTB = 0b00100001;
        _delay_us(delayPerBaris);
        PORTD = 0x08;  // 7
        PORTB = 0b00100001;
        _delay_us(delayPerBaris);
        PORTD = 0x04;  // 2
        PORTB = 0b00011110;
        _delay_us(delayPerBaris);

        j++;
      }
    } 



    else if (PINC & 0b00001000) {  // KIRI
      while (j < waktuTiapFrame * 0 && PINC & 0b00001000 && !(PINC & 0b00010000) && !(PINC & 0b00010000)) {
        PORTD = 0x80;  // c
        PORTB = 0b00111111;
        _delay_us(delayPerBaris);
        PORTD = 0x40;  // 8
        PORTB = 0b00111111;
        _delay_us(delayPerBaris);
        PORTD = 0x20;  // e
        PORTB = 0b00111111;
        _delay_us(delayPerBaris);
        PORTD = 0x10;  // 1
        PORTB = 0b00111111;
        _delay_us(delayPerBaris);
        PORTD = 0x08;  // 7
        PORTB = 0b00111111;
        _delay_us(delayPerBaris);
        PORTD = 0x04;  // 2
        PORTB = 0b00111111;
        _delay_us(delayPerBaris);

        j++;
      }

      while (j < waktuTiapFrame * 1 && PINC & 0b00001000 && !(PINC & 0b00010000)) {
        PORTD = 0x80;  // c
        PORTB = 0b00111111;
        _delay_us(delayPerBaris);
        PORTD = 0x40;  // 8
        PORTB = 0b00111111;
        _delay_us(delayPerBaris);
        PORTD = 0x20;  // e
        PORTB = 0b00111111;
        _delay_us(delayPerBaris);
        PORTD = 0x10;  // 1
        PORTB = 0b00111111;
        _delay_us(delayPerBaris);
        PORTD = 0x08;  // 7
        PORTB = 0b00111111;
        _delay_us(delayPerBaris);
        PORTD = 0x04;  // 2
        PORTB = 0b00111100;
        _delay_us(delayPerBaris);

        j++;
      }

      while (j < waktuTiapFrame * 2 && PINC & 0b00001000 && !(PINC & 0b00010000)) {
        PORTD = 0x80;  // c
        PORTB = 0b00111111;
        _delay_us(delayPerBaris);
        PORTD = 0x40;  // 8
        PORTB = 0b00111111;
        _delay_us(delayPerBaris);
        PORTD = 0x20;  // e
        PORTB = 0b00111111;
        _delay_us(delayPerBaris);
        PORTD = 0x10;  // 1
        PORTB = 0b00111110;
        _delay_us(delayPerBaris);
        PORTD = 0x08;  // 7
        PORTB = 0b00111100;
        _delay_us(delayPerBaris);
        PORTD = 0x04;  // 2
        PORTB = 0b00111100;
        _delay_us(delayPerBaris);

        j++;
      }

      while (j < waktuTiapFrame * 3 && PINC & 0b00001000 && !(PINC & 0b00010000)) {
        PORTD = 0x80;  // c
        PORTB = 0b00111111;
        _delay_us(delayPerBaris);
        PORTD = 0x40;  // 8
        PORTB = 0b00111111;
        _delay_us(delayPerBaris);
        PORTD = 0x20;  // e
        PORTB = 0b001111101;
        _delay_us(delayPerBaris);
        PORTD = 0x10;  // 1
        PORTB = 0b00111000;
        _delay_us(delayPerBaris);
        PORTD = 0x08;  // 7
        PORTB = 0b00111100;
        _delay_us(delayPerBaris);
        PORTD = 0x04;  // 2
        PORTB = 0b00111100;
        _delay_us(delayPerBaris);

        j++;
      }

      while (j < waktuTiapFrame * 4 && PINC & 0b00001000 && !(PINC & 0b00010000)) {
        PORTD = 0x80;  // c
        PORTB = 0b00111111;
        _delay_us(delayPerBaris);
        PORTD = 0x40;  // 8
        PORTB = 0b00111111;
        _delay_us(delayPerBaris);
        PORTD = 0x20;  // e
        PORTB = 0b00110001;
        _delay_us(delayPerBaris);
        PORTD = 0x10;  // 1
        PORTB = 0b00110000;
        _delay_us(delayPerBaris);
        PORTD = 0x08;  // 7
        PORTB = 0b00111100;
        _delay_us(delayPerBaris);
        PORTD = 0x04;  // 2
        PORTB = 0b00111100;
        _delay_us(delayPerBaris);

        j++;
      }

      while (j < waktuTiapFrame * 5 && PINC & 0b00001000 && !(PINC & 0b00010000)) {
        PORTD = 0x80;  // c
        PORTB = 0b00111111;
        _delay_us(delayPerBaris);
        PORTD = 0x40;  // 8
        PORTB = 0b00110111;
        _delay_us(delayPerBaris);
        PORTD = 0x20;  // e
        PORTB = 0b00100001;
        _delay_us(delayPerBaris);
        PORTD = 0x10;  // 1
        PORTB = 0b00100000;
        _delay_us(delayPerBaris);
        PORTD = 0x08;  // 7
        PORTB = 0b00110100;
        _delay_us(delayPerBaris);
        PORTD = 0x04;  // 2
        PORTB = 0b00111100;
        _delay_us(delayPerBaris);

        j++;
      }

      while (j < waktuTiapFrame * 6 && PINC & 0b00001000 && !(PINC & 0b00010000)) {
        PORTD = 0x80;  // c
        PORTB = 0b00110111;
        _delay_us(delayPerBaris);
        PORTD = 0x40;  // 8
        PORTB = 0b00100111;
        _delay_us(delayPerBaris);
        PORTD = 0x20;  // e
        PORTB = 0b00000001;
        _delay_us(delayPerBaris);
        PORTD = 0x10;  // 1
        PORTB = 0b00000000;
        _delay_us(delayPerBaris);
        PORTD = 0x08;  // 7
        PORTB = 0b00100100;
        _delay_us(delayPerBaris);
        PORTD = 0x04;  // 2
        PORTB = 0b00110100;
        _delay_us(delayPerBaris);

        j++;
      }

      while (j < waktuTiapFrame * 7 && PINC & 0b00001000 && !(PINC & 0b00010000)) {
        PORTD = 0x80;  // c
        PORTB = 0b00110111;
        _delay_us(delayPerBaris);
        PORTD = 0x40;  // 8
        PORTB = 0b00100111;
        _delay_us(delayPerBaris);
        PORTD = 0x20;  // e
        PORTB = 0b00000001;
        _delay_us(delayPerBaris);
        PORTD = 0x10;  // 1
        PORTB = 0b00000000;
        _delay_us(delayPerBaris);
        PORTD = 0x08;  // 7
        PORTB = 0b00100100;
        _delay_us(delayPerBaris);
        PORTD = 0x04;  // 2
        PORTB = 0b00110111;
        _delay_us(delayPerBaris);

        j++;
      }

      while (j < waktuTiapFrame * 8 && PINC & 0b00001000 && !(PINC & 0b00010000)) {
        PORTD = 0x80;  // c
        PORTB = 0b00110111;
        _delay_us(delayPerBaris);
        PORTD = 0x40;  // 8
        PORTB = 0b00100111;
        _delay_us(delayPerBaris);
        PORTD = 0x20;  // e
        PORTB = 0b00000001;
        _delay_us(delayPerBaris);
        PORTD = 0x10;  // 1
        PORTB = 0b00000001;
        _delay_us(delayPerBaris);
        PORTD = 0x08;  // 7
        PORTB = 0b00100111;
        _delay_us(delayPerBaris);
        PORTD = 0x04;  // 2
        PORTB = 0b00110111;
        _delay_us(delayPerBaris);

        j++;
      }

      while (j < waktuTiapFrame * 9 && PINC & 0b00001000 && !(PINC & 0b00010000)) {
        PORTD = 0x80;  // c
        PORTB = 0b00110111;
        _delay_us(delayPerBaris);
        PORTD = 0x40;  // 8
        PORTB = 0b00100111;
        _delay_us(delayPerBaris);
        PORTD = 0x20;  // e
        PORTB = 0b00000011;
        _delay_us(delayPerBaris);
        PORTD = 0x10;  // 1
        PORTB = 0b00000111;
        _delay_us(delayPerBaris);
        PORTD = 0x08;  // 7
        PORTB = 0b00100111;
        _delay_us(delayPerBaris);
        PORTD = 0x04;  // 2
        PORTB = 0b00110111;
        _delay_us(delayPerBaris);

        j++;
      }

      while (j < waktuTiapFrame * 10 && PINC & 0b00001000 && !(PINC & 0b00010000)) {
        PORTD = 0x80;  // c
        PORTB = 0b00110111;
        _delay_us(delayPerBaris);
        PORTD = 0x40;  // 8
        PORTB = 0b00100111;
        _delay_us(delayPerBaris);
        PORTD = 0x20;  // e
        PORTB = 0b00001111;
        _delay_us(delayPerBaris);
        PORTD = 0x10;  // 1
        PORTB = 0b00001111;
        _delay_us(delayPerBaris);
        PORTD = 0x08;  // 7
        PORTB = 0b00100111;
        _delay_us(delayPerBaris);
        PORTD = 0x04;  // 2
        PORTB = 0b00110111;
        _delay_us(delayPerBaris);

        j++;
      }

      while (j < waktuTiapFrame * 11 && PINC & 0b00001000 && !(PINC & 0b00010000)) {
        PORTD = 0x80;  // c
        PORTB = 0b00110111;
        _delay_us(delayPerBaris);
        PORTD = 0x40;  // 8
        PORTB = 0b00101111;
        _delay_us(delayPerBaris);
        PORTD = 0x20;  // e
        PORTB = 0b00011111;
        _delay_us(delayPerBaris);
        PORTD = 0x10;  // 1
        PORTB = 0b00011111;
        _delay_us(delayPerBaris);
        PORTD = 0x08;  // 7
        PORTB = 0b00101111;
        _delay_us(delayPerBaris);
        PORTD = 0x04;  // 2
        PORTB = 0b00110111;
        _delay_us(delayPerBaris);

        j++;
      }
    }
    


    else if (PINC & 0b00000100) {  // KANAN
      while (j < waktuTiapFrame * 0 && PINC & 0b00000100 && !(PINC & 0b00010000)) {
        PORTD = 0x80;  // c
        PORTB = 0b00111111;
        _delay_us(delayPerBaris);
        PORTD = 0x40;  // 8
        PORTB = 0b00111111;
        _delay_us(delayPerBaris);
        PORTD = 0x20;  // e
        PORTB = 0b00111111;
        _delay_us(delayPerBaris);
        PORTD = 0x10;  // 1
        PORTB = 0b00111111;
        _delay_us(delayPerBaris);
        PORTD = 0x08;  // 7
        PORTB = 0b00111111;
        _delay_us(delayPerBaris);
        PORTD = 0x04;  // 2
        PORTB = 0b00111111;
        _delay_us(delayPerBaris);

        j++;
      }

      while (j < waktuTiapFrame * 1 && PINC & 0b00000100 && !(PINC & 0b00010000)) {
        PORTD = 0x80;  // c
        PORTB = 0b00111111;
        _delay_us(delayPerBaris);
        PORTD = 0x40;  // 8
        PORTB = 0b00111111;
        _delay_us(delayPerBaris);
        PORTD = 0x20;  // e
        PORTB = 0b00111111;
        _delay_us(delayPerBaris);
        PORTD = 0x10;  // 1
        PORTB = 0b00111111;
        _delay_us(delayPerBaris);
        PORTD = 0x08;  // 7
        PORTB = 0b00111111;
        _delay_us(delayPerBaris);
        PORTD = 0x04;  // 2
        PORTB = 0b00001111;
        _delay_us(delayPerBaris);

        j++;
      }

      while (j < waktuTiapFrame * 2 && PINC & 0b00000100 && !(PINC & 0b00010000)) {
        PORTD = 0x80;  // c
        PORTB = 0b00111111;
        _delay_us(delayPerBaris);
        PORTD = 0x40;  // 8
        PORTB = 0b00111111;
        _delay_us(delayPerBaris);
        PORTD = 0x20;  // e
        PORTB = 0b00111111;
        _delay_us(delayPerBaris);
        PORTD = 0x10;  // 1
        PORTB = 0b00011111;
        _delay_us(delayPerBaris);
        PORTD = 0x08;  // 7
        PORTB = 0b00001111;
        _delay_us(delayPerBaris);
        PORTD = 0x04;  // 2
        PORTB = 0b00001111;
        _delay_us(delayPerBaris);

        j++;
      }

      while (j < waktuTiapFrame * 3 && PINC & 0b00000100 && !(PINC & 0b00010000)) {
        PORTD = 0x80;  // c
        PORTB = 0b00111111;
        _delay_us(delayPerBaris);
        PORTD = 0x40;  // 8
        PORTB = 0b00111111;
        _delay_us(delayPerBaris);
        PORTD = 0x20;  // e
        PORTB = 0b00101111;
        _delay_us(delayPerBaris);
        PORTD = 0x10;  // 1
        PORTB = 0b00000111;
        _delay_us(delayPerBaris);
        PORTD = 0x08;  // 7
        PORTB = 0b00001111;
        _delay_us(delayPerBaris);
        PORTD = 0x04;  // 2
        PORTB = 0b00001111;
        _delay_us(delayPerBaris);

        j++;
      }

      while (j < waktuTiapFrame * 4 && PINC & 0b00000100 && !(PINC & 0b00010000)) {
        PORTD = 0x80;  // c
        PORTB = 0b00111111;
        _delay_us(delayPerBaris);
        PORTD = 0x40;  // 8
        PORTB = 0b00111111;
        _delay_us(delayPerBaris);
        PORTD = 0x20;  // e
        PORTB = 0b00100011;
        _delay_us(delayPerBaris);
        PORTD = 0x10;  // 1
        PORTB = 0b00000011;
        _delay_us(delayPerBaris);
        PORTD = 0x08;  // 7
        PORTB = 0b00001111;
        _delay_us(delayPerBaris);
        PORTD = 0x04;  // 2
        PORTB = 0b00001111;
        _delay_us(delayPerBaris);

        j++;
      }

      while (j < waktuTiapFrame * 5 && PINC & 0b00000100 && !(PINC & 0b00010000)) {
        PORTD = 0x80;  // c
        PORTB = 0b00111111;
        _delay_us(delayPerBaris);
        PORTD = 0x40;  // 8
        PORTB = 0b00111011;
        _delay_us(delayPerBaris);
        PORTD = 0x20;  // e
        PORTB = 0b00100001;
        _delay_us(delayPerBaris);
        PORTD = 0x10;  // 1
        PORTB = 0b00000001;
        _delay_us(delayPerBaris);
        PORTD = 0x08;  // 7
        PORTB = 0b00001011;
        _delay_us(delayPerBaris);
        PORTD = 0x04;  // 2
        PORTB = 0b00001111;
        _delay_us(delayPerBaris);

        j++;
      }

      while (j < waktuTiapFrame * 6 && PINC & 0b00000100 && !(PINC & 0b00010000)) {
        PORTD = 0x80;  // c
        PORTB = 0b00111011;
        _delay_us(delayPerBaris);
        PORTD = 0x40;  // 8
        PORTB = 0b00111001;
        _delay_us(delayPerBaris);
        PORTD = 0x20;  // e
        PORTB = 0b00100000;
        _delay_us(delayPerBaris);
        PORTD = 0x10;  // 1
        PORTB = 0b00000000;
        _delay_us(delayPerBaris);
        PORTD = 0x08;  // 7
        PORTB = 0b00001001;
        _delay_us(delayPerBaris);
        PORTD = 0x04;  // 2
        PORTB = 0b00001011;
        _delay_us(delayPerBaris);

        j++;
      }

      while (j < waktuTiapFrame * 7 && PINC & 0b00000100 && !(PINC & 0b00010000)) {
        PORTD = 0x80;  // c
        PORTB = 0b00111011;
        _delay_us(delayPerBaris);
        PORTD = 0x40;  // 8
        PORTB = 0b00111001;
        _delay_us(delayPerBaris);
        PORTD = 0x20;  // e
        PORTB = 0b00100000;
        _delay_us(delayPerBaris);
        PORTD = 0x10;  // 1
        PORTB = 0b00000000;
        _delay_us(delayPerBaris);
        PORTD = 0x08;  // 7
        PORTB = 0b00001001;
        _delay_us(delayPerBaris);
        PORTD = 0x04;  // 2
        PORTB = 0b00111011;
        _delay_us(delayPerBaris);

        j++;
      }

      while (j < waktuTiapFrame * 8 && PINC & 0b00000100 && !(PINC & 0b00010000)) {
        PORTD = 0x80;  // c
        PORTB = 0b00111011;
        _delay_us(delayPerBaris);
        PORTD = 0x40;  // 8
        PORTB = 0b00111001;
        _delay_us(delayPerBaris);
        PORTD = 0x20;  // e
        PORTB = 0b00100000;
        _delay_us(delayPerBaris);
        PORTD = 0x10;  // 1
        PORTB = 0b00100000;
        _delay_us(delayPerBaris);
        PORTD = 0x08;  // 7
        PORTB = 0b00111001;
        _delay_us(delayPerBaris);
        PORTD = 0x04;  // 2
        PORTB = 0b00111011;
        _delay_us(delayPerBaris);

        j++;
      }

      while (j < waktuTiapFrame * 9 && PINC & 0b00000100 && !(PINC & 0b00010000)) {
        PORTD = 0x80;  // c
        PORTB = 0b00111011;
        _delay_us(delayPerBaris);
        PORTD = 0x40;  // 8
        PORTB = 0b00111001;
        _delay_us(delayPerBaris);
        PORTD = 0x20;  // e
        PORTB = 0b00110000;
        _delay_us(delayPerBaris);
        PORTD = 0x10;  // 1
        PORTB = 0b00111000;
        _delay_us(delayPerBaris);
        PORTD = 0x08;  // 7
        PORTB = 0b00111001;
        _delay_us(delayPerBaris);
        PORTD = 0x04;  // 2
        PORTB = 0b00111011;
        _delay_us(delayPerBaris);

        j++;
      }

      while (j < waktuTiapFrame * 10 && PINC & 0b00000100 && !(PINC & 0b00010000)) {
        PORTD = 0x80;  // c
        PORTB = 0b00111011;
        _delay_us(delayPerBaris);
        PORTD = 0x40;  // 8
        PORTB = 0b00111001;
        _delay_us(delayPerBaris);
        PORTD = 0x20;  // e
        PORTB = 0b00111100;
        _delay_us(delayPerBaris);
        PORTD = 0x10;  // 1
        PORTB = 0b00111100;
        _delay_us(delayPerBaris);
        PORTD = 0x08;  // 7
        PORTB = 0b00111001;
        _delay_us(delayPerBaris);
        PORTD = 0x04;  // 2
        PORTB = 0b00111011;
        _delay_us(delayPerBaris);

        j++;
      }

      while (j < waktuTiapFrame * 11 && PINC & 0b00000100 && !(PINC & 0b00010000)) {
        PORTD = 0x80;  // c
        PORTB = 0b00111011;
        _delay_us(delayPerBaris);
        PORTD = 0x40;  // 8
        PORTB = 0b00111101;
        _delay_us(delayPerBaris);
        PORTD = 0x20;  // e
        PORTB = 0b00111110;
        _delay_us(delayPerBaris);
        PORTD = 0x10;  // 1
        PORTB = 0b00111110;
        _delay_us(delayPerBaris);
        PORTD = 0x08;  // 7
        PORTB = 0b00111101;
        _delay_us(delayPerBaris);
        PORTD = 0x04;  // 2
        PORTB = 0b00111011;
        _delay_us(delayPerBaris);

        j++;
      }
    }

    else {PORTC = 0x00; PORTD = 0x00;}  // Cleanup
  goto loop;
}