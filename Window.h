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
	GLfloat getXChange();
	GLfloat getYChange();
	GLfloat getmuevex() { return muevex; }
	GLfloat getangulocola() { return angulocola; }
	bool getShouldClose() {
		return  glfwWindowShouldClose(mainWindow);}
	bool* getsKeys() { return keys; }
	void swapBuffers() { return glfwSwapBuffers(mainWindow); }
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
	bool keys[1024];
	GLint bufferWidth, bufferHeight;
	void createCallbacks();
	GLfloat lastX;
	GLfloat lastY;
	GLfloat xChange;
	GLfloat yChange;
	GLfloat muevex, wheelsRotation;
	GLfloat wheel1Rotation, wheel2Rotation, wheel3Rotation, wheel4Rotation, cofre = 0.0;

	GLfloat angulocola=0.0f;
	bool mouseFirstMoved;
	static void ManejaTeclado(GLFWwindow* window, int key, int code, int action, int mode);
	static void ManejaMouse(GLFWwindow* window, double xPos, double yPos);

};

