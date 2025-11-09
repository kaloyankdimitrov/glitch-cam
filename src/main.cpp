#include <Arduino.h>

#include "rx5808.h"

const uint8_t CH2_PIN = 22;
const uint8_t CHAN_SET = 32;
// const int freqLookup = [
// [5865, 5845, 5825, 5805, 5785, 5765, 5745, 5725],
// [5733, 5752, 5771, 5790, 5809, 5828, 5847, 5866],
// [5705, 5685, 5665, 5645, 5885, 5905, 5925, 5945],
// [5740, 5760, 5780, 5800, 5820, 5840, 5860, 5880],
// [5658, 5695, 5732, 5769, 5806, 5843, 5880, 5917],
// [5362, 5399, 5436, 5473, 5510, 5547, 5584, 5621],
// ];
const uint16_t MIN_FREQ = 5800;
const uint16_t MAX_FREQ = 5900;
// Config config;
Rx5808 rx(CH2_PIN);
uint16_t old_freq = 0;

void setup() {
  Serial.begin(115200);

  rx.init();
}

void loop() {
	uint16_t freq = (double(analogRead(CHAN_SET)) / 4095.0 * (MAX_FREQ - MIN_FREQ) + MIN_FREQ);
	Serial.println(freq);
	if (abs(old_freq - freq) > 1) {
		rx.setFrequency(freq);
		old_freq = freq;
	}
	delay(500);
}