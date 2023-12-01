#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "shader.h"
#include "drawcube.h"
#include "cube.h"
#include "triangle.h"
#include "pyramid.h"
#include "cylinder.h"
#include "torus.h"
//#include "sphere2.h"


void walls(Cube& cube, Shader& lightingShader, glm::mat4 alTogether, float colorArray[], unsigned int tiles1, unsigned int tiles2, unsigned int gt1, unsigned int gt2, unsigned int cas1, unsigned int cas2,unsigned int choto1, unsigned int choto2,unsigned int casdoor1, unsigned int casdoor2,float door_ang, float door_ang1,unsigned int grass1, unsigned int grass2)
{

    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model,temp;

    /*//floor
    translateMatrix = glm::translate(identityMatrix, glm::vec3(-48.5, -0.5, -6.5));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(82, .5, 68.0));
    model = alTogether * translateMatrix * scaleMatrix;
    //drawCube(cubeVAO, lightingShader, model, 0.545f, 0.271f, 0.075f);
    cube.setMaterialisticEimu(0.545f, 0.271f, 0.075f);
    //cube.setTextureProperty(cas1, cas2, 32.0);
    cube.drawCubeWithMaterialisticProperty(lightingShader, model);
    */
      
    


    //back wall
    translateMatrix = glm::translate(identityMatrix, glm::vec3(-48.5, -0.5, -6.5));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(82, 26, 0.25));
    model = alTogether * translateMatrix * scaleMatrix;
    //drawCube(cubeVAO, lightingShader, model, 0.58f, 0, 0.137f);
    cube.setTextureProperty(tiles1, tiles2, 32.0);
    cube.drawCubeWithTexture(lightingShader, model);
    
   /*  ////////////////front wall of dining
    translateMatrix = glm::translate(identityMatrix, glm::vec3(1.5, -0.45, 11));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(11, 7, 0.25));
    model = alTogether * translateMatrix * scaleMatrix;
    //drawCube(cubeVAO, lightingShader, model, 0.6, 0.0f, 0.125f);
    cube.setTextureProperty(tiles1, tiles2, 32.0);
    cube.drawCubeWithTexture(lightingShader, model);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0, -0.45, 11.2));

    scaleMatrix = glm::scale(identityMatrix, glm::vec3(3, 6.4, 0.15));
    model = alTogether * translateMatrix * scaleMatrix;
    //drawCube(cubeVAO, lightingShader, model, 0.6, 0.0f, 0.125f);
    cube.setTextureProperty(gt1, gt2, 32.0);
    cube.drawCubeWithTexture(lightingShader, model);

    */

    /*
    //left wall
    translateMatrix = glm::translate(identityMatrix, glm::vec3(6, -0.45, -6.5));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.25, 8, 25));
    model = alTogether * translateMatrix * scaleMatrix;
    drawCube(cubeVAO, lightingShader, model, 0.6, 0.0f, 0.125f);
    */

    //uporer talar right e wall
    translateMatrix = glm::translate(identityMatrix, glm::vec3(33.5, 6.4 - 0.5, -6.5));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.25, 21, 67));
    model = alTogether * translateMatrix * scaleMatrix;
    //drawCube(cubeVAO, lightingShader, model, 0.098f, 0.098f, 0.439f);
    //cube.drawCubeWithMaterialisticProperty(lightingShader, model);
    //cube.setMaterialisticEimu(0.58f, 0, 0.137f);
    //cube.drawCubeWithMaterialisticProperty(lightingShader, model);
    cube.setTextureProperty(tiles1, tiles2, 32.0);
    cube.drawCubeWithTexture(lightingShader, model);

    //uporer talar lefttttttt e wall
    translateMatrix = glm::translate(identityMatrix, glm::vec3(-48.5, 6.7, -6.5));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.25, 19.5, 66));
    model = alTogether * translateMatrix * scaleMatrix;
    //drawCube(cubeVAO, lightingShader, model, 0.098f, 0.098f, 0.439f);
    //cube.drawCubeWithMaterialisticProperty(lightingShader, model);
    //cube.setMaterialisticEimu(0.58f, 0, 0.137f);
    //cube.drawCubeWithMaterialisticProperty(lightingShader, model);
    cube.setTextureProperty(tiles1, tiles2, 32.0);
    cube.drawCubeWithTexture(lightingShader, model);

    //right wall
    translateMatrix = glm::translate(identityMatrix, glm::vec3(-6.5, -0.45, 6));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.25, 26, -13));
    model = alTogether * translateMatrix * scaleMatrix;
    //drawCube(cubeVAO, lightingShader, model, 0.58f, 0, 0.137f);
    //cube.drawCubeWithMaterialisticProperty(lightingShader, model);
    cube.setTextureProperty(tiles1, tiles2, 32.0);
    cube.drawCubeWithTexture(lightingShader, model);

    //right wall( nichtalar ekdom left)
    translateMatrix = glm::translate(identityMatrix, glm::vec3(-48.4, -0.45, 66));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.25, 26, -74));
    model = alTogether * translateMatrix * scaleMatrix;
    //drawCube(cubeVAO, lightingShader, model, 0.58f, 0, 0.137f);
    //cube.drawCubeWithMaterialisticProperty(lightingShader, model);
    cube.setTextureProperty(tiles1, tiles2, 32.0);
    cube.drawCubeWithTexture(lightingShader, model);


    //uporer talay left wall
    translateMatrix = glm::translate(identityMatrix, glm::vec3(-6.5, 6.7, 3));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.25, 18, 25));
    model = alTogether * translateMatrix * scaleMatrix;
    //drawCube(cubeVAO, lightingShader, model, 0.58f, 0, 0.137f);
    //cube.drawCubeWithMaterialisticProperty(lightingShader, model);
    cube.setTextureProperty(tiles1, tiles2, 32.0);
    cube.drawCubeWithTexture(lightingShader, model);

    //arekta right wall
    translateMatrix = glm::translate(identityMatrix, glm::vec3(-25.5, -0.45, 6));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.25, 8, -25));
    model = alTogether * translateMatrix * scaleMatrix;
    //drawCube(cubeVAO, lightingShader, model, 0.58f, 0, 0.137f);
    cube.setTextureProperty(tiles1, tiles2, 32.0);
    cube.drawCubeWithTexture(lightingShader, model);

    
    //uporer talar ceiling
    translateMatrix = glm::translate(identityMatrix, glm::vec3(-48.5, 25.4 - 0.5, -6.5));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(82, .9, 35.0));
    model = alTogether * translateMatrix * scaleMatrix;
    //drawCube(cubeVAO, lightingShader, model, 0.098f, 0.098f, 0.439f);
    //cube.drawCubeWithMaterialisticProperty(lightingShader, model);
    //cube.setMaterialisticEimu(0.58f, 0, 0.137f);
    //cube.drawCubeWithMaterialisticProperty(lightingShader, model);
    cube.setTextureProperty(tiles1, tiles2, 32.0);
    cube.drawCubeWithTexture(lightingShader, model);

    //uporer talar floor
    translateMatrix = glm::translate(identityMatrix, glm::vec3(-48.5, 6.4 - 0.5, -6.5));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(82, 1.0, 35.0));
    model = alTogether * translateMatrix * scaleMatrix;
    //drawCube(cubeVAO, lightingShader, model, 0.098f, 0.098f, 0.439f);
    //cube.drawCubeWithMaterialisticProperty(lightingShader, model);
    //cube.setMaterialisticEimu(0.58f, 0, 0.137f);
    //cube.drawCubeWithMaterialisticProperty(lightingShader, model);
    cube.setTextureProperty(tiles1, tiles2, 32.0);
    cube.drawCubeWithTexture(lightingShader, model);


   /* //ceiling
    translateMatrix = glm::translate(identityMatrix, glm::vec3(-26.5, 6 - 0.5, -6.5));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(45, .5, 25));
    model = alTogether * translateMatrix * scaleMatrix;
    //drawCube(cubeVAO, lightingShader, model, 0.098f, 0.098f, 0.439f);
    //cube.drawCubeWithMaterialisticProperty(lightingShader, model);
    cube.setMaterialisticEimu(0.6471f, 0.1647f, 0.1647f);
    cube.drawCubeWithMaterialisticProperty(lightingShader, model);
    */
    


    


    //left wall
    translateMatrix = glm::translate(identityMatrix, glm::vec3(12.7, -0.45, -6.5));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.25, 8, 10));
    model = alTogether * translateMatrix * scaleMatrix;
    //drawCube(cubeVAO, lightingShader, model, 0.58f, 0, 0.137f);
    cube.setTextureProperty(tiles1, tiles2, 32.0);
    cube.drawCubeWithTexture(lightingShader, model);


    //left wall( ekdom laster right wall ashole)
    translateMatrix = glm::translate(identityMatrix, glm::vec3(33.3, -0.1, -6.5));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.25, 8.2, 67));
    model = alTogether * translateMatrix * scaleMatrix;
    //drawCube(cubeVAO, lightingShader, model, 0.58f, 0, 0.137f);
    cube.setTextureProperty(tiles1, tiles2, 32.0);
    cube.drawCubeWithTexture(lightingShader, model);

 

    //front face of palace left
    translateMatrix = glm::translate(identityMatrix, glm::vec3(-47.8, 0.05, 66));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(30, 25.2, 0.5));
    model = alTogether * translateMatrix * scaleMatrix;
    //drawCube(cubeVAO, lightingShader, model, 0.6, 0.0f, 0.125f);
    cube.setTextureProperty(cas1, cas2, 32.0);
    cube.drawCubeWithTexture(lightingShader, model);

    //chotochoto
   
    for (int i = 0; i < 8; ++i) {
        temp = alTogether;

        translateMatrix = glm::translate(identityMatrix, glm::vec3(-47.8 + i * 4.0, 25.3, 66));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(2.0, 2.2, 0.5));
        model = temp * translateMatrix * scaleMatrix;

        cube.setTextureProperty(cas1, cas2, 32.0);
        cube.drawCubeWithTexture(lightingShader, model);
    }




    //lrft deyale window1
    for (int i = 0; i < 3; ++i) {
        temp = alTogether;

        translateMatrix = glm::translate(identityMatrix, glm::vec3(-47.8 + i * 10.0, 9.5, 66.9));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(7.0, 7.5, 0.1));
        model = temp * translateMatrix * scaleMatrix;

        cube.setTextureProperty(choto1, choto2, 32.0);
        cube.drawCubeWithTexture(lightingShader, model);
    }


    //front face of palace right
    translateMatrix = glm::translate(identityMatrix, glm::vec3(34.4, 0.05, 66));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(-29, 25.2, 0.5));
    model = alTogether * translateMatrix * scaleMatrix;
    //drawCube(cubeVAO, lightingShader, model, 0.6, 0.0f, 0.125f);
    cube.setTextureProperty(cas1, cas2, 32.0);
    cube.drawCubeWithTexture(lightingShader, model);


    ///right janlas
    for (int i = 0; i < 3; ++i) {
        temp = alTogether;

        translateMatrix = glm::translate(identityMatrix, glm::vec3(5.8 + i * 10.0, 9.5, 66.9));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(7.0, 7.5, 0.1));
        model = temp * translateMatrix * scaleMatrix;

        cube.setTextureProperty(choto1, choto2, 32.0);
        cube.drawCubeWithTexture(lightingShader, model);
    }

    for (int i = 0; i < 8; ++i) {
        temp = alTogether;

        translateMatrix = glm::translate(identityMatrix, glm::vec3(5.4 + i * 3.8, 25.3, 66));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(2.0, 2.2, 0.5));
        model = temp * translateMatrix * scaleMatrix;

        cube.setTextureProperty(cas1, cas2, 32.0);
        cube.drawCubeWithTexture(lightingShader, model);
    }
    
    //gate1
    translateMatrix = glm::translate(identityMatrix, glm::vec3(-18.0, 0.05, 66.00));
    rotateYMatrix = glm::rotate(identityMatrix, glm::radians(door_ang), glm::vec3(0.0f, 1.0f, 0.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(11.4f, 25.2f, .5f));
    model = alTogether * translateMatrix *rotateYMatrix * scaleMatrix;
    //drawCube(cubeVAO, lightingShader, model, 0.502f, 0, 0);
    //cube.setMaterialisticEimu(0.545f, 0.270f, 0.075f);
    //cube.drawCubeWithMaterialisticProperty(lightingShader, model);
    cube.setTextureProperty(casdoor1, casdoor2, 32.0);
    cube.drawCubeWithTexture(lightingShader, model);


    for (int i = 0; i < 5; ++i) {
        glm::mat4 temp = alTogether;

        // Spikes
        translateMatrix = glm::translate(identityMatrix, glm::vec3(-17.0 + i * 5, 25.21, 66.00));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(.6f, 2.6f, .1f));
        model = temp * translateMatrix * scaleMatrix;
        cube.setTextureProperty(cas1, cas2, 32.0);
        cube.drawCubeWithTexture(lightingShader, model);

        // Triangle
        translateMatrix = glm::translate(identityMatrix, glm::vec3(-16.6 + i * 5, 28.3 + 0.15, 66.5));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(2.5f, 2.2f, .1f));
        model = temp * translateMatrix * scaleMatrix;
        Triangle triangle = Triangle();
        triangle.drawTriangle(lightingShader, model, 0.0f, 0.0f, 0.0f);
    }

    



    //gate2
    translateMatrix = glm::translate(identityMatrix, glm::vec3(-5.9, 0.05, 66.00));
    //rotateXMatrix = glm::rotate(identityMatrix, glm::radians(-90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    rotateYMatrix = glm::rotate(identityMatrix, glm::radians(-door_ang), glm::vec3(0.0f, 1.0f, 0.0f));
    //rotateYMatrix = glm::rotate(identityMatrix, glm::radians(180.0f + door_ang1), glm::vec3(0.0, 1.0, 0.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(11.4f, 25.2f, .5f));
    //translateMatrix = glm::translate(identityMatrix, glm::vec3(5.9, 0.05, 66.00));

    model = alTogether * translateMatrix *rotateYMatrix * scaleMatrix;
    //drawCube(cubeVAO, lightingShader, model, 0.502f, 0, 0);
    //cube.setMaterialisticEimu(0.545f, 0.270f, 0.075f);
    //cube.drawCubeWithMaterialisticProperty(lightingShader, model);
    cube.setTextureProperty(casdoor1, casdoor2, 32.0);
    cube.drawCubeWithTexture(lightingShader, model);

    



   

    for (int i = 0; i < 4; ++i) {
        glm::mat4 temp = alTogether;

        // Cylinder pillar
        translateMatrix = glm::translate(identityMatrix, glm::vec3(46.0, 18.05, 56 - i * 20));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(7.5f, 20.6f, 6.1f));
        model = temp * translateMatrix * scaleMatrix;

        // Draw the cylinder for each pillar
        Cylinder cylinder = Cylinder();
        cylinder.drawCylinder(lightingShader, model, 0.6, 0.3f, 0.125f);

        temp = alTogether;

        translateMatrix = glm::translate(identityMatrix, glm::vec3(38.8, 23.5, 66.0-i*20));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(7.0, 7.5, 0.1));
        model = temp * translateMatrix * scaleMatrix;

        cube.setTextureProperty(choto1, choto2, 32.0);
        cube.drawCubeWithTexture(lightingShader, model);

        // Torus
        translateMatrix = glm::translate(identityMatrix, glm::vec3(46.0, 40.6, 56 - i * 20));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(4.5f, 3.5f, 1.6f));
        model = temp * translateMatrix * scaleMatrix;

        // Draw the torus for each pillar
        Torus torus = Torus();
        torus.drawTorus(lightingShader, model, 0.6, 0.3f, 0.125f);

        // Pyramid
        glm::mat4 pyramidTransform = glm::mat4(1.0f);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(42.4, 41.95, 64 - i * 20));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(15.0, 15.2, 5.5));
        pyramidTransform = temp * translateMatrix * scaleMatrix;

        // Create a Pyramid instance
        Pyramid pyramid(pyramidTransform, "Texture/castlewall.jpg");
        pyramid.draw(lightingShader);
    }



    for (int i = 0; i < 4; ++i) {
        glm::mat4 temp = alTogether;

        // Cylinder pillar
        translateMatrix = glm::translate(identityMatrix, glm::vec3(-59.0, 18.05, 56 - i * 20));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(7.5f, 20.6f, 6.1f));
        model = temp * translateMatrix * scaleMatrix;

        // Draw the cylinder for each pillar
        Cylinder cylinder = Cylinder();
        cylinder.drawCylinder(lightingShader, model, 0.6, 0.3f, 0.125f);



        temp = alTogether;

        translateMatrix = glm::translate(identityMatrix, glm::vec3(-57.8, 23.5, 66.0 - i * 20));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(7.0, 7.5, 0.1));
        model = temp * translateMatrix * scaleMatrix;

        cube.setTextureProperty(choto1, choto2, 32.0);
        cube.drawCubeWithTexture(lightingShader, model);


        // Torus
        translateMatrix = glm::translate(identityMatrix, glm::vec3(-59.0, 40.6, 56 - i * 20));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(4.5f, 3.5f, 1.6f));
        model = temp * translateMatrix * scaleMatrix;

        // Draw the torus for each pillar
        Torus torus = Torus();
        torus.drawTorus(lightingShader, model, 0.6, 0.3f, 0.125f);

        // Pyramid
        glm::mat4 pyramidTransform = glm::mat4(1.0f);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(-55.5, 41.95, 64 - i * 20));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(15.0, 15.2, 5.5));
        pyramidTransform = temp * translateMatrix * scaleMatrix;

        // Create a Pyramid instance
        Pyramid pyramid(pyramidTransform, "Texture/castlewall.jpg");
        pyramid.draw(lightingShader);
    }


    //floor
    translateMatrix = glm::translate(identityMatrix, glm::vec3(-48.5, -0.5, -6.5));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(82, .5, 68.0));
    model = alTogether * translateMatrix * scaleMatrix;
    //drawCube(cubeVAO, lightingShader, model, 0.502f, 0, 0);
    //cube.setMaterialisticEimu(0.545f, 0.270f, 0.075f);
    //cube.drawCubeWithMaterialisticProperty(lightingShader, als);
    cube.setTextureProperty(tiles1, tiles2, 32.0);
    cube.drawCubeWithTexture(lightingShader, model);


    //grassfloor
    translateMatrix = glm::translate(identityMatrix, glm::vec3(-73.5, -6.0, -6.5));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(134, .7, 88.0));
    model = alTogether * translateMatrix * scaleMatrix;
    //drawCube(cubeVAO, lightingShader, model, 0.502f, 0, 0);
    //cube.setMaterialisticEimu(0.545f, 0.270f, 0.075f);
    //cube.drawCubeWithMaterialisticProperty(lightingShader, als);
    cube.setTextureProperty(grass1, grass2, 32.0);
    cube.drawCubeWithTexture(lightingShader, model);

   

    




}

#pragma once