##The module has following pins connecting to a microcontroller:

1. GND: Ground.
2. VCC: 3.3V.
3. CE: Chip (RX/TX) Enable, high active. If high, module is either sending or listening.
4. CSN: Chip Select Not, low active. If low, the chip responds to SPI commands. This is actually the ‘real’ chip select signal, and is easily confusing with CE which enables/disables the transceiver radio part.
5. SCK: SPI Shift Clock, up to 10 MHz.
6. MOSI: Master-Out-Slave-In, used to shift data from the microcontroller to the device.
7. MISO: Master-In-Slave-Out, used to shift data from the device to the microcontroller.
8. IRQ: Optional Interrupt Request pin. Signals RX/TX status like packet sent or received.

## References

* [Tutorial: Ultra Low Cost 2.4 GHz Wireless Transceiver with the FRDM Board](http://mcuoneclipse.com/2013/07/20/tutorial-ultra-low-cost-2-4-ghz-wireless-transceiver-with-the-frdm-board/)

