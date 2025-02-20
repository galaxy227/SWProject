CC = g++
CCFLAGS = -Wall -Wextra -std=c++2a
DIR_OBJ = ./OBJ/
DIR_PROJ = ./project/
OBJ_FILES = $(addprefix $(DIR_OBJ), main.o project.o led.o flame.o motor.o ultrasound.o arc.o audio.o)
LIBRARIES = -lwiringPi -lmpg123 -lao

main: $(OBJ_FILES)
	$(CC) $(CCFLAGS) $(OBJ_FILES) -o main $(LIBRARIES)
	rm -r -f $(DIR_OBJ)

$(DIR_OBJ)main.o: $(DIR_PROJ)main.cc | $(DIR_OBJ)
	$(CC) $(CCFLAGS) -c $(DIR_PROJ)main.cc -o $(DIR_OBJ)main.o

$(DIR_OBJ)project.o: $(DIR_PROJ)project.cc $(DIR_PROJ)project.h
	$(CC) $(CCFLAGS) -c $(DIR_PROJ)project.cc -o $(DIR_OBJ)project.o

$(DIR_OBJ)led.o: $(DIR_PROJ)led.cc $(DIR_PROJ)project.h
	$(CC) $(CCFLAGS) -c $(DIR_PROJ)led.cc -o $(DIR_OBJ)led.o

$(DIR_OBJ)flame.o: $(DIR_PROJ)flame.cc $(DIR_PROJ)project.h
	$(CC) $(CCFLAGS) -c $(DIR_PROJ)flame.cc -o $(DIR_OBJ)flame.o

$(DIR_OBJ)motor.o: $(DIR_PROJ)motor.cc $(DIR_PROJ)project.h
	$(CC) $(CCFLAGS) -c $(DIR_PROJ)motor.cc -o $(DIR_OBJ)motor.o

$(DIR_OBJ)ultrasound.o: $(DIR_PROJ)ultrasound.cc $(DIR_PROJ)project.h
	$(CC) $(CCFLAGS) -c $(DIR_PROJ)ultrasound.cc -o $(DIR_OBJ)ultrasound.o

$(DIR_OBJ)arc.o: $(DIR_PROJ)arc.cc $(DIR_PROJ)project.h
	$(CC) $(CCFLAGS) -c $(DIR_PROJ)arc.cc -o $(DIR_OBJ)arc.o

$(DIR_OBJ)audio.o: $(DIR_PROJ)audio.cc $(DIR_PROJ)project.h
	$(CC) $(CCFLAGS) -c $(DIR_PROJ)audio.cc -o $(DIR_OBJ)audio.o

$(DIR_OBJ):
	mkdir -p $(DIR_OBJ)

clean:
	rm -f main
