// Recursos de ilumina��o simplificados
// Esta classe trabalha em conjunto com os arquivos genericoVshader.glsl e
// genericoFshader.glsl, que consideram duas fontes de luz com as mesmas
// caracter�sticas de luz ambiente, difusa e especular.
//    Prov� recursos de ilumina��o b�sicos, definindo coeficientes de reflex�o
// para um material que considera padr�o. Oferece a possibilidade de alterar
// esses coeficientes, gerando cores diferentes, atrav�s das fun��es matAmbiente,
// matDiffuse e matSpecular, mas retorna para o material padr�o de forma
// simplificada, atrav�s da fun��o stdMaterial. Essa fun��o deve ser utilizada
// logo ap�s desenhar o objeto com cor diferente, para para facilitar a administra��o
// de cores e garantir a predomin�ncia do material padr�o.
// Assim, � �til para criar cenas iluminadas, de forma simplificada, em que seja
// aceit�vel que o material padr�o seja predominante.

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
    //fun��es para alterar par�metros de material
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
