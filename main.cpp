// including the standard in/out header
#include <cstdio>
// include the GLEW loading library header
#include <GL/glew.h>
// including the GLFW library header
#include <GLFW/glfw3.h>

// callback for error handling
// arg1: the error code
// arg2: the error description string
void error_callback(int error, const char* description)
{
	fprintf(stderr, "Error: %s\n", description);
}

int main()
{
	// Pass error callback to GLFW so it can call errors
	glfwSetErrorCallback(error_callback);

	// create a pointer to the window for use
	GLFWwindow* window;

	// initialize GLFW library (or error out)
	if(!glfwInit()) return -1;

	// give GLFW context hints for version 3
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	// assign window
	window = glfwCreateWindow(640, 480, "Space Invaders", NULL, NULL);

	// terminate GLFW and the program if window creation fails
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	// make subsequent calls apply to the window context
	glfwMakeContextCurrent(window);

	// initialize GLEW
	GLenum err = glewInit();

	// if GlEW not initialized, terminate GLFW and program
	if(err != GLEW_OK)
	{
		fprintf(stderr, "Error initializing GLEW.\n");
		glfwTerminate();
		return -1;
	}

	// set array to define OpenGL version [major, minor]
	int glVersion[2] = {-1, 1};

	// get Major and Minor GL versions and set in array
	glGetIntegerv(GL_MAJOR_VERSION, &glVersion[0]);
	glGetIntegerv(GL_MINOR_VERSION, &glVersion[1]);

	// print Open GL version
	printf("Using OpenGL: %d.%d\n", glVersion[0], glVersion[1]);

	// set screen color to red
	glClearColor(1.0, 0.0, 0.0, 1.0);

	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
}