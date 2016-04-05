CC := g++
SRCDIR := src
BUILDDIR := build
TARGET := bin/conway-engine
RM := rm

SRCEXT := cpp
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
CFLAGS := -g -Wall
INC := -I include

$(TARGET): $(OBJECTS)
	@echo " Linking..."
	@echo " $(CC) $^ -o $(TARGET) $(LIB)"; $(CC) $^ -o $(TARGET)

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(BUILDDIR)
	@echo " $(CC) $(CFLAGS) $(INC) -c -o $@ $<"; $(CC) $(CFLAGS) $(INC) -c -o $@ $<

glider: $(TARGET)
	./run.sh 50 50 100 ../conway-algol/patterns/glider.cells

glidergun: $(TARGET)
	./run.sh 50 50 100 ../conway-algol/patterns/gosperglidergun.cells

clean:
	@echo " Cleaning...";
	@echo " $(RM) -rf $(BUILDDIR) $(TARGET)"; $(RM) -rf $(BUILDDIR) $(TARGET)

# Tests
tester:
	$(CC) $(CFLAGS) test/tester.cpp $(INC) $(LIB) -o bin/tester

.PHONY: clean
