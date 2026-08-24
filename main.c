#include <stdint.h>

#define RCC_BASE      0x40021000
#define PWR_BASE      0x40007400
#define GPIOA_BASE    0x48000000
#define GPIOB_BASE    0x48000400
#define GPIOC_BASE    0x48000800
#define SPI1_BASE     0x40013000
#define FLASH_BASE    0x40022000

#define GPIO_MODER    0x00
#define GPIO_OTYPER   0x04
#define GPIO_PUPDR    0x0C
#define GPIO_IDR      0x10
#define GPIO_ODR      0x14
#define GPIO_BSRR     0x18
#define GPIO_BRR      0x28

#define RCC_CR        ((volatile uint32_t *)(RCC_BASE + 0x00))
#define RCC_PLLCFGR   ((volatile uint32_t *)(RCC_BASE + 0x0C))
#define RCC_CFGR      ((volatile uint32_t *)(RCC_BASE + 0x08))
#define FLASH_ACR     ((volatile uint32_t *)(FLASH_BASE + 0x00))
#define PWR_CR1       ((volatile uint32_t *)(PWR_BASE + 0x00))
#define PWR_SR2       ((volatile uint32_t *)(PWR_BASE + 0x14))

#define SPI1_CR1      ((volatile uint32_t *)(SPI1_BASE + 0x00))
#define SPI1_CR2      ((volatile uint32_t *)(SPI1_BASE + 0x04))
#define SPI1_SR       ((volatile uint32_t *)(SPI1_BASE + 0x08))
#define SPI1_DR       ((volatile uint32_t *)(SPI1_BASE + 0x0C))

#define SPI_CS_PIN    15
#define SPI_CLK_PIN   5
#define SPI_MOSI_PIN  12
#define SPI_MISO_PIN  6
#define SPI_RST_PIN   15
#define I2C_EN_PIN    4

volatile uint32_t status_ALARM_IPM=0, status_THERM=0, status_EN_A_ACB=0, status_EN_B_ACB=0, status_PG_78_P1V0_PCIE=0, status_ALL_PLL_LOCKED=0;

/* ИСПРАВЛЕНО: Возвращено корректное объявление массивов фиксированного размера */
volatile uint8_t i2c_map[128];
volatile uint32_t discovered_devices_count;
volatile char i2c_devices_list[64] = "Not Scanned (No Power)";
volatile uint32_t flash_jedec_id = 0;

const char* pin_PA8="L", *pin_PA9="L", *pin_PA10="L", *pin_PB0="L", *pin_PB1="L", *pin_PB6="L", *pin_PB7="L";

static inline void delay_ticks(volatile uint32_t ticks) {
    while(ticks--) { __asm__ volatile("nop"); }
}

void delay_ms(volatile uint32_t ms) {
    volatile uint32_t count = ms * 16000;
    while(count--) { __asm__ volatile("nop"); }
}

void i2c3_init(void) {
    volatile uint32_t dummy; *(volatile uint32_t *)(RCC_BASE + 0x4C) |= 7;
    dummy = *(volatile uint32_t *)(RCC_BASE + 0x4C); delay_ticks(10);
    *(volatile uint32_t *)(GPIOB_BASE + GPIO_MODER) &= ~(3 << 8);
    *(volatile uint32_t *)(GPIOA_BASE + GPIO_ODR) |= (1 << 7); *(volatile uint32_t *)(GPIOB_BASE + GPIO_ODR) |= (1 << 4);
    *(volatile uint32_t *)(GPIOA_BASE + GPIO_OTYPER) |= (1 << 7); *(volatile uint32_t *)(GPIOB_BASE + GPIO_OTYPER) |= (1 << 4);
    *(volatile uint32_t *)(GPIOA_BASE + GPIO_PUPDR) &= ~(3 << 14); *(volatile uint32_t *)(GPIOA_BASE + GPIO_PUPDR) |= (1 << 14);
    *(volatile uint32_t *)(GPIOB_BASE + GPIO_PUPDR) &= ~(3 << 8); *(volatile uint32_t *)(GPIOB_BASE + GPIO_PUPDR) |= (1 << 8);
    *(volatile uint32_t *)(GPIOA_BASE + GPIO_MODER) &= ~(3 << 14); *(volatile uint32_t *)(GPIOA_BASE + GPIO_MODER) |= (1 << 14);
    *(volatile uint32_t *)(GPIOB_BASE + GPIO_MODER) &= ~(3 << 8); *(volatile uint32_t *)(GPIOB_BASE + GPIO_MODER) |= (1 << 8);
    delay_ticks(100);
}

