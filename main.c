#include <stdint.h>

typedef struct {
    uint16_t Reg_Addr;
    uint8_t  Reg_Mask;
    uint8_t  Reg_Val;
} Reg_Data;

/* Чип 0x70 (FPGA): CLK0=100МГц, CLK1/CLK2=125/100МГц, CLK3 не используется.
   Источник: Si5338-RevB-Registers_03092025_1452.txt */
static const Reg_Data Si5338_0x70_Regs[] = {
    {6,0xFF,0x08}, {27,0x80,0x00}, {28,0xFF,0x16}, {29,0xFF,0x90}, {30,0xFF,0xB0}, {31,0xFF,0xC0}, {32,0xFF,0xC0}, {33,0xFF,0xC0}, {34,0xFF,0xE3},
    {35,0xFF,0x00}, {36,0xFF,0x01}, {37,0xFF,0x07}, {38,0xFF,0x07}, {39,0xFF,0x00}, {40,0xFF,0xF7}, {41,0xFF,0x1C}, {42,0xFF,0x23},
    {45,0xFF,0x00}, {46,0xFF,0x00}, {47,0xFF,0x14}, {48,0xFF,0x3A}, {49,0xFF,0x00}, {50,0xFF,0xC4}, {51,0xFF,0x07}, {52,0xFF,0x10},
    {53,0xFF,0x80}, {54,0xFF,0x0A}, {55,0xFF,0x00}, {56,0xFF,0x00}, {57,0xFF,0x00}, {58,0xFF,0x00}, {59,0xFF,0x01}, {60,0xFF,0x00},
    {61,0xFF,0x00}, {62,0xFF,0x00}, {63,0xFF,0x10}, {64,0xFF,0x00}, {65,0xFF,0x08}, {66,0xFF,0x00}, {67,0xFF,0x00}, {68,0xFF,0x00},
    {69,0xFF,0x00}, {70,0xFF,0x01}, {71,0xFF,0x00}, {72,0xFF,0x00}, {73,0xFF,0x00}, {74,0xFF,0x10}, {75,0xFF,0x80}, {76,0xFF,0x0A},
    {77,0xFF,0x00}, {78,0xFF,0x00}, {79,0xFF,0x00}, {80,0xFF,0x00}, {81,0xFF,0x01}, {82,0xFF,0x00}, {83,0xFF,0x00}, {84,0xFF,0x00},
    {85,0xFF,0x10}, {86,0xFF,0x00}, {87,0xFF,0x00}, {88,0xFF,0x00}, {89,0xFF,0x00}, {90,0xFF,0x00}, {91,0xFF,0x00}, {92,0xFF,0x00},
    {93,0xFF,0x00}, {94,0xFF,0x00}, {95,0xFF,0x00}, {97,0xFF,0x00}, {98,0xFF,0x30}, {99,0xFF,0x00}, {100,0xFF,0x00}, {101,0xFF,0x00},
    {102,0xFF,0x00}, {103,0xFF,0x01}, {104,0xFF,0x00}, {105,0xFF,0x00}, {106,0xFF,0x80}, {107,0xFF,0x00}, {108,0xFF,0x00}, {109,0xFF,0x00},
    {110,0xFF,0xC0}, {111,0xFF,0x00}, {112,0xFF,0x00}, {113,0xFF,0x00}, {114,0xFF,0xC0}, {115,0xFF,0x00}, {116,0xFF,0x80}, {117,0xFF,0x00},
    {118,0xFF,0xC0}, {119,0xFF,0x00}, {120,0xFF,0x00}, {121,0xFF,0x00}, {122,0xFF,0x40}, {123,0xFF,0x00}, {124,0xFF,0x00}, {125,0xFF,0x00},
    {126,0xFF,0x00}, {127,0xFF,0x00}, {128,0xFF,0x00}, {129,0xFF,0x00}, {130,0xFF,0x00}, {131,0xFF,0x00}, {132,0xFF,0x00}, {133,0xFF,0x00},
    {134,0xFF,0x00}, {135,0xFF,0x00}, {136,0xFF,0x00}, {137,0xFF,0x00}, {138,0xFF,0x00}, {139,0xFF,0x00}, {140,0xFF,0x00}, {141,0xFF,0x00},
    {142,0xFF,0x00}, {143,0xFF,0x00}, {144,0xFF,0x00}, {152,0xFF,0x00}, {153,0xFF,0x00}, {154,0xFF,0x00}, {155,0xFF,0x00}, {156,0xFF,0x00},
    {157,0xFF,0x00}, {158,0xFF,0x00}, {159,0xFF,0x00}, {160,0xFF,0x00}, {161,0xFF,0x00}, {162,0xFF,0x00}, {163,0xFF,0x00}, {164,0xFF,0x00},
    {165,0xFF,0x00}, {166,0xFF,0x00}, {167,0xFF,0x00}, {168,0xFF,0x00}, {169,0xFF,0x00}, {170,0xFF,0x00}, {171,0xFF,0x00}, {172,0xFF,0x00},
    {173,0xFF,0x00}, {174,0xFF,0x00}, {175,0xFF,0x00}, {176,0xFF,0x00}, {177,0xFF,0x00}, {178,0xFF,0x00}, {179,0xFF,0x00}, {180,0xFF,0x00},
    {181,0xFF,0x00}, {182,0xFF,0x00}, {183,0xFF,0x00}, {184,0xFF,0x00}, {185,0xFF,0x00}, {186,0xFF,0x00}, {187,0xFF,0x00}, {188,0xFF,0x00},
    {189,0xFF,0x00}, {190,0xFF,0x00}, {191,0xFF,0x00}, {192,0xFF,0x00}, {193,0xFF,0x00}, {194,0xFF,0x00}, {195,0xFF,0x00}, {196,0xFF,0x00},
    {197,0xFF,0x00}, {198,0xFF,0x00}, {199,0xFF,0x00}, {200,0xFF,0x00}, {201,0xFF,0x00}, {202,0xFF,0x00}, {203,0xFF,0x00}, {204,0xFF,0x00},
    {205,0xFF,0x00}, {206,0xFF,0x00}, {207,0xFF,0x00}, {208,0xFF,0x00}, {209,0xFF,0x00}, {210,0xFF,0x00}, {211,0xFF,0x00}, {212,0xFF,0x00},
    {213,0xFF,0x00}, {214,0xFF,0x00}, {215,0xFF,0x00}, {216,0xFF,0x00}, {217,0xFF,0x00},
    {287,0xFF,0x00}, {288,0xFF,0x00}, {289,0xFF,0x01}, {290,0xFF,0x00}, {291,0xFF,0x00}, {292,0xFF,0x90}, {293,0xFF,0x31}, {294,0xFF,0x00},
    {295,0xFF,0x00}, {296,0xFF,0x01}, {297,0xFF,0x00}, {298,0xFF,0x00}, {299,0xFF,0x00}, {303,0xFF,0x00}, {304,0xFF,0x00}, {305,0xFF,0x01},
    {306,0xFF,0x00}, {307,0xFF,0x00}, {308,0xFF,0x90}, {309,0xFF,0x31}, {310,0xFF,0x00}, {311,0xFF,0x00}, {312,0xFF,0x01}, {313,0xFF,0x00},
    {314,0xFF,0x00}, {315,0xFF,0x00}, {319,0xFF,0x00}, {320,0xFF,0x00}, {321,0xFF,0x01}, {322,0xFF,0x00}, {323,0xFF,0x00}, {324,0xFF,0x90},
    {325,0xFF,0x31}, {326,0xFF,0x00}, {327,0xFF,0x00}, {328,0xFF,0x01}, {329,0xFF,0x00}, {330,0xFF,0x00}, {331,0xFF,0x00}, {335,0xFF,0x00},
    {336,0xFF,0x00}, {337,0xFF,0x00}, {338,0xFF,0x00}, {339,0xFF,0x00}, {340,0xFF,0x90}, {341,0xFF,0x31}, {342,0xFF,0x00}, {343,0xFF,0x00},
    {344,0xFF,0x01}, {345,0xFF,0x00}, {346,0xFF,0x00}, {347,0xFF,0x00}
};

