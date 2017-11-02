#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=mkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/ACTON_20150817.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/ACTON_20150817.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=U1_TX.c U1_RX.c U1_config.c config_setup.c SPI1_config.c SPI1_data.c main20151205.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/U1_TX.o ${OBJECTDIR}/U1_RX.o ${OBJECTDIR}/U1_config.o ${OBJECTDIR}/config_setup.o ${OBJECTDIR}/SPI1_config.o ${OBJECTDIR}/SPI1_data.o ${OBJECTDIR}/main20151205.o
POSSIBLE_DEPFILES=${OBJECTDIR}/U1_TX.o.d ${OBJECTDIR}/U1_RX.o.d ${OBJECTDIR}/U1_config.o.d ${OBJECTDIR}/config_setup.o.d ${OBJECTDIR}/SPI1_config.o.d ${OBJECTDIR}/SPI1_data.o.d ${OBJECTDIR}/main20151205.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/U1_TX.o ${OBJECTDIR}/U1_RX.o ${OBJECTDIR}/U1_config.o ${OBJECTDIR}/config_setup.o ${OBJECTDIR}/SPI1_config.o ${OBJECTDIR}/SPI1_data.o ${OBJECTDIR}/main20151205.o

# Source Files
SOURCEFILES=U1_TX.c U1_RX.c U1_config.c config_setup.c SPI1_config.c SPI1_data.c main20151205.c


CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/ACTON_20150817.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=32MX250F128D
MP_LINKER_FILE_OPTION=
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/U1_TX.o: U1_TX.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/U1_TX.o.d 
	@${RM} ${OBJECTDIR}/U1_TX.o 
	@${FIXDEPS} "${OBJECTDIR}/U1_TX.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/U1_TX.o.d" -o ${OBJECTDIR}/U1_TX.o U1_TX.c     
	
${OBJECTDIR}/U1_RX.o: U1_RX.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/U1_RX.o.d 
	@${RM} ${OBJECTDIR}/U1_RX.o 
	@${FIXDEPS} "${OBJECTDIR}/U1_RX.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/U1_RX.o.d" -o ${OBJECTDIR}/U1_RX.o U1_RX.c     
	
${OBJECTDIR}/U1_config.o: U1_config.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/U1_config.o.d 
	@${RM} ${OBJECTDIR}/U1_config.o 
	@${FIXDEPS} "${OBJECTDIR}/U1_config.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/U1_config.o.d" -o ${OBJECTDIR}/U1_config.o U1_config.c     
	
${OBJECTDIR}/config_setup.o: config_setup.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/config_setup.o.d 
	@${RM} ${OBJECTDIR}/config_setup.o 
	@${FIXDEPS} "${OBJECTDIR}/config_setup.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/config_setup.o.d" -o ${OBJECTDIR}/config_setup.o config_setup.c     
	
${OBJECTDIR}/SPI1_config.o: SPI1_config.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/SPI1_config.o.d 
	@${RM} ${OBJECTDIR}/SPI1_config.o 
	@${FIXDEPS} "${OBJECTDIR}/SPI1_config.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/SPI1_config.o.d" -o ${OBJECTDIR}/SPI1_config.o SPI1_config.c     
	
${OBJECTDIR}/SPI1_data.o: SPI1_data.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/SPI1_data.o.d 
	@${RM} ${OBJECTDIR}/SPI1_data.o 
	@${FIXDEPS} "${OBJECTDIR}/SPI1_data.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/SPI1_data.o.d" -o ${OBJECTDIR}/SPI1_data.o SPI1_data.c     
	
${OBJECTDIR}/main20151205.o: main20151205.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main20151205.o.d 
	@${RM} ${OBJECTDIR}/main20151205.o 
	@${FIXDEPS} "${OBJECTDIR}/main20151205.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/main20151205.o.d" -o ${OBJECTDIR}/main20151205.o main20151205.c     
	
else
${OBJECTDIR}/U1_TX.o: U1_TX.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/U1_TX.o.d 
	@${RM} ${OBJECTDIR}/U1_TX.o 
	@${FIXDEPS} "${OBJECTDIR}/U1_TX.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/U1_TX.o.d" -o ${OBJECTDIR}/U1_TX.o U1_TX.c     
	
${OBJECTDIR}/U1_RX.o: U1_RX.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/U1_RX.o.d 
	@${RM} ${OBJECTDIR}/U1_RX.o 
	@${FIXDEPS} "${OBJECTDIR}/U1_RX.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/U1_RX.o.d" -o ${OBJECTDIR}/U1_RX.o U1_RX.c     
	
${OBJECTDIR}/U1_config.o: U1_config.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/U1_config.o.d 
	@${RM} ${OBJECTDIR}/U1_config.o 
	@${FIXDEPS} "${OBJECTDIR}/U1_config.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/U1_config.o.d" -o ${OBJECTDIR}/U1_config.o U1_config.c     
	
${OBJECTDIR}/config_setup.o: config_setup.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/config_setup.o.d 
	@${RM} ${OBJECTDIR}/config_setup.o 
	@${FIXDEPS} "${OBJECTDIR}/config_setup.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/config_setup.o.d" -o ${OBJECTDIR}/config_setup.o config_setup.c     
	
${OBJECTDIR}/SPI1_config.o: SPI1_config.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/SPI1_config.o.d 
	@${RM} ${OBJECTDIR}/SPI1_config.o 
	@${FIXDEPS} "${OBJECTDIR}/SPI1_config.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/SPI1_config.o.d" -o ${OBJECTDIR}/SPI1_config.o SPI1_config.c     
	
${OBJECTDIR}/SPI1_data.o: SPI1_data.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/SPI1_data.o.d 
	@${RM} ${OBJECTDIR}/SPI1_data.o 
	@${FIXDEPS} "${OBJECTDIR}/SPI1_data.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/SPI1_data.o.d" -o ${OBJECTDIR}/SPI1_data.o SPI1_data.c     
	
${OBJECTDIR}/main20151205.o: main20151205.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main20151205.o.d 
	@${RM} ${OBJECTDIR}/main20151205.o 
	@${FIXDEPS} "${OBJECTDIR}/main20151205.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/main20151205.o.d" -o ${OBJECTDIR}/main20151205.o main20151205.c     
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/ACTON_20150817.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mdebugger -D__MPLAB_DEBUGGER_PK3=1 -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/ACTON_20150817.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}              -mreserve=boot@0x1FC00490:0x1FC00BEF  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_PK3=1,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/ACTON_20150817.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/ACTON_20150817.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}            -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml
	${MP_CC_DIR}/xc32-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/ACTON_20150817.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell "${PATH_TO_IDE_BIN}"mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
