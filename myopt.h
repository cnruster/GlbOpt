#pragma once

#include "glbopt.h"

class MYOPT : public GLB_OPT
{
    double VTR;
public:
    virtual int Interfun();
    void SetVTR(double vtr) {VTR = vtr; };
};