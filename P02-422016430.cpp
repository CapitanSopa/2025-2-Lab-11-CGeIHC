//Práctica 2: índices, mesh, proyecciones, transformaciones geométricas
#include <stdio.h>
#include <string.h>
#include<cmath>
#include<vector>
#include <glew.h>
#include <glfw3.h>
//glm
#include<glm.hpp>
#include<gtc\matrix_transform.hpp>
#include<gtc\type_ptr.hpp>
//clases para dar orden y limpieza al código
#include"Mesh.h"
#include"Shader.h"
#include"Window.h"
//Dimensiones de la ventana
const float toRadians = 3.14159265f/180.0; //grados a radianes
Window mainWindow;
std::vector<Mesh*> meshList;
std::vector<MeshColor*> meshColorList;
std::vector<Shader>shaderList;
//Vertex Shader
static const char* vShader = "shaders/shader.vert";
static const char* fShader = "shaders/shader.frag";
static const char* vShaderColor = "shaders/shadercolor.vert";
static const char* fShaderColor = "shaders/shadercolor.frag";
static const char* vShaderrojo = "shaders/shaderrojo.vert";
static const char* fShaderrojo = "shaders/shaderrojo.frag";
static const char* vShaderMadera = "shaders/shadermadera.vert";
static const char* fShaderMadera = "shaders/shadermadera.frag";
static const char* vShaderHojas = "shaders/shaderhojas.vert";
static const char* fShaderHojas = "shaders/shaderhojas.frag";
static const char* vShaderVerde = "shaders/shaderverde.vert";
static const char* fShaderVerde = "shaders/shaderverde.frag";
static const char* vShaderAzul = "shaders/shaderazul.vert";
static const char* fShaderAzul = "shaders/shaderazul.frag";
//shaders nuevos se crearían acá

float angulo = 0.0f;

//color café en RGB : 0.478, 0.255, 0.067

//Pirámide triangular regular
void CreaPiramide()
{
	unsigned int indices[] = {
		0, 1, 4,  // front face
		1, 2, 4,  // right face
		2, 3, 4,  // back face
		3, 0, 4,  // left face
		0, 3, 1,  // bottom face part 1
		1, 3, 2   // bottom face part 2
	};

	GLfloat vertices[] = {
		-0.5f, -0.5f, 0.5f,  // 0: front-left corner
		0.5f, -0.5f, 0.5f,   // 1: front-right corner
		0.5f, -0.5f, -0.5f,  // 2: back-right corner
		-0.5f, -0.5f, -0.5f, // 3: back-left corner
		0.0f, 0.5f, 0.0f     // 4: apex
	};

	Mesh* obj1 = new Mesh();
	obj1->CreateMesh(vertices, indices, 15, 18);
	meshList.push_back(obj1);
}

//Vértices de un cubo
void CrearCubo()
{
	unsigned int cubo_indices[] = {
		// front
		0, 1, 2,
		2, 3, 0,
		// right
		1, 5, 6,
		6, 2, 1,
		// back
		7, 6, 5,
		5, 4, 7,
		// left
		4, 0, 3,
		3, 7, 4,
		// bottom
		4, 5, 1,
		1, 0, 4,
		// top
		3, 2, 6,
		6, 7, 3
	};

GLfloat cubo_vertices[] = {
	// front
	-0.5f, -0.5f,  0.5f,
	0.5f, -0.5f,  0.5f,
	0.5f,  0.5f,  0.5f,
	-0.5f,  0.5f,  0.5f,
	// back
	-0.5f, -0.5f, -0.5f,
	0.5f, -0.5f, -0.5f,
	0.5f,  0.5f, -0.5f,
	-0.5f,  0.5f, -0.5f
};
Mesh *cubo = new Mesh();
cubo->CreateMesh(cubo_vertices, cubo_indices,24, 36);
meshList.push_back(cubo);
}

