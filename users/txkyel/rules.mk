SRC += txkyel.c

ifeq ($(strip $(TAP_DANCE_ENABLE)), yes)
	SRC += tap_dance.c
endif

ifdef CALLUM_OS
	SRC += callum_oneshot.c
endif
