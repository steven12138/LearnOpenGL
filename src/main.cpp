#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <cmath>

#define STB_IMAGE_IMPLEMENTATION

#include "shader/shader.hpp"
#include "texture/texture2D.hpp"

auto ResizeListener(GLFWwindow *window, int width, int height) -> void;

auto ProcessInput(GLFWwindow *window) -> void;

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


auto operator<<(std::ostream &os, const glm::vec4 &b) -> std::ostream & {
    os << "vec2: {x: " << b.x << ", y: " << b.y << ", z: " << b.z << ", w: " << b.w << "}";
    return os;
}

auto main() -> int {

    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    GLFWwindow *window = glfwCreateWindow(800, 600, "Hello OpenGL", nullptr, nullptr);
    if (window == nullptr) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        std::cerr << &glfwGetProcAddress << std::endl;
        std::cerr << "Failed to initialize GLAD" << std::endl;
        return -1;
    }
    glViewport(0, 0, 800, 600);
    glfwSetFramebufferSizeCallback(window, ResizeListener);


    int nrAttributes;
    glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &nrAttributes);
    std::cout << "maximum nr of vertex attributes supported: " << nrAttributes << std::endl;
    // output 16

    const char *vPath = STATIC_FILE_PATH"/static/shader/vertexShader.vert";
    const char *fPath = STATIC_FILE_PATH"/static/shader/fragmentShader.frag";

//    shader::ShaderProgram shaderChain(vPath, fPath);
    shader::Shader vertexShader(vPath, GL_VERTEX_SHADER);
    shader::Shader fragmentShader(fPath, GL_FRAGMENT_SHADER);
    shader::ShaderProgram shaderChain{};
    shaderChain
            .add(std::move(vertexShader))
            .add(std::move(fragmentShader))
            .load();

    float vertices[] = {
            // positions                     // colors                         // texture coords
            0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, // top right
            0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f, // bottom right
            -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, // bottom left
            -0.5f, 0.5f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f  // top left
    };

    unsigned int indices[] = {
            0, 1, 3,
            1, 2, 3
    };

    unsigned int VAO, VBO, EBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *) 0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *) (3 * sizeof(float)));
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *) (6 * sizeof(float)));

    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glEnableVertexAttribArray(2);

    texture::texture2DLoader wallTexture;
    wallTexture
            .addTexture(STATIC_FILE_PATH"/static/texture2D/face.png",
                        GL_TEXTURE1, GL_RGBA)
            .addTexture(STATIC_FILE_PATH"/static/texture2D/container.jpg",
                        GL_TEXTURE0);

    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);


    shaderChain.use();

    glUniform1i(glGetUniformLocation(shaderChain.getProgram(), "texture1"), 0);
    // or set it via the texture class
    shaderChain.set("texture2", (int) 1);

//    shaderChain.set("texture1", 0);
//    shaderChain.set("texture2", 1);



    while (!glfwWindowShouldClose(window)) {
        //处理输入事件
        ProcessInput(window);


        //设置颜色&清除缓冲
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glActiveTexture(GL_TEXTURE0);

        wallTexture.use();

        glm::mat4 transform = glm::mat4(1.0f);
        glBindVertexArray(VAO);

        transform = glm::mat4(1.0f);
        transform = glm::translate(transform, glm::vec3(0.5f, -0.5f, 0.0f));
        auto scaleAmount = static_cast<float>(sin(glfwGetTime() * 2));
        transform = glm::scale(transform, glm::vec3(scaleAmount, scaleAmount, scaleAmount));
        shaderChain.setTrans("transform", transform);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);


        transform = glm::mat4(1.0f);
        transform = glm::translate(transform, glm::vec3(-0.5f, -0.5f, 0.0f));
        scaleAmount = static_cast<float>(sin(glfwGetTime() * 2));
        transform = glm::scale(transform, glm::vec3(scaleAmount, scaleAmount, scaleAmount));
        shaderChain.setTrans("transform", transform);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        //检查调取事件，并交换缓冲
        glfwSwapBuffers(window);
        glfwPollEvents();
    }


    glfwTerminate();
    return 0;
}

auto ResizeListener(GLFWwindow *window, int width, int height) -> void {
    glViewport(0, 0, width, height);
}

auto ProcessInput(GLFWwindow *window) -> void {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }
}