/*
 * File:   main.c
 * Author: VINAYAK ACHARYA
 *
 * Created on 2 February, 2026, 4:35 PM
 */


#include <xc.h>
#include"header.h"

static unsigned char ssd[MAX_SSD_CNT];
static unsigned char digit[] = {ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE};

void init_config() {
    //    TRISB = 0x00;
    //    PORTB = 0x00;
    init_digital_keypad();
    init_ssd_control();
}

void main(void) {
    unsigned char key;
    unsigned int delay = 0;
    unsigned int count = 0;
    init_config();
    while (1) {
        key = read_digital_keypad(LEVEL);
        if (SWITCH1 == key) {
            if (delay++ > 200) {
                count = 0;
            }
        } else if (delay > 0 && delay < 200) {
            count++;
            delay = 0;
        } else {
            delay = 0;
        }

        ssd[3] = digit[count % 10];
        ssd[2] = digit[(count / 10) % 10];
        ssd[1] = digit[(count / 100) % 10];
        ssd[0] = digit[count / 1000];

        display(ssd);
        if (count > 9999)
            count = 0;
    }
}
