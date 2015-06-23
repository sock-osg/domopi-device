#include <p18f2550.h> //PIC 8bits
#FUSES NOWDT //No Watch Dog Timer
#FUSES XT //Crystal osc <= 4mhz for PCM/PCH , 3mhz to 10 mhz for PCD
#FUSES PUT //Power Up Timer
#FUSES NOPROTECT //Code not protected from reading
#FUSES NODEBUG //No Debug mode for ICD
#FUSES NOBROWNOUT //No brownout reset
#FUSES NOLVP //No low voltage prgming, B3(PIC16) or B5(PIC18) used for I/O
#FUSES NOCPD //No EE protection
#FUSES NOWRT //Program memory not write protected
#use delay(clock=4000000) //Clock de 4MHZ externo
#include <nrf24l01p.c>
#include <flex_lcd.c>
//variaveis
int8 a, b, c, d;
int8 teste[10] = {1, 2, 3, 4, 5, 6, 7, 8};
//programa principal

void main() {
    setup_adc_ports(NO_ANALOGS);
    setup_adc(ADC_OFF);
    setup_spi(SPI_SS_DISABLED);
    setup_timer_0(RTCC_INTERNAL | RTCC_DIV_1);
    setup_timer_1(T1_DISABLED);
    setup_timer_2(T2_DISABLED, 0, 1);
    setup_comparator(NC_NC_NC_NC);
    setup_vref(FALSE);
    //inicia e configura LCD
    lcd_init();
    //inicia e configura modulo
    config_nrf24();
    while (true) {
        output_high(pin_C0);
        Delay_ms(500);
        output_low(pin_C0);
        Delay_ms(500);
        ENVIA[0] = teste[0]++;
        ENVIA[1] = teste[1]++;
        ENVIA[2] = teste[2]++;
        ENVIA[3] = teste[3]++;
        ENVIA[4] = teste[4]++;
        ENVIA[5] = teste[5]++;
        ENVIA[6] = teste[6]++;
        ENVIA[7] = teste[7]++;
        ENVIA[8] = teste[8]++;
        ENVIA[9] = teste[9]++;
        //le status
        output_low(CSN);
        spi_write(0x07);
        a = spi_read(0);
        output_high(CSN);
        //le config
        output_low(CSN);
        spi_write(0x00);
        b = spi_read(0);
        output_high(CSN);
        // EN_RXADDR
        output_low(CSN);
        spi_write(0x02);
        c = spi_read(0);
        output_high(CSN);
        //RX_PW0
        output_low(CSN);
        spi_write(0x0A);
        d = spi_read(0);
        output_high(CSN);
        printf(lcd_putc, "\f%u,%u,%u,%u\n%X,%X,%X,%X"
                RECEBE[0], RECEBE[1], RECEBE[2], RECEBE[3], a, b, c, d);
        ACK = envia_dados();
    }
}
