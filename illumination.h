// Recursos de iluminação simplificados
// Esta classe trabalha em conjunto com os arquivos genericoVshader.glsl e
// genericoFshader.glsl, que consideram duas fontes de luz com as mesmas
// características de luz ambiente, difusa e especular.
//    Provê recursos de iluminação básicos, definindo coeficientes de reflexão
// para um material que considera padrão. Oferece a possibilidade de alterar
// esses coeficientes, gerando cores diferentes, através das funções matAmbiente,
// matDiffuse e matSpecular, mas retorna para o material padrão de forma
// simplificada, através da função stdMaterial. Essa função deve ser utilizada
// logo após desenhar o objeto com cor diferente, para para facilitar a administração
// de cores e garantir a predominância do material padrão.
// Assim, é útil para criar cenas iluminadas, de forma simplificada, em que seja
// aceitável que o material padrão seja predominante.

#ifndef ILLUMINATION_H
#define ILLUMINATION_H

#include "glm/glm.hpp" //vec2, vec3, mat4, etc

class Illumination
{
public:
    Illumination();
    Illumination(GLuint program);
    ~Illumination();
    void stdMaterial();
    //funções para alterar parâmetros de material
    void matAmbient(float r, float g, float b, float alfa);
    void matDiffuse(float r, float g, float b, float alfa);
    void matSpecular(float r, float g, float b, float alfa);
    void lightPositions(glm::vec4 lp1, glm::vec4 lp2);

private:
    glm::vec4 light_ambient, light_diffuse, light_specular;

    glm::vec4 material_ambient, material_diffuse, material_specular;
    float  material_shininess;

    glm::vec4 ambient_product, diffuse_product, specular_product;

    GLuint AmbProd_loc, DifProd_loc, SpecProd_loc,
           LightPosition1_loc, LightPosition2_loc, Shininess_loc;
};

#endif // ILLUMINATION_H
