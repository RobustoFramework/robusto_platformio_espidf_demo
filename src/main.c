#include <robusto_init.h>
#include <robusto_logging.h>
#include <robusto_time.h>


void app_main() {
    init_robusto();

    while (1) {
        r_delay(10000);
        ROB_LOGI("Example", "The memory warning is intentionally set low.");
    }
}