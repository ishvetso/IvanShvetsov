#include "plugins/LVLT_SM_function.hpp"
#include "interface/plugin.hpp"
#include "interface/utils.hpp"

using namespace std;
using namespace theta;

LVLT_SM_function::LVLT_SM_function(const theta::Configuration & cfg): pid_fLV(cfg.pm->get<VarIdManager>()->get_par_id(cfg.setting["fLV"])), pid_fLT(cfg.pm->get<VarIdManager>() -> get_par_id(cfg.setting["fLT"])){
    par_ids.insert(pid_fLV);
    par_ids.insert(pid_fLT);
}

double LVLT_SM_function::operator()(const theta::ParValues & values) const{
    double fLV = values.get(pid_fLV);
    double fLT = values.get(pid_fLT);
    double mt=173.5;
    double mW=80.385;
    double r = mt/mW;
    double ratio =  (2*r*r+1)/(r*r+2);
    
    return fLV*fLV*fLV*fLV/(fLV*fLV + ratio*fLT*fLT);
}

REGISTER_PLUGIN(LVLT_SM_function)
