#pragma once
#include <glm/glm.hpp>
#include <GL/glew.h>

class Vertex
{
public:
	Vertex(const glm::vec3& pos):pos_(pos) {
		//this->pos_=pos;
	}
	//~Vertex();
	
private:
	glm::vec3 pos_;
};

class Mesh {
public:
	Mesh(Vertex* vertices, unsigned int numVertices) ;
	~Mesh();
	void draw();
	enum 
	{
		POSITION_VB,
		NUM_BUFFERS
	};
	GLuint m_vertexArrayObject;
	GLuint m_vertexArrayBuffers[NUM_BUFFERS];
	unsigned int m_drawCount;
};