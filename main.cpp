#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "shader.h"
#include "camera.h"
#include "basic_camera.h"
#include "pointLight.h"
#include "directionalLight.h"
#include "SpotLight.h"
#include "walls.h"
#include "roundTable.h"
#include "chair.h"
#include "sofa.h"
#include "bed.h"
#include "sidedrawer.h"
#include "dining.h"
#include "bookShelf.h"
#include "cylinder.h"
#include "traizoid.h"
#include "halfs.h"
#include "triangle.h"
#include "cube.h"
#include "goblet.h"
#include "stb_image.h"
#include "library.h"
#include "mainstair.h"
#include "gate.h"
#include "pyramid.h"
#include "scull.h"
#include "broom.h"


using namespace std;

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void processInput(GLFWwindow* window);
unsigned int loadTexture(char const* path, GLenum textureWrappingModeS, GLenum textureWrappingModeT, GLenum textureFilteringModeMin, GLenum textureFilteringModeMax);
// settings
const unsigned int SCR_WIDTH = 1400;
const unsigned int SCR_HEIGHT = 800;

// modelling transform
float rotateAngle_X = 0.0;
float rotateAngle_Y = 0.0;
float rotateAngle_Z = 0.0;
float rotateAxis_X = 0.0;
float rotateAxis_Y = 0.0;
float rotateAxis_Z = 1.0;
float translate_X = 0.0;
float translate_Y = 0.0;
float translate_Z = 0.0;
float scale_X = 1.0;
float scale_Y = 1.0;
float scale_Z = 1.0;

//bookshelf er jonno code
std::random_device rd;
std::mt19937 gen(rd());
std::uniform_real_distribution<double> dis(0.0, 1.0);

float colorArray[300];





// camera
Camera camera(glm::vec3(-6.5f, 24.9f, 145.2f));
float lastX = SCR_WIDTH / 2.0f;
float lastY = SCR_HEIGHT / 2.0f;
bool firstMouse = true;

float eyeX = 0.0, eyeY = 1.0, eyeZ = 3.0;
float lookAtX = 0.0, lookAtY = 0.0, lookAtZ = 0.0;
glm::vec3 V = glm::vec3(0.0f, 1.0f, 0.0f);
BasicCamera basic_camera(eyeX, eyeY, eyeZ, lookAtX, lookAtY, lookAtZ, V);



// positions of the point lights
glm::vec3 pointLightPositions[] = {
    glm::vec3(-8.5f + 3.5f,  4.50f,  -6.5 + 0.25f),
    glm::vec3(4.5f,  4.5f,   -6.5 + 0.25f),
    glm::vec3(8.6f,  19.50f,  -6.5+0.25f),
    glm::vec3(-10.5f,  4.50f,  -6.5f+.25f),
    glm::vec3(-16.5f,  5.2f,  -6.50f+0.25f),
    glm::vec3(22.5f,  19.50f,  -6.5 + 0.25f),
    glm::vec3(9.4f,  4.5f,   -6.5 + 0.25f),
    glm::vec3(-22.5f,  4.5f,   -6.5 + 0.25f),
    glm::vec3(7.5f,  19.50f,  17.5 + 0.25f),
    glm::vec3(25.5f,  19.50f,  17.5 + 0.25f),
    glm::vec3(-40.5f,  19.50f,  -6.5 + 0.25f),
    glm::vec3(-20.0f,  19.50f,  -6.5 + 0.25f),
    glm::vec3(-30.0f,  22.50f,  3.5 + 0.25f),
    glm::vec3(-40.5f,  19.50f,  22.5 + 0.25f),
    glm::vec3(-20.0f,  19.50f,  22.5 + 0.25f),
    glm::vec3(-4.1f + 3.5f,  4.50f,  -6.5 + 0.25f),
    glm::vec3(-33.5f,  4.5f,   -6.5 + 0.25f),
    glm::vec3(-40.5f,  4.5f,   -6.5 + 0.25f),
    glm::vec3(-33.5f,  4.5f,   6.5 + 0.25f),
    glm::vec3(-40.5f,  4.5f,   6.5 + 0.25f),
    glm::vec3(16.5f,  4.5f,   -6.5 + 0.25f),
    glm::vec3(27.5f,  4.9f,   -5.5 + 0.25f),
    glm::vec3(-7.5f,  14.0f,   100.9 + 0.25f),
    glm::vec3(-15.5f,  14.0f,   100.9 + 0.25f),
    glm::vec3(4.5f,  14.0f,   100.9 + 0.25f),
    glm::vec3(9.5f,  14.0f,   100.9 + 0.25f),
    glm::vec3(-25.5f, 14.0f,   100.9 + 0.25f),
    glm::vec3(-7.5f, 26.0f,   100.9 + 0.25f),
    glm::vec3(-15.5f, 26.0f,   100.9 + 0.25f),
    glm::vec3(4.5f,  26.0f,   100.9 + 0.25f),
    glm::vec3(9.5f,  26.0f,   100.9 + 0.25f),
    glm::vec3(-25.5f, 26.0f,   100.9 + 0.25f),
    glm::vec3(-7.5f, 26.0f,   50.9 + 0.25f),
    glm::vec3(-15.5f, 26.0f,   50.9 + 0.25f),
    glm::vec3(4.5f,  26.0f,   50.9 + 0.25f),
    glm::vec3(9.5f,  26.0f,   50.9 + 0.25f),
    glm::vec3(-25.5f, 26.0f,   50.9 + 0.25f),
    glm::vec3(-5.0f,  14.0f,   100.9 + 0.25f)
};

PointLight pointlight1(

    pointLightPositions[0].x, pointLightPositions[0].y, pointLightPositions[0].z,  // position
        // ambient
    0.3f, 0.3f, 0.3f,     // diffuse
    1.0f, 1.0f, 1.0f,
    1.0f, 1.0f, 1.0f,        // specular
    1.0f,   //k_c
    0.09f,  //k_l
    0.032f, //k_q
    1       // light number
);


PointLight pointlight2(

    pointLightPositions[1].x, pointLightPositions[1].y, pointLightPositions[1].z,  // position
    0.3f, 0.3f, 0.3f,     // diffuse
    1.0f, 1.0f, 1.0f,
    1.0f, 1.0f, 1.0f,        // specular
    1.0f,   //k_c
    0.09f,  //k_l
    0.032f, //k_q
    2       // light number
);

PointLight pointlight3(

    pointLightPositions[2].x, pointLightPositions[2].y, pointLightPositions[2].z,  // position
    0.3f, 0.3f, 0.3f,     // diffuse
    1.0f, 1.0f, 1.0f,
    1.0f, 1.0f, 1.0f,        // specular
    1.0f,   //k_c
    0.09f,  //k_l
    0.032f, //k_q
    3       // light number
);


