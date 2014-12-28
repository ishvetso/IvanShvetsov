#!/bin/bash
# to retrieve files from T2_DE_DESY, e.g. when "crab getoutput doesn't work ;) "
for i in $(seq 1 111);
do lcg-cp -b -D srmv2  srm://dcache-se-cms.desy.de:8443/srm/managerv2?SFN=/pnfs/desy.de/cms/tier2/store/user/ishvetso/Phys14-campaign/WJetsToLNu_13TeV-madgraph-pythia8-tauola/WW-analysis/141221_212041/0000/patTuple_$i.root file:///afs/cern.ch/work/i/ishvetso/samples_PHYS14/patTuple_$i.root;
done
# to delete file
lcg-del -b -v -l -D srmv2  srm://dcache-se-cms.desy.de:8443/srm/managerv2?SFN=/pnfs/desy.de/cms/tier2/store/user/ishvetso/WWpt20_semileptonic_GENSIM_48.root
