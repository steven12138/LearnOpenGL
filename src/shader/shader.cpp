#include <glad/glad.h>

#include "shader.hpp"

#include <sstream>
#include <fstream>
#include <iostream>
#include <vector>

namespace shader {

    Shader::Shader(const char *path, GLenum shaderType) {
        std::ifstream shaderFile;
        std::string shaderCode;

        shaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
        try {
            shaderFile.open(path);
            std::stringstream codeStream;
            codeStream << shaderFile.rdbuf();
            shaderCode = codeStream.str();
        } catch (std::fstream::failure &e) {
            std::cerr << "ERROR::COULD_NOT_OPEN_FILE" << std::endl << e.what() << std::endl;
            throw shaderFileLoadException();
        }
        shaderID = glCreateShader(shaderType);
        const char *fShaderCode = shaderCode.c_str();
        glShaderSource(shaderID, 1, &fShaderCode, nullptr);
        glCompileShader(shaderID);

        int success;
        glGetShaderiv(shaderID, GL_COMPILE_STATUS, &success);
        if (!success) {
            char log[512];
            glGetShaderInfoLog(shaderID, 512, nullptr, log);
            std::cerr << "ERROR::COMPILE::SHADER: " << log << std::endl;
            throw shaderCompileError();
        }
    }

    auto Shader::GetShader() const -> unsigned int {
        return shaderID;
    }

    Shader::operator unsigned int() const {
        return GetShader();
    }


    ShaderProgram::ShaderProgram(const char *vShaderPath, const char *fShaderPath) {
        Shader vShader{vShaderPath, GL_VERTEX_SHADER};
        Shader fShader{fShaderPath, GL_FRAGMENT_SHADER};
        std::cout << vShader << std::endl << fShader << std::endl;
        programID = glCreateProgram();
        glAttachShader(programID, vShader);
        glAttachShader(programID, fShader);
        linkShader();
    }

    auto ShaderProgram::getProgram() const -> unsigned int {
        return programID;
    }

    ShaderProgram::operator unsigned int() const {
        return getProgram();
    }

    auto ShaderProgram::use() const -> void {
        if (!programIsReady) throw programNotConstructedException();
        glUseProgram(programID);
    }


    auto ShaderProgram::set1v(const std::string &name, float value) const -> void {
        auto location = glGetUniformLocation(programID, name.c_str());
        glUniform1f(location, value);
    }

    auto ShaderProgram::add(Shader &&shader) -> ShaderProgram & {
        shaderChain.push_back(shader);
        return *this;
    }

    auto ShaderProgram::load() -> void {
        programID = glCreateProgram();
        std::for_each(shaderChain.begin(), shaderChain.end(), [this](const auto &shader) {
            glAttachShader(programID, shader);
        });
        linkShader();
        programIsReady = true;
    }

    auto ShaderProgram::linkShader() const -> void {
        glLinkProgram(programID);
        int success;
        glGetProgramiv(programID, GL_LINK_STATUS, &success);
        if (!success) {
            char log[512];
            glGetProgramInfoLog(programID, 512, nullptr, log);
            std::cerr << "ERROR::SHADER_PROGRAM_LINKIN " << log << std::endl;
            throw programLinkError();
        }
    }
}