#include "project.h"
#include <thread>
using namespace Project;

void do_audio_thread() {
	do_audio("./audio/starwarssfxwithmeme.mp3");
}

int main(int argc, char* argv[]) {
	init_all();
	if (argc > 1) exit(0);
	do_led(RED, true);

	// Audio thread
	std::thread audio_thread(do_audio_thread);

	// Open trap door
	do_motor(TRAP_DOOR, true, OPEN);
	delay(500);
	do_motor(TRAP_DOOR, false);
	
	// Detect R2D2 falling
	bool is_movement = false;
	while (!is_movement) {
		is_movement = get_ultrasound(30);
		delay(100);
	}

	// Detect flame
	bool is_flame = false;
	while (!is_flame) {
		// Spark
		do_arc(true);		
		delay(50);
		do_arc(false);
		delay(50);
		// Detect
		is_flame = get_flame();
		delay(100);
	}

	// Open stormtrooper door
	do_motor(STORMTROOPER_DOOR, true, OPEN);
	do_led(RED, false);
	do_led(GREEN, true);
	delay(500); // TODO Wait for door to open
	do_motor(STORMTROOPER_DOOR, false);
	delay(5000); // TODO audio timing

	// Close all doors
	do_motor(TRAP_DOOR, true, CLOSE);
	do_motor(STORMTROOPER_DOOR, true, CLOSE);
	do_led(GREEN, false);
	do_led(RED, true);
	delay(500); // TODO Wait for doors to close

	// Turn off project
	audio_thread.join();
	off_all();

	return 0;
}
