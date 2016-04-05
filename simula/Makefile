CIM=sleep 1; cim
CC=gcc
EXECUTABLE=conway-player

ARCH=$(shell getconf LONG_BIT)
CIM_FLAGS_32=-DBIT32
CIM_FLAGS_64=-DBIT64
CIM_FLAGS=$(CIM_FLAGS_$(ARCH))

$(EXECUTABLE): conway.o unix.o patternreader.o bits.o conway-player.sim
	$(CIM) $(CIM_FLAGS) -e -o $(EXECUTABLE) conway-player.sim conway.o board.o unix.o bits.o patternreader.o

bits.o: bits.c
	$(CC) -c bits.c

unix.o: unix.sim bits.o
	$(CIM) $(CIM_FLAGS) -c unix.sim bits.o

board.o: board.sim
	$(CIM) $(CIM_FLAGS) -c board.sim

conway.o: board.o conway.sim
	$(CIM) $(CC_FLAGS) -c conway.sim board.o

patternreader.o: board.o conway.o patternreader.sim
	$(CIM) $(CC_FLAGS) -c patternreader.sim board.o conway.o

glider: $(EXECUTABLE)
	./run.sh 50 50 ../conway-algol/patterns/glider.cells 100	

glidergun: $(EXECUTABLE)
	./run.sh 50 50 ../conway-algol/patterns/gosperglidergun.cells 100

clean:
	rm -f *.o
	rm -f *.atr
	rm -f $(EXECUTABLE)
