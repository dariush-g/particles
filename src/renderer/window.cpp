#include "window.h"
#include <iostream>

Window::Window() {
  if (!glfwInit()) {
    std::cerr << "Failed to initialize GLFW" << std::endl;
    window = nullptr;
  }

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  window =
      glfwCreateWindow(DEFAULT_WIDTH, DEFAULT_HEIGHT, "spes", nullptr, nullptr);
  if (!window) {
    std::cerr << "Failed to create GLFW window" << std::endl;
    glfwTerminate();
    window = nullptr;
  }

  glfwMakeContextCurrent(window);

  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    std::cerr << "Failed to initialize GLAD" << std::endl;
    glfwDestroyWindow(window);
    glfwTerminate();
    window = nullptr;
  }

  glViewport(0, 0, DEFAULT_WIDTH, DEFAULT_HEIGHT);

  width = DEFAULT_WIDTH;
  height = DEFAULT_HEIGHT;
}

float Window::aspect_ratio() {
  return (float)width / (float)height;
}

void Window::resize(uint32_t new_width, uint32_t new_height) {
  glfwSetWindowSize(window, new_width, new_height);
  width = new_width;
  height = new_height;
}