/* Чип 0x71 (SYS/DDR/LAN): CLK0=66.66МГц, CLK1=133.33МГц, CLK2/CLK3=125МГц.
   Источник: Si5338-RevB_sys-ddr-lan-Registers.txt */
static const Reg_Data Si5338_0x71_Regs[] = {
    {6,0xFF,0x08}, {27,0x80,0x00}, {28,0xFF,0x16}, {29,0xFF,0x90}, {30,0xFF,0xB0}, {31,0xFF,0xC0}, {32,0xFF,0xC0}, {33,0xFF,0xC0}, {34,0xFF,0xC0},
    {35,0xFF,0xAA}, {36,0xFF,0x01}, {37,0xFF,0x01}, {38,0xFF,0x06}, {39,0xFF,0x06}, {40,0xFF,0xB5}, {41,0xFF,0x12}, {42,0xFF,0x24},
    {45,0xFF,0x00}, {46,0xFF,0x00}, {47,0xFF,0x14}, {48,0xFF,0x38}, {49,0xFF,0x00}, {50,0xFF,0xC4}, {51,0xFF,0x07}, {52,0xFF,0x10},
    {53,0xFF,0x00}, {54,0xFF,0x11}, {55,0xFF,0x00}, {56,0xFF,0x00}, {57,0xFF,0x00}, {58,0xFF,0x00}, {59,0xFF,0x01}, {60,0xFF,0x00},
    {61,0xFF,0x00}, {62,0xFF,0x00}, {63,0xFF,0x10}, {64,0xFF,0x7F}, {65,0xFF,0x07}, {66,0xFF,0x54}, {67,0xFF,0xAA}, {68,0xFF,0x00},
    {69,0xFF,0x00}, {70,0xFF,0x15}, {71,0xFF,0x34}, {72,0xFF,0x00}, {73,0xFF,0x00}, {74,0xFF,0x10}, {75,0xFF,0x21}, {76,0xFF,0x08},
    {77,0xFF,0xAC}, {78,0xFF,0x2A}, {79,0xFF,0x00}, {80,0xFF,0x00}, {81,0xFF,0x35}, {82,0xFF,0x0C}, {83,0xFF,0x00}, {84,0xFF,0x00},
    {85,0xFF,0x10}, {86,0xFF,0x21}, {87,0xFF,0x08}, {88,0xFF,0xAC}, {89,0xFF,0x2A}, {90,0xFF,0x00}, {91,0xFF,0x00}, {92,0xFF,0x35},
    {93,0xFF,0x0C}, {94,0xFF,0x00}, {95,0xFF,0x00}, {97,0xFF,0xA9}, {98,0xFF,0x30}, {99,0xFF,0x9C}, {100,0xFF,0x03}, {101,0xFF,0x00},
    {102,0xFF,0x00}, {103,0xFF,0x71}, {104,0xFF,0x02}, {105,0xFF,0x00}, {106,0xFF,0x80}, {107,0xFF,0x00}, {108,0xFF,0x00}, {109,0xFF,0x00},
    {110,0xFF,0x40}, {111,0xFF,0x00}, {112,0xFF,0x00}, {113,0xFF,0x00}, {114,0xFF,0x40}, {115,0xFF,0x00}, {116,0xFF,0x80}, {117,0xFF,0x00},
    {118,0xFF,0x40}, {119,0xFF,0x00}, {120,0xFF,0x00}, {121,0xFF,0x00}, {122,0xFF,0x40}, {123,0xFF,0x00}, {124,0xFF,0x00}, {125,0xFF,0x00},
    {126,0xFF,0x00}, {127,0xFF,0x00}, {128,0xFF,0x00}, {129,0xFF,0x00}, {130,0xFF,0x00}, {131,0xFF,0x00}, {132,0xFF,0x00}, {133,0xFF,0x00},
    {134,0xFF,0x00}, {135,0xFF,0x00}, {136,0xFF,0x00}, {137,0xFF,0x00}, {138,0xFF,0x00}, {139,0xFF,0x00}, {140,0xFF,0x00}, {141,0xFF,0x00},
    {142,0xFF,0x00}, {143,0xFF,0x00}, {144,0xFF,0x00}, {152,0xFF,0x00}, {153,0xFF,0x00}, {154,0xFF,0x00}, {155,0xFF,0x00}, {156,0xFF,0x00},
    {157,0xFF,0x00}, {158,0xFF,0x00}, {159,0xFF,0x00}, {160,0xFF,0x00}, {161,0xFF,0x00}, {162,0xFF,0x00}, {163,0xFF,0x00}, {164,0xFF,0x00},
    {165,0xFF,0x00}, {166,0xFF,0x00}, {167,0xFF,0x00}, {168,0xFF,0x00}, {169,0xFF,0x00}, {170,0xFF,0x00}, {171,0xFF,0x00}, {172,0xFF,0x00},
    {173,0xFF,0x00}, {174,0xFF,0x00}, {175,0xFF,0x00}, {176,0xFF,0x00}, {177,0xFF,0x00}, {178,0xFF,0x00}, {179,0xFF,0x00}, {180,0xFF,0x00},
    {181,0xFF,0x00}, {182,0xFF,0x00}, {183,0xFF,0x00}, {184,0xFF,0x00}, {185,0xFF,0x00}, {186,0xFF,0x00}, {187,0xFF,0x00}, {188,0xFF,0x00},
    {189,0xFF,0x00}, {190,0xFF,0x00}, {191,0xFF,0x00}, {192,0xFF,0x00}, {193,0xFF,0x00}, {194,0xFF,0x00}, {195,0xFF,0x00}, {196,0xFF,0x00},
    {197,0xFF,0x00}, {198,0xFF,0x00}, {199,0xFF,0x00}, {200,0xFF,0x00}, {201,0xFF,0x00}, {202,0xFF,0x00}, {203,0xFF,0x00}, {204,0xFF,0x00},
    {205,0xFF,0x00}, {206,0xFF,0x00}, {207,0xFF,0x00}, {208,0xFF,0x00}, {209,0xFF,0x00}, {210,0xFF,0x00}, {211,0xFF,0x00}, {212,0xFF,0x00},
    {213,0xFF,0x00}, {214,0xFF,0x00}, {215,0xFF,0x00}, {216,0xFF,0x00}, {217,0xFF,0x00},
    {287,0xFF,0x00}, {288,0xFF,0x00}, {289,0xFF,0x01}, {290,0xFF,0x00}, {291,0xFF,0x00}, {292,0xFF,0x90}, {293,0xFF,0x31}, {294,0xFF,0x00},
    {295,0xFF,0x00}, {296,0xFF,0x01}, {297,0xFF,0x00}, {298,0xFF,0x00}, {299,0xFF,0x00}, {303,0xFF,0x00}, {304,0xFF,0x00}, {305,0xFF,0x01},
    {306,0xFF,0x00}, {307,0xFF,0x00}, {308,0xFF,0x90}, {309,0xFF,0x31}, {310,0xFF,0x00}, {311,0xFF,0x00}, {312,0xFF,0x01}, {313,0xFF,0x00},
    {314,0xFF,0x00}, {315,0xFF,0x00}, {319,0xFF,0x00}, {320,0xFF,0x00}, {321,0xFF,0x01}, {322,0xFF,0x00}, {323,0xFF,0x00}, {324,0xFF,0x90},
    {325,0xFF,0x31}, {326,0xFF,0x00}, {327,0xFF,0x00}, {328,0xFF,0x01}, {329,0xFF,0x00}, {330,0xFF,0x00}, {331,0xFF,0x00}, {335,0xFF,0x00},
    {336,0xFF,0x00}, {337,0xFF,0x00}, {338,0xFF,0x00}, {339,0xFF,0x00}, {340,0xFF,0x90}, {341,0xFF,0x31}, {342,0xFF,0x00}, {343,0xFF,0x00},
    {344,0xFF,0x01}, {345,0xFF,0x00}, {346,0xFF,0x00}, {347,0xFF,0x00}
};

