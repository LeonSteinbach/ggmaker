#include <GLFW/glfw3.h>
#include <iostream>

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#include "ggmaker.h"

class Sandbox : public gg::Application
{
public:
	Sandbox(const char* title, int width, int height) : Application(title, width, height)
	{
	}

	~Sandbox() override
	{
	}

	void run() override
	{
		Application::run();
	}

	void init() override
	{
		Application::init();
	}

	void update(short elapsedMilliseconds) override
	{
		Application::update(elapsedMilliseconds);
	}

	void render() override
	{
		Application::render();
	}
};

int main()
{
	/*
	GLFWwindow* window;

	if (!glfwInit())
		return -1;

	window = glfwCreateWindow(640, 480, "Title", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	ImGui::StyleColorsDark();
	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init("#version 330");

	bool checked = true;

	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);

		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();

		ImGui::Begin("Title");
		ImGui::Text("Text");
		ImGui::Checkbox("Checkbox", &checked);
		ImGui::End();

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		glfwSwapBuffers(window);

		glfwPollEvents();
	}

	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();

	glfwTerminate();
	*/

	// Application
	const auto app = new Sandbox("ggmaker", 1280, 720);
	app->run();

	delete app;

	std::cin.get();

	return 0;
}
