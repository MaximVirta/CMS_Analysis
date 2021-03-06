PROGRAM       = CMS-analysis

version       = JTKT
CXX           = g++
CXXFLAGS      = -O -Wall -g -Wno-deprecated -D$(version)  #-ggdb
LD            = g++
LDFLAGS       = -O 
SOFLAGS       = -shared
#############################################
# -bind_at_load helps to remove linker error
############################################
CXXFLAGS += $(shell root-config --cflags)
CXXFLAGS += $(shell $(FASTJET)/bin/fastjet-config --cxxflags )

LDFLAGS  = $(shell root-config --libs)
LDFLAGS += -L$(FASTJET)/lib -lfastjettools -lfastjet -lfastjetplugins -lsiscone_spherical -lsiscone
LDFLAGS += -L$(PYTHIA8)/lib -lpythia8

LIBDIRARCH      = lib
LDFLAGS += -L$(PYTHIA8)/$(LIBDIRARCH) -lpythia8 -ldl
INCS    += -I$(PYTHIA8)/include
CXXFLAGS  += $(INCS) 

HDRSDICT = src/AliJCDijetHistos.h src/AliJHistogramInterface.h src/AliJHistManager.h src/AliJBaseTrack.h src/AliJBaseCard.h src/AliJCard.h src/AliJPhoton.h src/AliJJet.h src/JHistos.h src/JTreeDataManager.h
           
HDRS	+= $(HDRSDICT)   nanoDict.h


SRCS = $(HDRS:.h=.cxx)
OBJS = $(HDRS:.h=.o)

all:            $(PROGRAM)

$(PROGRAM):     $(OBJS) src/AliJConst.h $(PROGRAM).C
		@echo "Linking $(PROGRAM) ..."
		$(CXX) -lEG -lPhysics -L$(PWD) $(PROGRAM).C $(CXXFLAGS) $(OBJS) $(LDFLAGS) -o $(PROGRAM)
		@echo "done"


%.cxx:

%: %.cxx
	$(LINK.cc) $^ $(CXXFLAGS) $(LOADLIBES) $(LDLIBS) -o $@

%.o: %.cxx %.h
	@echo "Compile"
	@echo "$(OUTPUT_OPTION)"
	$(COMPILE.cc) $(OUTPUT_OPTION) $<
	@echo "Done"


clean:
		rm -f $(OBJS) core *Dict* $(PROGRAM).o *.d $(PROGRAM) $(PROGRAM).sl

cl:  clean $(PROGRAM)

nanoDict.cc: $(HDRSDICT)
		@echo "Generating dictionary ..."
		@rm -f nanoDict.cc nanoDict.hh nanoDict.h
		@rootcint nanoDict.cc -c -D$(version) $(HDRSDICT)