#define SI5338_0x70_REG_COUNT (sizeof(Si5338_0x70_Regs) / sizeof(Si5338_0x70_Regs[0]))
#define SI5338_0x71_REG_COUNT (sizeof(Si5338_0x71_Regs) / sizeof(Si5338_0x71_Regs[0]))

volatile uint32_t si5338_0x70_fail_count = 0;
volatile uint32_t si5338_0x71_fail_count = 0;
volatile uint32_t status_pb6_alarm_during_si5338 = 0;
volatile uint32_t si5338_0x70_locked = 0;
volatile uint32_t si5338_0x71_locked = 0;
volatile uint32_t status_si5338_lock_timeout = 0;

volatile uint32_t si5338_0x70_first_fail_index = 0xFFFFFFFF;
volatile uint8_t  si5338_0x70_first_fail_addr = 0xFF;
volatile uint8_t  si5338_0x70_first_fail_expected = 0xFF;
volatile uint8_t  si5338_0x70_first_fail_actual = 0xFF;

volatile uint32_t si5338_0x71_first_fail_index = 0xFFFFFFFF;
volatile uint8_t  si5338_0x71_first_fail_addr = 0xFF;
volatile uint8_t  si5338_0x71_first_fail_expected = 0xFF;
volatile uint8_t  si5338_0x71_first_fail_actual = 0xFF;

#define RCC_BASE      0x40021000
#define PWR_BASE      0x40007400
#define GPIOA_BASE    0x48000000
#define GPIOB_BASE    0x48000400
#define GPIOC_BASE    0x48000800
#define GPIOH_BASE    0x48001C00
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

