import FWCore.ParameterSet.Config as cms

process = cms.Process( "ElectronIsolation" )
process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(1000)
)

process.options = cms.untracked.PSet(wantSummary = cms.untracked.bool(True))
process.options.allowUnscheduled = cms.untracked.bool(False) 

#from CommonTools.PileupAlgos.Puppi_cff import puppi
from RecoJets.JetProducers.ak4PFJetsPuppi_cfi import ak4PFJetsPuppi

process.load("CommonTools.PileupAlgos.Puppi_cff")
process.puppi.candName = cms.InputTag('packedPFCandidates')
process.puppi.vertexName = cms.InputTag('offlineSlimmedPrimaryVertices')

#gedGsfElectrons slimmedElectrons
#particleFlow packedPFCandidates
process.load("CommonTools.ParticleFlow.pfNoPileUpIso_cff")
process.load("CommonTools.ParticleFlow.pfParticleSelection_cff")

process.particleFlowTmpPtrs = cms.EDProducer("PFCandidateFwdPtrProducer",
src = cms.InputTag('particleFlow')
)

process.pfNoPileUpCandidates = process.pfAllChargedHadrons.clone()
process.pfNoPileUpCandidates.pdgId.extend(process.pfAllNeutralHadronsAndPhotons.pdgId)

#gedGsfElectrons
#pfNoPileUpCandidates
process.ElectronIsolation = cms.EDProducer(
    "CITKPFIsolationSumProducer",
    srcToIsolate = cms.InputTag("slimmedElectrons"),
    srcForIsolationCone = cms.InputTag('packedPFCandidates'),
    isolationConeDefinitions = cms.VPSet(
        cms.PSet( isolationAlgo = cms.string('ElectronPFIsolationWithConeVetoEndcap_MapBasedVetoBarrel'), 
                  coneSize = cms.double(0.3),
                  VetoConeSizeBarrel = cms.double(0.0),
                  VetoConeSizeEndcaps = cms.double(0.015),
                  isolateAgainst = cms.string('h+'),
                  miniAODVertexCodes = cms.vuint32(2,3) ),
        cms.PSet( isolationAlgo = cms.string('ElectronPFIsolationWithConeVetoEndcap_MapBasedVetoBarrel'), 
                  coneSize = cms.double(0.3),
                  VetoConeSizeBarrel = cms.double(0.0),
                  VetoConeSizeEndcaps = cms.double(0.0),
                  isolateAgainst = cms.string('h0'),
                  miniAODVertexCodes = cms.vuint32(2,3) ),
        cms.PSet( isolationAlgo = cms.string('ElectronPFIsolationWithConeVetoEndcap_MapBasedVetoBarrel'), 
                  coneSize = cms.double(0.3),
                  VetoConeSizeBarrel = cms.double(0.0),
                  VetoConeSizeEndcaps = cms.double(0.08),
                  isolateAgainst = cms.string('gamma'),
                  miniAODVertexCodes = cms.vuint32(2,3) )
        )
    )

process.treeDumper = cms.EDAnalyzer("TreeMaker",
                                   ValueMaps_ChargedHadrons_src = cms.InputTag("ElectronIsolation", "h+-DR030-BarMapBasedVeto-EndVeto001"),
                                   ValueMaps_NeutralHadrons_src = cms.InputTag("ElectronIsolation", "h0-DR030-BarMapBasedVeto-EndVeto000"),
                                   ValueMaps_Photons_src = cms.InputTag("ElectronIsolation", "gamma-DR030-BarMapBasedVeto-EndVeto008"),
                                   electron_src = cms.InputTag("slimmedElectrons")
                                    )
#process.analysisPath = cms.Path(process.particleFlowTmpPtrs + process.pfParticleSelectionSequence + process.pfNoPileUpCandidates + process.ElectronIsolation + process.treeDumper  )
process.puppi_onMiniAOD = cms.Path(process.ElectronIsolation + process.treeDumper )

process.maxEvents.input = 1000
process.source = cms.Source("PoolSource",
    secondaryFileNames = cms.untracked.vstring(),
    fileNames = cms.untracked.vstring('file:///afs/cern.ch/work/i/ishvetso/RunII_preparation/samples/RSGravitonToWW_kMpl01_M_1000_Tune4C_13TeV_pythia8_PHYS14.root')
    
)
#/afs/cern.ch/work/i/ishvetso/RunII_preparation/samples/RSGravitonToWW_kMpl01_M_1000_Tune4C_13TeV_pythia8_PHYS14.root
#/afs/cern.ch/work/i/ishvetso/EgammaWork/CMSSW_7_2_0/src/RecoEgamma/EgammaIsolationAlgos/test/WToENu_AODSIM.root
process.load("FWCore.MessageLogger.MessageLogger_cfi")
process.MessageLogger.cerr.FwkReport.reportEvery = 1
#process.MessageLogger.cerr.FwkReport.limit = 99999999

process.out = cms.OutputModule("PoolOutputModule",
 fileName = cms.untracked.string('patTuple.root'),
  outputCommands = cms.untracked.vstring('keep *')
)

process.outpath = cms.EndPath(process.out)

process.TFileService = cms.Service("TFileService",
                                 fileName = cms.string("tree.root")
                                  )
