#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

int windowWidth = 640;
int windowHeight = 480;

void glfwWindowSizeCallback(GLFWwindow* window, int widht, int height) {
	windowWidth = widht;
	windowHeight = height;
	glViewport(0, 0, windowWidth, windowHeight);
}

void glfwKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mode) {
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, GLFW_TRUE);
	}
}

int main(void) {
	GLFWwindow* mainWindow;

	/* Initialize the library */
	if (!glfwInit()) {
		fprintf(stderr, "Can't initialize GLFW.");
		return -1;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	/* Create a windowed mode window and its OpenGL context */
	mainWindow = glfwCreateWindow(windowWidth, windowHeight, "Battle City", nullptr, nullptr);
	if (!mainWindow) {
		fprintf(stderr, "Can't create the window.");
		glfwTerminate();
		return -1;
	}

	glfwSetWindowSizeCallback(mainWindow, glfwWindowSizeCallback);
	glfwSetKeyCallback(mainWindow, glfwKeyCallback);

	/* Make the window's context current */
	glfwMakeContextCurrent(mainWindow);

	if (!gladLoadGL()) {
		fprintf(stderr, "Can\'t load GLAD.");
		return -1;
	}

	printf("Renderer %s\n", glGetString(GL_RENDERER));
	printf("OpenGL v.%s", glGetString(GL_VERSION));

	glClearColor(.15, .15, .15, 1);

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(mainWindow)) {
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);

		/* Swap front and back buffers */
		glfwSwapBuffers(mainWindow);

		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}