#define RCC_AHB2ENR   ((volatile uint32_t *)(RCC_BASE + 0x4C))
#define RCC_APB1ENR1  ((volatile uint32_t *)(RCC_BASE + 0x58))
#define RCC_BDCR      ((volatile uint32_t *)(RCC_BASE + 0x70))

#define SPI1_CR1      ((volatile uint32_t *)(SPI1_BASE + 0x00))
#define SPI1_CR2      ((volatile uint32_t *)(SPI1_BASE + 0x04))
#define SPI1_SR       ((volatile uint32_t *)(SPI1_BASE + 0x08))
#define SPI1_DR       ((volatile uint32_t *)(SPI1_BASE + 0x0C))

#define SPI_CS_PIN    15
#define SPI_CLK_PIN   5
#define SPI_MOSI_PIN  12
#define SPI_MISO_PIN  6
#define SPI_RST_PIN   15

#define I2C_EN_PIN      4
#define HRESET_PIN      4
#define PORESET_PIN     0
#define RCW_JTAG_PIN    3
#define RESET_REQ_PIN   3
#define CKSTP_PIN       5
#define PCI_PERSTN_PIN  14

#define T_POWER_STABILIZE_MS       1500
#define T_ASSERT_PAD_MS             235
#define T_PLL_LOCK_TIMEOUT_MS      2000
#define SI5338_CAL_POLL_TIMEOUT_MS  150

volatile uint32_t status_ALARM_IPM=0, status_THERM=0, status_EN_A_ACB=0, status_EN_B_ACB=0, status_PG_78_P1V0_PCIE=0, status_ALL_PLL_LOCKED=0;
volatile uint32_t status_RESET_REQ = 0;
volatile uint32_t status_CKSTP = 0;
volatile uint32_t status_PLL_LOCK_TIMEOUT = 0;
volatile uint32_t cpu_boot_stage = 0;

volatile uint8_t i2c_map[128];
volatile uint32_t discovered_devices_count;
volatile char i2c_devices_list[64] = "Not Scanned (No Power)";
volatile uint32_t flash_jedec_id = 0;

volatile uint8_t si5338_0x70_status0 = 0xFF;
volatile uint8_t si5338_0x71_status0 = 0xFF;
volatile uint8_t si5338_0x70_reg218 = 0xFF;
volatile uint8_t si5338_0x71_reg218 = 0xFF;

void delay(volatile uint32_t count) { while(count--); }

const char* pin_PA8="L", *pin_PA9="L", *pin_PA10="L", *pin_PB0="L", *pin_PB1="L", *pin_PB6="L", *pin_PB7="L";

static inline void delay_ticks(volatile uint32_t ticks) {
    while(ticks--) { __asm__ volatile("nop"); }
}

void delay_ms(volatile uint32_t ms) {
    volatile uint32_t count = ms * 16000;
    while(count--) { __asm__ volatile("nop"); }
}