PointLight pointlight4(

    pointLightPositions[3].x, pointLightPositions[3].y, pointLightPositions[3].z,  // position
    0.3f, 0.3f, 0.3f,     // diffuse
    1.0f, 1.0f, 1.0f,
    1.0f, 1.0f, 1.0f,        // specular
    1.0f,   //k_c
    0.09f,  //k_l
    0.032f, //k_q
    4      // light number
);
 PointLight pointlight5(

    pointLightPositions[4].x, pointLightPositions[4].y, pointLightPositions[4].z,  // position
    0.3f, 0.3f, 0.3f,     // diffuse
    1.0f, 1.0f, 1.0f,
    1.0f, 1.0f, 1.0f,        // specular
    1.0f,   //k_c
    0.09f,  //k_l
    0.032f, //k_q
    5      // light number
);
 PointLight pointlight6(

    pointLightPositions[5].x, pointLightPositions[5].y, pointLightPositions[5].z,  // position
    0.3f, 0.3f, 0.3f,     // diffuse
    1.0f, 1.0f, 1.0f,
    1.0f, 1.0f, 1.0f,        // specular
    1.0f,   //k_c
    0.09f,  //k_l
    0.032f, //k_q
    6      // light number
);
 PointLight pointlight7(

    pointLightPositions[6].x, pointLightPositions[6].y, pointLightPositions[6].z,  // position
    0.3f, 0.3f, 0.3f,     // diffuse
    1.0f, 1.0f, 1.0f,
    1.0f, 1.0f, 1.0f,        // specular
    1.0f,   //k_c
    0.09f,  //k_l
    0.032f, //k_q
    7      // light number
);

 PointLight pointlight8(

     pointLightPositions[7].x, pointLightPositions[7].y, pointLightPositions[7].z,  // position
     0.3f, 0.3f, 0.3f,     // diffuse
     1.0f, 1.0f, 1.0f,
     1.0f, 1.0f, 1.0f,        // specular
     1.0f,   //k_c
     0.09f,  //k_l
     0.032f, //k_q
     8      // light number
 );

 PointLight pointlight9(

     pointLightPositions[8].x, pointLightPositions[8].y, pointLightPositions[8].z,  // position
     0.3f, 0.3f, 0.3f,     // diffuse
     1.0f, 1.0f, 1.0f,
     1.0f, 1.0f, 1.0f,        // specular
     1.0f,   //k_c
     0.09f,  //k_l
     0.032f, //k_q
     9      // light number
 );
 PointLight pointlight10(

     pointLightPositions[9].x, pointLightPositions[9].y, pointLightPositions[9].z,  // position
     0.3f, 0.3f, 0.3f,     // diffuse
     1.0f, 1.0f, 1.0f,
     1.0f, 1.0f, 1.0f,        // specular
     1.0f,   //k_c
     0.09f,  //k_l
     0.032f, //k_q
     10      // light number
 );

 PointLight pointlight11(

     pointLightPositions[10].x, pointLightPositions[10].y, pointLightPositions[10].z,  // position
     0.3f, 0.3f, 0.3f,     // diffuse
     1.0f, 1.0f, 1.0f,
     1.0f, 1.0f, 1.0f,        // specular
     1.0f,   //k_c
     0.09f,  //k_l
     0.032f, //k_q
     11      // light number
 );
 PointLight pointlight12(

     pointLightPositions[11].x, pointLightPositions[11].y, pointLightPositions[11].z,  // position
     0.3f, 0.3f, 0.3f,     // diffuse
     1.0f, 1.0f, 1.0f,
     1.0f, 1.0f, 1.0f,        // specular
     1.0f,   //k_c
     0.09f,  //k_l
     0.032f, //k_q
     12      // light number
 );
 PointLight pointlight13(

     pointLightPositions[12].x, pointLightPositions[12].y, pointLightPositions[12].z,  // position
     0.3f, 0.3f, 0.3f,     // diffuse
     1.0f, 1.0f, 1.0f,
     1.0f, 1.0f, 1.0f,        // specular
     1.0f,   //k_c
     0.09f,  //k_l
     0.032f, //k_q
     13      // light number
 );
 PointLight pointlight14(

     pointLightPositions[13].x, pointLightPositions[13].y, pointLightPositions[13].z,  // position
     0.3f, 0.3f, 0.3f,     // diffuse
     1.0f, 1.0f, 1.0f,
     1.0f, 1.0f, 1.0f,        // specular
     1.0f,   //k_c
     0.09f,  //k_l
     0.032f, //k_q
     14      // light number
 );
 PointLight pointlight15(

     pointLightPositions[14].x, pointLightPositions[14].y, pointLightPositions[14].z,  // position
     0.3f, 0.3f, 0.3f,     // diffuse
     1.0f, 1.0f, 1.0f,
     1.0f, 1.0f, 1.0f,        // specular
     1.0f,   //k_c
     0.09f,  //k_l
     0.032f, //k_q
     15      // light number
 );
 PointLight pointlight16(

     pointLightPositions[15].x, pointLightPositions[15].y, pointLightPositions[15].z,  // position
     0.3f, 0.3f, 0.3f,     // diffuse
     1.0f, 1.0f, 1.0f,
     1.0f, 1.0f, 1.0f,        // specular
     1.0f,   //k_c
     0.09f,  //k_l
     0.032f, //k_q
     16      // light number
 );
 PointLight pointlight17(

     pointLightPositions[16].x, pointLightPositions[16].y, pointLightPositions[16].z,  // position
     0.3f, 0.3f, 0.3f,     // diffuse
     1.0f, 1.0f, 1.0f,
     1.0f, 1.0f, 1.0f,        // specular
     1.0f,   //k_c
     0.09f,  //k_l
     0.032f, //k_q
     17      // light number
 );
 PointLight pointlight18(

     pointLightPositions[17].x, pointLightPositions[17].y, pointLightPositions[17].z,  // position
     0.3f, 0.3f, 0.3f,     // diffuse
     1.0f, 1.0f, 1.0f,
     1.0f, 1.0f, 1.0f,        // specular
     1.0f,   //k_c
     0.09f,  //k_l
     0.032f, //k_q
     18      // light number
 );
 PointLight pointlight19(

     pointLightPositions[18].x, pointLightPositions[18].y, pointLightPositions[18].z,  // position
     0.3f, 0.3f, 0.3f,     // diffuse
     1.0f, 1.0f, 1.0f,
     1.0f, 1.0f, 1.0f,        // specular
     1.0f,   //k_c
     0.09f,  //k_l
     0.032f, //k_q
     19      // light number
 );
 PointLight pointlight20(

     pointLightPositions[19].x, pointLightPositions[19].y, pointLightPositions[19].z,  // position
     0.3f, 0.3f, 0.3f,     // diffuse
     1.0f, 1.0f, 1.0f,
     1.0f, 1.0f, 1.0f,        // specular
     1.0f,   //k_c
     0.09f,  //k_l
     0.032f, //k_q
     20      // light number
 );
 PointLight pointlight21(

     pointLightPositions[20].x, pointLightPositions[20].y, pointLightPositions[20].z,  // position
     0.3f, 0.3f, 0.3f,     // diffuse
     1.0f, 1.0f, 1.0f,
     1.0f, 1.0f, 1.0f,        // specular
     1.0f,   //k_c
     0.09f,  //k_l
     0.032f, //k_q
     21      // light number
 );
 PointLight pointlight22(

     pointLightPositions[21].x, pointLightPositions[21].y, pointLightPositions[21].z,  // position
     0.3f, 0.3f, 0.3f,     // diffuse
     1.0f, 1.0f, 1.0f,
     1.0f, 1.0f, 1.0f,        // specular
     1.0f,   //k_c
     0.09f,  //k_l
     0.032f, //k_q
     22      // light number
 );
 PointLight pointlight23(

     pointLightPositions[22].x, pointLightPositions[22].y, pointLightPositions[22].z,  // position
     0.3f, 0.3f, 0.3f,     // diffuse
     1.0f, 1.0f, 1.0f,
     1.0f, 1.0f, 1.0f,        // specular
     1.0f,   //k_c
     0.09f,  //k_l
     0.032f, //k_q
     23      // light number
 );
 PointLight pointlight24(

     pointLightPositions[23].x, pointLightPositions[23].y, pointLightPositions[23].z,  // position
     0.3f, 0.3f, 0.3f,     // diffuse
     1.0f, 1.0f, 1.0f,
     1.0f, 1.0f, 1.0f,        // specular
     1.0f,   //k_c
     0.09f,  //k_l
     0.032f, //k_q
     24      // light number
 );
 PointLight pointlight25(

     pointLightPositions[24].x, pointLightPositions[24].y, pointLightPositions[24].z,  // position
     0.3f, 0.3f, 0.3f,     // diffuse
     1.0f, 1.0f, 1.0f,
     1.0f, 1.0f, 1.0f,        // specular
     1.0f,   //k_c
     0.09f,  //k_l
     0.032f, //k_q
     25      // light number
 );
 PointLight pointlight26(

     pointLightPositions[25].x, pointLightPositions[25].y, pointLightPositions[25].z,  // position
     0.3f, 0.3f, 0.3f,     // diffuse
     1.0f, 1.0f, 1.0f,
     1.0f, 1.0f, 1.0f,        // specular
     1.0f,   //k_c
     0.09f,  //k_l
     0.032f, //k_q
     26      // light number
 );
 PointLight pointlight27(

     pointLightPositions[26].x, pointLightPositions[26].y, pointLightPositions[26].z,  // position
     0.3f, 0.3f, 0.3f,     // diffuse
     1.0f, 1.0f, 1.0f,
     1.0f, 1.0f, 1.0f,        // specular
     1.0f,   //k_c
     0.09f,  //k_l
     0.032f, //k_q
     27      // light number
 );
 PointLight pointlight28(

     pointLightPositions[27].x, pointLightPositions[27].y, pointLightPositions[27].z,  // position
     0.3f, 0.3f, 0.3f,     // diffuse
     1.0f, 1.0f, 1.0f,
     1.0f, 1.0f, 1.0f,        // specular
     1.0f,   //k_c
     0.09f,  //k_l
     0.032f, //k_q
     28      // light number
 );
 
 PointLight pointlight29(

     pointLightPositions[28].x, pointLightPositions[28].y, pointLightPositions[28].z,  // position
     0.3f, 0.3f, 0.3f,     // diffuse
     1.0f, 1.0f, 1.0f,
     1.0f, 1.0f, 1.0f,        // specular
     1.0f,   //k_c
     0.09f,  //k_l
     0.032f, //k_q
     29      // light number
 );
 PointLight pointlight30(

     pointLightPositions[29].x, pointLightPositions[29].y, pointLightPositions[29].z,  // position
     0.3f, 0.3f, 0.3f,     // diffuse
     1.0f, 1.0f, 1.0f,
     1.0f, 1.0f, 1.0f,        // specular
     1.0f,   //k_c
     0.09f,  //k_l
     0.032f, //k_q
     30      // light number
 );
 PointLight pointlight31(

     pointLightPositions[30].x, pointLightPositions[30].y, pointLightPositions[30].z,  // position
     0.3f, 0.3f, 0.3f,     // diffuse
     1.0f, 1.0f, 1.0f,
     1.0f, 1.0f, 1.0f,        // specular
     1.0f,   //k_c
     0.09f,  //k_l
     0.032f, //k_q
     31      // light number
 );
 PointLight pointlight32(

     pointLightPositions[31].x, pointLightPositions[31].y, pointLightPositions[31].z,  // position
     0.3f, 0.3f, 0.3f,     // diffuse
     1.0f, 1.0f, 1.0f,
     1.0f, 1.0f, 1.0f,        // specular
     1.0f,   //k_c
     0.09f,  //k_l
     0.032f, //k_q
     32      // light number
 );
 PointLight pointlight33(

     pointLightPositions[32].x, pointLightPositions[32].y, pointLightPositions[32].z,  // position
     0.3f, 0.3f, 0.3f,     // diffuse
     1.0f, 1.0f, 1.0f,
     1.0f, 1.0f, 1.0f,        // specular
     1.0f,   //k_c
     0.09f,  //k_l
     0.032f, //k_q
     33      // light number
 );
 PointLight pointlight34(

     pointLightPositions[33].x, pointLightPositions[33].y, pointLightPositions[33].z,  // position
     0.3f, 0.3f, 0.3f,     // diffuse
     1.0f, 1.0f, 1.0f,
     1.0f, 1.0f, 1.0f,        // specular
     1.0f,   //k_c
     0.09f,  //k_l
     0.032f, //k_q
     34      // light number
 );
 PointLight pointlight35(

     pointLightPositions[34].x, pointLightPositions[34].y, pointLightPositions[34].z,  // position
     0.3f, 0.3f, 0.3f,     // diffuse
     1.0f, 1.0f, 1.0f,
     1.0f, 1.0f, 1.0f,        // specular
     1.0f,   //k_c
     0.09f,  //k_l
     0.032f, //k_q
     35      // light number
 );
 PointLight pointlight36(

     pointLightPositions[35].x, pointLightPositions[35].y, pointLightPositions[35].z,  // position
     0.3f, 0.3f, 0.3f,     // diffuse
     1.0f, 1.0f, 1.0f,
     1.0f, 1.0f, 1.0f,        // specular
     1.0f,   //k_c
     0.09f,  //k_l
     0.032f, //k_q
     36      // light number
 );
 PointLight pointlight37(

     pointLightPositions[36].x, pointLightPositions[36].y, pointLightPositions[36].z,  // position
     0.3f, 0.3f, 0.3f,     // diffuse
     1.0f, 1.0f, 1.0f,
     1.0f, 1.0f, 1.0f,        // specular
     1.0f,   //k_c
     0.09f,  //k_l
     0.032f, //k_q
     37      // light number
 );
 PointLight pointlight38(

     pointLightPositions[37].x, pointLightPositions[37].y, pointLightPositions[37].z,  // position
     0.3f, 0.3f, 0.3f,     // diffuse
     1.0f, 1.0f, 1.0f,
     1.0f, 1.0f, 1.0f,        // specular
     1.0f,   //k_c
     0.09f,  //k_l
     0.032f, //k_q
     38      // light number
 );


