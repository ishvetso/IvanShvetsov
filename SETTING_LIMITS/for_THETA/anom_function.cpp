#include "plugins/anom_function.hpp"
#include "interface/plugin.hpp"
#include "interface/utils.hpp"

using namespace std;
using namespace theta;

anom_function::anom_function(const theta::Configuration & cfg): pid_fL(cfg.pm->get<VarIdManager>()->get_par_id(cfg.setting["fL"])),    pid_fR(cfg.pm->get<VarIdManager>() -> get_par_id(cfg.setting["fR"])){
    par_ids.insert(pid_fL);
    par_ids.insert(pid_fR);
}

double anom_function::operator()(const theta::ParValues & values) const{
    double fL = values.get(pid_fL);
    double fR = values.get(pid_fR);
    
    return 1./(fL*fL + fR*fR);
}

REGISTER_PLUGIN(anom_function)
