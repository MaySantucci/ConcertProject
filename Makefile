project_name = concert_manager
debug_binary = $(project_name)_debug

build:
	g++ *.cpp -o $(project_name)

run: build
	./$(project_name)

build-debug:
	g++ -g *.cpp -o $(debug_binary)

debug: build-debug
	gdb $(debug_binary)

clean:
	rm $(project_name) $(debug_binary)
