#pragma once
#include <iostream>
#include <fstream>

struct StlTriangle
{
    float nl[3];        // normal
    float v1[3];        // vertex 1
    float v2[3];        // vertex 2
    float v3[3];        // vertex 3

    uint16_t bc;        // byte count
};

class StlObject
{
private:
    uint8_t header[80];
    uint32_t nt;            // number of triangles
    StlTriangle* triangles;

public:

    StlObject();

    ~StlObject();

    bool readFromFile(const char* fName);

    void outPrintTriangles(int32_t n);

    void outPrintTriangle(int32_t n);

    const uint32_t get_nt();

    const uint8_t* get_header();

    const StlTriangle get_triangle(uint32_t n);

};