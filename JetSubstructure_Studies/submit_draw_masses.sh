mkdir -p scripts_masses_draw/
mkdir -p logs_masses_draw/
rm scripts_masses_draw/*.sh
rm logs_masses_draw/*.log
for iTree in "pf" "puppi" "chs"
do
  for iGroom  in "trimmed" "pruned" "softdrop" "raw"
  do
    iName="mass_"$iTree"_"$iGroom
    filename=scripts_masses_draw/$iName".sh"
    SAFE=""
    if [ "$iTree" = "pf" ]; then 
    SAFE="safe" 
    fi
    
    if [ "$iTree" = "chs" ] ; then 
    SAFE="safe" 
    fi
    
    if [ "$iTree" = "pupi" ] ; then 
    SAFE="" 
    fi
    echo $filename
    if [ "$iGroom" = "trimmed" ]; then
    echo "cd /storage/a/ishvetso/git_repository/IvanShvetsov/JetSubstructure_Studies/" >> $filename
    echo "./mass_draw $iTree $iGroom  mtrim"$SAFE"_Rtrim_020_Ptfrac_005 mtrim"$SAFE"_Rtrim_010_Ptfrac_003 mtrim"$SAFE"_Rtrim_020_Ptfrac_003 mtrim"$SAFE"_Rtrim_030_Ptfrac_003"  >> $filename
    fi
    if [ "$iGroom" = "pruned" ]; then
    echo "cd /storage/a/ishvetso/git_repository/IvanShvetsov/JetSubstructure_Studies/" >> $filename
    echo "./mass_draw $iTree $iGroom   mpruned"$SAFE"_zcut_010_R_cut_050 mpruned"$SAFE"_zcut_005_R_cut_050 mpruned"$SAFE"_zcut_005_R_cut_075 mpruned"$SAFE"_zcut_010_R_cut_075 " >> $filename
    fi
    if [ "$iGroom" = "softdrop" ]; then
    echo "cd /storage/a/ishvetso/git_repository/IvanShvetsov/JetSubstructure_Studies/" >> $filename
    echo "./mass_draw $iTree $iGroom  msoftdrop"$SAFE"_beta10 msoftdrop"$SAFE"_beta00 msoftdrop"$SAFE"_beta20" >> $filename
    fi
     if [ "$iGroom" = "raw" ]; then
    echo "cd /storage/a/ishvetso/git_repository/IvanShvetsov/JetSubstructure_Studies/" >> $filename
    echo "./mass_draw $iTree $iGroom  m mraw" >> $filename
    fi
    errorlog="/storage/a/ishvetso/git_repository/IvanShvetsov/JetSubstructure_Studies/logs_masses_draw/mass_"$iTree"_"$iGroom"_error.log"
    outlog="/storage/a/ishvetso/git_repository/IvanShvetsov/JetSubstructure_Studies/logs_masses_draw/mass_"$iTree"_"$iGroom"_output.log"
    qsub -l s_cpu=100:30:0 -e $errorlog -o $outlog -V $filename
  done
done