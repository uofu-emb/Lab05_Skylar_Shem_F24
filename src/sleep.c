#include <stdio.h>
#include <pico/stdlib.h>

int busy_loop(void);

int main(void)
{
    int toggle = 0;
    stdio_init_all();
    gpio_init(OUT_PIN);
    gpio_set_dir(OUT_PIN, GPIO_OUT);
    gpio_put(OUT_PIN, toggle);

    while (true) {
        toggle = !toggle;
        gpio_put(OUT_PIN, toggle);
        busy_loop();
        sleep_ms(DELAY_MS);
    }
}


int busy_loop(void) {
    int count = 0;
    while(count < 36) {
        count++;
        sleep_ms(1);
    }
}
