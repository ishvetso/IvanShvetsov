import FWCore.ParameterSet.Config as cms

isolatedElectrons = cms.EDFilter("PATElectronSelector",
                             src = cms.InputTag("slimmedElectrons"),
                             cut = cms.string("(pfIsolationVariables().sumChargedHadronPt"                +\
                                              "    + max(0.0, pfIsolationVariables().sumNeutralHadronEt"  +\
                                              "              +pfIsolationVariables().sumPhotonEt"         +\
                                              "          -0.5*pfIsolationVariables().sumPUPt))/pt < 0.33" 
                                             )
                             )

goodElectrons = cms.EDFilter("PATElectronSelector",
                             src = cms.InputTag("isolatedElectrons"),
                             cut = cms.string("pt > 40 & abs(eta) < 2.5 & "+\
                                              "(abs(superCluster().position().eta()) < 1.442 || "+\
                                              "abs(superCluster().position().eta()) > 1.566)"  
                                             )
                             )

eleSequence = cms.Sequence(isolatedElectrons+goodElectrons)

electronIDs = cms.EDFilter("ElectronID",
			   ValueMap_src = cms.InputTag("egmGsfElectronIDs","cutBasedElectronID-CSA14-PU20bx25-V0-standalone-tight"),
                           electron_src = cms.InputTag("slimmedElectrons"),
			    #False -> runs as producer 
			      #True -> filters events
			      filter_flag = cms.bool(False),
			    )