void CrearLetrasyFiguras()
{
	// Letra S
	GLfloat vertices_S[] = {
		//X         Y           Z           R       G       B
		-0.4f,      0.65f,      0.0f,       0.0f,   0.0f,   1.0f,
		-0.4f,      0.55f,      0.0f,       0.0f,   0.0f,   1.0f,
		-0.3f,      0.55f,      0.0f,       0.0f,   0.0f,   1.0f,

		-0.4f,      0.65f,      0.0f,       0.0f,   0.0f,   1.0f,
		-0.4f,      0.55f,      0.0f,       0.0f,   0.0f,   1.0f,
		-0.7f,      0.55f,      0.0f,       0.0f,   0.0f,   1.0f,

		-0.7f,      0.65f,      0.0f,       0.0f,   0.0f,   1.0f,
		-0.4f,      0.65f,      0.0f,       0.0f,   0.0f,   1.0f,
		-0.7f,      0.55f,      0.0f,       0.0f,   0.0f,   1.0f,

		-0.7f,      0.65f,      0.0f,       0.0f,   0.0f,   1.0f,
		-0.8f,      0.55f,      0.0f,       0.0f,   0.0f,   1.0f,
		-0.7f,      0.55f,      0.0f,       0.0f,   0.0f,   1.0f,

		-0.7f,      0.40f,      0.0f,       0.0f,   0.0f,   1.0f,
		-0.8f,      0.55f,      0.0f,       0.0f,   0.0f,   1.0f,
		-0.7f,      0.55f,      0.0f,       0.0f,   0.0f,   1.0f,

		-0.7f,      0.40f,      0.0f,       0.0f,   0.0f,   1.0f,
		-0.8f,      0.55f,      0.0f,       0.0f,   0.0f,   1.0f,
		-0.8f,      0.40f,      0.0f,       0.0f,   0.0f,   1.0f,

		-0.7f,      0.40f,      0.0f,       0.0f,   0.0f,   1.0f,
		-0.7f,      0.30f,      0.0f,       0.0f,   0.0f,   1.0f,
		-0.8f,      0.40f,      0.0f,       0.0f,   0.0f,   1.0f,

		-0.7f,      0.40f,      0.0f,       0.0f,   0.0f,   1.0f,
		-0.7f,      0.30f,      0.0f,       0.0f,   0.0f,   1.0f,
		-0.4f,      0.40f,      0.0f,       0.0f,   0.0f,   1.0f,

		-0.4f,      0.30f,      0.0f,       0.0f,   0.0f,   1.0f,
		-0.7f,      0.30f,      0.0f,       0.0f,   0.0f,   1.0f,
		-0.4f,      0.40f,      0.0f,       0.0f,   0.0f,   1.0f,

		-0.4f,      0.30f,      0.0f,       0.0f,   0.0f,   1.0f,
		-0.3f,      0.30f,      0.0f,       0.0f,   0.0f,   1.0f,
		-0.4f,      0.40f,      0.0f,       0.0f,   0.0f,   1.0f,

		-0.4f,      -0.05f,     0.0f,       0.0f,   0.0f,   1.0f,
		-0.3f,      0.30f,      0.0f,       0.0f,   0.0f,   1.0f,
		-0.4f,      0.40f,      0.0f,       0.0f,   0.0f,   1.0f,

		-0.4f,      -0.05f,     0.0f,       0.0f,   0.0f,   1.0f,
		-0.3f,      0.30f,      0.0f,       0.0f,   0.0f,   1.0f,
		-0.3f,      -0.05f,     0.0f,       0.0f,   0.0f,   1.0f,

		-0.4f,      -0.05f,     0.0f,       0.0f,   0.0f,   1.0f,
		-0.4f,      -0.15f,     0.0f,       0.0f,   0.0f,   1.0f,
		-0.3f,      -0.05f,     0.0f,       0.0f,   0.0f,   1.0f,

		-0.4f,      -0.05f,     0.0f,       0.0f,   0.0f,   1.0f,
		-0.4f,      -0.15f,     0.0f,       0.0f,   0.0f,   1.0f,
		-0.7f,      -0.05f,     0.0f,       0.0f,   0.0f,   1.0f,

		-0.7f,      -0.15f,     0.0f,       0.0f,   0.0f,   1.0f,
		-0.4f,      -0.15f,     0.0f,       0.0f,   0.0f,   1.0f,
		-0.7f,      -0.05f,     0.0f,       0.0f,   0.0f,   1.0f,

		-0.7f,      -0.15f,     0.0f,       0.0f,   0.0f,   1.0f,
		-0.8f,      -0.15f,     0.0f,       0.0f,   0.0f,   1.0f,
		-0.7f,      -0.05f,     0.0f,       0.0f,   0.0f,   1.0f,

	};
	MeshColor* letraS = new MeshColor();
	letraS->CreateMeshColor(vertices_S, 288);
	meshColorList.push_back(letraS);

	// Letra G
	GLfloat vertices_G[] = {
		//X         Y           Z           R       G       B
		0.35f,      0.55f,      0.0f,       1.0f,   0.0f,   0.0f,
		0.25f,      0.55f,      0.0f,       1.0f,   0.0f,   0.0f,
		0.25f,      0.35f,      0.0f,       1.0f,   0.0f,   0.0f,

		0.35f,      0.55f,      0.0f,       1.0f,   0.0f,   0.0f,
		0.35f,      0.35f,      0.0f,       1.0f,   0.0f,   0.0f,
		0.25f,      0.35f,      0.0f,       1.0f,   0.0f,   0.0f,

		0.35f,      0.55f,      0.0f,       1.0f,   0.0f,   0.0f,
		0.25f,      0.55f,      0.0f,       1.0f,   0.0f,   0.0f,
		0.25f,      0.65f,      0.0f,       1.0f,   0.0f,   0.0f,

		-0.05f,     0.55f,      0.0f,       1.0f,   0.0f,   0.0f,
		0.25f,      0.55f,      0.0f,       1.0f,   0.0f,   0.0f,
		0.25f,      0.65f,      0.0f,       1.0f,   0.0f,   0.0f,

		-0.05f,     0.55f,      0.0f,       1.0f,   0.0f,   0.0f,
		-0.05f,     0.65f,      0.0f,       1.0f,   0.0f,   0.0f,
		0.25f,      0.65f,      0.0f,       1.0f,   0.0f,   0.0f,

		-0.05f,     0.55f,      0.0f,       1.0f,   0.0f,   0.0f,
		-0.05f,     0.65f,      0.0f,       1.0f,   0.0f,   0.0f,
		-0.15f,     0.55f,      0.0f,       1.0f,   0.0f,   0.0f,

		-0.05f,     0.55f,      0.0f,       1.0f,   0.0f,   0.0f,
		-0.05f,     -0.05f,     0.0f,       1.0f,   0.0f,   0.0f,
		-0.15f,     0.55f,      0.0f,       1.0f,   0.0f,   0.0f,

		-0.05f,     0.55f,      0.0f,       1.0f,   0.0f,   0.0f,
		-0.05f,     -0.05f,     0.0f,       1.0f,   0.0f,   0.0f,
		-0.15f,     0.55f,      0.0f,       1.0f,   0.0f,   0.0f,

		-0.15f,     -0.05f,     0.0f,       1.0f,   0.0f,   0.0f,
		-0.05f,     -0.05f,     0.0f,       1.0f,   0.0f,   0.0f,
		-0.15f,     0.55f,      0.0f,       1.0f,   0.0f,   0.0f,

		-0.15f,     -0.05f,     0.0f,       1.0f,   0.0f,   0.0f,
		-0.05f,     -0.05f,     0.0f,       1.0f,   0.0f,   0.0f,
		-0.05f,     -0.15f,     0.0f,       1.0f,   0.0f,   0.0f,

		0.20f,      -0.05f,     0.0f,       1.0f,   0.0f,   0.0f,
		-0.05f,     -0.05f,     0.0f,       1.0f,   0.0f,   0.0f,
		-0.05f,     -0.15f,     0.0f,       1.0f,   0.0f,   0.0f,

		0.20f,      -0.05f,     0.0f,       1.0f,   0.0f,   0.0f,
		0.20f,      -0.15f,     0.0f,       1.0f,   0.0f,   0.0f,
		-0.05f,     -0.15f,     0.0f,       1.0f,   0.0f,   0.0f,

		0.20f,      -0.05f,     0.0f,       1.0f,   0.0f,   0.0f,
		0.20f,      -0.15f,     0.0f,       1.0f,   0.0f,   0.0f,
		0.30f,      -0.05f,     0.0f,       1.0f,   0.0f,   0.0f,

		0.25f,      -0.2f,      0.0f,       1.0f,   0.0f,   0.0f,
		0.35f,      -0.2f,      0.0f,       1.0f,   0.0f,   0.0f,
		0.25f,      0.15f,      0.0f,       1.0f,   0.0f,   0.0f,

		0.35f,      0.15f,      0.0f,       1.0f,   0.0f,   0.0f,
		0.35f,      -0.2f,      0.0f,       1.0f,   0.0f,   0.0f,
		0.25f,      0.15f,      0.0f,       1.0f,   0.0f,   0.0f,

		0.05f,      0.15f,      0.0f,       1.0f,   0.0f,   0.0f,
		0.25f,      0.05f,      0.0f,       1.0f,   0.0f,   0.0f,
		0.25f,      0.15f,      0.0f,       1.0f,   0.0f,   0.0f,

		0.05f,      0.15f,      0.0f,       1.0f,   0.0f,   0.0f,
		0.25f,      0.05f,      0.0f,       1.0f,   0.0f,   0.0f,
		0.05f,      0.05f,      0.0f,       1.0f,   0.0f,   0.0f,
	};
	MeshColor* letraG = new MeshColor();
	letraG->CreateMeshColor(vertices_G, 306);
	meshColorList.push_back(letraG);

	// Letra L
	GLfloat vertices_L[] = {
		//X         Y           Z           R       G       B
		0.45f,      -0.15f,     0.0f,       0.0f,   1.0f,   0.0f,
		0.45f,      0.65f,      0.0f,       0.0f,   1.0f,   0.0f,
		0.55f,      0.65f,      0.0f,       0.0f,   1.0f,   0.0f,

		0.45f,      -0.15f,     0.0f,       0.0f,   1.0f,   0.0f,
		0.55f,      -0.15f,     0.0f,       0.0f,   1.0f,   0.0f,
		0.55f,      0.65f,      0.0f,       0.0f,   1.0f,   0.0f,

		0.85f,      -0.15f,     0.0f,       0.0f,   1.0f,   0.0f,
		0.85f,      -0.05f,     0.0f,       0.0f,   1.0f,   0.0f,
		0.55f,      -0.15f,     0.0f,       0.0f,   1.0f,   0.0f,

		0.55f,      -0.05f,     0.0f,       0.0f,   1.0f,   0.0f,
		0.85f,      -0.05f,     0.0f,       0.0f,   1.0f,   0.0f,
		0.55f,      -0.15f,     0.0f,       0.0f,   1.0f,   0.0f,
	};
	MeshColor* letraL = new MeshColor();
	letraL->CreateMeshColor(vertices_L, 72);
	meshColorList.push_back(letraL);

}


