/* Original idea from : https://github.com/tuupola/avr_demo/tree/master/blog/simple_usart  -- code was a bit tweaked */
#ifndef __LANTERN_UART_H__
#define __LANTERN_UART_H__

#include <stdio.h>


void avr_uart_putchar(char c, FILE *stream);
char avr_uart_getchar(FILE *stream);

void avr_uart_init(void);

extern FILE avr_uart_output;
extern FILE avr_uart_input;
extern FILE avr_uart_input_echo;

#endif
