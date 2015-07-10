##The module has following pins connecting to a microcontroller:

1. GND: Ground.
2. VCC: 3.3V.
3. CE: Chip (RX/TX) Enable, high active. If high, module is either sending or listening.
4. CSN: Chip Select Not, low active. If low, the chip responds to SPI commands. This is actually the ‘real’ chip select signal, and is easily confusing with CE which enables/disables the transceiver radio part.
5. SCK: SPI Shift Clock, up to 10 MHz.
6. MOSI: Master-Out-Slave-In, used to shift data from the microcontroller to the device.
7. MISO: Master-In-Slave-Out, used to shift data from the device to the microcontroller.
8. IRQ: Optional Interrupt Request pin. Signals RX/TX status like packet sent or received.

## Operational modes configuration
|Mode       |PWR_UP     |PRIM_RX    |CE         |FIFO state                                             |
|-----------|-----------|-----------|-----------|-------------------------------------------------------|
|RX         |1          |1          |1          |-                                                      |
|TX         |1          |0          |1          |Data in TX FIFO. Will empty all levels in TX FIFO(a)   |          |
|TX         |1          |0          |>= 10us    |Data in TX FIFO. Will empty one level in TX FIFO(b)    |           |
|STBY-II    |1          |0          |1          |TX FIFO empty                                          |
|STBY-I     |1          |-          |0          |No ongoing packet transmission                         |
|Power Down |0          |-          |-          |-                                                      |

a. In this operating mode if the CE is held high the TX FIFO is emptied an all necessary ACK an posible
   retrasmits are carried out. The transmission continues as long as the TX FIFO is refilled. If the
   TX FIFO is empty when the CE is still high, nRF24L01 enters standby-II mode. In this mode the transmission
   of a packet is started as soon as the CSN is set high after a upload(UL) of a packet to TX FIFO.
b. This operating mode pulses the CE high for at least 10us. This allows one packet to be transmitted.
   This is the normal operating mode. After the packet is transmittet, the nRF24L01 enters standby-I mode.

## References

* [Tutorial: Ultra Low Cost 2.4 GHz Wireless Transceiver with the FRDM Board](http://mcuoneclipse.com/2013/07/20/tutorial-ultra-low-cost-2-4-ghz-wireless-transceiver-with-the-frdm-board/)

## Video References

* [10 - Microcontroladores PIC - Comunicação PIC+nRF24L01+](https://www.youtube.com/watch?v=Pj-enHa2wvU)

