/**
 * File:   domopi_rrf24l01.h
 * Author: samuel
 *
 * Created on June 23, 2015, 12:12 PM
 */

/*
 *       ___________________
 *      |____               |
 * GND  |1  2| 3.3V         |
 * CE   |3  4| CSN          |
 * SCX  |5  6| MOSI         |
 * MISQ |7__8| IRQ          |
 *      |___________________|
 */

#ifndef DOMOPI_NRF24L01_H
#define	DOMOPI_NRF24L01_H

#ifdef	__cplusplus
extern "C" {
#endif

/* Configurations */
// This signal is active low and controlled by three maskable interrupt sources.
#define IRQ     PORTBbits.RB0;
// This signal is active high and used to activate the chip in RX or TX mode.
#define CE      PORTBbits.RB1;
// Every new SPI command must be started by a high to low transition.
#define CSN     PORTBbits.RB2;
// SPI signal
#define SCX     PORTBbits.RB3;
// SPI signal
#define MOSI    PORTBbits.RB4;
// SPI signal
#define MISQ    PORTBbits.RB5;

// Define commands for Nordic via SPI
#define R_REGISTER    0x00
#define W_REGISTER    0x20
#define R_RX_PAYLOAD  0x61
#define W_TX_PAYLOAD  0xA0
#define FLUSH_TX      0xE1
#define FLUSH_RX      0xE2
#define REUSE_TX_PL   0xE3
#define NOP           0xFF
    
    
#ifdef	__cplusplus
}
#endif

#endif	/* DOMOPI_NRF24L01_H */
