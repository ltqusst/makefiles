# This Makefile cannot be so simple w/o built-in rules of GNU make!!!


# COMPILE.cc = $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(TARGET_ARCH) -c
# COMPILE.c  = $(CC) $(CFLAGS) $(CPPFLAGS) $(TARGET_ARCH) -c
# LINK.o = $(CC) $(LDFLAGS) $(TARGET_ARCH)
# %: %.o
#	$(LINK.o) $^ $(LOADLIBES) $(LDLIBS) -o $@
# %.o: %.c
#	$(COMPILE.c) $(OUTPUT_OPTION) $<
# %.o: %.cpp
#	$(COMPILE.cpp) $(OUTPUT_OPTION) $<


CC=gcc
CXX=g++

LDLIBS += -lm
LDLIBS += $(shell pkg-config --libs opencv)

CPPFLAGS += $(shell pkg-config --cflags opencv)

SRC = main.cpp 
SRC += module/util.cpp

APP = cvshow

#========================================================================
BINDIR=bin/
OBJDIR=$(BINDIR)obj/
$(shell mkdir -p $(BINDIR) >/dev/null)
$(shell mkdir -p $(OBJDIR) >/dev/null)

OBJ=$(patsubst %.c,$(OBJDIR)%.o,$(patsubst %.cpp,$(OBJDIR)%.o,$(SRC)))
DEP=$(wildcard $(OBJ:.o=.d))

$(BINDIR)$(APP): $(OBJ)
	$(CXX) $(LDFLAGS) $(TARGET_ARCH) $^ $(LOADLIBES) $(LDLIBS) -o $@

# in following implicit rules, the stem(what matches '%') will be the relative path
# of the source file wrt. the root, plus file basename, and this part can be referenced by $* 
OUTPUT_OPTION=-MT $@ -MMD -MP -MF $(OBJDIR)$*.d -o $@

$(OBJDIR)%.o: %.cpp
	@test -d $(@D) || mkdir -p $(@D)
	$(COMPILE.cpp) $(OUTPUT_OPTION) $<

$(OBJDIR)%.o: %.c
	@test -d $(@D) || mkdir -p $(@D)
	$(COMPILE.c) $(OUTPUT_OPTION) $<

-include $(DEP)

.PHONY: clean 
clean:
	rm -f $(OBJ) $(DEP) cvshow

info:
	@echo SRC=$(SRC)	
	@echo OBJ=$(OBJ)
	@echo DEP=$(DEP)


