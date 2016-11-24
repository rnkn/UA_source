#ifndef YUFO_H_INCLUDED
#define YUFO_H_INCLUDED

#include "nucleas.h"
#include "ypabact.h"

struct __NC_STACK_ypaufo
{
    NC_STACK_ypaworld *ywo;
    _NC_STACK_ypaworld *yw;
    __NC_STACK_ypabact *bact_internal;
    float field_c;
    float field_10;
    float field_14;
    float field_18;
    int field_1c;
};

class NC_STACK_ypaufo: public NC_STACK_ypabact
{
public:
    virtual size_t func0(stack_vals *stak);
    virtual size_t func1(stack_vals *stak);
    virtual size_t func2(stack_vals *stak);
    virtual size_t func3(stack_vals *stak);
    virtual void ypabact_func70(update_msg *arg);
    virtual void ypabact_func71(update_msg *arg);
    virtual void ypabact_func74(bact_arg74 *arg);
    virtual size_t ypabact_func80(bact_arg80 *arg);
    virtual void ypabact_func96(void *);

    virtual size_t compatcall(int method_id, void *data);
    NC_STACK_ypaufo() {
        memset(&stack__ypaufo, 0, sizeof(stack__ypaufo));
    };
    virtual ~NC_STACK_ypaufo() {};

    virtual const char * getClassName() {
        return "ypaufo.class";
    };

    static NC_STACK_nucleus * newinstance() {
        return new NC_STACK_ypaufo();
    };

    enum UFO_ATT
    {
        UFO_ATT_TOGO = 0x80002000
    };

    virtual void setBACT_inputting(int);
    virtual void setUFO_togo(int);

    virtual int getUFO_togo();

    int ypaufo_func0__sub0(stack_vals *stak);
    int ypaufo_func2__sub0(stack_vals *stak);
    void ypaufo_func3__sub0(stack_vals *stak);

    //Data
    static const NewClassDescr description;

    __NC_STACK_ypaufo stack__ypaufo;
};

#endif // YUFO_H_INCLUDED
