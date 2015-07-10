/* 
 * File:   domopi_rrf24l01.h
 * Author: samuel
 *
 * Created on June 23, 2015, 12:12 PM
 */

/**
 *       ___________________
 *      |____               |
 * GND  |1  2| 3.3V         |
 * CE   |3  4| CSN          |
 * SCX  |5  6| MOSI         |
 * MISQ |7__8| IRQ          |
 *      |___________________|
 */

#ifndef DOMOPI_RRF24L01_H
#define	DOMOPI_RRF24L01_H

#ifdef	__cplusplus
extern "C" {
#endif

/* 
 * Configurations 
 */

/**
 * Power Down Mode
 * Power down mode is entered by setting:
 *      PWR_UP bit in the CONFIG register low
 */

/*
 * RX mode
 * To enter this mode, the nRF24L01 must have:
 *      PWR_UP bit set high
 *      PRIM_RX bit set high
 *      CE pin set high
 */
#define     RX_MODE     1;

/*
 * TX mode
 * To enter this mode, the nRF24L01 must have:
 *      PWR_UP bit set high
 *      PRIM_RX bit set low
 *      a payload in the TX FIFO
 *      a high pulse on the CE for more than 10μs.
 */
#define     TX_MODE     0;

#ifdef	__cplusplus
}
#endif

#endif	/* DOMOPI_RRF24L01_H */

