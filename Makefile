MAKEFILE = Makefile

all: build

build:
	@echo "Building system..."
	cd practice_1; make
	cd practice_2; make
	cd practice_3; make
	cd practice_4; make
	cd practice_5; make
	cd practice_6; make
	cd practice_7; make
	cd practice_8; make
	cd practice_9; make
	cd practice_10; make

test:
	@echo "Tests!"
