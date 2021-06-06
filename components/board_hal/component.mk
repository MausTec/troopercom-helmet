#
# "main" pseudo-component makefile.
#
# (Uses default behaviour of compiling all source files in directory, adding 'include' to include path.)

ifdef CONFIG_AUDIO_BOARD_CUSTOM
COMPONENT_ADD_INCLUDEDIRS += ./codec_driver
COMPONENT_SRCDIRS += ./codec_driver

COMPONENT_ADD_INCLUDEDIRS += ./troopercom_helm_v1_0
COMPONENT_SRCDIRS += ./troopercom_helm_v1_0
endif