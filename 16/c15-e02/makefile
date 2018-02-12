ex:			main.o  Func1.o  Func2.o  Graph.o  GUI.o  Simple_window.o  Window.o
			g++   -o ex   main.o  Func1.o  Func2.o  Graph.o  GUI.o  Simple_window.o  Window.o   /usr/local/lib/libfltk_images.a -lpng -lz -ljpeg /usr/local/lib/libfltk_gl.a -lGLU -lGL /usr/local/lib/libfltk.a -lXext -lXft -lfontconfig -lXinerama -lpthread -ldl -lm -lX11

main.o:			main.cpp  Func1.hpp  Func2.hpp  /home/blanca/bs_ppp/bs_fltk/Simple_window.h  /home/blanca/bs_ppp/bs_fltk/Graph.h
			g++   -I/usr/local/include -I/usr/include/freetype2 -D_LARGEFILE_SOURCE -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64 -D_THREAD_SAFE -D_REENTRANT   -c -Wno-deprecated   main.cpp   -o main.o

Func1.o:		Func1.cpp  Func1.hpp  /home/blanca/bs_ppp/bs_fltk/Simple_window.h  /home/blanca/bs_ppp/bs_fltk/Graph.h
			g++   -I/usr/local/include -I/usr/include/freetype2 -D_LARGEFILE_SOURCE -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64 -D_THREAD_SAFE -D_REENTRANT   -c -Wno-deprecated   Func1.cpp   -o Func1.o

Func2.o:		Func2.cpp  Func2.hpp  /home/blanca/bs_ppp/bs_fltk/Simple_window.h  /home/blanca/bs_ppp/bs_fltk/Graph.h
			g++   -I/usr/local/include -I/usr/include/freetype2 -D_LARGEFILE_SOURCE -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64 -D_THREAD_SAFE -D_REENTRANT   -c -Wno-deprecated   Func2.cpp   -o Func2.o



Graph.o:		/home/blanca/bs_ppp/bs_fltk/Graph.cpp  /home/blanca/bs_ppp/bs_fltk/Graph.h
			g++   -I/usr/local/include -I/usr/include/freetype2 -D_LARGEFILE_SOURCE -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64 -D_THREAD_SAFE -D_REENTRANT   -c -Wno-deprecated   /home/blanca/bs_ppp/bs_fltk/Graph.cpp   -o Graph.o

GUI.o:			/home/blanca/bs_ppp/bs_fltk/GUI.cpp  /home/blanca/bs_ppp/bs_fltk/GUI.h
			g++   -I/usr/local/include -I/usr/include/freetype2 -D_LARGEFILE_SOURCE -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64 -D_THREAD_SAFE -D_REENTRANT   -c -Wno-deprecated   /home/blanca/bs_ppp/bs_fltk/GUI.cpp   -o GUI.o

Simple_window.o:	/home/blanca/bs_ppp/bs_fltk/Simple_window.cpp  /home/blanca/bs_ppp/bs_fltk/Simple_window.h
			g++   -I/usr/local/include -I/usr/include/freetype2 -D_LARGEFILE_SOURCE -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64 -D_THREAD_SAFE -D_REENTRANT   -c -Wno-deprecated   /home/blanca/bs_ppp/bs_fltk/Simple_window.cpp   -o Simple_window.o

Window.o:		/home/blanca/bs_ppp/bs_fltk/Window.cpp  /home/blanca/bs_ppp/bs_fltk/Window.h  /home/blanca/bs_ppp/bs_fltk/Graph.h  /home/blanca/bs_ppp/bs_fltk/GUI.h
			g++   -I/usr/local/include -I/usr/include/freetype2 -D_LARGEFILE_SOURCE -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64 -D_THREAD_SAFE -D_REENTRANT   -c -Wno-deprecated   /home/blanca/bs_ppp/bs_fltk/Window.cpp   -o Window.o



clean:
	rm *.o
