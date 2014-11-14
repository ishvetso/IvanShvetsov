import FWCore.ParameterSet.Config as cms

process = cms.Process( "TEST" )
process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(1000)
)

process.options = cms.untracked.PSet(wantSummary = cms.untracked.bool(True))
process.options = cms.untracked.PSet( allowUnscheduled = cms.untracked.bool(False) )


option = 'RECO' # 'GEN' or 'RECO'

process.load("ExoDiBosonResonances.EDBRCommon.goodMuons_cff")
process.load("ExoDiBosonResonances.EDBRCommon.goodElectrons_cff")
process.load("ExoDiBosonResonances.EDBRCommon.goodJets_cff")

### Hadronic and leptonic boson.
### Naturally, you should choose the one channel you need
process.load("ExoDiBosonResonances.EDBRCommon.leptonicW_cff")
process.load("ExoDiBosonResonances.EDBRCommon.hadronicW_cff")


# Updates
process.goodMuons.src = "slimmedMuons"
process.goodElectrons.src = "slimmedElectrons"
process.goodJets.src = "slimmedJetsAK8"


process.genCollection = cms.EDFilter("CandViewSelector",
                         src = cms.InputTag("prunedGenParticles"),
                         cut = cms.string("")
                         )


# Muons
process.TightMuons = cms.EDProducer("TightMuonSelector",
                         src = cms.InputTag("slimmedMuons"),
                         vertex = cms.InputTag("offlineSlimmedPrimaryVertices")
                         )

# Electrons
process.load("Configuration.StandardSequences.Services_cff")
process.load("Configuration.StandardSequences.Geometry_cff")
process.load("Configuration.StandardSequences.MagneticField_38T_cff")
process.load("Configuration.StandardSequences.FrontierConditions_GlobalTag_cff")
process.load("Configuration.StandardSequences.Reconstruction_cff")
process.load('RecoEgamma.ElectronIdentification.egmGsfElectronIDs_cff')
#process.load('RecoEgamma.ElectronIdentification.ElectronIDValueMapProducer_cfi ')

process.GlobalTag.globaltag = 'PLS170_V7AN1::All'
process.egmGsfElectronIDs.physicsObjectSrc = cms.InputTag('slimmedElectrons')



from RecoEgamma.ElectronIdentification.Identification.cutBasedElectronID_CSA14_PU20bx25_V0_cff import \
          cutBasedElectronID_CSA14_PU20bx25_V0_standalone_tight
process.egmGsfElectronIDs.physicsObjectIDs = cms.VPSet( cms.PSet( idDefinition = cutBasedElectronID_CSA14_PU20bx25_V0_standalone_tight, idMD5 = cms.string('93968aee4532a06bb3dbaf06045725da')))

process.electronIDValueMapProducer.dataFormat = cms.string('PAT')
process.electronIDValueMapProducer.ebReducedRecHitCollection = cms.InputTag('reducedEgamma:reducedEBRecHits')
process.electronIDValueMapProducer.eeReducedRecHitCollection = cms.InputTag('reducedEgamma:reducedEERecHits')
process.electronIDValueMapProducer.esReducedRecHitCollection = cms.InputTag('reducedEgamma:reducedESRecHits')
process.electronIDValueMapProducer.src = cms.InputTag('slimmedElectrons')

process.egmGsfElectronIDSequence = cms.Sequence(process.electronIDValueMapProducer * process.egmGsfElectronIDs)
print process.egmGsfElectronIDs.dumpPython()
#process.egmGsfElectronIDs.electronsArePAT = cms.bool(True)
'''
from PhysicsTools.SelectorUtils.tools.vid_id_tools import * #load python tools for importing VID modules
#add the VID producer to the process
switchOnVIDElectronIdProducer(process)
#example of adding a single VID module to the producer
from RecoEgamma.ElectronIdentification.Identification.cutBasedElectronID_CSA14_PU20bx25_V0_cff import \
          cutBasedElectronID_CSA14_PU20bx25_V0_standalone_tight
setupVIDElectronSelection(process,cutBasedElectronID_CSA14_PU20bx25_V0_standalone_tight)
                         
print "XXXXXXXXXXXX"
print process.electronIDValueMapProducer.dumpPython()
process.electronIDValueMapProducer.eeReducedRecHitCollection = cms.InputTag("reducedEgamma:reducedEERecHits")
process.electronIDValueMapProducer.ebReducedRecHitCollection = cms.InputTag("reducedEgamma:reducedEBRecHits")
process.electronIDValueMapProducer.esReducedRecHitCollection = cms.InputTag("reducedEgamma:reducedESRecHits")
print process.electronIDValueMapProducer.dumpPython()
print process.egmGsfElectronIDs.dumpPython()
print "XXXXXXXXXXXX"'''

