#pragma once

#include <cstdint>
extern "C" {  
  #include <glad/glad.h>
}
#include <GLFW/glfw3.h>

constexpr uint32_t DEFAULT_WIDTH = 2400;
constexpr uint32_t DEFAULT_HEIGHT = 1200;

struct Window {
  GLFWwindow *window;
  uint32_t width;
  uint32_t height;

  Window();
  void resize(uint32_t new_width, uint32_t new_height);
  float aspect_ratio();
};
