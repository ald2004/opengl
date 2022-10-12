#pragma once
#include <string>
#include <SDL.h>

class Display {
public:
	Display(int w, int h, const std::string& title);
	Display();
	~Display();
	void Update();
	bool IsClosed();
private:
	SDL_Window* m_window;
	SDL_GLContext m_gl;
	SDL_GLContext m_glContext;
	bool m_isClosed=false;
};

