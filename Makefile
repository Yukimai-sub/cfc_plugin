ifdef CROSSCOMPILE # Note: Cross compilation has not been tested
	CC=x86_64-w64-mingw32-g++
	CCFLAGS=-I$(GCC_WIN32_PLUGIN_PATH)/include -I./include
	LDFLAGS=-shared -Wl,--export-all-symbols
	STATICLIB=$(GCC_WIN32_PLUGIN_PATH)/cc1.exe.a
	PLUGINTARGET=cfc.dll
else
	CC=g++
	CCFLAGS=-I`$(RVCC) -print-file-name=plugin`/include -I/usr/local/include -fPIC -fno-rtti -I./include
	LDFLAGS=-shared
	STATICLIB=
	PLUGINTARGET=cfc.so
endif
RVCC=riscv64-unknown-elf-g++
PLUGINSRC=$(wildcard src/*.cpp)
PLUGINHDR=$(wildcard include/*.h)
PLUGINOBJ=$(PLUGINSRC:src/%.cpp=%.o)
TESTSRC=$(wildcard test/*.cpp)
TESTOBJ=$(TESTSRC:test/%.cpp=%.test.S)

all: $(PLUGINTARGET)

$(PLUGINTARGET): $(PLUGINOBJ)
	$(CC) $^ $(STATICLIB) -o $@ $(LDFLAGS)

%.o: src/%.cpp $(PLUGINHDR)
	$(CC) $< -c -o $@ $(CCFLAGS)

%.test.S: test/%.cpp $(PLUGINTARGET)
	$(RVCC) $< -fplugin=./$(PLUGINTARGET) -S -o $@

test: $(TESTOBJ)
	echo $(TESTOBJ)

clean:
	rm -f *.test.S *.o $(PLUGINTARGET)

.PHONY: all test clean
