#pragma once

#include <glad/glad.h>
#include <vector>
#include <map>

#include "texture2D.hpp"

#include <stb_image.h>

#include <iostream>

namespace texture {

    class texture2DLoader {
    public:
        class repeatTextureUnitException : std::exception {
        };

        struct textureAttrib {
            int width, height, nrChannels;

            textureAttrib() = default;

            textureAttrib(int width, int height, int nrChannels)
                    : width(width), height(height), nrChannels(nrChannels) {}
        };

        struct texture2D {
            unsigned int textureID{};
            textureAttrib attr;

            texture2D() = default;

            texture2D(unsigned int textureId, const textureAttrib &attr) : textureID(textureId), attr(attr) {}

        };

        texture2DLoader() = default;

        template<GLint s = GL_REPEAT, GLint t = GL_REPEAT, GLint minF = GL_LINEAR, GLint magF = GL_LINEAR>
        explicit texture2DLoader(const char *texturePath, GLint imageType = GL_RGB);

        template<GLint s = GL_REPEAT, GLint t = GL_REPEAT, GLint minF = GL_LINEAR, GLint magF = GL_LINEAR>
        auto addTexture(const char *texturePath, GLenum textureUnit, GLint imageType = GL_RGB) -> texture2DLoader &;

        auto use() -> void;

    private:
        std::vector<texture2D> textures;
        std::map<GLenum, bool> isUnitUnique;

        textureAttrib attr{};

        static auto setDefaultParams(GLint s, GLint t, GLint minF, GLint magF) -> void;

        static auto loadTexture(const char *texturePath, GLint imageType) -> textureAttrib;

    };


    template<GLint s, GLint t, GLint minF, GLint magF>
    texture2DLoader::
    texture2DLoader(const char *texturePath, GLint imageType) {
        addTexture(texturePath, GL_TEXTURE0, imageType);
    }


    template<GLint s, GLint t, GLint minF, GLint magF>
    auto texture2DLoader::
    addTexture(const char *texturePath, GLenum textureUnit, GLint imageType) -> texture2DLoader & {
        if (this->isUnitUnique[textureUnit]) {
            std::cerr << "ERROR::REPEAT_TEXTURE_UNIT" << std::endl;
            throw repeatTextureUnitException();
        }
        isUnitUnique[textureUnit] = true;

        unsigned int textureID;
        glGenTextures(1, &textureID);
        glActiveTexture(textureUnit);
        glBindTexture(GL_TEXTURE_2D, textureID);
        setDefaultParams(s, t, minF, magF);

        attr = loadTexture(texturePath, imageType);
        textures.emplace_back(texture2D(textureID, attr));
        return *this;
    }

    auto texture2DLoader::
    use() -> void {
        if (textures.empty()) return;
        for (const auto &texture: textures) {
            glBindTexture(GL_TEXTURE_2D, texture.textureID);
        }
    }


    auto texture2DLoader::
    setDefaultParams(GLint s, GLint t, GLint minF, GLint magF) -> void {
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, s);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, t);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, minF);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, magF);

    }

    auto texture2DLoader::
    loadTexture(const char *texturePath, GLint imageType) -> texture2DLoader::textureAttrib {
        int width = 0, height = 0, nrChannels = 0;
        unsigned char *data = stbi_load(texturePath,
                                        &width, &height, &nrChannels,
                                        0);
        if (data) {
            glTexImage2D(GL_TEXTURE_2D, 0, imageType, width, height, 0, imageType, GL_UNSIGNED_BYTE, data);
            glGenerateMipmap(GL_TEXTURE_2D);
        } else {
            std::cerr << "ERROR::FAILED_TO_LOAD_TEXTURE: " << texturePath << std::endl;
        }
        stbi_image_free(data);
        return {width, height, nrChannels};
    }
}