#include <iostream>
#include <GL/glew.h>
#include "Display.h"
#include "mesh.h"
#include "shader.h"

int main(int a, char** b) {
	Display display(800, 600, "h gl");
	Vertex  v[] = {
		Vertex(glm::vec3(-0.5,-0.5,0)),
		Vertex(glm::vec3(0,0.5,0)),
		Vertex(glm::vec3(0.5,-0.5,0))
	};
	Mesh mesh(v, sizeof(v )/ sizeof(v[0]));
	//Shader shader("C://Users//yuanp//source//repos//openGL//x64//Debug//basicShader");
	Shader shader("./basicShader");
	while (!display.IsClosed()) {
		glClearColor(0.0f, 0.15f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		shader.bind();
		mesh.draw();
		display.Update();
	}
	std::cout << "h gl" << std::endl;
	return 0;
}