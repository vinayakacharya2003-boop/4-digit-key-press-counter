/*
 * File:   dkp.c
 * Author: VINAYAK ACHARYA
 *
 * Created on 2 February, 2026, 4:35 PM
 */


#include <xc.h>
#include"header.h"

void init_digital_keypad(void) {
    TRISC = (TRISC | 0x0F);
}

unsigned char read_digital_keypad(unsigned char type) {
    static unsigned char flag = 0;
    if (type == LEVEL) {
        return (PORTC & 0x0F);
    } else if (type == EDGE) {
        if (((PORTC & 0x0F) != 0x0F) && (flag == 0)) {
            flag = 1;
            return (PORTC & 0x0F);
        } else if ((PORTC & 0x0F) == 0x0F) {
            flag = 0;
        }

    }
    return 0x0F;
}
