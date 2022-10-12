#pragma once
#include <gl/glew.h>
#include <string>

class Shader
{
public:
	Shader(const std::string & filename);
	~Shader();
	void bind();

private:
	static const unsigned int NUM_SHADERS = 2;
	GLuint m_program;
	GLuint m_shaders[NUM_SHADERS];
};