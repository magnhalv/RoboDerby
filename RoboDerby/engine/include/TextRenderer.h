#pragma once

#include <ft2build.h>
#include FT_FREETYPE_H  

#include "Shader.h"

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <string>
#include <map>
#include <iostream>

struct Character {
	GLuint     TextureID;  // ID handle of the glyph texture
	glm::ivec2 Size;       // Size of glyph
	glm::ivec2 Bearing;    // Offset from baseline to left/top of glyph
	GLuint     Advance;    // Offset to advance to next glyph
};

class TextRenderer {
public:
	TextRenderer(GLuint screenWidth, GLuint screenHeight);
	~TextRenderer();
	void init();
	void renderText(Shader &s, std::string text, GLfloat x, GLfloat y, GLfloat scale, glm::vec3 color);
private:
	std::map<GLchar, Character> characters_;
	GLuint VAO, VBO;
	glm::mat4 projection_;
};