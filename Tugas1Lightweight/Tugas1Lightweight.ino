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
  uint8_t portBValuesRight[6] = {0b00011111, 0b00001111, 0b00000111, 0b00001111, 0b00011111, 0b00101101};
  uint8_t portBValuesLeft[6] = {0b00111110, 0b00111100, 0b00111000, 0b00111100, 0b00111110, 0b00101101};
  int numRows = 6;
  int refreshCount = 0;
  int updatesPerShift = 10;  // Number of frame refreshes before shifting

  loop:
    j = waktuTiapFrame * -1;



    if (PINC & 0b00010000) {  // HAZARD
      j = waktuTiapInterval * -1;
      while (j < waktuTiapInterval * 20 && PINC & 0b00010000) {
        PORTD = 0x84;  // c 2
        PORTB = 0b00110011;
        _delay_us(100);
        PORTD = 0x48;  // 8 7
        PORTB = 0b00100001;
        _delay_us(100);
        PORTD = 0b00110000;  // e 1
        PORTB = 0b00001100;
        _delay_us(100);

        j++;
      }

      while (j < waktuTiapInterval * 40 && PINC & 0b00010000) {
        PORTD = 0x00;
        PORTB = 0b00;
        _delay_us(300);

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
      goto loop;
    } 



    else if (PINC & 0b00001000) {  // KIRI
      while (PINC & 0b00001000 && !(PINC & 0b00010000) && !(PINC & 0b00100000)) {
        for (int i = 0; i < numRows; i++) {
          PORTD = (0x80 >> i);  // Select row
          PORTB = portBValuesLeft[i];  // Set column pattern
          _delay_us(delayPerBaris);  // Maintain a fast frame update rate
        }

        refreshCount++;

        if (refreshCount >= updatesPerShift) {
          refreshCount = 0;  // Reset the counter

          // Perform the shift and warp for all rows
          for (int i = 0; i < numRows; i++) {
              uint8_t msb = (portBValuesLeft[i] & 0b00100000) >> 5;  // Extract the LSB
              portBValuesLeft[i] = (portBValuesLeft[i] << 1) & 0b00111110;  // Shift right and clear MSB
              portBValuesLeft[i] |= (msb << 0);  // Warp MSB to 3rd bit from the left(???)
          }
        }
      }
      j++;
    }
    


    else if (PINC & 0b00000100) {  // KANAN
      while (PINC & 0b00000100 && !(PINC & 0b00010000) && !(PINC & 0b00100000)) {
        for (int i = 0; i < numRows; i++) {
          PORTD = (0x80 >> i);  // Select row
          PORTB = portBValuesRight[i];  // Set column pattern
          _delay_us(delayPerBaris);  // Maintain a fast frame update rate
        }

        refreshCount++;

        if (refreshCount >= updatesPerShift) {
          refreshCount = 0;  // Reset the counter

          // Perform the shift and warp for all rows
          for (int i = 0; i < numRows; i++) {
              uint8_t lsb = (portBValuesRight[i] & 0b00000001);  // Extract the LSB
              portBValuesRight[i] = (portBValuesRight[i] >> 1) & 0b01111111;  // Shift right and clear MSB
              portBValuesRight[i] |= (lsb << 5);  // Warp LSB to 3rd bit from the left (bit position 5)
          }
        }
      }
      j++;
    }

    else {PORTC = 0x00; PORTD = 0x00;}  // Cleanup
  goto loop;
}