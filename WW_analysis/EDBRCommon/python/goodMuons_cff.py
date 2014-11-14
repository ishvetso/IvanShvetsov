import FWCore.ParameterSet.Config as cms

goodMuons = cms.EDFilter("CandViewSelector",
                         src = cms.InputTag("TightMuons"),
                         cut = cms.string("pt > 100 & abs(eta) < 2.4 & ( trackIso < 3 ) & (caloIso < 5)")
                         )


muSequence = cms.Sequence(goodMuons )
