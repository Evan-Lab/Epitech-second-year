##
## EPITECH PROJECT, 2023
## raytracer
## File description:
## Makefile
##

## ===========================================================
## =========================[SRC]=============================
## ===========================================================

SRC	=	main.cpp					\
		primitives/3D/Point3D.cpp	\
		primitives/3D/Vector3D.cpp	\
		primitives/3D/Ray.cpp	\
		primitives/3D/Rectangle3D.cpp	\
		primitives/sphere.cpp	\
		primitives/plane.cpp	\
		transformations/translation.cpp	\
		parser/Parser.cpp		\
		material/color.cpp		\
		ppm/ppm.cpp					\
		light/direct_light.cpp	\
		scene_configuration/set_up_camera.cpp	\

## ===========================================================
## ======================[VARIABLE]===========================
## ===========================================================

NAME	=	raytracer

BUILDDIR	=	build

OBJ_SRC	=	$(patsubst %.cpp, $(BUILDDIR)/%.o, $(SRC))

$(BUILDDIR)/%.o:	src/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

CXXFLAGS	=	-std=c++20 -Wall -Wextra `pkg-config --cflags libconfig++` \
				`pkg-config --libs libconfig++`

CXX	=	g++

## ===========================================================
## =========================[RULES]===========================
## ===========================================================

all:	$(NAME)

$(NAME):	$(OBJ_SRC)
			$(CXX) -o $(NAME) $(OBJ_SRC) $(CXXFLAGS)

debug:	CXXFLAGS += -g3
debug:	re

## ===========================================================
## =========================[CLEAN]===========================
## ===========================================================

clean:
		$(RM) $(OBJ_SRC)

fclean:	clean
		$(RM) $(NAME)
		$(RM) -r $(BUILDDIR)

re:	fclean all

## ===========================================================
## =========================[PHONY]===========================
## ===========================================================

.PHONY:	all clean fclean re