uint16_t i2c3_ping_address(uint8_t address) {
    volatile uint32_t *GPIOA_ODR = (volatile uint32_t *)(GPIOA_BASE + GPIO_ODR);
    volatile uint32_t *GPIOB_ODR = (volatile uint32_t *)(GPIOB_BASE + GPIO_ODR);
    volatile uint32_t *GPIOB_IDR = (volatile uint32_t *)(GPIOB_BASE + GPIO_IDR);
    uint8_t sh_addr = (address << 1);
    *GPIOB_ODR |= (1 << 4); delay_ticks(5); *GPIOA_ODR |= (1 << 7); delay_ticks(5);
    *GPIOB_ODR &= ~(1 << 4); delay_ticks(5); *GPIOA_ODR &= ~(1 << 7); delay_ticks(5);
    for (int bit = 0; bit < 8; bit++) {
        if (sh_addr & (1 << (7 - bit))) *GPIOB_ODR |= (1 << 4); else *GPIOB_ODR &= ~(1 << 4);
        delay_ticks(3); *GPIOA_ODR |= (1 << 7); delay_ticks(5); *GPIOA_ODR &= ~(1 << 7); delay_ticks(3);
    }
    *GPIOB_ODR |= (1 << 4); delay_ticks(3); *GPIOA_ODR |= (1 << 7); delay_ticks(5);
    uint16_t ack = (*GPIOB_IDR & (1 << 4)) ? 0 : 1;
    delay_ticks(3); *GPIOA_ODR &= ~(1 << 7); delay_ticks(5);
    *GPIOB_ODR &= ~(1 << 4); delay_ticks(5); *GPIOA_ODR |= (1 << 7); delay_ticks(5);
    *GPIOB_ODR |= (1 << 4); delay_ticks(5); return ack;
}

void scan_i2c_bus(void) {
    discovered_devices_count = 0;
    for (int i = 0; i < 128; i++) i2c_map[i] = 0;
    for (int i = 0; i < 64; i++)  i2c_devices_list[i] = 0;
    int str_idx = 0; const char hex_chars[] = "0123456789ABCDEF";
    for (uint8_t addr = 0x08; addr < 0x78; addr++) {
        if (i2c3_ping_address(addr)) {
            i2c_map[addr] = 1; discovered_devices_count++;
            if (str_idx < 58) {
                i2c_devices_list[str_idx++] = '0'; i2c_devices_list[str_idx++] = 'x';
                i2c_devices_list[str_idx++] = hex_chars[(addr >> 4) & 0x0F]; i2c_devices_list[str_idx++] = hex_chars[addr & 0x0F];
                i2c_devices_list[str_idx++] = ' ';
            }
        }
        delay_ticks(20);
    }
    if (discovered_devices_count == 0) {
        i2c_devices_list[0]='N'; i2c_devices_list[1]='o'; i2c_devices_list[2]='n'; i2c_devices_list[3]='e'; i2c_devices_list[4]=0;
    }
}

uint8_t spi_flash_transfer(uint8_t data_out) {
    volatile uint8_t *spi_dr_8 = (volatile uint8_t *)(SPI1_BASE + 0x0C);
    while (*SPI1_SR & (1u << 0)) { volatile uint8_t dummy_rx = *spi_dr_8; (void)dummy_rx; }
    while (!(*SPI1_SR & (1u << 1)));
    *spi_dr_8 = data_out;
    while (!(*SPI1_SR & (1u << 0)));
    return *spi_dr_8;
}

