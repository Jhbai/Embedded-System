#include <stdint.h>
#include <stdbool.h>
// 1. 硬體抽象層（HAL）：
// HAL 是一層軟體，它屏蔽了底層硬體的複雜性，為開發者提供標準化的接口，便於不同硬體平台上的程式移植
// 2. 寄存器（Register）：
// 微控制器內部的特殊存儲單元，用於配置或控制硬體外設，如 GPIO、定時器等。
// 3. 記憶體映射（Memory-Mapped I/O）：
// 一種將硬體外設的控制寄存器直接映射到 CPU 的地址空間的技術，方便通過讀寫特定地址訪問外設。
// 4. 抽象接口（Abstract Interface）：
// 提供與硬體交互的標準函式，如初始化、讀取、寫入等。


// 定義 GPIO 寄存器地址 (假設為嵌入式平台特定地址)
#define GPIO_BASE_ADDR   0x40020000
#define GPIO_MODER       (*(volatile uint32_t *)(GPIO_BASE_ADDR + 0x00))
#define GPIO_ODR         (*(volatile uint32_t *)(GPIO_BASE_ADDR + 0x14))

// 定義 GPIO 位元位置
#define GPIO_PIN         5

// HAL 層函式
void HAL_GPIO_Init(void) {
    // 將 GPIO_PIN 配置為輸出模式
    GPIO_MODER &= ~(0x3 << (GPIO_PIN * 2));  // 清除模式位元
    GPIO_MODER |=  (0x1 << (GPIO_PIN * 2));  // 設置為輸出模式
}

void HAL_GPIO_Write(bool state) {
    if (state) {
        GPIO_ODR |= (1 << GPIO_PIN);  // 設置 PIN 為高電平
    } else {
        GPIO_ODR &= ~(1 << GPIO_PIN); // 設置 PIN 為低電平
    }
}

int main() {
    HAL_GPIO_Init();  // 初始化 GPIO

    while (1) {
        HAL_GPIO_Write(true);  // 開燈
        for (volatile int i = 0; i < 1000000; i++);  // 簡單延遲

        HAL_GPIO_Write(false); // 關燈
        for (volatile int i = 0; i < 1000000; i++);  // 簡單延遲
    }

    return 0;
}
