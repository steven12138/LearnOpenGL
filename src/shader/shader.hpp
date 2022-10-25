#pragma once

#include <glad/glad.h>
#include <glm/gtc/type_ptr.hpp>
#include <vector>
#include <string>

namespace shader {
    class Shader {
    public:
        class shaderCompileError : std::exception {
        };

        class shaderFileLoadException : std::exception {
        };

        explicit Shader(const char *path, GLenum shaderType);

        explicit Shader(const Shader &shader) = delete;


        [[nodiscard]] auto GetShader() const -> unsigned int;

        operator unsigned int() const;

    private:
        unsigned int shaderID{};
    };


    class ShaderProgram {
    public:

        class programNotConstructedException : std::exception {
        };

        class programLinkError : std::exception {
        };

        explicit ShaderProgram() = default;

        explicit ShaderProgram(const char *vShaderPath, const char *fShaderPath);

        [[nodiscard]] auto getProgram() const -> unsigned int;

        explicit operator unsigned int() const;

        auto use() const -> void;

        auto add(Shader &&shader) -> ShaderProgram &;

        auto load() -> void;

        auto set(const std::string &name, float value) const -> void;

        auto set(const std::string &name, int value) const -> void;

        auto setTrans(const std::string &name, glm::mat4 &trans) const -> void;

    private:
        std::vector<unsigned int> shaderChain{};
        unsigned int programID{};
        bool programIsReady = false;

        auto linkShader() const -> void;
    };
}