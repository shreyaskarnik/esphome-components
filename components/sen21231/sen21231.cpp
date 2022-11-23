#include "sen21231.h"
#include "esphome/core/log.h"

namespace esphome {
namespace sen21231_sensor {

static const char *TAG = "sen21231_sensor.sensor";

void Sen21231Sensor::read_data_() {
    // read data and cast it into the person_sensor_results_t struct
    person_sensor_results_t results;
    this->read_bytes(PERSON_SENSOR_REG_RESULTS, (uint8_t *)&results,
                     sizeof(results));
    if (results.num_faces > 0) {
        ESP_LOGD(TAG, "SEN21231: %d faces detected", results.num_faces);
        this->publish_state(true);
    }
}
void Sen21231Sensor::setup() {}

void Sen21231Sensor::update() {}

void Sen21231Sensor::dump_config() {
    ESP_LOGCONFIG(TAG, "SEN21231:");
    LOG_I2C_DEVICE(this);
    if (this->is_failed()) {
        ESP_LOGE(TAG, "Communication with SEN21231 failed!");
    }
    ESP_LOGI(TAG, "SEN21231: %s", this->is_failed() ? "FAILED" : "OK");
    this->read_data_();
}

} // namespace sen21231_sensor
} // namespace esphome
