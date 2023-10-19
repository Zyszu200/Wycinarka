#include "stlObject.h"

StlObject::StlObject() { nt = 0; }

StlObject::~StlObject() { if (nt != 0) delete[] triangles; }

bool StlObject::readFromFile(const char* fName)
{
    FILE *stlFile;
    stlFile = fopen(fName, "r");
    if(stlFile == nullptr) return false;

    fread(header, sizeof(header), 1, stlFile);
    fread(&nt, sizeof(nt), 1, stlFile);

    // todo - check for overflows | ex. file is not an valid stl file

    triangles = new StlTriangle[nt];

    for(uint32_t n = 0; n < nt; n++)
    {
        fread(triangles[n].nl, sizeof(StlTriangle::nl), 1, stlFile);
        fread(triangles[n].v1, sizeof(StlTriangle::v1), 1, stlFile);
        fread(triangles[n].v2, sizeof(StlTriangle::v2), 1, stlFile);
        fread(triangles[n].v3, sizeof(StlTriangle::v3), 1, stlFile);
        fread(&triangles[n].bc, sizeof(StlTriangle::bc), 1, stlFile);
    }

    fclose(stlFile);
    return true;
}

void StlObject::outPrintTriangles(int32_t n)
{
    if(n > nt) return;

    for( uint32_t i = 0;  i< n; i++){
        using namespace std;
        cout << "Triangle " + to_string(i+1) + ":" << endl;
        
        cout << "\tnl :" << endl;
        cout << "\t\tx: " + to_string(triangles[i].nl[0]) << endl;
        cout << "\t\ty: " + to_string(triangles[i].nl[1]) << endl;
        cout << "\t\tz: " + to_string(triangles[i].nl[2]) << endl;

        cout << "\tv1 :" << endl;
        cout << "\t\tx: " + to_string(triangles[i].nl[0]) << endl;
        cout << "\t\ty: " + to_string(triangles[i].nl[1]) << endl;
        cout << "\t\tz: " + to_string(triangles[i].nl[2]) << endl;

        cout << "\tv2 :" << endl;
        cout << "\t\tx: " + to_string(triangles[i].v2[0]) << endl;
        cout << "\t\ty: " + to_string(triangles[i].v2[1]) << endl;
        cout << "\t\tz: " + to_string(triangles[i].v2[2]) << endl;

        cout << "\tv3 :" << endl;
        cout << "\t\tx: " + to_string(triangles[i].v3[0]) << endl;
        cout << "\t\ty: " + to_string(triangles[i].v3[1]) << endl;
        cout << "\t\tz: " + to_string(triangles[i].v3[2]) << endl;

        cout << "\tbc: " + to_string(triangles[i].bc) << endl;
    }

}

void StlObject::outPrintTriangle(int32_t n)
{
    using namespace std;
    cout << "Triangle " + to_string(n) + ":" << endl;
    
    cout << "\tnl :" << endl;
    cout << "\t\tx: " + to_string(triangles[n].nl[0]) << endl;
    cout << "\t\ty: " + to_string(triangles[n].nl[1]) << endl;
    cout << "\t\tz: " + to_string(triangles[n].nl[2]) << endl;
    cout << "\tv1 :" << endl;
    cout << "\t\tx: " + to_string(triangles[n].nl[0]) << endl;
    cout << "\t\ty: " + to_string(triangles[n].nl[1]) << endl;
    cout << "\t\tz: " + to_string(triangles[n].nl[2]) << endl;

    cout << "\tv2 :" << endl;
    cout << "\t\tx: " + to_string(triangles[n].v2[0]) << endl;
    cout << "\t\ty: " + to_string(triangles[n].v2[1]) << endl;
    cout << "\t\tz: " + to_string(triangles[n].v2[2]) << endl;

    cout << "\tv3 :" << endl;
    cout << "\t\tx: " + to_string(triangles[n].v3[0]) << endl;
    cout << "\t\ty: " + to_string(triangles[n].v3[1]) << endl;
    cout << "\t\tz: " + to_string(triangles[n].v3[2]) << endl;

    cout << "\tbc: " + to_string(triangles[n].bc) << endl;
}

const uint32_t StlObject::get_nt() { return nt; }

const uint8_t* StlObject::get_header() { return header; }

const StlTriangle StlObject::get_triangle(uint32_t n)
{
    if(n < nt) return triangles[n];
}