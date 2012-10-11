CXX = g++
CXXFLAGS ?= -g -Wall -W -ansi -std=c++0x
LDFLAGS ?= 
SED = sed
MV = mv
RM = rm

.SUFFIXES: .o .cpp

lib = UnitTest++
test = testcppfunc

test_src = Main.cpp \
	   equal.cpp \
	   predicates.cpp \
	   map.cpp \
	   folding.cpp \
	   filter.cpp \
	   zipWith.cpp
	   

test_objects = $(patsubst %.cpp, %.o, $(test_src))
test_dependencies = $(subst .o,.d,$(test_objects))

define make-depend
  $(CXX) $(CXXFLAGS) -M $1 | \
  $(SED) -e 's,\($(notdir $2)\) *:,$(dir $2)\1: ,' > $3.tmp
  $(SED) -e 's/#.*//' \
      -e 's/^[^:]*: *//' \
      -e 's/ *\\$$//' \
      -e '/^$$/ d' \
      -e 's/$$/ :/' $3.tmp >> $3.tmp
  $(MV) $3.tmp $3
endef


all: clean $(test)

    
$(test): $(test_objects)
	@$(CXX) $(LDFLAGS) -o $(test) $(test_objects) -l $(lib)
	@echo Running unit tests...
	@./$(test)

clean:
	-@$(RM) $(test_objects) $(test_dependencies) $(test) 2> /dev/null

%.o : %.cpp
	@echo $<
	@$(call make-depend,$<,$@,$(subst .o,.d,$@))
	@$(CXX) $(CXXFLAGS) -c $< -o $(patsubst %.cpp, %.o, $<)


ifneq "$(MAKECMDGOALS)" "clean"
-include $(test_dependencies)
endif
