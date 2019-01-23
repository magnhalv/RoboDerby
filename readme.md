
#Setup

##Dependencies:


Use CMAKE to build the following libaries, and link to them in a Include(header files) and Libary(bin files) directory. Set the correct path in Project Properties -> VC++ Directories. 
	- GLFW:
		- https://www.glfw.org/download.html
	- GLAD:
		- https://glad.dav1d.de/
		- <= v3.3
	- STB Image (header libary)
		- https://github.com/nothings/stb/blob/master/stb_image.h
	- freetype
		- https://www.freetype.org/

Using CMAKE:
	- Download cmake: https://cmake.org/download/
	- Convert source code to a visual studio project
	- Build the project as release for Win32. 
