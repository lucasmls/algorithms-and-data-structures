CC=gcc
CCOPTS=-Wall -Wextra

BINARIES_FOLDER=.bin
OBJECTS_FOLDER=.objects

BINARIES=algorithms/binary_search

OBJECT_FILES=algorithms/binary_search.o \
	data-structures/array/array.o \
	data-structures/linked-list/linked-list.o \

LIBS=$(OBJECTS_FOLDER)/array.o \
	$(OBJECTS_FOLDER)/linked-list.o

.PHONE: all clean

all: $(BINARIES)

clean:
	@ echo
	@ echo Cleaning up binaries and object files...
	@ echo
	@ rm -rf $(OBJECTS_FOLDER) $(BINARIES_FOLDER)

folders:
	@ mkdir -p $(BINARIES_FOLDER) && mkdir -p $(OBJECTS_FOLDER)

%.o: %.c folders
	@ echo [COMPILING] $<
	@ $(CC) $(CCOPTS) -o $(OBJECTS_FOLDER)/$(notdir $@) -c $<

$(BINARIES): $(OBJECT_FILES)
	@ echo [INFO] Creating binary $(BINARIES_FOLDER)/$(notdir $@)
	@ $(CC) $(CCOPTS) -o $(BINARIES_FOLDER)/$(notdir $@) $(OBJECTS_FOLDER)/$(notdir $@).o $(LIBS)