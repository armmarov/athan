
# Define commands
CP		= cp -fp
RM		= rm -rf
MV		= mv
MKDIR	= mkdir
RMDIR	= rmdir
CHMOD	= chmod
CC		= gcc
CPP		= gcc
CXX		= g++
AS		= as
AR		= ar
LD		= ld
STRIP   = strip -g -X -R .comment -R .note.GCC-command-line
RANLIB  = $(TOOL_BIN)/$(CROSS_COMPILE)ranlib

# Define flags
CPPFLAGS += -g -O2 -Wall