uint32_t spi_flash_read_jedec_id_continuous(void) {
    volatile uint32_t *A_BSRR = (volatile uint32_t *)(GPIOA_BASE + GPIO_BSRR);
    volatile uint32_t *A_BRR  = (volatile uint32_t *)(GPIOA_BASE + GPIO_BRR);
    uint32_t id = 0;

    *A_BRR = (1u << SPI_CS_PIN);
    delay_ticks(300);

    spi_flash_transfer(0x9F);
    id |= (((uint32_t)spi_flash_transfer(0x00) & 0xFFU) << 16);
    id |= (((uint32_t)spi_flash_transfer(0x00) & 0xFFU) << 8);
    id |= ((uint32_t)spi_flash_transfer(0x00) & 0xFFU);

    *A_BSRR = (1u << SPI_CS_PIN);
    delay_ticks(200);
    return id;
}

void spi_flash_init(void) {
    volatile uint32_t *GPIOA_MODER  = (volatile uint32_t *)(GPIOA_BASE + GPIO_MODER);
    volatile uint32_t *GPIOA_OTYPER = (volatile uint32_t *)(GPIOA_BASE + GPIO_OTYPER);
    volatile uint32_t *GPIOA_PUPDR  = (volatile uint32_t *)(GPIOA_BASE + GPIO_PUPDR);
    volatile uint32_t *GPIOA_AFRL   = (volatile uint32_t *)(GPIOA_BASE + 0x20);
    volatile uint32_t *GPIOA_AFRH   = (volatile uint32_t *)(GPIOA_BASE + 0x24);
    volatile uint32_t *A_BSRR = (volatile uint32_t *)(GPIOA_BASE + GPIO_BSRR);
    volatile uint32_t *C_BSRR = (volatile uint32_t *)(GPIOC_BASE + GPIO_BSRR);
    volatile uint32_t *C_BRR  = (volatile uint32_t *)(GPIOC_BASE + GPIO_BRR);

    *(volatile uint32_t *)(RCC_BASE + 0x60) |= (1u << 12); delay_ticks(10);

    *GPIOA_AFRL &= ~((15u << (5 * 4)) | (15u << (6 * 4))); *GPIOA_AFRL |= ((5u << (5 * 4)) | (5u << (6 * 4)));
    *GPIOA_AFRH &= ~(15u << ((12 - 8) * 4)); *GPIOA_AFRH |= (5u << ((12 - 8) * 4));

    *GPIOA_MODER &= ~((3u << (SPI_CLK_PIN * 2)) | (3u << (SPI_MISO_PIN * 2)) | (3u << (SPI_MOSI_PIN * 2)));
    *GPIOA_MODER |=  ((2u << (SPI_CLK_PIN * 2)) | (2u << (SPI_MISO_PIN * 2)) | (2u << (SPI_MOSI_PIN * 2)));

    *GPIOA_OTYPER &= ~((1u << SPI_CLK_PIN) | (1u << SPI_MOSI_PIN));

    *GPIOA_MODER  &= ~(3u << (SPI_CS_PIN * 2)); *GPIOA_MODER |= (1u << (SPI_CS_PIN * 2));
    *GPIOA_OTYPER &= ~(1u << SPI_CS_PIN);

    *GPIOA_MODER  &= ~(3u << (I2C_EN_PIN * 2)); *GPIOA_MODER |= (1u << (I2C_EN_PIN * 2));
    *GPIOA_OTYPER &= ~(1u << I2C_EN_PIN);

    *(volatile uint32_t *)(GPIOC_BASE + GPIO_MODER) &= ~(3u<<(SPI_RST_PIN*2)); *(volatile uint32_t *)(GPIOC_BASE + GPIO_MODER) |= (1u<<(SPI_RST_PIN*2));
    *(volatile uint32_t *)(GPIOC_BASE + GPIO_OTYPER) &= ~(1u << SPI_RST_PIN);

    *SPI1_CR1 = 0; *SPI1_CR2 = 0;
    *SPI1_CR1 |= (1u << 9) | (1u << 8);
    *SPI1_CR1 |= (3u << 3);              /* Делитель /16 -> Частота SPI1 = 5 МГц */
    *SPI1_CR1 |= (1u << 2);
    *SPI1_CR1 |= (1u << 1) | (1u << 0);
    *SPI1_CR2 |= (7u << 8); *SPI1_CR2 |= (1u << 12);
    *SPI1_CR1 |= (1u << 6);

    *A_BSRR = (1u << SPI_CS_PIN); *A_BSRR = (1u << I2C_EN_PIN);
    *C_BRR = (1u << SPI_RST_PIN); delay_ms(10); *C_BSRR = (1u << SPI_RST_PIN); delay_ms(50);

    *(volatile uint32_t *)(GPIOA_BASE + GPIO_BRR) = (1u << SPI_CS_PIN); delay_ms(5);
    spi_flash_transfer(0xFF);
    *(volatile uint32_t *)(GPIOA_BASE + GPIO_BSRR) = (1u << SPI_CS_PIN); delay_ms(10);
}