void CreateShaders()
{

	Shader *shader1 = new Shader(); //shader para usar índices: objetos: cubo y  pirámide
	shader1->CreateFromFiles(vShader, fShader);
	shaderList.push_back(*shader1);

	Shader *shader2 = new Shader();//shader para usar color como parte del VAO: letras 
	shader2->CreateFromFiles(vShaderColor, fShaderColor);
	shaderList.push_back(*shader2);

	Shader *shaderRojo = new Shader();//Shader color rojo
	shaderRojo->CreateFromFiles(vShaderrojo, fShaderrojo);
	shaderList.push_back(*shaderRojo);

	Shader* shaderMadera = new Shader();//Shader Madera
	shaderMadera->CreateFromFiles(vShaderMadera, fShaderMadera);
	shaderList.push_back(*shaderMadera);

	Shader* shaderHojas = new Shader();//Shader Hojas
	shaderHojas->CreateFromFiles(vShaderHojas, fShaderHojas);
	shaderList.push_back(*shaderHojas);

	Shader* shaderVerde = new Shader();//Shader Verde
	shaderVerde->CreateFromFiles(vShaderVerde, fShaderVerde);
	shaderList.push_back(*shaderVerde);

	Shader* shaderAzul = new Shader();//Shader Azul
	shaderAzul->CreateFromFiles(vShaderAzul, fShaderAzul);
	shaderList.push_back(*shaderAzul);
}


