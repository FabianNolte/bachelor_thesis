#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "Cint" for configuration "Release"
set_property(TARGET Cint APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Cint PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libCint.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/libCint.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS Cint )
list(APPEND _IMPORT_CHECK_FILES_FOR_Cint "${_IMPORT_PREFIX}/lib/libCint.lib" "${_IMPORT_PREFIX}/bin/libCint.dll" )

# Import target "Reflex" for configuration "Release"
set_property(TARGET Reflex APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Reflex PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libReflex.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/libReflex.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS Reflex )
list(APPEND _IMPORT_CHECK_FILES_FOR_Reflex "${_IMPORT_PREFIX}/lib/libReflex.lib" "${_IMPORT_PREFIX}/bin/libReflex.dll" )

# Import target "genmap" for configuration "Release"
set_property(TARGET genmap APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(genmap PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/genmap.exe"
  )

list(APPEND _IMPORT_CHECK_TARGETS genmap )
list(APPEND _IMPORT_CHECK_FILES_FOR_genmap "${_IMPORT_PREFIX}/bin/genmap.exe" )

# Import target "Cintex" for configuration "Release"
set_property(TARGET Cintex APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Cintex PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libCintex.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "Core"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/libCintex.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS Cintex )
list(APPEND _IMPORT_CHECK_FILES_FOR_Cintex "${_IMPORT_PREFIX}/lib/libCintex.lib" "${_IMPORT_PREFIX}/bin/libCintex.dll" )

# Import target "Rint" for configuration "Release"
set_property(TARGET Rint APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Rint PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libRint.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/libRint.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS Rint )
list(APPEND _IMPORT_CHECK_FILES_FOR_Rint "${_IMPORT_PREFIX}/lib/libRint.lib" "${_IMPORT_PREFIX}/bin/libRint.dll" )

# Import target "Thread" for configuration "Release"
set_property(TARGET Thread APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Thread PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libThread.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/libThread.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS Thread )
list(APPEND _IMPORT_CHECK_FILES_FOR_Thread "${_IMPORT_PREFIX}/lib/libThread.lib" "${_IMPORT_PREFIX}/bin/libThread.dll" )

# Import target "rootcint" for configuration "Release"
set_property(TARGET rootcint APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(rootcint PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/rootcint.exe"
  )

list(APPEND _IMPORT_CHECK_TARGETS rootcint )
list(APPEND _IMPORT_CHECK_FILES_FOR_rootcint "${_IMPORT_PREFIX}/bin/rootcint.exe" )

# Import target "rlibmap" for configuration "Release"
set_property(TARGET rlibmap APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(rlibmap PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/rlibmap.exe"
  )

list(APPEND _IMPORT_CHECK_TARGETS rlibmap )
list(APPEND _IMPORT_CHECK_FILES_FOR_rlibmap "${_IMPORT_PREFIX}/bin/rlibmap.exe" )

# Import target "Core" for configuration "Release"
set_property(TARGET Core APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Core PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libCore.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/libCore.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS Core )
list(APPEND _IMPORT_CHECK_FILES_FOR_Core "${_IMPORT_PREFIX}/lib/libCore.lib" "${_IMPORT_PREFIX}/bin/libCore.dll" )

# Import target "rmkdepend" for configuration "Release"
set_property(TARGET rmkdepend APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(rmkdepend PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/rmkdepend.exe"
  )

list(APPEND _IMPORT_CHECK_TARGETS rmkdepend )
list(APPEND _IMPORT_CHECK_FILES_FOR_rmkdepend "${_IMPORT_PREFIX}/bin/rmkdepend.exe" )

# Import target "bindexplib" for configuration "Release"
set_property(TARGET bindexplib APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(bindexplib PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/bindexplib.exe"
  )

list(APPEND _IMPORT_CHECK_TARGETS bindexplib )
list(APPEND _IMPORT_CHECK_FILES_FOR_bindexplib "${_IMPORT_PREFIX}/bin/bindexplib.exe" )

# Import target "MathCore" for configuration "Release"
set_property(TARGET MathCore APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(MathCore PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libMathCore.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/libMathCore.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS MathCore )
list(APPEND _IMPORT_CHECK_FILES_FOR_MathCore "${_IMPORT_PREFIX}/lib/libMathCore.lib" "${_IMPORT_PREFIX}/bin/libMathCore.dll" )

# Import target "MathMore" for configuration "Release"
set_property(TARGET MathMore APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(MathMore PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libMathMore.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/libMathMore.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS MathMore )
list(APPEND _IMPORT_CHECK_FILES_FOR_MathMore "${_IMPORT_PREFIX}/lib/libMathMore.lib" "${_IMPORT_PREFIX}/bin/libMathMore.dll" )

# Import target "Matrix" for configuration "Release"
set_property(TARGET Matrix APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Matrix PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libMatrix.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/libMatrix.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS Matrix )
list(APPEND _IMPORT_CHECK_FILES_FOR_Matrix "${_IMPORT_PREFIX}/lib/libMatrix.lib" "${_IMPORT_PREFIX}/bin/libMatrix.dll" )

# Import target "Minuit" for configuration "Release"
set_property(TARGET Minuit APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Minuit PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libMinuit.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/libMinuit.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS Minuit )
list(APPEND _IMPORT_CHECK_FILES_FOR_Minuit "${_IMPORT_PREFIX}/lib/libMinuit.lib" "${_IMPORT_PREFIX}/bin/libMinuit.dll" )

# Import target "Minuit2" for configuration "Release"
set_property(TARGET Minuit2 APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Minuit2 PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libMinuit2.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/libMinuit2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS Minuit2 )
list(APPEND _IMPORT_CHECK_FILES_FOR_Minuit2 "${_IMPORT_PREFIX}/lib/libMinuit2.lib" "${_IMPORT_PREFIX}/bin/libMinuit2.dll" )

# Import target "Fumili" for configuration "Release"
set_property(TARGET Fumili APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Fumili PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libFumili.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/libFumili.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS Fumili )
list(APPEND _IMPORT_CHECK_FILES_FOR_Fumili "${_IMPORT_PREFIX}/lib/libFumili.lib" "${_IMPORT_PREFIX}/bin/libFumili.dll" )

# Import target "Physics" for configuration "Release"
set_property(TARGET Physics APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Physics PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libPhysics.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/libPhysics.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS Physics )
list(APPEND _IMPORT_CHECK_FILES_FOR_Physics "${_IMPORT_PREFIX}/lib/libPhysics.lib" "${_IMPORT_PREFIX}/bin/libPhysics.dll" )

# Import target "MLP" for configuration "Release"
set_property(TARGET MLP APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(MLP PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libMLP.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/libMLP.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS MLP )
list(APPEND _IMPORT_CHECK_FILES_FOR_MLP "${_IMPORT_PREFIX}/lib/libMLP.lib" "${_IMPORT_PREFIX}/bin/libMLP.dll" )

# Import target "Quadp" for configuration "Release"
set_property(TARGET Quadp APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Quadp PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libQuadp.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/libQuadp.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS Quadp )
list(APPEND _IMPORT_CHECK_FILES_FOR_Quadp "${_IMPORT_PREFIX}/lib/libQuadp.lib" "${_IMPORT_PREFIX}/bin/libQuadp.dll" )

# Import target "Foam" for configuration "Release"
set_property(TARGET Foam APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Foam PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libFoam.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/libFoam.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS Foam )
list(APPEND _IMPORT_CHECK_FILES_FOR_Foam "${_IMPORT_PREFIX}/lib/libFoam.lib" "${_IMPORT_PREFIX}/bin/libFoam.dll" )

# Import target "Smatrix" for configuration "Release"
set_property(TARGET Smatrix APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Smatrix PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libSmatrix.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "Core;Cint"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/libSmatrix.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS Smatrix )
list(APPEND _IMPORT_CHECK_FILES_FOR_Smatrix "${_IMPORT_PREFIX}/lib/libSmatrix.lib" "${_IMPORT_PREFIX}/bin/libSmatrix.dll" )

# Import target "SPlot" for configuration "Release"
set_property(TARGET SPlot APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(SPlot PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libSPlot.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/libSPlot.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS SPlot )
list(APPEND _IMPORT_CHECK_FILES_FOR_SPlot "${_IMPORT_PREFIX}/lib/libSPlot.lib" "${_IMPORT_PREFIX}/bin/libSPlot.dll" )

# Import target "GenVector" for configuration "Release"
set_property(TARGET GenVector APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(GenVector PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libGenVector.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "Core;Cint"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/libGenVector.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS GenVector )
list(APPEND _IMPORT_CHECK_FILES_FOR_GenVector "${_IMPORT_PREFIX}/lib/libGenVector.lib" "${_IMPORT_PREFIX}/bin/libGenVector.dll" )

# Import target "Genetic" for configuration "Release"
set_property(TARGET Genetic APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Genetic PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libGenetic.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "Core"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/libGenetic.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS Genetic )
list(APPEND _IMPORT_CHECK_FILES_FOR_Genetic "${_IMPORT_PREFIX}/lib/libGenetic.lib" "${_IMPORT_PREFIX}/bin/libGenetic.dll" )

# Import target "Unuran" for configuration "Release"
set_property(TARGET Unuran APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Unuran PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libUnuran.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "Cint;Core"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/libUnuran.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS Unuran )
list(APPEND _IMPORT_CHECK_FILES_FOR_Unuran "${_IMPORT_PREFIX}/lib/libUnuran.lib" "${_IMPORT_PREFIX}/bin/libUnuran.dll" )

# Import target "Hist" for configuration "Release"
set_property(TARGET Hist APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Hist PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libHist.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/libHist.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS Hist )
list(APPEND _IMPORT_CHECK_FILES_FOR_Hist "${_IMPORT_PREFIX}/lib/libHist.lib" "${_IMPORT_PREFIX}/bin/libHist.dll" )

# Import target "HistPainter" for configuration "Release"
set_property(TARGET HistPainter APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(HistPainter PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libHistPainter.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/libHistPainter.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS HistPainter )
list(APPEND _IMPORT_CHECK_FILES_FOR_HistPainter "${_IMPORT_PREFIX}/lib/libHistPainter.lib" "${_IMPORT_PREFIX}/bin/libHistPainter.dll" )

# Import target "Spectrum" for configuration "Release"
set_property(TARGET Spectrum APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Spectrum PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libSpectrum.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/libSpectrum.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS Spectrum )
list(APPEND _IMPORT_CHECK_FILES_FOR_Spectrum "${_IMPORT_PREFIX}/lib/libSpectrum.lib" "${_IMPORT_PREFIX}/bin/libSpectrum.dll" )

# Import target "SpectrumPainter" for configuration "Release"
set_property(TARGET SpectrumPainter APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(SpectrumPainter PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libSpectrumPainter.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/libSpectrumPainter.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS SpectrumPainter )
list(APPEND _IMPORT_CHECK_FILES_FOR_SpectrumPainter "${_IMPORT_PREFIX}/lib/libSpectrumPainter.lib" "${_IMPORT_PREFIX}/bin/libSpectrumPainter.dll" )

# Import target "Tree" for configuration "Release"
set_property(TARGET Tree APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Tree PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libTree.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/libTree.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS Tree )
list(APPEND _IMPORT_CHECK_FILES_FOR_Tree "${_IMPORT_PREFIX}/lib/libTree.lib" "${_IMPORT_PREFIX}/bin/libTree.dll" )

# Import target "TreePlayer" for configuration "Release"
set_property(TARGET TreePlayer APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(TreePlayer PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libTreePlayer.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/libTreePlayer.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS TreePlayer )
list(APPEND _IMPORT_CHECK_FILES_FOR_TreePlayer "${_IMPORT_PREFIX}/lib/libTreePlayer.lib" "${_IMPORT_PREFIX}/bin/libTreePlayer.dll" )

# Import target "TreeViewer" for configuration "Release"
set_property(TARGET TreeViewer APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(TreeViewer PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libTreeViewer.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "TreePlayer"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/libTreeViewer.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS TreeViewer )
list(APPEND _IMPORT_CHECK_FILES_FOR_TreeViewer "${_IMPORT_PREFIX}/lib/libTreeViewer.lib" "${_IMPORT_PREFIX}/bin/libTreeViewer.dll" )

# Import target "RIO" for configuration "Release"
set_property(TARGET RIO APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(RIO PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libRIO.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/libRIO.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS RIO )
list(APPEND _IMPORT_CHECK_FILES_FOR_RIO "${_IMPORT_PREFIX}/lib/libRIO.lib" "${_IMPORT_PREFIX}/bin/libRIO.dll" )

# Import target "SQLIO" for configuration "Release"
set_property(TARGET SQLIO APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(SQLIO PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libSQLIO.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/libSQLIO.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS SQLIO )
list(APPEND _IMPORT_CHECK_FILES_FOR_SQLIO "${_IMPORT_PREFIX}/lib/libSQLIO.lib" "${_IMPORT_PREFIX}/bin/libSQLIO.dll" )

# Import target "XMLIO" for configuration "Release"
set_property(TARGET XMLIO APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(XMLIO PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libXMLIO.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/libXMLIO.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS XMLIO )
list(APPEND _IMPORT_CHECK_FILES_FOR_XMLIO "${_IMPORT_PREFIX}/lib/libXMLIO.lib" "${_IMPORT_PREFIX}/bin/libXMLIO.dll" )

# Import target "Net" for configuration "Release"
set_property(TARGET Net APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Net PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libNet.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/libNet.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS Net )
list(APPEND _IMPORT_CHECK_FILES_FOR_Net "${_IMPORT_PREFIX}/lib/libNet.lib" "${_IMPORT_PREFIX}/bin/libNet.dll" )

# Import target "RootAuth" for configuration "Release"
set_property(TARGET RootAuth APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(RootAuth PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libRootAuth.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/libRootAuth.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS RootAuth )
list(APPEND _IMPORT_CHECK_FILES_FOR_RootAuth "${_IMPORT_PREFIX}/lib/libRootAuth.lib" "${_IMPORT_PREFIX}/bin/libRootAuth.dll" )

# Import target "RHTTP" for configuration "Release"
set_property(TARGET RHTTP APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(RHTTP PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libRHTTP.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/libRHTTP.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS RHTTP )
list(APPEND _IMPORT_CHECK_FILES_FOR_RHTTP "${_IMPORT_PREFIX}/lib/libRHTTP.lib" "${_IMPORT_PREFIX}/bin/libRHTTP.dll" )

# Import target "Gpad" for configuration "Release"
set_property(TARGET Gpad APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Gpad PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libGpad.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/libGpad.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS Gpad )
list(APPEND _IMPORT_CHECK_FILES_FOR_Gpad "${_IMPORT_PREFIX}/lib/libGpad.lib" "${_IMPORT_PREFIX}/bin/libGpad.dll" )

# Import target "Graf" for configuration "Release"
set_property(TARGET Graf APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Graf PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libGraf.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/libGraf.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS Graf )
list(APPEND _IMPORT_CHECK_FILES_FOR_Graf "${_IMPORT_PREFIX}/lib/libGraf.lib" "${_IMPORT_PREFIX}/bin/libGraf.dll" )

# Import target "Postscript" for configuration "Release"
set_property(TARGET Postscript APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Postscript PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libPostscript.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/libPostscript.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS Postscript )
list(APPEND _IMPORT_CHECK_FILES_FOR_Postscript "${_IMPORT_PREFIX}/lib/libPostscript.lib" "${_IMPORT_PREFIX}/bin/libPostscript.dll" )

# Import target "mathtext" for configuration "Release"
set_property(TARGET mathtext APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(mathtext PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/mathtext.lib"
  )

list(APPEND _IMPORT_CHECK_TARGETS mathtext )
list(APPEND _IMPORT_CHECK_FILES_FOR_mathtext "${_IMPORT_PREFIX}/lib/mathtext.lib" )

# Import target "Win32gdk" for configuration "Release"
set_property(TARGET Win32gdk APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Win32gdk PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libWin32gdk.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "Cint;Core;Graf"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/libWin32gdk.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS Win32gdk )
list(APPEND _IMPORT_CHECK_FILES_FOR_Win32gdk "${_IMPORT_PREFIX}/lib/libWin32gdk.lib" "${_IMPORT_PREFIX}/bin/libWin32gdk.dll" )

# Import target "ASImage" for configuration "Release"
set_property(TARGET ASImage APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(ASImage PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libASImage.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "Core"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/libASImage.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS ASImage )
list(APPEND _IMPORT_CHECK_FILES_FOR_ASImage "${_IMPORT_PREFIX}/lib/libASImage.lib" "${_IMPORT_PREFIX}/bin/libASImage.dll" )

# Import target "ASImageGui" for configuration "Release"
set_property(TARGET ASImageGui APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(ASImageGui PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libASImageGui.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/libASImageGui.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS ASImageGui )
list(APPEND _IMPORT_CHECK_FILES_FOR_ASImageGui "${_IMPORT_PREFIX}/lib/libASImageGui.lib" "${_IMPORT_PREFIX}/bin/libASImageGui.dll" )

# Import target "Graf3d" for configuration "Release"
set_property(TARGET Graf3d APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Graf3d PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libGraf3d.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/libGraf3d.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS Graf3d )
list(APPEND _IMPORT_CHECK_FILES_FOR_Graf3d "${_IMPORT_PREFIX}/lib/libGraf3d.lib" "${_IMPORT_PREFIX}/bin/libGraf3d.dll" )

# Import target "Eve" for configuration "Release"
set_property(TARGET Eve APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Eve PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libEve.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "GLEW;FTGL;Cint;Core"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/libEve.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS Eve )
list(APPEND _IMPORT_CHECK_FILES_FOR_Eve "${_IMPORT_PREFIX}/lib/libEve.lib" "${_IMPORT_PREFIX}/bin/libEve.dll" )

# Import target "RGL" for configuration "Release"
set_property(TARGET RGL APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(RGL PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libRGL.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "GLEW;FTGL"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/libRGL.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS RGL )
list(APPEND _IMPORT_CHECK_FILES_FOR_RGL "${_IMPORT_PREFIX}/lib/libRGL.lib" "${_IMPORT_PREFIX}/bin/libRGL.dll" )

# Import target "GLEW" for configuration "Release"
set_property(TARGET GLEW APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(GLEW PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libGLEW.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/libGLEW.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS GLEW )
list(APPEND _IMPORT_CHECK_FILES_FOR_GLEW "${_IMPORT_PREFIX}/lib/libGLEW.lib" "${_IMPORT_PREFIX}/bin/libGLEW.dll" )

# Import target "FTGL" for configuration "Release"
set_property(TARGET FTGL APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(FTGL PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libFTGL.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/libFTGL.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS FTGL )
list(APPEND _IMPORT_CHECK_FILES_FOR_FTGL "${_IMPORT_PREFIX}/lib/libFTGL.lib" "${_IMPORT_PREFIX}/bin/libFTGL.dll" )

# Import target "Gviz3d" for configuration "Release"
set_property(TARGET Gviz3d APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Gviz3d PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libGviz3d.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "GLEW;FTGL"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/libGviz3d.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS Gviz3d )
list(APPEND _IMPORT_CHECK_FILES_FOR_Gviz3d "${_IMPORT_PREFIX}/lib/libGviz3d.lib" "${_IMPORT_PREFIX}/bin/libGviz3d.dll" )

# Import target "Gui" for configuration "Release"
set_property(TARGET Gui APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Gui PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libGui.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "Cint;Core"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/libGui.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS Gui )
list(APPEND _IMPORT_CHECK_FILES_FOR_Gui "${_IMPORT_PREFIX}/lib/libGui.lib" "${_IMPORT_PREFIX}/bin/libGui.dll" )

# Import target "Ged" for configuration "Release"
set_property(TARGET Ged APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Ged PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libGed.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/libGed.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS Ged )
list(APPEND _IMPORT_CHECK_FILES_FOR_Ged "${_IMPORT_PREFIX}/lib/libGed.lib" "${_IMPORT_PREFIX}/bin/libGed.dll" )

# Import target "FitPanel" for configuration "Release"
set_property(TARGET FitPanel APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(FitPanel PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libFitPanel.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/libFitPanel.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS FitPanel )
list(APPEND _IMPORT_CHECK_FILES_FOR_FitPanel "${_IMPORT_PREFIX}/lib/libFitPanel.lib" "${_IMPORT_PREFIX}/bin/libFitPanel.dll" )

# Import target "GuiBld" for configuration "Release"
set_property(TARGET GuiBld APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(GuiBld PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libGuiBld.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/libGuiBld.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS GuiBld )
list(APPEND _IMPORT_CHECK_FILES_FOR_GuiBld "${_IMPORT_PREFIX}/lib/libGuiBld.lib" "${_IMPORT_PREFIX}/bin/libGuiBld.dll" )

# Import target "GuiHtml" for configuration "Release"
set_property(TARGET GuiHtml APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(GuiHtml PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libGuiHtml.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/libGuiHtml.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS GuiHtml )
list(APPEND _IMPORT_CHECK_FILES_FOR_GuiHtml "${_IMPORT_PREFIX}/lib/libGuiHtml.lib" "${_IMPORT_PREFIX}/bin/libGuiHtml.dll" )

# Import target "Recorder" for configuration "Release"
set_property(TARGET Recorder APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Recorder PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libRecorder.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/libRecorder.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS Recorder )
list(APPEND _IMPORT_CHECK_FILES_FOR_Recorder "${_IMPORT_PREFIX}/lib/libRecorder.lib" "${_IMPORT_PREFIX}/bin/libRecorder.dll" )

# Import target "SessionViewer" for configuration "Release"
set_property(TARGET SessionViewer APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(SessionViewer PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libSessionViewer.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/libSessionViewer.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS SessionViewer )
list(APPEND _IMPORT_CHECK_FILES_FOR_SessionViewer "${_IMPORT_PREFIX}/lib/libSessionViewer.lib" "${_IMPORT_PREFIX}/bin/libSessionViewer.dll" )

# Import target "Proof" for configuration "Release"
set_property(TARGET Proof APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Proof PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libProof.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/libProof.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS Proof )
list(APPEND _IMPORT_CHECK_FILES_FOR_Proof "${_IMPORT_PREFIX}/lib/libProof.lib" "${_IMPORT_PREFIX}/bin/libProof.dll" )

# Import target "ProofPlayer" for configuration "Release"
set_property(TARGET ProofPlayer APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(ProofPlayer PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libProofPlayer.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/libProofPlayer.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS ProofPlayer )
list(APPEND _IMPORT_CHECK_FILES_FOR_ProofPlayer "${_IMPORT_PREFIX}/lib/libProofPlayer.lib" "${_IMPORT_PREFIX}/bin/libProofPlayer.dll" )

# Import target "ProofDraw" for configuration "Release"
set_property(TARGET ProofDraw APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(ProofDraw PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libProofDraw.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/libProofDraw.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS ProofDraw )
list(APPEND _IMPORT_CHECK_FILES_FOR_ProofDraw "${_IMPORT_PREFIX}/lib/libProofDraw.lib" "${_IMPORT_PREFIX}/bin/libProofDraw.dll" )

# Import target "Html" for configuration "Release"
set_property(TARGET Html APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Html PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libHtml.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/libHtml.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS Html )
list(APPEND _IMPORT_CHECK_FILES_FOR_Html "${_IMPORT_PREFIX}/lib/libHtml.lib" "${_IMPORT_PREFIX}/bin/libHtml.dll" )

# Import target "EG" for configuration "Release"
set_property(TARGET EG APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(EG PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libEG.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/libEG.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS EG )
list(APPEND _IMPORT_CHECK_FILES_FOR_EG "${_IMPORT_PREFIX}/lib/libEG.lib" "${_IMPORT_PREFIX}/bin/libEG.dll" )

# Import target "VMC" for configuration "Release"
set_property(TARGET VMC APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VMC PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libVMC.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/libVMC.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VMC )
list(APPEND _IMPORT_CHECK_FILES_FOR_VMC "${_IMPORT_PREFIX}/lib/libVMC.lib" "${_IMPORT_PREFIX}/bin/libVMC.dll" )

# Import target "EGPythia8" for configuration "Release"
set_property(TARGET EGPythia8 APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(EGPythia8 PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libEGPythia8.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "Core"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/libEGPythia8.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS EGPythia8 )
list(APPEND _IMPORT_CHECK_FILES_FOR_EGPythia8 "${_IMPORT_PREFIX}/lib/libEGPythia8.lib" "${_IMPORT_PREFIX}/bin/libEGPythia8.dll" )

# Import target "Geom" for configuration "Release"
set_property(TARGET Geom APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Geom PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libGeom.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/libGeom.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS Geom )
list(APPEND _IMPORT_CHECK_FILES_FOR_Geom "${_IMPORT_PREFIX}/lib/libGeom.lib" "${_IMPORT_PREFIX}/bin/libGeom.dll" )

# Import target "GeomBuilder" for configuration "Release"
set_property(TARGET GeomBuilder APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(GeomBuilder PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libGeomBuilder.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/libGeomBuilder.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS GeomBuilder )
list(APPEND _IMPORT_CHECK_FILES_FOR_GeomBuilder "${_IMPORT_PREFIX}/lib/libGeomBuilder.lib" "${_IMPORT_PREFIX}/bin/libGeomBuilder.dll" )

# Import target "GeomPainter" for configuration "Release"
set_property(TARGET GeomPainter APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(GeomPainter PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libGeomPainter.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/libGeomPainter.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS GeomPainter )
list(APPEND _IMPORT_CHECK_FILES_FOR_GeomPainter "${_IMPORT_PREFIX}/lib/libGeomPainter.lib" "${_IMPORT_PREFIX}/bin/libGeomPainter.dll" )

# Import target "Gdml" for configuration "Release"
set_property(TARGET Gdml APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Gdml PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libGdml.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/libGdml.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS Gdml )
list(APPEND _IMPORT_CHECK_FILES_FOR_Gdml "${_IMPORT_PREFIX}/lib/libGdml.lib" "${_IMPORT_PREFIX}/bin/libGdml.dll" )

# Import target "Table" for configuration "Release"
set_property(TARGET Table APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Table PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libTable.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "Core;Cint"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/libTable.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS Table )
list(APPEND _IMPORT_CHECK_FILES_FOR_Table "${_IMPORT_PREFIX}/lib/libTable.lib" "${_IMPORT_PREFIX}/bin/libTable.dll" )

# Import target "root.exe" for configuration "Release"
set_property(TARGET root.exe APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(root.exe PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/root.exe"
  )

list(APPEND _IMPORT_CHECK_TARGETS root.exe )
list(APPEND _IMPORT_CHECK_FILES_FOR_root.exe "${_IMPORT_PREFIX}/bin/root.exe" )

# Import target "proofserv.exe" for configuration "Release"
set_property(TARGET proofserv.exe APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(proofserv.exe PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/proofserv.exe"
  )

list(APPEND _IMPORT_CHECK_TARGETS proofserv.exe )
list(APPEND _IMPORT_CHECK_FILES_FOR_proofserv.exe "${_IMPORT_PREFIX}/bin/proofserv.exe" )

# Import target "hadd" for configuration "Release"
set_property(TARGET hadd APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(hadd PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/hadd.exe"
  )

list(APPEND _IMPORT_CHECK_TARGETS hadd )
list(APPEND _IMPORT_CHECK_FILES_FOR_hadd "${_IMPORT_PREFIX}/bin/hadd.exe" )

# Import target "PyROOT" for configuration "Release"
set_property(TARGET PyROOT APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(PyROOT PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libPyROOT.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "RIO;Net;Hist;Graf;Graf3d;Gpad;Tree;Matrix;Thread"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/libPyROOT.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS PyROOT )
list(APPEND _IMPORT_CHECK_FILES_FOR_PyROOT "${_IMPORT_PREFIX}/lib/libPyROOT.lib" "${_IMPORT_PREFIX}/bin/libPyROOT.dll" )

# Import target "TMVA" for configuration "Release"
set_property(TARGET TMVA APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(TMVA PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libTMVA.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "Core;Cint"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/libTMVA.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS TMVA )
list(APPEND _IMPORT_CHECK_FILES_FOR_TMVA "${_IMPORT_PREFIX}/lib/libTMVA.lib" "${_IMPORT_PREFIX}/bin/libTMVA.dll" )

# Import target "RooFitCore" for configuration "Release"
set_property(TARGET RooFitCore APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(RooFitCore PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libRooFitCore.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "Core;Cint"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/libRooFitCore.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS RooFitCore )
list(APPEND _IMPORT_CHECK_FILES_FOR_RooFitCore "${_IMPORT_PREFIX}/lib/libRooFitCore.lib" "${_IMPORT_PREFIX}/bin/libRooFitCore.dll" )

# Import target "RooFit" for configuration "Release"
set_property(TARGET RooFit APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(RooFit PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libRooFit.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "Core;Cint"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/libRooFit.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS RooFit )
list(APPEND _IMPORT_CHECK_FILES_FOR_RooFit "${_IMPORT_PREFIX}/lib/libRooFit.lib" "${_IMPORT_PREFIX}/bin/libRooFit.dll" )

# Import target "RooStats" for configuration "Release"
set_property(TARGET RooStats APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(RooStats PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libRooStats.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "Core;Cint"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/libRooStats.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS RooStats )
list(APPEND _IMPORT_CHECK_FILES_FOR_RooStats "${_IMPORT_PREFIX}/lib/libRooStats.lib" "${_IMPORT_PREFIX}/bin/libRooStats.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
