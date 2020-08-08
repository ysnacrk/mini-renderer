
#include <vector>
#include <glad/glad.h>
#include <iostream>


struct VertexBufferElement {

    // point edilecek olan attribute bilgileri


    unsigned int count;         // attribute kaç tane eleman içeriyor
    unsigned int type;          // attribute tipi
    unsigned int normalized;    // ve normalize edilmesi gerekiyor mu
    unsigned int size;

};


class VertexBufferLayout {

    // bu sınıf parse edilecek buffera işaret etmektedir

    // örnek olarak bir buffer hem koordinat hemde renk bilgisini içeriyorsa 
    // ona göre bilgileri tutmamız gerekiyor
    // elements dizisi koordinat, renk, texture ifade eder ve bunların
    // tipi ve boyutları hakkında bilgi verir

    // bu sınıfı her buffer için ayrı ayrı çağırmamız gerekiyor



    private:
        std::vector <VertexBufferElement> elements;
        unsigned int stride;

    public:
        VertexBufferLayout():stride(0){
        }

        void push(unsigned int type, unsigned int count){
            if(type == GL_FLOAT){
                elements.push_back({ count, GL_FLOAT, GL_FALSE , sizeof(float)});
                stride += (count*sizeof(float));
            }
            else if(type == GL_UNSIGNED_INT){
                elements.push_back({ count, GL_UNSIGNED_INT, GL_FALSE , sizeof(unsigned int)});
                stride += (count*sizeof(unsigned int));
            }
        }

        unsigned int getStride() const{
            return stride;
        }

        const std::vector<VertexBufferElement> getElements () const {
            return elements;
        }
};