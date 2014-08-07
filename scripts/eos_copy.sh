prefix="/eos/cms/store/group/phys_jetmet/pharris/puppi_v3/WW_13TeV_0/"
for i in $(lcg-ls -b -D srmv2 'srm://srm-eoscms.cern.ch:8443/srm/v2/server?SFN=/eos/cms/store/group/phys_jetmet/pharris/puppi_v3/WW_13TeV_0/')
do
   filename=${i#${prefix}}
   echo $filename
   lcg-cp -b -D srmv2 'srm://srm-eoscms.cern.ch:8443/srm/v2/server?SFN=/eos/cms/store/group/phys_jetmet/pharris/puppi_v3/WW_13TeV_0/'"$filename" file:////storage/1/ishvetso/ntuples_JME-14-001/$filename
done




