build/prog: cpp_files/*.cpp
	rm -rf build/
	mkdir -p build
	g++ -I h_files cpp_files/*.cpp -o build/prog -lraylib -lX11 -lXrandr -lXinerama -lXcursor -lXi -lXext -lGL -lm -lpthread -ldl -lrt


run: build/prog
	./build/prog
	rm -rf build/
