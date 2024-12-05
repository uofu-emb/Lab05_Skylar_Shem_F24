#include <stdio.h>
#include <pico/stdlib.h>
#include <pico/sync.h>

// start the toggle variable high
int toggle = 1;

int busy_loop(void);
/*
* Interrupt request
*
*  @param gpio: input from the wave generator.
*/
void irq_callback(uint gpio, uint32_t event_mask)
{
    sleep_ms(36);
    if (gpio != IN_PIN) return;
    toggle = !toggle;
    if (event_mask & GPIO_IRQ_EDGE_RISE) {
        gpio_put(OUT_PIN, true);
    } else if (event_mask & GPIO_IRQ_EDGE_FALL) {
        gpio_put(OUT_PIN, false);
    }
}

int main(void)
{
    // setup
    stdio_init_all();

    // pin assignment
    gpio_init(IN_PIN);
    gpio_set_dir(IN_PIN, GPIO_IN);

    gpio_init(OUT_PIN);
    gpio_set_dir(OUT_PIN, GPIO_OUT);
    gpio_put(OUT_PIN, toggle);

    // Interrupt request
    gpio_set_irq_enabled_with_callback(IN_PIN, GPIO_IRQ_EDGE_RISE | GPIO_IRQ_EDGE_FALL , true, irq_callback);

    // Infinite no_op loop
    while(1) __wfi();
    return 0;
}


int busy_loop(void) {
    int count = 0;
    while(count < 36) {
        count++;
        sleep_ms(1);
    }
}