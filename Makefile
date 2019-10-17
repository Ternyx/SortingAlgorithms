CC = g++
CPPFLAGS = -std=c++14 -I${IDIR} 

IDIR = include
SRCDIR = src
OBJDIR = obj

SRC = ${wildcard ${SRCDIR}/*.cpp}
OBJ = $(SRC:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)
DEPS = ${wildcard ${IDIR}/*.hpp}

exec: ${OBJ}
	${CC} ${OBJ} -o $@ ${CPPFLAGS}

${OBJDIR}/%.o: ${SRCDIR}/%.cpp ${DEPS}
	${CC} ${CPPFLAGS} -c $< -o $@

.PHONY: clean

clean:
	rm -r ${OBJDIR}/*.o exec 