DirLight dirLight(
        -0.2f, -1.0f, -0.3f,
        0.05f, 0.05f, 0.05f,
        .5f, 0.5f, 0.5f,     // diffuse
        0.5f, 0.5f, 0.5f
);


SpotLight spotLight(
    -3.50f, 4.0f, -2.0f,
    0.6f, -1.0f, 0.5f,
    0.5f, 0.0f, 0.5f,
    1.0f, 0.0f, 1.0f,
    1.0f, 1.0f, 1.0f,
    1.0f,
    0.09f,
    0.032f,
    12.5f,
    15.0f
);



// light settings
bool PointToggle1 = true;
bool PointToggle3 = true;
bool ambientToggle = true;
bool diffuseToggle = true;
bool specularToggle = true;


// timing
float deltaTime = 0.0f;    // time between current frame and last frame
float lastFrame = 0.0f;


float door_ang = 0.0;
float door_ang1 = 0.0;
float spare_angle = 10.0f;


int main()
{
    // glfw: initialize and configure
    // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // glfw window creation
    // --------------------
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "CSE 4208: Computer Graphics Laboratory", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetCursorPosCallback(window, mouse_callback);
    glfwSetScrollCallback(window, scroll_callback);

    // tell GLFW to capture our mouse
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);

    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // configure global opengl state
    // -----------------------------
    glEnable(GL_DEPTH_TEST);

    // build and compile our shader zprogram
    // ------------------------------------
    Shader lightingWithTextureShader("Shader/PhongShadingWithTexture/vertexShaderForPhongShadingWithTexture.vs", "Shader/PhongShadingWithTexture/fragmentShaderForPhongShadingWithTexture.fs");
    //Shader lightingShader("vertexShaderForGouraudShading.vs", "fragmentShaderForGouraudShading.fs");
    Shader ourShader("Shader/vertexShader.vs", "Shader/fragmentShader.fs");

    string diffuseMapPath = "Texture/container2.png";
    string specularMapPath = "Texture/container2_specular.png";
    //string woodtablediffMapPath = "Texture/wood_table_001_diff_4k.jpg";
    //string woodtablespecMapPath = "Texture/wood_table_001_disp_4k.png";
    string brickdiffMapPath = "Texture/patterned_brick_floor_diff_4k.jpg";
    string brickspecMapPath = "Texture/patterned_brick_floor_disp_4k.png";
    string tilesdiffMapPath = "Texture/red_sandstone_wall_diff_4k.jpg";
    string tilesspecMapPath = "Texture/red_sandstone_wall_disp_4k.png";
    string windowdiffMapPath = "Texture/window.jpeg";
    string windowspecMapPath = "Texture/window.jpeg";
    string bedpichondiffMapPath = "Texture/bedpichon.jpg";
    string bedpichonspecMapPath = "Texture/bedpichon.jpg";
    string redsofadiffMapPath = "Texture/red-sofa.jpg";
    string redsofaspecMapPath = "Texture/red-sofa.jpg";
    string mywindowdiffMapPath = "Texture/mywindow.jpg";
    string mywindowspecMapPath = "Texture/mywindow.jpg";
    string chairiffMapPath = "Texture/chair.jpg";
    string chairspecMapPath = "Texture/chair.jpg";
    string frdiffMapPath = "Texture/fr.jpg";
    string frspecMapPath = "Texture/fr.jpg";
    string dumbdiffMapPath = "Texture/dumb.jpg";
    string dumbspecMapPath = "Texture/dumb.jpg";
    string tablediffMapPath = "Texture/table.jpg";
    string tablespecMapPath = "Texture/table.jpg";
    string ttdiffMapPath = "Texture/wood_table_001_diff_4k.jpg";
    string ttspecMapPath = "Texture/wood_table_001_diff_4k.jpg";
    string seatdiffMapPath = "Texture/sofacushion.jpg";
    string seatspecMapPath = "Texture/sofacushion.jpg";
    string glassdiffMapPath = "Texture/window.jpg";
    string glassspecMapPath = "Texture/window.jpg";
    string pdiffMapPath = "Texture/potion.jpg";
    string pspecMapPath = "Texture/potion.jpg";
    string doordiffMapPath = "Texture/doorr.jpg";
    string doorspecMapPath = "Texture/doorr.jpg";
    string boarddiffMapPath = "Texture/board.jpg";
    string boardspecMapPath = "Texture/board.jpg";
    string skeldiffMapPath = "Texture/dskeleton.jpg";
    string skelspecMapPath = "Texture/dskeleton.jpg";
    string carpetdiffMapPath = "Texture/carpet.jpg";
    string carpetspecMapPath = "Texture/carpet.jpg";
    string pavementdiffMapPath = "Texture/greathalldoor.jpg";
    string pavementspecMapPath = "Texture/greathalldoor.jpg";
    string snapediffMapPath = "Texture/snape.jpg";
    string snapespecMapPath = "Texture/snape.jpg";
    string hagriddiffMapPath = "Texture/hagrid.jpg";
    string hagridspecMapPath = "Texture/hagrid.jpg";
    string mineveradiffMapPath = "Texture/miinevera.jpg";
    string mineveraspecMapPath = "Texture/miinevera.jpg";
    string flagdiffMapPath = "Texture/gryf.jpg";
    string flagspecMapPath = "Texture/gryf.jpg";
    string gobletfirediffMapPath = "Texture/gobletfire.jpg";
    string gobletfirespecMapPath = "Texture/gobletfire.jpg";
    string roqdiffMapPath = "Texture/roq.jpg";
    string roqspecMapPath = "Texture/roq.jpg";
    string tiaradiffMapPath = "Texture/tiara.jpg";
    string tiaraspecMapPath = "Texture/tiara.jpg";
    string locketdiffMapPath = "Texture/locket.jpg";
    string locketspecMapPath = "Texture/locket.jpg";
    string sculldiffMapPath = "Texture/scull.jpg";
    string scullspecMapPath = "Texture/scull.jpg";
    string castlediffMapPath = "Texture/castlewall.jpg";
    string castlespecMapPath = "Texture/castlewall.jpg";
    string chotodiffMapPath = "Texture/palace_window.jpg";
    string chotospecMapPath = "Texture/palace_window.jpg";
    string castledoordiffMapPath = "Texture/doorcopy.jpg";
    string castledoorspecMapPath = "Texture/doorcopy.jpg";
    string grassdiffMapPath = "Texture/grass.jpg";
    string grassspecMapPath = "Texture/grass.jpg";


    unsigned int diffMap = loadTexture(diffuseMapPath.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int specMap = loadTexture(specularMapPath.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    //unsigned int woodtablediffMap = loadTexture(woodtablediffMapPath.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    //unsigned int woodtablespecMap = loadTexture(woodtablespecMapPath.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int brickdiffMap = loadTexture(brickdiffMapPath.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int brickspecMap = loadTexture(brickspecMapPath.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int tilesdiffMap = loadTexture(tilesdiffMapPath.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int tilesspecMap = loadTexture(tilesdiffMapPath.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int windowdiffMap = loadTexture(windowdiffMapPath.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int windowdspecMap = loadTexture(windowspecMapPath.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int bedpichondiffMap = loadTexture(bedpichondiffMapPath.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int bedpichonspecMap = loadTexture(bedpichonspecMapPath.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int redsofadiffMap = loadTexture(redsofadiffMapPath.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int redsofaspecMap = loadTexture(redsofaspecMapPath.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int mywindowdiffMap = loadTexture(mywindowdiffMapPath.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int mywindowspecMap = loadTexture(mywindowspecMapPath.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int chairdiffMap = loadTexture(chairiffMapPath.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int chairspecMap = loadTexture(chairspecMapPath.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int frdiffMap = loadTexture(frdiffMapPath.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int frrspecMap = loadTexture(frspecMapPath.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int dumbdiffMap = loadTexture(dumbdiffMapPath.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int dumbspecMap = loadTexture(dumbspecMapPath.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int tablediffMap = loadTexture(tablediffMapPath.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int tablespecMap = loadTexture(tablespecMapPath.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int ttdiffMap = loadTexture(ttdiffMapPath.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int ttspecMap = loadTexture(ttspecMapPath.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int seatdiffMap = loadTexture(seatdiffMapPath.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int seatspecMap = loadTexture(seatspecMapPath.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int glassdiffMap = loadTexture(glassdiffMapPath.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int glassspecMap = loadTexture(glassspecMapPath.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int pdiffMap = loadTexture(pdiffMapPath.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int pspecMap = loadTexture(pspecMapPath.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int doordiffMap = loadTexture(doordiffMapPath.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int doorspecMap = loadTexture(doorspecMapPath.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int boarddiffMap = loadTexture(boarddiffMapPath.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int boardspecMap = loadTexture(boardspecMapPath.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int skeldiffMap = loadTexture(skeldiffMapPath.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int skelspecMap = loadTexture(skelspecMapPath.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int carpetdiffMap = loadTexture(carpetdiffMapPath.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int carpetspecMap = loadTexture(carpetspecMapPath.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int pavementdiffMap = loadTexture(pavementdiffMapPath.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int pavementspecMap = loadTexture(pavementspecMapPath.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int snapediffMap = loadTexture(snapediffMapPath.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int snapespecMap = loadTexture(snapespecMapPath.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int hagriddiffMap = loadTexture(hagriddiffMapPath.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int hagridspecMap = loadTexture(hagridspecMapPath.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int mineveradiffMap = loadTexture(mineveradiffMapPath.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int mineveraspecMap = loadTexture(mineveraspecMapPath.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int flagdiffMap = loadTexture(flagdiffMapPath.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int flagspecMap = loadTexture(flagspecMapPath.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int gobletfirediffMap = loadTexture(gobletfirediffMapPath.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int gobletfirespecMap = loadTexture(gobletfirespecMapPath.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int roqdiffMap = loadTexture(roqdiffMapPath.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int roqspecMap = loadTexture(roqspecMapPath.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int tiaradiffMap = loadTexture(tiaradiffMapPath.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int tiaraspecMap = loadTexture(tiaraspecMapPath.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int locketdiffMap = loadTexture(locketdiffMapPath.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int locketspecMap = loadTexture(locketspecMapPath.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int sculldiffMap = loadTexture(sculldiffMapPath.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int scullspecMap = loadTexture(scullspecMapPath.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int castlediffMap = loadTexture(castlediffMapPath.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int castlespecMap = loadTexture(castlespecMapPath.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int chotodiffMap = loadTexture(chotodiffMapPath.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int chotospecMap = loadTexture(chotospecMapPath.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int castledoordiffMap = loadTexture(castledoordiffMapPath.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int castledoorspecMap = loadTexture(castledoorspecMapPath.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int grassdiffMap = loadTexture(grassdiffMapPath.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int grassspecMap = loadTexture(grassspecMapPath.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);



    //cout<<woodtablediffMap<<endl;
    //cout<<woodtablespecMap<<endl;
    //cout<<brickdiffMap<<endl;
    //cout<<brickspecMap<<endl;
    //cout<<tilesdiffMap<<endl;
    //cout<<tilesspecMap<<endl;
    //cout<<windowdiffMap<<endl;

    Cube cube = Cube(diffMap, specMap, 32.0f, 0.0f, 0.0f, 1.0f, 1.0f);
    
    //////////////////////////////////sphere and cylinder
    Sphere sphere = Sphere();
    Cylinder cylinder = Cylinder();


    //Sphere2  sphere2 = Sphere2(1.0f, 144, 72, glm::vec3(0.898f, 0.459f, 0.125f), glm::vec3(0.898f, 0.459f, 0.125f), glm::vec3(0.5f, 0.5f, 0.5f), 32.0f, skydiffMap, skyspecMap, 0.0f, 0.0f, 1.0f, 1.0f);


    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    //bookshelf er code
    bool firstcall = true;
    for (int i = 0; i < 300; i++)
    {
        colorArray[i] = dis(gen);
    }

    //ourShader.use();
    //lightingShader.use();

    
    float rotate2 = 0.0f;
    float rotate1 = 0.0f;
    float currentRotation = 0.0f;
    float rotationSpeed = 0.5f;


    // render loop
    // -----------
    while (!glfwWindowShouldClose(window))
    {
        
        // per-frame time logic
        // --------------------
        float currentFrame = static_cast<float>(glfwGetTime());
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        // input
        // -----
        processInput(window);

        // render
        // ------
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // be sure to activate shader when setting uniforms/drawing objects
        lightingWithTextureShader.use();
        lightingWithTextureShader.setVec3("viewPos", camera.Position);

        // point light 1
        pointlight1.setUpPointLight(lightingWithTextureShader);
        // point light 2
        pointlight2.setUpPointLight(lightingWithTextureShader);
        // point light 3
        pointlight3.setUpPointLight(lightingWithTextureShader);
        // point light 4
        pointlight4.setUpPointLight(lightingWithTextureShader);
        //5
        pointlight5.setUpPointLight(lightingWithTextureShader);
        pointlight6.setUpPointLight(lightingWithTextureShader);
        pointlight7.setUpPointLight(lightingWithTextureShader);
        pointlight8.setUpPointLight(lightingWithTextureShader);
        pointlight9.setUpPointLight(lightingWithTextureShader);
        pointlight10.setUpPointLight(lightingWithTextureShader);
        pointlight11.setUpPointLight(lightingWithTextureShader);
        pointlight12.setUpPointLight(lightingWithTextureShader);
        pointlight13.setUpPointLight(lightingWithTextureShader);
        pointlight14.setUpPointLight(lightingWithTextureShader);
        pointlight15.setUpPointLight(lightingWithTextureShader);
        pointlight16.setUpPointLight(lightingWithTextureShader);
        pointlight17.setUpPointLight(lightingWithTextureShader);
        pointlight18.setUpPointLight(lightingWithTextureShader);
        pointlight19.setUpPointLight(lightingWithTextureShader);
        pointlight20.setUpPointLight(lightingWithTextureShader);
        pointlight21.setUpPointLight(lightingWithTextureShader);
        pointlight22.setUpPointLight(lightingWithTextureShader);
        pointlight23.setUpPointLight(lightingWithTextureShader);
        pointlight24.setUpPointLight(lightingWithTextureShader);
        pointlight25.setUpPointLight(lightingWithTextureShader);
        pointlight26.setUpPointLight(lightingWithTextureShader);
        pointlight27.setUpPointLight(lightingWithTextureShader);
        pointlight28.setUpPointLight(lightingWithTextureShader);
        pointlight29.setUpPointLight(lightingWithTextureShader);
        pointlight30.setUpPointLight(lightingWithTextureShader);
        pointlight31.setUpPointLight(lightingWithTextureShader);
        pointlight32.setUpPointLight(lightingWithTextureShader);
        pointlight33.setUpPointLight(lightingWithTextureShader);
        pointlight34.setUpPointLight(lightingWithTextureShader);
        pointlight35.setUpPointLight(lightingWithTextureShader);
        pointlight36.setUpPointLight(lightingWithTextureShader);
        pointlight37.setUpPointLight(lightingWithTextureShader);
        pointlight38.setUpPointLight(lightingWithTextureShader);



        dirLight.setUpDirLight(lightingWithTextureShader);
        spotLight.setUpSpotLight(lightingWithTextureShader);

        /*
        lightingShader.setVec3("dirLight.direction", -0.2f, -1.0f, -0.3f);
        lightingShader.setVec3("dirLight.ambient", 0.05f, 0.05f, 0.05f);
        lightingShader.setVec3("dirLight.diffuse", 0.4f, 0.4f, 0.4f);
        lightingShader.setVec3("dirLight.specular", 0.5f, 0.5f, 0.5f);
        */
        // activate shader

        lightingWithTextureShader.use();

        // pass projection matrix to shader (note that in this case it could change every frame)
        glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
        //glm::mat4 projection = glm::ortho(-2.0f, +2.0f, -1.5f, +1.5f, 0.1f, 100.0f);
        lightingWithTextureShader.setMat4("projection", projection);

        // camera/view transformation
        glm::mat4 view = camera.GetViewMatrix();
        //glm::mat4 view = basic_camera.createViewMatrix();
        lightingWithTextureShader.setMat4("view", view);

        // Modelling Transformation
        glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
        glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model, temp,tempx;

        translateMatrix = glm::translate(identityMatrix, glm::vec3(translate_X, translate_Y, translate_Z));
        rotateXMatrix = glm::rotate(identityMatrix, glm::radians(rotateAngle_X), glm::vec3(1.0f, 0.0f, 0.0f));
        rotateYMatrix = glm::rotate(identityMatrix, glm::radians(rotateAngle_Y), glm::vec3(0.0f, 1.0f, 0.0f));
        rotateZMatrix = glm::rotate(identityMatrix, glm::radians(rotateAngle_Z), glm::vec3(0.0f, 0.0f, 1.0f));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(scale_X, scale_Y, scale_Z));
        model = translateMatrix * rotateXMatrix * rotateYMatrix * rotateZMatrix * scaleMatrix;
        temp = model;
        lightingWithTextureShader.setMat4("model", model);

        //glBindVertexArray(cubeVAO);
        //glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
        //glDrawArrays(GL_TRIANGLES, 0, 36);
       // bed(cubeVAO, lightingShader, model); 
       //here the model matrix is the alTogether matrix



        walls(cube, lightingWithTextureShader, model, colorArray,tilesdiffMap,tilesspecMap,doordiffMap,doorspecMap,castlediffMap,castlespecMap,chotodiffMap,chotospecMap,castledoordiffMap,castledoorspecMap,door_ang,door_ang1,grassdiffMap,grassspecMap);

        scaleMatrix = glm::scale(identityMatrix, glm::vec3(.2, 0.2, .2));
        model = model * scaleMatrix;
        bed(cube, lightingWithTextureShader, model, colorArray, tilesdiffMap, tilesspecMap, bedpichondiffMap, bedpichonspecMap,mywindowdiffMap,mywindowspecMap, frdiffMap, frrspecMap,dumbdiffMap,dumbspecMap,tablediffMap,tablespecMap, pdiffMap,pspecMap,doordiffMap,doorspecMap,boarddiffMap,boardspecMap,skeldiffMap,skelspecMap,carpetdiffMap,carpetspecMap,snapediffMap,snapespecMap,hagriddiffMap,hagridspecMap,mineveradiffMap,mineveraspecMap,flagdiffMap,flagspecMap);




        bookShelf(cube, lightingWithTextureShader, model);


         translateMatrix = glm::translate(identityMatrix, glm::vec3(-3.0, translate_Y, translate_Z));

         model = model * translateMatrix;

         sofa(cube, lightingWithTextureShader, model, colorArray, redsofadiffMap, redsofaspecMap);




         translateMatrix = glm::translate(identityMatrix, glm::vec3(-12.0, translate_Y, -20.0f));

         model = model * translateMatrix;
         chair(cube, lightingWithTextureShader, model, colorArray, chairdiffMap, chairspecMap);


         translateMatrix = glm::translate(identityMatrix, glm::vec3(3.0, translate_Y, 15.f));

         model = model * translateMatrix;
         sidedrawer(cube, lightingWithTextureShader, model);

         
         translateMatrix = glm::translate(identityMatrix, glm::vec3(25.0, translate_Y, -6.0));
         model = model * translateMatrix;
         dining(cube, lightingWithTextureShader, model, colorArray,tablediffMap,tablespecMap,ttdiffMap, ttspecMap, seatdiffMap,seatspecMap,redsofadiffMap,redsofaspecMap,glassdiffMap,glassspecMap,frdiffMap, frrspecMap,windowdiffMap, windowdspecMap );

         translateMatrix = glm::translate(identityMatrix, glm::vec3(-45.0, translate_Y, 0.0));
         scaleMatrix = glm::scale(identityMatrix, glm::vec3(4.0, 3.0, 1.0));
         model = model *scaleMatrix* translateMatrix;
         library(cube, lightingWithTextureShader, model, colorArray, tilesdiffMap, tilesspecMap);

         translateMatrix = glm::translate(identityMatrix, glm::vec3(65.0, translate_Y, 0.0));
         scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.0, 1.0, 1.0));
         model = model * scaleMatrix * translateMatrix;
         goblet(cube, lightingWithTextureShader, model, colorArray,gobletfirediffMap,gobletfirespecMap,tablediffMap,tablespecMap,roqdiffMap,roqspecMap,tiaradiffMap, tiaraspecMap,carpetdiffMap,carpetspecMap,locketdiffMap,locketspecMap);



         /*translateMatrix = glm::translate(identityMatrix, glm::vec3(-22.0, 0.0, 265.0));
         scaleMatrix = glm::scale(identityMatrix, glm::vec3(2.5, 2.0, 1.0));
         model = model * scaleMatrix * translateMatrix;
         mainstairCase(cube, lightingWithTextureShader, model);

         */

         //////////staircase
            /*
             temp = model;
             translateMatrix = glm::translate(identityMatrix, glm::vec3(-40.0, 0.0, 195.0));
             scaleMatrix = glm::scale(identityMatrix, glm::vec3(2.0, 2.0, 1.0));
             rotateYMatrix = glm::rotate(identityMatrix, glm::radians(rotate1), glm::vec3(0.0f, 1.0f, 0.0f));
             model = model *translateMatrix*scaleMatrix* rotateYMatrix;
             mainstairCase(cube, lightingWithTextureShader, model);
             rotate1 = rotate1 + 0.5f;
             model = temp;

             */


             ////////////stairecase
             tempx = model;
             //////////staircase
             {
                 //////////staircase
                 {
                     temp = model;
                     translateMatrix = glm::translate(identityMatrix, glm::vec3(-37.0, 0.0, 195.0));
                     scaleMatrix = glm::scale(identityMatrix, glm::vec3(2.0, 3.0, 1.0));
                     if (rotate1 < 360.0f) {
                         rotateYMatrix = glm::rotate(identityMatrix, glm::radians(currentRotation), glm::vec3(0.0f, 1.0f, 0.0f));
                         currentRotation += rotationSpeed;
                         rotate1 = rotate1 + 1.0f;
                         cout << rotate1 << endl;
                     }
                     else if (rotate1 >= 360.0f && rotate1 <= 720.0f) {
                         rotateYMatrix = glm::rotate(identityMatrix, glm::radians(currentRotation), glm::vec3(0.0f, 1.0f, 0.0f));
                         currentRotation -= rotationSpeed;
                         rotate1 = rotate1 + 1.0f;
                         cout << rotate1 << endl;
                     }
                     if (rotate1 > 720.0f) {
                         rotate1 = 0.0f;
                     }
                     model = model *translateMatrix*scaleMatrix* rotateYMatrix;
                     mainstairCase(cube, lightingWithTextureShader, model);

                     model = temp;
                 }
             }
             model = tempx;
         

      /////
             temp = model;
             //translateMatrix = glm::translate(identityMatrix, glm::vec3(-40.0, 0.0, 195.0));
             //scaleMatrix = glm::scale(identityMatrix, glm::vec3(2.0, 2.0, 1.0));
             rotateYMatrix = glm::rotate(identityMatrix, glm::radians(rotate2), glm::vec3(0.0f, 1.0f, 0.0f));
             model = model* rotateYMatrix;
             jharbati(cube, lightingWithTextureShader, model);
             rotate2 = rotate2 + 0.5f;
             model = temp;



             //translateMatrix = glm::translate(identityMatrix, glm::vec3(-5.0, 0.5, 360.0));
             //scaleMatrix = glm::scale(identityMatrix, glm::vec3(5.0, 15.0, 1.0));
             //model = model * scaleMatrix * translateMatrix;
             //gate(cube, lightingWithTextureShader, model);
        
     /////
             temp = model;
             translateMatrix = glm::translate(identityMatrix, glm::vec3(-6.0, 6.0, 175));
             scaleMatrix = glm::scale(identityMatrix, glm::vec3(.7, .7, 1.0));
             rotateYMatrix = glm::rotate(identityMatrix, glm::radians(rotate2), glm::vec3(0.0f, 1.0f, 0.0f));
             model = model *translateMatrix* scaleMatrix*rotateYMatrix;
             scull(cube, lightingWithTextureShader, model);
             rotate2 = rotate2 + 0.5f;
             model = temp;

             temp = model;
             translateMatrix = glm::translate(identityMatrix, glm::vec3(-60.0, 6.0, 175));
             scaleMatrix = glm::scale(identityMatrix, glm::vec3(.7, .7, 1.0));
             rotateYMatrix = glm::rotate(identityMatrix, glm::radians(rotate2), glm::vec3(0.0f, 1.0f, 0.0f));
             model = model * translateMatrix * scaleMatrix * rotateYMatrix;
             scull(cube, lightingWithTextureShader, model);
             rotate2 = rotate2 + 0.5f;
             model = temp;
             


             temp = model;
             translateMatrix = glm::translate(identityMatrix, glm::vec3(-65.0, 6.0, 25));
             scaleMatrix = glm::scale(identityMatrix, glm::vec3(.7, .7, 1.0));
             rotateYMatrix = glm::rotate(identityMatrix, glm::radians(rotate2), glm::vec3(0.0f, 1.0f, 0.0f));
             model = model * translateMatrix * scaleMatrix * rotateYMatrix;
             scull(cube, lightingWithTextureShader, model);
             rotate2 = rotate2 + 0.5f;
             model = temp;


             temp = model;
             translateMatrix = glm::translate(identityMatrix, glm::vec3(-48.0, 22.0, 50));
             scaleMatrix = glm::scale(identityMatrix, glm::vec3(2.8, 2.8, 1.5));
             rotateYMatrix = glm::rotate(identityMatrix, glm::radians(rotate2), glm::vec3(0.0f, 1.0f, 0.0f));
             model = model * translateMatrix * scaleMatrix*rotateYMatrix;
             broom(cube, lightingWithTextureShader, model);
             rotate2 = rotate2 + 3.5f;
             model = temp;

             




        glm::mat4 translate = glm::mat4(1.0f);
        glm::mat4 translate2 = glm::mat4(1.0f);
        glm::mat4 scale = glm::mat4(1.0f);
        glm::mat4 rotateY = glm::mat4(1.0f);
        
        // also draw the lamp object(s)
        ourShader.use();
        ourShader.setMat4("projection", projection);
        ourShader.setMat4("view", view);

        // we now draw as many light bulbs as we have point lights.
        for (unsigned int i = 0; i < 22; i++)
        {
            model = glm::mat4(1.0f);
            model = glm::translate(model, pointLightPositions[i]);
            model = glm::scale(model, glm::vec3(0.5f)); // Make it a smaller cube
            cube.drawCube(ourShader, model, 0.8f, 0.8f, 0.8f);
        }
            
        //}

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // optional: de-allocate all resources once they've outlived their purpose:
    // ------------------------------------------------------------------------
    //glDeleteVertexArrays(1, &cubeVAO);
    //glDeleteVertexArrays(1, &lightCubeVAO);
    //glDeleteBuffers(1, &cubeVBO);
    //glDeleteBuffers(1, &cubeEBO);
    //delete cube;

    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();
    return 0;
}




// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
        camera.ProcessKeyboard(FORWARD, deltaTime);
    }
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
        camera.ProcessKeyboard(BACKWARD, deltaTime);
    }
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
        camera.ProcessKeyboard(LEFT, deltaTime);
    }
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
        camera.ProcessKeyboard(RIGHT, deltaTime);
    }

    if (glfwGetKey(window, GLFW_KEY_I) == GLFW_PRESS) {
        camera.ProcessKeyboard(UP, deltaTime);
    }
    if (glfwGetKey(window, GLFW_KEY_K) == GLFW_PRESS) {
        camera.ProcessKeyboard(DOWN, deltaTime);
    }

    if (glfwGetKey(window, GLFW_KEY_K) == GLFW_PRESS)
    {
        if (rotateAxis_X) rotateAngle_X -= 0.1;
        else if (rotateAxis_Y) rotateAngle_Y -= 0.1;
        else rotateAngle_Z -= 0.1;
    }
    if (glfwGetKey(window, GLFW_KEY_N) == GLFW_PRESS)
    {

        if (door_ang == 0.0f) {
            door_ang = 90.0f;
        }

    }
    if (glfwGetKey(window, GLFW_KEY_M) == GLFW_PRESS)
    {
        if (door_ang == 90.0f) {
            door_ang = 0.0f;
        }
    }

    if (glfwGetKey(window, GLFW_KEY_C) == GLFW_PRESS)
    {

        if (door_ang1 == 0.0f) {
            door_ang1 = 160.0f;
        }

    }
    if (glfwGetKey(window, GLFW_KEY_V) == GLFW_PRESS)
    {
        if (door_ang1 == 160.0f) {
            door_ang1 = 0.0f;
        }
    }


    //if (glfwGetKey(window, GLFW_KEY_I) == GLFW_PRESS) translate_Y += 0.001;
    //if (glfwGetKey(window, GLFW_KEY_K) == GLFW_PRESS) translate_Y -= 0.001;
    //if (glfwGetKey(window, GLFW_KEY_L) == GLFW_PRESS) translate_X += 0.001;
    //if (glfwGetKey(window, GLFW_KEY_J) == GLFW_PRESS) translate_X -= 0.001;
    //if (glfwGetKey(window, GLFW_KEY_O) == GLFW_PRESS) translate_Z += 0.001;
    //if (glfwGetKey(window, GLFW_KEY_P) == GLFW_PRESS) translate_Z -= 0.001;
    //if (glfwGetKey(window, GLFW_KEY_C) == GLFW_PRESS) scale_X += 0.001;
    //if (glfwGetKey(window, GLFW_KEY_V) == GLFW_PRESS) scale_X -= 0.001;
    //if (glfwGetKey(window, GLFW_KEY_B) == GLFW_PRESS) scale_Y += 0.001;
    //if (glfwGetKey(window, GLFW_KEY_N) == GLFW_PRESS) scale_Y -= 0.001;
    //if (glfwGetKey(window, GLFW_KEY_M) == GLFW_PRESS) scale_Z += 0.001;
    //if (glfwGetKey(window, GLFW_KEY_U) == GLFW_PRESS) scale_Z -= 0.001;

    if (glfwGetKey(window, GLFW_KEY_X) == GLFW_PRESS)
    {
        rotateAngle_X += 0.1;
        rotateAxis_X = 1.0;
        rotateAxis_Y = 0.0;
        rotateAxis_Z = 0.0;
    }
    if (glfwGetKey(window, GLFW_KEY_Y) == GLFW_PRESS)
    {
        rotateAngle_Y += 0.1;
        rotateAxis_X = 0.0;
        rotateAxis_Y = 1.0;
        rotateAxis_Z = 0.0;
    }
    if (glfwGetKey(window, GLFW_KEY_Z) == GLFW_PRESS)
    {
        rotateAngle_Z += 0.1;
        rotateAxis_X = 0.0;
        rotateAxis_Y = 0.0;
        rotateAxis_Z = 1.0;
    }

    if (glfwGetKey(window, GLFW_KEY_H) == GLFW_PRESS)
    {
        eyeX += 2.5 * deltaTime;
        basic_camera.changeEye(eyeX, eyeY, eyeZ);
    }
    if (glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS)
    {
        eyeX -= 2.5 * deltaTime;
        basic_camera.changeEye(eyeX, eyeY, eyeZ);
    }
    if (glfwGetKey(window, GLFW_KEY_T) == GLFW_PRESS)
    {
        eyeZ += 2.5 * deltaTime;
        basic_camera.changeEye(eyeX, eyeY, eyeZ);
    }
    if (glfwGetKey(window, GLFW_KEY_G) == GLFW_PRESS)
    {
        eyeZ -= 2.5 * deltaTime;
        basic_camera.changeEye(eyeX, eyeY, eyeZ);
    }
    if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
    {
        eyeY += 2.5 * deltaTime;
        basic_camera.changeEye(eyeX, eyeY, eyeZ);
    }
    if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
    {
        eyeY -= 2.5 * deltaTime;
        basic_camera.changeEye(eyeX, eyeY, eyeZ);
    }
    if (glfwGetKey(window, GLFW_KEY_1) == GLFW_PRESS)
    {
        pointlight1.turnOn();
        pointlight2.turnOn();
        pointlight3.turnOn();
        pointlight4.turnOn();
        pointlight5.turnOn();
        pointlight6.turnOn();
        pointlight7.turnOn();
        pointlight8.turnOn();
        pointlight9.turnOn();
        pointlight10.turnOn();
        pointlight11.turnOn();
        pointlight12.turnOn();
        pointlight13.turnOn();
        pointlight14.turnOn();
        pointlight15.turnOn();
        pointlight16.turnOn();
        pointlight17.turnOn();
        pointlight18.turnOn();
        pointlight19.turnOn();
        pointlight20.turnOn();
        pointlight21.turnOn();
        pointlight22.turnOn();
        pointlight23.turnOn();
        pointlight24.turnOn();
        pointlight25.turnOn();
        pointlight26.turnOn();
        pointlight27.turnOn();
        pointlight28.turnOn();
        pointlight29.turnOn();
        pointlight30.turnOn();
        pointlight31.turnOn();
        pointlight32.turnOn();
        pointlight33.turnOn();
        pointlight34.turnOn();
        pointlight35.turnOn();
        pointlight36.turnOn();
        pointlight37.turnOn();
        pointlight38.turnOn();
    }
    if (glfwGetKey(window, GLFW_KEY_2) == GLFW_PRESS)
    {
        pointlight1.turnOff();
        pointlight2.turnOff();
        pointlight3.turnOff();
        pointlight4.turnOff();
        pointlight5.turnOff();
        pointlight6.turnOff();
        pointlight7.turnOff();
        pointlight8.turnOff();
        pointlight9.turnOff();
        pointlight10.turnOff();
        pointlight11.turnOff();
        pointlight12.turnOff();
        pointlight13.turnOff();
        pointlight14.turnOff();
        pointlight15.turnOff();
        pointlight16.turnOff();
        pointlight17.turnOff();
        pointlight18.turnOff();
        pointlight19.turnOff();
        pointlight20.turnOff();
        pointlight21.turnOff();
        pointlight22.turnOff();
        pointlight23.turnOff();
        pointlight24.turnOff();
        pointlight25.turnOff();
        pointlight26.turnOff();
        pointlight27.turnOff();
        pointlight28.turnOff();
        pointlight29.turnOff();
        pointlight30.turnOff();
        pointlight31.turnOff();
        pointlight32.turnOff();
        pointlight33.turnOff();
        pointlight34.turnOff();
        pointlight35.turnOff();
        pointlight36.turnOff();
        pointlight37.turnOff();
        pointlight38.turnOff();

    }
    if (glfwGetKey(window, GLFW_KEY_7) == GLFW_PRESS)
    {
        pointlight1.turnDiffuseOn();
        pointlight3.turnDiffuseOn();
        spotLight.turnDiffuseOn();
        dirLight.turnDiffuseOn();

    }
    if (glfwGetKey(window, GLFW_KEY_8) == GLFW_PRESS)
    {

        pointlight1.turnOff();
        pointlight3.turnOff();
        dirLight.turnOff();
        spotLight.turnOff();

    }

    if (glfwGetKey(window, GLFW_KEY_3) == GLFW_PRESS)
    {
        dirLight.turnOn();

    }
    if (glfwGetKey(window, GLFW_KEY_4) == GLFW_PRESS)
    {
        dirLight.turnOff();
    }
    if (glfwGetKey(window, GLFW_KEY_5) == GLFW_PRESS)
    {
        spotLight.turnOn();

    }
    if (glfwGetKey(window, GLFW_KEY_6) == GLFW_PRESS)
    {
        spotLight.turnOff();
    }
    if (glfwGetKey(window, GLFW_KEY_9) == GLFW_PRESS)
    {
        pointlight1.turnAmbientOn();
        pointlight2.turnAmbientOn();
        pointlight3.turnAmbientOn();
        pointlight4.turnAmbientOn();
        pointlight5.turnAmbientOn();
        pointlight6.turnAmbientOn();
        pointlight7.turnAmbientOn();
        pointlight8.turnAmbientOn();
        pointlight9.turnAmbientOn();
        pointlight10.turnAmbientOn();
        pointlight11.turnAmbientOn();
        pointlight12.turnAmbientOn();
        pointlight13.turnAmbientOn();
        pointlight14.turnAmbientOn();
        pointlight15.turnAmbientOn();
        pointlight16.turnAmbientOn();
        pointlight17.turnAmbientOn();
        pointlight18.turnAmbientOn();
        pointlight19.turnAmbientOn();
        pointlight20.turnAmbientOn();
        pointlight21.turnAmbientOn();
        pointlight22.turnAmbientOn();
        pointlight23.turnAmbientOn();
        pointlight24.turnAmbientOn();
        pointlight25.turnAmbientOn();
        pointlight26.turnAmbientOn();
        pointlight27.turnAmbientOn();
        pointlight28.turnAmbientOn();
        pointlight29.turnAmbientOn();
        pointlight30.turnAmbientOn();
        pointlight31.turnAmbientOn();
        pointlight32.turnAmbientOn();
        pointlight33.turnAmbientOn();
        pointlight34.turnAmbientOn();
        pointlight35.turnAmbientOn();
        pointlight36.turnAmbientOn();
        pointlight37.turnAmbientOn();
        pointlight38.turnAmbientOn();
        spotLight.turnAmbientOn();
        dirLight.turnAmbientOn();
    }
    if (glfwGetKey(window, GLFW_KEY_0) == GLFW_PRESS)
    {
        pointlight1.turnSpecularOn();
        pointlight2.turnSpecularOn();
        pointlight3.turnSpecularOn();
        pointlight4.turnSpecularOn();
        pointlight5.turnSpecularOn();
        pointlight6.turnSpecularOn();
        pointlight7.turnSpecularOn();
        pointlight8.turnSpecularOn();
        pointlight9.turnSpecularOn();
        pointlight10.turnSpecularOn();
        pointlight11.turnSpecularOn();
        pointlight12.turnSpecularOn();
        pointlight13.turnSpecularOn();
        pointlight14.turnSpecularOn();
        pointlight15.turnSpecularOn();
        pointlight16.turnSpecularOn();
        spotLight.turnSpecularOn();
        dirLight.turnSpecularOn();
    }






}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}

