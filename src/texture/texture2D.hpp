#pragma once

#include <glad/glad.h>
#include <iostream>
#include <stb_image.h>
#include <sstream>

namespace texture {
    class texture2D {
    public:
        explicit texture2D() = delete;

        explicit texture2D(const texture2D &) = delete;

        explicit texture2D(const char *texturePath);

        auto setParameter(GLenum type, GLint value) -> void;

    private:
        int width{}, height{}, nrChannels{};
        unsigned int textureID;
    };

    texture2D::texture2D(const char *texturePath) {
        std::stringstream pathStream;
        pathStream << STATIC_FILE_PATH << texturePath;
        unsigned char *data = stbi_load(pathStream.str().c_str(), &width, &height, &nrChannels, 0);
        if (data) {
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
            glGenerateMipmap(GL_TEXTURE_2D);
        } else {
            std::cerr << "ERROR::FAILED_TO_LOAD_TEXTURE" << std::endl;
        }
        stbi_image_free(data);

        glGenTextures(1, &textureID);
        glBindTexture(GL_TEXTURE_2D, textureID);
    }

    auto texture2D::setParameter(GLenum type, GLint value) -> void {
        glTexParameteri(GL_TEXTURE_2D, type, value);
    }
}