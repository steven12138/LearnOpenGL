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

int screenHeight = 600, screenWidth = 800;

auto getModel() -> glm::mat4 {
    glm::mat4 model{1};
    return glm::rotate(model, glm::radians(-55.0f), glm::vec3{1, 0, 0});
}

glm::vec3 pos{0, 0, -3};
glm::vec2 cam{0, 0};

auto getView() -> glm::mat4 {
    glm::mat4 view{1};
    view = glm::rotate(view, cam.x,
                       glm::vec3{1, 0, 0});
    view = glm::rotate(view, cam.y,
                       glm::vec3{0, 1, 0});

    view = glm::translate(view, pos);
    return view;
}

auto getProjection() -> glm::mat4 {
    glm::mat4 projection{1};
    projection = glm::perspective(glm::radians(45.0f), (float) screenWidth / (float) screenHeight, 0.1f, 100.0f);
    return projection;
}

auto main() -> int {

    auto &&projection = getProjection();


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
            -0.5f, -0.5f, -0.5f, 0.0f, 0.0f,
            0.5f, -0.5f, -0.5f, 1.0f, 0.0f,
            0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
            0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
            -0.5f, 0.5f, -0.5f, 0.0f, 1.0f,
            -0.5f, -0.5f, -0.5f, 0.0f, 0.0f,

            -0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
            0.5f, -0.5f, 0.5f, 1.0f, 0.0f,
            0.5f, 0.5f, 0.5f, 1.0f, 1.0f,
            0.5f, 0.5f, 0.5f, 1.0f, 1.0f,
            -0.5f, 0.5f, 0.5f, 0.0f, 1.0f,
            -0.5f, -0.5f, 0.5f, 0.0f, 0.0f,

            -0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
            -0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
            -0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
            -0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
            -0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
            -0.5f, 0.5f, 0.5f, 1.0f, 0.0f,

            0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
            0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
            0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
            0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
            0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
            0.5f, 0.5f, 0.5f, 1.0f, 0.0f,

            -0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
            0.5f, -0.5f, -0.5f, 1.0f, 1.0f,
            0.5f, -0.5f, 0.5f, 1.0f, 0.0f,
            0.5f, -0.5f, 0.5f, 1.0f, 0.0f,
            -0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
            -0.5f, -0.5f, -0.5f, 0.0f, 1.0f,

            -0.5f, 0.5f, -0.5f, 0.0f, 1.0f,
            0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
            0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
            0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
            -0.5f, 0.5f, 0.5f, 0.0f, 0.0f,
            -0.5f, 0.5f, -0.5f, 0.0f, 1.0f
    };

    unsigned int indices[] = {
            0, 1, 3,
            1, 2, 3
    };

    glEnable(GL_DEPTH_TEST);

    unsigned int VAO, VBO, EBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

//    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *) 0);
//    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *) (3 * sizeof(float)));
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *) (3 * sizeof(float)));

    glEnableVertexAttribArray(0);
//    glEnableVertexAttribArray(1);
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

    shaderChain.setTrans("projection", projection);

    glUniform1i(glGetUniformLocation(shaderChain.getProgram(), "texture1"), 0);
    // or set it via the texture class
    shaderChain.set("texture2", (int) 1);

//    shaderChain.set("texture1", 0);
//    shaderChain.set("texture2", 1);


    glm::vec3 cubePosition[] = {
            glm::vec3(0.0f, 0.0f, 0.0f),
            glm::vec3(2.0f, 5.0f, -15.0f),
            glm::vec3(-1.5f, -2.2f, -2.5f),
            glm::vec3(-3.8f, -2.0f, -12.3f),
            glm::vec3(2.4f, -0.4f, -3.5f),
            glm::vec3(-1.7f, 3.0f, -7.5f),
            glm::vec3(1.3f, -2.0f, -2.5f),
            glm::vec3(1.5f, 2.0f, -2.5f),
            glm::vec3(1.5f, 0.2f, -1.5f),
            glm::vec3(-1.3f, 1.0f, -1.5f)
    };

    while (!glfwWindowShouldClose(window)) {
        //处理输入事件
        ProcessInput(window);


        //设置颜色&清除缓冲
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glActiveTexture(GL_TEXTURE0);

        wallTexture.use();

        glBindVertexArray(VAO);

        for (auto i = 0; i < 10; i++) {
            glm::mat4 model{1};
            model = glm::translate(model, cubePosition[i]);
            float angle = 20.0f * i;
            model = glm::rotate(model, (float) glfwGetTime() * glm::radians(90.0f) + angle,
                                glm::vec3{0.5, 1, 0});
            shaderChain.setTrans("model", model);
            auto &&view = getView();
            shaderChain.setTrans("view", view);
            glDrawArrays(GL_TRIANGLES, 0, 36);
        }

        //检查调取事件，并交换缓冲
        glfwSwapBuffers(window);
        glfwPollEvents();
    }


    glfwTerminate();
    return 0;
}

auto ResizeListener(GLFWwindow *window, int width, int height) -> void {
    screenHeight = height;
    screenWidth = width;
    glViewport(0, 0, width, height);
}


auto ProcessInput(GLFWwindow *window) -> void {
#define PRESS(KEY) (glfwGetKey(window, (KEY)) == GLFW_PRESS)
    if (PRESS(GLFW_KEY_ESCAPE)) {
        glfwSetWindowShouldClose(window, true);
    }
    if (PRESS(GLFW_KEY_W)) {
        pos += glm::vec3{-sin(cam.y) * 0.1, 0, cos(cam.y) * 0.1};
    }


    if (PRESS(GLFW_KEY_S)) {
        pos += glm::vec3{sin(cam.y) * 0.1, 0, -cos(cam.y) * 0.1};
    }


    if (PRESS(GLFW_KEY_A)) {
        pos += glm::vec3{cos(cam.y) * 0.1, 0, sin(cam.y) * 0.1};
    }

    if (PRESS(GLFW_KEY_D)) {
        pos += glm::vec3{-cos(cam.y) * 0.1, 0, sin(cam.y) * 0.1};
    }

    if (PRESS(GLFW_KEY_LEFT_SHIFT)) {
        pos += glm::vec3{0, 0.1, 0};
    }

    if (PRESS(GLFW_KEY_SPACE)) {
        pos += glm::vec3{0, -0.1, 0};
    }

    if (PRESS(GLFW_KEY_UP)) {
        cam += glm::vec2{-0.03, 0};
    }
    if (PRESS(GLFW_KEY_DOWN)) {
        cam += glm::vec2{0.03, 0};
    }
    if (PRESS(GLFW_KEY_LEFT)) {
        cam += glm::vec2{0, -0.03};
    }
    if (PRESS(GLFW_KEY_RIGHT)) {
        cam += glm::vec2{0, 0.03};
    }

    if (PRESS(GLFW_KEY_R)) {
        cam = glm::vec2{0, 0};
    }
#undef PRESS
}