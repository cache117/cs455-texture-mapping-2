#include <iostream>
#include <GL/glew.h>
#include "display.h"
#include "mesh.h"
#include "shader.h"
#include "texture.h"
#include "transform.h"
#include "camera.h"

#define WIDTH 800
#define HEIGHT 600

int main(int charc, char** argv)
{
	Display display(WIDTH, HEIGHT, "Hello World");

	Vertex vertices[] = { Vertex(glm::vec3(-0.5, -0.5, 0), glm::vec2(0, 0)),
							Vertex(glm::vec3(0, 0.5, 0), glm::vec2(0.5, 1.0)),
							Vertex(glm::vec3(0.5, -0.5 ,0), glm::vec2(1.0, 0)) };

	unsigned int indices[] = { 0, 1, 2 };

	//Mesh mesh(vertices, sizeof(vertices) / sizeof(vertices[0]), indices, sizeof(indices)/sizeof(indices[0]));
	//Mesh mesh("./res/monkey3.obj");
	//Mesh mesh("./res/crayon.obj");
	Mesh mesh("./res/crayonBox.obj");
	Shader shader("./res/basicShader");
	//Texture texture("./res/bricks.jpg");
	//Texture texture("./res/violetCrayon.png");
	Texture texture("./res/CrayonBox2.png");
	Camera camera(glm::vec3(0, 0, -3), 70.0f, (float)WIDTH / (float)HEIGHT, 0.01f, 1000.0f);
	Transform transform;

	float counter = 0.0f;

	while (!display.isClosed())
	{
		float sinCounter = sinf(counter);
		float cosCounter = cosf(counter);

		transform.position.x = sinCounter;
		//transform.position.z = cosCounter;
		//transform.rotation.z = counter;
		transform.rotation.y = counter;
		//transform.scale = glm::vec3(cosCounter, cosCounter, cosCounter);

		display.Clear(0.0f, 0.15f, 0.3f, 1.0f);

		shader.Bind();
		texture.Bind(0);
		shader.Update(transform, camera);
		mesh.Draw();

		display.Update();
		counter += 0.001f;
	}
	return 0;
}