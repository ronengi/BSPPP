graphics_gtk3:	build_folder Point Color_rgb Shape Line main
		g++ -Wall build/Color_rgb.o build/Point.o build/Shape.o build/Line.o build/main.o  -o build/graphics_gtk3 `pkg-config gtkmm-3.0 --cflags --libs`

build_folder:
		mkdir -p build

Point:	Point.cpp Point.hpp
		g++ -c -Wall Point.cpp  -o build/Point.o

Color_rgb:	Color_rgb.cpp Color_rgb.hpp
		g++ -c -Wall Color_rgb.cpp  -o build/Color_rgb.o

Shape:	Shape.cpp Shape.hpp Point.hpp Color_rgb.hpp
		g++ -c -Wall Shape.cpp  -o build/Shape.o

Line:	Line.cpp Line.hpp Shape
		g++ -c -Wall Line.cpp  -o build/Line.o

main:	main.cpp
		g++ -c -Wall main.cpp  -o build/main.o

clean:
	rm -fr build

