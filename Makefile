CC=gcc
CCOPTS=-Wall -Wextra

BINARIES_FOLDER=.bin
OBJECTS_FOLDER=.objects

BINARIES=algorithms/binary_search \
	algorithms/rec_binary_search \
	algorithms/selection_sort \
	exercises/recursion/static_and_global \
	exercises/recursion/tail_and_head \
	exercises/recursion/tree \
	exercises/recursion/indirect

OBJECT_FILES=algorithms/binary_search.o \
	algorithms/rec_binary_search.o \
	algorithms/selection_sort.o \
	data-structures/array/array.o \
	data-structures/linked-list/linked-list.o \
	exercises/recursion/static_and_global.o \
	exercises/recursion/tail_and_head.o \
	exercises/recursion/tree.o \
	exercises/recursion/indirect.o \

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