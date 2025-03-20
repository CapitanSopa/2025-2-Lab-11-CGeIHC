#pragma once
#include<stdio.h>
#include<glew.h>
#include<glfw3.h>

class Window
{
public:
	Window();
	Window(GLint windowWidth, GLint windowHeight);
	int Initialise();
	GLfloat getBufferWidth() { return bufferWidth; }
	GLfloat getBufferHeight() { return bufferHeight; }
	bool getShouldClose() {
		return  glfwWindowShouldClose(mainWindow);}
	bool* getsKeys() { return keys; }
	GLfloat getXChange();
	GLfloat getYChange();
	void swapBuffers() { return glfwSwapBuffers(mainWindow); }
	GLfloat getrotay() { return rotay; }
	GLfloat getrotax() { return rotax; }
	GLfloat getrotaz() { return rotaz; }

	

	// Llantas
	GLfloat getWheelsRotation() { return wheelsRotation; }
	GLfloat getWheel1Rotation() { return wheel1Rotation; }
	GLfloat getWheel2Rotation() { return wheel2Rotation; }
	GLfloat getWheel3Rotation() { return wheel3Rotation; }
	GLfloat getWheel4Rotation() { return wheel4Rotation; }
	GLfloat getCofreRotation() { return cofre; }




	~Window();
private: 
	GLFWwindow *mainWindow;
	GLint width, height;
	GLfloat rotax,rotay,rotaz,wheel1Rotation, wheel2Rotation, wheel3Rotation, wheel4Rotation, wheelsRotation, cofre;




	bool keys[1024];
	GLint bufferWidth, bufferHeight;
	GLfloat lastX;
	GLfloat lastY;
	GLfloat xChange;
	GLfloat yChange;
	bool mouseFirstMoved;
	void createCallbacks();
	static void ManejaTeclado(GLFWwindow* window, int key, int code, int action, int mode);
	static void ManejaMouse(GLFWwindow* window, double xPos, double yPos);
};

