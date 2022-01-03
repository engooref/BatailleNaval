SOURCE_DIR = Sources/
SRC_DIR = $(shell find $(SOURCE_DIR) -type d)
INCLUDE_DIR = Includes/

CC = gcc
CFLAGS = -W -Wall -I$(INCLUDE_DIR)
CLIBS = -lstdc++

EXEC = Navy
EXT_SRC = .cpp

SRC = $(shell find $(SRC_DIR) -name *$(EXT_SRC))
OBJ = $(SRC:$(EXT_SRC)=.o)

all: $(EXEC)
	$(shell make clean)

$(EXEC): $(OBJ)
	$(CC) -o $@ $^ $(CLIBS)
	

%.o: %.cpp  
	$(CC) -o $@ -c $< $(CFLAGS)

clean: 
	@rm -f $(OBJ)