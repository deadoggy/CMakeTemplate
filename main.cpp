#include<iostream>
#include<adder.h>
#include<GLFW/glfw3.h>
#include<SPOONConfig.h>

int main(int argc, char* argv[]){
    std::cout << "Hey, Yinjia!" << std::endl;
    std::cout << adder(13.0f, 13.0f) << std::endl;
    std::cout << argv[0] << " Version "<< SPOON_VERSION_MAJOR 
              << "." << SPOON_VERSION_MINOR << '\n';

    GLFWwindow* window;
    int width, height;

    if( !glfwInit() )
    {
        fprintf( stderr, "Failed to initialize GLFW\n" );
        exit( EXIT_FAILURE );
    }

    glfwWindowHint(GLFW_DEPTH_BITS, 16);
    glfwWindowHint(GLFW_TRANSPARENT_FRAMEBUFFER, GLFW_TRUE);

    window = glfwCreateWindow( 300, 300, "Gears", NULL, NULL );
    if (!window)
    {
        fprintf( stderr, "Failed to open GLFW window\n" );
        glfwTerminate();
        exit( EXIT_FAILURE );
    }


    // Main loop
    while( !glfwWindowShouldClose(window) )
    {
        // Draw gears
        // draw();

        // Update animation
        // animate();

        // Swap buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Terminate GLFW
    glfwTerminate();



    return 0;
}
