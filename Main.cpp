#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>
/// Lost at 21 min


int main()
{
	std::cout << "Helo opengl" << std::endl;

	// init the glfw window
	glfwInit();

	// tell GLFW what OpenGL version we use
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
	
	// Tell GLFW to use CORE profile
	glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);

	// open gl datatype float
	GLfloat vertices[] = 
	{
		// each array is an accordinated
		-0.5f, -0.5f * float(squre(3)) / 3, 0.0f,
	}

	// init hte window setting
	//
	GLFWwindow* window = glfwCreateWindow(800, 800, "Open GL Course", NULL, NULL); // w h name full screen 

	// faild return -1
	if (window == NULL)
	{
		std::cout << "Faild to create window" << std::endl;
		glfwTerminate();
		return -1;
	}

	// create context and introduce the window to it.
	glfwMakeContextCurrent(window);

	// load glad to config OpenGL
	gladLoadGL();

	glViewport(0, 0, 800, 800);
	
	
	
	// shader is opengl object by reference
	// open gl interger , positive interger 
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);

	GLuint fragmentShaderSource = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShaderSource, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShaderSource);
	
	
	
	// set background color
	glClearColor(0.07f, 0.13f, 0.17f, 1.0f); 

	// clean back buffer, and assign the new color to it
	glClear(GL_COLOR_BUFFER_BIT);

	// swap the back buffer with the front buffer
	glfwSwapBuffers(window);


	//open window
	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents(); // appearing, resizing
	}

	glfwDestroyWindow(window);

	glfwTerminate();
	return 0;
}
