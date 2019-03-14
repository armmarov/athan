# Include
include ./target.mk

### 'TARGET' : Target file of compile. ###
TARGET  = athan.a

LIBSRC = athan.cpp
LIBHDR = athan.h 
LIBOBJ = $(LIBSRC:.cpp=.o)

all: $(TARGET)

$(TARGET): $(LIBOBJ)
	$(AR) rcs $(TARGET) $<

$(LIBOBJ): $(LIBSRC)
	$(CXX) $(CPPFLAGS) -c $< -o $@

clean: 
	$(RM) $(TARGET)
	$(RM) *.o
	$(RM) athan

unit_test:
	$(CXX) $(CPPFLAGS) athan.cpp -DUNIT_TEST -o athan