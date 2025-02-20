#include "project.h"
#include <thread>
#include <chrono>
using Time = std::chrono::high_resolution_clock::time_point;
using Clock = std::chrono::high_resolution_clock;
using Duration = std::chrono::duration<float>;
using namespace Project;

void do_audio_thread() {
	do_audio("./audio/starwarssfxwithmeme.mp3");
}
void do_flame_thread() {
	bool is_flame = false;
	const int max_loop = 50;
	for (int i = 0; i < max_loop && !is_flame; i++) {
		// Spark
		do_arc(true);
		delay(50);
		do_arc(false);
		delay(50);
		// Detect
		is_flame = get_flame();
		delay(100);
	}
}
Duration get_duration(Time start_time) {
	return Clock::now() - start_time;
}

int main(int argc, char* argv[]) {
	init_all();
	if (argc > 1) exit(0);
	do_led(RED, true);

	// Audio thread
	std::thread audio_thread(do_audio_thread);
	Time start_time = Clock::now();
	
	// Wait for trap door sound (15.75 second mark)
	while (get_duration(start_time).count() < 15.75f) {}
	// Open trap door
	do_motor(TRAP_DOOR, true, OPEN);
	delay(250); // Wait for trap door
	do_motor(TRAP_DOOR, false);
	
	// Detect R2D2 falling
	bool is_movement = false;
	while (!is_movement) {
		is_movement = get_ultrasound(30);
		delay(100);
	}

	// Flame thread
	std::thread flame_thread(do_flame_thread);
	
	// Wait for stormtrooper door sound (27 second mark)
	while (get_duration(start_time).count() < 27) {}
	// Open stormtrooper door
	do_motor(STORMTROOPER_DOOR, true, OPEN);
	delay(325); // TODO Wait for stormtrooper door
	do_motor(STORMTROOPER_DOOR, false);
	do_led(RED, false);
	do_led(GREEN, true);
	// Close trap door
	do_motor(TRAP_DOOR, true, CLOSE);
	delay(190); // Wait for trap door
	do_motor(TRAP_DOOR, false);

	// Wait for ending music (40 second mark)
	while (get_duration(start_time).count() < 40) {}
	// Close stormtrooper door
	do_motor(STORMTROOPER_DOOR, true, CLOSE);
	delay(275); // Wait for stormtrooper door
	do_motor(STORMTROOPER_DOOR, false);
	do_led(RED, true);
	do_led(GREEN, false);
	
	// Wait for meme sound (63 second mark)
	while (get_duration(start_time).count() < 63) {}
	// Meme
	do_motor(STORMTROOPER_DOOR, true, OPEN);
	int flicker_count = 0;
	while (get_duration(start_time).count() < 101) {
		bool is_on = (flicker_count % 2 == 0) ? true : false;
		do_led(GREEN, is_on);
		do_led(RED, !is_on);
		flicker_count++;
		delay(500);
	}

	// Turn off project
	audio_thread.join();
	off_all();
	flame_thread.join();	

	return 0;
}
