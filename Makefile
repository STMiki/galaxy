##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Simple description
##

DIR			=	src

SRCDIRS		= $(shell find $(DIR) -name '*.cpp' -exec dirname {} \; | uniq)

CC			=	g++

OBJDIR		=	obj

CFLAGS		+=	-Wall -Wextra -Werror -g
CFLAGS		+= -Iheader

LDFLAGS		+=	-lsfml-system -lsfml-audio -lsfml-network -lsfml-window -lsfml-graphics

FILE 	  	=   $(shell find $(DIR) -name '*.cpp')

OBJ			=	$(patsubst %.cpp,$(OBJDIR)/%.o,$(FILE))

APPNAME		=	galaxy

TEST_TERM	=	$(shell [ -t 1 ] && echo 1 || echo 0)

COLORGOOD	=	\033[1;32m

COLORINFO	=	\033[0;36m

COLORWARN	=	\033[1;33m

COLORERROR	=	\033[0;31m

COLORRESET	=	\033[0m

all: buildrepo compiling build
	@echo "$(COLORINFO)Done !$(COLORRESET)"

$(APPNAME): $(OBJ)
	@echo "$(COLORGOOD)Linking all file...$(COLORRESET)"
	@$(CC) $(OBJ) $(CFLAGS) $(LDFLAGS) -o $@

$(OBJDIR)/%.o: %.cpp
	@echo "$(COLORGOOD)Generating `echo $@ | rev | cut -d/ -f1 | rev` from $<...$(COLORRESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

disassemble: $(BINARY)
	@objdump --no-show-raw-insn -d -Mintel $(APPNAME) | source-highlight -s asm -f esc256 | less -eRiMX

clean:
	@echo "$(COLORWARN)Removing object file...$(COLORRESET)"
	@rm -f $(OBJ)
	@rm -frd $(OBJDIR)

fclean:	clean
	@echo "$(COLORWARN)Removing executable file...$(COLORRESET)"
	@rm -f $(APPNAME)

re:	fclean	all

compiling:
	@echo "$(COLORINFO)Compiling...$(COLORRESET)"

build: $(APPNAME)

buildrepo:
	@$(call make-repo)

define make-repo
	mkdir -p $(OBJDIR);				\
	for dir in $(SRCDIRS);			\
	do								\
		mkdir -p $(OBJDIR)/$$dir;	\
	done
endef