void i2c3_init(void) {
    volatile uint32_t dummy;
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

uint8_t i2c3_read_reg(uint8_t address, uint8_t reg) {
    volatile uint32_t *GPIOA_ODR = (volatile uint32_t *)(GPIOA_BASE + GPIO_ODR);
    volatile uint32_t *GPIOB_ODR = (volatile uint32_t *)(GPIOB_BASE + GPIO_ODR);
    volatile uint32_t *GPIOB_IDR = (volatile uint32_t *)(GPIOB_BASE + GPIO_IDR);
    uint8_t data = 0; uint8_t addr_w = (address << 1);
    *GPIOB_ODR |= (1 << 4); delay(10); *GPIOA_ODR |= (1 << 7); delay(10);
    *GPIOB_ODR &= ~(1 << 4); delay(10); *GPIOA_ODR &= ~(1 << 7); delay(10);
    for (int bit = 0; bit < 8; bit++) {
        if (addr_w & (1 << (7 - bit))) *GPIOB_ODR |= (1 << 4);
        else                           *GPIOB_ODR &= ~(1 << 4);
        delay(5); *GPIOA_ODR |= (1 << 7); delay(10); *GPIOA_ODR &= ~(1 << 7); delay(5);
    }
    *GPIOB_ODR |= (1 << 4); delay(5); *GPIOA_ODR |= (1 << 7); delay(10); *GPIOA_ODR &= ~(1 << 7); delay(5);
    for (int bit = 0; bit < 8; bit++) {
        if (reg & (1 << (7 - bit))) *GPIOB_ODR |= (1 << 4);
        else                        *GPIOB_ODR &= ~(1 << 4);
        delay(5); *GPIOA_ODR |= (1 << 7); delay(10); *GPIOA_ODR &= ~(1 << 7); delay(5);
    }
    *GPIOB_ODR |= (1 << 4); delay(5); *GPIOA_ODR |= (1 << 7); delay(10); *GPIOA_ODR &= ~(1 << 7); delay(5);
    *GPIOB_ODR |= (1 << 4); delay(10); *GPIOA_ODR |= (1 << 7); delay(10);
    *GPIOB_ODR &= ~(1 << 4); delay(10); *GPIOA_ODR &= ~(1 << 7); delay(10);
    uint8_t addr_r = (address << 1) | 1;
    for (int bit = 0; bit < 8; bit++) {
        if (addr_r & (1 << (7 - bit))) *GPIOB_ODR |= (1 << 4);
        else                           *GPIOB_ODR &= ~(1 << 4);
        delay(5); *GPIOA_ODR |= (1 << 7); delay(10); *GPIOA_ODR &= ~(1 << 7); delay(5);
    }
    *GPIOB_ODR |= (1 << 4); delay(5); *GPIOA_ODR |= (1 << 7); delay(10); *GPIOA_ODR &= ~(1 << 7); delay(5);
    *GPIOB_ODR |= (1 << 4);
    for (int bit = 0; bit < 8; bit++) {
        delay(5); *GPIOA_ODR |= (1 << 7); delay(5);
        if (*GPIOB_IDR & (1 << 4)) data |= (1 << (7 - bit));
        delay(5); *GPIOA_ODR &= ~(1 << 7);
    }
    *GPIOB_ODR |= (1 << 4); delay(5); *GPIOA_ODR |= (1 << 7); delay(10); *GPIOA_ODR &= ~(1 << 7); delay(5);
    *GPIOB_ODR &= ~(1 << 4); delay(10); *GPIOA_ODR |= (1 << 7); delay(10);
    *GPIOB_ODR |= (1 << 4); delay(10);
    return data;
}

void i2c3_write_reg(uint8_t address, uint8_t reg, uint8_t value) {
    volatile uint32_t *GPIOA_ODR = (volatile uint32_t *)(GPIOA_BASE + GPIO_ODR);
    volatile uint32_t *GPIOB_ODR = (volatile uint32_t *)(GPIOB_BASE + GPIO_ODR);
    *GPIOB_ODR |= (1 << 4);  delay(10); *GPIOA_ODR |= (1 << 7);  delay(10);
    *GPIOB_ODR &= ~(1 << 4); delay(10); *GPIOA_ODR &= ~(1 << 7); delay(10);
    uint8_t addr_w = (address << 1);
    for (int bit = 0; bit < 8; bit++) {
        if (addr_w & (1 << (7 - bit))) *GPIOB_ODR |= (1 << 4);
        else                           *GPIOB_ODR &= ~(1 << 4);
        delay(5); *GPIOA_ODR |= (1 << 7); delay(10); *GPIOA_ODR &= ~(1 << 7); delay(5);
    }
    *GPIOB_ODR |= (1 << 4); delay(5); *GPIOA_ODR |= (1 << 7); delay(10); *GPIOA_ODR &= ~(1 << 7); delay(5);
    for (int bit = 0; bit < 8; bit++) {
        if (reg & (1 << (7 - bit))) *GPIOB_ODR |= (1 << 4);
        else                        *GPIOB_ODR &= ~(1 << 4);
        delay(5); *GPIOA_ODR |= (1 << 7); delay(10); *GPIOA_ODR &= ~(1 << 7); delay(5);
    }
    *GPIOB_ODR |= (1 << 4); delay(5); *GPIOA_ODR |= (1 << 7); delay(10); *GPIOA_ODR &= ~(1 << 7); delay(5);
    for (int bit = 0; bit < 8; bit++) {
        if (value & (1 << (7 - bit))) *GPIOB_ODR |= (1 << 4);
        else                          *GPIOB_ODR &= ~(1 << 4);
        delay(5); *GPIOA_ODR |= (1 << 7); delay(10); *GPIOA_ODR &= ~(1 << 7); delay(5);
    }
    *GPIOB_ODR |= (1 << 4); delay(5); *GPIOA_ODR |= (1 << 7); delay(10); *GPIOA_ODR &= ~(1 << 7); delay(5);
    *GPIOB_ODR &= ~(1 << 4); delay(10); *GPIOA_ODR |= (1 << 7); delay(10); *GPIOB_ODR |= (1 << 4); delay(10);
}

uint32_t si5338_load_table(uint8_t address, const Reg_Data *table, uint32_t count,
                            volatile uint32_t *pb6_alarm_flag,
                            volatile uint32_t *first_fail_index,
                            volatile uint8_t  *first_fail_addr,
                            volatile uint8_t  *first_fail_expected,
                            volatile uint8_t  *first_fail_actual) {
    volatile uint32_t *B_IDR = (volatile uint32_t *)(GPIOB_BASE + GPIO_IDR);
    uint32_t fails = 0;
    /* Инициализируем как 0x00: чип стартует на странице 0 по умолчанию.
       Прежнее значение 0xFF вызывало запись PAGE_SELECT=0 перед первым
       регистром, что нарушало работу шины и давало 233/234 ошибок. */
    uint8_t current_page = 0x00;

    for (uint32_t i = 0; i < count; i++) {
        uint8_t mask = table[i].Reg_Mask;
        if (mask == 0) continue;

        uint8_t page      = (uint8_t)(table[i].Reg_Addr >> 8);
        uint8_t phys_addr = (uint8_t)(table[i].Reg_Addr & 0xFF);

        if (page != current_page) {
            i2c3_write_reg(address, 255, page);
            current_page = page;
            delay_ticks(50);
        }

        uint8_t old = i2c3_read_reg(address, phys_addr);
        uint8_t new_val = (uint8_t)((old & (uint8_t)~mask) | (table[i].Reg_Val & mask));
        i2c3_write_reg(address, phys_addr, new_val);
        delay_ticks(50);

        uint8_t verify = i2c3_read_reg(address, phys_addr);
        if ((verify & mask) != (new_val & mask)) {
            fails++;
            if (*first_fail_index == 0xFFFFFFFF) {
                *first_fail_index = i;
                *first_fail_addr = phys_addr;
                *first_fail_expected = new_val;
                *first_fail_actual = verify;
            }
        }

        if (*B_IDR & (1u << 6)) *pb6_alarm_flag = 1;
        delay_ticks(50);
    }

    /* Вернуться на страницу 0 только если фактически переключались */
    if (current_page != 0) {
        i2c3_write_reg(address, 255, 0);
    }
    return fails;
}

uint32_t si5338_poll_lock(uint8_t address, uint32_t timeout_ms) {
    uint32_t waited = 0;
    while (waited < timeout_ms) {
        uint8_t status = i2c3_read_reg(address, 218);
        if ((status & 0x15) == 0) return 1;
        delay_ms(1);
        waited++;
    }
    return 0;
}

void si5338_finalize_calibration(uint8_t address) {
    uint8_t fcal_lsb      = i2c3_read_reg(address, 235);
    uint8_t fcal_mid      = i2c3_read_reg(address, 236);
    uint8_t fcal_msb_bits = i2c3_read_reg(address, 237) & 0x03;
    uint8_t reg49;

    i2c3_write_reg(address, 45, fcal_lsb);
    i2c3_write_reg(address, 46, fcal_mid);
    i2c3_write_reg(address, 47, (uint8_t)(0x14 | fcal_msb_bits));

    reg49 = i2c3_read_reg(address, 49);
    i2c3_write_reg(address, 49, (uint8_t)(reg49 | 0x80));
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
    *A_BRR = (1u << SPI_CS_PIN); delay_ticks(300);
    spi_flash_transfer(0x9F);
    id |= (((uint32_t)spi_flash_transfer(0x00) & 0xFFU) << 16);
    id |= (((uint32_t)spi_flash_transfer(0x00) & 0xFFU) << 8);
    id |= ((uint32_t)spi_flash_transfer(0x00) & 0xFFU);
    *A_BSRR = (1u << SPI_CS_PIN); delay_ticks(200);
    return id;
}

void spi_flash_init(void) {
    volatile uint32_t *GPIOA_MODER  = (volatile uint32_t *)(GPIOA_BASE + GPIO_MODER);
    volatile uint32_t *GPIOA_OTYPER = (volatile uint32_t *)(GPIOA_BASE + GPIO_OTYPER);
    volatile uint32_t *GPIOA_AFRL   = (volatile uint32_t *)(GPIOA_BASE + 0x20);
    volatile uint32_t *GPIOA_AFRH   = (volatile uint32_t *)(GPIOA_BASE + 0x24);
    volatile uint32_t *A_BSRR = (volatile uint32_t *)(GPIOA_BASE + GPIO_BSRR);
    volatile uint32_t *C_BSRR = (volatile uint32_t *)(GPIOC_BASE + GPIO_BSRR);
    volatile uint32_t *C_BRR  = (volatile uint32_t *)(GPIOC_BASE + GPIO_BRR);

    *(volatile uint32_t *)(RCC_BASE + 0x60) |= (1u << 12); delay_ticks(10);
    *GPIOA_AFRL &= ~((15u << (5*4)) | (15u << (6*4))); *GPIOA_AFRL |= ((5u << (5*4)) | (5u << (6*4)));
    *GPIOA_AFRH &= ~(15u << ((12-8)*4)); *GPIOA_AFRH |= (5u << ((12-8)*4));
    *GPIOA_MODER &= ~((3u<<(SPI_CLK_PIN*2))|(3u<<(SPI_MISO_PIN*2))|(3u<<(SPI_MOSI_PIN*2)));
    *GPIOA_MODER |=  ((2u<<(SPI_CLK_PIN*2))|(2u<<(SPI_MISO_PIN*2))|(2u<<(SPI_MOSI_PIN*2)));
    *GPIOA_OTYPER &= ~((1u<<SPI_CLK_PIN)|(1u<<SPI_MOSI_PIN));
    *GPIOA_MODER  &= ~(3u<<(SPI_CS_PIN*2)); *GPIOA_MODER |= (1u<<(SPI_CS_PIN*2));
    *GPIOA_OTYPER &= ~(1u<<SPI_CS_PIN);
    *(volatile uint32_t *)(GPIOC_BASE+GPIO_MODER) &= ~(3u<<(SPI_RST_PIN*2));
    *(volatile uint32_t *)(GPIOC_BASE+GPIO_MODER) |=  (1u<<(SPI_RST_PIN*2));
    *(volatile uint32_t *)(GPIOC_BASE+GPIO_OTYPER) &= ~(1u<<SPI_RST_PIN);
    *SPI1_CR1 = 0; *SPI1_CR2 = 0;
    *SPI1_CR1 |= (1u<<9)|(1u<<8)|(3u<<3)|(1u<<2)|(1u<<1)|(1u<<0);
    *SPI1_CR2 |= (7u<<8)|(1u<<12);
    *SPI1_CR1 |= (1u<<6);
    *A_BSRR = (1u<<SPI_CS_PIN);
    *C_BRR = (1u<<SPI_RST_PIN); delay_ms(10); *C_BSRR = (1u<<SPI_RST_PIN); delay_ms(50);
    *(volatile uint32_t *)(GPIOA_BASE+GPIO_BRR) = (1u<<SPI_CS_PIN); delay_ms(5);
    spi_flash_transfer(0xFF);
    *(volatile uint32_t *)(GPIOA_BASE+GPIO_BSRR) = (1u<<SPI_CS_PIN); delay_ms(10);
}

void spi_flash_release_bus(void) {
    volatile uint32_t *GPIOA_MODER = (volatile uint32_t *)(GPIOA_BASE + GPIO_MODER);
    *SPI1_CR1 &= ~(1u<<6);
    *GPIOA_MODER &= ~((3u<<(SPI_CLK_PIN*2))|(3u<<(SPI_MISO_PIN*2))|
                      (3u<<(SPI_MOSI_PIN*2))|(3u<<(SPI_CS_PIN*2)));
}

void cpu_reset_gpio_init(void) {
    volatile uint32_t *A_MODER  = (volatile uint32_t *)(GPIOA_BASE + GPIO_MODER);
    volatile uint32_t *A_OTYPER = (volatile uint32_t *)(GPIOA_BASE + GPIO_OTYPER);
    volatile uint32_t *B_MODER  = (volatile uint32_t *)(GPIOB_BASE + GPIO_MODER);
    volatile uint32_t *B_PUPDR  = (volatile uint32_t *)(GPIOB_BASE + GPIO_PUPDR);
    volatile uint32_t *C_MODER  = (volatile uint32_t *)(GPIOC_BASE + GPIO_MODER);
    volatile uint32_t *C_OTYPER = (volatile uint32_t *)(GPIOC_BASE + GPIO_OTYPER);
    volatile uint32_t *H_MODER  = (volatile uint32_t *)(GPIOH_BASE + GPIO_MODER);
    volatile uint32_t *H_OTYPER = (volatile uint32_t *)(GPIOH_BASE + GPIO_OTYPER);

    *RCC_AHB2ENR |= (1u<<7); delay_ticks(10);

    *A_MODER  &= ~(3u<<(PORESET_PIN*2)); *A_MODER  |= (1u<<(PORESET_PIN*2));
    *A_OTYPER &= ~(1u<<PORESET_PIN);

    *A_MODER  &= ~(3u<<(HRESET_PIN*2)); *A_MODER  |= (1u<<(HRESET_PIN*2));
    *A_OTYPER |=  (1u<<HRESET_PIN);

    *B_MODER &= ~(3u<<(RESET_REQ_PIN*2));
    *B_PUPDR &= ~(3u<<(RESET_REQ_PIN*2)); *B_PUPDR |= (1u<<(RESET_REQ_PIN*2));

    *B_MODER &= ~(3u<<(CKSTP_PIN*2));
    *B_PUPDR &= ~(3u<<(CKSTP_PIN*2)); *B_PUPDR |= (1u<<(CKSTP_PIN*2));

    *C_MODER  &= ~(3u<<(PCI_PERSTN_PIN*2)); *C_MODER  |= (1u<<(PCI_PERSTN_PIN*2));
    *C_OTYPER &= ~(1u<<PCI_PERSTN_PIN);

    *H_MODER  &= ~(3u<<(RCW_JTAG_PIN*2)); *H_MODER  |= (1u<<(RCW_JTAG_PIN*2));
    *H_OTYPER &= ~(1u<<RCW_JTAG_PIN);
}

uint32_t cpu_read_reset_req(void) {
    return (*(volatile uint32_t *)(GPIOB_BASE + GPIO_IDR) & (1u<<RESET_REQ_PIN)) ? 0 : 1;
}

uint32_t cpu_read_ckstp(void) {
    return (*(volatile uint32_t *)(GPIOB_BASE + GPIO_IDR) & (1u<<CKSTP_PIN)) ? 0 : 1;
}

uint32_t cpu_wait_pll_locked(uint32_t timeout_ms) {
    volatile uint32_t *B_IDR = (volatile uint32_t *)(GPIOB_BASE + GPIO_IDR);
    uint32_t waited = 0;
    while (waited < timeout_ms) {
        if (!(*B_IDR & (1u<<6))) return 1;
        delay_ms(1); waited++;
    }
    return 0;
}

void cpu_boot_sequence(void) {
    cpu_boot_stage = 1;
    *(volatile uint32_t *)(GPIOH_BASE + GPIO_BRR) = (1u<<RCW_JTAG_PIN);
    delay_ms(T_POWER_STABILIZE_MS);
    cpu_boot_stage = 2;

    *(volatile uint32_t *)(GPIOC_BASE + GPIO_BRR) = (1u<<PCI_PERSTN_PIN);
    *(volatile uint32_t *)(GPIOA_BASE + GPIO_BRR) = (1u<<HRESET_PIN) | (1u<<PORESET_PIN);
    cpu_boot_stage = 3;

    scan_i2c_bus();
    flash_jedec_id = spi_flash_read_jedec_id_continuous();
    cpu_boot_stage = 4;

    delay_ms(T_ASSERT_PAD_MS);
    cpu_boot_stage = 5;

    i2c3_write_reg(0x70, 230, 0x10);
    i2c3_write_reg(0x71, 230, 0x10);
    i2c3_write_reg(0x70, 241, 0xE5);
    i2c3_write_reg(0x71, 241, 0xE5);

    status_pb6_alarm_during_si5338 = 0;
    si5338_0x70_first_fail_index = 0xFFFFFFFF;
    si5338_0x71_first_fail_index = 0xFFFFFFFF;

    si5338_0x70_fail_count = si5338_load_table(0x70, Si5338_0x70_Regs, SI5338_0x70_REG_COUNT,
        &status_pb6_alarm_during_si5338,
        &si5338_0x70_first_fail_index, &si5338_0x70_first_fail_addr,
        &si5338_0x70_first_fail_expected, &si5338_0x70_first_fail_actual);
    si5338_0x71_fail_count = si5338_load_table(0x71, Si5338_0x71_Regs, SI5338_0x71_REG_COUNT,
        &status_pb6_alarm_during_si5338,
        &si5338_0x71_first_fail_index, &si5338_0x71_first_fail_addr,
        &si5338_0x71_first_fail_expected, &si5338_0x71_first_fail_actual);
    cpu_boot_stage = 6;

    i2c3_write_reg(0x70, 246, 0x02);
    i2c3_write_reg(0x71, 246, 0x02);
    delay_ms(25);

    i2c3_write_reg(0x70, 241, 0x65);
    i2c3_write_reg(0x71, 241, 0x65);
    cpu_boot_stage = 7;

    si5338_0x70_locked = si5338_poll_lock(0x70, SI5338_CAL_POLL_TIMEOUT_MS);
    si5338_0x71_locked = si5338_poll_lock(0x71, SI5338_CAL_POLL_TIMEOUT_MS);
    status_si5338_lock_timeout = (si5338_0x70_locked && si5338_0x71_locked) ? 0 : 1;

    si5338_0x70_reg218 = i2c3_read_reg(0x70, 218);
    si5338_0x71_reg218 = i2c3_read_reg(0x71, 218);

    if (si5338_0x70_locked) si5338_finalize_calibration(0x70);
    if (si5338_0x71_locked) si5338_finalize_calibration(0x71);
    cpu_boot_stage = 8;

    i2c3_write_reg(0x70, 230, 0x08);
    i2c3_write_reg(0x71, 230, 0x00);

    status_PLL_LOCK_TIMEOUT = status_si5338_lock_timeout;
    (void)cpu_wait_pll_locked(T_PLL_LOCK_TIMEOUT_MS);
    cpu_boot_stage = 9;

    *(volatile uint32_t *)(GPIOA_BASE + GPIO_BSRR) = (1u<<HRESET_PIN) | (1u<<PORESET_PIN);
    *(volatile uint32_t *)(GPIOC_BASE + GPIO_BSRR) = (1u<<PCI_PERSTN_PIN);
    spi_flash_release_bus();
    cpu_boot_stage = 10;
}

void cpu_monitor_loop(void) {
    for (;;) {
        status_RESET_REQ = cpu_read_reset_req();
        status_CKSTP     = cpu_read_ckstp();
        if (status_RESET_REQ) cpu_boot_sequence();
        delay_ms(10);
    }
}

void Reset_Handler(void) {
    *RCC_AHB2ENR |= 0x7u; delay_ticks(10);
    *RCC_APB1ENR1 |= (1u<<28); delay_ticks(10);
    *PWR_CR1 |= (1u<<8);
    *RCC_BDCR |= (1u<<16); *RCC_BDCR &= ~(1u<<16);
    *PWR_CR1 &= ~(3u<<9); *PWR_CR1 |= (1u<<9);
    while (*PWR_SR2 & (1u<<10));
    *FLASH_ACR &= ~7u; *FLASH_ACR |= 4u;
    while ((*FLASH_ACR & 7u) != 4u);

    *RCC_CR &= ~(15u<<4); *RCC_CR |= (6u<<4);
    *RCC_CR |= (1u<<3);
    while (!(*RCC_CR & (1u<<1)));

    *RCC_PLLCFGR = 0;
    *RCC_PLLCFGR |= (1u<<0)|(0u<<4)|(0x28<<8)|(1u<<25)|(1u<<24);
    *RCC_CR |= (1u<<24);
    while (!(*RCC_CR & (1u<<25)));

    *RCC_CFGR &= ~3u; *RCC_CFGR |= 3u;
    while ((*RCC_CFGR & (3u<<2)) != (3u<<2));

    *(volatile uint32_t *)(GPIOB_BASE+GPIO_MODER) &= ~15;
    *(volatile uint32_t *)(GPIOB_BASE+GPIO_PUPDR) &= ~3;
    *(volatile uint32_t *)(GPIOB_BASE+GPIO_PUPDR) |= 1;
    *(volatile uint32_t *)(GPIOB_BASE+GPIO_MODER) &= ~(3<<10);

    *(volatile uint32_t *)(GPIOA_BASE+GPIO_MODER) &= ~(3<<20);
    *(volatile uint32_t *)(GPIOB_BASE+GPIO_MODER) &= ~(3<<14);
    *(volatile uint32_t *)(GPIOA_BASE+GPIO_PUPDR) &= ~(3<<20);
    *(volatile uint32_t *)(GPIOB_BASE+GPIO_PUPDR) &= ~(3<<14);

    *(volatile uint32_t *)(GPIOA_BASE+GPIO_MODER) &= ~((3<<14)|(3<<4));
    *(volatile uint32_t *)(GPIOB_BASE+GPIO_MODER) &= ~(3<<8);
    *(volatile uint32_t *)(GPIOA_BASE+GPIO_PUPDR) &= ~((3<<14)|(3<<4));
    *(volatile uint32_t *)(GPIOA_BASE+GPIO_PUPDR) |= ((1<<14)|(1<<4));
    *(volatile uint32_t *)(GPIOB_BASE+GPIO_ODR) |= (1<<7)|(1<<2)|(1<<4);

    *(volatile uint32_t *)(GPIOC_BASE+GPIO_MODER) &= ~(3<<26);
    *(volatile uint32_t *)(GPIOC_BASE+GPIO_MODER) |=  (1<<26);
    *(volatile uint32_t *)(GPIOC_BASE+GPIO_ODR) |= (1<<13); delay_ms(10);

    i2c3_init(); spi_flash_init(); cpu_reset_gpio_init();

    volatile uint32_t *GPIOA_IDR = (volatile uint32_t *)(GPIOA_BASE + GPIO_IDR);
    volatile uint32_t *GPIOB_IDR = (volatile uint32_t *)(GPIOB_BASE + GPIO_IDR);

    status_ALARM_IPM       = (*GPIOB_IDR & (1<<0)) ? 1 : 0;
    status_THERM           = (*GPIOB_IDR & (1<<1)) ? 1 : 0;
    status_EN_A_ACB        = (*GPIOA_IDR & (1<<8)) ? 1 : 0;
    status_EN_B_ACB        = (*GPIOA_IDR & (1<<9)) ? 1 : 0;
    status_PG_78_P1V0_PCIE = (*GPIOA_IDR & (1<<10)) ? 1 : 0;
    status_ALL_PLL_LOCKED  = (*GPIOB_IDR & (1<<6)) ? 0 : 1;

    pin_PA8  = (*GPIOA_IDR & (1<<8))  ? "HIGH" : "LOW";
    pin_PA9  = (*GPIOA_IDR & (1<<9))  ? "HIGH" : "LOW";
    pin_PA10 = (*GPIOA_IDR & (1<<10)) ? "HIGH" : "LOW";
    pin_PB0  = (*GPIOB_IDR & (1<<0))  ? "HIGH" : "LOW";
    pin_PB1  = (*GPIOB_IDR & (1<<1))  ? "HIGH" : "LOW";
    pin_PB6  = (*GPIOB_IDR & (1<<6))  ? "HIGH" : "LOW";
    pin_PB7  = (*GPIOB_IDR & (1<<7))  ? "HIGH" : "LOW";

    if ((*GPIOA_IDR & (1<<10)) && (*GPIOB_IDR & (1<<7))) {
        cpu_boot_sequence();
    } else {
        flash_jedec_id = 0x00000000;
    }

    cpu_monitor_loop();
}

void Dummy_Handler(void) { while(1); }
extern void _estack(void);
__attribute__((section(".vector_table")))
void (* const vector_table[])(void) = {
    &_estack, Reset_Handler, Dummy_Handler, Dummy_Handler,
    Dummy_Handler, Dummy_Handler, Dummy_Handler, 0, 0, 0, 0,
    Dummy_Handler, Dummy_Handler, 0, Dummy_Handler, Dummy_Handler
};
