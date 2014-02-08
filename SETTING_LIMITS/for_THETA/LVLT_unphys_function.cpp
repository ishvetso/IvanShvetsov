#include "plugins/LVLT_unphys_function.hpp"
#include "interface/plugin.hpp"
#include "interface/utils.hpp"

using namespace std;
using namespace theta;

LVLT_unphys_function::LVLT_unphys_function(const theta::Configuration & cfg): pid_fLV(cfg.pm->get<VarIdManager>()->get_par_id(cfg.setting["fLV"])), pid_fLT(cfg.pm->get<VarIdManager>() -> get_par_id(cfg.setting["fLT"])){
    par_ids.insert(pid_fLV);
    par_ids.insert(pid_fLT);
}

double LVLT_unphys_function::operator()(const theta::ParValues & values) const{
    double fLV = values.get(pid_fLV);
    double fLT = values.get(pid_fLT);
    double mt=173.5;
    double mW=80.385;
    double r = mt/mW;
    double ratio =  (2*r*r+1)/(r*r+2);
    double W_unphys = 3.812;
    double W_SM = 1.49;
    
    return W_unphys*fLV*fLV*fLT*fLT/(W_SM*(fLV*fLV + ratio*fLT*fLT));
}

REGISTER_PLUGIN(LVLT_unphys_function)
