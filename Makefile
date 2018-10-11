project_name = concert_manager
release_binary = $(project_name).out
debug_binary = $(project_name)_debug.out

build:
	g++ *.cpp -o $(release_binary)

run: build
	./$(release_binary)

build-debug:
	g++ -g *.cpp -o $(debug_binary)

debug: build-debug
	gdb $(debug_binary)

clean:
	rm $(release_binary) $(debug_binary)
