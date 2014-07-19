rm RSGravToWW_kMpl01_M-1000_Tune4C_13TeV-pythia8_Spring14.txt QCD_Pt-300to470_Tune4C_13TeV_pythia8_Spring14.txt QCD_Pt-470to600_Tune4C_13TeV_pythia8_Spring14.txt
for i in $(lcg-ls -b -D srmv2 'srm://srm-eoscms.cern.ch:8443/srm/v2/server?SFN=/eos/cms/store/user/rgerosa/MiniNtuple_csa14/QCD_Pt-470to600_Tune4C_13TeV_pythia8_Spring14/')
do
 echo $i >> QCD_Pt-470to600_Tune4C_13TeV_pythia8_Spring14.txt
done

for ii in $(lcg-ls -b -D srmv2 'srm://srm-eoscms.cern.ch:8443/srm/v2/server?SFN=/eos/cms/store/user/rgerosa/MiniNtuple_csa14/QCD_Pt-300to470_Tune4C_13TeV_pythia8_Spring14/')
do
 echo $ii >> QCD_Pt-300to470_Tune4C_13TeV_pythia8_Spring14.txt
done

for iii in $(lcg-ls -b -D srmv2 'srm://srm-eoscms.cern.ch:8443/srm/v2/server?SFN=/eos/cms/store/user/rgerosa/MiniNtuple_csa14/RSGravToWW_kMpl01_M-1000_Tune4C_13TeV-pythia8_Spring14/')
do
 echo $iii >> RSGravToWW_kMpl01_M-1000_Tune4C_13TeV-pythia8_Spring14.txt
done

