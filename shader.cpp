#include <iostream>
#include <fstream>

#include "shader.h"

static void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage) {
	GLint success = 0;
	GLchar error[1024] = { 0 };
	if (isProgram) {
		glGetProgramiv(shader, flag, &success);
	}
	else {
		glGetShaderiv(shader, flag, &success);
	}
	if (success == GL_FALSE) {
		if (isProgram) {
			glGetProgramInfoLog(shader, sizeof(error), NULL, error);
		}
		else
		{
			glGetShaderInfoLog(shader, sizeof(error), NULL, error);
		}
		std::cerr << errorMessage << ":'" << error << "'" << std::endl;
	}
}

static std::string LoadShader(const std::string& filename) {
	std::ifstream file;
	file.open((filename).c_str());
	std::string output;
	std::string line;
	if (file.is_open()) {
		while (file.good()) {
			std::getline(file, line);
			output.append(line + "\n");
			std::cout << line << std::endl;
		}
	}
	else
	{
	std::cerr << "unable to load shader:" << filename << std::endl;
	}
	return output;
}

static GLuint CreateShader(const std::string& text, GLenum shaderType) {
	GLuint shader = glCreateShader(shaderType);
	if (shader) {
		std::cerr << "create shader error." << std::endl;

	}
	const GLchar* shaderSourceString[1];
	GLint shaderSourceStringLength[1];
	shaderSourceString[0] = text.c_str();
	shaderSourceStringLength[0] = text.length();
	glShaderSource(shader, 1, shaderSourceString, shaderSourceStringLength);
	glCompileShader(shader);
	CheckShaderError(shader, GL_COMPILE_STATUS, false, "error :compile error.");
	return shader;
}

Shader::Shader(const std::string& filename) {
	m_program = glCreateProgram();
	m_shaders[0]=CreateShader(LoadShader(filename + ".vs"),GL_VERTEX_SHADER);
	m_shaders[1]=CreateShader(LoadShader(filename + ".fs"),GL_FRAGMENT_SHADER);
	for (unsigned int i = 0; i < NUM_SHADERS; i++) {
		glAttachShader(m_program, m_shaders[i]);
	}
	glLinkProgram(m_program);
	CheckShaderError(m_program, GL_LINK_STATUS, true, "eroor: program linking error");
	glValidateProgram(m_program);
	CheckShaderError(m_program, GL_VALIDATE_STATUS, true, "eroor: program validate error");
}

Shader::~Shader() {
	for (unsigned int i = 0; i < NUM_SHADERS; i++) {
		glDetachShader(m_program, m_shaders[i]);
		glDeleteShader(m_shaders[i]);

	}
	glDeleteProgram(m_program);
}

void Shader::bind() {
	glUseProgram(m_program);
}