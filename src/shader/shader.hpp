#pragma once

#include <glad/glad.h>
#include <vector>

namespace shader {
    class Shader {
    public:
        explicit Shader(const char *path, GLenum shaderType);

        explicit Shader(const Shader &shader) = delete;


        [[nodiscard]] auto GetShader() const -> unsigned int;

        operator unsigned int() const;

    private:
        unsigned int shaderID{};
    };



    class ShaderProgram {
    public:

        explicit ShaderProgram() = default;

        explicit ShaderProgram(const char *vShaderPath, const char *fShaderPath);

        [[nodiscard]] auto getProgram() const -> unsigned int;

        explicit operator unsigned int() const;

        auto use() const -> void;

        auto add(Shader &&shader) -> ShaderProgram &;

        auto load() -> void;

        auto set1v(const std::string &name, float value) const -> void;

    private:
        std::vector<unsigned int> shaderChain{};
        unsigned int programID{};

        auto linkShader() const -> void;
    };
}