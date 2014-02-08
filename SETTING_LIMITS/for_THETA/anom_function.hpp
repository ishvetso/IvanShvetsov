#ifndef PLUGIN_ANOM
#define PLUGIN_ANOM

#include "interface/phys.hpp"

class anom_function: public theta::Function{
private:
    theta::ParId pid_fL;
    theta::ParId pid_fR;

public:
    /// constructor for the plugin system
    anom_function(const theta::Configuration & cfg);
    /// overloaded evaluation operator of theta::Function
    virtual double operator()(const theta::ParValues & v) const;
    
    
};


#endif
