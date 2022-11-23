#include "esphome/core/log.h"
#include "sen21231.h"

namespace esphome {
namespace sen21231 {

static const char *TAG = "sen21231.sensor";

void SEN21231Component::setup() {}

void SEN21231Component::loop() {}

void SEN21231Component::dump_config() {
    ESP_LOGCONFIG(TAG, " SEN21231 component");
}

} // namespace sen21231
} // namespace esphome
