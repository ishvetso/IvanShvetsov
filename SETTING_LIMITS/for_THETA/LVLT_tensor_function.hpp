#ifndef PLUGIN_LVLT_TENSOR
#define PLUGIN_LVLT_TENSOR

#include "interface/phys.hpp"

class LVLT_tensor_function: public theta::Function{
private:
    theta::ParId pid_fLV;
    theta::ParId pid_fLT;

public:
    /// constructor for the plugin system
    LVLT_tensor_function(const theta::Configuration & cfg);
    /// overloaded evaluation operator of theta::Function
    virtual double operator()(const theta::ParValues & v) const;
    
    
};


#endif
