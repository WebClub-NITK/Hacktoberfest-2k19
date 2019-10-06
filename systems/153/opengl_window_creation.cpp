#include <iostream>
#include <GLFW/glfw3.h>

//Allows to print erros to console
static void glfwError(int id, const char* description)
{
  std::cout << description << std::endl;
}

int main()
{
    GLFWwindow* window;

    glfwSetErrorCallback(&glfwError);

    // Initialize GLFW library
    if (!glfwInit())
        return -1;

    // Set window as resizable
    glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);

    // Create the window
    window = glfwCreateWindow(1920, 1080, "Hacktoberfest 2k19", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);

    // Wait for window to be closed
    while (!glfwWindowShouldClose(window))
    {
        //Render here
        glClear(GL_COLOR_BUFFER_BIT);
        // Set window color
        glClearColor(1, (GLfloat)165/255, 0, 1);

        // Swap front and back buffers (Show drawing)
        glfwSwapBuffers(window);

        //Poll for and process events
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
