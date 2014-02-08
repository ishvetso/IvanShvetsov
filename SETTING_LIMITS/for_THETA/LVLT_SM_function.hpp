#ifndef PLUGIN_LVLT_SM
#define PLUGIN_LVLT_SM

#include "interface/phys.hpp"

class LVLT_SM_function: public theta::Function{
private:
    theta::ParId pid_fLV;
    theta::ParId pid_fLT;

public:
    /// constructor for the plugin system
    LVLT_SM_function(const theta::Configuration & cfg);
    /// overloaded evaluation operator of theta::Function
    virtual double operator()(const theta::ParValues & v) const;
    
    
};


#endif
