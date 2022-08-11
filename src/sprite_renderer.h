#ifndef SPRITE_RENDERER_H
#define SPRITE_RENDERER_H

#include <glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "shader.h"
#include "texture.h"


class SpriteRenderer {
public:
	SpriteRenderer(const Shader &shader);
	~SpriteRenderer();

	void DrawSprite(const Texture2D &texture, glm::vec2 position,
		glm::vec2 size = glm::vec2(10, 10), GLfloat rotate = 0.0f,
		glm::vec3 color = glm::vec3(1.0));
private:
	Shader shader;
	GLuint quadVAO;
	void initRenderData();
};

#endif