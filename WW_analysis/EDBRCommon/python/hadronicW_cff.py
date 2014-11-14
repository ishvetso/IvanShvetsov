import FWCore.ParameterSet.Config as cms


hadronicV = cms.EDFilter("PATJetSelector",
                         src = cms.InputTag("jetsWithTau"),
                           cut = cms.string('pt > 100 & ' + \
			   '(userFloat("ak8PFJetsCHSPrunedLinks") > 50.0) &'+\
			   '(userFloat("ak8PFJetsCHSPrunedLinks") < 110.0)')
                         )

hadronicVSequence = cms.Sequence(hadronicV)
