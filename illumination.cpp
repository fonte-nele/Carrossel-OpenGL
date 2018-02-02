#define GLEW_STATIC
#include <GL/glew.h>

#include "illumination.h"

Illumination::Illumination() {  }

Illumination::Illumination(GLuint program) {
    // Initialize shader lighting parameters with standard material
    AmbProd_loc = glGetUniformLocation(program, "AmbientProduct");
    DifProd_loc = glGetUniformLocation(program, "DiffuseProduct");
    SpecProd_loc = glGetUniformLocation(program, "SpecularProduct");

    LightPosition1_loc = glGetUniformLocation(program, "LightPosition1");
    LightPosition2_loc = glGetUniformLocation(program, "LightPosition2");
    Shininess_loc = glGetUniformLocation(program, "Shininess");

    light_ambient = glm::vec4( 0.2f, 0.2f, 0.2f, 1.0f );
    light_diffuse = glm::vec4( 1.0f, 1.0f, 1.0f, 1.0f );
    light_specular = glm::vec4( 1.0f, 1.0f, 1.0f, 1.0f );

    material_ambient = glm::vec4( 1.0f, 0.0f, 1.0f, 1.0f );
    material_diffuse = glm::vec4( 0.8f, 0.6f, 0.0f, 1.0f );
    material_specular = glm::vec4( 0.9f, 0.7f, 0.0f, 1.0f );
    material_shininess = 100.0f;

    ambient_product = light_ambient * material_ambient;
    diffuse_product = light_diffuse * material_diffuse;
    specular_product = light_specular * material_specular;

    glUniform4fv( AmbProd_loc, 1, glm::value_ptr(ambient_product ));
    glUniform4fv( DifProd_loc, 1, glm::value_ptr(diffuse_product ));
    glUniform4fv( SpecProd_loc, 1, glm::value_ptr(specular_product ));

    glUniform4fv( LightPosition1_loc, 1,
                  glm::value_ptr(glm::vec4( 1.0f, 1.0f, 0.0f, 1.0f ) ));
    glUniform4fv( LightPosition2_loc, 1,
                  glm::value_ptr(glm::vec4( -1.0f, 1.0f, 0.0f, 1.0f ) ));

    glUniform1f( Shininess_loc, material_shininess );
}

Illumination::~Illumination() {  }

void Illumination::matDiffuse(float r, float g, float b, float alfa)
{
    glm::vec4 dif_prod = light_diffuse * glm::vec4( r, g, b, alfa );
    glUniform4fv( DifProd_loc, 1, glm::value_ptr(dif_prod ));
}

void Illumination::matAmbient(float r, float g, float b, float alfa)
{
    glm::vec4 amb_prod = light_ambient * glm::vec4( r, g, b, alfa );
    glUniform4fv( AmbProd_loc, 1, glm::value_ptr(amb_prod ));
}

void Illumination::matSpecular(float r, float g, float b, float alfa)
{
    glm::vec4 spec_prod = light_specular * glm::vec4( r, g, b, alfa );
    glUniform4fv( SpecProd_loc, 1, glm::value_ptr(spec_prod ));
}

void Illumination::stdMaterial()
{
    glUniform4fv( AmbProd_loc, 1, glm::value_ptr(ambient_product ));
    glUniform4fv( DifProd_loc, 1, glm::value_ptr(diffuse_product ));
    glUniform4fv( SpecProd_loc, 1, glm::value_ptr(specular_product ));
}

void Illumination::lightPositions(glm::vec4 lp1, glm::vec4 lp2)
{
    glUniform4fv( LightPosition1_loc, 1, glm::value_ptr(lp1 ));
    glUniform4fv( LightPosition2_loc, 1, glm::value_ptr(lp2 ));
}
