#ifndef AMESH_H_INCLUDED
#define AMESH_H_INCLUDED

#include <inttypes.h>
#include "area.h"




class NC_STACK_amesh: public NC_STACK_area
{
public:
    struct ATTS
    {
        int16_t polyID = 0;
        uint8_t colorVal = 0;
        uint8_t shadeVal = 0;
        uint8_t tracyVal = 0;
        uint8_t pad = 0;
    };
    
public:
    virtual size_t Init(IDVList &stak);
    virtual size_t LoadingFromIFF(IFFile **file);
    virtual size_t SaveIntoIFF(IFFile **file);
    virtual size_t ade_func65(area_arg_65 *arg, InstanceOpts * opts = NULL);

    NC_STACK_amesh() {};
    virtual ~NC_STACK_amesh() {};
    
    virtual const std::string &ClassName() const {
        return description._classname;
    };

    static NC_STACK_nucleus * newinstance() {
        return new NC_STACK_amesh();
    };

    enum AMESH_ATT
    {
        AMESH_ATT_NUMPOLY = 0x80003000,
        AMESH_ATT_ATTPOLYS = 0x80003001,
        AMESH_ATT_OTLPOOL = 0x80003002
    };


    virtual void setAMESH_numpoly(int);
    virtual int setAMESH_polys(ATTS *);
    virtual int setAMESH_otls(tUtV **);

    virtual int getAMESH_numpoly();

    //Data
    static const Nucleus::ClassDescr description;
    
public:
    int16_t polyCnt = 0;
    std::vector<ATTS> atts;       // ATTS heap
    std::vector<tUtV *> texCoords; // Tex coords for polygons
    std::vector<tUtV> texCoordsData; // Tex coords heap
};

#endif // AMESH_H_INCLUDED
