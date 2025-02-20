#ifndef PROJECT_H
#define PROJECT_H

#define RED 1
#define GREEN 0
#define OPEN 1
#define CLOSE 0
#define TRAP_DOOR 1
#define STORMTROOPER_DOOR 0

#include <wiringPi.h>

namespace Project {
	// PROJECT
	void init_all();
	void init_wiringPi();
	void off_all();
	// LED
	void init_led();
	void do_led(const bool is_red, const bool is_on);
	// FLAME
	void init_flame();
	bool get_flame();
	// MOTOR
	void init_motor();
	void do_motor(const bool is_trapdoor, const bool is_on, const bool is_opening = true);
	// ULTRASOUND
	void init_ultrasound();
	bool get_ultrasound(const int distance_threshold);
	// ARC
	void init_arc();
	void do_arc(const bool is_on);
	// AUDIO
	void do_audio(const char* audio_file);
}

#endif
