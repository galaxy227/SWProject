CC = g++
CCFLAGS = -Wall -Wextra -std=c++2a

# INTEGRATION
integration: integrationTest.o
	$(CC) $(CCFLAGS) integrationTest.o -o integration -lwiringPi
	rm -f integrationTest.o
integrationTest.o: integrationTest.cc
	$(CC) $(CCFLAGS) -c integrationTest.cc -o integrationTest.o

# FLAME
flame: flameTest.o
	$(CC) $(CCFLAGS) flameTest.o -o flame -lwiringPi
	rm -f flameTest.o
flameTest.o: flameTest.cc
	$(CC) $(CCFLAGS) -c flameTest.cc -o flameTest.o

# MOTOR
motor: motorTest.o
	$(CC) $(CCFLAGS) motorTest.o -o motor -lwiringPi
	rm -f motorTest.o
motorTest.o: motorTest.cc
	$(CC) $(CCFLAGS) -c motorTest.cc -o motorTest.o

# LED
led: ledTest.o
	$(CC) $(CCFLAGS) ledTest.o -o led -lwiringPi
	rm -f ledTest.o
ledTest.o: ledTest.cc
	$(CC) $(CCFLAGS) -c ledTest.cc -o ledTest.o

# ULTRASOUND
ultrasound: ultrasoundTest.o
	$(CC) $(CCFLAGS) ultrasoundTest.o -o ultrasound -lwiringPi
	rm -f ultrasoundTest.o
ultrasoundTest.o: ultrasoundTest.cc
	$(CC) $(CCFLAGS) -c ultrasoundTest.cc -o ultrasoundTest.o

# SPARK
spark: sparkTest.o
	$(CC) $(CCFLAGS) sparkTest.o -o spark -lwiringPi
	rm -f sparkTest.o
sparkTest.o: sparkTest.cc
	$(CC) $(CCFLAGS) -c sparkTest.cc -o sparkTest.o

# ARC
arc: arcTest.o
	$(CC) $(CCFLAGS) arcTest.o -o arc -lwiringPi
	rm -f arcTest.o
arcTest.o: arcTest.cc
	$(CC) $(CCFLAGS) -c arcTest.cc -o arcTest.o

# AUDIO
audio: audioTest.o
	$(CC) $(CCFLAGS) audioTest.o -o audio -lmpg123 -lao
	rm -f audioTest.o
audioTest.o: audioTest.cc
	$(CC) $(CCFLAGS) -c audioTest.cc -o audioTest.o

clean:
	rm -f integration flame motor led ultrasound spark arc audio