void Reset_Handler(void) {
    *(volatile uint32_t *)(RCC_BASE + 0x58) |= (1u << 28);
    delay_ticks(10);
    *PWR_CR1 &= ~(3u << 9); *PWR_CR1 |= (1u << 9);
    while (*PWR_SR2 & (1u << 10));

    *FLASH_ACR &= ~7u; *FLASH_ACR |= 4u;
    while ((*FLASH_ACR & 7u) != 4u);

    *RCC_CR &= ~(15u << 4); *RCC_CR |= (6u << 4);
    *RCC_CR |= (1u << 3);
    while (!(*RCC_CR & (1 << 1)));

    *RCC_PLLCFGR = 0;
    *RCC_PLLCFGR |= (1u << 0) | (0u << 4) | (0x28 << 8) | (1u << 25) | (1u << 24);

    *RCC_CR |= (1u << 24);
    while (!(*RCC_CR & (1u << 25)));

    *RCC_CFGR &= ~3u; *RCC_CFGR |= 3u;
    while ((*RCC_CFGR & (3u << 2)) != (3u << 2));

    *(volatile uint32_t *)(GPIOB_BASE + GPIO_MODER) &= ~15;
    *(volatile uint32_t *)(GPIOB_BASE + GPIO_PUPDR) &= ~3; *(volatile uint32_t *)(GPIOB_BASE + GPIO_PUPDR) |= 1;
    *(volatile uint32_t *)(GPIOB_BASE + GPIO_MODER) &= ~(3 << 10);

    /* ИСПРАВЛЕНО: убрано паразитное слово Ext */
    *(volatile uint32_t *)(GPIOB_BASE + GPIO_MODER) &= ~((3 << 14) | (3 << 12));
    *(volatile uint32_t *)(GPIOB_BASE + GPIO_MODER) |= (1 << 12);
    *(volatile uint32_t *)(GPIOB_BASE + GPIO_ODR) &= ~(1 << 6);

    *(volatile uint32_t *)(GPIOA_BASE + GPIO_MODER) &= ~(3 << 20); *(volatile uint32_t *)(GPIOB_BASE + GPIO_MODER) &= ~(3 << 14);
    *(volatile uint32_t *)(GPIOA_BASE + GPIO_PUPDR) &= ~(3 << 20); *(volatile uint32_t *)(GPIOB_BASE + GPIO_PUPDR) &= ~(3 << 14);

    *(volatile uint32_t *)(GPIOA_BASE + GPIO_MODER) &= ~((3 << 14) | (3 << 4)); *(volatile uint32_t *)(GPIOB_BASE + GPIO_MODER) &= ~(3 << 8);
    *(volatile uint32_t *)(GPIOA_BASE + GPIO_PUPDR) &= ~((3 << 14) | (3 << 4)); *(volatile uint32_t *)(GPIOA_BASE + GPIO_PUPDR) |= ((1 << 14) | (1 << 4));
    *(volatile uint32_t *)(GPIOB_BASE + GPIO_ODR) |= (1 << 7) | (1 << 2); *(volatile uint32_t *)(GPIOB_BASE + GPIO_ODR) |= (1 << 4);

    *(volatile uint32_t *)(GPIOC_BASE + GPIO_MODER) &= ~(3 << 26); *(volatile uint32_t *)(GPIOC_BASE + GPIO_MODER) |= (1 << 26);
    *(volatile uint32_t *)(GPIOC_BASE + GPIO_ODR) |= (1 << 13); delay_ms(10);

    i2c3_init(); spi_flash_init();

    volatile uint32_t *GPIOA_IDR = (volatile uint32_t *)(GPIOA_BASE + GPIO_IDR);
    volatile uint32_t *GPIOB_IDR = (volatile uint32_t *)(GPIOB_BASE + GPIO_IDR);
    volatile uint32_t *A_BSRR = (volatile uint32_t *)(GPIOA_BASE + GPIO_BSRR);
    volatile uint32_t *A_BRR  = (volatile uint32_t *)(GPIOA_BASE + GPIO_BRR);

    uint32_t loop_counter = 1; uint8_t execution_phase_done = 0;

    while(1) {
        status_ALARM_IPM = (*GPIOB_IDR & (1 << 0)) ? 1 : 0; status_THERM = (*GPIOB_IDR & (1 << 1)) ? 1 : 0;
        status_EN_A_ACB = (*GPIOA_IDR & (1 << 8)) ? 1 : 0; status_EN_B_ACB = (*GPIOA_IDR & (1 << 9)) ? 1 : 0;
        status_PG_78_P1V0_PCIE = (*GPIOA_IDR & (1 << 10)) ? 1 : 0; status_ALL_PLL_LOCKED = (*GPIOB_IDR & (1 << 5)) ? 1 : 0;

        pin_PA8 = (*GPIOA_IDR & (1 << 8)) ? "HIGH" : "LOW"; pin_PA9 = (*GPIOA_IDR & (1 << 9)) ? "HIGH" : "LOW"; pin_PA10 = (*GPIOA_IDR & (1 << 10)) ? "HIGH" : "LOW";
        pin_PB0 = (*GPIOB_IDR & (1 << 0)) ? "HIGH" : "LOW"; pin_PB1 = (*GPIOB_IDR & (1 << 1)) ? "HIGH" : "LOW";
        pin_PB6 = (*(volatile uint32_t *)(GPIOB_BASE + GPIO_ODR) & (1 << 6)) ? "HIGH" : "LOW"; pin_PB7 = (*GPIOB_IDR & (1 << 7)) ? "HIGH" : "LOW";

        if ((*GPIOA_IDR & (1 << 10)) && (*GPIOB_IDR & (1 << 7))) {
            if (!execution_phase_done) {
                delay_ms(100);
                *A_BRR = (1u << I2C_EN_PIN); delay_ms(10); scan_i2c_bus(); delay_ms(10); *A_BSRR = (1u << I2C_EN_PIN);
                delay_ms(50);

                *(volatile uint32_t *)(GPIOA_BASE + GPIO_BRR) = (1u << SPI_CS_PIN); delay_ms(5); spi_flash_transfer(0xFF);
                *(volatile uint32_t *)(GPIOA_BASE + GPIO_BSRR) = (1u << SPI_CS_PIN); delay_ms(10);
                *(volatile uint32_t *)(GPIOA_BASE + GPIO_BRR) = (1u << SPI_CS_PIN); delay_ms(20);
                execution_phase_done = 1;
            }
            if (loop_counter % 50 == 0) { flash_jedec_id = spi_flash_read_jedec_id_continuous(); }
        } else {
            if (execution_phase_done) { *A_BSRR = (1u << I2C_EN_PIN); execution_phase_done = 0; }
            flash_jedec_id = 0x00000000;
        }
        loop_counter++; delay_ms(10);
    }
}

void Dummy_Handler(void) { while(1); }
extern void _estack(void);
__attribute__((section(".vector_table")))
void (* const vector_table[])(void) = {
    &_estack, Reset_Handler, Dummy_Handler, Dummy_Handler,
    Dummy_Handler, Dummy_Handler, Dummy_Handler, 0, 0, 0, 0,
    Dummy_Handler, Dummy_Handler, 0, Dummy_Handler, Dummy_Handler
};
