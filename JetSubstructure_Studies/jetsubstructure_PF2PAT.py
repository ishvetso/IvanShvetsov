## import skeleton process
from PhysicsTools.PatAlgos.patTemplate_cfg import *

# verbose flags for the PF2PAT modules
process.options.allowUnscheduled = cms.untracked.bool(True)
process.load("PhysicsTools.PatAlgos.patSequences_cff")
#process.Tracer = cms.Service("Tracer")
process.TFileService = cms.Service("TFileService", fileName = cms.string("histo.root") )

runOnMC = True

# load the PAT config (for the PAT only part)
process.load("PhysicsTools.PatAlgos.producersLayer1.patCandidates_cff")
process.load("PhysicsTools.PatAlgos.selectionLayer1.selectedPatCandidates_cff")

# An empty postfix means that only PF2PAT is run,
# otherwise both standard PAT and PF2PAT are run. In the latter case PF2PAT
# collections have standard names + postfix (e.g. patElectronPFlow)
postfix = "PFlow"
jetAlgo = "AK5"


# Configure PAT to use PF2PAT instead of AOD sources
# this function will modify the PAT sequences.
from PhysicsTools.PatAlgos.tools.pfTools import *
usePF2PAT(process,runPF2PAT=True, jetAlgo=jetAlgo, runOnMC=runOnMC, postfix=postfix)
# to run second PF2PAT+PAT with different postfix uncomment the following lines
# and add the corresponding sequence to path
#postfix2 = "PFlow2"
#jetAlgo2="AK7"
#usePF2PAT(process,runPF2PAT=True, jetAlgo=jetAlgo2, runOnMC=True, postfix=postfix2)

# to use tau-cleaned jet collection uncomment the following:
#getattr(process,"pfNoTau"+postfix).enable = True

# to switch default tau (HPS) to old default tau (shrinking cone) uncomment
# the following:
# note: in current default taus are not preselected i.e. you have to apply
# selection yourself at analysis level!
#adaptPFTaus(process,"shrinkingConePFTau",postfix=postfix)

from RecoJets.JetProducers.ak5PFJetsTrimmed_cfi import ak5PFJetsTrimmed


from RecoJets.JetProducers.ak5PFJetsPruned_cfi import ak5PFJetsPruned

process.ak5PrunedPFlow = ak5PFJetsPruned.clone(
src = process.pfJetsPFlow.src,
doAreaFastjet = cms.bool(True)
)
process.pfInputsSequence = cms.Sequence(
 # process.pfInputsCA8 *
  process.ak5PrunedPFlow
  #process.pfInputsCA12
    #process.pfInputsCA12 *
  #process.pfInputsAK7 *
  #process.pfInputsAK8
)

from PhysicsTools.PatAlgos.recoLayer0.jetCorrFactors_cfi import *
process.ak5PFJetsPrunedJEC = patJetCorrFactors.clone()
process.ak5PFJetsPrunedJEC.src = 'ak5PrunedPFlow'
# will need to add L2L3 corrections in the cfg
process.ak5PFJetsPrunedJEC.levels = ['L1FastJet', 'L2Relative', 'L3Absolute']
process.ak5PFJetsPrunedJEC.payload = 'AK7PFchs'
process.ak5PFJetsPrunedJEC.useRho = True
## ------------------------------------------------------
#  In addition you usually want to change the following
#  parameters:
## ------------------------------------------------------
#
#   process.GlobalTag.globaltag =  ...    ##  (according to https://twiki.cern.ch/twiki/bin/view/CMS/SWGuideFrontierConditions)
#                                         ##
#   process.source.fileNames =  ...       ##  (e.g. 'file:AOD.root')
#
process.maxEvents.input = 10
#                                         ##
process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring('file:/storage/a/ishvetso/RSGravitonToWW_DIGI_RECO/run_reco_DIGI_L1_DIGI2RAW_HLT_RAW2DIGI_L1Reco_RECO_WW4000_posHCAL_fixTRACK.root')
)                                     ##
process.out = cms.OutputModule("PoolOutputModule",
                               fileName = cms.untracked.string('patTuple.root'),
                               ## save only events passing the full path
                               #SelectEvents = cms.untracked.PSet( SelectEvents = cms.vstring('p') ),
                               ## save PAT output; you need a '*' to unpack the list of commands
                               ## 'patEventContent'
                               outputCommands = cms.untracked.vstring('drop *'
									   ,'keep *_ak5PFJets_*_*'
									  ,'keep *_ak8PFJets_*_*'
									  ,'keep *_ak5PrunedPFlow_*_*'
									  ,'keep *_ca8PFJetsCHS_*_*'
									  ,'keep *_selectedPatJets_*_*'
									  ,'keep *_selectedPatJetsCA8PF_*_*'
									  ,'keep *_pfInputsCA8_*_*')
                               )
                               
process.pPF = cms.Path()
process.pPF +=process.patDefaultSequence
process.pPF += process.pfInputsSequence
process.pPF += process.ak5PFJetsPrunedJEC
process.patJets.embedPFCandidates=True
print process.patJets.jetSource