process.leptonicVFilter = cms.EDFilter("CandViewCountFilter",
                                       src = cms.InputTag("leptonicV"),
                                       minNumber = cms.uint32(1),
                                      )

process.hadronicVFilter = cms.EDFilter("CandViewCountFilter",
                                       src = cms.InputTag("hadronicV"),
                                       minNumber = cms.uint32(1),
                                      )



process.leptonSequence = cms.Sequence(process.muSequence +
                                      process.eleSequence +
                                      process.leptonicVSequence +
                                      process.leptonicVFilter )

process.jetSequence = cms.Sequence(process.fatJetsSequence +
                                   process.hadronicV +
                                   process.hadronicVFilter)


print "++++++++++ CUTS ++++++++++\n"
print "Leptonic V cut = "+str(process.leptonicV.cut)
print "Hadronic V cut = "+str(process.hadronicV.cut)
print "\n++++++++++++++++++++++++++"

process.treeDumper = cms.EDAnalyzer("EDBRTreeMaker",
                                    originalNEvents = cms.int32(1),
                                    crossSectionPb = cms.double(1),
                                    targetLumiInvPb = cms.double(1.0),
                                    isGen = cms.bool(False),
                                    hadronicVSrc = cms.string("hadronicV"),
                                    leptonicVSrc = cms.string("leptonicV"),
                                    metSrc = cms.string("slimmedMETs"),
                                    genSrc = cms.string("prunedGenParticles"),
                                    )

'''if option=='GEN':
    process.treeDumper.metSrc = 'genMetTrue'
    process.treeDumper.isGen  = True
if option=='RECO':
    process.treeDumper.metSrc = 'slimmedMETs'
    process.treeDumper.isGen  = False'''

### In case you need to select the decay channel at GEN level
process.load("SimGeneral.HepPDTESSource.pythiapdt_cfi")
process.load("ExoDiBosonResonances.EDBRGenStudies.selectLeptonicDecay")
process.load("ExoDiBosonResonances.EDBRGenStudies.selectHadronicDecay")
process.leptonicDecay.src = "prunedGenParticles"
process.hadronicDecay.src = "prunedGenParticles"

process.load("SimGeneral.HepPDTESSource.pythiapdt_cfi")
process.printTree = cms.EDAnalyzer("ParticleListDrawer",
  maxEventsToPrint = cms.untracked.int32(1000),
  printVertex = cms.untracked.bool(False),
  src = cms.InputTag("prunedGenParticles")
)


process.analysis = cms.Path( process.egmGsfElectronIDSequence + process.TightMuons + process.leptonSequence +   process.jetSequence +  process.treeDumper )
#process.analysis = cms.Path( egmGsfElectronIDSequence )



### Source
#process.load("ExoDiBosonResonances.EDBRCommon.simulation.DYJetsToLL_HT-600toInf")
#process.load("ExoDiBosonResonances.EDBRCommon.simulation.RSGravToZZ_kMpl01_M-1000")
#process.source.fileNames = ["file:/afs/cern.ch/work/i/ishvetso/RunII_preparation/samples/Wjets1.root",]
process.maxEvents.input = 1000
process.source = cms.Source("PoolSource",
    secondaryFileNames = cms.untracked.vstring(),
    fileNames = cms.untracked.vstring('file:///afs/cern.ch/work/i/ishvetso/RunII_preparation/samples/RSGraviton_1000_ToWW.root')
    
)




process.load("FWCore.MessageLogger.MessageLogger_cfi")
process.MessageLogger.cerr.FwkReport.reportEvery = 1
process.MessageLogger.cerr.FwkReport.limit = 99999999


'''process.out = cms.OutputModule("PoolOutputModule",
                               fileName = cms.untracked.string('patTuple.root'),
                               ## save only events passing the full path
                               #SelectEvents = cms.untracked.PSet( SelectEvents = cms.vstring('p') ),
                               ## save PAT output; you need a '*' to unpack the list of commands
                               ## 'patEventContent'
                               #outputCommands = cms.untracked.vstring('keep *')
                               )                            
                               
process.outpath = cms.EndPath(process.out)'''

process.TFileService = cms.Service("TFileService",
                                 fileName = cms.string("tree.root")
                                  )