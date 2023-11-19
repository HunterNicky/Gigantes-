#pragma once

#include "Animacao/AnimacaoStrategy.hpp"

namespace Animacao {
    class AnimacaoBloco : public AnimacaoStrategy{
        private:
            float actualFrame;
            int actualImage;
            void updateAnimationFrame(double dt, float standardTime);
            void updateSpriteRect();
        public:
            AnimacaoBloco(Entidades::Entidade* entidade ,std::string path, int numFrames);
            ~AnimacaoBloco();
            void updateSprite(double dt, float standardTime);
            void changeTexture();
    };
}