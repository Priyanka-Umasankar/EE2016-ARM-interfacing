#include <LPC214X.H>
#include "led.h"
#include "delay.h"

void display_hex_on_leds(unsigned char hex_val) {
    Led_Off_All(); // Clear all LEDs
    if (hex_val & 0x01) LED1_ON; // LED0
    if (hex_val & 0x02) LED2_ON; // LED1
    if (hex_val & 0x04) LED3_ON; // LED2
    if (hex_val & 0x08) LED4_ON; // LED3
    if (hex_val & 0x10) LED5_ON; // LED4
    if (hex_val & 0x20) LED6_ON; // LED5
    if (hex_val & 0x40) LED7_ON; // LED6
    if (hex_val & 0x80) LED8_ON; // LED7
}

int main(void) {
    unsigned int roll_number = 60; // Replace with your actual roll number
    unsigned char hex_val = roll_number % 1000; // Get the last three digits

    set_led_port_output(); // Initialize LED port

    while (1) {
if (hex_val & 0x01) LED1_ON; // LED0
if (hex_val & 0x02) LED2_ON; // LED1
if (hex_val & 0x04) LED3_ON; // LED2
if (hex_val & 0x08) LED4_ON; // LED3
if (hex_val & 0x10) LED5_ON; // LED4
if (hex_val & 0x20) LED6_ON; // LED5
if (hex_val & 0x40) LED7_ON; // LED6
if (hex_val & 0x80) LED8_ON; // LED7
delay_mSec(10); // Delay for visibility
    }
    return 0;
}
