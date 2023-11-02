## Process this file with automake to produce Makefile.in

INCLUDES = \
	-DPACKAGE_DATA_DIR=\""$(datadir)"\" \
	-DPACKAGE_LOCALE_DIR=\""$(prefix)/$(DATADIRNAME)/locale"\" \
	@PACKAGE_CFLAGS@

bin_PROGRAMS = smartesprit_w

smartesprit_w_SOURCES = \
	main.c \
	support.c support.h \
	interface.c interface.h \
	callbacks.c callbacks.h\
	SEW.c SEW.h\
        Agent_de_foyer.c AF.h \
	verfier.c verfier.h\
	ajouter.c ajouter.h\
	verfier_j.c verfier_j.h\
	verfier_t.c verfier_t.h\
	modifier.c modifier.h\
	supprimer.c supprimer.h\
	verfier_h.c verfier_h.h\
	Aziz.c Aziz.h\
	atef.c atef.h \
	capteur.c capteur.h


smartesprit_w_LDADD = @PACKAGE_LIBS@ $(INTLLIBS)