int main()
{
	mainWindow = Window(800, 600);
	mainWindow.Initialise();
	CreaPiramide(); //índice 0 en MeshList
	CrearCubo();//índice 1 en MeshList
	CrearLetrasyFiguras(); //usa MeshColor, índices en MeshColorList
	CreateShaders();
	GLuint uniformProjection = 0;
	GLuint uniformModel = 0;

	
	//Projection: Matriz de Dimensión 4x4 para indicar si vemos en 2D( orthogonal) o en 3D) perspectiva
	glm::mat4 projection = glm::ortho(-1.0f, 1.0f, -1.0f, 1.0f, 0.1f, 100.0f);
	//glm::mat4 projection = glm::perspective(glm::radians(60.0f)	,mainWindow.getBufferWidth() / mainWindow.getBufferHeight(), 0.1f, 100.0f);
	
	//Model: Matriz de Dimensión 4x4 en la cual se almacena la multiplicación de las transformaciones geométricas.
	glm::mat4 model(1.0); //fuera del while se usa para inicializar la matriz con una identidad
	
	//Loop mientras no se cierra la ventana
	while (!mainWindow.getShouldClose())
	{
		//Recibir eventos del usuario
		glfwPollEvents();
		//Limpiar la ventana
		glClearColor(0.0f,0.0f,0.0f,0.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //Se agrega limpiar el buffer de profundidad
		

		//Para las letras hay que usar el segundo set de shaders con índice 1 en ShaderList 
		shaderList[1].useShader();
		uniformModel = shaderList[1].getModelLocation();
		uniformProjection = shaderList[1].getProjectLocation();
		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));


		// S
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(0.0f, 0.6f, -2.0f));
		model = glm::scale(model, glm::vec3(0.5f, 0.5f, 1.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		meshColorList[0]->RenderMeshColor();

		// G
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(0.0f, 0.6f, -2.0f));
		model = glm::scale(model, glm::vec3(0.5f, 0.5f, 1.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		meshColorList[1]->RenderMeshColor();

		// L
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(0.0f, 0.6f, -2.0f));
		model = glm::scale(model, glm::vec3(0.5f, 0.5f, 1.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		meshColorList[2]->RenderMeshColor();

		//Shader Azul
		shaderList[6].useShader();
		uniformModel = shaderList[6].getModelLocation();
		uniformProjection = shaderList[6].getProjectLocation();

		//Piramide (TECHO)
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(0.0f, 0.25f, -3.0f));
		model = glm::scale(model, glm::vec3(1.0f, 0.5f, 1.0f));
		//model = glm::rotate(model, 45 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));//FALSE ES PARA QUE NO SEA TRANSPUESTA
		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		meshList[0]->RenderMesh();

		//Shader Rojo
		shaderList[2].useShader();
		uniformModel = shaderList[2].getModelLocation();
		uniformProjection = shaderList[2].getProjectLocation();

		//Cubo (CASA)
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(0.0f, -0.50f, -3.0f));
		model = glm::scale(model, glm::vec3(0.8f, 1.0f, 1.0f));
		//model = glm::rotate(model, 45 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));//FALSE ES PARA QUE NO SEA TRANSPUESTA
		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		meshList[1]->RenderMesh();

		//Shader Ventana y Puerta
		shaderList[5].useShader();
		uniformModel = shaderList[5].getModelLocation();
		uniformProjection = shaderList[5].getProjectLocation();

		//Cubo (Ventana 1 )
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-0.2f, -0.3f, -1.9f));
		model = glm::scale(model, glm::vec3(0.3f, 0.3f, 1.0f));
		//model = glm::rotate(model, 45 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		meshList[1]->RenderMesh();

		//Cubo (Ventana 2 )
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(0.2f, -0.3f, -1.9f));
		model = glm::scale(model, glm::vec3(0.3f, 0.3f, 1.0f));
		//model = glm::rotate(model, 45 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		meshList[1]->RenderMesh();

		//Cubo (Puerta )
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(0.0f, -0.9f, -1.9f));
		model = glm::scale(model, glm::vec3(0.3f, 0.7f, 1.0f));
		//model = glm::rotate(model, 45 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		meshList[1]->RenderMesh();

		// Shader café
		shaderList[3].useShader();
		uniformModel = shaderList[3].getModelLocation();
		uniformProjection = shaderList[3].getProjectLocation();
		
		//Tronco 1
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-0.7f, -0.9f, -1.5f));
		model = glm::scale(model, glm::vec3(0.20f, 0.20f, 1.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		meshList[1]->RenderMesh();

		//Tronco 2
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(0.7f, -0.9f, -1.5f));
		model = glm::scale(model, glm::vec3(0.2f, 0.2f, 1.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));

		meshList[1]->RenderMesh();

		// Shader hojas
		shaderList[4].useShader();
		uniformModel = shaderList[4].getModelLocation();
		uniformProjection = shaderList[4].getProjectLocation();
		 
		// Copa verde 1 
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-0.7f, -0.1f, -2.0f));
		model = glm::scale(model, glm::vec3(0.5f, 1.4f, 1.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		meshList[0]->RenderMesh();

		// Copa verde 2 
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(0.7f, -0.1f, -2.0f));
		model = glm::scale(model, glm::vec3(0.5f, 1.4f, 1.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		meshList[0]->RenderMesh();


		glUseProgram(0);
		mainWindow.swapBuffers();

	}
	return 0;
}



// inicializar matriz: glm::mat4 model(1.0);
// reestablecer matriz: model = glm::mat4(1.0);
//Traslación
//model = glm::translate(model, glm::vec3(0.0f, 0.0f, -5.0f));
//////////////// ROTACIÓN //////////////////
//model = glm::rotate(model, 45 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
////////////////  ESCALA ////////////////
//model = glm::scale(model, glm::vec3(0.5f, 0.5f, 0.5f));
///////////////////// T+R////////////////
/*model = glm::translate(model, glm::vec3(valor, 0.0f, 0.0f));
model = glm::rotate(model, 45 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
model = glm::rotate(model, glm::radians(angulo), glm::vec3(0.0f, 1.0f, 0.0f));
*/
/////////////R+T//////////
/*model = glm::rotate(model, 45 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
model = glm::translate(model, glm::vec3(valor, 0.0f, 0.0f));
*/