#include "hist_creater.cpp"

void hist_creater_theta()
{
	
	std::map<string,vector <string> > hist_map;
 
	vector <string> Drell_Yan;
	vector <string> Drell_Yan_JECUp;
	vector <string> Drell_Yan_JECDown;
	vector <string> Drell_Yan_JERUp;
	vector <string> Drell_Yan_JERDown;
	vector <string> Drell_Yan_TagUp;
	vector <string> Drell_Yan_TagDown;
	vector <string> Drell_Yan_MistagUp;
	vector <string> Drell_Yan_MistagDown;
	vector <string> Drell_Yan_METUnclUp;
	vector <string> Drell_Yan_METUnclDown;
	vector <string> Drell_Yan_TrigUp;
	vector <string> Drell_Yan_TrigDown;
		
	 
	vector <string> Diboson;
	vector <string> Diboson_JECUp;
	vector <string> Diboson_JECDown;
	vector <string> Diboson_JERUp;
	vector <string> Diboson_JERDown;
	vector <string> Diboson_TagUp;
	vector <string> Diboson_TagDown;
	vector <string> Diboson_MistagUp;
	vector <string> Diboson_MistagDown;
	vector <string> Diboson_METUnclUp;
	vector <string> Diboson_METUnclDown;
	vector <string> Diboson_TrigUp;
	vector <string> Diboson_TrigDown;
	
	 
	vector <string> t_channel_pw;
	vector <string> t_channel_pw_JECUp;
	vector <string> t_channel_pw_JECDown;
	vector <string> t_channel_pw_JERUp;
	vector <string> t_channel_pw_JERDown;
	vector <string> t_channel_pw_TagUp;
	vector <string> t_channel_pw_TagDown;
	vector <string> t_channel_pw_MistagUp;
	vector <string> t_channel_pw_MistagDown;
	vector <string> t_channel_pw_METUnclUp;
	vector <string> t_channel_pw_METUnclDown;
	vector <string> t_channel_pw_TrigUp;
	vector <string> t_channel_pw_TrigDown;
	vector <string> t_channel_pw_Q2Up;
	vector <string> t_channel_pw_Q2Down;
	
	vector <string> t_channel_ch;
	vector <string> t_channel_ch_JECUp;
	vector <string> t_channel_ch_JECDown;
	vector <string> t_channel_ch_JERUp;
	vector <string> t_channel_ch_JERDown;
	vector <string> t_channel_ch_TagUp;
	vector <string> t_channel_ch_TagDown;
	vector <string> t_channel_ch_MistagUp;
	vector <string> t_channel_ch_MistagDown;
	vector <string> t_channel_ch_METUnclUp;
	vector <string> t_channel_ch_METUnclDown;
	vector <string> t_channel_ch_TrigUp;
	vector <string> t_channel_ch_TrigDown;

	vector <string> unphys_ch;
	vector <string> unphys_ch_JECUp;
	vector <string> unphys_ch_JECDown;
	vector <string> unphys_ch_JERUp;
	vector <string> unphys_ch_JERDown;
	vector <string> unphys_ch_TagUp;
	vector <string> unphys_ch_TagDown;
	vector <string> unphys_ch_MistagUp;
	vector <string> unphys_ch_MistagDown;
	vector <string> unphys_ch_METUnclUp;
	vector <string> unphys_ch_METUnclDown;
	
	vector <string> right_ch;
	vector <string> right_ch_JECUp;
	vector <string> right_ch_JECDown;
	vector <string> right_ch_JERUp;
	vector <string> right_ch_JERDown;
	vector <string> right_ch_TagUp;
	vector <string> right_ch_TagDown;
	vector <string> right_ch_MistagUp;
	vector <string> right_ch_MistagDown;
	vector <string> right_ch_METUnclUp;
	vector <string> right_ch_METUnclDown;
	
	vector <string> unphys_LVLT_ch;
	vector <string> unphys_LVLT_ch_JECUp;
	vector <string> unphys_LVLT_ch_JECDown;
	vector <string> unphys_LVLT_ch_JERUp;
	vector <string> unphys_LVLT_ch_JERDown;
	vector <string> unphys_LVLT_ch_TagUp;
	vector <string> unphys_LVLT_ch_TagDown;
	vector <string> unphys_LVLT_ch_MistagUp;
	vector <string> unphys_LVLT_ch_MistagDown;
	vector <string> unphys_LVLT_ch_METUnclUp;
	vector <string> unphys_LVLT_ch_METUnclDown;
	
	vector <string> tensor_ch;
	vector <string> tensor_ch_JECUp;
	vector <string> tensor_ch_JECDown;
	vector <string> tensor_ch_JERUp;
	vector <string> tensor_ch_JERDown;
	vector <string> tensor_ch_TagUp;
	vector <string> tensor_ch_TagDown;
	vector <string> tensor_ch_MistagUp;
	vector <string> tensor_ch_MistagDown;
	vector <string> tensor_ch_METUnclUp;
	vector <string> tensor_ch_METUnclDown;
	
	
	 
	vector <string> s_channel;
	vector <string> s_channel_JECUp;
	vector <string> s_channel_JECDown;
	vector <string> s_channel_JERUp;
	vector <string> s_channel_JERDown;
	vector <string> s_channel_TagUp;
	vector <string> s_channel_TagDown;
	vector <string> s_channel_MistagUp;
	vector <string> s_channel_MistagDown;
	vector <string> s_channel_METUnclUp;
	vector <string> s_channel_METUnclDown;
	vector <string> s_channel_TrigUp;
	vector <string> s_channel_TrigDown;
	
	vector <string> tw_channel;
	vector <string> tw_channel_JECUp;
	vector <string> tw_channel_JECDown;
	vector <string> tw_channel_JERUp;
	vector <string> tw_channel_JERDown;
	vector <string> tw_channel_TagUp;
	vector <string> tw_channel_TagDown;
	vector <string> tw_channel_MistagUp;
	vector <string> tw_channel_MistagDown;
	vector <string> tw_channel_METUnclUp;
	vector <string> tw_channel_METUnclDown;
	vector <string> tw_channel_TrigUp;
	vector <string> tw_channel_TrigDown;
	vector <string> tw_channel_Q2Up;
	vector <string> tw_channel_Q2Down;
	
	vector <string> ttbar;
	vector <string> ttbar_JECUp;
	vector <string> ttbar_JECDown;
	vector <string> ttbar_JERUp;
	vector <string> ttbar_JERDown;
	vector <string> ttbar_TagUp;
	vector <string> ttbar_TagDown;
	vector <string> ttbar_MistagUp;
	vector <string> ttbar_MistagDown;
	vector <string> ttbar_METUnclUp;
	vector <string> ttbar_METUnclDown;
	vector <string> ttbar_TrigUp;
	vector <string> ttbar_TrigDown;
	vector <string> ttbar_Q2Up;
	vector <string> ttbar_Q2Down;
	vector <string> ttbar_matchingUp;
	vector <string> ttbar_matchingDown;
	
	vector <string> wjets;
	vector <string> wjets_JECUp;
	vector <string> wjets_JECDown;
	vector <string> wjets_JERUp;
	vector <string> wjets_JERDown;
	vector <string> wjets_TagUp;
	vector <string> wjets_TagDown;
	vector <string> wjets_MistagUp;
	vector <string> wjets_MistagDown;
	vector <string> wjets_METUnclUp;
	vector <string> wjets_METUnclDown;
	vector <string> wjets_TrigUp;
	vector <string> wjets_TrigDown;
	
	vector <string> wjets_W_light;
	vector <string> wjets_W_light_JECUp;
	vector <string> wjets_W_light_JECDown;
	vector <string> wjets_W_light_JERUp;
	vector <string> wjets_W_light_JERDown;
	vector <string> wjets_W_light_TagUp;
	vector <string> wjets_W_light_TagDown;
	vector <string> wjets_W_light_MistagUp;
	vector <string> wjets_W_light_MistagDown;
	vector <string> wjets_W_light_METUnclUp;
	vector <string> wjets_W_light_METUnclDown;
	vector <string> wjets_W_light_TrigUp;
	vector <string> wjets_W_light_TrigDown;
	
	vector <string> wjets_Wc;
	vector <string> wjets_Wc_JECUp;
	vector <string> wjets_Wc_JECDown;
	vector <string> wjets_Wc_JERUp;
	vector <string> wjets_Wc_JERDown;
	vector <string> wjets_Wc_TagUp;
	vector <string> wjets_Wc_TagDown;
	vector <string> wjets_Wc_MistagUp;
	vector <string> wjets_Wc_MistagDown;
	vector <string> wjets_Wc_METUnclUp;
	vector <string> wjets_Wc_METUnclDown;
	vector <string> wjets_Wc_TrigUp;
	vector <string> wjets_Wc_TrigDown;
	
	vector <string> wjets_WQQ;
	vector <string> wjets_WQQ_JECUp;
	vector <string> wjets_WQQ_JECDown;
	vector <string> wjets_WQQ_JERUp;
	vector <string> wjets_WQQ_JERDown;
	vector <string> wjets_WQQ_TagUp;
	vector <string> wjets_WQQ_TagDown;
	vector <string> wjets_WQQ_MistagUp;
	vector <string> wjets_WQQ_MistagDown;
	vector <string> wjets_WQQ_METUnclUp;
	vector <string> wjets_WQQ_METUnclDown;
	vector <string> wjets_WQQ_TrigUp;
	vector <string> wjets_WQQ_TrigDown;
	
	vector <string> wjets_W_other;
	vector <string> wjets_W_other_JECUp;
	vector <string> wjets_W_other_JECDown;
	vector <string> wjets_W_other_JERUp;
	vector <string> wjets_W_other_JERDown;
	vector <string> wjets_W_other_TagUp;
	vector <string> wjets_W_other_TagDown;
	vector <string> wjets_W_other_MistagUp;
	vector <string> wjets_W_other_MistagDown;
	vector <string> wjets_W_other_METUnclUp;
	vector <string> wjets_W_other_METUnclDown;
	vector <string> wjets_W_other_TrigUp;
	vector <string> wjets_W_other_TrigDown;
	
	vector <string> wjets_WQQ_matchingUp;
	vector <string> wjets_WQQ_matchingDown;
	
	vector <string> wjets_Wc_matchingUp;
	vector <string> wjets_Wc_matchingDown;
	
	vector <string> wjets_W_light_matchingUp;
	vector <string> wjets_W_light_matchingDown;
	
	vector <string> wjets_W_other_matchingUp;
	vector <string> wjets_W_other_matchingDown;
	
	vector <string> wjets_matchingUp;
	vector <string> wjets_matchingDown;

	vector <string> QCD;
	vector <string> data;
	

/*
	 * Drell-Yan
	 */
	Drell_Yan.push_back("DY-mumu.root");
	Drell_Yan.push_back("DY-tautau.root");
	
	Drell_Yan_JECUp.push_back("DY-mumu_JECUp.root");
	Drell_Yan_JECUp.push_back("DY-tautau_JECUp.root");
	Drell_Yan_JECDown.push_back("DY-mumu_JECDown.root");
	Drell_Yan_JECDown.push_back("DY-tautau_JECDown.root");
	
	Drell_Yan_JERUp.push_back("DY-mumu_JERUp.root");
	Drell_Yan_JERUp.push_back("DY-tautau_JERUp.root");
	Drell_Yan_JERDown.push_back("DY-mumu_JERDown.root");
	Drell_Yan_JERDown.push_back("DY-tautau_JERDown.root");
	
	Drell_Yan_TagUp.push_back("DY-mumu_TagUp.root");
	Drell_Yan_TagUp.push_back("DY-tautau_TagUp.root");
	Drell_Yan_TagDown.push_back("DY-mumu_TagDown.root");
	Drell_Yan_TagDown.push_back("DY-tautau_TagDown.root");
	
	Drell_Yan_MistagUp.push_back("DY-mumu_MistagUp.root");
	Drell_Yan_MistagUp.push_back("DY-tautau_MistagUp.root");
	Drell_Yan_MistagDown.push_back("DY-mumu_MistagDown.root");
	Drell_Yan_MistagDown.push_back("DY-tautau_MistagDown.root");
	
	Drell_Yan_METUnclUp.push_back("DY-mumu_METUnclUp.root");
	Drell_Yan_METUnclUp.push_back("DY-tautau_METUnclUp.root");
	Drell_Yan_METUnclDown.push_back("DY-mumu_METUnclDown.root");
	Drell_Yan_METUnclDown.push_back("DY-tautau_METUnclDown.root");
	
 	Drell_Yan_TrigUp.push_back("DY-mumu_TrigUp.root");
 	Drell_Yan_TrigUp.push_back("DY-tautau_TrigUp.root");
 	Drell_Yan_TrigDown.push_back("DY-mumu_TrigDown.root");
 	Drell_Yan_TrigDown.push_back("DY-tautau_TrigDown.root");

	/*
	 * diboson
	 */
	
	Diboson.push_back("WW.root");
	Diboson.push_back("WZ.root");
	Diboson.push_back("ZZ.root");
	
	Diboson_JECUp.push_back("WW_JECUp.root");
	Diboson_JECUp.push_back("WZ_JECUp.root");
	Diboson_JECUp.push_back("ZZ_JECUp.root");
	
	Diboson_JECDown.push_back("WW_JECDown.root");
	Diboson_JECDown.push_back("WZ_JECDown.root");
	Diboson_JECDown.push_back("ZZ_JECDown.root");
	
	Diboson_JERUp.push_back("WW_JERUp.root");
	Diboson_JERUp.push_back("WZ_JERUp.root");
	Diboson_JERUp.push_back("ZZ_JERUp.root");
	
	Diboson_JERDown.push_back("WW_JERDown.root");
	Diboson_JERDown.push_back("WZ_JERDown.root");
	Diboson_JERDown.push_back("ZZ_JERDown.root");
	
	Diboson_TagUp.push_back("WW_TagUp.root");
	Diboson_TagUp.push_back("WZ_TagUp.root");
	Diboson_TagUp.push_back("ZZ_TagUp.root");
	
	Diboson_TagDown.push_back("WW_TagDown.root");
	Diboson_TagDown.push_back("WZ_TagDown.root");
	Diboson_TagDown.push_back("ZZ_TagDown.root");
	
	Diboson_MistagUp.push_back("WW_MistagUp.root");
	Diboson_MistagUp.push_back("WZ_MistagUp.root");
	Diboson_MistagUp.push_back("ZZ_MistagUp.root");
	
	Diboson_MistagDown.push_back("WW_MistagDown.root");
	Diboson_MistagDown.push_back("WZ_MistagDown.root");
	Diboson_MistagDown.push_back("ZZ_MistagDown.root");
	
	Diboson_METUnclUp.push_back("WW_METUnclUp.root");
	Diboson_METUnclUp.push_back("WZ_METUnclUp.root");
	Diboson_METUnclUp.push_back("ZZ_METUnclUp.root");
	
	Diboson_METUnclDown.push_back("WW_METUnclDown.root");
	Diboson_METUnclDown.push_back("WZ_METUnclDown.root");
	Diboson_METUnclDown.push_back("ZZ_METUnclDown.root");
	
 	Diboson_TrigUp.push_back("WW_TrigUp.root");
 	Diboson_TrigUp.push_back("WZ_TrigUp.root");
 	Diboson_TrigUp.push_back("ZZ_TrigUp.root");
	
 	Diboson_TrigDown.push_back("WW_TrigDown.root");
 	Diboson_TrigDown.push_back("WZ_TrigDown.root");
 	Diboson_TrigDown.push_back("ZZ_TrigDown.root");

	
	/*
	 * t-ch(POWHEG)
	 */
	t_channel_pw.push_back("t-tchan-pw.root");
	t_channel_pw.push_back("tbar-tchan-pw.root");
	
	t_channel_pw_JECUp.push_back("t-tchan-pw_JECUp.root");
	t_channel_pw_JECUp.push_back("tbar-tchan-pw_JECUp.root");
	
	t_channel_pw_JECDown.push_back("t-tchan-pw_JECDown.root");
	t_channel_pw_JECDown.push_back("tbar-tchan-pw_JECDown.root");
	
	t_channel_pw_JERUp.push_back("t-tchan-pw_JERUp.root");
	t_channel_pw_JERUp.push_back("tbar-tchan-pw_JERUp.root");
	
	t_channel_pw_JERDown.push_back("t-tchan-pw_JERDown.root");
	t_channel_pw_JERDown.push_back("tbar-tchan-pw_JERDown.root");
	
	t_channel_pw_TagUp.push_back("t-tchan-pw_TagUp.root");
	t_channel_pw_TagUp.push_back("tbar-tchan-pw_TagUp.root");
	
	t_channel_pw_TagDown.push_back("t-tchan-pw_TagDown.root");
	t_channel_pw_TagDown.push_back("tbar-tchan-pw_TagDown.root");
	
	t_channel_pw_MistagUp.push_back("t-tchan-pw_MistagUp.root");
	t_channel_pw_MistagUp.push_back("tbar-tchan-pw_MistagUp.root");
	
	t_channel_pw_MistagDown.push_back("t-tchan-pw_MistagDown.root");
	t_channel_pw_MistagDown.push_back("tbar-tchan-pw_MistagDown.root");
	
	t_channel_pw_METUnclUp.push_back("t-tchan-pw_METUnclUp.root");
	t_channel_pw_METUnclUp.push_back("tbar-tchan-pw_METUnclUp.root");
	
	t_channel_pw_METUnclDown.push_back("t-tchan-pw_METUnclDown.root");
	t_channel_pw_METUnclDown.push_back("tbar-tchan-pw_METUnclDown.root");
	
 	t_channel_pw_TrigUp.push_back("t-tchan-pw_TrigUp.root");
 	t_channel_pw_TrigUp.push_back("tbar-tchan-pw_TrigUp.root");
	
 	t_channel_pw_TrigDown.push_back("t-tchan-pw_TrigDown.root");
 	t_channel_pw_TrigDown.push_back("tbar-tchan-pw_TrigDown.root");
	
 	t_channel_pw_Q2Up.push_back("t-tchan-pw-scaleup.root");
 	t_channel_pw_Q2Up.push_back("tbar-tchan-pw-scaleup.root");
	
 	t_channel_pw_Q2Down.push_back("t-tchan-pw-scaledown.root");
 	t_channel_pw_Q2Down.push_back("tbar-tchan-pw-scaledown.root");
	
	
	/*
	 * t-ch (CompHEP)
	 */
	t_channel_ch.push_back("t-tchan-mu-ch.root");
	t_channel_ch.push_back("t-tchan-tau-ch.root");

	t_channel_ch_JECUp.push_back("t-tchan-mu-ch_JECUp.root");
	t_channel_ch_JECUp.push_back("t-tchan-tau-ch_JECUp.root");

	t_channel_ch_JECDown.push_back("t-tchan-mu-ch_JECDown.root");
	t_channel_ch_JECDown.push_back("t-tchan-tau-ch_JECDown.root");

	t_channel_ch_JERUp.push_back("t-tchan-mu-ch_JERUp.root");
	t_channel_ch_JERUp.push_back("t-tchan-tau-ch_JERUp.root");

	t_channel_ch_JERDown.push_back("t-tchan-mu-ch_JERDown.root");
	t_channel_ch_JERDown.push_back("t-tchan-tau-ch_JERDown.root");

	t_channel_ch_TagUp.push_back("t-tchan-mu-ch_TagUp.root");
	t_channel_ch_TagUp.push_back("t-tchan-tau-ch_TagUp.root");

	t_channel_ch_TagDown.push_back("t-tchan-mu-ch_TagDown.root");
	t_channel_ch_TagDown.push_back("t-tchan-tau-ch_TagDown.root");

	t_channel_ch_MistagUp.push_back("t-tchan-mu-ch_MistagUp.root");
	t_channel_ch_MistagUp.push_back("t-tchan-tau-ch_MistagUp.root");

	t_channel_ch_MistagDown.push_back("t-tchan-mu-ch_MistagDown.root");
	t_channel_ch_MistagDown.push_back("t-tchan-tau-ch_MistagDown.root");

	t_channel_ch_METUnclUp.push_back("t-tchan-mu-ch_METUnclUp.root");
	t_channel_ch_METUnclUp.push_back("t-tchan-tau-ch_METUnclUp.root");

	t_channel_ch_METUnclDown.push_back("t-tchan-mu-ch_METUnclDown.root");
	t_channel_ch_METUnclDown.push_back("t-tchan-tau-ch_METUnclDown.root");

 	t_channel_ch_TrigUp.push_back("t-tchan-mu-ch_TrigUp.root");
 	t_channel_ch_TrigUp.push_back("t-tchan-tau-ch_TrigUp.root");

 	t_channel_ch_TrigDown.push_back("t-tchan-mu-ch_TrigDown.root");
 	t_channel_ch_TrigDown.push_back("t-tchan-tau-ch_TrigDown.root");
	
		/*
	 *UNPHYS t-ch (CompHEP)
	 */
	unphys_ch.push_back("t-tchan-LVRV-unphys-mu-ch.root");
	unphys_ch.push_back("t-tchan-LVRV-unphys-tau-ch.root");
	

	unphys_ch_JECUp.push_back("t-tchan-LVRV-unphys-mu-ch_JECUp.root");
	unphys_ch_JECDown.push_back("t-tchan-LVRV-unphys-mu-ch_JECDown.root");
	unphys_ch_JECUp.push_back("t-tchan-LVRV-unphys-tau-ch_JECUp.root");
	unphys_ch_JECDown.push_back("t-tchan-LVRV-unphys-tau-ch_JECDown.root");

	unphys_ch_JERUp.push_back("t-tchan-LVRV-unphys-mu-ch_JERUp.root");
	unphys_ch_JERDown.push_back("t-tchan-LVRV-unphys-mu-ch_JERDown.root");
	unphys_ch_JERUp.push_back("t-tchan-LVRV-unphys-tau-ch_JERUp.root");
	unphys_ch_JERDown.push_back("t-tchan-LVRV-unphys-tau-ch_JERDown.root");
	
	unphys_ch_TagUp.push_back("t-tchan-LVRV-unphys-mu-ch_TagUp.root");
	unphys_ch_TagDown.push_back("t-tchan-LVRV-unphys-mu-ch_TagDown.root");
	unphys_ch_TagUp.push_back("t-tchan-LVRV-unphys-tau-ch_TagUp.root");
	unphys_ch_TagDown.push_back("t-tchan-LVRV-unphys-tau-ch_TagDown.root");
	
	unphys_ch_MistagUp.push_back("t-tchan-LVRV-unphys-mu-ch_MistagUp.root");
	unphys_ch_MistagDown.push_back("t-tchan-LVRV-unphys-mu-ch_MistagDown.root");
	unphys_ch_MistagUp.push_back("t-tchan-LVRV-unphys-tau-ch_MistagUp.root");
	unphys_ch_MistagDown.push_back("t-tchan-LVRV-unphys-tau-ch_MistagDown.root");
	
	unphys_ch_METUnclUp.push_back("t-tchan-LVRV-unphys-mu-ch_METUnclUp.root");
	unphys_ch_METUnclDown.push_back("t-tchan-LVRV-unphys-mu-ch_METUnclDown.root");
	unphys_ch_METUnclUp.push_back("t-tchan-LVRV-unphys-tau-ch_METUnclUp.root");
	unphys_ch_METUnclDown.push_back("t-tchan-LVRV-unphys-tau-ch_METUnclDown.root");
	
	
		/*
	 *UNPHYS t-ch (CompHEP) LVLT
	 */
	unphys_LVLT_ch.push_back("t-tchan-LVLT-unphys-mu-ch.root");
	unphys_LVLT_ch.push_back("t-tchan-LVLT-unphys-tau-ch.root");
	

	unphys_LVLT_ch_JECUp.push_back("t-tchan-LVLT-unphys-mu-ch_JECUp.root");
	unphys_LVLT_ch_JECDown.push_back("t-tchan-LVLT-unphys-mu-ch_JECDown.root");
	unphys_LVLT_ch_JECUp.push_back("t-tchan-LVLT-unphys-tau-ch_JECUp.root");
	unphys_LVLT_ch_JECDown.push_back("t-tchan-LVLT-unphys-tau-ch_JECDown.root");

	unphys_LVLT_ch_JERUp.push_back("t-tchan-LVLT-unphys-mu-ch_JERUp.root");
	unphys_LVLT_ch_JERDown.push_back("t-tchan-LVLT-unphys-mu-ch_JERDown.root");
	unphys_LVLT_ch_JERUp.push_back("t-tchan-LVLT-unphys-tau-ch_JERUp.root");
	unphys_LVLT_ch_JERDown.push_back("t-tchan-LVLT-unphys-tau-ch_JERDown.root");
	
	unphys_LVLT_ch_TagUp.push_back("t-tchan-LVLT-unphys-mu-ch_TagUp.root");
	unphys_LVLT_ch_TagDown.push_back("t-tchan-LVLT-unphys-mu-ch_TagDown.root");
	unphys_LVLT_ch_TagUp.push_back("t-tchan-LVLT-unphys-tau-ch_TagUp.root");
	unphys_LVLT_ch_TagDown.push_back("t-tchan-LVLT-unphys-tau-ch_TagDown.root");
	
	unphys_LVLT_ch_MistagUp.push_back("t-tchan-LVLT-unphys-mu-ch_MistagUp.root");
	unphys_LVLT_ch_MistagDown.push_back("t-tchan-LVLT-unphys-mu-ch_MistagDown.root");
	unphys_LVLT_ch_MistagUp.push_back("t-tchan-LVLT-unphys-tau-ch_MistagUp.root");
	unphys_LVLT_ch_MistagDown.push_back("t-tchan-LVLT-unphys-tau-ch_MistagDown.root");
	
	unphys_LVLT_ch_METUnclUp.push_back("t-tchan-LVLT-unphys-mu-ch_METUnclUp.root");
	unphys_LVLT_ch_METUnclDown.push_back("t-tchan-LVLT-unphys-mu-ch_METUnclDown.root");
	unphys_LVLT_ch_METUnclUp.push_back("t-tchan-LVLT-unphys-tau-ch_METUnclUp.root");
	unphys_LVLT_ch_METUnclDown.push_back("t-tchan-LVLT-unphys-tau-ch_METUnclDown.root");
	
	/*
	 * 0100
	 */
	right_ch.push_back("t-tchan-LVRV-0100-mu-ch.root");
	right_ch.push_back("t-tchan-LVRV-0100-tau-ch.root");

	right_ch_JECUp.push_back("t-tchan-LVRV-0100-mu-ch_JECUp.root");
	right_ch_JECDown.push_back("t-tchan-LVRV-0100-mu-ch_JECDown.root");
	right_ch_JECUp.push_back("t-tchan-LVRV-0100-tau-ch_JECUp.root");
	right_ch_JECDown.push_back("t-tchan-LVRV-0100-tau-ch_JECDown.root");

	right_ch_JERUp.push_back("t-tchan-LVRV-0100-mu-ch_JERUp.root");
	right_ch_JERDown.push_back("t-tchan-LVRV-0100-mu-ch_JERDown.root");
	right_ch_JERUp.push_back("t-tchan-LVRV-0100-tau-ch_JERUp.root");
	right_ch_JERDown.push_back("t-tchan-LVRV-0100-tau-ch_JERDown.root");
	
	right_ch_TagUp.push_back("t-tchan-LVRV-0100-mu-ch_TagUp.root");
	right_ch_TagDown.push_back("t-tchan-LVRV-0100-mu-ch_TagDown.root");
	right_ch_TagUp.push_back("t-tchan-LVRV-0100-tau-ch_TagUp.root");
	right_ch_TagDown.push_back("t-tchan-LVRV-0100-tau-ch_TagDown.root");
	
	right_ch_MistagUp.push_back("t-tchan-LVRV-0100-mu-ch_MistagUp.root");
	right_ch_MistagDown.push_back("t-tchan-LVRV-0100-mu-ch_MistagDown.root");
	right_ch_MistagUp.push_back("t-tchan-LVRV-0100-tau-ch_MistagUp.root");
	right_ch_MistagDown.push_back("t-tchan-LVRV-0100-tau-ch_MistagDown.root");
	
	right_ch_METUnclUp.push_back("t-tchan-LVRV-0100-mu-ch_METUnclUp.root");
	right_ch_METUnclDown.push_back("t-tchan-LVRV-0100-mu-ch_METUnclDown.root");
	right_ch_METUnclUp.push_back("t-tchan-LVRV-0100-tau-ch_METUnclUp.root");
	right_ch_METUnclDown.push_back("t-tchan-LVRV-0100-tau-ch_METUnclDown.root");

	/*
	 * 0010
	 */
	tensor_ch.push_back("t-tchan-LVLT-0010-mu-ch.root");
	tensor_ch.push_back("t-tchan-LVLT-0010-tau-ch.root");

	tensor_ch_JECUp.push_back("t-tchan-LVLT-0010-mu-ch_JECUp.root");
	tensor_ch_JECDown.push_back("t-tchan-LVLT-0010-mu-ch_JECDown.root");
	tensor_ch_JECUp.push_back("t-tchan-LVLT-0010-tau-ch_JECUp.root");
	tensor_ch_JECDown.push_back("t-tchan-LVLT-0010-tau-ch_JECDown.root");

	tensor_ch_JERUp.push_back("t-tchan-LVLT-0010-mu-ch_JERUp.root");
	tensor_ch_JERDown.push_back("t-tchan-LVLT-0010-mu-ch_JERDown.root");
	tensor_ch_JERUp.push_back("t-tchan-LVLT-0010-tau-ch_JERUp.root");
	tensor_ch_JERDown.push_back("t-tchan-LVLT-0010-tau-ch_JERDown.root");
	
	tensor_ch_TagUp.push_back("t-tchan-LVLT-0010-mu-ch_TagUp.root");
	tensor_ch_TagDown.push_back("t-tchan-LVLT-0010-mu-ch_TagDown.root");
	tensor_ch_TagUp.push_back("t-tchan-LVLT-0010-tau-ch_TagUp.root");
	tensor_ch_TagDown.push_back("t-tchan-LVLT-0010-tau-ch_TagDown.root");
	
	tensor_ch_MistagUp.push_back("t-tchan-LVLT-0010-mu-ch_MistagUp.root");
	tensor_ch_MistagDown.push_back("t-tchan-LVLT-0010-mu-ch_MistagDown.root");
	tensor_ch_MistagUp.push_back("t-tchan-LVLT-0010-tau-ch_MistagUp.root");
	tensor_ch_MistagDown.push_back("t-tchan-LVLT-0010-tau-ch_MistagDown.root");
	
	tensor_ch_METUnclUp.push_back("t-tchan-LVLT-0010-mu-ch_METUnclUp.root");
	tensor_ch_METUnclDown.push_back("t-tchan-LVLT-0010-mu-ch_METUnclDown.root");
	tensor_ch_METUnclUp.push_back("t-tchan-LVLT-0010-tau-ch_METUnclUp.root");
	tensor_ch_METUnclDown.push_back("t-tchan-LVLT-0010-tau-ch_METUnclDown.root");

	/*
	 * s-ch
	 */
	s_channel.push_back("t-schan-pw.root");
	s_channel.push_back("tbar-schan-pw.root");
	
	s_channel_JECUp.push_back("t-schan-pw_JECUp.root");
	s_channel_JECUp.push_back("tbar-schan-pw_JECUp.root");
	
	s_channel_JECDown.push_back("t-schan-pw_JECDown.root");
	s_channel_JECDown.push_back("tbar-schan-pw_JECDown.root");
	
	s_channel_JERUp.push_back("t-schan-pw_JERUp.root");
	s_channel_JERUp.push_back("tbar-schan-pw_JERUp.root");
	
	s_channel_JERDown.push_back("t-schan-pw_JERDown.root");
	s_channel_JERDown.push_back("tbar-schan-pw_JERDown.root");
	
	s_channel_TagUp.push_back("t-schan-pw_TagUp.root");
	s_channel_TagUp.push_back("tbar-schan-pw_TagUp.root");
	
	s_channel_TagDown.push_back("t-schan-pw_TagDown.root");
	s_channel_TagDown.push_back("tbar-schan-pw_TagDown.root");
	
	s_channel_MistagUp.push_back("t-schan-pw_MistagUp.root");
	s_channel_MistagUp.push_back("tbar-schan-pw_MistagUp.root");
	
	s_channel_MistagDown.push_back("t-schan-pw_MistagDown.root");
	s_channel_MistagDown.push_back("tbar-schan-pw_MistagDown.root");
	
	s_channel_METUnclUp.push_back("t-schan-pw_METUnclUp.root");
	s_channel_METUnclUp.push_back("tbar-schan-pw_METUnclUp.root");
	
	s_channel_METUnclDown.push_back("t-schan-pw_METUnclDown.root");
	s_channel_METUnclDown.push_back("tbar-schan-pw_METUnclDown.root");
	
 	s_channel_TrigUp.push_back("t-schan-pw_TrigUp.root");
	s_channel_TrigUp.push_back("tbar-schan-pw_TrigUp.root");
	
 	s_channel_TrigDown.push_back("t-schan-pw_TrigDown.root");
 	s_channel_TrigDown.push_back("tbar-schan-pw_TrigDown.root");

	/**
	 * tW-ch
	 */
	
	tw_channel.push_back("tbar-tWchan-DR-pw.root");
	tw_channel.push_back("t-tWchan-DR-pw.root");
	
	tw_channel_JECUp.push_back("tbar-tWchan-DR-pw_JECUp.root");
	tw_channel_JECUp.push_back("t-tWchan-DR-pw_JECUp.root");
	
	tw_channel_JECDown.push_back("tbar-tWchan-DR-pw_JECDown.root");
	tw_channel_JECDown.push_back("t-tWchan-DR-pw_JECDown.root");
	
	tw_channel_JERUp.push_back("tbar-tWchan-DR-pw_JERUp.root");
	tw_channel_JERUp.push_back("t-tWchan-DR-pw_JERUp.root");
	
	tw_channel_JERDown.push_back("tbar-tWchan-DR-pw_JERDown.root");
	tw_channel_JERDown.push_back("t-tWchan-DR-pw_JERDown.root");
	
	tw_channel_TagUp.push_back("tbar-tWchan-DR-pw_TagUp.root");
	tw_channel_TagUp.push_back("t-tWchan-DR-pw_TagUp.root");
	
	tw_channel_TagDown.push_back("tbar-tWchan-DR-pw_TagDown.root");
	tw_channel_TagDown.push_back("t-tWchan-DR-pw_TagDown.root");
	
	tw_channel_MistagUp.push_back("tbar-tWchan-DR-pw_MistagUp.root");
	tw_channel_MistagUp.push_back("t-tWchan-DR-pw_MistagUp.root");
	
	tw_channel_MistagDown.push_back("tbar-tWchan-DR-pw_MistagDown.root");
	tw_channel_MistagDown.push_back("t-tWchan-DR-pw_MistagDown.root");
	
	tw_channel_METUnclUp.push_back("tbar-tWchan-DR-pw_METUnclUp.root");
	tw_channel_METUnclUp.push_back("t-tWchan-DR-pw_METUnclUp.root");
	
	tw_channel_METUnclDown.push_back("tbar-tWchan-DR-pw_METUnclDown.root");
	tw_channel_METUnclDown.push_back("t-tWchan-DR-pw_METUnclDown.root");
	
 	tw_channel_TrigUp.push_back("tbar-tWchan-DR-pw_TrigUp.root");
 	tw_channel_TrigUp.push_back("t-tWchan-DR-pw_TrigUp.root");
	
 	tw_channel_TrigDown.push_back("tbar-tWchan-DR-pw_TrigDown.root");
 	tw_channel_TrigDown.push_back("t-tWchan-DR-pw_TrigDown.root");
	
 	tw_channel_Q2Up.push_back("tbar-tWchan-DR-pw-scaleup.root");
 	tw_channel_Q2Up.push_back("t-tWchan-DR-pw-scaleup.root");
	
 	tw_channel_Q2Down.push_back("tbar-tWchan-DR-pw-scaledown.root");
 	tw_channel_Q2Down.push_back("t-tWchan-DR-pw-scaledown.root");
	
	/**
	 * ttbar
	 */
	ttbar.push_back("ttbar-mg.root");
	
	ttbar_JECUp.push_back("ttbar-mg_JECUp.root");
	ttbar_JECDown.push_back("ttbar-mg_JECDown.root");
	
	ttbar_JERUp.push_back("ttbar-mg_JERUp.root");
	ttbar_JERDown.push_back("ttbar-mg_JERDown.root");
	
	ttbar_TagUp.push_back("ttbar-mg_TagUp.root");
	ttbar_TagDown.push_back("ttbar-mg_TagDown.root");

	ttbar_MistagUp.push_back("ttbar-mg_MistagUp.root");
	ttbar_MistagDown.push_back("ttbar-mg_MistagDown.root");
	
	ttbar_METUnclUp.push_back("ttbar-mg_METUnclUp.root");
	ttbar_METUnclDown.push_back("ttbar-mg_METUnclDown.root");
	
 	ttbar_TrigUp.push_back("ttbar-mg_TrigUp.root");
 	ttbar_TrigDown.push_back("ttbar-mg_TrigDown.root");
	
 	ttbar_Q2Up.push_back("ttbar-mg-scaleup.root");
 	ttbar_Q2Down.push_back("ttbar-mg-scaledown.root");
	
 	ttbar_matchingUp.push_back("ttbar-mg-matchingup.root");
 	ttbar_matchingDown.push_back("ttbar-mg-matchingdown.root");
	
	/**
	 * wjets
	 */
	wjets.push_back("Wjets-mg.root");
	wjets.push_back("Wjets-2p-mg.root");
	wjets.push_back("Wjets-3p-mg.root");
	wjets.push_back("Wjets-4p-mg.root");
	
	wjets_JECUp.push_back("Wjets-mg_JECUp.root");
	wjets_JECUp.push_back("Wjets-2p-mg_JECUp.root");
	wjets_JECUp.push_back("Wjets-3p-mg_JECUp.root");
	wjets_JECUp.push_back("Wjets-4p-mg_JECUp.root");
	
	wjets_JECDown.push_back("Wjets-mg_JECDown.root");
	wjets_JECDown.push_back("Wjets-2p-mg_JECDown.root");
	wjets_JECDown.push_back("Wjets-3p-mg_JECDown.root");
	wjets_JECDown.push_back("Wjets-4p-mg_JECDown.root");
	
	wjets_JERUp.push_back("Wjets-mg_JERUp.root");
	wjets_JERUp.push_back("Wjets-2p-mg_JERUp.root");
	wjets_JERUp.push_back("Wjets-3p-mg_JERUp.root");
	wjets_JERUp.push_back("Wjets-4p-mg_JERUp.root");
	
	wjets_JERDown.push_back("Wjets-mg_JERDown.root");
	wjets_JERDown.push_back("Wjets-2p-mg_JERDown.root");
	wjets_JERDown.push_back("Wjets-3p-mg_JERDown.root");
	wjets_JERDown.push_back("Wjets-4p-mg_JERDown.root");
	
	wjets_TagUp.push_back("Wjets-mg_TagUp.root");
	wjets_TagUp.push_back("Wjets-2p-mg_TagUp.root");
	wjets_TagUp.push_back("Wjets-3p-mg_TagUp.root");
	wjets_TagUp.push_back("Wjets-4p-mg_TagUp.root");
	
	wjets_TagDown.push_back("Wjets-mg_TagDown.root");
	wjets_TagDown.push_back("Wjets-2p-mg_TagDown.root");
	wjets_TagDown.push_back("Wjets-3p-mg_TagDown.root");
	wjets_TagDown.push_back("Wjets-4p-mg_TagDown.root");
		
	wjets_MistagUp.push_back("Wjets-mg_MistagUp.root");
	wjets_MistagUp.push_back("Wjets-2p-mg_MistagUp.root");
	wjets_MistagUp.push_back("Wjets-3p-mg_MistagUp.root");
	wjets_MistagUp.push_back("Wjets-4p-mg_MistagUp.root");
	
	wjets_MistagDown.push_back("Wjets-mg_MistagDown.root");
	wjets_MistagDown.push_back("Wjets-2p-mg_MistagDown.root");
	wjets_MistagDown.push_back("Wjets-3p-mg_MistagDown.root");
	wjets_MistagDown.push_back("Wjets-4p-mg_MistagDown.root");
	
	wjets_METUnclUp.push_back("Wjets-mg_METUnclUp.root");
	wjets_METUnclUp.push_back("Wjets-2p-mg_METUnclUp.root");
	wjets_METUnclUp.push_back("Wjets-3p-mg_METUnclUp.root");
	wjets_METUnclUp.push_back("Wjets-4p-mg_METUnclUp.root");
	
	wjets_METUnclDown.push_back("Wjets-mg_METUnclDown.root");
	wjets_METUnclDown.push_back("Wjets-2p-mg_METUnclDown.root");
	wjets_METUnclDown.push_back("Wjets-3p-mg_METUnclDown.root");
	wjets_METUnclDown.push_back("Wjets-4p-mg_METUnclDown.root");
	
 	wjets_TrigUp.push_back("Wjets-mg_TrigUp.root");
	wjets_TrigUp.push_back("Wjets-2p-mg_TrigUp.root");
	wjets_TrigUp.push_back("Wjets-3p-mg_TrigUp.root");
 	wjets_TrigUp.push_back("Wjets-4p-mg_TrigUp.root");
	
 	wjets_TrigDown.push_back("Wjets-mg_TrigDown.root");
 	wjets_TrigDown.push_back("Wjets-2p-mg_TrigDown.root");
 	wjets_TrigDown.push_back("Wjets-3p-mg_TrigDown.root");
 	wjets_TrigDown.push_back("Wjets-4p-mg_TrigDown.root");
	
	/**
	 *wjets_w_light
	 */
	wjets_W_light.push_back("Wjets-mg.root");
	wjets_W_light.push_back("Wjets-2p-mg.root");
	wjets_W_light.push_back("Wjets-3p-mg.root");
	wjets_W_light.push_back("Wjets-4p-mg.root");
	
	wjets_W_light_JECUp.push_back("Wjets-mg_JECUp.root");
	wjets_W_light_JECUp.push_back("Wjets-2p-mg_JECUp.root");
	wjets_W_light_JECUp.push_back("Wjets-3p-mg_JECUp.root");
	wjets_W_light_JECUp.push_back("Wjets-4p-mg_JECUp.root");
	
	wjets_W_light_JECDown.push_back("Wjets-mg_JECDown.root");
	wjets_W_light_JECDown.push_back("Wjets-2p-mg_JECDown.root");
	wjets_W_light_JECDown.push_back("Wjets-3p-mg_JECDown.root");
	wjets_W_light_JECDown.push_back("Wjets-4p-mg_JECDown.root");
	
	wjets_W_light_JERUp.push_back("Wjets-mg_JERUp.root");
	wjets_W_light_JERUp.push_back("Wjets-2p-mg_JERUp.root");
	wjets_W_light_JERUp.push_back("Wjets-3p-mg_JERUp.root");
	wjets_W_light_JERUp.push_back("Wjets-4p-mg_JERUp.root");
	
	wjets_W_light_JERDown.push_back("Wjets-mg_JERDown.root");
	wjets_W_light_JERDown.push_back("Wjets-2p-mg_JERDown.root");
	wjets_W_light_JERDown.push_back("Wjets-3p-mg_JERDown.root");
	wjets_W_light_JERDown.push_back("Wjets-4p-mg_JERDown.root");
	
	wjets_W_light_TagUp.push_back("Wjets-mg_TagUp.root");
	wjets_W_light_TagUp.push_back("Wjets-2p-mg_TagUp.root");
	wjets_W_light_TagUp.push_back("Wjets-3p-mg_TagUp.root");
	wjets_W_light_TagUp.push_back("Wjets-4p-mg_TagUp.root");
	
	wjets_W_light_TagDown.push_back("Wjets-mg_TagDown.root");
	wjets_W_light_TagDown.push_back("Wjets-2p-mg_TagDown.root");
	wjets_W_light_TagDown.push_back("Wjets-3p-mg_TagDown.root");
	wjets_W_light_TagDown.push_back("Wjets-4p-mg_TagDown.root");
		
	wjets_W_light_MistagUp.push_back("Wjets-mg_MistagUp.root");
	wjets_W_light_MistagUp.push_back("Wjets-2p-mg_MistagUp.root");
	wjets_W_light_MistagUp.push_back("Wjets-3p-mg_MistagUp.root");
	wjets_W_light_MistagUp.push_back("Wjets-4p-mg_MistagUp.root");
	
	wjets_W_light_MistagDown.push_back("Wjets-mg_MistagDown.root");
	wjets_W_light_MistagDown.push_back("Wjets-2p-mg_MistagDown.root");
	wjets_W_light_MistagDown.push_back("Wjets-3p-mg_MistagDown.root");
	wjets_W_light_MistagDown.push_back("Wjets-4p-mg_MistagDown.root");
	
	wjets_W_light_METUnclUp.push_back("Wjets-mg_METUnclUp.root");
	wjets_W_light_METUnclUp.push_back("Wjets-2p-mg_METUnclUp.root");
	wjets_W_light_METUnclUp.push_back("Wjets-3p-mg_METUnclUp.root");
	wjets_W_light_METUnclUp.push_back("Wjets-4p-mg_METUnclUp.root");
	
	wjets_W_light_METUnclDown.push_back("Wjets-mg_METUnclDown.root");
	wjets_W_light_METUnclDown.push_back("Wjets-2p-mg_METUnclDown.root");
	wjets_W_light_METUnclDown.push_back("Wjets-3p-mg_METUnclDown.root");
	wjets_W_light_METUnclDown.push_back("Wjets-4p-mg_METUnclDown.root");
	
 	wjets_W_light_TrigUp.push_back("Wjets-mg_TrigUp.root");
	wjets_W_light_TrigUp.push_back("Wjets-2p-mg_TrigUp.root");
	wjets_W_light_TrigUp.push_back("Wjets-3p-mg_TrigUp.root");
 	wjets_W_light_TrigUp.push_back("Wjets-4p-mg_TrigUp.root");
	
 	wjets_W_light_TrigDown.push_back("Wjets-mg_TrigDown.root");
 	wjets_W_light_TrigDown.push_back("Wjets-2p-mg_TrigDown.root");
 	wjets_W_light_TrigDown.push_back("Wjets-3p-mg_TrigDown.root");
 	wjets_W_light_TrigDown.push_back("Wjets-4p-mg_TrigDown.root");
	
	/**
	 *wjets_w_other
	 */
	wjets_W_other.push_back("Wjets-mg.root");
	wjets_W_other.push_back("Wjets-2p-mg.root");
	wjets_W_other.push_back("Wjets-3p-mg.root");
	wjets_W_other.push_back("Wjets-4p-mg.root");
	
	wjets_W_other_JECUp.push_back("Wjets-mg_JECUp.root");
	wjets_W_other_JECUp.push_back("Wjets-2p-mg_JECUp.root");
	wjets_W_other_JECUp.push_back("Wjets-3p-mg_JECUp.root");
	wjets_W_other_JECUp.push_back("Wjets-4p-mg_JECUp.root");
	
	wjets_W_other_JECDown.push_back("Wjets-mg_JECDown.root");
	wjets_W_other_JECDown.push_back("Wjets-2p-mg_JECDown.root");
	wjets_W_other_JECDown.push_back("Wjets-3p-mg_JECDown.root");
	wjets_W_other_JECDown.push_back("Wjets-4p-mg_JECDown.root");
	
	wjets_W_other_JERUp.push_back("Wjets-mg_JERUp.root");
	wjets_W_other_JERUp.push_back("Wjets-2p-mg_JERUp.root");
	wjets_W_other_JERUp.push_back("Wjets-3p-mg_JERUp.root");
	wjets_W_other_JERUp.push_back("Wjets-4p-mg_JERUp.root");
	
	wjets_W_other_JERDown.push_back("Wjets-mg_JERDown.root");
	wjets_W_other_JERDown.push_back("Wjets-2p-mg_JERDown.root");
	wjets_W_other_JERDown.push_back("Wjets-3p-mg_JERDown.root");
	wjets_W_other_JERDown.push_back("Wjets-4p-mg_JERDown.root");
	
	wjets_W_other_TagUp.push_back("Wjets-mg_TagUp.root");
	wjets_W_other_TagUp.push_back("Wjets-2p-mg_TagUp.root");
	wjets_W_other_TagUp.push_back("Wjets-3p-mg_TagUp.root");
	wjets_W_other_TagUp.push_back("Wjets-4p-mg_TagUp.root");
	
	wjets_W_other_TagDown.push_back("Wjets-mg_TagDown.root");
	wjets_W_other_TagDown.push_back("Wjets-2p-mg_TagDown.root");
	wjets_W_other_TagDown.push_back("Wjets-3p-mg_TagDown.root");
	wjets_W_other_TagDown.push_back("Wjets-4p-mg_TagDown.root");
		
	wjets_W_other_MistagUp.push_back("Wjets-mg_MistagUp.root");
	wjets_W_other_MistagUp.push_back("Wjets-2p-mg_MistagUp.root");
	wjets_W_other_MistagUp.push_back("Wjets-3p-mg_MistagUp.root");
	wjets_W_other_MistagUp.push_back("Wjets-4p-mg_MistagUp.root");
	
	wjets_W_other_MistagDown.push_back("Wjets-mg_MistagDown.root");
	wjets_W_other_MistagDown.push_back("Wjets-2p-mg_MistagDown.root");
	wjets_W_other_MistagDown.push_back("Wjets-3p-mg_MistagDown.root");
	wjets_W_other_MistagDown.push_back("Wjets-4p-mg_MistagDown.root");
	
	wjets_W_other_METUnclUp.push_back("Wjets-mg_METUnclUp.root");
	wjets_W_other_METUnclUp.push_back("Wjets-2p-mg_METUnclUp.root");
	wjets_W_other_METUnclUp.push_back("Wjets-3p-mg_METUnclUp.root");
	wjets_W_other_METUnclUp.push_back("Wjets-4p-mg_METUnclUp.root");
	
	wjets_W_other_METUnclDown.push_back("Wjets-mg_METUnclDown.root");
	wjets_W_other_METUnclDown.push_back("Wjets-2p-mg_METUnclDown.root");
	wjets_W_other_METUnclDown.push_back("Wjets-3p-mg_METUnclDown.root");
	wjets_W_other_METUnclDown.push_back("Wjets-4p-mg_METUnclDown.root");
	
 	wjets_W_other_TrigUp.push_back("Wjets-mg_TrigUp.root");
 	wjets_W_other_TrigUp.push_back("Wjets-2p-mg_TrigUp.root");
 	wjets_W_other_TrigUp.push_back("Wjets-3p-mg_TrigUp.root");
 	wjets_W_other_TrigUp.push_back("Wjets-4p-mg_TrigUp.root");
	
 	wjets_W_other_TrigDown.push_back("Wjets-mg_TrigDown.root");
 	wjets_W_other_TrigDown.push_back("Wjets-2p-mg_TrigDown.root");
 	wjets_W_other_TrigDown.push_back("Wjets-3p-mg_TrigDown.root");
 	wjets_W_other_TrigDown.push_back("Wjets-4p-mg_TrigDown.root");
	
	/**
	 *wjets_WQQ
	 */
	wjets_WQQ.push_back("Wjets-mg.root");
	wjets_WQQ.push_back("Wjets-2p-mg.root");
	wjets_WQQ.push_back("Wjets-3p-mg.root");
	wjets_WQQ.push_back("Wjets-4p-mg.root");
	
	wjets_WQQ_JECUp.push_back("Wjets-mg_JECUp.root");
	wjets_WQQ_JECUp.push_back("Wjets-2p-mg_JECUp.root");
	wjets_WQQ_JECUp.push_back("Wjets-3p-mg_JECUp.root");
	wjets_WQQ_JECUp.push_back("Wjets-4p-mg_JECUp.root");
	
	wjets_WQQ_JECDown.push_back("Wjets-mg_JECDown.root");
	wjets_WQQ_JECDown.push_back("Wjets-2p-mg_JECDown.root");
	wjets_WQQ_JECDown.push_back("Wjets-3p-mg_JECDown.root");
	wjets_WQQ_JECDown.push_back("Wjets-4p-mg_JECDown.root");
	
	wjets_WQQ_JERUp.push_back("Wjets-mg_JERUp.root");
	wjets_WQQ_JERUp.push_back("Wjets-2p-mg_JERUp.root");
	wjets_WQQ_JERUp.push_back("Wjets-3p-mg_JERUp.root");
	wjets_WQQ_JERUp.push_back("Wjets-4p-mg_JERUp.root");
	
	wjets_WQQ_JERDown.push_back("Wjets-mg_JERDown.root");
	wjets_WQQ_JERDown.push_back("Wjets-2p-mg_JERDown.root");
	wjets_WQQ_JERDown.push_back("Wjets-3p-mg_JERDown.root");
	wjets_WQQ_JERDown.push_back("Wjets-4p-mg_JERDown.root");
	
	wjets_WQQ_TagUp.push_back("Wjets-mg_TagUp.root");
	wjets_WQQ_TagUp.push_back("Wjets-2p-mg_TagUp.root");
	wjets_WQQ_TagUp.push_back("Wjets-3p-mg_TagUp.root");
	wjets_WQQ_TagUp.push_back("Wjets-4p-mg_TagUp.root");
	
	wjets_WQQ_TagDown.push_back("Wjets-mg_TagDown.root");
	wjets_WQQ_TagDown.push_back("Wjets-2p-mg_TagDown.root");
	wjets_WQQ_TagDown.push_back("Wjets-3p-mg_TagDown.root");
	wjets_WQQ_TagDown.push_back("Wjets-4p-mg_TagDown.root");
		
	wjets_WQQ_MistagUp.push_back("Wjets-mg_MistagUp.root");
	wjets_WQQ_MistagUp.push_back("Wjets-2p-mg_MistagUp.root");
	wjets_WQQ_MistagUp.push_back("Wjets-3p-mg_MistagUp.root");
	wjets_WQQ_MistagUp.push_back("Wjets-4p-mg_MistagUp.root");
	
	wjets_WQQ_MistagDown.push_back("Wjets-mg_MistagDown.root");
	wjets_WQQ_MistagDown.push_back("Wjets-2p-mg_MistagDown.root");
	wjets_WQQ_MistagDown.push_back("Wjets-3p-mg_MistagDown.root");
	wjets_WQQ_MistagDown.push_back("Wjets-4p-mg_MistagDown.root");
	
	wjets_WQQ_METUnclUp.push_back("Wjets-mg_METUnclUp.root");
	wjets_WQQ_METUnclUp.push_back("Wjets-2p-mg_METUnclUp.root");
	wjets_WQQ_METUnclUp.push_back("Wjets-3p-mg_METUnclUp.root");
	wjets_WQQ_METUnclUp.push_back("Wjets-4p-mg_METUnclUp.root");
	
	wjets_WQQ_METUnclDown.push_back("Wjets-mg_METUnclDown.root");
	wjets_WQQ_METUnclDown.push_back("Wjets-2p-mg_METUnclDown.root");
	wjets_WQQ_METUnclDown.push_back("Wjets-3p-mg_METUnclDown.root");
	wjets_WQQ_METUnclDown.push_back("Wjets-4p-mg_METUnclDown.root");
	
 	wjets_WQQ_TrigUp.push_back("Wjets-mg_TrigUp.root");
 	wjets_WQQ_TrigUp.push_back("Wjets-2p-mg_TrigUp.root");
 	wjets_WQQ_TrigUp.push_back("Wjets-3p-mg_TrigUp.root");
 	wjets_WQQ_TrigUp.push_back("Wjets-4p-mg_TrigUp.root");
 	
 	wjets_WQQ_TrigDown.push_back("Wjets-mg_TrigDown.root");
 	wjets_WQQ_TrigDown.push_back("Wjets-2p-mg_TrigDown.root");
 	wjets_WQQ_TrigDown.push_back("Wjets-3p-mg_TrigDown.root");
 	wjets_WQQ_TrigDown.push_back("Wjets-4p-mg_TrigDown.root");
	
	/**
	 *wjets_Wc
	 */
	wjets_Wc.push_back("Wjets-mg.root");
	wjets_Wc.push_back("Wjets-2p-mg.root");
	wjets_Wc.push_back("Wjets-3p-mg.root");
	wjets_Wc.push_back("Wjets-4p-mg.root");
	
	wjets_Wc_JECUp.push_back("Wjets-mg_JECUp.root");
	wjets_Wc_JECUp.push_back("Wjets-2p-mg_JECUp.root");
	wjets_Wc_JECUp.push_back("Wjets-3p-mg_JECUp.root");
	wjets_Wc_JECUp.push_back("Wjets-4p-mg_JECUp.root");
	
	wjets_Wc_JECDown.push_back("Wjets-mg_JECDown.root");
	wjets_Wc_JECDown.push_back("Wjets-2p-mg_JECDown.root");
	wjets_Wc_JECDown.push_back("Wjets-3p-mg_JECDown.root");
	wjets_Wc_JECDown.push_back("Wjets-4p-mg_JECDown.root");
	
	wjets_Wc_JERUp.push_back("Wjets-mg_JERUp.root");
	wjets_Wc_JERUp.push_back("Wjets-2p-mg_JERUp.root");
	wjets_Wc_JERUp.push_back("Wjets-3p-mg_JERUp.root");
	wjets_Wc_JERUp.push_back("Wjets-4p-mg_JERUp.root");
	
	wjets_Wc_JERDown.push_back("Wjets-mg_JERDown.root");
	wjets_Wc_JERDown.push_back("Wjets-2p-mg_JERDown.root");
	wjets_Wc_JERDown.push_back("Wjets-3p-mg_JERDown.root");
	wjets_Wc_JERDown.push_back("Wjets-4p-mg_JERDown.root");
	
	wjets_Wc_TagUp.push_back("Wjets-mg_TagUp.root");
	wjets_Wc_TagUp.push_back("Wjets-2p-mg_TagUp.root");
	wjets_Wc_TagUp.push_back("Wjets-3p-mg_TagUp.root");
	wjets_Wc_TagUp.push_back("Wjets-4p-mg_TagUp.root");
	
	wjets_Wc_TagDown.push_back("Wjets-mg_TagDown.root");
	wjets_Wc_TagDown.push_back("Wjets-2p-mg_TagDown.root");
	wjets_Wc_TagDown.push_back("Wjets-3p-mg_TagDown.root");
	wjets_Wc_TagDown.push_back("Wjets-4p-mg_TagDown.root");
		
	wjets_Wc_MistagUp.push_back("Wjets-mg_MistagUp.root");
	wjets_Wc_MistagUp.push_back("Wjets-2p-mg_MistagUp.root");
	wjets_Wc_MistagUp.push_back("Wjets-3p-mg_MistagUp.root");
	wjets_Wc_MistagUp.push_back("Wjets-4p-mg_MistagUp.root");
	
	wjets_Wc_MistagDown.push_back("Wjets-mg_MistagDown.root");
	wjets_Wc_MistagDown.push_back("Wjets-2p-mg_MistagDown.root");
	wjets_Wc_MistagDown.push_back("Wjets-3p-mg_MistagDown.root");
	wjets_Wc_MistagDown.push_back("Wjets-4p-mg_MistagDown.root");
	
	wjets_Wc_METUnclUp.push_back("Wjets-mg_METUnclUp.root");
	wjets_Wc_METUnclUp.push_back("Wjets-2p-mg_METUnclUp.root");
	wjets_Wc_METUnclUp.push_back("Wjets-3p-mg_METUnclUp.root");
	wjets_Wc_METUnclUp.push_back("Wjets-4p-mg_METUnclUp.root");
	
	wjets_Wc_METUnclDown.push_back("Wjets-mg_METUnclDown.root");
	wjets_Wc_METUnclDown.push_back("Wjets-2p-mg_METUnclDown.root");
	wjets_Wc_METUnclDown.push_back("Wjets-3p-mg_METUnclDown.root");
	wjets_Wc_METUnclDown.push_back("Wjets-4p-mg_METUnclDown.root");
	
 	wjets_Wc_TrigUp.push_back("Wjets-mg_TrigUp.root");
 	wjets_Wc_TrigUp.push_back("Wjets-2p-mg_TrigUp.root");
 	wjets_Wc_TrigUp.push_back("Wjets-3p-mg_TrigUp.root");
 	wjets_Wc_TrigUp.push_back("Wjets-4p-mg_TrigUp.root");
 	
 	wjets_Wc_TrigDown.push_back("Wjets-mg_TrigDown.root");
 	wjets_Wc_TrigDown.push_back("Wjets-2p-mg_TrigDown.root");
 	wjets_Wc_TrigDown.push_back("Wjets-3p-mg_TrigDown.root");
 	wjets_Wc_TrigDown.push_back("Wjets-4p-mg_TrigDown.root");
	
	wjets_WQQ_matchingUp.push_back("Wjets-mg-matchingup.root");
	wjets_WQQ_matchingDown.push_back("Wjets-mg-mathcingdown.root");
	
	wjets_Wc_matchingUp.push_back("Wjets-mg-matchingup.root");
	wjets_Wc_matchingDown.push_back("Wjets-mg-mathcingdown.root");
	
	wjets_W_light_matchingUp.push_back("Wjets-mg-matchingup.root");
	wjets_W_light_matchingDown.push_back("Wjets-mg-mathcingdown.root");
	
	wjets_W_other_matchingUp.push_back("Wjets-mg-matchingup.root");
	wjets_W_other_matchingDown.push_back("Wjets-mg-mathcingdown.root");
	
	wjets_matchingUp.push_back("Wjets-mg-matchingup.root");
	wjets_matchingDown.push_back("Wjets-mg-mathcingdown.root");
	
	QCD.push_back("SingleMu-Run2011A.root");
	QCD.push_back("MuHad-Run2011B.root");
	QCD.push_back("MuHad-Run2011A.root");

	data.push_back("SingleMu-Run2011A.root");
	data.push_back("SingleMu-Run2011B.root");
	
	/**
	 * pushing everything to the map
	 */
	
	hist_map.insert ( std::pair<string,vector <string> >("Drell-Yan", Drell_Yan));
	hist_map.insert ( std::pair<string,vector <string> >("Drell-Yan_JECUp", Drell_Yan_JECUp));
	hist_map.insert ( std::pair<string,vector <string> >("Drell-Yan_JECDown", Drell_Yan_JECDown));
	hist_map.insert ( std::pair<string,vector <string> >("Drell-Yan_JERUp", Drell_Yan_JERUp));
	hist_map.insert ( std::pair<string,vector <string> >("Drell-Yan_JERDown", Drell_Yan_JERDown));
	hist_map.insert ( std::pair<string,vector <string> >("Drell-Yan_TagUp", Drell_Yan_TagUp));
	hist_map.insert ( std::pair<string,vector <string> >("Drell-Yan_TagDown", Drell_Yan_TagDown));
	hist_map.insert ( std::pair<string,vector <string> >("Drell-Yan_MistagUp", Drell_Yan_MistagUp));
	hist_map.insert ( std::pair<string,vector <string> >("Drell-Yan_MistagDown", Drell_Yan_MistagDown));
	hist_map.insert ( std::pair<string,vector <string> >("Drell-Yan_METUnclUp", Drell_Yan_METUnclUp));
	hist_map.insert ( std::pair<string,vector <string> >("Drell-Yan_METUnclDown", Drell_Yan_METUnclDown));
  	hist_map.insert ( std::pair<string,vector <string> >("Drell-Yan_TrigUp", Drell_Yan_TrigUp));
  	hist_map.insert ( std::pair<string,vector <string> >("Drell-Yan_TrigDown", Drell_Yan_TrigDown));
	
	hist_map.insert ( std::pair<string,vector <string> >("Diboson", Diboson) );
	hist_map.insert ( std::pair<string,vector <string> >("Diboson_JECUp", Diboson_JECUp) );
	hist_map.insert ( std::pair<string,vector <string> >("Diboson_JECDown", Diboson_JECDown) );
	hist_map.insert ( std::pair<string,vector <string> >("Diboson_JERUp", Diboson_JERUp) );
	hist_map.insert ( std::pair<string,vector <string> >("Diboson_JERDown", Diboson_JERDown));
	hist_map.insert ( std::pair<string,vector <string> >("Diboson_TagUp", Diboson_TagUp) );
	hist_map.insert ( std::pair<string,vector <string> >("Diboson_TagDown", Diboson_TagDown));
	hist_map.insert ( std::pair<string,vector <string> >("Diboson_MistagUp", Diboson_MistagUp) );
	hist_map.insert ( std::pair<string,vector <string> >("Diboson_MistagDown", Diboson_MistagDown));
	hist_map.insert ( std::pair<string,vector <string> >("Diboson_METUnclUp", Diboson_METUnclUp) );
	hist_map.insert ( std::pair<string,vector <string> >("Diboson_METUnclDown", Diboson_METUnclDown));
  	hist_map.insert ( std::pair<string,vector <string> >("Diboson_TrigUp", Diboson_TrigUp) );
  	hist_map.insert ( std::pair<string,vector <string> >("Diboson_TrigDown", Diboson_TrigDown));
	
	hist_map.insert ( std::pair<string,vector <string> >("t-ch_pw", t_channel_pw) );
	hist_map.insert ( std::pair<string,vector <string> >("t-ch_pw_JECUp", t_channel_pw_JECUp) );
	hist_map.insert ( std::pair<string,vector <string> >("t-ch_pw_JECDown", t_channel_pw_JECDown) );
	hist_map.insert ( std::pair<string,vector <string> >("t-ch_pw_JERUp", t_channel_pw_JERUp) );
	hist_map.insert ( std::pair<string,vector <string> >("t-ch_pw_JERDown", t_channel_pw_JERDown) );
	hist_map.insert ( std::pair<string,vector <string> >("t-ch_pw_TagUp", t_channel_pw_TagUp) );
	hist_map.insert ( std::pair<string,vector <string> >("t-ch_pw_TagDown", t_channel_pw_TagDown) );
	hist_map.insert ( std::pair<string,vector <string> >("t-ch_pw_MistagUp", t_channel_pw_MistagUp) );
	hist_map.insert ( std::pair<string,vector <string> >("t-ch_pw_MistagDown", t_channel_pw_MistagDown) );
	hist_map.insert ( std::pair<string,vector <string> >("t-ch_pw_METUnclUp", t_channel_pw_METUnclUp) );
	hist_map.insert ( std::pair<string,vector <string> >("t-ch_pw_METUnclDown", t_channel_pw_METUnclDown) );
  	hist_map.insert ( std::pair<string,vector <string> >("t-ch_pw_TrigUp", t_channel_pw_TrigUp) );
  	hist_map.insert ( std::pair<string,vector <string> >("t-ch_pw_TrigDown", t_channel_pw_TrigDown) );
   	hist_map.insert ( std::pair<string,vector <string> >("t-ch_pw_Q2Up", t_channel_pw_Q2Up) );
   	hist_map.insert ( std::pair<string,vector <string> >("t-ch_pw_Q2Down", t_channel_pw_Q2Down) );
	
	hist_map.insert ( std::pair<string,vector <string> >("t-ch_ch", t_channel_ch) );
	hist_map.insert ( std::pair<string,vector <string> >("t-ch_ch_JECUp", t_channel_ch_JECUp) );
	hist_map.insert ( std::pair<string,vector <string> >("t-ch_ch_JECDown", t_channel_ch_JECDown) );
	hist_map.insert ( std::pair<string,vector <string> >("t-ch_ch_JERUp", t_channel_ch_JERUp) );
	hist_map.insert ( std::pair<string,vector <string> >("t-ch_ch_JERDown", t_channel_ch_JERDown) );
	hist_map.insert ( std::pair<string,vector <string> >("t-ch_ch_TagUp", t_channel_ch_TagUp) );
	hist_map.insert ( std::pair<string,vector <string> >("t-ch_ch_TagDown", t_channel_ch_TagDown) );
	hist_map.insert ( std::pair<string,vector <string> >("t-ch_ch_MistagUp", t_channel_ch_MistagUp) );
	hist_map.insert ( std::pair<string,vector <string> >("t-ch_ch_MistagDown", t_channel_ch_MistagDown) );
	hist_map.insert ( std::pair<string,vector <string> >("t-ch_ch_METUnclUp", t_channel_ch_METUnclUp) );
	hist_map.insert ( std::pair<string,vector <string> >("t-ch_ch_METUnclDown", t_channel_ch_METUnclDown) );
  	hist_map.insert ( std::pair<string,vector <string> >("t-ch_ch_TrigUp", t_channel_ch_TrigUp) );
  	hist_map.insert ( std::pair<string,vector <string> >("t-ch_ch_TrigDown", t_channel_ch_TrigDown) );

	hist_map.insert ( std::pair<string,vector <string> >("unphys_ch", unphys_ch) );
	hist_map.insert ( std::pair<string,vector <string> >("unphys_ch_JECUp", unphys_ch_JECUp) );
	hist_map.insert ( std::pair<string,vector <string> >("unphys_ch_JECDown", unphys_ch_JECDown) );
	hist_map.insert ( std::pair<string,vector <string> >("unphys_ch_JERUp", unphys_ch_JERUp) );
	hist_map.insert ( std::pair<string,vector <string> >("unphys_ch_JERDown", unphys_ch_JERDown) );
	hist_map.insert ( std::pair<string,vector <string> >("unphys_ch_TagUp", unphys_ch_TagUp) );
	hist_map.insert ( std::pair<string,vector <string> >("unphys_ch_TagDown", unphys_ch_TagDown) );
	hist_map.insert ( std::pair<string,vector <string> >("unphys_ch_MistagUp", unphys_ch_MistagUp) );
	hist_map.insert ( std::pair<string,vector <string> >("unphys_ch_MistagDown", unphys_ch_MistagDown) );
	hist_map.insert ( std::pair<string,vector <string> >("unphys_ch_METUnclUp", unphys_ch_METUnclUp) );
	hist_map.insert ( std::pair<string,vector <string> >("unphys_ch_METUnclDown", unphys_ch_METUnclDown) );
	
	hist_map.insert ( std::pair<string,vector <string> >("unphys_LVLT_ch", unphys_LVLT_ch) );
	hist_map.insert ( std::pair<string,vector <string> >("unphys_LVLT_ch_JECUp", unphys_LVLT_ch_JECUp) );
	hist_map.insert ( std::pair<string,vector <string> >("unphys_LVLT_ch_JECDown", unphys_LVLT_ch_JECDown) );
	hist_map.insert ( std::pair<string,vector <string> >("unphys_LVLT_ch_JERUp", unphys_LVLT_ch_JERUp) );
	hist_map.insert ( std::pair<string,vector <string> >("unphys_LVLT_ch_JERDown", unphys_LVLT_ch_JERDown) );
	hist_map.insert ( std::pair<string,vector <string> >("unphys_LVLT_ch_TagUp", unphys_LVLT_ch_TagUp) );
	hist_map.insert ( std::pair<string,vector <string> >("unphys_LVLT_ch_TagDown", unphys_LVLT_ch_TagDown) );
	hist_map.insert ( std::pair<string,vector <string> >("unphys_LVLT_ch_MistagUp", unphys_LVLT_ch_MistagUp) );
	hist_map.insert ( std::pair<string,vector <string> >("unphys_LVLT_ch_MistagDown", unphys_LVLT_ch_MistagDown) );
	hist_map.insert ( std::pair<string,vector <string> >("unphys_LVLT_ch_METUnclUp", unphys_LVLT_ch_METUnclUp) );
	hist_map.insert ( std::pair<string,vector <string> >("unphys_LVLT_ch_METUnclDown", unphys_LVLT_ch_METUnclDown) );
	
	hist_map.insert ( std::pair<string,vector <string> >("right_ch", right_ch) );
	hist_map.insert ( std::pair<string,vector <string> >("right_ch_JECUp", right_ch_JECUp) );
	hist_map.insert ( std::pair<string,vector <string> >("right_ch_JECDown", right_ch_JECDown) );
	hist_map.insert ( std::pair<string,vector <string> >("right_ch_JERUp", right_ch_JERUp) );
	hist_map.insert ( std::pair<string,vector <string> >("right_ch_JERDown", right_ch_JERDown) );
	hist_map.insert ( std::pair<string,vector <string> >("right_ch_TagUp", right_ch_TagUp) );
	hist_map.insert ( std::pair<string,vector <string> >("right_ch_TagDown", right_ch_TagDown) );
	hist_map.insert ( std::pair<string,vector <string> >("right_ch_MistagUp", right_ch_MistagUp) );
	hist_map.insert ( std::pair<string,vector <string> >("right_ch_MistagDown", right_ch_MistagDown) );
	hist_map.insert ( std::pair<string,vector <string> >("right_ch_METUnclUp", right_ch_METUnclUp) );
	hist_map.insert ( std::pair<string,vector <string> >("right_ch_METUnclDown", right_ch_METUnclDown) );
	
	hist_map.insert ( std::pair<string,vector <string> >("tensor_ch", tensor_ch) );
	hist_map.insert ( std::pair<string,vector <string> >("tensor_ch_JECUp", tensor_ch_JECUp) );
	hist_map.insert ( std::pair<string,vector <string> >("tensor_ch_JECDown", tensor_ch_JECDown) );
	hist_map.insert ( std::pair<string,vector <string> >("tensor_ch_JERUp", tensor_ch_JERUp) );
	hist_map.insert ( std::pair<string,vector <string> >("tensor_ch_JERDown", tensor_ch_JERDown) );
	hist_map.insert ( std::pair<string,vector <string> >("tensor_ch_TagUp", tensor_ch_TagUp) );
	hist_map.insert ( std::pair<string,vector <string> >("tensor_ch_TagDown", tensor_ch_TagDown) );
	hist_map.insert ( std::pair<string,vector <string> >("tensor_ch_MistagUp", tensor_ch_MistagUp) );
	hist_map.insert ( std::pair<string,vector <string> >("tensor_ch_MistagDown", tensor_ch_MistagDown) );
	hist_map.insert ( std::pair<string,vector <string> >("tensor_ch_METUnclUp", tensor_ch_METUnclUp) );
	hist_map.insert ( std::pair<string,vector <string> >("tensor_ch_METUnclDown", tensor_ch_METUnclDown) );
	
	hist_map.insert ( std::pair<string,vector <string> >("s-ch", s_channel) );
	hist_map.insert ( std::pair<string,vector <string> >("s-ch_JECUp", s_channel_JECUp) );
	hist_map.insert ( std::pair<string,vector <string> >("s-ch_JECDown", s_channel_JECDown) );
	hist_map.insert ( std::pair<string,vector <string> >("s-ch_JERUp", s_channel_JERUp) );
	hist_map.insert ( std::pair<string,vector <string> >("s-ch_JERDown", s_channel_JERDown) );
	hist_map.insert ( std::pair<string,vector <string> >("s-ch_TagUp", s_channel_TagUp) );
	hist_map.insert ( std::pair<string,vector <string> >("s-ch_TagDown", s_channel_TagDown) );
	hist_map.insert ( std::pair<string,vector <string> >("s-ch_MistagUp", s_channel_MistagUp) );
	hist_map.insert ( std::pair<string,vector <string> >("s-ch_MistagDown", s_channel_MistagDown) );
	hist_map.insert ( std::pair<string,vector <string> >("s-ch_METUnclUp", s_channel_METUnclUp) );
	hist_map.insert ( std::pair<string,vector <string> >("s-ch_METUnclDown", s_channel_METUnclDown) );
  	hist_map.insert ( std::pair<string,vector <string> >("s-ch_TrigUp", s_channel_TrigUp) );
  	hist_map.insert ( std::pair<string,vector <string> >("s-ch_TrigDown", s_channel_TrigDown) );

	hist_map.insert ( std::pair<string,vector <string> >("tW-ch", tw_channel) );
	hist_map.insert ( std::pair<string,vector <string> >("tW-ch_JECUp", tw_channel_JECUp) );
	hist_map.insert ( std::pair<string,vector <string> >("tW-ch_JECDown", tw_channel_JECDown) );
	hist_map.insert ( std::pair<string,vector <string> >("tW-ch_JERUp", tw_channel_JERUp) );
	hist_map.insert ( std::pair<string,vector <string> >("tW-ch_JERDown", tw_channel_JERDown) );
	hist_map.insert ( std::pair<string,vector <string> >("tW-ch_TagUp", tw_channel_TagUp) );
	hist_map.insert ( std::pair<string,vector <string> >("tW-ch_TagDown", tw_channel_TagDown) );
	hist_map.insert ( std::pair<string,vector <string> >("tW-ch_MistagUp", tw_channel_MistagUp) );
	hist_map.insert ( std::pair<string,vector <string> >("tW-ch_MistagDown", tw_channel_MistagDown) );
	hist_map.insert ( std::pair<string,vector <string> >("tW-ch_METUnclUp", tw_channel_METUnclUp) );
	hist_map.insert ( std::pair<string,vector <string> >("tW-ch_METUnclDown", tw_channel_METUnclDown) );
  	hist_map.insert ( std::pair<string,vector <string> >("tW-ch_TrigUp", tw_channel_TrigUp) );
  	hist_map.insert ( std::pair<string,vector <string> >("tW-ch_TrigDown", tw_channel_TrigDown) );
   	hist_map.insert ( std::pair<string,vector <string> >("tW-ch_Q2Up", tw_channel_Q2Up));
   	hist_map.insert ( std::pair<string,vector <string> >("tW-ch_Q2Down", tw_channel_Q2Down));


	hist_map.insert ( std::pair<string,vector <string> >("ttbar", ttbar) );
	hist_map.insert ( std::pair<string,vector <string> >("ttbar_JECUp", ttbar_JECUp) );
	hist_map.insert ( std::pair<string,vector <string> >("ttbar_JECDown", ttbar_JECDown) );
	hist_map.insert ( std::pair<string,vector <string> >("ttbar_JERUp", ttbar_JERUp) );
	hist_map.insert ( std::pair<string,vector <string> >("ttbar_JERDown", ttbar_JERDown));
	hist_map.insert ( std::pair<string,vector <string> >("ttbar_TagUp", ttbar_TagUp) );
	hist_map.insert ( std::pair<string,vector <string> >("ttbar_TagDown", ttbar_TagDown));
	hist_map.insert ( std::pair<string,vector <string> >("ttbar_MistagUp", ttbar_MistagUp) );
	hist_map.insert ( std::pair<string,vector <string> >("ttbar_MistagDown", ttbar_MistagDown));
	hist_map.insert ( std::pair<string,vector <string> >("ttbar_METUnclUp", ttbar_METUnclUp) );
	hist_map.insert ( std::pair<string,vector <string> >("ttbar_METUnclDown", ttbar_METUnclDown));
  	hist_map.insert ( std::pair<string,vector <string> >("ttbar_TrigUp", ttbar_TrigUp) );
  	hist_map.insert ( std::pair<string,vector <string> >("ttbar_TrigDown", ttbar_TrigDown));
  	hist_map.insert ( std::pair<string,vector <string> >("ttbar_Q2Up", ttbar_Q2Up) );
   	hist_map.insert ( std::pair<string,vector <string> >("ttbar_Q2Down", ttbar_Q2Down));
   	hist_map.insert ( std::pair<string,vector <string> >("ttbar_matchingUp", ttbar_matchingUp) );
   	hist_map.insert ( std::pair<string,vector <string> >("ttbar_matchingDown", ttbar_matchingDown));	

	hist_map.insert ( std::pair<string,vector <string> >("Wjets", wjets) );
	hist_map.insert ( std::pair<string,vector <string> >("Wjets_JECUp", wjets_JECUp) );
	hist_map.insert ( std::pair<string,vector <string> >("Wjets_JECDown", wjets_JECDown) );
	hist_map.insert ( std::pair<string,vector <string> >("Wjets_JERUp", wjets_JERUp) );
	hist_map.insert ( std::pair<string,vector <string> >("Wjets_JERDown", wjets_JERDown) );
	hist_map.insert ( std::pair<string,vector <string> >("Wjets_TagUp", wjets_TagUp) );
	hist_map.insert ( std::pair<string,vector <string> >("Wjets_TagDown", wjets_TagDown) );
	hist_map.insert ( std::pair<string,vector <string> >("Wjets_MistagUp", wjets_MistagUp) );
	hist_map.insert ( std::pair<string,vector <string> >("Wjets_MistagDown", wjets_MistagDown) );
	hist_map.insert ( std::pair<string,vector <string> >("Wjets_METUnclUp", wjets_METUnclUp) );
	hist_map.insert ( std::pair<string,vector <string> >("Wjets_METUnclDown", wjets_METUnclDown) );
  	hist_map.insert ( std::pair<string,vector <string> >("Wjets_TrigUp", wjets_TrigUp) );
  	hist_map.insert ( std::pair<string,vector <string> >("Wjets_TrigDown", wjets_TrigDown) );
   	hist_map.insert ( std::pair<string,vector <string> >("Wjets_matchingUp", wjets_matchingUp) );
   	hist_map.insert ( std::pair<string,vector <string> >("Wjets_matchingDown", wjets_matchingDown) );

	hist_map.insert ( std::pair<string,vector <string> >("Wjets_WQQ", wjets_WQQ) );
	hist_map.insert ( std::pair<string,vector <string> >("Wjets_WQQ_JECUp", wjets_WQQ_JECUp) );
	hist_map.insert ( std::pair<string,vector <string> >("Wjets_WQQ_JECDown", wjets_WQQ_JECDown) );
	hist_map.insert ( std::pair<string,vector <string> >("Wjets_WQQ_JERUp", wjets_WQQ_JERUp) );
	hist_map.insert ( std::pair<string,vector <string> >("Wjets_WQQ_JERDown", wjets_WQQ_JERDown) );
	hist_map.insert ( std::pair<string,vector <string> >("Wjets_WQQ_TagUp", wjets_WQQ_TagUp) );
	hist_map.insert ( std::pair<string,vector <string> >("Wjets_WQQ_TagDown", wjets_WQQ_TagDown) );
	hist_map.insert ( std::pair<string,vector <string> >("Wjets_WQQ_MistagUp", wjets_WQQ_MistagUp) );
	hist_map.insert ( std::pair<string,vector <string> >("Wjets_WQQ_MistagDown", wjets_WQQ_MistagDown) );
	hist_map.insert ( std::pair<string,vector <string> >("Wjets_WQQ_METUnclUp", wjets_WQQ_METUnclUp) );
	hist_map.insert ( std::pair<string,vector <string> >("Wjets_WQQ_METUnclDown", wjets_WQQ_METUnclDown) );
  	hist_map.insert ( std::pair<string,vector <string> >("Wjets_WQQ_TrigUp", wjets_WQQ_TrigUp) );
  	hist_map.insert ( std::pair<string,vector <string> >("Wjets_WQQ_TrigDown", wjets_WQQ_TrigDown) );
   	hist_map.insert ( std::pair<string,vector <string> >("Wjets_WQQ_matchingUp", wjets_WQQ_matchingUp) );
   	hist_map.insert ( std::pair<string,vector <string> >("Wjets_WQQ_matchingDown", wjets_WQQ_matchingDown) );
	
	hist_map.insert ( std::pair<string,vector <string> >("Wjets_Wc", wjets_Wc) );
	hist_map.insert ( std::pair<string,vector <string> >("Wjets_Wc_JECUp", wjets_Wc_JECUp) );
	hist_map.insert ( std::pair<string,vector <string> >("Wjets_Wc_JECDown", wjets_Wc_JECDown) );
	hist_map.insert ( std::pair<string,vector <string> >("Wjets_Wc_JERUp", wjets_Wc_JERUp) );
	hist_map.insert ( std::pair<string,vector <string> >("Wjets_Wc_JERDown", wjets_Wc_JERDown) );
	hist_map.insert ( std::pair<string,vector <string> >("Wjets_Wc_TagUp", wjets_Wc_TagUp) );
	hist_map.insert ( std::pair<string,vector <string> >("Wjets_Wc_TagDown", wjets_Wc_TagDown) );
	hist_map.insert ( std::pair<string,vector <string> >("Wjets_Wc_MistagUp", wjets_Wc_MistagUp) );
	hist_map.insert ( std::pair<string,vector <string> >("Wjets_Wc_MistagDown", wjets_Wc_MistagDown) );
	hist_map.insert ( std::pair<string,vector <string> >("Wjets_Wc_METUnclUp", wjets_Wc_METUnclUp) );
	hist_map.insert ( std::pair<string,vector <string> >("Wjets_Wc_METUnclDown", wjets_Wc_METUnclDown) );
  	hist_map.insert ( std::pair<string,vector <string> >("Wjets_Wc_TrigUp", wjets_Wc_TrigUp) );
  	hist_map.insert ( std::pair<string,vector <string> >("Wjets_Wc_TrigDown", wjets_Wc_TrigDown) );
   	hist_map.insert ( std::pair<string,vector <string> >("Wjets_Wc_matchingUp", wjets_Wc_matchingUp) );
   	hist_map.insert ( std::pair<string,vector <string> >("Wjets_Wc_matchingDown", wjets_Wc_matchingDown) );
	
	hist_map.insert ( std::pair<string,vector <string> >("Wjets_W_light", wjets_W_light) );
	hist_map.insert ( std::pair<string,vector <string> >("Wjets_W_light_JECUp", wjets_W_light_JECUp) );
	hist_map.insert ( std::pair<string,vector <string> >("Wjets_W_light_JECDown", wjets_W_light_JECDown) );
	hist_map.insert ( std::pair<string,vector <string> >("Wjets_W_light_JERUp", wjets_W_light_JERUp) );
	hist_map.insert ( std::pair<string,vector <string> >("Wjets_W_light_JERDown", wjets_W_light_JERDown) );
	hist_map.insert ( std::pair<string,vector <string> >("Wjets_W_light_TagUp", wjets_W_light_TagUp) );
	hist_map.insert ( std::pair<string,vector <string> >("Wjets_W_light_TagDown", wjets_W_light_TagDown) );
	hist_map.insert ( std::pair<string,vector <string> >("Wjets_W_light_MistagUp", wjets_W_light_MistagUp) );
	hist_map.insert ( std::pair<string,vector <string> >("Wjets_W_light_MistagDown", wjets_W_light_MistagDown) );
	hist_map.insert ( std::pair<string,vector <string> >("Wjets_W_light_METUnclUp", wjets_W_light_METUnclUp) );
	hist_map.insert ( std::pair<string,vector <string> >("Wjets_W_light_METUnclDown", wjets_W_light_METUnclDown) );
  	hist_map.insert ( std::pair<string,vector <string> >("Wjets_W_light_TrigUp", wjets_W_light_TrigUp) );
  	hist_map.insert ( std::pair<string,vector <string> >("Wjets_W_light_TrigDown", wjets_W_light_TrigDown) );
   	hist_map.insert ( std::pair<string,vector <string> >("Wjets_W_light_matchingUp", wjets_W_light_matchingUp) );
   	hist_map.insert ( std::pair<string,vector <string> >("Wjets_W_light_matchingDown", wjets_W_light_matchingDown) );
	
	
	hist_map.insert ( std::pair<string,vector <string> >("Wjets_W_other", wjets_W_other) );
	hist_map.insert ( std::pair<string,vector <string> >("Wjets_W_other_JECUp", wjets_W_other_JECUp) );
	hist_map.insert ( std::pair<string,vector <string> >("Wjets_W_other_JECDown", wjets_W_other_JECDown) );
	hist_map.insert ( std::pair<string,vector <string> >("Wjets_W_other_JERUp", wjets_W_other_JERUp) );
	hist_map.insert ( std::pair<string,vector <string> >("Wjets_W_other_JERDown", wjets_W_other_JERDown) );
	hist_map.insert ( std::pair<string,vector <string> >("Wjets_W_other_TagUp", wjets_W_other_TagUp) );
	hist_map.insert ( std::pair<string,vector <string> >("Wjets_W_other_TagDown", wjets_W_other_TagDown) );
	hist_map.insert ( std::pair<string,vector <string> >("Wjets_W_other_MistagUp", wjets_W_other_MistagUp) );
	hist_map.insert ( std::pair<string,vector <string> >("Wjets_W_other_MistagDown", wjets_W_other_MistagDown) );
	hist_map.insert ( std::pair<string,vector <string> >("Wjets_W_other_METUnclUp", wjets_W_other_METUnclUp) );
	hist_map.insert ( std::pair<string,vector <string> >("Wjets_W_other_METUnclDown", wjets_W_other_METUnclDown) );
  	hist_map.insert ( std::pair<string,vector <string> >("Wjets_W_other_TrigUp", wjets_W_other_TrigUp) );
  	hist_map.insert ( std::pair<string,vector <string> >("Wjets_W_other_TrigDown", wjets_W_other_TrigDown) );
   	hist_map.insert ( std::pair<string,vector <string> >("Wjets_W_other_matchingUp", wjets_W_other_matchingUp) );
   	hist_map.insert ( std::pair<string,vector <string> >("Wjets_W_other_matchingDown", wjets_W_other_matchingDown) );
	

	hist_map.insert (std::pair<string,vector <string> >("QCD", QCD) );
	hist_map.insert (std::pair<string,vector <string> >("data", data));


	hist_creater g;
	g.SetDimension(1);
	g.SetRange(0.,1.);
	g.SetVar("NN_SM");
	g.SetCommonSelection("NN_QCD > 0.7 && Charge_Lep > 0.0");
	g.SetQCDSelection("weight*weight_QCDdata*0.16");
	g.SetMCSelection("weight");
	g.SetNbins(45);
	g.SetOutFileName("histograms_plus.root");
	g.SetMap(hist_map);
	g.SetInDirectory("/afs/cern.ch/work/i/ishvetso/samples_27_01_2014/makeTuples/tuples/");
	g.SetInDirectoryQCD("/afs/cern.ch/work/i/ishvetso/samples_27_01_2014/makeTuples/tuples_QCD/");
	g.SetOutDirectory("/afs/cern.ch/work/i/ishvetso/charge_ratio/NN_ttbar_NN_Wjets/");
	g.SetConvertOption(false);
	g.CreateHists();
	
	
}
