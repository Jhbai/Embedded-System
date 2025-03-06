#include <stdint.h>
#define UART0_BASE 0x101f1000
#define UART0_DR (UART0_BASE + 0x00)
#define UART0_FR (UART0_BASE + 0x18)
void putchar(char c) {
    while (*(volatile uint32_t *)UART0_FR & 0x20); // 等待傳輸寄存器空
    *(volatile uint32_t *)UART0_DR = c;
}
int main() {
    putchar('H'); putchar('e'); putchar('l'); putchar('l');
    putchar('o'); putchar(' '); putchar('W'); putchar('o');
    putchar('r'); putchar('l'); putchar('d'); putchar('!');
    putchar('\n');
    return 0;
}
