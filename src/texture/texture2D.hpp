#pragma once

#include <glad/glad.h>
#include <iostream>
#include <stb_image.h>
#include <sstream>
#include <vector>
#include <tuple>
#include <map>

namespace texture {

    template<GLint s = GL_REPEAT, GLint t = GL_REPEAT, GLint minF = GL_LINEAR, GLint magF = GL_LINEAR>
    class texture2DLoader {
    public:

        class repeatTextureUnit : std::exception {
        };

        struct textureAttrib {
            int width, height, nrChannels;

            explicit textureAttrib(int width, int height, int nrChannels)
                    : width(width), height(height), nrChannels(nrChannels) {}
        };

        struct texture2D {
            unsigned int textureID;
            textureAttrib attr;

            texture2D(unsigned int textureId, const textureAttrib &attr) : textureID(textureId), attr(attr) {}
        };

        explicit texture2DLoader() = delete;

        explicit texture2DLoader(const texture2DLoader &) = delete;

        explicit texture2DLoader(const char *texturePath);

        auto addTexture(const char *texturePath, GLenum textureUnit) -> void;

        auto use() -> void;

    private:
        std::vector<textureAttrib> textures;
        static std::map<GLenum, bool> isUnitUnique;

        static auto setDefaultParams() -> void;

        auto loadTexture(const char *texturePath) -> textureAttrib;

    };


    template<GLint s, GLint t, GLint minF, GLint magF>
    auto texture2DLoader<s, t, minF, magF>::setDefaultParams() -> void {
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, s);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, t);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, minF);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, magF);
    }

    template<GLint s, GLint t, GLint minF, GLint magF>
    texture2DLoader<s, t, minF, magF>::texture2DLoader(const char *texturePath) {
        addTexture(texturePath, GL_TEXTURE0);
    }

    template<GLint s, GLint t, GLint minF, GLint magF>
    auto texture2DLoader<s, t, minF, magF>::use() -> void {
        glBindTexture(GL_TEXTURE_2D, textures[0].textureID);
    }

    template<GLint s, GLint t, GLint minF, GLint magF>
    auto texture2DLoader<s, t, minF, magF>::addTexture(const char *texturePath, GLenum textureUnit) -> void {
        if (isUnitUnique[textureUnit]) {
            std::cerr << "ERROR::REPEAT_TEXTURE_UNIT" << std::endl;
            return ;
        }
        isUnitUnique[textureUnit] = true;

        unsigned int textureID;
        glGenTextures(1, &textureID);
        glActiveTexture(textureUnit);
        glBindTexture(GL_TEXTURE_2D, textureID);
        setDefaultParams();

        auto attr = loadTexture(texturePath);
        textures.emplace_back(texture2D(textureID, attr));
    }

    template<GLint s, GLint t, GLint minF, GLint magF>
    auto texture2DLoader<s, t, minF, magF>::loadTexture(const char *texturePath) -> textureAttrib {
        int width = 0, height = 0, nrChannels = 0;
        unsigned char *data = stbi_load(texturePath,
                                        &width, &height, &nrChannels,
                                        0);

        if (data) {
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
            glGenerateMipmap(GL_TEXTURE_2D);
        } else {
            std::cerr << "ERROR::FAILED_TO_LOAD_TEXTURE" << std::endl;
        }
        stbi_image_free(data);
        return (textureAttrib) {width, height, nrChannels};
    }
}