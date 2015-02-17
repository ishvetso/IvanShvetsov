import FWCore.ParameterSet.Config as cms

process = cms.Process( "isotest" )
process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(1000)
)

process.options = cms.untracked.PSet(wantSummary = cms.untracked.bool(True))
process.options.allowUnscheduled = cms.untracked.bool(False) 


process.maxEvents.input = 1000
process.source = cms.Source("PoolSource",
    secondaryFileNames = cms.untracked.vstring(),
    fileNames = cms.untracked.vstring('file:///afs/cern.ch/work/i/ishvetso/RunII_preparation/samples/RSGravitonToWW_kMpl01_M_1000_Tune4C_13TeV_pythia8_PHYS14.root')
    #cms.untracked.vstring('file:///afs/cern.ch/work/i/ishvetso/EgammaWork/CMSSW_7_2_0/src/RecoEgamma/EgammaIsolationAlgos/test/WToENu_AODSIM.root')
    
)
#slimmedPhotons gedPhotons
#packedPFCandidates particleFlow
process.egmPhotonIsolation = cms.EDProducer(
    "CITKPFIsolationSumProducer",
    srcToIsolate = cms.InputTag("slimmedPhotons"),
    srcForIsolationCone = cms.InputTag('packedPFCandidates'),
    isolationConeDefinitions = cms.VPSet(
        cms.PSet( isolationAlgo = cms.string('PhotonPFIsolationWithMapBasedVeto'), 
                  coneSize = cms.double(0.3),
                  isolateAgainst = cms.string('h+'),
		  vertexCollection = cms.string('offlineSlimmedPrimaryVertices'),
		  dzMax = cms.double(0.2),
		  dxyMax = cms.double(0.1), 
		 )
    )
  )	

process.analysis = cms.Path(process.egmPhotonIsolation)


process.load("FWCore.MessageLogger.MessageLogger_cfi")
process.MessageLogger.cerr.FwkReport.reportEvery = 1
#process.MessageLogger.cerr.FwkReport.limit = 99999999


process.out = cms.OutputModule("PoolOutputModule",
                               fileName = cms.untracked.string('patTuple.root'),
                               ## save only events passing the full path
                               #SelectEvents = cms.untracked.PSet( SelectEvents = cms.vstring('p') ),
                               ## save PAT output; you need a '*' to unpack the list of commands
                               ## 'patEventContent'
                               outputCommands = cms.untracked.vstring('keep *')
                               )                            
                               
process.outpath = cms.EndPath(process.out)