#include "core/particles.h"
#include "renderer/window.h"
#include <chrono>

int main() {
  Window window = Window();


  while (!glfwWindowShouldClose(window.window)) {

  }

  glfwDestroyWindow(window.window);

  
  return 0;
}
