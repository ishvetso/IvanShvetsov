#ifndef PLUGIN_LVLT_UNPHYS
#define PLUGIN_LVLT_UNPHYS

#include "interface/phys.hpp"

class LVLT_unphys_function: public theta::Function{
private:
    theta::ParId pid_fLV;
    theta::ParId pid_fLT;

public:
    /// constructor for the plugin system
    LVLT_unphys_function(const theta::Configuration & cfg);
    /// overloaded evaluation operator of theta::Function
    virtual double operator()(const theta::ParValues & v) const;
    
    
};


#endif