unsigned int loadTexture(char const* path, GLenum textureWrappingModeS, GLenum textureWrappingModeT, GLenum textureFilteringModeMin, GLenum textureFilteringModeMax)
{
    unsigned int textureID;
    glGenTextures(1, &textureID);

    int width, height, nrComponents;
    stbi_set_flip_vertically_on_load(true);
    unsigned char* data = stbi_load(path, &width, &height, &nrComponents, 0);
    if (data)
    {
        GLenum format;
        if (nrComponents == 1)
            format = GL_RED;
        else if (nrComponents == 3)
            format = GL_RGB;
        else if (nrComponents == 4)
            format = GL_RGBA;

        glBindTexture(GL_TEXTURE_2D, textureID);
        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, textureWrappingModeS);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, textureWrappingModeT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, textureFilteringModeMin);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, textureFilteringModeMax);

        stbi_image_free(data);
    }
    else
    {
        std::cout << "Texture failed to load at path: " << path << std::endl;
        assert(false); //fail the code
        stbi_image_free(data);
    }

    return textureID;
}

// glfw: whenever the mouse moves, this callback is called
// -------------------------------------------------------
void mouse_callback(GLFWwindow* window, double xposIn, double yposIn)
{
    float xpos = static_cast<float>(xposIn);
    float ypos = static_cast<float>(yposIn);
    //float zpos = static_cast<float>(zposIn);

    if (firstMouse)
    {
        lastX = xpos;
        lastY = ypos;
        //lastZ = zpos;
        firstMouse = false;
    }

    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top
    //float zoffset = lastZ - zpos;

    lastX = xpos;
    lastY = ypos;
    //lastZ = zpos;   

    camera.ProcessMouseMovement(xoffset, yoffset);
}

// glfw: whenever the mouse scroll wheel scrolls, this callback is called
// ----------------------------------------------------------------------
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
    camera.ProcessMouseScroll(static_cast<float>(yoffset));
}
